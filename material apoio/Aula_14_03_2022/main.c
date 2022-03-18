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
	objetos = inserirObjeto(objetos,"info1",100); // Inserção de um 1º registo
	printf("Quantidade: %d\n", quantidadeObjetos(objetos));
	objetos = inserirObjeto(objetos,"info2",200);
	printf("Quantidade: %d\n", quantidadeObjetos(objetos));
	objetos = inserirObjeto(objetos,"info3",300);
	printf("Quantidade: %d\n", quantidadeObjetos(objetos));
	objetos = inserirObjeto(objetos,"info4",400);
	printf("Quantidade: %d\n", quantidadeObjetos(objetos));
	objetos = inserirObjeto(objetos,"info5",500);

	// Listagem dos objetos existentes na lista ligada
	// referenciada por objetos
        listarObjetos(objetos);
        
	printf("Quantidade: %d\n", quantidadeObjetos(objetos));

	printf("Distancia: %.2f\n", consultarObjeto(objetos, "info6"));
        
	objetos = removerObjeto(objetos,"info1");
        listarObjetos(objetos);

	return 0;
}
