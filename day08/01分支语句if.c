#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


/*
C语言是一门结构化的程序设计语言
1.顺序结构
2.选择结构
3.循环结构
*/
/*
什么是语句？
由一个分号，隔开的就是一条语句 如：
int a=10; 就是一条语句，但是是空语句
*/
//如果表达式结果为真，执行{}对应的代码 
int main0101()
{
	//这里是一种错误写法
	/*
	int age = 10;
	if (18<=age<28);//注意这里是先执行18<=10为假，然后0<28为真，则执行
	{
		printf("青年\n");
	}
	*/
	//正确写法
	printf("请输入你的年龄\n");
	int age;
	scanf("%d", &age);
	if (age < 18)
	{
		//这里如果只有一条语句，可以省略{}
		printf("未成年\n");
		printf("不能谈恋爱\n");
	}
	else
	{
		if (age >= 18 && age < 28)
			printf("青年\n");
		else if (age >= 28 && age < 50)
			printf("壮年\n");
		else if (age >= 50 && age < 90)
			printf("老年\n");
		else
			printf("老不死的\n");
	}

	return EXIT_SUCCESS;
}

//悬空else
//看下面这段代码，结果是什么呢？？？
int main0102(void)
{
	int a = 0;
	int b = 2;
	if (a == 1)
		if (b == 2)
			printf("hehe\n");
		/*else  注意这里的else和if(b==2)匹配
			printf("haha\n");*/

		else  //注意这里的else不跟if(a==1)匹配；但和if(b==2)匹配
			printf("haha\n");
	//结果为空
	//适当的使用{}可以使代码的逻辑更加清楚
	return 0;
}

//以下代码能否打印
int main0103(void)
{
	int sum = 4;
	//if (sum = 5)//答案是能的，注意这里=是赋值运算符；==是判断相等
	//{
	//	printf("呵呵\n");
	//}

	//可以把常量放到左边，预防错误，这也是好的代码风格
	if (5 ==sum)
	{
		printf("呵呵\n");
	}
	return 0;
}


//判断一个数是否为奇数，并输出1-100之间的奇数
int main0104(void)
{
	int i = 1;
	while (i <= 100)
	{
		if (i % 2 == 1)//或(i%2!=0);
			printf("%d\n", i);
		i++;
	}
	return 0;
}

//能不用if语句吗？？？
int main0105(void)
{
	int i = 1;
	while (i <= 100)
	{
		printf("%d\n", i);
		i += 2;
	}
	return 0;
}

