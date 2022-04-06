#ifdef _WIN32 /*compatibile anche con windows*/
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <stdio.h>
#include <stdlib.h>

#define KRED  "\x1B[31m"
#define KNRM  "\x1B[0m"

/*clear && gcc -ansi -std=gnu99 -pedantic-errors -Wall -fsanitize=undefined -fsanitize=address -o xtetris xtetris.c && ./xtetris*/

const int SECONDS = 3; /*secondi di pausa*/
/*le lunghezze degli array, definite con const, non vanno bene con c90 in quanto non sono delle costanti a compile-time*/
const int ROWS = 15; /*altezza campo*/
const int COLUMNS = 10; /*larghezza campo*/
const int NROFTETROMINOS = 7; /*numero di tipi di tetramini*/
const int PIECES = 20; /*quantita disponibile di ciascun tipo di tetramino*/
const int FOUR = 4;

typedef struct s_tetromino /*rappresentazione di un tetramino*/
{
	int container[4][4];
	int exists;
} t_tetromino;

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

int is_row_full(int field[ROWS][COLUMNS], int row) /*dice se la riga row-esima e piena*/
{
	int j, used_cells = 0;

	for (j = 0; j < COLUMNS; ++j)
		used_cells += field[row][j];

	return used_cells == COLUMNS;
}

void shift_from_row(int field[ROWS][COLUMNS], int row) /*sposta dalla riga row-esima in su, verso giu di una riga*/
{
	int i, j;

	for (i = row; i >= 0; --i)
		for (j = 0; j < COLUMNS; ++j)
			field[i][j] = (row == 0 ? 0 : field[i - 1][j]);
	for (j = 0; j < COLUMNS; ++j)
		field[0][j] = 0;
}

