#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FNAME "bacteria"
#define EXT ".ext"
#define S "#include <stdio.h>%1$c#include <stdlib.h>%1$c#include <string.h>%1$c#define FNAME %2$cbacteria%2$c%1$c#define EXT %2$c.ext%2$c%1$c#define S %2$c%3$s%2$c%1$cint i = %5$d;%1$c#define FT() int main() {char filename[50]; char cmd[120]; sprintf(filename, %2$c%4$cs_%4$cd.c%2$c, FNAME, i); FILE *f = fopen(filename, %2$cw%2$c); if (!f) return 1; fprintf(f, S, 10, 34, S, 37, i - 1); fclose(f); sprintf(cmd, %2$cgcc %4$c1$s_%4$c2$d.c -o %4$c1$s_%4$c2$d%4$c3$s%2$c, FNAME, i, EXT); system(cmd); if (i <= 0) return 0; sprintf(filename, %2$c./%4$cs_%4$cd%4$cs%2$c, FNAME, i, EXT); system(filename); return 0;}%1$c/*%1$c	Run quine%1$c*/%1$cFT();"
int i = 50;
#define FT() int main() {char filename[50]; char cmd[120]; sprintf(filename, "%s_%d.c", FNAME, i); FILE *f = fopen(filename, "w"); if (!f) return 1; fprintf(f, S, 10, 34, S, 37, i - 1); fclose(f); sprintf(cmd, "gcc %1$s_%2$d.c -o %1$s_%2$d%3$s", FNAME, i, EXT); system(cmd); if (i <= 0) return 0; sprintf(filename, "./%s_%d%s", FNAME, i, EXT); system(filename); return 0;}
/*
	Run quine
*/
FT();