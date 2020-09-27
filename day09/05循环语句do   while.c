#include<stdio.h>

int main0501()
{
	int i = 1;
	do
	{
		if (5 == i)
			//break;
			continue;
		printf("%d\n", i);
		i++;
	}
	while (i <= 10);
	//do...while循环可以认为是while循环的一个变型, 它会先执行语句然后再判断是否继续循环
	//我们发现在do  while循环中也可以使用break和continue
	//do...while循环至少执行一次，使用的场景有限，所以不经常使用
	return 0;
}