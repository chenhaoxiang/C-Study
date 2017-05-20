#ifndef TIME_H
#define TIME_H
class CTime
{
public:
	void setHour(int hour);
	void setMinute(int minute);
	void setSecond(int second);

	int getHour();
	int getMinute();
	int getSecond();
private:
	int m_hour;
	int m_minute;
	int m_second;
};
#endif