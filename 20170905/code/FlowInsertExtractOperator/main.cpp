 
#include"Time.h" 

using namespace std;

CTime addTime(CTime& time1, CTime& time2)//����������ʱ���������ӣ���60��1
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
//��Ԫ���������������
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

//��ΪҪ�õ�CTime��ĳ�Ա�����԰�����ȡ�������ΪCTime�����Ԫ
istream& operator>>(istream& input, CTime& time)
{
	//����ֱ��ʹ��CTIme������ݳ�Ա��
	cin >> time.m_nHour >> time.m_nMinute >> time.m_nSecond;
	return input;

}

//���������������
ostream& operator<<(ostream& output, CTime& time)
{
	cout << time.getHour() << time.getMinute() << time.getSecond()<<endl;
	return output;
}

void func(CTime a)
{

}

int main()
{ 
	CTime time(10, 50, 20);
	CTime time2(12); 

	cin >> time;  //������������������������֮������Ҳ������C++����Ԥ����õ���������һ���������Ķ�������������
	
	cout << time << time2;

	operator>>(cin, time);
	operator<<(cout, time);
	operator<<(cout, time2);

	time2 + CTime(3);//������ǿ������ת������int����ת��ΪCTime���͡�
	//֮���Կ��Խ��д���ת��������Ϊ�Ѿ�ΪCTime�������˾���һ��int���Ͳ����Ĺ��캯������˾���һ�������Ĺ��캯����������������ת������֮Ϊת�����캯��

	CTime time3(20);
	CTime time4 = 20;//�������Ǿ�Ч��һ����,�Զ�����ת��
	CTime time5 = CTime(20);

	func(time);
	func(10);//���������Զ�����һ��CTime����ʱ����

	int nSecond = time;
	cout << nSecond;

	getchar();
	getchar();
	return 0;
}

