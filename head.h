#ifndef XTETRIS
#define XTETRIS

#ifdef _WIN32 /*compatibile anche con windows*/
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <stdio.h>
#include <stdlib.h>

#define KRED  "\x1B[31m"
#define KNRM  "\x1B[0m"

/*gcc -ansi -std=gnu99 -pedantic-errors -Wall -fsanitize=undefined -fsanitize=address -o*/

const int SECONDS; /*secondi di pausa*/
/*le lunghezze degli array, definite con const, non vanno bene con c90 in quanto non sono delle costanti a compile-time*/
const int ROWS; /*altezza campo*/
const int COLUMNS; /*larghezza campo*/
const int NROFTETROMINOS; /*numero di tipi di tetramini*/
const int PIECES; /*quantita disponibile di ciascun tipo di tetramino*/
const int FOUR;

typedef struct s_tetromino /*rappresentazione di un tetramino*/
{
	int container[4][4];
	int exists;
} t_tetromino;

void clear(); /*pulisce lo schermo*/
void make_pause(); /*per attendere qualche secondo, la chiamo cosi in quanto unistd.h definisce gia una funzione di nome pause*/
void fill(t_tetromino* t, int i, int j); /*occupa un quadrato della matrice del tetramino*/
void init_tetromino(t_tetromino* t); /*mette tutti zeri nel tetramino*/
void init_tetromat(t_tetromino tetromat[NROFTETROMINOS][FOUR]); /*inizializza la matrice di tetramini*/
void print_tetromino(t_tetromino* t); /*stampa un tetramino ruotato in uno dei modi per lui disponibili*/
void print_tetromat(t_tetromino tetromat[NROFTETROMINOS][FOUR], int tetrominos[NROFTETROMINOS]); /*stampa tutti i tetramini esistenti con le relative rotazioni per loro disponibili*/
void print_field(int field[ROWS][COLUMNS]); /*stampa il campo da gioco*/
int is_row_full(int field[ROWS][COLUMNS], int row); /*dice se la riga row-esima e piena*/
void shift_from_row(int field[ROWS][COLUMNS], int row); /*sposta dalla riga row-esima in su, verso giu di una riga*/
int update_field_and_points(int field[ROWS][COLUMNS]); /*aggiorna il punteggio e la tabella in base alle righe piene*/
void end_match_prints_sp(int field[ROWS][COLUMNS], int total_points, int has_won); /*stampa il risultato finale ed il relativo punteggio*/
void end_match_prints_mp(int total_points1, int total_points2); /*stampa il risultato finale ed i relativi punteggi*/
int is_game_finished_qty(int tetrominos[NROFTETROMINOS]); /*restituisce 1 se sono finiti tutti i tetramini, 0 altrimenti*/
int overlaps(int field[ROWS][COLUMNS], t_tetromino tetromat[NROFTETROMINOS][FOUR], int tetronumber, int tetrorot, int tetrocol, int tetrorow); /*controlla dove si sta cercando di posizionare il tetramino. Restituisce 1 se il tetramino che sto provando a mettere si sovrappone a qualcosa di gia presente, -1 se parte del tetramino finirebbe sopra del campo, -2 se finirebbe a destra del campo, 0 altrimenti*/
void place_tetromino(int field[ROWS][COLUMNS], t_tetromino tetromat[NROFTETROMINOS][FOUR], int tetronumber, int tetrorot, int tetrocol, int tetrorow); /*posiziona il tetramino a partire da una certa riga e colonna, verso su*/
int try_to_place(int field[ROWS][COLUMNS], t_tetromino tetromat[NROFTETROMINOS][FOUR], int tetronumber, int tetrorot, int tetrocol); /*posiziona il tetramino, di un certo tipo e rotazione, in basso a partire dall'alto della colonna indicata. Restituisce -1 se ho perso (non ci sta in altezza), 0 se e stato piazzato, 1 se il valore della colonna non e valido o se il tetramino e troppo a destra*/
int make_move(int field[ROWS][COLUMNS], t_tetromino tetromat[NROFTETROMINOS][FOUR], int tetrominos[NROFTETROMINOS], int playernr); /*restituisce 0 se ho posizionato il tetramino o fatto mossa nulla, -1 se ho perso (ovvero se il tetramino non ci sta in altezza)*/
void init_match_values(int field[ROWS][COLUMNS], int tetrominos[NROFTETROMINOS], int* total_points, int* status, int piecesnr); /*inizializza campo, punteggio e stato del gioco per un singolo partecipante*/
void singleplayer(); /*partita con un singolo giocatore*/
void multiplayer(); /*partita contro un altro giocatore*/
void ai(); /*partita contro computer*/
void print_game_menu(); /*stampa menu*/
void switch_menu(int* ahead); /*menu principale*/

#endif