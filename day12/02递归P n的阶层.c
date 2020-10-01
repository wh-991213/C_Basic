#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//int Fac1(int n)
//{
//	//循环
//	int i = 0;
//	int ret = 1;
//	for ( i = 1; i <=n; i++)
//	{
//		ret *= i;
//	}
//	return ret;
//}
//阶乘这里有个公式：Fac(n)
			  //n<=1   1
			  //n>1	   n*Fac(n-1)
int Fac(int n)
{
	//递归
	if (n <= 1)
		return 1;
	else
		return n * Fac(n - 1);
}
//递归与迭代 
//求n的阶乘（不考虑溢出）
int main0204()
{
	int n = 0;
	int ret = 0;
	scanf("%d", &n);
	ret = Fac(n);
	printf("%d\n", ret);
	return 0;
}