#ifndef TIME_H
#define TIME_H 

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

	CTime operator+(CTime& time);

 
	friend CTime addTime(CTime& time1, CTime& time2); 
	/*friend CTime operator+(CTime& time1, CTime& time2);*/

private:
	int m_nHour;
	int m_nMinute;
	int m_nSecond; 
};

#endif