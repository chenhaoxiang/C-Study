//宏编译指令，防止头文件被重复包含
#ifndef STUDENT_H
#define STUDENT_H
class Student
{
public:
	void print()
	{
		//这里是有问题的！输出的值不确定！因为调用之前没有赋值
		std::cout << age << std::endl;
	}
	int getAge();
private:
	char name[128];
	int age;
	char addr[128];
};

#endif