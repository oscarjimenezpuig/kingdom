/*
============================================================
  Fichero: jugador.c
  Creado: 22-10-2025
  Ultima Modificacion: jue 23 oct 2025 11:02:21
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "jugador.h"

void jugador_accion(u2 id,u2 cs) {
	char str[100];
	Country* c=country+id;
	if(c->grain>=cs && c->farmers>0) {
buy:
		print(0,"How many soldiers do you want to buy? ",0);
		char inp[10];
		input(9,inp);
		int compra=strtonum(inp);
		int coste=pais_compra_soldados(id,compra,cs);
		if(coste>0) {
			concatenate(str,"Yo get %i new soldiers and you expend %i tons of grain",compra,coste);
			print(0,str,1);
			goto end;
		} else if(coste==-1) {
			print(0,"You don't have enough grain to buy this soldiers",1);
			goto buy;
		} else if(coste==-2) {
			print(0,"You don't have enough farmers to train to be soldiers",1);
			goto buy;
		}
	}
	if(c->soldiers>0) {
		u2 ca[NPT];
		u2 cas=0;
		for(u1 n=0;n<NPT;n++) {
			Country* c=country+n;
			if(c->jugador==0 && c->areas>0) {
				ca[cas++]=n;
			}
		}
		if(cas) {
			print(0,"Do you want to attack any country?",1);
			print(0,"These are your options: ",1);
			print(1,"0. No",1);
			for(u1 n=0;n<cas;n++) {
				concatenate(str,"%i. %s",n+1,(country+ca[n])->name);
				print(1,str,1);
			}
try:
			print(0,"Try an option: ",0);
			char opt[3];
			input(2,opt);
			u1 nopt=strtonum(opt);
			if(nopt>cas) goto try;
			if(nopt>0) {
				batalla_de_jugador(id,ca[nopt-1]);
				goto end;
			}
		}
	}
	print(0,"You can't do anything for your country.",1);
	char pt[1];
	input(0,pt);
end:
}
	
