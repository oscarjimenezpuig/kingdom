/*
============================================================
  Fichero: turno.c
  Creado: 22-10-2025
  Ultima Modificacion: dijous, 23 d’octubre de 2025, 05:30:25
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "turno.h"

void transcurre_turno(u2 turno,u2* coste) {
	*coste=rnd(MIS,MAS);
	char str[100];
	concatenate(str,"YEAR: %i",turno);
	print(0,str,1);
	int ij=0;
	u1 idjug=0;
	u2 migracion_total=0;
	for(u1 i=0;i<NPT;i++) {
		ij=country[i].jugador;
		idjug=i;
		if(ij) {
			print(0,"In the begining of the year, your country: ",1);
			pais_print(i);
		}
		int pp=pais_produccion(i);
		if(ij) {
			concatenate(str,"Production of this year: %i tons",pp);
			print(0,str,1);
		}
		int cs=pais_consumo(i);
		if(ij) {
			if(cs>=0) {
				concatenate(str,"Your population waste %i tons of grain",cs);
			} else {
				concatenate(str,"There was not enough grain for your population, so %i inmates has dead...");
			}
			print(0,str,1);
		}
		int cv=pais_crecimiento(i);
		if(ij) {
			concatenate(str,"The rate growth of your country this year is %i",cv);
			print(0,str,1);
		}
		u2 mg=pais_migracion(i);
		if(mg>0 && ij) {
			concatenate(str,"You don't have enough place for everybody, so %i habitants leave your country...",mg);
			print(0,str,1);
		}
		migracion_total+=mg;
	}
	if(migracion_total>0) {
		u2 entrada[NPT];
		pais_inmigracion(entrada,migracion_total);
		for(u1 n=0;n<NPT;n++) {
			if(entrada[n]>0) {
				if(n==idjug) {
					concatenate(str,"From other countries of the world, arrive to your country %i new inmates...",entrada[n]);
					print(0,str,1);
				}
			}
		}
	}
	concatenate(str,"This year, the price for train a soldier is %i tons of grain",*coste);
	print(0,str,1);
}

void recorrido_turnos(u2 cs) {
	static int inicio=0;
	static int final=NPT;
	int p=inicio;
	s1 direccion=(inicio<final)?1:-1;
	while(p!=final) {
		Country* c=country+p;
		if(c->areas) {
			if(c->jugador) jugador_accion(p,cs);
			//TODO Falta programar acciones de paises de ordenador
		}
		p=p+direccion;
	}
	inicio=(inicio==0)?NPT-1:0;
	final=(final==-1)?NPT:-1;
}



		





