/*
============================================================
  Fichero: paises.h
  Creado: 22-10-2025
  Ultima Modificacion: dijous, 23 d’octubre de 2025, 18:59:17
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

u2 pais_migracion(u1 id);
//se produce migracion de un pais a paises con disponibilidad de espacio siempre
//que se supere el maximo de habitantes permitidos, esta funcion devuelve
//el numero de habitantes que se han ido del pais

u2 pais_inmigracion(u2* entrada,u2 migracion);
//se introduce el numero total de migrantes de todos los paises y se reparten en los
//diferentes paises vacios. Si no hay, la poblacion se pierde. Entrada es un vector que
//guarda las entradas de habitantes a cada pais. El retorno de la funcion son los habitantes
//que desaparecen. La poblacion ya queda variada automaticamente.

int pais_compra_soldados(u1 id,u2 soldados,u2 precio);
//esta funcion hace la compra de soldados de un pais. El precio del soldado queda establecido
//al principio de cada turno. La funcion devuelve el precio si se han podido comprar los soldados
//y -1 si no se ha podido. Los soldados son transformacones de granjeros, por lo tanto, debe
//haber suficientes granjeros para ello. Salida -1 no hay dinero, salida -2 no hay granjeros, 
//salida positiva el coste, correcto.

u1 pais_vivo(u1 id);
//nos dice si un pais es vivo (tiene superficie o poblacion)

void pais_principio_ano(u1 id);
//imprimir caracteristicas del pais antes de todos los cambios del año

void pais_final_ano(u1 id);
//imnprimir todas las caracteristicas despues de los cambios del año


#endif
