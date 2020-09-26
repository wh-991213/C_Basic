#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int main0201()
{
	int day=0;
	scanf("%d", &day);
	if (1 == day)
		printf("星期一\n");
	else if (2 == day)
		printf("星期二\n");
	else if (3 == day)
		printf("星期三\n");
	else if (4 == day)
		printf("星期四\n");
	//... ...
	return 0;
}
//switch语句也是一种分支语句。常常用于多分支的情况
int main0202(void)
{
	printf("请输入星期(1-7)\n");
	int day;
	scanf("%d", &day);
	
	switch (day)
	{
	case 1:
		printf("星期一\n");
		break;
	case 2:
		printf("星期二\n");
		break;
	case 3:
		printf("星期三\n");
		break;
	case 4:
		printf("星期四\n");
		break;
	case 5:
		printf("星期五\n");
		break;
	case 6:
		printf("星期六\n");
		break;
	case 7:
		printf("星期日\n");
		break;
	}
	return 0;
}

int main0203(void)
{
	printf("请输入星期(1-7)\n");
	int day;
	scanf("%d", &day);

	switch (day)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		printf("工作日\n");
		break;
	case 6:
	case 7:
		printf("休息日\n");
		break;
	default:
		printf("输入错误\n");
		break;
	}
	return 0;
	//如果多个分支有相同的属性，可以这样写
}


//输出结果是多少？？？
int main0204(void)
{
	int n = 1;
	int m = 2;
	switch (n)
	{
	case 1:
		m++;
	case 2:
		n++;
	case 3:
		switch (n)
		{
		case 1:
			n++;
		case 2:
			m++;
			n++;
			break;
		}
	case 4:
		m++;
		break;
	default:
		break;
	}
	printf("m=%d n=%d\n", m, n);//5  ,3
	return 0;
}
int main0205()
{
	int score ;
	scanf("%d", &score);
	switch (score / 10)
	{
	case 10:
		printf("优秀\n");
		break;
	case 9:
		printf("优秀\n");
		break;
	case 8:
		printf("良好\n");
		break;
	case 7:
		printf("及格\n");
		break;
	case 6:
		printf("及格\n");
		break;
	default:
		printf("不及格\n");
		break;
	}

	return 0;
}
//switch可以把程序跳转到多个语句中的一个执行，它包括了多个case标签，以及最多一个default标签。
/*switch(整型表达式)：括号里的表达式会被计算一次，并和case标签中的常量表达式作比较。如果表达式的值匹配其中某个case常量，
程序就会跳转到该case标签后面的语句，如果没有匹配的case常量，程序就会跳转到default标签后面的语句*/
//如果有多个分支，需要break跳出
//switch()里的表达式必须是整型表达式；case后面必须是整型常量表达式
//switch允许嵌套使用
//switch里的最后一个分支，最好加上break，为后人在写代码的时候提供一个好的代码风格


