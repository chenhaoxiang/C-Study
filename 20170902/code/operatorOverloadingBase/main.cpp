#include<iostream>
#include"Time.h" 

using namespace std;

CTime addTime(CTime& time1, CTime& time2)//这里的相加是时分秒进行相加，满60进1
{
	int hour=0, minute = 0;
	int second = time1.m_nSecond + time2.m_nSecond;
	if (second > 60)
	{
		minute++;
		second -= 60;
	}

	minute += (time1.m_nMinute + time2.m_nMinute);
	if (minute > 60)
	{
		hour++;
		minute -= 60;
	}

	hour += (time1.m_nHour + time2.m_nHour);
	if (hour > 24)
	{
		hour -= 24;
	}
	return CTime(hour,minute,second);
}

/* 
//友元函数的运算符重载
CTime operator+(CTime& time1, CTime& time2)
{
	int hour = 0, minute = 0;
	int second = time1.m_nSecond + time2.m_nSecond;
	if (second > 60)
	{
		minute++;
		second -= 60;
	}

	minute += (time1.m_nMinute + time2.m_nMinute);
	if (minute > 60)
	{
		hour++;
		minute -= 60;
	}

	hour += (time1.m_nHour + time2.m_nHour);
	if (hour > 24)
	{
		hour -= 24;
	}
	return CTime(hour, minute, second);
}
*/

int main()
{ 
	CTime time(10, 50, 20);
	CTime time2(12); 
	CTime time3 = addTime(time, time2); 
	std::cout << time3.getHour() << ":" << time3.getMinute() << ":" << time3.getSecond() << endl;

	/*CTime time4 = time + time2;*/	//使用+号重载对两个CTime对象进行相加 
	CTime time4 = time.operator+(time2);
	std::cout << time4.getHour() << ":" << time4.getMinute() << ":" << time4.getSecond() << endl;

	time = time3;//直接使用一个对象对一个存在的对象赋值，这个时候才使用的是类的赋值运算符

	std::cout << time.getHour() << ":" << time.getMinute() << ":" << time.getSecond() << endl;

	//time = time;//会直接返回原对象

	CTime time5 = time3;//这里调用的是拷贝构造函数CTime::CTime(CTime& time) ，而不是赋值成员函数。要验证的话，可以使用断点来调试验证

	CTime time6(time3);//调用的是拷贝构造函数

	getchar();
	return 0;
}