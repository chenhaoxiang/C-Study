#include<iostream>
#include"String.h"

int main()
{
	String str("Hello String!");  //һ�������Ĺ��캯��
	std::cout << str << std::endl;

	String str2(10, 'a');  //�ṩ��һ���ַ���ɵ��ַ���
	std::cout << str2 << std::endl;

	str2 = str;  //����=��������صĺ���
	std::cout << str2 << std::endl;

	String str3 = str2;   //���ÿ������캯��
	std:cout << str3 << std::endl;

	std::cout << "size:" << str3.size() << ", lenght:" << str3.length() << std::endl;

	str3 += "abcdkdkd";   //ƴ�������ַ����������ַ���������
	std::cout << str3 << std::endl;
	std::cout << "size:" << str3.size() << ", lenght:" << str3.length() << std::endl;

	String str4(50, 'a');
	str3 += str4;
	std::cout << str3 << std::endl;
	std::cout << "size:" << str3.size() << ", lenght:" << str3.length() << std::endl;

	getchar();
	return 0;
}