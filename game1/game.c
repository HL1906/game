#include"game.h"

//��ʼ������
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

//��ӡ����
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

//�������
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x;
	int y;
	printf("����� > \n");
	while (1)
	{
		printf("�������������꣺> \n");
		scanf("%d %d", &x, &y);
		//�ж�����Ϸ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("���걻ռ�ã����������룡");
			}
		}
		else
		{
			printf("����Ƿ�������������\n");
		}
	}

}

//��������
void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("������ > \n");
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
//ƽ��
int IsFull(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;//����û��
			}
		}
	}
	return 1;//��������
}


//�ж���Ӯ
char IsWin(char board[ROW][COL], int row, int col)
{
	//�ж�����
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

	//�ж�����
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

	//�ж϶Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}


	//ƽ��
	//������˷���1����������0
	int ret = IsFull(board, row, col);
	if (ret == 1)
	{
		return 'Q';
	}
	//��Ϸ����
	return 'C';
}