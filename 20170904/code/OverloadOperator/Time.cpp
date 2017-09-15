#include"Time.h"
#include<iostream>
using namespace std;

CTime::CTime() 
{
	m_nHour = 0;
	m_nMinute = 0;
	m_nSecond = 0; 
}

CTime::~CTime()
{
}

CTime::CTime(int value) 
{
	m_nHour = m_nMinute = 12;
	m_nSecond = value;
}
 
CTime::CTime(int hour, int minute, int second) 
{
	m_nHour = hour;
	m_nMinute = minute;
	m_nSecond = second;
}

//�������캯��
CTime::CTime(CTime& time) 
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

 

CTime CTime::operator+(CTime& time)
{
	int hour = 0, minute = 0;
	int second = this->m_nSecond + time.m_nSecond;
	if (second > 60)
	{
		minute++;
		second -= 60;
	}
	minute += (this->m_nMinute + time.m_nMinute);
	if (minute > 60)
	{
		hour++;
		minute -= 60;
	}
	hour += (this->m_nHour + time.m_nHour);
	if (hour > 24)
	{
		hour -= 24;
	}
	return CTime(hour, minute, second);
}

CTime& CTime::operator=(CTime& time)
{
	//Ϊ�˷�ֹͬһ��������и�ֵ����Ҫ���ж�һ��,�жϵ�ַ�ǲ���һ��
	if (this == &time)
	{
		return *this;
	}

	//Ĭ�ϵ��Ǹ�����Ա�ֱ�ֵ
	m_nHour = time.m_nHour;
	m_nMinute = time.m_nMinute;
	m_nSecond = time.m_nSecond;

	return *this;//���ص�ǰ�������
}

//�ж϶����ÿ����Ա�����Ƿ����
bool CTime::operator==(CTime& time)
{
	if (m_nHour == time.m_nHour&&m_nMinute == time.m_nMinute&&m_nSecond == time.m_nSecond)
	{
		return true;
	}
	return false;
}

bool CTime::operator>(CTime& time)
{
	if (m_nHour > time.m_nHour) //���ж����������Сʱ���Ĵ�С
	{
		return true;
	}
	else if (m_nHour < time.m_nHour)
	{
		return false;
	}
	else //������������Сʱ����ȵ���������������жϷ�����
	{
		if (m_nMinute> time.m_nMinute) //���ж���������ķ������Ĵ�С
		{
			return true;
		}
		else if (m_nMinute < time.m_nMinute)
		{
			return false;
		}
		else //�������������ʱ�Ӻͷ�����ȵ������
		{
			if (m_nSecond>time.m_nSecond) //���Ƚ�����
			{
				return true;
			}
			else
			{
				return false;
			}
		}

	}

	return false;  //����������������ȣ�Ҳ������һ�������������һ����������������false
}
CTime CTime::operator++() //����++(ǰ��)�����
{
	CTime time(0, 0, 1); //������һ������Ϊ1�Ķ���
	*this = *this + time;//����ǰ��ĺ����Ѿ������˼Ӻ�������������Ѿ����������صĲ�������������������˼Ӻ�����������غ��������������������һ
	return *this; //ǰ��++�Ĳ���˳������ȼ��ٷ�������ֵ
}

CTime CTime::operator++(int) //����++(����)�����
{
	CTime time = *this;//����++�Ĳ����������ȷ����ټӣ�������Ҫ����һ����ʱ�����������������ֵ
	CTime time2(0, 0, 1); // ������һ������Ϊ1�Ķ���
		*this = *this + time2;//ͬ�ϵ����˼ӷ�����������غ���
	return *this;//���ؼӷ�����֮ǰ�Ķ����ֵ
}