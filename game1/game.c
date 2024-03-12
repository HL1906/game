#include"game.h"

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (int j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x;
	int y;
	printf("玩家走 > \n");
	while (1)
	{
		printf("请输入下棋坐标：> \n");
		scanf("%d %d", &x, &y);
		//判断坐标合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标被占用，请重新输入！");
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}
	}

}

//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑走 > \n");
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
//平局
int IsFull(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;//棋盘没满
			}
		}
	}
	return 1;//棋盘满了
}


//判断输赢
char IsWin(char board[ROW][COL], int row, int col)
{
	//判断三行
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col - 2; j++)
		{
			if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && board[i][j] != ' ')
			{
				return board[i][j];
			}
		}

		//if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		//{
		//	return board[i][1];
		//}
	}

	//判断三列
	for (int i = 0; i < row - 2; i++)
	{
		//if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		//{
		//	return board[1][i];
		//}


		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == board[i + 1][j] && board[i + 1][j] == board[i + 2][j] && board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}

	//判断对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}


	//平局
	//如果满了返回1，不满返回0
	int ret = IsFull(board, row, col);
	if (ret == 1)
	{
		return 'Q';
	}
	//游戏继续
	return 'C';
}