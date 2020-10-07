#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

//将棋盘初始化为空格 
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for ( i = 0; i < row; i++)
	{
		for ( j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//打印棋盘 
//棋盘样式
//   |   |
//---|---|---
//   |   |
//---|---|---
//   |   |

//printf(" %c | %c | %c \n",board[i][0],board[i][1],board[i][2]);//打印一行的数据
//printf("---|---|---\n");//打印分割行 
//以上两行代码太戳，大神匆鸟（如果有一天我希望棋盘不再是3*3而是10*10，那么使用此方法完整打印棋盘，这里的行可以打印，但列已经写死了，所以要修改才能达到目地）

//以下的代码（1和2为一组）
//   |   |
//---|---|---
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for ( i = 0; i < row; i++)
	{
		for ( j = 0; j < col; j++)
		{
			//1.第一次外循环结束打印一行的数据	 %c|%c|%c
			printf(" %c ", board[i][j]);
			if(j<col-1)//判断；从而使最后一组（右）没有|
			printf("|");
		}
		printf("\n");//第一行结束后的换行
		//2.打印分割行
		if (i < row - 1)//判断；从而使最后一组（下）没有---|---|--- 
		{	
			//第一次外循环结束打印一行的数据	---|---|--- 
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)//判断；从而使最后一组（右）没有|
				printf("|");
			}
			printf("\n");
		}
	}
}

//玩家下棋的实现
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走:>\n");
	while (1)
	{
		printf("请输入要下的坐标:>");
		scanf("%d%d", &x, &y);
		//判断x,y坐标的合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)//用户的角度
		{
			if(board[x-1][y-1]==' ')//判断此时的坐标为空格才落子；程序员的角度
			{
				board[x - 1][y - 1] = '*';	
				break;
			}
			else//如果坐标合法的情况还要判断坐标是否被占用
			{
				printf("该坐标被占用\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}
	}

}

//电脑下棋的实现
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走:>\n");
	while (1)
	{
		x = rand() % row;//0-2
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}  
}

//判断结局
//返回1表示棋盘满了，返回0表示棋盘没满
int IsFull(char board[ROW][COL],int row ,int col)
{
	int i = 0;
	int j = 0;
	for ( i = 0; i < row; i++)
	{
		for ( j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
//判断结局
char IsWin(char board[ROW][COL], int row, int col)
{	
	int i = 0;
	//判断行
	for ( i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//判断列
	for ( i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//判断两个对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//判断是否平局
	if (1 == IsFull(board, ROW, COL))
	{
		return 'Q';
	}
	//继续
	return 'C';
}

