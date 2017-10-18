#include<iostream>
#include"String.h"

int main()
{
	String str("Hello String!");  //一个参数的构造函数
	std::cout << str << std::endl;

	String str2(10, 'a');  //提供由一个字符组成的字符串
	std::cout << str2 << std::endl;

	str2 = str;  //调用=运算符重载的函数
	std::cout << str2 << std::endl;

	String str3 = str2;   //调用拷贝构造函数
	std:cout << str3 << std::endl;

	std::cout << "size:" << str3.size() << ", lenght:" << str3.length() << std::endl;

	str3 += "abcdkdkd";   //拼接两个字符串，测试字符串的连接
	std::cout << str3 << std::endl;
	std::cout << "size:" << str3.size() << ", lenght:" << str3.length() << std::endl;

	String str4(50, 'a');
	str3 += str4;
	std::cout << str3 << std::endl;
	std::cout << "size:" << str3.size() << ", lenght:" << str3.length() << std::endl;

	getchar();
	return 0;
}