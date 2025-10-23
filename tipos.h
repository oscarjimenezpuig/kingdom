/*
============================================================
  Fichero: tipos.h
  Creado: 22-10-2025
  Ultima Modificacion: mié 22 oct 2025 11:28:43
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#ifndef TIPOS_H
#define TIPOS_H

#include "constantes.h"

typedef unsigned char u1;
typedef unsigned short u2;
typedef unsigned int u4;
typedef unsigned char s1;
typedef signed short s2;
typedef signed int s4;

typedef struct {
	char name[CNL];
	u2 areas;
	u2 population;
	u2 grain;
	u2 soldiers;
} Country;

#endif 
