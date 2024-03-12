#include<stdio.h>
#include"game.h"

void menu()
{
	printf("********************************\n");
	printf("**********  1. play   **********\n");
	printf("**********  0. exit   **********\n");
	printf("********************************\n");
}

void game()
{
	//1、存储数据  ----->  二维数组
	char board[ROW][COL];
	//2、初始化棋盘  ----->  初始化空格
	InitBoard(board, ROW, COL);
	//3.打印一下棋盘----->本质是打印数组内容
		DisplayBoard(board, ROW, COL);
	//对弈
		char ret = 0;
		while (1)
		{
			//玩家下棋
			PlayerMove(board, ROW, COL);
			DisplayBoard(board, ROW, COL);
			//判断输赢
			ret = IsWin(board, ROW, COL);
			if (ret != 'C')
			{
				break;
			}

			//电脑下棋
			ComputerMove(board, ROW, COL);
			DisplayBoard(board, ROW, COL);
			//判断输赢
			ret = IsWin(board, ROW, COL);
			if (ret != 'C')
			{
				break;
			}
		}
		if (ret == '*')
		{
			printf("玩家赢了！\n");
		}
		else if (ret == '#')
		{
			printf("电脑赢了！\n");
		}
		else
		{
			printf("平局！\n");
		}
		DisplayBoard(board, ROW, COL);
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择：> ");
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
			printf("选择错误，重新选择\n");
			break;
		}
	} while (input);

	return 0;
}