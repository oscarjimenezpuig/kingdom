/*
============================================================
  Fichero: batalla.c
  Creado: 22-10-2025
  Ultima Modificacion: jue 23 oct 2025 11:05:43
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "batalla.h"

#define DADO rnd(1,6)

int batalla(u2 a,u2 d) {
	Country* ca=country+a;
	Country* cd=country+d;
	u1 sa=ca->soldiers;
	int puntos=0;
	for(u1 n=0;n<sa;n++) {
		if(cd->soldiers>0 || cd->farmers>GES) {
			u1 da=DADO;
			u1 dd=DADO;
			if(da>dd) {
				if(cd->soldiers) {
					cd->soldiers--;
				} else if(cd->farmers) {
					cd->farmers-=GES;
				} else return 1;
				puntos++;
			} else if(dd>da) {
				if(ca->soldiers) {
					ca->soldiers--;
					puntos--;
				} else return -1;
			}
		} else puntos++;
	}
	return puntos;
}

u2 atacante_gana(u2 a,u2 d) {
	Country* ca=country+a;
	Country* cd=country+d;
	u2 poblacion=cd->farmers+cd->soldiers;
	int habper=poblacion*AGB/cd->areas;
	cd->areas-=AGB;
	ca->areas+=AGB;
	for(u2 n=0;n<habper;n++) {
		if(rnd(0,1)) {
			if(cd->soldiers) cd->soldiers--;
			else if(cd->farmers) cd->farmers--;
		} else {
			if(cd->farmers) cd->farmers--;
			else if(cd->soldiers) cd->soldiers--;
		}
	}
	return habper;
}

void batalla_de_jugador(u2 a,u2 d) {
	printf("id a=%i id d=%i\n",a,d);//dbg
	char str[100];
	Country* ca=country+a;
	Country* cd=country+d;
	concatenate(str,"You atack %s whith an army of %i soldiers",cd->name,ca->soldiers);
	print(0,str,1);
	concatenate(str,"Their army has %i soldiers to defend the country...",cd->soldiers);
	print(0,str,1);
	u2 sa=ca->soldiers;
	u2 sd=cd->soldiers;
	u2 gd=cd->farmers;
	int rb=batalla(a,d);
	if(rb>0) print(0,"YOU WIN THE BATTLE",1);
	else print(0,"YOU LOSE THE BATTLE",1);
	concatenate(str,"You lose %i soldiers in this battle",sa-ca->soldiers);
	print(0,str,1);
	concatenate(str,"%s lose %i soldiers and %i farmers in this battle",cd->name,sd-cd->soldiers,gd-cd->farmers);
	print(0,str,1);
	if(rb) {
		u2 pp=atacante_gana(a,d);
		concatenate(0,"You win %i area from %s. They loose %i inmates because of this",AGB,cd->name,pp);
		print(0,str,1);
	}
}

void batalla_contra_jugador(u2 a,u2 d) {
	char str[100];
	Country* ca=country+a;
	Country* cd=country+d;
	concatenate(str,"%s atacks you whith an army of %i soldiers",cd->name,ca->soldiers);
	print(0,str,1);
	concatenate(str,"Your army has %i soldiers to defend the country...",cd->soldiers);
	print(0,str,1);
	u2 sa=ca->soldiers;
	u2 sd=cd->soldiers;
	u2 gd=cd->farmers;
	int rb=batalla(a,d);
	if(rb>0) print(0,"YOU LOSE THE BATTLE",1);
	else print(0,"YOU WIN THE BATTLE",1);
	concatenate(str,"%s lose %i soldiers in this battle",ca->name,sa-ca->soldiers);
	print(0,str,1);
	concatenate(str,"You lose %i soldiers and %i farmers in this battle",cd->name,sd-cd->soldiers,gd-(cd->farmers));
	if(rb) {
		u2 pp=atacante_gana(a,d);
		concatenate(0,"You lose %i and %i inmates because of this",AGB,pp);
	}
}

void batalla_entre_no_jugadores(u2 a,u2 d) {
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



	
