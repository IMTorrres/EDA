#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int main(){
	Objeto *objetos=NULL; // Lista ligada vazia
	printf("Quantidade: %d\n", quantidadeObjetos(objetos));


	// Se a lista ligada não for vazia
	// então objetos contém o endereço de memória do
	// 1º registo da lista ligada
	objetos = inserirObjeto(objetos,"info1",100);
}