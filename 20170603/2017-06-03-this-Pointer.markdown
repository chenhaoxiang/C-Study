---
layout: post
title: "【C++】This指针和复制构造函数"
date: 2017-06-03 13:38:54 +0800
comments: true
categories: C++
tags: [C++, basis]
keyword: 陈浩翔, 谙忆, C++, This指针和复制构造函数
description: 在每个成员函数中，都包含一个特殊的指针。这个指针的名字是固定的，就是this指针。this指针是指向类对象的指针，它的值是当前被调用的所在对象的地址！  
---

在声明一个类的时候，是没有分配存储空间的，只有在真正定义一个对象的时候，程序才会为这个对象分配相应的存储空间。  
如果定义了多个对象，这些对象都有自己的存储空间，但是这些对象都是用相同的成员方法的。  

当不同的对象调用成员方法时，怎么保证就是这个对象的成员？

<!-- more -->
----------

#this指针

在每个成员函数中，都包含一个特殊的指针。  
这个指针的名字是固定的，就是this指针。  
this指针是指向类对象的指针，它的值是当前被调用的所在对象的地址！  

this指针是指向本类对象的指针，它作为参数传递给成员函数  
this指针是隐式使用的。由编译器自动实现，我们不必人为的在形参中添加this指针。 

因为this表示这个对象的指针，所以*this就表示这个对象了  

(*this).调用成员变量/函数和this->调用成员变量/函数,是一样的效果！  
注意给*this添加括号，因为.运算符的优先级比较高  

#复制构造函数

复制构造函数和普通构造函数有一些相似处的，也没有返回值，类名作为函数名！  

复制构造函数一种特殊的构造函数，在创建一个新的对象时将其他对象作为参数时，  
编译器将会调用复制构造函数。不提供时使用默认构造函数。默认构造函数内部各个成员变量赋值。  
创建之后，新对象是老对象的副本，二者值相同。但具有不同的存储空间。  
```C++ 形式
CTime(CTime& time);//使用类名对象作为参数，传引用
```

##调用复制构造函数的时机：
在什么情况下使用复制构造函数  
###1.以其他对象作为参数创建新对象时。  
比如:创建一个新的对象的时候，把原来的一个对象作为参数传递给新的对象作为构造函数  
```
CTime time;
CTime time2(time);//会自动执行复制构造函数，复制成员等  
```  
```c++ 复制构造函数
CTime::CTime(CTime& time){
	m_hour = time.m_hour;
	m_minute = time.m_minute;
	m_second = time.m_second;
}
```

```c++ 通过复制构造函数复制原来的time
	CTime time;
	time.setHour(10);//通过成员方法设置值
	time.setMinute(20);
	time.setSecond(30);

	cout << time.getHour() << ":" << time.getMinute() << ":" << time.getSecond() << endl;
	//输出结果： 10:20:30

	CTime time2(time);

	cout << time2.getHour() << ":" << time2.getMinute() << ":" << time2.getSecond() << endl;

```
(注意，构造函数实现的时候，需要在其他函数前面先实现)  
复制构造函数也是构造函数的一种！  

###2.类对象（传值）作为函数参数时。
```C++ 类对象（传值）作为函数参数时。
#include <iostream>
#include "Time.h"
using namespace std;

void func(CTime time){
	cout << time.getHour()<<endl;
}

int main(){
	CTime time;
	time.setHour(10);//通过成员方法设置值
	time.setMinute(20);
	time.setSecond(30);
	CTime time2(time);//第一次调用复制构造函数

	func(time);//第二次调用复制构造函数  复制给func中的形参time

	cout << time.getHour() << ":" << time.getMinute() << ":" << time.getSecond() << endl;
	//输出结果： 10:20:30

	cout << time2.getHour() << ":" << time2.getMinute() << ":" << time2.getSecond() << endl;

	getchar();//这句是为了防止输出窗口秒关闭
	return 0;
}
```
  
###3.类对象作为函数返回值时。
```C++ 类对象作为函数返回值时。
#include <iostream>
#include "Time.h"
using namespace std;

void func(CTime time){
	cout << time.getHour()<<endl;
}
CTime func1(CTime time){
	//复制给func1中的形参time 也会调用一次复制构造函数
	cout << time.getHour() << endl;
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
	
	cout << time.getHour() << ":" << time.getMinute() << ":" << time.getSecond() << endl;
	//输出结果： 10:20:30


	cout << time2.getHour() << ":" << time2.getMinute() << ":" << time2.getSecond() << endl;

	getchar();//这句是为了防止输出窗口秒关闭
	return 0;
}
```

上面就是复制构造函数使用的三种情形！  

如果我们把复制构造函数 CTime::CTime(CTime& time)修改为CTime::CTime(CTime time)   
CTime& time是一个引用类型的参数，现在将引用去掉的话，就满足了调用复制构造函数中的一种，以类对象（传值）作为函数参数时，  
这样在使用的时候，就会造成死循环！  

所以注意复制构造函数是传引用来实现的！    

我们使用类对象作为函数参数的时候，以及返回一个对象的时候，代价是很大的，  
因为伴随着对象的创建和销毁，还伴随着复制构造函数的调用， 所以一般使用传引用来规避这种代价！  
引用传递：  
形参相当于是实参的“别名”，对形参的操作其实就是对实参的操作，在引用传递过程中，被调函数的形式参数虽然也作为局部变量在栈中开辟了内存空间，但是这时存放的是由主调函数放进来的实参变量的地址。被调函数对形参的任何操作都被处理成间接寻址，即通过栈中存放的地址访问主调函数中的实参变量。正因为如此，被调函数对形参做的任何操作都影响了主调函数中的实参变量。  

#源代码下载地址：
<blockquote cite='陈浩翔'>
GITHUB源码下载地址:<strong>【<a href='http://chenhaoxiang.cn' target='_blank'>点我进行下载</a>】</strong></p>
</blockquote>


本文章由<a href="http://chenhaoxiang.cn/">[谙忆]</a>编写， 所有权利保留。 
欢迎转载，分享是进步的源泉。
<blockquote cite='陈浩翔'>
<p background-color='#D3D3D3'>转载请注明出处：<a href='http://chenhaoxiang.cn'><font color="green">http://chenhaoxiang.cn</font></a><br><br>
本文源自<strong>【<a href='http://chenhaoxiang.cn' target='_blank'>人生之旅_谙忆的博客</a>】</strong></p>
</blockquote>
