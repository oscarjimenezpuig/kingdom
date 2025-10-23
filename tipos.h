/*
============================================================
  Fichero: tipos.h
  Creado: 22-10-2025
  Ultima Modificacion: jue 23 oct 2025 10:48:01
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#ifndef TIPOS_H
#define TIPOS_H

#include "constantes.h"

typedef unsigned char u1;
typedef unsigned short u2;
typedef unsigned int u4;
typedef signed char s1;
typedef signed short s2;
typedef signed int s4;

typedef struct {
	char name[CNL];
	u1 jugador;
	u2 areas;
	u2 farmers;
	u2 soldiers;
	u2 grain;
} Country;

#endif 
