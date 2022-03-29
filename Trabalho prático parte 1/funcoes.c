/**
 * @file funcoes.c
 * @author GonçaloTorres (gon.im.torres@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-03-23
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma region Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
#pragma endregion

#pragma region Metodosº
/*
Process *InsertData(Process *process, int nprocess, int nop, int pc, int time)
{
    Process *prs = CreateProcessPlan(nprocess);
    process = InsertProcessPlan(prs, process);

    Operation *operationobj = CreateOperation(nop);
    process = InsertOperationProcess(operationobj, process, nprocess);

    operationobj = CreateOperation(3);
    process = InsertOperationProcess(operationobj, process, nprocess);

    Machine *machineobj = CreateMachine(pc, time);
    process = InsertMachineOperationProcess(process, machineobj, nop, nprocess);
    Machine *machine = CreateMachine(12, 21);
    process = InsertMachineOperationProcess(process, machine, 3, nprocess);
}*/
/*
Process *ReadFile()
{

    FILE *fl = fopen("dados.txt", "rt");
    char str[50];
    char str1[50];
    int machine[10];
    int time[10];
    char *pch;
    char *pch1;
    int op;
    if (fl != NULL)

        if (!feof(fl))
        {
            printf("\nentrou_____________-\n");
            fscanf(fl, "%d;%[^;];%[^;]\n", &op, str, str1);
            printf("ola %d %s %s", op, str, str1);
            fclose(fl);
            InsertData(process,nprocess, int nop, int pc, int time);
        }
}
*/
Process *SearchProcessPlan(Process *prs, int nProcess)
{
    Process *auxPrs = prs;

    while (auxPrs != NULL)
    {
        if (nProcess == auxPrs->npp)
        {
            return auxPrs;
        }

        auxPrs = auxPrs->next;
    }
 
}

Operation *SearchOperation(Operation *op, int nOperation)
{
    Operation *auxOp = op;
    while (auxOp != NULL)
    {
        if (nOperation == auxOp->noperation)
        {
            return auxOp;
        }
        auxOp = auxOp->next;
    }
}
Machine *SearchMachine(Machine *mch, int nMachine)
{
    Machine *auxMch = mch;
    while (auxMch != NULL)
    {
        if (nMachine == auxMch->pc)
        {
            return auxMch;
        }
        auxMch = auxMch->next;
    }
}
Machine *ChangeMachine(Process *process, int nProcess, int nOperation, int nMachine)
{
    Process *prs = NULL;
    Operation *op = NULL;
    Machine *mch = NULL;
    prs = SearchProcessPlan(process, nProcess);
    prs->op = op;
    op = SearchOperation(op, nOperation);
    op->machine = mch;
    mch = SearchMachine(mch, nMachine);
    return mch;
}

#pragma region PP

/**
 * @brief Create a Process Plan object
 *
 * @param npp
 * @return * Process*
 */
Process *CreateProcessPlan(int npp)
{
    printf("MAlloc process plan--\n"); // Debug
    Process *aux = (Process *)calloc(1, sizeof(Process));
    // if (aux != NULL)
    //{
    aux->npp = npp;
    aux->next = NULL;
    printf("create pp %d %p", aux->npp, aux->next);
    // }
    return aux;
}

/**
 * @brief Junta o objeto á lista process
 *
 */
Process *InsertProcessPlan(Process *prsobj, Process *process)
{
    if (prsobj != NULL )
    {
        prsobj->op = NULL;
        prsobj->next = process;
        return (prsobj);
    }
    else
        return (process);
}

#pragma endregion

/**
 * @brief  Mostra todas as litas
 *
 * @param prs
 */
void Showlist(Process *prs)
{
    Process *auxPrs = prs;
    Operation *op = NULL;
    Machine *mch = NULL;
    printf("\nentrou showlist\n");
    while (auxPrs != NULL)
    {
        printf("\nNumber npp: %p %d %p\n", auxPrs, auxPrs->npp, auxPrs->next);
        op = auxPrs->op;
        while (op != NULL)
        {
            printf(" \n    Operation: %p %d %p\n", op, op->noperation, op->next);

            mch = op->machine;
            while (mch != NULL)
            {
                printf("       Machine: %d Time: %d\n", mch->pc, mch->time);
                mch = mch->next;
            }

            op = op->next;
        }

        auxPrs = auxPrs->next;
    }
}

int ShowOperation(Process *process, int prsSub, int opSub)
{

    Process *auxPrs = process;
    Operation *op = NULL;
    Machine *mch = NULL;
    printf("\nentrou showOperation\n");
    while (auxPrs != NULL)
    {
        if (prsSub == auxPrs->npp)
        {
            op = auxPrs->op;
            while (op != NULL)
            {
                if (opSub == op->noperation)
                {
                    mch = op->machine;
                    while (mch != NULL)
                    {
                        printf("       Machine: %d Time: %d\n", mch->pc, mch->time);
                        mch = mch->next;
                        return 1;
                    }
                }
                else
                {
                    return 0;
                }
                op = op->next;
            }
        }
        else
        {
            return 0;
        }
        auxPrs = auxPrs->next;
    }
}

