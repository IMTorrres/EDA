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

void Showlist(Process *prs)
{
    Operation *op = NULL;
    Machine *mch = NULL;
    printf("entrou");
    while (prs != NULL)
    {
        printf("Number npp: %d\n", prs->npp);
        op = prs->op;
        while (op != NULL)
        {
            printf(" Operation: %d\n", op->noperation);
            mch = op->machine;
            while (mch != NULL)
            {
                printf(" Machine: %d Time: %d\n", mch->pc, mch->time);
            }
            prs = prs->next;
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

Operation *InsertOperation(Operation *op, Process *prs, int nprocess, int nop)
{
    op = MallocOperation(op);
    printf("InsertOperation entrou"); // debug
    while (prs != NULL)
    {
        if (nprocess = prs->npp)
        {
            op = prs->next;
            while (op!=NULL)
            {
                =MallocOperation(Operation *op)

        
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





                
            }
            
                printf("if nprocess == prs->npp\n");
                prs->op = op;
                op->machine = NULL;
                // InsertMachine();
        }
    }
    return op;
}
Machine *MallocMachine(Machine *mch)
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
