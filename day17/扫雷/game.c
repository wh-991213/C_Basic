#include"game.h"

//实现
//初始化mine和show棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for ( i = 0; i < rows; i++)
	{
		for ( j = 0; j < cols; j++)
		{
			board[i][j] =set;
		}
	}
}

//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{	
	int i = 0;
	int j = 0;
	//打印列号
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n"); 
	for ( i = 1; i <= row; i++)
	{
		//打印行号
		printf("%d ", i);

		for ( j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);               
		}
		printf("\n"); 
	}
}

//布置雷
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;//1-9
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

//扫雷(计算周围有几个雷）
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	//因为它的周围不是1就是0，所以把它周围的8个坐标加起来，就是有几个雷。但这种方法，存的是字符而不是数字
	//我们发现
	//'1'-'0'=1
	//'3'-'0'=3
	//周围8个坐标之和-8*'0'相当于各自减上一个字符0
	//0   0   1
	//0  x,y  0
	//1   0   0
	//'0'+'0'+'0'+'1'+'0'+'0'+'0'+'1'-8*'0'=386-384=2
		return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}

//使用递归展开无雷区（棋盘不展开的条件是某位置周围有雷。）
void OpenMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y)
{
	int ret = 0;
	ret= get_mine_count(mine, x, y);
	if (ret == 0)
	{
		show[x][y] = ' ';
		if (x > 0 && y + 1 <= col && show[x][y + 1] == '*')
		{
			OpenMine(mine, show, row, col, x, y + 1);
		}
		if (x - 1 > 0 && y + 1 <= col && show[x - 1][y + 1] == '*')
		{
			OpenMine(mine, show, row, col, x - 1, y + 1);
		}
		if (x - 1 > 0 && y > 0 && show[x - 1][y] == '*')
		{
			OpenMine(mine, show, row, col, x - 1, y);
		}
		if (x - 1 > 0 && y - 1 > 0 && show[x - 1][y - 1] == '*')
		{
			OpenMine(mine, show, row, col, x - 1, y - 1);
		}
		if (x > 0 && y - 1 > 0 && show[x][y - 1] == '*')
		{
			OpenMine(mine, show, row, col, x, y - 1);
		}
		if (x + 1 <= row && y - 1 > 0 && show[x + 1][y - 1] == '*')
		{
			OpenMine(mine, show, row, col, x + 1, y - 1);
		}
		if (x + 1 <= row && y > 0 && show[x + 1][y] == '*')
		{
			OpenMine(mine, show, row, col, x + 1, y);
		}
		if (x + 1 <= row && y + 1 <= col && show[x + 1][y + 1] == '*')
		{
			OpenMine(mine, show,row, col, x + 1, y + 1);
		}
	}
	else
	{
		show[x][y] = ret + '0';//2 + 48 = 50 = 2
	}
}


//扫雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	//9*9-10=71代表棋盘除了雷之外有71个位置
	while (win<ROW*COL-EASY_COUNT )
	{
		printf("请输入排查雷的坐标\n");
		scanf("%d%d", &x, &y);              
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//坐标合法
			//1.踩雷
			if (mine[x][y] == '1')
			{
				printf("你被炸死了\n");
				DisplayBoard(mine, row, col);
				break;
			}
			//2.非雷
			else
			{
				//封装一个函数用于计算x、y坐标周围有几个雷
				int count=get_mine_count(mine, x, y);
				//展开功能--递归
				OpenMine(mine, show, row, col, x, y);
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("输入坐标非法，请重新输入\n");
		}
	}
		if (win == row * col - EASY_COUNT)
		{
			printf("恭喜你，排雷成功\n");
			DisplayBoard(mine, row, col);
		}
}
