---
layout: post
title: "【C++】成员函数重载二元和一元运算符"
date: 2017-09-04 15:54:54 +0800
comments: true
categories: c-plus-plus
tags: [C++, basis]
keyword: 陈浩翔, 谙忆, C++, 二元, 一元运算符
description: 重载双目运算符时，运算符函数中应该具有两个参数，若运算符函数作为类的成员函数(当运算符重载函数作为类的成员函数时，要求操作数左边必须是一个对象，而函数的参数可以是同类的对象也可以是普通的变量)，则只需要一个参数。 
---

重载双目运算符时，运算符函数中应该具有两个参数，若运算符函数作为类的成员函数(当运算符重载函数作为类的成员函数时，要求操作数左边必须是一个对象，而函数的参数可以是同类的对象也可以是普通的变量)，则只需要一个参数。  

<!-- more -->
----------

#双目运算符

双目运算符就是具有两个操作数的运算符。如 +、-、==等。

对双目运算符而言，成员函数重载运算符的函数参数表中只有一个参数，而用友元函数重载运算符函数参数表中含有两个参数。  

##成员函数重载 == 、>运算符:
```C++ 声明
	bool operator==(CTime& time);
	bool operator>(CTime& time);
```

```C++ 实现
//判断对象的每个成员变量是否相等
bool CTime::operator==(CTime& time)
{
	if (m_nHour == time.m_nHour&&m_nMinute == time.m_nMinute&&m_nSecond == time.m_nSecond)
	{
		return true;
	}
	return false;
}

bool CTime::operator>(CTime& time)
{
	if (m_nHour > time.m_nHour) //先判断两个对象的小时数的大小
	{
		return true;
	}
	else if (m_nHour < time.m_nHour)
	{
		return false;
	}
	else //这是两个对象小时数相等的情况，接下来就判断分钟数
	{
		if (m_nMinute> time.m_nMinute) //再判断两个对象的分钟数的大小
		{
			return true;
		}
		else if (m_nMinute < time.m_nMinute)
		{
			return false;
		}
		else //这是两个对象的时钟和分钟相等的情况下
		{
			if (m_nSecond>time.m_nSecond) //最后比较秒钟
			{
				return true;
			}
			else
			{
				return false;
			}
		}

	}
	
	return false;  //最后就是两个对象相等，也不满足一个对象大于另外一个对象的情况，返回false
}
```

##成员函数重载++运算符

```C++
	CTime operator++();//前置的++
	CTime operator++(int);//后置++，这个int类型的参数只是为了区分，我们并不会使用这个参数，所以我们不需要形参的名字
```

```C++
//前置的++
CTime CTime::operator++() //重载++(前置)运算符
{
	CTime time(0,0,1); //定义了一个秒数为1的对象
	*this = *this + time;//由于前面的函数已经重载了加号运算符，里面已经定义好了相关的操作，所以这句代码调用了加号运算符的重载函数，并将对象的秒数加一
	return *this; //前置++的操作顺序就是先加再返回它的值
}

CTime CTime::operator++(int) //重载++(后置)运算符
{
	CTime time = *this;//后置++的操作规则是先返回再加，所以需要创建一个临时变量保存好这个对象的值
	CTime time2(0, 0, 1);//定义了一个秒数为1的对象
	*this = *this + time2;//同上调用了加法运算符的重载函数
	return *this;//返回加法操作之前的对象的值
}
```

```C++ 测试
	CTime time(10, 50, 20);

	++time;
	std::cout << time.getHour() << ":" << time.getMinute() << ":" << time.getSecond() << endl;

	time++;
	std::cout << time.getHour() << ":" << time.getMinute() << ":" << time.getSecond() << endl;
	 
```
###结果
![](https://i.imgur.com/iUU9UYt.png)  


#源代码下载地址：
<blockquote cite='陈浩翔'>
GITHUB源码下载地址:<strong>【<a href='https://github.com/chenhaoxiang/C-Study/tree/master/20170904/code/OverloadOperator' target='_blank'>点我进行下载</a>】</strong>
</blockquote>


本文章由<a href="http://chenhaoxiang.cn/">[谙忆]</a>编写， 所有权利保留。 
欢迎转载，分享是进步的源泉。
<blockquote cite='陈浩翔'>
<p background-color='#D3D3D3'>转载请注明出处：<a href='http://chenhaoxiang.cn'><font color="green">http://chenhaoxiang.cn</font></a><br><br>
本文源自<strong>【<a href='http://chenhaoxiang.cn' target='_blank'>人生之旅_谙忆的博客</a>】</strong></p>
</blockquote>
