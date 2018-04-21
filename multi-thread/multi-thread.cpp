#include <iostream>
#include <pthread.h>
#include <cstdlib>

using namespace std;

#define NUM_THREADS  5

void *say_hello(void *args)
{
	int value = *(int *)(args);
	cout << "hello multi_thread: args = " << value << endl;
	pthread_exit(NULL);
	//return 0;
}


int main(void)
{
	//定义线程id变量， 多个变量使用数组
	pthread_t tids[NUM_THREADS];
	int index[NUM_THREADS];
	
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
	
	//等各个线程退出后，进程才结束，否则进程强制结束了，线程可能还没反应过来；
	pthread_exit(NULL);
	
	return 0;
}