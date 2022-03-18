// header file funcoes.h
#include <stdio.h>

#define MAXNOME 40	

typedef enum { F, T } bool;	///Boolean

typedef struct obj {
	char nome[MAXNOME];	// Designação do Objeto
	float dist;	        // Distancia do objeto
	struct obj *seguinte;
}Objeto;

Objeto* inserirObjeto(Objeto * obj, char nome[], float d);
