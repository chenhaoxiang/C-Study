#include "Date.h"
#include "Time.h"
#include<iostream>
using namespace std;
CDate::CDate(int year, int month, int day)
:m_nYear(year), m_nMonth(month), m_nDay(day)
{
}

void CDate::disPlay(const CTime& time)//下面是使用了类的成员，所以在这里是需要类的声明的
{
	std::cout << m_nYear << "-" << m_nDay << "-" << m_nDay << "-" << time.m_nHour << ":" << time.m_nMinute << ":" << time.m_nSecond << ":" << time.m_nNum;
}