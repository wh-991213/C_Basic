#define _CRT_SECURE_NO_WARNINGS
#include"game.h"


// 测试三子棋游戏
void menu()
{
	printf("****************************\n");
	printf("****1. play      0. exit****\n");
	printf("****************************\n");
}

//游戏的整个算法实现
//注意:比如关于棋盘的初始化，是游戏模块的相关代码。需要在game.h这个头文件里声明，才能在game.c里实现	
void game()
{
	char ret = 0;
	//创建二维数组
	char board[ROW][COL] = { 0 };
	//初始化棋盘（数组里的内容是空格）本质上就是初始化board这个数组，如果要访问这个数组，还要知道这个数组有几行几列，所以还要把行与列传过去
	InitBoard(board,ROW,COL);
	//打印棋盘 
	DisplayBoard(board,ROW,COL);
	//下棋
	while (1)	
	{
		//玩家下棋
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//判断玩家是否赢
		ret=IsWin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
		//电脑下棋
		ComputerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//判断电脑是否赢	
		ret=IsWin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}

	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if(ret=='#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:	
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择!\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}