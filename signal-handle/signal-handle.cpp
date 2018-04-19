#include <iostream>
#include <csignal>
#include <unistd.h>
#include <cstdlib>

using namespace std;
void  signalHandle(int signum)
{
	cout << "inttrupt signal : "<< signum << endl;
	
	// 清理并关闭
    // 终止程序  
	exit(signum);
}

#if 0
int main(void)
{
	// 注册信号 SIGINT 和信号处理程序
	signal(SIGINT, signalHandle);
	
	while(1)
	{
		cout << "going to sleep..." << endl;
		sleep(1);
	}
	return 0;
}
#endif


/*
 raise() 生成信号，该函数带有一个整数信号编号作为参数,自动触发中断函数
*/
int main(void)
{
	int i = 0;
	// 注册信号 SIGINT 和信号处理程序
	signal(SIGINT, signalHandle);
	
	while(++i)
	{
		cout << "going to sleep..." << endl;
		
		if(3 == i)
		{
			raise(SIGINT);
		}
		sleep(1);
	}
	return 0;
}