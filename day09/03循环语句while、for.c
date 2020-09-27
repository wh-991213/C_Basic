#include<stdio.h>

//while循环
int main0301(void)
{
	//死循环
	/*while(1)
		printf("呵呵\n");*/


	//continue
	//int i = 1;
	//while (i<=10)
	//{
	//	if (5 == i)
	//		//break;
	//		continue;//死循环；continue的作用是不执行本次循环下面的代码。这里会回到while(i<=10)
	//	printf("%d\n", i);
	//	i++;
	//}

	int i=0;
	while (i <= 10)
	{
		i++;
		if (5 == i)
			continue;//这里continue的作用是不打印5；同上面这里把i++放到了continue上，所以不会死循环
		printf("%d\n", i);
	}

	//总的来说，continue在循环中的作用是不执行本次循环,也就是说本次循环中continue后面的代码不会执行而是直接跳转到while语句的判断部分，进行下一次循环的入口判断
	//最后我们可以发现在while循环中，初始化、判断和调整三部分偏离较远，这样查找和修改不集中、方便
	return 0;
}


//for循环
int main0302(void)
{
	//相对于while循环，for循环将初始化、判断和调整放到了一起，可以更好的观察修改
	for (int i = 1; i <=10; i++)
	{
		if (5 == i)
			//break;
		continue;
		printf("%d\n", i);
	}
	//我们发现在for循环中也可以使用break和continue,他们的意义和在while循环中是一样的。但还是有些差异
	return 0;
}

//不可在for循环体内修改循环变量，防止for循环失去控制
int main0303(void)
{
	int i = 0;
	for ( i = 0; i < 10; i++)
	{
		if (i=5)
			printf("haha\n");
		printf("hehe\n");
	}
	return 0;
}

//建议for语句的循环控制变量的取值采用前闭后开区间的写法
int main0304(void)
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//为什么建议前闭后开？？？
	//10次循环、10次打印、10个元素
	//而不采用for(i=0;i<=9;i++)这种写法
	int i = 0;
	for ( i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

//for循环的变式
//1
int main0305(void)
{
	/*for (;;)
	{
		printf("hehe\n");
	}*/
	//死循环
	//for循环的初始化、判断和调整都可以省略；但是for循环的判断部分如果被省略，那判断条件就是：恒为真
	int i = 0;
	int j = 0;
	for (; i < 10; i++)
	{
		for (; j < 10; j++)
		{
			printf("hehe\n");//这里共打印10组hehe
		}
	}
	return 0;
	//为什么只打印10次
	//因为在打印10次hehe后j=10。i=1再执行外循环，此时内循环依旧是j=10不满足条件
	//解决方法：再内循环里添加初始化j=0;
	//由此如果不是很熟练,建议不要省略
}
	
//2 比较少见
int main0306(void)
{
	int x, y;
	for (x = 0, y = 0; x < 2 && y < 5; ++x, y++)
	{
		printf("hehe\n");//2	
	}
	return 0;
}
//共循环了几次？？？
int main0307(void)
{
	int i = 0;
	int k = 0;
	for (i = 0, k = 0; k = 1; i++, k++)
		k++;	
	return 0;
	//0循环，因为这里的判断不是判断，而是赋值（把0赋值给k,表达式的结果为0，所以为假）
	//此代码只要为非0，就是死循环
}

