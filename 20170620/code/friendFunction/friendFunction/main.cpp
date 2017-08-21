#include<iostream>
#include"Time.h" 
#include "Date.h"
using namespace std;

void func()
{
	CTime time(1,1,1);
	time.m_nHour = 3;
	cout << time.m_nHour << endl;
}

int main()
{
	const CTime time(10,50,20);
	CTime const time2;
	std::cout << time.getNum() << std::endl;
	func();

	CDate date(2015, 1, 26);
	date.disPlay(time);

	getchar();
	return 0;
}