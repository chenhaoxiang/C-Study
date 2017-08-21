---
layout: post
title: "【C++】C++友元"
date: 2017-06-20 13:38:54 +0800
comments: true
categories: C++
tags: [C++, basis]
keyword: 陈浩翔, 谙忆, C++, C++友元
description:  C++中可以使用friend关键字来将函数、类声明为某个类的友元 友元包括友元函数和友元类 友元具有一些特权，可以访问private的成员.友元只能授予，不能索取，单向，不能传递 
---

C++中可以使用friend关键字来将函数、类声明为某个类的友元  
友元包括友元函数和友元类  
友元具有一些特权，可以访问private的成员  
友元只能授予，不能索取，单向，不能传递(比如a是b的友元，b是c的友元，但a不是c的友元)  

<!-- more -->
----------

#友元函数
在类体中使用friend关键字对友元函数进行声明：  
将非成员函数/一般函数声明为友元：  
friend void func();  //func为非成员函数，不属于任何类  
将其他类的成员函数声明为友元：  
friend void CTime::getNum();//getNum为CTime类的成员。  

#友元类
在类体中使用friend关键字将某类声明为自己的友元类。  
friend CTime;  
 
好处就是方便，可以在其他类或方法直接访问私有成员  

缺点：  
面向对象的基本原则包括封装性和信息隐藏，而由于友元可以访问其他类的私有成员，这是对封装原则的一个破坏。因此使用友元的时候要特别慎重。  

#实例
```C++ Time.h
#ifndef TIME_H
#define TIME_H 
#include "Date.h"
class CTime
{
public:
	CTime();
	CTime(int hour, int minute, int second = 0);
	CTime(int value);
	CTime(CTime& time);
	~CTime();
	void setHour(int hour);
	void setMinute(int minute);
	void setSecond(int second);

	int getHour();
	int getMinute();
	int getSecond(); 

	int getNum() const;

	//friend CDate;//声明友元类,需要声明class CDate;    这样整个类都可以访问CTime的私有成员的了,由于我们只在disPlay函数中访问，所以可以用下面的方法
	friend void CDate::disPlay(const CTime& time);
	friend void func();//告诉编译器，CTime这个类，已经将func()这个函数声明为自己的友元函数，这个声明可以放在本CTime类中任何地方
private:
	int m_nHour;
	int m_nMinute;
	int m_nSecond;
	const int m_nNum;
};

#endif
```
```C++ Date.h
#ifndef DATA_H
#define DATA_H

class CTime;//类的前置声明，一般情况下，是需要声明之后才可以使用的

class CDate
{
public:
	CDate(int year, int month, int day);

	//friend CTime;//在这里声明友元没用，因为友元只能授予，不能索取！
	void disPlay(const CTime& time);//使用的是类的引用(引用也是使用指针来实现的),这里不声明是可以的

private:
	int m_nYear;
	int m_nMonth;
	int m_nDay;

};
#endif
```
main.cpp
```C++ main.cpp
#include<iostream>
#include"Time.h" 
#include "Date.h"
using namespace std;

void func()
{
	CTime time(1,1,1);
	time.m_nHour = 3;
	cout << time.m_nHour << endl;
}

int main()
{
	const CTime time(10,50,20);
	CTime const time2;
	std::cout << time.getNum() << std::endl;
	func();

	CDate date(2015, 1, 26);
	date.disPlay(time);

	getchar();
	return 0;
}
```
##演示结果
![](http://i.imgur.com/3zb3loZ.png)  
 
#源代码下载地址：
<blockquote cite='陈浩翔'>
GITHUB源码下载地址:<strong>【<a href='https://github.com/chenhaoxiang/C-Study/tree/master/20170620/code/friendFunction' target='_blank'>点我进行下载</a>】</strong></p>
</blockquote>


本文章由<a href="http://chenhaoxiang.cn/">[谙忆]</a>编写， 所有权利保留。 
欢迎转载，分享是进步的源泉。
<blockquote cite='陈浩翔'>
<p background-color='#D3D3D3'>转载请注明出处：<a href='http://chenhaoxiang.cn'><font color="green">http://chenhaoxiang.cn</font></a><br><br>
本文源自<strong>【<a href='http://chenhaoxiang.cn' target='_blank'>人生之旅_谙忆的博客</a>】</strong></p>
</blockquote>
