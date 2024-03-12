#pragma once
//头文件的包含
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


//一、定义常量
#define ROW 5 
#define   COL 5


//二、函数声明


//1.初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);

//2.打印一下棋盘函数
void DisplayBoard(char board[ROW][COL], int row, int col);

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);

//判断输赢
char IsWin(char board[ROW][COL], int row, int col);