#include <string.h>
#include <stdlib.h>
#include "funcoes.h"

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
