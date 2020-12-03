#include<stdio.h>

//结构体初始化
struct T
{
	double weight;
	int age;
};
struct S
{
	char c;
	struct T st;//结构体的成员可以是标量、数组、指针，甚至是其它结构体,但不能是本身
	int a;
	double d;
	char arr[20];
};

int main0201()
{
	//结构体初始化 - 这里没有包含struct T st
	//struct S s = { 'c',100,3.14,"hello" };
	//结构体成员访问 - 结构体变量.成员变量
	//printf("%c %d %lf %s\n", s.c, s.a, s.d, s.arr);

	//结构体中的结构体
	struct S s = { 'c',{55.6,42},100,3.14,"hello" };//初始化结构体中的结构体需要加上大括号 
	printf("%lf %d\n", s.st.weight, s.st.age);//访问结构体中的结构体 - 结构体变量.结构体中结构体变量.结构体中结构体成员变量
	return 0;
}
