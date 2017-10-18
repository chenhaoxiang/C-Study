#include"String.h" //包含类的声明头文件

#define EXT_LEN 50  //定义一个宏，用户申请的内存大小，我们实际上为字符串分配的空间要多EXT_LEN，以便字符串的连接
String::String(const char* pStr)
{
	m_nRealLen = strlen(pStr); //获得字符串的实际大小
	m_pBuff = new char[m_nRealLen + EXT_LEN]; //实际分配的内存比字符串多了EXT_LEN
	//strcpy(m_pBuff, pStr);  //C提供的一个字符串函数，将后面参数的字符复制到第一个字符串后面，并添加一个结束字符\0，C中字符串的指针指向的是字符串的首地址，这个函数遇到\0以为字符串结束
	memcpy(m_pBuff, pStr, m_nRealLen);  //内存拷贝，遇到\0不会结束，提供了需要拷贝的数据的长度
	m_nBuffSize = m_nRealLen + EXT_LEN;  //计算字符串的空间大小
}

String::String(int n, char c)  //构造一个由n个一种字符串构成的字符串
{
	m_pBuff = new char[n + EXT_LEN];  //实际分配的内存比字符串多了EXT_LEN
	for (int i = 0; i < n; i++)
	{
		m_pBuff[i] = c;  //利用下标运算符和循环赋值
	}
	m_nRealLen = n;  //赋值字符串大小
	m_nBuffSize = n + EXT_LEN;  //分配的空间大小
}

String::~String()
{
	if (m_pBuff)   //判断字符串指针是否为空
	{
		delete[] m_pBuff;
		m_pBuff = NULL;  //避免野指针的产生
	}

	m_nRealLen = 0;  //对字符串的长度清零
	m_nBuffSize = 0; //对分配的空间清零 
}

String::String(String& str)
{
	//这里不用判断 左操作数的字符串首地址是否指向内存，就销毁再指向空
	//因为左操作数m_pBuff开始没有赋值，默认会指向一个无法访问的地址，在这里销毁无法访问的地址，就会出现异常
	//if (m_pBuff) //如果左操作数的字符串首地址指向内存，就销毁再指向空
	//{
	//	delete[]m_pBuff;
	//	m_pBuff = NULL;
	//}
	m_pBuff = new char[str.length() + EXT_LEN];//重新分配一段空间
	//strcpy(m_pBuff, str.m_pBuff);
	memcpy(m_pBuff, str.m_pBuff, str.length());  //字符串的拷贝
	m_nRealLen = str.length();   //实际长度等于字符串的字符长度
	m_nBuffSize = m_nRealLen + EXT_LEN;
}

const String& String::operator=(const String& str)
{
	if (this == &str)  //避免自赋值
	{
		return *this;
	}

	if (m_pBuff) //如果左操作数的字符串首地址指向内存，就销毁再指向空
	{
		delete[]m_pBuff;
		m_pBuff = NULL;
	}

	m_pBuff = new char[str.length() + EXT_LEN];  //分配空间
	//strcpy(m_pBuff, str.m_pBuff);
	memcpy(m_pBuff, str.m_pBuff, str.length());
	m_nRealLen = str.length();
	m_nBuffSize = m_nRealLen + EXT_LEN;

	return *this;  //返回左操作数的引用
}

char String::operator[](int nPos)const
{

	return m_pBuff[nPos];  //使用了C里面字符串的下标访问
}

char String::at(int nPos)const
{
	if (nPos >= m_nRealLen)  //如果给出的下标超出了字符串的实际长度，就抛出一个异常
	{
		//throw exception
	} 
	return m_pBuff[nPos];
}

int String::size()const
{
	return m_nBuffSize;  //返回字符串的空间大小
}

int String::length()const
{
	return m_nRealLen;  //返回字符串的字符大小
}

bool String::empty()const
{
	return !m_nRealLen;  //根据字符串的实际长度返回是否为空
}

const String& String::operator+=(const String& str)
{
	if (m_nBuffSize - m_nRealLen >= str.length())  
//计算 空间大小减去字符大小 剩余的分配了的但是没有使用的空间 是否可以连接后面的字符串，
//如果可以不用再次分配空间直接连接，就不用再分配空间了。
	{
		//strcat(m_pBuff, str.m_pBuff);
		memcpy(m_pBuff + m_nRealLen, str.m_pBuff, str.length());
		m_nRealLen = m_nRealLen + str.length();
		
	}	
	else  //需要重新分配空间情况
	{
		int nLen = m_nRealLen + str.length();
		char*p = new char[nLen + EXT_LEN];
		//strcpy(p, m_pBuff);
		memcpy(p, m_pBuff, m_nRealLen); //将前面的字符串拷贝到新申请的空间中
		//strcpy(p + m_nRealLen, str.m_pBuff);
		memcpy(p + m_nRealLen, str.m_pBuff, str.length());  
		//因为新空间已经有了一个字符串，我们不能再从首地址拷贝开始了，我们将首地址加上已经拷贝过去的字符串的长度，
		//从这个位置开始后面没有拷贝字符串的位置拼接好第二个字符串
		m_nRealLen = nLen;
		m_nBuffSize = nLen + EXT_LEN;

		if (m_pBuff)  //如果前面的字符串不是空的，我们就删除前面拼接之前的第一个字符串
		{
			delete[]m_pBuff;
		}

		m_pBuff = p;  //将拼接好的字符串赋值给对象指向字符串首地址的指针
	}

	return *this;
}
istream& operator>>(istream& input, String& str)
{
	std::cin.get(str.m_pBuff, str.size(), '\n');  
	//不直接使用cin是怕cin的输入没有结束或者字符串的长度导致越界，这个是c的一个读入指定长度字符串的函数，
	//该函数将str.size()长度的字符串读取到str.m_pBuff中，第三个字符是结束字符，即使没有达到指定长度，遇到这个字符也会结束的。
	return input;
}
ostream& operator<<(ostream& output, String& str)
{
	for (int i = 0; i < str.length(); i++)  
	//因为cout对字符串的输出是以\0来结束输出，我们使用的memcpy函数是不会在字符串的结尾自动加入结束符号\0，
	//所以我们需要利用循环和它的实际长度来实现遍历输出
	{
		std::cout.put(str[i]);  //每次向屏幕输出一个字符
	}
	return output;
}