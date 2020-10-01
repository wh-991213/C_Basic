#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main0201()
{
	printf(" hehe\n");
	main();//这就是一个递归
	return 0;	
	//递归常见错误：栈溢出stack overflow
}


	
void print(int n)
{
	//递归的两个必要条件（缺一不可）
	//1.存在限制条件，当满足这个限制条件的时候，递归便不再继续（n>9)
	//2.每次递归调用之后越来越接近这个限制条件(n/10)
	if (n > 9)//说明这个数至少是两位及两位以上的数字
	{
		print(n / 10);
	}
	printf("%d ", n %10);
}
//P 接收一个整型值（无符号），按照顺序打印它的每一位。例如：输入1234   输出1 2 3 4
int main0202()
{
	unsigned int num = 0;
	scanf("%d", &num);//1234
	//递归
	print(num);
	//print(1234)
	//print(123) 4
	//print(12)3 4
	//print(1) 2 3 4			
	return 0;
}



