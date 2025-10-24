/*
============================================================
  Fichero: paises.c
  Creado: 22-10-2025
  Ultima Modificacion: dijous, 23 d’octubre de 2025, 19:17:35
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "paises.h"

Country country[NPT];

static void hispania() {
	Country* c=country+HID;
	copy(c->name,"Hispania");
	c->jugador=1;
	c->areas=10;
	c->farmers=10;
	c->grain=10;
	c->soldiers=0;
}

static void francia() {
	Country* c=country+FID;
	copy(c->name,"Francia");
	c->jugador=0;
	c->areas=10;
	c->farmers=10;
	c->grain=10;
	c->soldiers=0;
}

static void portugal() {
	Country* c=country+PID;
	copy(c->name,"Portugal");
	c->jugador=0;
	c->areas=5;
	c->farmers=9;
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
	u2 areas=c->areas;
	u2 grano_producido=0;
	int granjeros=c->farmers;
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
	u2 mfarmer=0;
	u2 msoldier=0;
	u2 consumo=0;
	for(u2 n=0;n<c->soldiers;n++) {
		if(c->grain>=GPS) {
			consumo+=GPS;
			c->grain-=GPS;
		} else {
			if(DADO<PMH) msoldier++;
		}
	}
	c->soldiers-=msoldier;
	for(u2 n=0;n<c->farmers;n++) {
		if(c->grain>=GPG) {
			consumo+=GPG;
			c->grain-=GPG;
		} else if(DADO<PMH) mfarmer++;
	}
	c->farmers-=mfarmer;
	int muertes=mfarmer+msoldier;
	if(muertes==0) return consumo;
	else return -muertes;
}

int pais_crecimiento(u1 id) {
	Country* c=country+id;
	u1 ij=c->jugador;
	u2 muerte_soldados=0;
	for(u2 n=0;n<c->soldiers;n++) {
		if(DADO<PMN) muerte_soldados++;
	}
	u2 muerte_granjeros=0;
	for(u2 n=0;n<c->farmers;n++) {
		if(DADO<PMN) muerte_granjeros++;
	}
	u2 muertes=muerte_soldados+muerte_granjeros;
	c->soldiers-=muerte_soldados;
	c->farmers-=muerte_granjeros;
	u2 nacimientos=0;
	u2 parejas=c->farmers/2;
	for(u2 n=0;n<parejas;n++) {
		nacimientos+=rnd(0,MHP);
	}
	c->farmers+=nacimientos;
	if(ij) {
		char str[100];
		concatenate(str,"In your country die %i farmers and %i soldiers. Born %i new habitants.",muerte_granjeros,muerte_soldados,nacimientos);
		print(0,str,1);
	}
	int crecimiento=(int)nacimientos-(int)muertes;
	return crecimiento;
}

u2 pais_migracion(u1 id) {
	Country* c=country+id;
	u2 maximo=c->areas*MHA;
	u2 migracion=0;
	u2 poblacion=c->farmers+c->soldiers;
	if(poblacion>maximo) {
		migracion=poblacion-maximo;
		for(u2 n=0;n<migracion;n++) {
			if(rnd(0,1)) {
				if(c->farmers) c->farmers--;
				else if(c->soldiers) c->soldiers--;
			} else {
				if(c->soldiers) c->soldiers--;
				else if(c->farmers) c->farmers--;
			}
		}
	}
	return migracion;
}

u2 pais_inmigracion(u2* entrada,u2 migracion) {
	u1 lleno[NPT];
	for(u1 n=0;n<NPT;n++) {
		entrada[n]=0;
		lleno[n]=0;
	}
	u2 out=0;
	u2 cid=0;
	while(migracion) {
		Country* c=country+cid;
		u2 maximo=c->areas*MHA;
		u2 poblacion=c->farmers+c->soldiers;
		if(lleno[cid]==0 && poblacion<maximo) {
			entrada[cid]++;
			c->farmers++;
			migracion--;
			cid=(cid+1)%MHA;
		} else {
			lleno[cid]=1;
			u1 suma=0;
			for(u2 n=0;n<NPT;n++) suma+=lleno[n];
			if(suma==NPT) {
				out=migracion;
				migracion=0;
			} else cid=(cid+1)%MHA;
		}
	}
	return out;
}

int pais_compra_soldados(u1 id,u2 s,u2 p) {
	Country* c=country+id;
	int cost=p*s;
	if(c->farmers>=s) {
		if(cost<=c->grain) {
			c->grain-=cost;
			c->soldiers+=s;
			c->farmers-=s;
			return cost;
		} else return -1;
	} else return -2;
}

u1 pais_vivo(u1 id) {
	Country* c=country+id;
	return (c->areas!=0);
}

void pais_principio_ano(u1 id) {
	Country* c=country+id;
	printf("%s\n",c->name);
	printf("The surface of the country is %i areas.\n",c->areas);
	printf("The country have in their granarys %i tons of grain.\n",c->grain);
	u2 population=c->farmers+c->soldiers;
	printf("The population of the country is %i habitants. %i of them are farmers and %i soldiers.\n",population,c->farmers,c->soldiers);
}

void pais_final_ano(u1 id) {
	Country* c=country+id;
	printf("So now, you have %i areas, %i tons of grain.\n",c->areas,c->grain);
	printf("Your population is %i habitants, %i farmers and %i soldiers.\n",c->farmers+c->soldiers,c->farmers,c->soldiers);
}

	
	
	

	


