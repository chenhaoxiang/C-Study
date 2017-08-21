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

	//friend CDate;//������Ԫ��,��Ҫ����class CDate;    ���������඼���Է���CTime��˽�г�Ա����,��������ֻ��disPlay�����з��ʣ����Կ���������ķ���
	friend void CDate::disPlay(const CTime& time);
	friend void func();//���߱�������CTime����࣬�Ѿ���func()�����������Ϊ�Լ�����Ԫ����������������Է��ڱ�CTime�����κεط�
private:
	int m_nHour;
	int m_nMinute;
	int m_nSecond;
	const int m_nNum;
};

#endif