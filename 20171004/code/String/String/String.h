#ifndef STRING_H//头文件卫士，避免头文件被多次编译
#define STRING_H
#include<iostream>  //输入输出头文件
using namespace std; //命名空间
class String
{
public://公有的声明
	String(const char*); //构造函数
	String(int n,char c); //传入大小的构造函数
	~String(); //析构函数

public:
	String(String &str);  //拷贝构造函数
	const String& operator=(const String& str);//赋值运算符重载，我们在不需要修改参数的值的地方都应该声明为const

	char operator[](int pos)const;//下标访问运算符重载
	char at(int pos)const;//检查越界的下标访问

	int size()const; //字符串的空间大小
	int length()const; //字符串的字符大小
	bool empty()const; //判断为空的函数

	const String& operator+=(const String& str); //字符串的连接
	bool operator==(const String& str);//字符串的相等判断
	bool compare(const String& str);//字符串的相等判断

	friend istream& operator>>(istream& input, String& str); //输入操作符的重载
	friend ostream& operator<<(ostream& output, String& str); //输出操作符的重载
private:
	char* m_pBuff;//保存字符串的首地址
	int m_nRealLen;  //字符串的字符大小
	int m_nBuffSize;  //字符串的空间大小

};

#endif
