/*
============================================================
  Fichero: utils.c
  Creado: 22-10-2025
  Ultima Modificacion: mié 22 oct 2025 10:48:43
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "utils.h"

void randomize(int s) {
	if(s<0) srand(time(NULL));
	else srand(s);
}

int rnd(int a,int b) {
	int max=(a>b)?a:b;
	int min=(a>b)?b:a;
	int dif=max-min+1;
	return min+(rand()%dif);
}

void pause(double s) {
	clock_t next=clock()+s*CLOCKS_PER_SEC;
	while(clock()<next);
}
