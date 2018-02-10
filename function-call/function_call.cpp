#include <iostream>
#include <string.h>

using namespace std;

class function_call{
public:
    function_call()
	{
		cout<<"function_call construct"<<endl;
	}
	void swap_one(int a, int b)
	{
		cout<<"swap_one start"<<endl;
		cout<<"a is:"<<a<<"|||"<<"&a is:"<<&a<<endl;
		cout<<"b is:"<<b<<"|||"<<"&b is:"<<&b<<endl;
		int temp;
		temp = a;
		a = b;
		b = temp;
		cout<<"swap_one end"<<endl;
		cout<<"a is:"<<a<<"|||"<<"&a is:"<<&a<<endl;
		cout<<"b is:"<<b<<"|||"<<"&b is:"<<&b<<endl;
	}
	
	void swap_two(int* a, int* b)
	{
		cout<<"swap_two start"<<endl;
		cout<<"a is:"<<a<<"|||"<<"*a is:"<<*a<<endl;
		cout<<"b is:"<<b<<"|||"<<"*b is:"<<*b<<endl;
		int temp;
		temp = *a;
		*a = *b;
		*b = temp;
		cout<<"swap_two end"<<endl;
		cout<<"a is:"<<a<<"|||"<<"*a is:"<<*a<<endl;
		cout<<"b is:"<<b<<"|||"<<"*b is:"<<*b<<endl;
	}
	
	void swap_three(int &a, int &b)
	{
		cout<<"swap_three start"<<endl;
		cout<<"a is:"<<a<<"|||"<<"&a is:"<<&a<<endl;
		cout<<"b is:"<<b<<"|||"<<"&b is:"<<&b<<endl;
		int temp;
		temp = a;
		a = b;
		b = temp;
		cout<<"swap_three end"<<endl;
		cout<<"a is:"<<a<<"|||"<<"&a is:"<<&a<<endl;
		cout<<"b is:"<<b<<"|||"<<"&b is:"<<&b<<endl;
	}
	
	~function_call()
	{
		cout<<"function_call destruct"<<endl;
	}
    
	virtual void breathe()//virtual虚函数，编译时采用迟邦定技术，运行时依据对象来确定调用的是哪一个函数
	{
		cout<<"animal breathe"<<endl;
	}
};

int main(void)
{
	function_call fun_c;
	
	int x, y;
	
	x= 10, y = 20;
	cout<<"x address is:"<<&x<<"|||"<<"y address is:"<<&y<<endl;
	fun_c.swap_one(x, y);
	cout<<"x is:"<<x<<"|||"<<"y is:"<<y<<endl;
	
	x= 10, y = 20;
	fun_c.swap_two(&x, &y);
	cout<<"x is:"<<x<<"|||"<<"y is:"<<y<<endl;
	
	x= 10, y = 20;
	fun_c.swap_three(x, y);
	cout<<"x is:"<<x<<"|||"<<"y is:"<<y<<endl;
	
    return 1;
}
