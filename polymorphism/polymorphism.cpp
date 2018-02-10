#include <iostream>
#include <string.h>

using namespace std;

class animal{
public:
    animal()
	{
		cout<<"animal one construct"<<endl;
	}
	animal(int height, int weight)
	{
		cout<<"animal two construct"<<endl;
	}
	~animal()
	{
		cout<<"animal destruct"<<endl;
	}
    void eat()
	{
		cout<<"animal eat"<<endl;
	}
	void sleep()
	{
		cout<<"animal sleep"<<endl;
	}
	virtual void breathe()//virtual虚函数，编译时采用迟邦定技术，运行时依据对象来确定调用的是哪一个函数
	//void breathe()
	//virtual void breathe()=0;//纯虚函数
	{
		cout<<"animal breathe"<<endl;
	}
};

class fish:public animal
{
public:
	fish()
	{
		cout<<"fish one construct"<<endl;
	}
	fish(int a):animal(400, 300)
	{
		cout<<"fish two construct"<<endl;
	}
	~fish()
	{
		cout<<"fish destruct"<<endl;
	}
	void breathe()//在基类的函数前加上virtual关键字，在派生类中重写该函数，运行时根据对象的实际类型来调用对应的函数
	{
		cout<<"fish bubble"<<endl;
	}
};

void fun(animal* pAn)
{
	pAn->breathe();
}
int main(void)
{
	animal *pAn = NULL;
	fish fs;
	
	pAn = &fs;
	fun(&fs);
	
    return 1;
}
