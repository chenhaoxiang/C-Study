#include "Date.h"
#include "Time.h"
#include<iostream>
using namespace std;
CDate::CDate(int year, int month, int day)
:m_nYear(year), m_nMonth(month), m_nDay(day)
{
}

void CDate::disPlay(const CTime& time)//������ʹ������ĳ�Ա����������������Ҫ���������
{
	std::cout << m_nYear << "-" << m_nDay << "-" << m_nDay << "-" << time.m_nHour << ":" << time.m_nMinute << ":" << time.m_nSecond << ":" << time.m_nNum;
}