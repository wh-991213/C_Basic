#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//这里介绍的是IDE是Visual Studio2017
int Add(int x, int y)
{
	return x + y;
}
int main0201()
{
	printf("hehe\n");
	int a = 10;
	int b = 20;
	int c = Add(a, b);
	//1.F9：创建断点和取消断点，可以在程序的任意位置设置断点。 - 可以使程序在想要的位置停止执行，继而再执行
	//2.F5：启动调试，配合F9直接跳到下一个断点处
	//3.F10：逐过程，用来跳过一个过程 - 过程可以是一次函数调用或者是一条语句 - 
	//4.F11：逐语句，每次都执行一条语句，这个快捷键可以执行进入函数内部
	//5.CTRL+F5：开始执行不调试 - 程序直接运行起来而不调试
	//6.Shift+F5：停止调试
	//7.Shift+F11：跳出 - 用于跳出函数内部
	//在调试的过程中还可以在 - 调试 - 窗口 中使用监视、自动窗口、局部变量、调用堆栈、内存、反汇编、寄存器等以便更好的观察代码
	return 0;
}

void test4()
{
	printf("hehe\n");
}
void test3()
{
	test4();
}
void test2()
{
	test3();
}
void test1()
{
	test2();
}
void test()
{
	test1();
}
int main0202(void)
{
	test();
	//调试过程中使用调试 - 窗口 - 调用堆栈：像栈一样的形式来展示函数调用的逻辑  - 先进后出
	//test4
	//test3
	//test2	
	//test1
	//test
	//main
	return 0;
}

//实例(错误代码调试)：求1!+2!+3! ... +n!(阶层之和) - 不考虑溢出
//eg：scanf(3) - 3阶层之和1+2+6=9  - 这里是1+2+(2*1*2*3)=15 - 原因是没有将ret重置
//这里使用调试解决的问题是程序运行起来的时候发现结果与预期不符 - 语法错误是不需要调试的
int main0203(void)
{
	int n = 0;
	int ret = 1;
	int sum = 0;
	scanf("%d", &n);
	for (int i = 1; i <=n; i++)
	{
		//ret = 0;//这是修改后的
		for (int j = 1; j <= i; j++)
		{
			ret *= j;
		}
		sum += ret;
	}
	printf("%d\n", sum); 
	//总结调试过程：
	//经过思考，发现可能在求3的阶层时发生了错误，需要调试来验证，但从最开始开始调试太戳
	//那如何才能很快的求到3的阶层 - 当内循环的i是3时
	//所以在内循环的那一行加上断点 - 并右击断点 - 找到条件 - 并修改即可
	//这时很迅速的验证了上述的的猜想 - 最后再测试
	return 0;
}
