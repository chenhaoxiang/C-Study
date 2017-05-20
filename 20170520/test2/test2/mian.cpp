#include <iostream>
#include "Time.h"
using namespace std;

int main(){
	CTime time;
	time.setHour(10);//通过成员方法设置值
	time.setMinute(20);
	time.setSecond(30);

	cout << time.getHour() << ":" << time.getMinute() << ":" << time.getSecond() << endl;
	//输出结果： 10:20:30

	getchar();//这句是为了防止输出窗口秒关闭
	return 0;
}