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

typedef struct _job
{
	Operation *op;
	struct _job *left;
	struct _job *right;
} *Job;

//..
Process *CreateProcessPlan(int numberProcess);
Process *InsertProcessPlan(Process *prsObj, Process *Process);

Operation *CreateOperation(int numberOperation);
Process *InsertMachineOperationProcess(Process *prs, Machine *mchObj, int numberOperation, int numberProcess);

Machine *CreateMachine(int pc, int time);
Process *InsertOperationProcess(Operation *opObj, Process *prs, int numberProcess);

Process *RemoveOperation(Process *process, int prsSub, int opSubs);

int ShowAll(Process *process, int showPrs, int showOp, int showMch);
int Showlist(Process *prs);
int Show(Process *process, int prsSub, int opSub, int showPrs, int showOp, int showMch);

Process *SearchProcessPlan(Process *prs, int nProcess);
Operation *SearchOperation(Operation *op, int nOperation);
Machine *SearchMachine(Machine *mch, int nMachine);

Machine *ChangeOperation(Process *process, int prsSub, int opSub, int mchSub, int newTime, int newPc);

Process *InsertData(Process *process);

Process *ReadFile(Process *process);

float MeanLow(Process *process, int processMeanLow);
float MeanHigh(Process *process, int processMeanHigh);
float MeanProcess(Process *process, int processMean);
float MeanOperation(Process *process, int operationMean);

int SumLow(Process *process, int processMeanLow);
int SumHigh(Process *process, int processSumHigh);

int CountOperation(Operation *operation);
int ShowProcess(Process *process);
Job consultar(Job abp, int valor);
Job inserir(Job abp, int valor);
void preorder(Job abp);