#include<stdio.h>
#include<math.h>

int main1001()
{
	//水仙花：从100—999各个位数的立方和相加等于这个数本身就是一个水仙花数

	int i = 100;
	do
	{
		int a = i % 10;//个
		int b = i / 10 % 10;//十
		int c = i / 100;//百
		if (pow(a,3)+pow(b,3)+pow(c,3)==i)//同(a*a*a + b*b*b + c*c*c == i)所在头文件<math.h>
			printf("%d\n", i);
		i++;
	} while (i <= 999);
	return 0;
}