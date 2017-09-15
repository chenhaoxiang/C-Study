 
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
//友元函数的运算符重载
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

//因为要用到CTime类的成员，所以把流提取运算符作为CTime类的友元
istream& operator>>(istream& input, CTime& time)
{
	//可以直接使用CTIme类的数据成员了
	cin >> time.m_nHour >> time.m_nMinute >> time.m_nSecond;
	return input;

}

//重载流插入运算符
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

	cin >> time;  //在我们重载了输入输出运算符之后，我们也可以像C++里面预定义好的数据类型一样对这个类的对象进行输入输出
	
	cout << time << time2;

	operator>>(cin, time);
	operator<<(cout, time);
	operator<<(cout, time2);

	time2 + CTime(3);//类似于强制类型转换，将int类型转换为CTime类型。
	//之所以可以进行此种转换，是因为已经为CTime对象定义了具有一个int类型参数的构造函数。因此具有一个参数的构造函数可以用来做类型转换，称之为转换构造函数

	CTime time3(20);
	CTime time4 = 20;//和下面那句效果一样的,自动类型转换
	CTime time5 = CTime(20);

	func(time);
	func(10);//编译器会自动构造一个CTime的临时对象

	int nSecond = time;
	cout << nSecond;

	getchar();
	getchar();
	return 0;
}

