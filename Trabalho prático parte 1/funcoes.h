// header file funcoes.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Lista de dados papra 
typedef struct _machine {      
	int pc;
	int time;
	struct _machine *next;
}Machine;


typedef struct _op {
	int noperation;
	Machine *machine;
	struct _op *next;
}Operation;


typedef struct _pp {
	int npp;
	Operation *op;	      
	struct _pp *next;
}Process;


Process* mallocProcessPlan(Operation* op, Process* prs,int noperation, int machArray[],int timehArray[]);
Process* insertProcessPlan(Process* prs,int npp);
void showList(Process* prs);