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
	void breath()
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
};

int main(void)
{
    //animal an;
	fish fs;
	fish fh(2);
    //an.eat();
	fs.eat();
	fh.eat();
    return 1;
}
