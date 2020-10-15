#include<stdio.h>
#pragma warning(disable:4996)

//方法1
int main0201(void)
{
	//比如要得到123的每一位
	//123%10=3;
	//123/10=12;
	//12%10=2;
	//12/10=1;
	//1%10=1;
	//同理如果要得到一个数的二进制，要不断的%2和/2
	//也就是统计num的补码中有几个1
	int	num = 0;
	int count = 0;
	scanf("%d", &num);
	while (num)
	{
		if (num % 2 == 1)
			count++;
		num = num / 2;
	}
	printf("%d\n", count);
//如果这样去做这道题。输入的是-1（我们都知道-1在内存中的补码全是1）得到的是0
}
//方法2
int main0202(void)
{
	//3
	//00000000 00000000 00000000 00000011--3的二进制
	//00000000 00000000 00000000 00000001--1的二进制
	//00000000 00000000 00000000 00000000--3&1
	//我们让这个数按位与1，发现如果得到的是1那么这个数的这个位就是1，那么count++；并让这个数num>>1,让其它位继续按位与1
	int num = 0;
	int count = 0;
	scanf("%d", &num);
	for (int i = 0; i < 32; i++)
	{
		if (1 == ((num >> i) & 1))
			count++;
	}
	printf("%d\n", count);
	return 0;
}
//方法3
int main0203(void)
{
	//这种方法每次都按位与它本身-1的数
	int num = 0;
	int count = 0;
	scanf("%d", &num);
	while (num)
	{
		count++;
		num = num & (num - 1);
	}
	printf("%d\n", count);
	return 0;
}

