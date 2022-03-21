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

Process *MallocProcessPlan(Process *prs);
Process *InsertProcessPlan(Process *prs, int nnp);
Operation *MallocOperation(Operation *op);
Operation *InsertOperation(Operation *op, Process *prs, int nprocess);
Machine* MallocMachine(Machine *mch);
void InsertMachine(Process *prs, int process, int maquina, int operacao, int pc, int time);
