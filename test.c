#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

char x[3][3] = {{' ', ' ', ' '},
				{' ', ' ', ' '},
				{' ', ' ', ' '}};

void printBoard(char board[3][3])
{
	// first line
	printf("   1   2   3\n");
	printf("A| %1$c | %2$c | %3$c \n", board[0][0], board[0][1], board[0][2]);
	// 2nd line
	printf("-------------\n");
	printf("B| %1$c | %2$c | %3$c \n", board[1][0], board[1][1], board[1][2]);
	// 3rd line
	printf("-------------\n");
	printf("C| %1$c | %2$c | %3$c \n", board[2][0], board[2][1], board[2][2]);
	printf("\n");
	
}

bool placeLogic(char move[2], char piece)
{
	switch (toupper(move[0]))
	{
	case 'A':
		if (move[1] - '0' - 1 > 3)
		{
			printf("INVALID MOVE, please try again!\n");
			return false;
		}
		
		if (x[0][move[1] - '0' - 1] == ' ')
		{
			x[0][move[1] - '0' - 1] = piece;
			return true;
		}
		else
		{
			printf("INVALID MOVE, please try again!\n");
			return false;
		}

	case 'B':
		if (move[1] - '0' - 1> 3)
		{
			printf("INVALID MOVE, please try again!\n");
			return false;
		}
		if (x[1][move[1] - '0' - 1] == ' ')
		{
			x[1][move[1] - '0' - 1] = piece;
			return true;
		}
		else
		{
			printf("INVALID MOVE, please try again!\n");
			return false;
		}

		break;

	case 'C':
		if (move[1] - '0' - 1 > 3)
		{
			printf("INVALID MOVE, please try again!\n");
			return false;
		}
		if (x[2][move[1] - '0' - 1] == ' ')
		{
			x[2][move[1] - '0' - 1] = piece;
			return true;
		}
		else
		{
			printf("INVALID MOVE, please try again!\n");
			return false;
		}
		break;

	case 'E':
		exit(0);
		break;

	default:
		break;
	}

	printf("INVALID MOVE, please try again!\n");
	return false;
}

bool isGameWon()
{
	for (int i = 0; i < 3; i++)
	{
		if (x[i][0] == x[i][1] && x[i][1] == x[i][2] && x[i][0] != ' ')
		{
			return true;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (x[0][i] == x[1][i] && x[1][i] == x[2][i] && x[0][i] != ' ')
		{
			return true;
		}
	}

	if (x[0][0] == x[1][1] && x[1][1] == x[2][2] && x[1][1] != ' ')
	{
		return true;
	}

	if (x[2][0] == x[1][1] && x[1][1] == x[0][2] && x[1][1] != ' ')
	{
		return true;
	}
	return false;
}

int main()
{
	char scanmove[10];
	char piece = 'x';
	printf("Welcome to shitty tic tac toe:\n");
	printBoard(x);
	for (int i = 0; i < 9; i++)
	{
	PLACE_ATTEMPT:	
		printf("%1$c: Where do you want to place? (eg: B2) ", piece);
		scanf("%s", scanmove);
		printf("\n");

		if (!placeLogic(scanmove, piece))
		{
			goto PLACE_ATTEMPT;
		}
		printBoard(x);
		if (isGameWon())
		{
			printf("%1$c WON!\n", piece);
			exit(0);
		}
		if (piece == 'x')
			piece = 'o';
		else if (piece == 'o')
			piece = 'x';
	}

	printf("Game is tied!\n");
	return 0;
}