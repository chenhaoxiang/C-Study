#include "Student.h"

//inline关键词可以这样理解
//inline 定义的类的内联函数，函数的代码被放入符号表中，在使用时直接进行替换，（像宏一样展开），没有了调用的开销，效率也很高。
//要具体了解的，可以直接搜索C++中inline的用法
inline int Student::getAge(){
	return age;
}