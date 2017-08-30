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

	getchar();
	return 0;
}