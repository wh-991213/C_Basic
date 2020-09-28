#include<stdio.h>
#pragma warning(disable:4996)

int main0901()
{
	int a, b, c;
	printf("请输入三只小猪的体重\n");
	scanf("%d%d%d", &a, &b, &c);

	if (a > b)
	{
		if (a > c)
			printf("小猪a最重\n");
		else
			printf("小猪c最重\n");
	}
	else
	{
		if (b > c)
			printf("小猪b最重\n");
		else
			printf("小猪c最重\n");
	}
	return 0;
}


