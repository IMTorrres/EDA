#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int main(){
	int machArray[10]={1, 3};
	int timehArray[10]={4, 5};
	int noperation=1;
 // Lista ligada vazia
 	Process *process=NULL;
	process = MallocProcessPlan(process);
	process = InsertProcessPlan(process,1);
	ShowList(process);

	Operation *op=NULL;
	op = MallocOperation(op);
	process = InsertProcessPlan(op,process,noperation,machArray,timehArray);
	ShowList(process);

}