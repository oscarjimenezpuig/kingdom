/*
============================================================
  Fichero: inout.h
  Creado: 22-10-2025
  Ultima Modificacion: mié 22 oct 2025 11:29:28
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#ifndef INOUT_H
#define INOUT_H

#include <stdio.h>
#include <stdarg.h>

size_t copy(char* destiny,char* origin);

size_t input(size_t len,char* str);

void print(unsigned char tab,char* s,unsigned char newline);
//imprime con tab tabulaciones delante y newlines carros detras

char* concatenate(char* destiny,const char* str,...);

#endif
