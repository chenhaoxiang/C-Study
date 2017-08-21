#include"Time.h"
#include<iostream>
using namespace std;

CTime::CTime()
:m_nNum(0)
{
	m_nHour = 0;
	m_nMinute = 0;
	m_nSecond = 0; 
}

CTime::~CTime()
{
}

CTime::CTime(int value)
:m_nNum(0)
{
	m_nHour = m_nMinute = 0;
	m_nSecond = value;
}

CTime::CTime(int hour, int minute, int second)
:m_nNum(0)
{
	m_nHour = hour;
	m_nMinute = minute;
	m_nSecond = second;
}

CTime::CTime(CTime& time)
:m_nNum(0)
{
	m_nHour = time.m_nHour;
	m_nMinute = time.m_nMinute;
	m_nSecond = time.m_nSecond;
}

void CTime::setHour(int hour)
{
	m_nHour = hour;
}

void CTime::setMinute(int minute)
{
	m_nMinute = minute;
}

void CTime::setSecond(int second)
{
	this->m_nSecond = second;
}

int CTime::getHour()
{
	return m_nHour;
}

int CTime::getMinute()
{
	return m_nMinute;
}

int CTime::getSecond()
{
	return m_nSecond;
} 

int CTime::getNum() const
{
	return m_nNum;
}