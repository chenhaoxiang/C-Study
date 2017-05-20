#include "Time.h"

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