/*
============================================================
  Fichero: simula.c
  Creado: 22-10-2025
  Ultima Modificacion: dijous, 23 d’octubre de 2025, 05:14:28
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "turno.h"

int main() {
	randomize(-1);
	paises_init();
	u2 year=1;
	for(u1 n=0;n<10;n++) {
		u2 coste;
		transcurre_turno(year++,&coste);
		recorrido_turnos(coste);
	}
	return 0;
}
