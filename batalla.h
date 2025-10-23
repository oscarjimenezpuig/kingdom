/*
============================================================
  Fichero: batalla.h
  Creado: 22-10-2025
  Ultima Modificacion: jue 23 oct 2025 10:56:32
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#ifndef BATALLA_H
#define BATALLA_H

#include "paises.h"

int batalla(u2 id_atacante,u2 id_defensor);
//batalla entre atacante y defensor. Si el atacante gana se lleva un area del
//rival.
//Una batalla se hara entre cada soldado del pais atacante contra un soldado o el equivalente
//en granjeros del pais defensor. El que pierda resulta muerto (o muertos en caso de los
//granjeros). El que gane mas enfrentamientos es el ganador. Si es el atacante se queda
//con un area si es el defensor mantiene el area.
//La funcion devuelve un positivo si gana el atacante y un negativo si gana el defensor o
//hay empate.
//Un pais no puede atacar si no tiene soldados.

u2 atacante_gana(u2 id_atacante,u2 id_defensor);
//si el atacante gana la batalla se lleve un area. El defensor pierde el area y la 
//parte proporcional de habitantes correspondientes ha dicha area (eso es lo que retorna 
//la funcion

void batalla_de_jugador(u2 jugador_ataca,u2 defensor);

void batalla_contra_jugador(u2 atacante,u2 jugador_defensor);

void batalla_entre_no_jugadores(u2 atacante,u2 defensor);


#endif 

