#include<stdio.h>

//#define RED 0
//#define GREEN 1
//#define BLUE 2

//#define - enum
//我们可以使用#define定义常量，为个么非要使用枚举？？？
//1.增加代码的可读性和可维护性
//2.和#define定义的标识符比较枚举有类型检查，更加严谨；枚举有具体的类型，有类型就有限制，所以更严谨
//3.防止命名污染（封装）,就是命名冲突
//4.便于调试
//5.使用方便，枚举一次可定义多个常量 

enum Color
{
	RED, 
	GREEN,
	BLUE,
};
int main0801(void)
{
	enum Color c;
	return 0;
}


//这里再看一下enum的内存大小
//所以enum的内存大小都是4个字节
enum Sex
{
	MALE,
	FEMALE,
	SECRET,
};
int main0802(void)
{
	//拿一个可能取值给s赋值。MALE是一个整数，s是一个整型变量
	enum Sex s = MALE;
	printf("%d\n", sizeof(s));//4
	return 0;
}