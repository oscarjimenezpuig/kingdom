/*
============================================================
  Fichero: simula.c
  Creado: 22-10-2025
  Ultima Modificacion: mié 22 oct 2025 12:08:50
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "paises.h"

int main() {
	randomize(-1);
	paises_init();
	for(int n=0;n<3;n++) {
		for(int m=0;m<3;m++) {
			pais_produccion(m);
			pais_consumo(m);
			pais_crecimiento(m);
			pais_print(m);
		}
		puts("======================");
	}
}
