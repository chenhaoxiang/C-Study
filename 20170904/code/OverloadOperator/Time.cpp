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

//拷贝构造函数
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
	//为了防止同一个对象进行赋值，需要先判断一下,判断地址是不是一样
	if (this == &time)
	{
		return *this;
	}

	//默认的是各个成员分别赋值
	m_nHour = time.m_nHour;
	m_nMinute = time.m_nMinute;
	m_nSecond = time.m_nSecond;

	return *this;//返回当前这个对象
}

//判断对象的每个成员变量是否相等
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
	if (m_nHour > time.m_nHour) //先判断两个对象的小时数的大小
	{
		return true;
	}
	else if (m_nHour < time.m_nHour)
	{
		return false;
	}
	else //这是两个对象小时数相等的情况，接下来就判断分钟数
	{
		if (m_nMinute> time.m_nMinute) //再判断两个对象的分钟数的大小
		{
			return true;
		}
		else if (m_nMinute < time.m_nMinute)
		{
			return false;
		}
		else //这是两个对象的时钟和分钟相等的情况下
		{
			if (m_nSecond>time.m_nSecond) //最后比较秒钟
			{
				return true;
			}
			else
			{
				return false;
			}
		}

	}

	return false;  //最后就是两个对象相等，也不满足一个对象大于另外一个对象的情况，返回false
}
CTime CTime::operator++() //重载++(前置)运算符
{
	CTime time(0, 0, 1); //定义了一个秒数为1的对象
	*this = *this + time;//由于前面的函数已经重载了加号运算符，里面已经定义好了相关的操作，所以这句代码调用了加号运算符的重载函数，并将对象的秒数加一
	return *this; //前置++的操作顺序就是先加再返回它的值
}

CTime CTime::operator++(int) //重载++(后置)运算符
{
	CTime time = *this;//后置++的操作规则是先返回再加，所以需要创建一个临时变量保存好这个对象的值
	CTime time2(0, 0, 1); // 定义了一个秒数为1的对象
		*this = *this + time2;//同上调用了加法运算符的重载函数
	return *this;//返回加法操作之前的对象的值
}