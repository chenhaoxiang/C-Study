---
layout: post
title: "【C++】C++运算符重载-基础"
date: 2017-08-10 18:40:54 +0800
comments: true
categories: c-plus-plus
tags: [C++, basis]
keyword: 陈浩翔, 谙忆, C++, 运算符重载, 运算符重载基础  
description: 运算符重载就是对已有的运算符赋予新的含义，实现新的功能。运算符重载，如+，它可以对int、float、string类型进行加法运算。
---

本篇博客讲解:  
运算符重载基础，以及实例  


<!-- more -->
----------

#运算符重载基础
运算符重载就是对已有的运算符赋予新的含义，实现新的功能。  

运算符重载，如“+”，它可以对int、float、string类型进行加法运算。  
```<<```是C++中的左移运算符，但是在输出操作中与cout配合被称为流插入运算符，可以进行输出。  
```>>```是右移运算符，与cin配合使用被称为流提取运算符。  
它们都被称为运算符重载。  

我们也可以根据我们的需要对C++中现有的运算符进行重载，来赋予这些运算符新的含义。  
如CTime类，重载+运算符，实现两个CTime对象的相加。  

介绍运算符重载前，我们看下如何来实现两个CTime对象相加。   
CTime重载+运算符实现两个CTime对象的相加，  
time1 + time2   
首先需要定义一个重载的运算符函数，此后在执行被重载的运算符时，系统将自动调用该运算符函数。  
**运算符重载实际上是函数的重载**。  
  
运算符重载的格式：返回类型 operator运算符（参数列表）  
```
CTime operator+(CTime& time1, CTime& time2)
```  
 
重载的运算符函数可以作为一般的函数，也可以作为类的成员函数。  
```
CTime operator+(CTime& time) 
```  
下面通过代码来看吧
普通的，通过函数来相加:
```C++ Time.h中声明友元函数
friend CTime addTime(CTime& time1, CTime& time2); 
```
```C++ main.cpp中直接实现
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

//输出
int main()
{ 
	CTime time(10, 50, 20);
	CTime time2(12); 
	CTime time3 = addTime(time, time2); 
	std::cout << time3.getHour() << ":" << time3.getMinute() << ":" << time3.getSecond() << endl; 
	getchar();
	return 0;
}
```
+号运算重载：
```C++ Time.h中声明
friend CTime operator+(CTime& time1, CTime& time2);
```
```C++ main.cpp中实现

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

int main()
{ 
	CTime time(10, 50, 20);
	CTime time2(12); 
 
	CTime time4 = time + time2;	//使用+号重载对两个CTime对象进行相加
	std::cout << time4.getHour() << ":" << time4.getMinute() << ":" << time4.getSecond() << endl;

	getchar();
	return 0;
}
```
##输出结果:
![](http://i.imgur.com/3xtl8kk.png)  
 
在CTime类内部定义+号重载运算符  
```C++ Time.h中声明
CTime operator+(CTime& time);
```

```C++ Time.cpp中实现
CTime CTime::operator+(CTime& time)
{
	int hour = 0, minute = 0;
	int second = this->m_nSecond + time.m_nSecond;
	if (second > 60)
	{
		minute++;
		second -= 60;
	}

	minute += (this->m_nMinute + time.m_nMinute);
	if (minute > 60)
	{
		hour++;
		minute -= 60;
	}

	hour += (this->m_nHour + time.m_nHour);
	if (hour > 24)
	{
		hour -= 24;
	}
	return CTime(hour, minute, second);
}
```
```C++ main.cpp中调用

int main()
{ 
	CTime time(10, 50, 20);
	CTime time2(12); 
	CTime time4 = time.operator+(time2);
	std::cout << time4.getHour() << ":" << time4.getMinute() << ":" << time4.getSecond() << endl;

	getchar();
	return 0;
}
```
结果和前面的是一样的。  
 

#源代码下载地址：
<blockquote cite='陈浩翔'>
GITHUB源码下载地址:<strong>【<a href='https://github.com/chenhaoxiang/C-Study/tree/master/20170810/code/operatorOverloadingBase' target='_blank'>点我进行下载</a>】</strong>
</blockquote>

本文章由<a href="http://chenhaoxiang.cn/">[谙忆]</a>编写， 所有权利保留。 
欢迎转载，分享是进步的源泉。
<blockquote cite='陈浩翔'>
<p background-color='#D3D3D3'>转载请注明出处：<a href='http://chenhaoxiang.cn'><font color="green">http://chenhaoxiang.cn</font></a><br><br>
本文源自<strong>【<a href='http://chenhaoxiang.cn' target='_blank'>人生之旅_谙忆的博客</a>】</strong></p>
</blockquote>
