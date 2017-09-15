---
layout: post
title: "【C++】流插入、提取运算符和类型转换"
date: 2017-09-05 17:28:34 +0800
comments: true
categories: c-plus-plus
tags: [C++, basis]
keyword: 陈浩翔, 谙忆, C++, 流插入, 运算符
description: 流插入,流提取运算符重载和类型转换的讲解和实例 流插入运算符"<<"和流提取运算符">>"也可以被用来重载。重载流插入和提取运算符的运算符函数，不能作为类的成员函数，只能作为普通函数  
---

流插入,流提取运算符重载和类型转换的讲解和实例

重载流插入和提取运算符的运算符函数，不能作为类的成员函数，只能作为普通函数  
<!-- more -->
----------

#流插入,流提取运算符重载

流插入运算符"<<"和流提取运算符">>"也可以被用来重载。  

我们可以使用cout对一个int，string等等类型的数据进行输出，我们却不可以对我们自己定义的一个类的对象进行直接输出，因为我们这个类是没有"<<"运算符的。  

"<<"运算符是有两个操作数的，它是一个双目运算符，平时貌似只给了它一个操作数,形如cout<<a;我们只知道a是一个变量，是它的一个操作数，还有一个操作数其实是cout！  

cout也是它的一个操作数，cout是一个在ostream类里面已经定义好了的对象，ostream类还为我们定义好了系统中已经存在的类型的输出，如int，double…..这个对象作为了它的左操作数。显然cout这个对象是不属于我们新声明的类的，但是它又需要作为第一个参数，它是没有办法调用我们这个类的成员函数的，所以只能将"<<"运算符的重载声明为友元函数。  

可以为CTime类定义重载的流插入和流提取运算符。  

重载之后就可以直接对CTime对象进行输入和输出：  
```c++
cout<<time;
cin>>time;
```
**重载流插入和提取运算符的运算符函数，不能作为类的成员函数，只能作为普通函数** 这是一个规定，没有为什么    

"<<"和">>"重载的函数声明如下：  
```C++
istream& operator>> (istream& input, CTime& time);//输入流
ostream& operator<<(ostream& output, CTime& time);//输出流
```
istream和ostream分别是输入流类和输出流类。cin和cout就分别是istream和ostream的对象。  
注意:  
**重载"<<"流插入运算符的函数第一个参数和返回类型必须是ostream&类型。  
重载">>"流提取运算符的函数第一个参数和返回类型必须是istream&类型。**  
第二个参数是用户自定义的类  

##流提取运算符"<<"重载
```C++ 流提取运算符重载
ostream& operator<<(ostream& output, CTime& time) //返回ostream类的对象output的引用是为了实现连续输出，如cout<<a<<b;
{
cout<<time.getHour()<<time.getMinute()<<time.getSecond()<<endl;
return output;
}
```

##流输入运算符">>"重载
```C++ 流输入运算符">>"重载
//因为要用到CTime类的成员，所以把流提取运算符作为CTime类的友元
istream& operator>>(istream& input, CTime& time)
{
	//可以直接使用CTIme类的数据成员了
	cin >> time.m_nHour >> time.m_nMinute >> time.m_nSecond;
	return input;
}
```
```C++ Time.h声明友元
friend istream& operator>>(istream& input, CTime& time);
```

在重载完流插入和提取运算符后，我们就可以对该类使用<<输出数据，使用>>输入数据。这样是非常直观的。
```C++
CTime time(10, 50, 20);
CTime time2(12); 

cin >> time;  //在我们重载了输入输出运算符之后，我们也可以像C++里面预定义好的数据类型一样对这个类的对象进行输入输出

cout << time << time2;

operator>>(cin, time);
operator<<(cout, time);
operator<<(cout, time2);
```
###结果
![](https://i.imgur.com/umGMKFJ.png)  


#类型转换

##使用构造函数进行类型转换

在为CTime类重载+运算符后，我们就可以对两个CTime对象使用+运算符进行操作。  
但仍然不能使用+运算符将一个CTime对象和一个int类型相加。为了实现它，我们可以先将int类型转换为一个CTime的临时对象，然后在进行相加。  
如下：  ```time + CTime(3)```

CTime(3)这种形式很类似于强制类型转换，将int类型转换为CTime类型。之所以可以进行此种转换，是因为已经为CTime对象定义了具有一个int类型参数的构造函数。因此具有一个参数的构造函数可以用来做类型转换，称之为**转换构造函数**    

有了类型转换函数，在需要CTime类型参数的地方可以使用int类型代替  
```C++
CTime time3(20);
CTime time4 = 20;//和下面那句效果一样的,自动类型转换
CTime time5 = CTime(20);

func(time);
func(10);//编译器会自动构造一个CTime的临时对象
```

如果我们期望避免这种转换，我们可以在含有一个参数的构造函数前面加上声明explicit  
如:
```c++ Time.h文件
explicit CTime(int value);
```  
这样，我们使用前面的func(10),CTime time4 = 20;的时候，编译器就会报错  
![](https://i.imgur.com/PU5wW9T.png)  


##类型转换函数进行类型转换

类型转换函数用以将类的对象转换另一种数据类型的函数。  
类型转换函数没有参数，没有返回类型。它是成员函数。  

如 可以将CTime类对象转换int类型。  
```C++
int nSecond = time;  //执行了将对象转换为int类型的操作，调用类型转换函数
```
类型转换函数的声明形式：  
```C++ Time.h
operator int();  //int为它的返回类型
```
下面定义一个类型转换函数：  
```C++
CTime::operator int() //将一个CTime类的对象转换成秒数
{
	return m_nHour * 60 * 60 + m_nMinute * 60 + m_nSecond;
}
```
```C++ 
int nSecond = time;
cout << nSecond;
```
![](https://i.imgur.com/tBo8bmZ.png)  
最后面的那行输出 6:3:3的秒数 

类型转换函数在平时比较少见，在这里只介绍了一下如何使用的。  


#源代码下载地址：
<blockquote cite='陈浩翔'>
GITHUB源码下载地址:<strong>【<a href='https://github.com/chenhaoxiang/C-Study/tree/master/20170905/code/FlowInsertExtractOperator' target='_blank'>点我进行下载</a>】</strong>
</blockquote>


本文章由<a href="http://chenhaoxiang.cn/">[谙忆]</a>编写， 所有权利保留。 
欢迎转载，分享是进步的源泉。
<blockquote cite='陈浩翔'>
<p background-color='#D3D3D3'>转载请注明出处：<a href='http://chenhaoxiang.cn'><font color="green">http://chenhaoxiang.cn</font></a><br><br>
本文源自<strong>【<a href='http://chenhaoxiang.cn' target='_blank'>人生之旅_谙忆的博客</a>】</strong></p>
</blockquote>
 