//宏定义常量区
//玩家视角
#define ROW 9
#define COL 9
//程序员视角   如果在地图边界排查雷的时候，会越界，所以把地图扩大一圈
#define ROWS ROW+2
#define COLS COL+2
//雷的个数
#define EASY_COUNT 10


//头文件引用
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning (disable:4996)



//声明
//初始化
void InitBoard(char board[ROWS][COLS],int rows,int cols,char set);
//打印棋盘
void DisplayBoard(char board[ROWS][COLS],int row,int col);
//布置雷
void SetMine(char board[ROWS][COLS], int row, int col);
//扫雷
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col);
//展开功能--递归
void OpenMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col,int x,int y);