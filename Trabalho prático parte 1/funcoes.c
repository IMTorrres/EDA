#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

Process *MallocProcessPlan(Process *prs)
{
    printf("MAlloc process plan"); // Debug
    prs = (Process *)malloc(sizeof(Process));
    return (prs);
}

Process *InsertProcessPlan(Process *prs, int nnp)
{

    if (prs != NULL)
    {
        prs->npp = nnp;
        prs->op = NULL;
        prs->next = NULL;
    }
    else
        return (prs);
}

void ShowList(Process *prs)
{
    Operation *op = NULL;
    Machine *mch = NULL;
    printf("entrou");
    while (prs != NULL)
    {
        printf("Number npp: %d\n", prs->npp);
         op=prs->op;
        while (op != NULL)
        {
            printf(" Operation: %d\n", op->noperation);
            mch = op->machine;
            while (mch!=NULL)
            {
                printf(" Machine: %d Time: %d\n", mch->pc, mch->time);

            }
            prs=prs->next;
        }

        prs = prs->next;
    }
}

Operation *MallocOperation(Operation *op)
{
    printf("MAlloc operações"); // Debug
    op = (Operation *)malloc(sizeof(Operation));
    return (op);
}

Operation *InsertOperation(Operation *op, Process *prs, int nprocess)
{   op =  MallocOperation(op);
    printf("InsertOperation entrou"); // debug
    while (prs != NULL)
    {
        if (nprocess == prs->npp)
        {
            printf("if nprocess == prs->npp\n");
            prs->op = op;
            op->machine = NULL;
            // InsertMachine()
        }
        else
        {
            op = op->next;
        }
    }
    return op;
}
Machine* MallocMachine(Machine *mch)
{
    printf("MAlloc machine"); // Debug
    mch = (Machine *)malloc(sizeof(Machine));
    return (mch);
}
void InsertMachine(Process *prs, int process, int maquina, int operacao, int pc, int time)
{
    Operation *op = NULL;
    Machine *mch = NULL;
    while (prs != NULL)
    {
        if (prs->npp = process)
        {
            prs->op = op;
            while (op != NULL)
            {
                if (op->noperation == operacao)
                {
                    mch = MallocMachine(mch);
                    op->machine = mch;
                    mch->pc = pc;
                    mch->time = time;
                }

                op = op->next;
            }
        }
        prs = prs->next;
    }
}

