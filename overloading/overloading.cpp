#include <iostream>
#include <string.h>

/*
可重载运算符/不可重载运算符
下面是可重载的运算符列表：
双目算术运算符	+ (加)，-(减)，*(乘)，/(除)，% (取模)
关系运算符	==(等于)，!= (不等于)，< (小于)，> (大于>，<=(小于等于)，>=(大于等于)
逻辑运算符	||(逻辑或)，&&(逻辑与)，!(逻辑非)
单目运算符	+ (正)，-(负)，*(指针)，&(取地址)
自增自减运算符	++(自增)，--(自减)
位运算符	| (按位或)，& (按位与)，~(按位取反)，^(按位异或),，<< (左移)，>>(右移)
赋值运算符	=, +=, -=, *=, /= , % = , &=, |=, ^=, <<=, >>=
空间申请与释放	new, delete, new[ ] , delete[]
其他运算符	()(函数调用)，->(成员访问)，,(逗号)，[](下标)
下面是不可重载的运算符列表：
.：成员访问运算符
.*, ->*：成员指针访问运算符
::：域运算符
sizeof：长度运算符
?:：条件运算符
#： 预处理符号
*/
using namespace std;

//function overload
class output{
	public:
	void print(int a)
	{
		cout << "int is:" << a << endl;
	}
	
	void print(double a)
	{
		cout << "double is:" << a << endl;
	}
	
	void print(string a)
	{
		cout << "string is：" << a << endl;
	}
};

//operate overload
class operate_overload
{
	public:
		double get_volume(void)
		{
			return length*width*height;
		}
		
		void set_length(double length)
		{
			this->length = length;
		}
		
		void set_width(double width)
		{
			this->width = width;
		}
		
		void set_height(double height)
		{
			this->height = height;
		}
		
		//运算符重载，重载+运算符，把两个对象相加
		operate_overload operator+(const operate_overload& op)
		{
			operate_overload  opt_od;
			
			opt_od.length = this->length + op.length;
			opt_od.width = this->width + op.width;
			opt_od.height = this->height + op.height;
			
			return opt_od;
		}
	
	private:
		double length;
		double width;
		double height;
};

int main(void)
{
    output opt;
	operate_overload box1, box2, box3;
	
	opt.print(10);
	opt.print(10.123);
	opt.print("hello C++");
	
	box1.set_length(10);
	box1.set_width(20);
	box1.set_height(30);
	
	cout << "box1 colume is : " <<box1.get_volume() << endl;
	
	box2.set_length(20);
	box2.set_width(30);
	box2.set_height(40);
	
	cout << "box2 colume is : " <<box2.get_volume() << endl;
	
	box3 = box1 + box2;
	
	cout << "box3 volume is: " << box3.get_volume() << endl;
	
    return 1;
}
