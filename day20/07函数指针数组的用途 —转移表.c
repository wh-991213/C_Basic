#include<stdio.h>
#pragma warning (disable:4996)

//函数指针数组的用途：转移表
//计算器
void menu()
{
	printf("****************************\n");
	printf("**** 1.add        2.sub ****\n");
	printf("**** 3.mul        4.div ****\n");
	printf("****       0.exit      *****\n");
	printf("****************************\n");
}

int Add3(int x, int y)
{
	return x + y;
}
int Sub3(int x, int y)
{
	return x - y;
}
int Mul3(int x, int y)
{
	return x * y;
}
int Div3(int x, int y)
{
	return x / y;
}

//一
//int main0701(void)
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	do
//	{
//		menu();
//		printf("请选择：>\n");
//		scanf("%d", &input);
//		if (input == 0)//确定输入的数是0；
//			goto again;
//		else if(input < 1 || input >4)//确定输入的数是选择错误
//			goto again1;
//		//或者在下面所需要的每个case标签下输入printf("请输入两个数：>\n"); scanf("%d%d", &x, &y);
//
//		printf("请输入两个数：>\n");
//		scanf("%d%d", &x, &y);
//		switch (input)
//		{
//		case 1:
//			printf("%d\n", Add3(x, y));
//			break;
//		case 2:
//			printf("%d\n", Sub3(x, y));
//			break;
//		case 3:
//			printf("%d\n", Mul3(x, y));
//			break;
//		case 4:
//			printf("%d\n", Div3(x, y));
//			break;
//		case 0:
//			again:
//			printf("退出\n");
//			break;
//		default:
//			again1:
//			printf("选择错误\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}
//这样写代码，假设还要进行两个数之间按位与、按位或、按位异或、左移、右移的运算时，就需要多个case语句


//二
//int main0702(void)
//{
//	int input = 0;
//	int x = 0;
//	int y = 0; 
//	//pfArr是一个函数指针数组 - 通过下标找到元素，然后再去找到这个元素所指向的这个函数里面去 - 所以经常把这种函数指针数组叫做转移表
//	int(*pfArr[])(int, int) = { 0,Add3,Sub3,Mul3,Div3 };
//	do
//	{
//		menu();
//		printf("请选择：>\n");
//		scanf("%d", &input);
//		if (input >= 1 && input <= 4)
//		{
//			printf("请输入两个数：>\n");
//			scanf("%d%d", &x, &y);
//			int ret = pfArr[input](x, y);//或者(*pfArr[input])(x,y);	
//			printf("结果：%d\n", ret);
//		}
//		else if(input == 0)
//		{
//			printf("退出\n");
//		}
//		else
//		{
//			printf("选择错误，请重新选择\n");
//		}
//	}while(input);
//	//这样写的好处：如果需要增加其它的运算符，不需要像switch语句增加case标签，只需要稍稍改动
//	return 0;
//}


//再回到上面的代码一 - 优化	
/*回调函数：就是一个通过函数指针调用的函数。如果你把函数的指针(地址)作为参数传递给另一个函数，当这个
指针被用来调用其所指向的函数时，我们就说这是回调函数。回调函数不是由该函数的实现方直接调用，而是在特定
的事件或条件发生时由另外的一方调用的，用于对该事件或条件进行响应*/
//发现每个case标签唯一不同的是调用的函数不一样 - 封装一个Calc函数

void Calc(int(*pf)(int, int))//用函数指针接收传过来的不同的函数地址 - 实现了不同的功能
{
	int x = 0;
	int y = 0;
	printf("请输入两个数：>\n");
	scanf("%d%d", &x, &y);
	printf("%d\n", pf(x, y));
}
int main0701(void)
{
	int input = 0;
	do
	{
		menu();
		printf("请选择：>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Calc(Add3);
			/*printf("请输入两个数：>\n");
			scanf("%d%d", &x, &y);
			printf("%d\n", Add3(x, y));*/
			break;
		case 2:
			Calc(Sub3);
			/*printf("请输入两个数：>\n");
			scanf("%d%d", &x, &y);
			printf("%d\n", Sub3(x, y));*/
			break;
		case 3:
			Calc(Mul3);
			/*printf("请输入两个数：>\n");
			scanf("%d%d", &x, &y);
			printf("%d\n", Mul3(x, y));*/
			break;
		case 4:
			Calc(Div3);
			/*printf("请输入两个数：>\n");
			scanf("%d%d", &x, &y);
			printf("%d\n", Div3(x, y));*/
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	//把一个函数的地址传递给一个指针pf - 在函数内部通过这个指针去调用那个函数 - 那个被调用的函数就称为回调函数 - 很好的解决了代码冗余的问题
	return 0;
}


//对于回调函数
void print3(char *str)
{
	printf("hehe:%s", str);
}
void test(void(*p)(char*))//2.test函数的参数部分用函数指针接收 - 这个函数指针指向的函数参数是char*类型，返回类型是void
{
	printf("test\n");
	p("hello");//3.在test函数内部通过传过来的函数的地址p，然后去调用它所指向的那个函数
}
int main0704(void)
{
	test(print3);//1.这里在调用test函数时传了个print3函数；把print3函数的地址作为test函数的参数

	//总的来说：
	//print3函数不是主动去调用它的 - 而是把print3函数的地址作为test函数的参数
	//- 在test函数内部某种场景下去调用print3这个函数 - 这个被调的函数print3就被称为回调函数
	//- 这种机制就被称为回调函数机制
	return 0;
}
