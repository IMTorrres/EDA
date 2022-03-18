#include <string.h>
#include <stdlib.h>
#include "funcoes.h"


// Inserção de um novo objeto na 1ª posição de uma lista ligada
// referenciada pelo parâmetro lista
// lista: contém o endereço inicial da lista ligada
// nome: nome do objeto
// d: distância do objeto
// Devolve como resultado o novo endereço inicial da lista ligada
Objeto* inserirObjeto(Objeto * lista, char nome[], float d)
{Objeto *obj = (Objeto*) malloc(sizeof(Objeto));

 if (obj!=NULL)
 {strcpy(obj->nome,nome);
  obj->dist = d;
  obj->seguinte = lista;
  return(obj);
 }
 else return(lista);
}




void listarObjetos(Objeto *obj)
{while (obj!=NULL)
 {printf("%p %s %.2f %p\n", obj, obj->nome, obj->dist, obj->seguinte );
  obj = obj->seguinte;
 }
}

void listarObjetos2(Objeto *obj)
{for(;obj!=NULL;obj=obj->seguinte)
  printf("%p %s %.2f %p\n", obj, obj->nome, obj->dist, obj->seguinte );
}

void listarObjetos3(Objeto *obj)
{if (obj!=NULL)
 {printf("%p %s %.2f %p\n", obj, obj->nome, obj->dist, obj->seguinte );
  listarObjetos3(obj->seguinte);
 }
}

// Quantidade de objetos presentes na lista ligada referenciada por obj
int quantidadeObjetos(Objeto *obj)
{int soma=0;
 while(obj!=NULL)
 {obj=obj->seguinte;
  soma++;
 }
 return(soma);
}

// Solução recursiva
int quantidadeObjetos1(Objeto *obj)
{ if (obj!=NULL) return(1+quantidadeObjetos1(obj->seguinte));
  else return(0);
}

// Consultar objeto
// Apresentar a distancia da 1ª ocorrência do objeto cujo nome é 
// passado por parâmetro
float consultarObjeto(Objeto *obj, char nome[])
{while ((obj!=NULL) && strcmp(obj->nome,nome)!=0)
   obj = obj->seguinte;
 if (obj==NULL) return(-1);
 else return(obj->dist);
}


// Remover lista ligada
void removerObjetos(Objeto *obj)
{Objeto *aux;
 while(obj!=NULL)
 {aux = obj;
  obj = obj->seguinte;
  free(aux);
 }
}

// Remover a 1ª ocorrência do objeto cujo nome é passado 
// por parâmetro
Objeto* removerObjeto(Objeto *lista, char nome[])
{Objeto *nodoAtual = lista, *nodoAnterior;
 if (strcmp(nodoAtual->nome,nome)==0)
 {lista=nodoAtual->seguinte;
  free(nodoAtual);
 }
 else
 {nodoAnterior = lista;
  nodoAtual = nodoAnterior->seguinte;
  while ((nodoAtual!=NULL)&&(strcmp(nodoAtual->nome,nome)!=0))
  {nodoAnterior = nodoAtual;
   nodoAtual = nodoAtual->seguinte;
  }
  if (nodoAtual!=NULL)
  {nodoAnterior->seguinte = nodoAtual->seguinte;
   free(nodoAtual);
  }
 }
 return(lista);
}

