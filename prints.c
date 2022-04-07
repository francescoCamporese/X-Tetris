#include "head.h"

void clear() /*pulisce lo schermo*/
{
	#ifdef _WIN32
	system("cls");
	#else
	system("clear");
	#endif
}

void make_pause() /*per attendere qualche secondo, la chiamo cosi in quanto unistd.h definisce gia una funzione di nome pause*/
{
	sleep(SECONDS);
}

void print_tetromino(t_tetromino* t) /*stampa un tetramino ruotato in uno dei modi per lui disponibili*/
{
	int i, j;
	
	for (i = 0; i < FOUR; ++i)
	{
		for (j = 0; j < FOUR; ++j)
			if ((t->container)[i][j])
				printf("%s%d%s ", KRED, (t->container)[i][j], KNRM);
			else
				printf("%d ", (t->container)[i][j]);
		printf("\n");
	}
	printf("\n");
}

void print_tetromat(t_tetromino tetromat[NROFTETROMINOS][FOUR], int tetrominos[NROFTETROMINOS]) /*stampa tutti i tetramini esistenti con le relative rotazioni per loro disponibili*/
{
	int i, j;

	printf("\n\n");

	for (i = 0; i < NROFTETROMINOS; ++i)
	{
		printf("TETROMINO n.%d (%d available)\n\n", i, tetrominos[i]);
		if (tetrominos[i])
		{
			for (j = 0; j < FOUR; ++j)
				if ((tetromat[i][j]).exists != 0)
				{
					printf("Rotation n.%d:\n", j);
					print_tetromino(&(tetromat[i][j]));
				}
			printf("\n\n");
		}
	}
	printf("\n\n");
}

void print_field(int field[ROWS][COLUMNS]) /*stampa il campo da gioco*/
{
	int i, j;

	printf("\nFIELD\n\n");

	for (i = 0; i < ROWS; ++i)
	{
		for (j = 0; j < COLUMNS; ++j)
			if (field[i][j])
				printf("%s%d%s     ", KRED, field[i][j], KNRM);
			else
				printf("%d     ", field[i][j]);
		printf("\n\n");
	}
}

void end_match_prints_sp(int field[ROWS][COLUMNS], int total_points, int has_won) /*stampa il risultato finale ed il relativo punteggio*/
{
	clear();
	print_field(field);

	if (has_won == 1)
		printf("\nYOU WON! ");
	else
		printf("\nYOU LOST ");

	printf("POINTS: %d\n\n", total_points);
	make_pause();
}

void end_match_prints_mp(int total_points1, int total_points2) /*stampa il risultato finale ed i relativi punteggi*/
{
	//TODO implementare secondo le casistiche
	printf("PLAYER 1 POINTS: %d\nPLAYER 2 POINTS:%d\n\n", total_points1, total_points2);	
	make_pause();
}

void print_game_menu() /*stampa menu*/
{
	clear();
	printf("X-TETRIS:\n");
	printf("1 Single player\n");
	printf("2 Two players\n");
	printf("3 Play versus the computer\n");
	printf("0 Exit\n");
	printf("Choose: ");
}