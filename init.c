#include "head.h"

void fill(t_tetromino* t, int i, int j) /*occupa un quadrato della matrice del tetramino*/
{
	(t->container)[i][j] = 1;
}

void init_tetromino(t_tetromino* t) /*mette tutti zeri nel tetramino*/
{
	int i, j;

	for (i = 0; i < FOUR; ++i)
		for (j = 0; j < FOUR; ++j)
			(t->container)[i][j] = 0;
}

void init_tetromat(t_tetromino tetromat[NROFTETROMINOS][FOUR]) /*inizializza la matrice di tetramini*/
{
	int i, j;

	for (i = 0; i < NROFTETROMINOS; ++i)
		for (j = 0; j < FOUR; ++j)
		{
			init_tetromino(&(tetromat[i][j]));
			(tetromat[i][j]).exists = 0;
		}

	(tetromat[0][0]).exists = 1;
	(tetromat[0][1]).exists = 1;
	(tetromat[0][2]).exists = 0;
	(tetromat[0][3]).exists = 0;

	(tetromat[1][0]).exists = 1;
	(tetromat[1][1]).exists = 1;
	(tetromat[1][2]).exists = 1;
	(tetromat[1][3]).exists = 1;

	(tetromat[2][0]).exists = 1;
	(tetromat[2][1]).exists = 1;
	(tetromat[2][2]).exists = 1;
	(tetromat[2][3]).exists = 1;

	(tetromat[3][0]).exists = 1;
	(tetromat[3][1]).exists = 0;
	(tetromat[3][2]).exists = 0;
	(tetromat[3][3]).exists = 0;

	(tetromat[4][0]).exists = 1;
	(tetromat[4][1]).exists = 1;
	(tetromat[4][2]).exists = 0;
	(tetromat[4][3]).exists = 0;

	(tetromat[5][0]).exists = 1;
	(tetromat[5][1]).exists = 1;
	(tetromat[5][2]).exists = 0;
	(tetromat[5][3]).exists = 0;

	(tetromat[6][0]).exists = 1;
	(tetromat[6][1]).exists = 1;
	(tetromat[6][2]).exists = 1;
	(tetromat[6][3]).exists = 1;

	fill(&(tetromat[0][0]), 3, 0);
	fill(&(tetromat[0][0]), 3, 1);
	fill(&(tetromat[0][0]), 3, 2);
	fill(&(tetromat[0][0]), 3, 3);

	fill(&(tetromat[0][1]), 0, 0);
	fill(&(tetromat[0][1]), 1, 0);
	fill(&(tetromat[0][1]), 2, 0);
	fill(&(tetromat[0][1]), 3, 0);

	fill(&(tetromat[1][0]), 2, 0);
	fill(&(tetromat[1][0]), 2, 1);
	fill(&(tetromat[1][0]), 2, 2);
	fill(&(tetromat[1][0]), 3, 2);

	fill(&(tetromat[1][1]), 1, 1);
	fill(&(tetromat[1][1]), 2, 1);
	fill(&(tetromat[1][1]), 3, 1);
	fill(&(tetromat[1][1]), 3, 0);

	fill(&(tetromat[1][2]), 1, 0);
	fill(&(tetromat[1][2]), 1, 1);
	fill(&(tetromat[1][2]), 2, 0);
	fill(&(tetromat[1][2]), 3, 0);

	fill(&(tetromat[1][3]), 2, 0);
	fill(&(tetromat[1][3]), 3, 0);
	fill(&(tetromat[1][3]), 3, 1);
	fill(&(tetromat[1][3]), 3, 2);

	fill(&(tetromat[2][0]), 2, 0);
	fill(&(tetromat[2][0]), 2, 1);
	fill(&(tetromat[2][0]), 2, 2);
	fill(&(tetromat[2][0]), 3, 0);

	fill(&(tetromat[2][1]), 1, 0);
	fill(&(tetromat[2][1]), 1, 1);
	fill(&(tetromat[2][1]), 2, 1);
	fill(&(tetromat[2][1]), 3, 1);

	fill(&(tetromat[2][2]), 2, 2);
	fill(&(tetromat[2][2]), 3, 0);
	fill(&(tetromat[2][2]), 3, 1);
	fill(&(tetromat[2][2]), 3, 2);

	fill(&(tetromat[2][3]), 1, 0);
	fill(&(tetromat[2][3]), 2, 0);
	fill(&(tetromat[2][3]), 3, 0);
	fill(&(tetromat[2][3]), 3, 1);

	fill(&(tetromat[3][0]), 2, 0);
	fill(&(tetromat[3][0]), 2, 1);
	fill(&(tetromat[3][0]), 3, 0);
	fill(&(tetromat[3][0]), 3, 1);

	fill(&(tetromat[4][0]), 2, 1);
	fill(&(tetromat[4][0]), 2, 2);
	fill(&(tetromat[4][0]), 3, 0);
	fill(&(tetromat[4][0]), 3, 1);

	fill(&(tetromat[4][1]), 1, 0);
	fill(&(tetromat[4][1]), 2, 0);
	fill(&(tetromat[4][1]), 2, 1);
	fill(&(tetromat[4][1]), 3, 1);

	fill(&(tetromat[5][0]), 2, 0);
	fill(&(tetromat[5][0]), 2, 1);
	fill(&(tetromat[5][0]), 3, 1);
	fill(&(tetromat[5][0]), 3, 2);

	fill(&(tetromat[5][1]), 1, 1);
	fill(&(tetromat[5][1]), 2, 0);
	fill(&(tetromat[5][1]), 2, 1);
	fill(&(tetromat[5][1]), 3, 0);

	fill(&(tetromat[6][0]), 2, 0);
	fill(&(tetromat[6][0]), 2, 1);
	fill(&(tetromat[6][0]), 2, 2);
	fill(&(tetromat[6][0]), 3, 1);

	fill(&(tetromat[6][1]), 1, 1);
	fill(&(tetromat[6][1]), 2, 0);
	fill(&(tetromat[6][1]), 2, 1);
	fill(&(tetromat[6][1]), 3, 1);

	fill(&(tetromat[6][2]), 2, 1);
	fill(&(tetromat[6][2]), 3, 0);
	fill(&(tetromat[6][2]), 3, 1);
	fill(&(tetromat[6][2]), 3, 2);

	fill(&(tetromat[6][3]), 1, 0);
	fill(&(tetromat[6][3]), 2, 0);
	fill(&(tetromat[6][3]), 2, 1);
	fill(&(tetromat[6][3]), 3, 0);
}

void init_match_values(int field[ROWS][COLUMNS], int tetrominos[NROFTETROMINOS], int* total_points, int* status, int piecesnr) /*inizializza campo, punteggio e stato del gioco per un singolo partecipante*/
{
	int i, j;

	for (i = 0; i < ROWS; ++i)
		for (j = 0; j < COLUMNS; ++j)
			field[i][j] = 0;
	if (tetrominos != NULL)
		for (i = 0; i < NROFTETROMINOS; ++i)
			tetrominos[i] = piecesnr;

	*total_points = 0;
	*status = 0;
}