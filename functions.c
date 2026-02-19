#include "header.h"
#include <stdio.h>

void printBoard(int rows, int columns, int gridNums[][3])//https://www.geeksforgeeks.org/c/pass-2d-array-parameter-c/
{
    printf("   |   |   \n");
    printf(" %d | %d | %d \n", gridNums[0][0], gridNums[0][1], gridNums[0][2]);
    printf("---|---|---\n");
    printf(" %d | %d | %d \n", gridNums[1][0], gridNums[1][1], gridNums[1][2]);
    printf("---|---|---\n");
    printf(" %d | %d | %d \n", gridNums[2][0], gridNums[2][1], gridNums[2][2]);
    printf("   |   |   \n");
}

void printGameBoard(int rows, int columns, char board[][3]) //created to print the char array game board
{
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("   |   |   \n");
}

int clearBoard(int rows, int columns, char board[][3])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            board[i][j] = '-';
        }
    }
}

int turnCheck(int moveNum)//using move number to track whose turn it is
{
    int r = moveNum % 2;
    return r;
}


char enterMoves(int playersTurn, int rows, int columns, int gridNums[][3], char board[][3], int input)
{
    if (playersTurn == 0)//use turnCheck function to check players turn
    {
        printf("Player 2, please make your move: ");
    }
    else
    {
        printf("Player 1, please make your move: ");
    }
    scanf(" %d", &input);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (input == gridNums[i][j])//match user input to a grid square
            {
                if(playersTurn == 0)//update the selected square on the board
                {
                    board[i][j] = 'X'; //if it was player 2's turn, fill the selected space with an X
                }
                else
                {
                    board[i][j] = 'O'; //player 1 is O
                }
            }
        }
    }
    return board[3][3];
}
