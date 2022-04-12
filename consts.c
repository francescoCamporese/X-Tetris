#include "head.h"

const int SECONDS = 3; /*secondi di pausa*/
/*le lunghezze degli array, definite con const, non vanno bene con c90 in quanto non sono delle costanti a compile-time*/
const int ROWS = 15; /*altezza campo*/
const int COLUMNS = 10; /*larghezza campo*/
const int NROFTETROMINOS = 7; /*numero di tipi di tetramini*/
const int PIECES = 20; /*quantita disponibile di ciascun tipo di tetramino*/
const int FOUR = 4;
const int BUFSIZE = 1024;