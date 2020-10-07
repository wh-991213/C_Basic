//宏定义行与列
#define ROW 3
#define COL 3

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


//注意只有在头文件里声明，才能在game.c里实现
//声明初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);
//声明打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);
//声明玩家下棋
void PlayerMove(char board[ROW][COL],int row,int col);
//声明电脑下棋
void ComputerMove(char board[ROW][COL],int row,int col);
//声明游戏结局；告诉我们四种游戏的状态
//玩家赢 -'*'
//电脑赢-'#'
//平局-'Q'
//继续-'C'
char IsWin(char board[ROW][COL],int row,int col);


