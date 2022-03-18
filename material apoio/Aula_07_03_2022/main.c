#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int main(){
	Objeto *objetos=NULL; // Lista ligada vazia

	objetos = inserirObjeto(objetos,"info1",100); // Inserção de um 1º registo
	objetos = inserirObjeto(objetos,"info2",200);
	objetos = inserirObjeto(objetos,"info3",300);
	objetos = inserirObjeto(objetos,"info4",400);
	objetos = inserirObjeto(objetos,"info5",500);

	return 0;
}
