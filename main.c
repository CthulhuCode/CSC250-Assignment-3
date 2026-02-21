#include <stdio.h>
#include "header.h"

int main()
{
        int gridNums[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};       //Array to show the users which number to enter to choose a spot
        char board[3][3];       //Array to save X & O placements as the game progresses
        int player1 = 0;        //Track player 1's wins
        int player2 = 0;        //Track player 2's wins
        int input;     //User input. I changed this to an int since we are comparing the numbers the user entered to grid numbers.
        char keepPlaying;
        int cat = 0;//Track ties

        printf("-----------------------\n");
        printf("----  Tic-Tac-Toe  ----\n");
        printf("-----------------------\n");
        //Print the grid numbers before the game starts (call function)
        ////Only print once at the beginning of each game
        while(keepPlaying != 'n')
        {
                //Fill board array with dashes
                clearBoard(3, 3, board);//board is now empty.
                printBoard(3, 3, gridNums);
                printGameBoard(3, 3, board);
                int moveCounter = 1; //Determine Cat's game.

                //Game Logic
                while(moveCounter < 10)
                {
                        board[3][3] = enterMoves(turnCheck(moveCounter), 3, 3, gridNums, board, input);
                        printGameBoard(3, 3, board);
                        int winner = checkWin(3, 3, board, turnCheck(moveCounter));
                        if (winner != -1)//no winner yet
                        {
                                if (winner == 1)
                                {
                                        player1++;
                                        printf("Player 1 wins!\n");
                                        break;
                                }
                                else if (winner == 0)//numMoves/2 has a remainder of 0
                                {
                                        player2++;
                                        printf("Player 2 wins!\n");
                                        break;
                                }
                        }
                        moveCounter++;
                }
                if (moveCounter==10)
                {
                        cat++;
                        printf("Cat's game (tie)\n");
                }

                //Prompt players for spots and save
                



                //Ask to play again
                printf("Do you want to play again? (y/n): ");
                scanf(" %c", &keepPlaying);
        }
        saveScores(player1, player2, cat);
        printf("Thank you for playing! To view final results, open the scores.txt file.\n");
        return 0;
}
