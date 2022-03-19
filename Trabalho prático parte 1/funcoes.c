#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

Process *MallocProcessPlan(Process *prs)
{
     printf("MAlloc process plan");//Debug
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
    printf("entrou");
    while (prs != NULL)
    {
        printf("Number npp: %d e %p\n", prs->npp, prs->next);
        prs = prs->next;
    }
}

Operation *MallocOperation(Operation *op)
{
    printf("MAlloc operações");//Debug
    op = (Operation *)malloc(sizeof(Operation));
    return (op);
}

Operation *InsertOperation(Operation *op,Process *prs,int nprocess,int noperation,int machArray[],int timehArray[])
{
    if(nprocess!=)


    if (prs != NULL)
    {
        prs->npp = nnp;
        prs->op = NULL;
        prs->next = NULL;
    }
    else
        return (prs);
}
