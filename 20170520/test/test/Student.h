//�����ָ���ֹͷ�ļ����ظ�����
#ifndef STUDENT_H
#define STUDENT_H
class Student
{
public:
	void print()
	{
		//������������ģ������ֵ��ȷ������Ϊ����֮ǰû�и�ֵ
		std::cout << age << std::endl;
	}
	int getAge();
private:
	char name[128];
	int age;
	char addr[128];
};

#endif