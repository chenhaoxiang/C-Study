#include"String.h" //�����������ͷ�ļ�

#define EXT_LEN 50  //����һ���꣬�û�������ڴ��С������ʵ����Ϊ�ַ�������Ŀռ�Ҫ��EXT_LEN���Ա��ַ���������
String::String(const char* pStr)
{
	m_nRealLen = strlen(pStr); //����ַ�����ʵ�ʴ�С
	m_pBuff = new char[m_nRealLen + EXT_LEN]; //ʵ�ʷ�����ڴ���ַ�������EXT_LEN
	//strcpy(m_pBuff, pStr);  //C�ṩ��һ���ַ���������������������ַ����Ƶ���һ���ַ������棬�����һ�������ַ�\0��C���ַ�����ָ��ָ������ַ������׵�ַ�������������\0��Ϊ�ַ�������
	memcpy(m_pBuff, pStr, m_nRealLen);  //�ڴ濽��������\0����������ṩ����Ҫ���������ݵĳ���
	m_nBuffSize = m_nRealLen + EXT_LEN;  //�����ַ����Ŀռ��С
}

String::String(int n, char c)  //����һ����n��һ���ַ������ɵ��ַ���
{
	m_pBuff = new char[n + EXT_LEN];  //ʵ�ʷ�����ڴ���ַ�������EXT_LEN
	for (int i = 0; i < n; i++)
	{
		m_pBuff[i] = c;  //�����±��������ѭ����ֵ
	}
	m_nRealLen = n;  //��ֵ�ַ�����С
	m_nBuffSize = n + EXT_LEN;  //����Ŀռ��С
}

String::~String()
{
	if (m_pBuff)   //�ж��ַ���ָ���Ƿ�Ϊ��
	{
		delete[] m_pBuff;
		m_pBuff = NULL;  //����Ұָ��Ĳ���
	}

	m_nRealLen = 0;  //���ַ����ĳ�������
	m_nBuffSize = 0; //�Է���Ŀռ����� 
}

String::String(String& str)
{
	//���ﲻ���ж� ����������ַ����׵�ַ�Ƿ�ָ���ڴ棬��������ָ���
	//��Ϊ�������m_pBuff��ʼû�и�ֵ��Ĭ�ϻ�ָ��һ���޷����ʵĵ�ַ�������������޷����ʵĵ�ַ���ͻ�����쳣
	//if (m_pBuff) //�������������ַ����׵�ַָ���ڴ棬��������ָ���
	//{
	//	delete[]m_pBuff;
	//	m_pBuff = NULL;
	//}
	m_pBuff = new char[str.length() + EXT_LEN];//���·���һ�οռ�
	//strcpy(m_pBuff, str.m_pBuff);
	memcpy(m_pBuff, str.m_pBuff, str.length());  //�ַ����Ŀ���
	m_nRealLen = str.length();   //ʵ�ʳ��ȵ����ַ������ַ�����
	m_nBuffSize = m_nRealLen + EXT_LEN;
}

const String& String::operator=(const String& str)
{
	if (this == &str)  //�����Ը�ֵ
	{
		return *this;
	}

	if (m_pBuff) //�������������ַ����׵�ַָ���ڴ棬��������ָ���
	{
		delete[]m_pBuff;
		m_pBuff = NULL;
	}

	m_pBuff = new char[str.length() + EXT_LEN];  //����ռ�
	//strcpy(m_pBuff, str.m_pBuff);
	memcpy(m_pBuff, str.m_pBuff, str.length());
	m_nRealLen = str.length();
	m_nBuffSize = m_nRealLen + EXT_LEN;

	return *this;  //�����������������
}

char String::operator[](int nPos)const
{

	return m_pBuff[nPos];  //ʹ����C�����ַ������±����
}

char String::at(int nPos)const
{
	if (nPos >= m_nRealLen)  //����������±곬�����ַ�����ʵ�ʳ��ȣ����׳�һ���쳣
	{
		//throw exception
	} 
	return m_pBuff[nPos];
}

int String::size()const
{
	return m_nBuffSize;  //�����ַ����Ŀռ��С
}

int String::length()const
{
	return m_nRealLen;  //�����ַ������ַ���С
}

bool String::empty()const
{
	return !m_nRealLen;  //�����ַ�����ʵ�ʳ��ȷ����Ƿ�Ϊ��
}

const String& String::operator+=(const String& str)
{
	if (m_nBuffSize - m_nRealLen >= str.length())  
//���� �ռ��С��ȥ�ַ���С ʣ��ķ����˵ĵ���û��ʹ�õĿռ� �Ƿ�������Ӻ�����ַ�����
//������Բ����ٴη���ռ�ֱ�����ӣ��Ͳ����ٷ���ռ��ˡ�
	{
		//strcat(m_pBuff, str.m_pBuff);
		memcpy(m_pBuff + m_nRealLen, str.m_pBuff, str.length());
		m_nRealLen = m_nRealLen + str.length();
		
	}	
	else  //��Ҫ���·���ռ����
	{
		int nLen = m_nRealLen + str.length();
		char*p = new char[nLen + EXT_LEN];
		//strcpy(p, m_pBuff);
		memcpy(p, m_pBuff, m_nRealLen); //��ǰ����ַ���������������Ŀռ���
		//strcpy(p + m_nRealLen, str.m_pBuff);
		memcpy(p + m_nRealLen, str.m_pBuff, str.length());  
		//��Ϊ�¿ռ��Ѿ�����һ���ַ��������ǲ����ٴ��׵�ַ������ʼ�ˣ����ǽ��׵�ַ�����Ѿ�������ȥ���ַ����ĳ��ȣ�
		//�����λ�ÿ�ʼ����û�п����ַ�����λ��ƴ�Ӻõڶ����ַ���
		m_nRealLen = nLen;
		m_nBuffSize = nLen + EXT_LEN;

		if (m_pBuff)  //���ǰ����ַ������ǿյģ����Ǿ�ɾ��ǰ��ƴ��֮ǰ�ĵ�һ���ַ���
		{
			delete[]m_pBuff;
		}

		m_pBuff = p;  //��ƴ�Ӻõ��ַ�����ֵ������ָ���ַ����׵�ַ��ָ��
	}

	return *this;
}
istream& operator>>(istream& input, String& str)
{
	std::cin.get(str.m_pBuff, str.size(), '\n');  
	//��ֱ��ʹ��cin����cin������û�н��������ַ����ĳ��ȵ���Խ�磬�����c��һ������ָ�������ַ����ĺ�����
	//�ú�����str.size()���ȵ��ַ�����ȡ��str.m_pBuff�У��������ַ��ǽ����ַ�����ʹû�дﵽָ�����ȣ���������ַ�Ҳ������ġ�
	return input;
}
ostream& operator<<(ostream& output, String& str)
{
	for (int i = 0; i < str.length(); i++)  
	//��Ϊcout���ַ������������\0���������������ʹ�õ�memcpy�����ǲ������ַ����Ľ�β�Զ������������\0��
	//����������Ҫ����ѭ��������ʵ�ʳ�����ʵ�ֱ������
	{
		std::cout.put(str[i]);  //ÿ������Ļ���һ���ַ�
	}
	return output;
}