#include <iostream>
#include "Time.h"
using namespace std;

void func(CTime time){
	//cout << time.getHour()<<endl;
}
CTime func1(CTime time){
	//���Ƹ�func1�е��β�time Ҳ�����һ�θ��ƹ��캯��
	//cout << time.getHour() << endl;
	return time;//time�ڷ��ص�ʱ��Ḵ�Ƹ����ص�ֵ�����ʱ�����ø��ƹ��캯��
}


int main(){
	CTime time;
	time.setHour(10);//ͨ����Ա��������ֵ
	time.setMinute(20);
	time.setSecond(30);
	
	CTime time2(time);//��һ�ε��ø��ƹ��캯��
	func(time);//�ڶ��ε��ø��ƹ��캯��  ���Ƹ�func�е��β�time
	CTime time3 = func1(time);//�����κ͵��Ĵε��ø��ƹ��캯��
	CTime::getNum();
	time.getNum();
	cout << time.getHour() << ":" << time.getMinute() << ":" << time.getSecond() << endl;
	//�������� 10:20:30
	cout << time2.getHour() << ":" << time2.getMinute() << ":" << time2.getSecond() << endl;

	//const
	const CTime time4(10);
	CTime const time5;

	time4.getHour();


	getchar();//�����Ϊ�˷�ֹ���������ر�
	return 0;
}