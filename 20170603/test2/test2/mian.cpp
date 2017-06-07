#include <iostream>
#include "Time.h"
using namespace std;

void func(CTime time){
	//cout << time.getHour()<<endl;
}
CTime func1(CTime time){
	//复制给func1中的形参time 也会调用一次复制构造函数
	//cout << time.getHour() << endl;
	return time;//time在返回的时候会复制给返回的值，这个时候会调用复制构造函数
}


int main(){
	CTime time;
	time.setHour(10);//通过成员方法设置值
	time.setMinute(20);
	time.setSecond(30);
	
	CTime time2(time);//第一次调用复制构造函数
	func(time);//第二次调用复制构造函数  复制给func中的形参time
	CTime time3 = func1(time);//第三次和第四次调用复制构造函数
	CTime::getMNum();
	time.getMNum();
	cout << time.getHour() << ":" << time.getMinute() << ":" << time.getSecond() << endl;
	//输出结果： 10:20:30
	cout << time2.getHour() << ":" << time2.getMinute() << ":" << time2.getSecond() << endl;

	//const
	const CTime time4(10);
	CTime const time5;
	cout << time5.getNum() <<endl;

	//time4.getHour();//会报错，不能调用非const函数


	getchar();//这句是为了防止输出窗口秒关闭
	return 0;
}