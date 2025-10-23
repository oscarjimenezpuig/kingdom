/*
============================================================
  Fichero: inout.c
  Creado: 22-10-2025
  Ultima Modificacion: dimecres, 22 d’octubre de 2025, 20:46:10
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "inout.h"

#define EOE '\0'
#define CAR '\n'

#define TABS 4

size_t copy(char* d,char* o) {
	char* pto=o;
	char* ptd=d;
	while(*pto!=EOE) *ptd++=*pto++;
	*ptd=EOE;
	return ptd-d;
}

size_t input(size_t l,char* s) {
	char c=0;
	char* pts=s;
	while((c=getchar())!=CAR && pts-s<l) *pts++=c;
	*pts=EOE;
	return pts-s;
}

void print(unsigned char ts,char* s,unsigned char ls) {
	for(unsigned char n=0;n<ts;n++) {
		for(unsigned char m=0;m<TABS;m++) {
			printf(" ");
		}
	}
	printf("%s",s);
	for(unsigned char n=0;n<ls;n++) printf("%c",CAR);
}

char* concatenate(char* d,const char* s,...) {
	va_list list;
	va_start(list,s);
	vsprintf(d,s,list);
	va_end(list);
	return d;
}

int strtonum(char* str) {
	int val=0;
	sscanf(str,"%i",&val);
	return val;
}
	
