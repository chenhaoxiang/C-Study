// test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Student.h"
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	Student stu;
	//ͨ���������ͳ�Ա���������"."������  
	stu.print();
	stu.getAge();
	//ͨ��ָ������ָ��������  
	Student *p = &stu;
	p->print();
	p->getAge();

	//ͨ������������  
	Student &s = stu;//����s��stu�ı���
	s.print();
	s.getAge();

	getchar();
	return 0;
}

