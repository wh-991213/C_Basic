#include<stdio.h>
#include<stddef.h>

//在对齐方式不合适的时候，我们可以自己更改默认对齐数
//修改默认对齐数#pragma pack()
//设置默认对齐数4 - 一般设置默认对齐数是偶数
#pragma pack(4)
//取消设置的默认对齐数,还原为默认
//#pragma pack()
struct S5
{
	char c;//1       //1
	//7				 //3
	double d;//8	 //8
};
int main0401()
{
	struct S5 s;
	printf("%d\n", sizeof(s));
	return 0;
}


//如果我们想要知道c相对于起始位置的偏移量，d相对于起始位置的偏移量，a相对于起始位置的偏移量？？？
//offsetof是用来计算结构体成员相对于结构体起始位置偏移量
//offsetof()：size_t offsetof(structName,memberName);所在头文件<stddef.h>，offsetof不是函数，而是一个宏;
struct S6
{ 
	char c;
	int d;
	double a;
};
int main0402(void)
{
	//返回的是成员对于起始位置的偏移量
	printf("%d\n", offsetof(struct S6, c));//0
	printf("%d\n", offsetof(struct S6, d));//4
	printf("%d\n", offsetof(struct S6, a));//8
	return 0;
}