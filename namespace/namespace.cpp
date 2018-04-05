#include <iostream>
#include <string.h>

using namespace std;

// 第一个命名空间
namespace first_space
{
	//public:
		void fun()
		{
			cout << " first_space " << endl;
		}
}


// 第二个命名空间
namespace second_space
{
	//public:
		void fun()
		{
			cout << " second_space " << endl;
		}
}

int main(void)
{
	// 调用第一个命名空间
	first_space::fun();
	// 调用第二个命名空间
	second_space::fun();
	
    return 1;
}
