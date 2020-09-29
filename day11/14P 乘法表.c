#include<stdio.h>
/*
1*1=1
1*2=2 2*2=4
1*3=3 2*3=6 3*3=9
*/

int main1401()
{
	for (int i = 1; i < 10; i++)
	{
		for ( int j = 1; j <= i; j++)
		{
			printf("%d*%d=%d\t", j, i,i*j);
		}
		printf("\n");
	}
	return 0;
}