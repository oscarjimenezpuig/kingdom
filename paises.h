/*
============================================================
  Fichero: paises.h
  Creado: 22-10-2025
  Ultima Modificacion: mié 22 oct 2025 12:29:47
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#ifndef PAISES_H
#define PAISES_H

#include "tipos.h"
#include "utils.h"
#include "inout.h"

extern Country country[NPT];

void paises_init();
//define todos los paises

int pais_produccion(u1 id);
//devuelve la produccion de grano del pais en un año (el grano queda actualizado)

int pais_consumo(u1 id);
//da el grano consumido y actualiza el grano total. Si el resultado
//es positivo da el grano consumido, si es negativo las muertes totales
//primero consumen los soldados y luego los granjeros

int pais_crecimiento(u1 id);
//crecimiento vegetativo del pais (nacimientos y muertes) primero se aplican
//las muertes, luego los nacimientos (en positivo crecimiento positivo, en negativo, negativo)
//Los soldados no tienen hijos

int pais_migracion(u1 id);
//se produce migracion de un pais a paises con disponibilidad de espacio siempre
//que se supere el maximo de habitantes permitidos, esta funcion devuelve
//el numero de habitantes que se han ido del pais

void pais_print(u1 id);
//imprimir caracteristicas del pais

#endif
