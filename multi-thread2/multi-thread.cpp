#include <iostream>
#include <pthread.h>
#include <cstdlib>
#include <unistd.h>


/*
pthread_join() 子程序阻碍调用程序，直到指定的 threadid 线程终止为止。当创建一个线程时，
它的某个属性会定义它是否是可连接的（joinable）或可分离的（detached）。只有创建时定义为
可连接的线程才可以被连接。如果线程创建时被定义为可分离的，则它永远也不能被连接。
这个实例演示了如何使用 pthread_join() 函数来等待线程的完成。
*/
using namespace std;

#define NUM_THREADS  5

void *say_hello(void *args)
{
	int value = *(int *)(args);
	cout << " sleeping in thread " << endl;
	cout << "thread with id:  " << value << endl;
	pthread_exit(NULL);
}


int main(void)
{
	//定义线程id变量， 多个变量使用数组
	pthread_t tids[NUM_THREADS];
	pthread_attr_t attr;
	int index[NUM_THREADS];
	
	// 初始化并设置线程为可连接的（joinable）
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	
	for(int i=0; i<NUM_THREADS; i++)
	{
		index[i] = i;
		//参数依次是：创建的线程id，线程参数，调用的函数，传入的函数参数
		int ret = pthread_create(&tids[i], NULL, say_hello, (void*)(&index[i]));
		if(ret != 0)
		{
			cout << "pthread_create error: error code=" << ret << endl;
			exit(-1);
		}
	}
	
	// 删除属性，并等待其他线程
	pthread_attr_destroy(&attr);
	
	for(int i=0; i<NUM_THREADS; i++ )
	{
		void *status;
		int ret = pthread_join(tids[i], &status);
		if(ret != 0)
		{
			cout << "pthread_create error: error code=" << ret << endl;
			exit(-1);
		}
		
		cout << "main: complete thread id: . " << i << endl;
		cout << " exciting with status: " << status << endl;
	}
	
	cout << "main program exiting. " << endl;
	//等各个线程退出后，进程才结束，否则进程强制结束了，线程可能还没反应过来；
	pthread_exit(NULL);
	
	return 0;
}