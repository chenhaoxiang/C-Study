---
layout: post
title: "【C++】C++类和对象"
date: 2017-05-20 13:38:54 +0800
comments: true
categories: C++
tags: [C++, basis]
keyword: 陈浩翔, 谙忆, C++, C++定义类和对象
description: 每个实体都可以看成一个对象。在C++中，对象的类型被称为类。类代表了某一批对象的共性和特征。类是对象的抽象，而对象是类的具体实现。在C++中要使用一个类，首先要定义一个类。
---

最近在公司弄游戏开发，C++基础也不是特别好，所以就打算继续开始学习C++。

既然从头学习C++，就打算写一个系列教程。C++学习之路。
我是在边学习C++，边学习cocos2dx 3.X，白天时间不是很多，
先把C++系列写完再写coco2dx的教程。
希望对大家有帮助。
（可能基础知识不是很详细，对没有其他语言基础的人来说不是很友好，请见谅）

<!-- more -->
----------

每个实体都可以看成一个对象。在C++中，对象的类型被称为类。
类代表了某一批对象的共性和特征。

类是对象的抽象，而对象是类的具体实现。

在C++中要使用一个类，首先要定义一个类。

#定义类

定义类和声明结构体的结构是相似的。

##定义结构体
```C++ 定义结构体

struct Student{
	char name[128];
	int age;
	char add[128];
};

```

##类的定义格式
```C++ 类的定义格式

class 类名{
	private:
		成员数据;
		成员函数;
	public:
		成员数据;
		成员函数;
	protected:
		成员数据;
		成员函数;
};
```
private,public,protected这3个限定符就不介绍了  
建议把：  
public放前面  
private放最后  

别忘了最后的分号哦。  
struct默认是public  
class默认是private  

##一个简单的例子
```C++ 
// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
using namespace std;

class Student
{
public:
	void print()
	{
		cout <<  age  << endl;
	}
	int getAge();
private:
	char name[128] ;
	int age = 20;
	char addr[128] ;
};
inline int Student::getAge(){
	return age;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Student stu;
	stu.print();
	stu.getAge();
	getchar();
	return 0;
}
```

 
#类和对象的使用

##对象成员的引用

程序中访问对象成员有以下三种方法：  
1、通过对象名和成员访问运算符"."来访问  
2、通过指向对象的指针来访问  
3、通过引用来访问  

```C++
	Student stu;
	//通过对象名和成员访问运算符"."来访问  
	stu.print();
	stu.getAge();
	//通过指向对象的指针来访问  
	Student *p = &stu;
	p->print();
	p->getAge();

	//通过引用来访问  
	Student &s = stu;//表明s是stu的别名
	s.print();
	s.getAge();
```

##类声明和成员函数实现的分离
类的定义和成员函数的实现一般不放在一起，而是放在不同的文件中。

一般来说，在大型项目中，将类的声明放在单独的头文件中，一般以类名命名。
成员函数的实现放在该类对应的cpp文件中。
这样就将类的声明和实现进行了分离.

如果需要使用某个对象，直接引用那个对象声明的头文件即可，而不需要再重复声明了！

这样工程的结构就清晰很多了。


这章很简单，没多少要写的，你有语言基础的话，这章用个5分钟就可以过了~~
这里我写了2个例子
#源代码下载地址：
<blockquote cite='陈浩翔'>
GITHUB源码下载地址:<strong>【<a href='https://github.com/chenhaoxiang/C-Study/tree/master/20170520' target='_blank'>点我进行下载</a>】</strong></p>
</blockquote>

本文章由<a href="http://chenhaoxiang.cn/">[谙忆]</a>编写， 所有权利保留。 
欢迎转载，分享是进步的源泉。
<blockquote cite='陈浩翔'>
<p background-color='#D3D3D3'>转载请注明出处：<a href='http://chenhaoxiang.cn'><font color="green">http://chenhaoxiang.cn</font></a><br><br>
本文源自<strong>【<a href='http://chenhaoxiang.cn' target='_blank'>人生之旅_谙忆的博客</a>】</strong></p>
</blockquote>
