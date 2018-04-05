#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

template <class T>

class stack
{
	private:
		vector<T> elems; //元素
		
	public:
		void push(T const&);//入栈
		void pop();			//出栈
		T top() const;		//返回栈顶元素
		bool empty() const	//判断栈是否为空
		{
			return elems.empty();
		}
};

template <class T>

void stack<T>::push(T const& elem)
{
	//追加传入元素的副本
	elems.push_back(elem);
}

template <class T>
void stack<T>::pop()
{
	if(elems.empty())
	{
		throw out_of_range("stack<>::pop: empty stack");
	}
	
	//删除最后一个元素
	elems.pop_back();
}

template <class T>
T stack<T>::top () const 
{ 
    if (elems.empty()) { 
        throw out_of_range("Stack<>::top(): empty stack"); 
    }
    // 返回最后一个元素的副本 
    return elems.back();      
}

int main(void)
{
	try
	{
		stack<int> intstack;  //int 类型的栈
		stack<string> stringstack; //string类型的栈
		
		//操作int类型的栈
		intstack.push(7);
		cout << intstack.top()<< endl;
		
		//操作string类型的栈
		stringstack.push("template");
		cout<< stringstack.top() << endl;
		stringstack.pop();
		stringstack.pop();
	}
	catch(exception const& ex)
	{
		cerr << "exception: " << ex.what() <<endl;
		return -1;
	}
	return 1;
}

/***
throw: 当问题出现时，程序会抛出一个异常。这是通过使用 throw 关键字来完成的。
catch: 在您想要处理问题的地方，通过异常处理程序捕获异常。catch 关键字用于捕获异常。
try: try 块中的代码标识将被激活的特定异常。它后面通常跟着一个或多个 catch 块。
***/