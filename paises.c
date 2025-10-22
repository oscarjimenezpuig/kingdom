/*
============================================================
  Fichero: paises.c
  Creado: 22-10-2025
  Ultima Modificacion: mié 22 oct 2025 12:29:47
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "paises.h"

Country country[NPT];

static void hispania() {
	Country* c=country+HID;
	copy(c->name,"Hispania");
	c->areas=10;
	c->population=10;
	c->grain=10;
	c->soldiers=0;
}

static void francia() {
	Country* c=country+FID;
	copy(c->name,"Francia");
	c->areas=10;
	c->population=10;
	c->grain=10;
	c->soldiers=0;
}

static void portugal() {
	Country* c=country+PID;
	copy(c->name,"Portugal");
	c->areas=5;
	c->population=10;
	c->grain=10;
	c->soldiers=1;
}

void paises_init() {
	hispania();
	francia();
	portugal();
}

int pais_produccion(u1 id) {
	Country* c=country+id;
	u2 granjeros=c->population-c->soldiers;
	u2 areas=c->areas;
	u2 grano_producido=0;
	while(granjeros && areas) {
		if(granjeros>=HNP) {
			granjeros-=HNP;
			grano_producido+=rnd(1,MPG);
		} else {
			u2 limite=MPG*granjeros/HNP;
			grano_producido+=rnd(1,limite);
		}
		areas--;
	}
	c->grain+=grano_producido;
	return grano_producido;
}

#define DADO rnd(1,100)

int pais_consumo(u1 id) {
	Country* c=country+id;
	u2 granjeros=c->population-c->soldiers;
	u2 muertes=0;
	u2 consumo=0;
	for(u2 n=0;n<c->soldiers;n++) {
		if(c->grain>=GPS) {
			consumo+=GPS;
			c->grain-=GPS;
		} else {
			if(DADO<PMH) muertes++;
		}
	}
	for(u2 n=0;n<granjeros;n++) {
		if(c->grain>=GPG) {
			consumo+=GPG;
			c->grain-=GPG;
		} else if(DADO<PMH) muertes++;
	}
	c->population-=muertes;
	if(muertes==0) return consumo;
	else return -muertes;
}

int pais_crecimiento(u1 id) {
	Country* c=country+id;
	u2 granjeros=c->population-c->soldiers;
	u2 muerte_soldados=0;
	for(u2 n=0;n<c->soldiers;n++) {
		if(DADO<PMN) muerte_soldados++;
	}
	u2 muerte_granjeros=0;
	for(u2 n=0;n<granjeros;n++) {
		if(DADO<PMN) muerte_granjeros++;
	}
	u2 muertes=muerte_soldados+muerte_granjeros;
	c->soldiers-=muerte_soldados;
	c->population-=muertes;
	u2 nacimientos=0;
	u2 parejas=granjeros/2;
	for(u2 n=0;n<parejas;n++) {
		nacimientos+=rnd(0,MHP);
	}
	c->population+=nacimientos;
	int crecimiento=(int)nacimientos-(int)muertes;
	return crecimiento;
}

int pais_migracion(u1 id) {
	Country* c=country+id;
	u2 maximo=c->areas*MHA;
	u2 migracion=0;
	if(c->population>maximo) {
		migracion=c->population-maximo;
		c->population=maximo;
	}
	return migracion;
}

void pais_print(u1 id) {
	Country* c=country+id;
	printf("%s\n",c->name);
	printf("Areas: %i\n",c->areas);
	printf("Population: %i\n",c->population);
	printf("Grain: %i\n",c->grain);
	printf("Soldiers: %i\n",c->soldiers);
}



	


