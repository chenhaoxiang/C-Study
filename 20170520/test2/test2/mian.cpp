#include <iostream>
#include "Time.h"
using namespace std;

int main(){
	CTime time;
	time.setHour(10);//ͨ����Ա��������ֵ
	time.setMinute(20);
	time.setSecond(30);

	cout << time.getHour() << ":" << time.getMinute() << ":" << time.getSecond() << endl;
	//�������� 10:20:30

	getchar();//�����Ϊ�˷�ֹ���������ر�
	return 0;
}