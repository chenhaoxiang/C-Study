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
	CTime& operator=(CTime& time);//返回的是对象的引用形式

	void setHour(int hour);
	void setMinute(int minute);
	void setSecond(int second);

	int getHour();
	int getMinute();
	int getSecond();  

	CTime operator+(CTime& time);

 
	friend CTime addTime(CTime& time1, CTime& time2); 
	/*friend CTime operator+(CTime& time1, CTime& time2); //友元函数的运算符重载 */

private:
	int m_nHour;
	int m_nMinute;
	int m_nSecond; 
};

#endif