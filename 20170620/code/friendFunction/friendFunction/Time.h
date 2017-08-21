#ifndef TIME_H
#define TIME_H 
#include "Date.h"
class CTime
{
public:
	CTime();
	CTime(int hour, int minute, int second = 0);
	CTime(int value);
	CTime(CTime& time);
	~CTime();
	void setHour(int hour);
	void setMinute(int minute);
	void setSecond(int second);

	int getHour();
	int getMinute();
	int getSecond(); 

	int getNum() const;

	//friend CDate;//声明友元类,需要声明class CDate;    这样整个类都可以访问CTime的私有成员的了,由于我们只在disPlay函数中访问，所以可以用下面的方法
	friend void CDate::disPlay(const CTime& time);
	friend void func();//告诉编译器，CTime这个类，已经将func()这个函数声明为自己的友元函数，这个声明可以放在本CTime类中任何地方
private:
	int m_nHour;
	int m_nMinute;
	int m_nSecond;
	const int m_nNum;
};

#endif