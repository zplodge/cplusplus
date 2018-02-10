#include <iostream>
#include <string.h>

using namespace std;

class point{
public:
	int x, y, z;
	
    point()//构造函数，起初始化的作用
	{
		x=y=z=0;
	}
	point(int a, int b, int c)//函数的重载，参数类型和参数个数不一样时，可以构成函数重载
	{
		x=a;
		y=b;
		z=c;
	}
	
	void input(int x, int y, int z)
	{
		this->x = x; //this,一种隐含的指针属性，指向对象本身，代表了对象的地址
		this->y = y;
		this->z = z;
	}
	
	void output()
	{
	    cout<<x<<endl<<y<<endl<<z<<endl;
	}
};

class student
{
private:
    char* pName;

public:
     char *nName;
    student()
	{
		pName = new char[50];
		nName = "this is a student class";
		strncpy(pName, nName, 50);
	}
	
	void output()
	{
		cout<<pName<<endl;
	}
	
	~student()//析构函数，不允许带参数，一个类中只能有一个析构函数，用于清除类的对象
	{
		delete[] pName;
	}
	
	
};

int main(void)
{
    point pt;
	point pt1(1,2,3);
    student st;
	
	
    pt.output();
	pt.input(4, 5, 6);
	pt.output();
	pt1.output();
	st.output();
	
    return 1;
}