#pragma region OP
/**
 * @brief Cria o obejeto operation
 *
 * @param nOp
 * @return Operation*
 */
Operation *CreateOperation(int nOp)
{

    printf("MAlloc operações inicio"); // Debug
    Operation *aux = (Operation *)calloc(1, sizeof(Operation));

    if (aux != NULL)
    {
        aux->noperation = nOp;
        aux->next = NULL;
        aux->machine = NULL;
        printf("create op %d %p", aux->noperation, aux->next);
    }
    return aux;
    ("MAlloc operações fim");
}
/**
 * @brief Insere o objeto no processo
 *
 * @param opobj
 * @param prs
 * @param nprocess
 * @return Process*
 */
Process *InsertOperationProcess(Operation *opobj, Process *prs, int nprocess)
{

    Process *auxPrs = prs;
    Operation *opaux = prs->op;

    printf("InsertOperation entrou"); // debug
    while (auxPrs != NULL)
    {

        if (nprocess = auxPrs->npp) // encontra o numero de processo igual
        {
            // dar next em op e adicionar o valor de op ao pp
            if (opobj != NULL)
            {
                Operation *aux = opaux;
                auxPrs->op = opobj;
                opobj->next = aux;
                return prs;
            }
        }
        auxPrs = auxPrs->next;
    }
}

void RemoveOperation(Process *prs, int prsSubs, int opSubs)
{

    Process *auxPrs = prs;
    Operation *op = NULL;
    Machine *mch = NULL;
    while (auxPrs != NULL)
    {
        printf("\n\n processo entrada %d", auxPrs->npp);
        if (prsSubs == auxPrs->npp)
        {
            op = auxPrs->op;
            Operation *nodoAtual = op, *nodoAnterior;
            printf("\n\n operacap entrada %d", op->noperation);
            if (op->noperation == opSubs)
            {
                printf("entrou if");
                op = nodoAtual->next;
                free(nodoAtual);
            }
            else
            {
                nodoAnterior = op;
                nodoAtual = nodoAnterior->next;
                while ((nodoAtual != NULL) && (nodoAtual->noperation != opSubs))
                {
                    nodoAnterior = nodoAtual;
                    nodoAtual = nodoAtual->next;
                }
                if (nodoAtual != NULL)
                {
                    nodoAnterior->next = nodoAtual->next;
                    free(nodoAtual);
                    Machine *mchRemove = nodoAtual->machine;
                    Machine *auxRemoveMachine;
                    while (mchRemove != NULL)
                    {
                        auxRemoveMachine = mchRemove;
                        mchRemove = mchRemove->next;
                        free(auxRemoveMachine);
                    }
                }
                // return (lista);
            }
            break;
        }
        auxPrs = auxPrs->next;
    }
}

void AlterarOperações(Process *prs, int prsSubs, int opSubs)
{
    Process *auxPrs = prs;
    Operation *op = NULL;
    Machine *mch = NULL;
    printf("\nentrou showlist\n");
    while (auxPrs != NULL)
    {
        op = auxPrs->op;
        while (op != NULL)
        {
            printf(" \n    Operation: %p %d %p\n", op, op->noperation, op->next);

            mch = op->machine;
            while (mch != NULL)
            {
                printf("       Machine: %d Time: %d\n", mch->pc, mch->time);
                mch = mch->next;
            }

            op = op->next;
        }

        auxPrs = auxPrs->next;
    }
}
#pragma endregion
#pragma region MCH

Machine *CreateMachine(int pc, int time)
{
    printf("MAlloc machine--\n"); // Debug
    Machine *aux = (Machine *)calloc(1, sizeof(Machine));

    aux->pc = pc;
    aux->time = time;
    aux->next = NULL;
    printf("create machine %d %d %p", aux->pc, aux->time, aux->next);
    return aux;
}

Process *InsertMachineOperationProcess(Process *prs, Machine *machine, int nop, int nprocess)
{
    Process *auxPrs = prs;
    Operation *opaux = prs->op;

    printf("InsertOperation entrou"); // debug
    while (auxPrs != NULL)
    {

        if (nprocess == auxPrs->npp) // encontra o numero de processo igual
        {
            // dar next em op e adicionar o valor de op ao pp

            while (opaux != NULL)
            {
                if (nop == opaux->noperation)
                {
                    if (machine != NULL)
                    {
                        machine->next = opaux->machine;

                        Machine *aux = opaux->machine;
                        opaux->machine = machine;
                        machine->next = aux;
                        return prs;
                    }
                }
                opaux = opaux->next;
            }
        }
        auxPrs = auxPrs->next;
    }
    // InsertMachine();
    printf("%p -----", auxPrs);
}
#pragma endregion
#pragma endregion