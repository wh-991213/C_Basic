#include<stdio.h>
int main0101()
{
	//一.类型的意义
	//1.使用这个类型开辟内存空间的大小（大小决定了使用范围）
	//2.如何看待内存的视角
	// ||   ||   ||   ||
	int a = 10;//0a 00 00 00
	float f = 10.0;//00 00 20 41
	//同样是4个字节，但是不同的类型，数据的存放却是大不相同
	return 0;
}


void test1()
{
	printf("hehe\n");
}
void test2(void)
{
	printf("hehe\n");
}
int main0102()
{
	//二.C语言类型
	//1.内置类型 - 也就是语言本身具有的类型 - char、short、int、float...
	//2.自定义类型(构造类型) - 也就是说自己可以去创造的类型
	//数组类型 - int arr[10];数组的类型(数组名去掉剩下的就是类型) - int[10]就是arr的类型  
	//int[10]:10个int类型的元素     int[5]:5个int类型的元素       char[5]:5个char类型的元素
	//结构体类型
	//枚举类型
	//联合体类型
	//3.指针类型 - 大小都是4或8个字节
	//int *pi;
	//char *pc;
	//void *pv;
	//4.空类型
	//void表示空类型(无类型),通常应用于函数的返回类型，函数的参数，指针类型
	test1();//返回类型
	test2(100);//函数的参数   
	//这里会发现如果上面的参数部分没有接收100的情况下也是可以正常打印的
	//这里如果想明确的指定test2函数不需要传参  - void test2(void) - 如果传参过去warning:test2用void参数列表声明
	
	return 0;
}

int main0103()
{
	//三.类型的基本归类
	//1.整型家族
	//char - char其实在内存中存储的是字符所对应的ASCII码值，ASCII码值是整数
	//	  unsigned char
	//	  signed char
	//short
	//	   unsigned short[int] - 在定义short类型时，int可以省略或写上
	//	   signed short[int]
	//int
	//     unsigned int
	//	   signed int
	//long 
	//     unsigned long[int]
	//	   signed long[int]
	short a = 10;
	short int b = 10;

	//2.浮点型家族
	//float
	//double
	return 0;
}