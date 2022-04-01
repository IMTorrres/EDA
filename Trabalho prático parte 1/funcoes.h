/**
 * @file funcoes.h
 * @author GonçaloTorres (gon.im.torres@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-03-23
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Lista de dados papra maquinas
typedef struct _machine
{
	int pc;
	int time;
	struct _machine *next;
} Machine;

// Lista de dados papra operações e contem apontador para lista de maquinas
typedef struct _op
{
	int noperation;
	Machine *machine;
	struct _op *next;
} Operation;

// Lista de dados papra processplan e contem apontador para lista de operações
typedef struct _pp
{
	int npp;
	Operation *op;
	struct _pp *next;
} Process;

Process *CreateProcessPlan(int npp);
Process *InsertProcessPlan(Process *prs, Process *Process);
Operation *CreateOperation(int nop);
Process *InsertOperationProcess(Operation *op, Process *prs, int nprocess);
Machine *CreateMachine(int pc, int time);
Process *InsertMachineOperationProcess(Process *prs, Machine *mch, int nop, int nprocess);
void RemoveOperation(Process *process, int opPrs, int opSubs);
int ShowOperation(Process *process, int prsSub, int opSub);
void Showlist(Process *prs);
Process *SearchProcessPlan(Process *prs, int nProcess);
Operation *SearchOperation(Operation *op, int nOperation);
Machine *SearchMachine(Machine *mch, int nMachine);
void ChangeMachine(Process *process, int prsSub, int opSub, int mchSub);
Process *InsertData(Process *process);
Process *ReadFile(Process *process);
