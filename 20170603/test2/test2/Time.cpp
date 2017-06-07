#include <iostream>
#include "Time.h"

using namespace std;
CTime::CTime() : num(10){
	
	m_hour = 0;
	m_minute = 0;
	m_second = 0;
	m_nNum++;
	cout << m_nNum << endl;
}
CTime::~CTime(){
	m_nNum--;
	cout << m_nNum << endl;
}
CTime::CTime(int hour) : num(10){
	this->m_hour = hour;
	//(*this).m_hour = hour; //Ч��һ����
}

//���ƹ��캯��
CTime::CTime(CTime& time) : num(10){
	m_hour = time.m_hour;
	m_minute = time.m_minute;
	m_second = time.m_second;
	//cout << "���븴�ƹ��캯��" << endl;
}

void CTime::setHour(int hour){
	m_hour = hour;
}

void CTime::setMinute(int minute){
	m_minute = minute;
}

void CTime::setSecond(int second){
	m_second = second;
}

int CTime::getHour(){
	return m_hour;
}
int CTime::getMinute(){
	return m_minute;
}
int CTime::getSecond(){
	return m_second;
}

int CTime::m_nNum = 0;
//��ʼ����ʱ��ǰ�治Ҫ��static
//������ˣ���ô�������ڱ����ʱ�򣬾ͻ�Ϊm_nNum�����ڴ�ռ�

int CTime::getMNum(){
	return m_nNum;
}

int CTime::getNum() const {
	if (m_age == 0){
		m_age++;
	}
	else{
		m_age = 0;
	}
	return num;
}