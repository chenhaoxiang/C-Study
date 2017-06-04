#ifndef TIME_H
#define TIME_H
class CTime
{
public:
	CTime();//构造函数
	~CTime();//析构函数
	CTime(int hour);
	CTime(CTime& time);
	void setHour(int hour);
	void setMinute(int minute);
	void setSecond(int second);

	int getHour();
	int getMinute();
	int getSecond();

	static int getNum();
private:
	int m_hour;
	int m_minute;
	int m_second;

	static int m_nNum;
};
#endif