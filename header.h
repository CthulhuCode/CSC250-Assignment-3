#ifndef HEADER_FILE
#define HEADER_FILE

void printBoard(int rows, int columns, int gridNums[][3]);
void printGameBoard(int rows, int columns, char board[][3]);
int clearBoard(int rows, int columns, char board[][3]);
int turnCheck(int moveNum);
char enterMoves(int playersTurn, int rows, int columns, int gridNums[][3], char board[][3], int input);


#endif
