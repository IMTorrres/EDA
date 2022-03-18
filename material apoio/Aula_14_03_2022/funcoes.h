// header file funcoes.h
#include <stdio.h>

#define MAXNOME 40	

typedef struct obj {
	char nome[MAXNOME];	// Designação do Objeto
	float dist;	        // Distancia do objeto
	struct obj *seguinte;
}Objeto;

Objeto* inserirObjeto(Objeto * obj, char nome[], float d);
void listarObjetos(Objeto * obj);
int quantidadeObjetos(Objeto *obj);
float consultarObjeto(Objeto *obj, char nome[]);
Objeto* removerObjeto(Objeto *lista, char nome[]);
