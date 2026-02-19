#include <stdio.h>
#include "header.h"

int main()
{
        int gridNums[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};       //Array to show the users which number to enter to choose a spot
        char board[3][3];       //Array to save X & O placements as the game progresses
        int player1 = 0;        //Track player 1's wins
        int player2 = 0;        //Track player 2's wins
        int input;     //User input. I changed this to an int since we are comparing the numbers the user entered to grid numbers.
        char keepPlaying = 'y';
        int moveCounter = 1; //Determine Cat's game.

        printf("-----------------------\n");
        printf("----  Tic-Tac-Toe  ----\n");
        printf("-----------------------\n");
        //Print the grid numbers before the game starts (call function)
        ////Only print once at the beginning of each game
        while(keepPlaying == 'y')
        {
                //Fill board array with dashes
                clearBoard(3, 3, board);//board is now empty.
                printBoard(3, 3, gridNums);
                printGameBoard(3, 3, board);

                //Game Logic
                while(moveCounter < 10)
                {
                        board[3][3] = enterMoves(turnCheck(moveCounter), 3, 3, gridNums, board, input);
                        moveCounter++;
                        printGameBoard(3, 3, board);
                }

                //Prompt players for spots and save
                



                //Ask to play again
                printf("Do you want to play again? (y/n): ");
                scanf(" %c", &keepPlaying);
        }
        return 0;
}
