#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;



int main(void)
{
	char data[100];
	// 以写模式打开文件
	ofstream outfile;
	
	outfile.open("afile.dat");
	
	cout << "writing to  the file" << endl;
	cout << "enter your name: " << endl;
	cin.getline(data, 100);
	
	// 向文件写入用户输入的数据
	outfile << data << endl;
	
	cout << "enter your age: " << endl;
	cin >> data;
	cin.ignore();
	
	// 再次向文件写入用户输入的数据
	outfile << data << endl;
	
	//关闭打开的文件
	outfile.close();
	
	memset(data, 0, sizeof(data));
	//以读模式打开文件
	ifstream infile;
	infile.open("afile.dat");
	cout << "reading data from file" << endl;
	
	//将读出的数据存入data
	infile >> data;
	cout<< data << endl;
	
	//再次读
	infile >> data;
	cout<< data << endl;
	
	infile.close();
	
    return 1;
}
/***
// 定位到 fileObject 的第 n 个字节（假设是 ios::beg）
fileObject.seekg( n );
 
// 把文件的读指针从 fileObject 当前位置向后移 n 个字节
fileObject.seekg( n, ios::cur );
 
// 把文件的读指针从 fileObject 末尾往回移 n 个字节
fileObject.seekg( n, ios::end );
 
// 定位到 fileObject 的末尾
fileObject.seekg( 0, ios::end );
***/