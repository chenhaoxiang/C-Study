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
	CTime& operator=(CTime& time);//���ص��Ƕ����������ʽ

	void setHour(int hour);
	void setMinute(int minute);
	void setSecond(int second);

	int getHour();
	int getMinute();
	int getSecond();  

	CTime operator+(CTime& time);

	///
	bool operator==(CTime& time);
	bool operator>(CTime& time);
	///
	CTime operator++();//ǰ�õ�++
	CTime operator++(int);//����++�����int���͵Ĳ���ֻ��Ϊ�����֣����ǲ�����ʹ������������������ǲ���Ҫ�βε�����

	friend CTime addTime(CTime& time1, CTime& time2); 
	/*friend CTime operator+(CTime& time1, CTime& time2);*/

private:
	int m_nHour;
	int m_nMinute;
	int m_nSecond; 
};

#endif