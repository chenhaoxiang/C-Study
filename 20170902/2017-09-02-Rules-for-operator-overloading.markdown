---
layout: post
title: "【C++】C++运算符重载的规则"
date: 2017-09-02 18:40:54 +0800
comments: true
categories: c-plus-plus
tags: [C++, basis]
keyword: 陈浩翔, 谙忆, C++, 运算符重载, 运算符重载的规则
description: 被重载的运算符必须是已经存在的C++运算符，不能重载自己创建的运算符。运算符被重载之后，原有功能仍然保留。只是扩展了原有功能。
---

本篇博客讲解:  
运算符重载的规则，以及实例  

<!-- more -->
----------

#运算符重载的规则 
**被重载的运算符必须是已经存在的C++运算符，不能重载自己创建的运算符**。  
运算符被重载之后，**原有功能仍然保留**。只是扩展了原有功能。  
重载不能改变运算符运算对象的个数。  
+运算符具有两个操作数，在+运算符函数作为类(例如上个例子中的CTime)的成员函数的时候，有一个参数是隐含的，也就是当前的对象，使用this指针来引用。  
另一个参数通过函数参数指定。  

可以重载的运算符：  
```
1.算术运算符：+，-，*，/，%，   
2.逻辑运算符：&&，||，！  
3.关系运算符：>,<,=,>=,<=,==,!=  
4.位操作符：～，<<(左移)，>>(右移)，&，^），|  
5.自增自减运算符：++，--  
6.复合赋值运算符：+=，-=，*=，/=，%=  
7.其他：&(取地址符)、*、 () 、->(成员访问运算符) 、[] (下标运算符)、.new/delete、>>、<<  
```

不能重载的运算符：
```
?:(条件运算符) 
.(成员访问运算符)
*(成员指针访问运算符)
::(域运算符)
sizeof(sizeof 是运算符,而不是函数)
```
不需要重载的运算符
```
=（赋值）和&(取地址符)
```  
因为编译器会为每个类自动实现一个默认的赋值运算符/取地址符的成员函数    
当然，我们可以重写这个默认的成员函数。  
```C++ CTime.h声明
CTime& operator=(CTime& time);//返回的是对象的引用形式
```
```C++ CTime.cpp定义
CTime& CTime::operator=(CTime& time)
{
	//为了防止同一个对象进行赋值，需要先判断一下,判断地址是不是一样
	if (this == &time)
	{
		return *this;
	}

	//默认的是各个成员分别赋值
	m_nHour = time.m_nHour;
	m_nMinute = time.m_nMinute;
	m_nSecond = time.m_nSecond;

	return *this;//返回当前这个对象
}
```

友元函数的运算符重载  
```C++ CTime.h声明
//friend为友元函数的关键字,这个符号运算符重载函数的参数类型至少有一个类类型或者类的引用,也就是说，可以有一个参数不是对象
friend CTime operator+(CTime& time1, CTime& time2);
```
```C++ main.cpp实现-使用类来实现
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
```


赋值函数  
普通函数和类的成员函数都可以作为类的友元，但什么时候应该使用普通函数，什么时候应该使用成员函数方式呢？  

**普通函数形式的运算符函数一般都声明为类的友元函数**，用以访问类的私有数据成员。  
这样可以减低开销，但破坏封装性。因此建议尽量使用成员函数形式。  

**一般将单目运算符重载为成员函数，将双目运算符重载为友元函数**  

成员函数方式要求左侧的参数要与类的类型相同。而普通函数则要求实参顺序与形参类型顺序一致。  

如  
有的运算符必须定义为类的成员函数
```
=、赋值运算符
[]、下标运算符
() 函数调用运算符
```

有的运算符不能定义为类的成员函数，只能定义为类的友元  
```
<<、>>
```

运算符重载可以在函数内执行任意的操作，比如可以将+定义成两个对象相减的操作  
但是这样违背我们日常使用的习惯，容易使用误用，减低程序可读性，因此必须保证重载的运算符与该运算符应用于标准数据类型时所具有的功能。 


#源代码下载地址：
<blockquote cite='陈浩翔'>
GITHUB源码下载地址:<strong>【<a href='https://github.com/chenhaoxiang/C-Study/tree/master/20170902/code/operatorOverloadingBase' target='_blank'>点我进行下载</a>】</strong></p>
</blockquote>


本文章由<a href="http://chenhaoxiang.cn/">[谙忆]</a>编写， 所有权利保留。 
欢迎转载，分享是进步的源泉。
<blockquote cite='陈浩翔'>
<p background-color='#D3D3D3'>转载请注明出处：<a href='http://chenhaoxiang.cn'><font color="green">http://chenhaoxiang.cn</font></a><br><br>
本文源自<strong>【<a href='http://chenhaoxiang.cn' target='_blank'>人生之旅_谙忆的博客</a>】</strong></p>
</blockquote>
