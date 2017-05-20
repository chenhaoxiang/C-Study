// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Student.h"
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	Student stu;
	//通过对象名和成员访问运算符"."来访问  
	stu.print();
	stu.getAge();
	//通过指向对象的指针来访问  
	Student *p = &stu;
	p->print();
	p->getAge();

	//通过引用来访问  
	Student &s = stu;//表明s是stu的别名
	s.print();
	s.getAge();

	getchar();
	return 0;
}

