#ifndef STRING_H//ͷ�ļ���ʿ������ͷ�ļ�����α���
#define STRING_H
#include<iostream>  //�������ͷ�ļ�
using namespace std; //�����ռ�
class String
{
public://���е�����
	String(const char*); //���캯��
	String(int n,char c); //�����С�Ĺ��캯��
	~String(); //��������

public:
	String(String &str);  //�������캯��
	const String& operator=(const String& str);//��ֵ��������أ������ڲ���Ҫ�޸Ĳ�����ֵ�ĵط���Ӧ������Ϊconst

	char operator[](int pos)const;//�±�������������
	char at(int pos)const;//���Խ����±����

	int size()const; //�ַ����Ŀռ��С
	int length()const; //�ַ������ַ���С
	bool empty()const; //�ж�Ϊ�յĺ���

	const String& operator+=(const String& str); //�ַ���������
	bool operator==(const String& str);//�ַ���������ж�
	bool compare(const String& str);//�ַ���������ж�

	friend istream& operator>>(istream& input, String& str); //���������������
	friend ostream& operator<<(ostream& output, String& str); //���������������
private:
	char* m_pBuff;//�����ַ������׵�ַ
	int m_nRealLen;  //�ַ������ַ���С
	int m_nBuffSize;  //�ַ����Ŀռ��С

};

#endif
