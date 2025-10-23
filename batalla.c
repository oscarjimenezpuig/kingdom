/*
============================================================
  Fichero: batalla.c
  Creado: 22-10-2025
  Ultima Modificacion: dijous, 23 d’octubre de 2025, 05:00:43
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "batalla.h"

#define DADO rnd(1,6)

int batalla(u1 a,u1 d) {
	Country* ca=country+a;
	Country* cd=country+d;
	u1 sa=ca->soldiers;
	int puntos=0;
	for(u1 n=0;n<sa;n++) {
		if(cd->soldiers>0 || cd->population>GES) {
			u1 da=DADO;
			u1 dd=DADO;
			if(da>dd) {
				if(cd->soldiers) {
					cd->soldiers--;
					cd->population--;
				} else cd->population-=GES;
				puntos++;
			} else if(dd>da) {
				ca->soldiers--;
				ca->population--;
				puntos--;
			}
		} else puntos++;
	}
	return puntos;
}

u2 atacante_gana(u1 a,u1 d) {
	Country* ca=country+a;
	Country* cd=country+d;
	int habper=cd->population*AGB/cd->areas;
	cd->areas-=AGB;
	ca->areas+=AGB;
	cd->population-=habper;
	if(cd->soldiers>cd->population) cd->soldiers=cd->population;
	return habper;
}

void batalla_de_jugador(u1 a,u1 d) {
	char str[100];
	Country* ca=country+a;
	Country* cd=country+d;
	concatenate(str,"You atack %s whith an army of %i soldiers",cd->name,ca->soldiers);
	print(0,str,1);
	concatenate(str,"Their army has %i soldiers to defend the country...",cd->soldiers);
	print(0,str,1);
	u2 sa=ca->soldiers;
	u2 sd=cd->soldiers;
	u2 gd=cd->population-sd;
	int rb=batalla(a,d);
	if(rb>0) print(0,"YOU WIN THE BATTLE",1);
	else print(0,"YOU LOSE THE BATTLE",1);
	concatenate(str,"You lose %i soldiers in this battle",sa-ca->soldiers);
	print(0,str,1);
	concatenate(str,"%s lose %i soldiers and %i farmers in this battle",cd->name,sd-cd->soldiers,gd-(cd->population-cd->soldiers));
	if(rb) {
		u2 pp=atacante_gana(a,d);
		concatenate(0,"You win %i area from %s. They loose %i inmates because of this",AGB,cd->name,pp);
	}
}

void batalla_contra_jugador(u1 a,u1 d) {
	char str[100];
	Country* ca=country+a;
	Country* cd=country+d;
	concatenate(str,"%s atacks you whith an army of %i soldiers",cd->name,ca->soldiers);
	print(0,str,1);
	concatenate(str,"Your army has %i soldiers to defend the country...",cd->soldiers);
	print(0,str,1);
	u2 sa=ca->soldiers;
	u2 sd=cd->soldiers;
	u2 gd=cd->population-sd;
	int rb=batalla(a,d);
	if(rb>0) print(0,"YOU LOSE THE BATTLE",1);
	else print(0,"YOU WIN THE BATTLE",1);
	concatenate(str,"%s lose %i soldiers in this battle",ca->name,sa-ca->soldiers);
	print(0,str,1);
	concatenate(str,"You lose %i soldiers and %i farmers in this battle",cd->name,sd-cd->soldiers,gd-(cd->population-cd->soldiers));
	if(rb) {
		u2 pp=atacante_gana(a,d);
		concatenate(0,"You lose %i and %i inmates because of this",AGB,pp);
	}
}

void batalla_entre_no_jugadores(u1 a,u1 d) {
	char str[100];
	Country* ca=country+a;
	Country* cd=country+d;
	concatenate("Some notices arrive. %s attack %s...",ca->name,cd->name);
	int rb=batalla(a,d);
	if(rb>0) {
		concatenate(str,"Seems that %s win the battle...",ca->name);
		atacante_gana(a,d);
	} else {
		concatenate(str,"Seems that %s lose the battle...",ca->name);
	}
	print(0,str,1);
}



	
