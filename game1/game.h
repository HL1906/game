#pragma once
//ͷ�ļ��İ���
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


//һ�����峣��
#define ROW 5 
#define   COL 5


//������������


//1.��ʼ������
void InitBoard(char board[ROW][COL], int row, int col);

//2.��ӡһ�����̺���
void DisplayBoard(char board[ROW][COL], int row, int col);

//�������
void PlayerMove(char board[ROW][COL], int row, int col);

//�ж���Ӯ
char IsWin(char board[ROW][COL], int row, int col);