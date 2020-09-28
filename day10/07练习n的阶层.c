#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//n的阶层
int main0701()
{
	int i = 0;
	int n = 0;
	int ret = 1;
	scanf("%d", &n);
	for ( i = 1; i <=n; i++)
	{
		ret = ret * i;
	}
	printf("ret=%d\n", ret);
	return 0;
}



//计算1的阶层到10的阶层的和
//ret=1*1=1
//ret=1*1*2=2
//ret=1*1*2*3=6
int main0702(void)
{
	int i = 0;
	int n = 0;
	int sum = 0;
	int ret = 1;
	for (n = 1; n <= 10; n++)
	{
		ret = 1;
		for (i = 1; i <= n; i++)
		{
			ret = ret * i;
		}
		//n的阶乘
		sum = sum + ret;
	}
	printf("sum=%d\n", sum);
	return 0;
}


//观察，代码还有很大的优化空间
//ret=1*1=1      ————   ret=1*1=1
//ret=1*1*2=2	 ————	ret=1*2=2
//ret=1*1*2*3=6	 ————	ret=2*3=6
int main0703(void)
{
	int i = 0;
	int n = 0;
	int sum = 0;
	int ret = 1;
	for (n = 1; n <= 10; n++)
	{
		ret = ret * n;
		sum = sum + ret;
	}
	printf("sum=%d\n", sum);
	return 0;
}