int update_field_and_points(int field[ROWS][COLUMNS]) /*aggiorna il punteggio e la tabella in base alle righe piene*/
{
	int i;
	int full_rows = 0;
	int add_points = 0;

	for (i = ROWS - 1; i >= 0;)
		if (is_row_full(field, i))
		{
			++full_rows;
			shift_from_row(field, i);
		}
		else
			--i;

	switch (full_rows)
	{
		case 0:
		 	add_points = 0;
		 	break;
		case 1:
			add_points = 1;
			break;
		case 2:
			add_points = 3;
			break;
		case 3:
			add_points = 6;
			break;
		case 4:
			add_points = 12;
			break;
	}

	return add_points;
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

int is_game_finished_qty(int tetrominos[NROFTETROMINOS]) /*restituisce 1 se sono finiti tutti i tetramini, 0 altrimenti*/
{
	int i;
	
	for (i = 0; i < NROFTETROMINOS; ++i)
		if (tetrominos[i] > 0)
			return 0;

	return 1;
}

int overlaps(int field[ROWS][COLUMNS], t_tetromino tetromat[NROFTETROMINOS][FOUR], int tetronumber, int tetrorot, int tetrocol, int tetrorow) /*controlla dove si sta cercando di posizionare il tetramino. Restituisce 1 se il tetramino che sto provando a mettere si sovrappone a qualcosa di gia presente, -1 se parte del tetramino finirebbe sopra del campo, -2 se finirebbe a destra del campo, 0 altrimenti*/
{
	int i, j;

	for (i = 0; i < FOUR; ++i)
		for (j = 0; j < FOUR; ++j)
		{	
			if (tetrocol + j >= COLUMNS && ((tetromat[tetronumber][tetrorot]).container)[FOUR - i - 1][j])
				return -2;
			if (tetrorow - i < 0 && ((tetromat[tetronumber][tetrorot]).container)[FOUR - i - 1][j])
				return -1;
			if (tetrorow - i >= 0 && tetrocol + j < COLUMNS && field[tetrorow - i][tetrocol + j] && ((tetromat[tetronumber][tetrorot]).container)[FOUR - i - 1][j])
				return 1;
		}

	return 0;
}

void place_tetromino(int field[ROWS][COLUMNS], t_tetromino tetromat[NROFTETROMINOS][FOUR], int tetronumber, int tetrorot, int tetrocol, int tetrorow) /*posiziona il tetramino a partire da una certa riga e colonna, verso su*/
{
	int i, j;

	for (i = 0; i < FOUR; ++i)
		for (j = 0; j < FOUR; ++j)
			if (tetrorow - i >= 0 && tetrocol + j < COLUMNS && field[tetrorow - i][tetrocol + j] == 0)
				field[tetrorow - i][tetrocol + j] = ((tetromat[tetronumber][tetrorot]).container)[FOUR - i - 1][j];
}

int try_to_place(int field[ROWS][COLUMNS], t_tetromino tetromat[NROFTETROMINOS][FOUR], int tetronumber, int tetrorot, int tetrocol) /*posiziona il tetramino, di un certo tipo e rotazione, in basso a partire dall'alto della colonna indicata. Restituisce -1 se ho perso (non ci sta in altezza), 0 se e stato piazzato, 1 se il valore della colonna non e valido o se il tetramino e troppo a destra*/
{
	int row, fits_from_row = -1, res, retval = -1;
	
	if (tetrocol < 0 || tetrocol >= COLUMNS)
		return 1;
	for (row = 0; row < ROWS; ++row)
	{
		res = overlaps(field, tetromat, tetronumber, tetrorot, tetrocol, row);
		if (res == -2)
		{
			retval = 1;
			break;
		}
		else if (res == 0)
		{
			fits_from_row = row;
			retval = 0;
		}
		else if (res == 1)
			break;
	}
	if (fits_from_row < 0 && res == -1)
		retval = -1;
	if (retval == 0)
		place_tetromino(field, tetromat, tetronumber, tetrorot, tetrocol, fits_from_row);
	
	return retval;
}

int make_move(int field[ROWS][COLUMNS], t_tetromino tetromat[NROFTETROMINOS][FOUR], int tetrominos[NROFTETROMINOS], int playernr) /*restituisce 0 se ho posizionato il tetramino o fatto mossa nulla, -1 se ho perso (ovvero se il tetramino non ci sta in altezza)*/
{
	int tetronumber;
	int tetrorot;
	int tetrocol;
	int res;

	clear();
	if (playernr != 0)
		printf("\nPLAYER %d TURN\n", playernr);
	print_field(field);
	print_tetromat(tetromat, tetrominos);

	printf("Type of tetromino to use (0-6):");
	scanf("%d", &tetronumber);
	printf("Choose a rotation (0-depends from the selected tetromino):");
	scanf("%d", &tetrorot);

	if (tetronumber < 0 || tetronumber >= NROFTETROMINOS || tetrorot < 0 || tetrorot >= 4 || tetrominos[tetronumber] == 0 || (tetromat[tetronumber][tetrorot]).exists == 0) /*faccio il controllo sugli input e se ho finito i tetramini del tipo scelto oppure non esiste la rotazione indicata allora richiedo tutto*/
	{
		printf("The selected tetromino or the selected rotation for the tetromino are not available\n");
		make_pause();
	}
	else
	{
		printf("Further left column of the tetromino to place(0-%d): ", COLUMNS - 1);
		scanf("%d", &tetrocol);
		res = try_to_place(field, tetromat, tetronumber, tetrorot, tetrocol);

		if (res == 0)
		{
			--tetrominos[tetronumber];
		}
		else if (res == 1)
		{
			printf("You can't place the tetromino from this column (too right for the tetromino or wrong column value\n");
			make_pause();
		}
		else
			return res;
	}

	return 0;
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

void singleplayer() /*partita con un singolo giocatore*/
{
	int field[ROWS][COLUMNS];
	int tetrominos[NROFTETROMINOS];
	int total_points;
	int status;
	t_tetromino tetromat[NROFTETROMINOS][FOUR];
	
	init_tetromat(tetromat);
	init_match_values(field, tetrominos, &total_points, &status, PIECES);

	while (status == 0)
	{
		if (is_game_finished_qty(tetrominos))
			status = 1;
		else
			status = make_move(field, tetromat, tetrominos, 0);
		total_points += update_field_and_points(field);
	}

	end_match_prints_sp(field, total_points, status);
}

void multiplayer() /*partita contro un altro giocatore*/
{
	/*
	due giocatori giocano a turni alterni ciascuno nel proprio campo di gioco
	ma pescando dallo stesso insieme di tetramini (si avranno il doppio di pezzi a disposizione).
	
	//TODO:
	Nel caso in cui un giocatore cancelli una o due linee simultaneamente,
	il gioco procede come per il caso single player. Nel caso il giocatore cancelli 3 o
	più linee con una singola mossa, il campo dell’avversario viene modificato invertendo il corrispondente
	numero di linee nella parte più bassa del campo di gioco: una posizione vuota diventa piena e viceversa.
	Un giocatore perde la partita se non posiziona correttamente un pezzo nel proprio campo di gioco.
	Se i pezzi finiscono, vince il giocatore con il punteggio più alto.
	*/
	t_tetromino tetromat[NROFTETROMINOS][FOUR];
	int field1[ROWS][COLUMNS];
	int field2[ROWS][COLUMNS];
	int tetrominos[NROFTETROMINOS];
	int total_points1;
	int total_points2;
	int status; //TODO come lo gestisco?
	int playernr = 1;
	
	init_tetromat(tetromat);
	init_match_values(field1, tetrominos, &total_points1, &status, PIECES * 2);
	init_match_values(field2, NULL, &total_points2, &status, PIECES * 2);

	while (status == 0)
	{
		if (is_game_finished_qty(tetrominos))
			status = 1;
		else
		{
			if (playernr == 1)
				status = make_move(field1, tetromat, tetrominos, 1);
			else
				status = make_move(field2, tetromat, tetrominos, 2);
			
		}
		if (playernr == 1)
		{
			total_points1 += update_field_and_points(field1);
			playernr = 2;
		}
		else
		{
			total_points2 += update_field_and_points(field2);
			playernr = 1;
		}
	}

	end_match_prints_mp(total_points1, total_points2);
}

void ai() /*partita contro computer*/
{
	//TODO implementare possibilita di giocare anche contro un computer
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

void switch_menu(int* ahead) /*menu principale*/
{
	int chosen;

	print_game_menu();
	scanf("%d", &chosen);
	*ahead = chosen;

	switch (chosen)
	{
		case 1:
			singleplayer();
			break;
		case 2:
			multiplayer();
			break;
		case 3:
			ai();
			break;
		case 0:
			break;
		default:
			printf("Choose one of the possible choices!\n");
			make_pause();
			switch_menu(ahead);
			break;
	}
}

int main()
{
	int ahead = 1;

	while (ahead)
		switch_menu(&ahead);
		
	return 0;
}