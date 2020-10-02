#include<stdio.h>
#pragma warning(disable:4996)

//斐波那契数列(前两个数之和等于第三个数)
//1 1 2 3 5 8 13 21 34 55... 
//描述第n个斐波那契数
//Fib(n)
//n<=2,  1
//n>2,   Fib(n-1)+Fib(n-2)

int count = 0;
int Fib(int n)
{
	if (n == 3)
	{
		count++;//这里用于测试第3个斐波那契数被重复计算了多少次
	}
	if (n <= 2)
		return 1;
	else
		return Fib(n - 1) + Fib(n - 2);
}
//输入第几位数就对应斐波那契数
int main0205()
{
	//先把主函数这个函数怎么用先写出来，然后再实现这个函数		
	//这种设计思路叫TDD - 测试驱动开发
	int n = 0;
	int ret = 0;
	scanf("%d", &n);
	ret = Fib(n);
	printf("ret=%d\n", ret);
	printf("count=%d\n", count);//测试结果为
	return 0;
	//这个代码当我们测试第50位的斐波那契数时，发现所需时间较大，效率低
	//为什么效率这么低呢？？？
	//从后往前，使用递归的方式计算
	//50
	//49 48
	//48 47 47 46
	//47 46 46 45 46 45 45 44
	//...
	//首先这样计算每层都是2的次方数，再则重复计算的值多（我们已经在上面测试了在求第40个斐波那契数，仅是3就要重复3000多万次)
}


//显然有些问题用递归去解决并不合适
//从前往后使用循环的方式计算
//1 1 2 3 5 8 13 21 34 55   
//a b c
int Fib1(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;//这里可用于n<=2的情况

	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}
int main0206()
{
	int n = 0;
	int ret = 0;
	scanf("%d", &n);
	ret = Fib1(n);
	printf("ret=%d\n", ret);
	return 0;
}




//递归加上两个必要条件是不是就不会栈溢出了呢？？？
//如下代码已验证，虽然两个必要条件满足，但依旧会栈溢出
void test(int n)
{
	if (n < 10000)
	{
		test(n + 1);
	}
}
int main0207()
{
	test(1);
	return 0;
}



