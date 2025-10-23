/*
============================================================
  Fichero: turno.h
  Creado: 22-10-2025
  Ultima Modificacion: dijous, 23 d’octubre de 2025, 05:13:37
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#ifndef TURNO_H
#define TURNO_H

#include "jugador.h"

void transcurre_turno(u2 turno,u2* coste_soldado);

void recorrido_turnos(u2 coste_soldado);
//esta funcion va recorriendo los turnos dando los paises que todavia tienen entidad

#endif
