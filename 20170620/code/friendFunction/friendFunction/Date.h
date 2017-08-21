#ifndef DATA_H
#define DATA_H

class CTime;//类的前置声明，一般情况下，是需要声明之后才可以使用的

class CDate
{
public:
	CDate(int year, int month, int day);

	//friend CTime;//在这里声明友元没用，因为友元只能授予，不能索取！
	void disPlay(const CTime& time);//使用的是类的引用(引用也是使用指针来实现的),这里不声明是可以的

private:
	int m_nYear;
	int m_nMonth;
	int m_nDay;

};
#endif