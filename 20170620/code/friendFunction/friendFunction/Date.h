#ifndef DATA_H
#define DATA_H

class CTime;//���ǰ��������һ������£�����Ҫ����֮��ſ���ʹ�õ�

class CDate
{
public:
	CDate(int year, int month, int day);

	//friend CTime;//������������Ԫû�ã���Ϊ��Ԫֻ�����裬������ȡ��
	void disPlay(const CTime& time);//ʹ�õ����������(����Ҳ��ʹ��ָ����ʵ�ֵ�),���ﲻ�����ǿ��Ե�

private:
	int m_nYear;
	int m_nMonth;
	int m_nDay;

};
#endif