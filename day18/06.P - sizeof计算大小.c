#include<stdio.h>

test1(int arr[])
{
	//这里的arr是指针，那sizeof(arr)的大小是4或者8（在32(x86)位操作系统中是4；在64(x64)位操作系统中是8）我的是x64平台
	printf("%d\n", sizeof(arr));
}
test2(char ch[])
{
	printf("%d\n", sizeof(ch));
}
//观察判断下面代码输出的结果
int main0501()
{
	int arr[10] = { 0 };
	char ch[10] = { 0 };
	printf("%d\n", sizeof(arr));//40
	printf("%d\n", sizeof(ch));//10
	//数组名单独放到sizeof内计算的是整个数组的大小，单位量字节 

	test1(arr);//8
	//数组在传参的时候，真正传过去的是数组首元素地址，只要是地址，最合理的方式是用一个指针来接收。
	test2(ch);//8
	return 0;
}