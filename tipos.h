/*
============================================================
  Fichero: tipos.h
  Creado: 22-10-2025
  Ultima Modificacion: dimecres, 22 d’octubre de 2025, 18:49:47
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
	u1 jugador;
	u2 areas;
	u2 population;
	u2 grain;
	u2 soldiers;
} Country;

#endif 
