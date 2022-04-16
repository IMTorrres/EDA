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

#pragma region Metodos
/**
 * @brief Insere os dados nas estruturas
 *
 * @param process
 * @return Process*
 */
Process *InsertData(Process *process)
{
    int nprocess = 1;
    int nop = 3;
    int time = 5;
    int pc = 32;
    Process *prs = CreateProcessPlan(nprocess);
    process = InsertProcessPlan(prs, process);
    /*
        Operation *operationobj = CreateOperation(nop);
        process = InsertOperationProcess(operationobj, process, nprocess);

        Machine *machineobj = CreateMachine(pc, time);
        process = InsertMachineOperationProcess(process, machineobj, nop, nprocess);*/

    Operation *operationobj = CreateOperation(01);
    process = InsertOperationProcess(operationobj, process, 1);
    operationobj = CreateOperation(02);
    process = InsertOperationProcess(operationobj, process, 1);
    operationobj = CreateOperation(03);
    process = InsertOperationProcess(operationobj, process, 1);
    operationobj = CreateOperation(04);
    process = InsertOperationProcess(operationobj, process, 1);

    Machine *machineobj = CreateMachine(1, 4);
    process = InsertMachineOperationProcess(process, machineobj, 1, nprocess);

    machineobj = CreateMachine(3, 5);
    process = InsertMachineOperationProcess(process, machineobj, 1, nprocess);
    /*
        machineobj = CreateMachine(2, 4);
        process = InsertMachineOperationProcess(process, machineobj, 2, nprocess);

        machineobj = CreateMachine(4, 5);
        process = InsertMachineOperationProcess(process, machineobj, 2, nprocess);

        machineobj = CreateMachine(2, 4);
        process = InsertMachineOperationProcess(process, machineobj, 2, nprocess);

        machineobj = CreateMachine(4, 5);
        process = InsertMachineOperationProcess(process, machineobj, 2, nprocess);
    */
    machineobj = CreateMachine(3, 5);
    process = InsertMachineOperationProcess(process, machineobj, 3, nprocess);

    machineobj = CreateMachine(5, 6);
    process = InsertMachineOperationProcess(process, machineobj, 3, nprocess);

    machineobj = CreateMachine(4, 5);
    process = InsertMachineOperationProcess(process, machineobj, 4, nprocess);

    machineobj = CreateMachine(5, 5);
    process = InsertMachineOperationProcess(process, machineobj, 4, nprocess);
    machineobj = CreateMachine(6, 4);
    process = InsertMachineOperationProcess(process, machineobj, 4, nprocess);

    machineobj = CreateMachine(7, 5);
    process = InsertMachineOperationProcess(process, machineobj, 4, nprocess);
    machineobj = CreateMachine(8, 9);
    process = InsertMachineOperationProcess(process, machineobj, 4, nprocess);
    return process;
}
/**
 * @brief Faz a leitura do ficheiro
 *
 * @param process
 * @return Process*
 */
Process *ReadFile(Process *process)
{

    FILE *fl = fopen("dados.txt", "rt");
    char str[50];
    char str1[50];
    int machine[10];
    int time[10];
    char *pch;

    int op;
    if (fl != NULL)

        if (!feof(fl))
        {
            fscanf(fl, "%d;%[^;];%[^;]\n", &op, str, str1);
            printf("%d %s %s", op, str, str1);
            fclose(fl);
        }
    pch = strtok(str, ",");
    while (pch != NULL)
    {
        printf("%s\n", pch);
        pch = strtok(NULL, ",");
    }

    return process;
}
/**
 * @brief Retorna o endereço de memoria do ProcessPlan
 *
 * @param prs
 * @param nProcess
 * @return Process*
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
/**
 * @brief Retorna o endereço de memoria de Operation
 *
 * @param op
 * @param nOperation
 * @return Operation*
 */
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
/**
 * @brief Retorna o endereço de memoria de Machine
 *
 * @param mch
 * @param nMachine
 * @return Machine*
 */
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
/**
 * @brief Altera os valores de machine
 *
 * @param process
 * @param nProcess
 * @param nOperation
 * @param nMachine
 * @return Machine*
 */
Machine *ChangeMachine(Process *process, int nProcess, int nOperation, int nMachine)
{
    Process *prs = NULL;
    Operation *op = NULL;
    Machine *mch = NULL;
    if (process != NULL)
    {
        prs = SearchProcessPlan(process, nProcess);
        op = prs->op;
        op = SearchOperation(op, nOperation);
        if (op != NULL)
        {
            mch = op->machine;
        }
        if (mch != NULL)
        {
            mch = SearchMachine(mch, nMachine);
        }
    }
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

    Process *aux = (Process *)calloc(1, sizeof(Process));
    if (aux != NULL)
    {
        aux->npp = npp;
        aux->next = NULL;
    }
    return aux;
}

/**
 * @brief Junta o objeto á lista process
 *
 */
Process *InsertProcessPlan(Process *prsobj, Process *process)
{
    if (prsobj != NULL)
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
 * @brief Mostra todas as litas
 *
 * @param prs
 * @return int
 */
int Showlist(Process *prs)
{
    Process *auxPrs = prs;
    Operation *op = NULL;
    Machine *mch = NULL;
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
    return 1;
}
/**
 * @brief Mostra todos os valores encolhendo process e operation
 *
 * @param process
 * @param prsSub
 * @param opSub
 * @return int
 */
int Show(Process *process, int prsSub, int opSub, int showPrs, int showOp, int showMachine)
{

    Process *auxPrs = process;
    Operation *op = NULL;
    Machine *mch = NULL;
    while (auxPrs != NULL)
    {
        if (showPrs = 1)
            printf("\nNumber npp: %p %d %p\n", auxPrs, auxPrs->npp, auxPrs->next);
        if (prsSub == auxPrs->npp)
        {
            op = auxPrs->op;
            while (op != NULL)
            {
                if (showOp == 1)
                    printf(" \n    Operation: %p %d %p\n", op, op->noperation, op->next);

                if (opSub == op->noperation)
                {
                    mch = op->machine;
                    while (mch != NULL)
                    {
                        if (showMachine == 1)
                            printf("       Machine: %d Time: %d\n", mch->pc, mch->time);
                        mch = mch->next;
                    }
                    return 1;
                }

                op = op->next;
            }
        }

        auxPrs = auxPrs->next;
    }
}

/**
 * @brief Mostra todos os valores encolhendo process e operation
 *
 * @param process
 * @param prsSub
 * @param opSub
 * @return int
 */
int ShowAll(Process *process, int showPrs, int showOp, int showMachine)
{

    Process *auxPrs = process;
    Operation *op = NULL;
    Machine *mch = NULL;
    while (auxPrs != NULL)
    {
        if (showPrs = 1)
            printf("\nNumber npp: %p %d %p\n", auxPrs, auxPrs->npp, auxPrs->next);
        if (showOp == 1)
        {
            op = auxPrs->op;
            while (op != NULL)
            {

                printf(" \n    Operation: %p %d %p\n", op, op->noperation, op->next);
                if (showMachine == 1)
                {
                    mch = op->machine;
                    while (mch != NULL)
                    {

                        printf("       Machine: %d Time: %d\n", mch->pc, mch->time);
                        mch = mch->next;
                    }
                    return 1;
                }
                op = op->next;
            }
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

    Operation *aux = (Operation *)calloc(1, sizeof(Operation));

    if (aux != NULL)
    {
        aux->noperation = nOp;
        aux->next = NULL;
        aux->machine = NULL;
    }
    return aux;
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
/**
 * @brief Romove uma operation de um process
 *
 * @param prs
 * @param prsSubs
 * @param opSubs
 */
Process *RemoveOperation(Process *prs, int prsSubs, int opSubs)
{ /*
     Operation *Op = lista->op;

     Operation *nodoAtual = Op, *nodoAnterior;
     if (Op->noperation == opSubs)
     {
         Op = nodoAtual->next;
         free(nodoAtual);
     }
     else
     {
         nodoAnterior = Op;
         nodoAtual = nodoAnterior->next;
         while ((nodoAtual != NULL) && (Op->noperation == opSubs))
         {
             nodoAnterior = nodoAtual;
             nodoAtual = nodoAtual->next;
         }
         if (nodoAtual != NULL)
         {
             nodoAnterior->next = nodoAtual->next;
             free(nodoAtual);
         }
     }
 */

    Process *auxPrs = prs;
    Operation *Op = NULL;
    Machine *Mch = NULL;
    Operation *auxRemoveOp = NULL;
    Machine *auxRemoveMch = NULL;
    if (auxPrs != NULL)
    { // apaga nodod
        Op = auxPrs->op;
        Op = SearchOperation(Op, opSubs);
        // apaga lista completa
        /* Mch = Op->machine;
         while (Mch != NULL)
         {
             auxRemoveMch = Mch;
             Mch = Mch->next;
             free(auxRemoveMch);
         }///////////*/
        // Op->machine = NULL;
        Operation *nodoAtual = Op, *nodoAnterior;
        if (nodoAtual->noperation == opSubs)
        {
            Op = nodoAtual->next;
            prs->op = Op;
            free(nodoAtual);
        }
        else
        {
            nodoAnterior = Op;
            nodoAtual = nodoAnterior->next;
            while ((nodoAtual != NULL) && (nodoAtual->noperation == opSubs))
            {
                nodoAnterior = nodoAtual;
                nodoAtual = nodoAtual->next;
            }
            if (nodoAtual != NULL)
            {
                nodoAnterior->next = nodoAtual->next;
                free(nodoAtual);
            }
        }
        return prs;
    }
}

#pragma endregion
#pragma region MCH

Machine *CreateMachine(int pc, int time)
{
    Machine *aux = (Machine *)calloc(1, sizeof(Machine));

    aux->pc = pc;
    aux->time = time;
    aux->next = NULL;
    return aux;
}

Process *InsertMachineOperationProcess(Process *prs, Machine *machine, int nop, int nprocess)
{
    printf("\n----ISP %p %p %d %d \n", prs, machine, nop, nprocess);
    Process *auxPrs = prs;

    while (auxPrs != NULL)
    {
        if (nprocess == auxPrs->npp) // encontra o numero de processo igual
        {
            // dar next em op e adicionar o valor de op ao pp
            Operation *opaux = prs->op;
            while (opaux != NULL)
            {
                if (nop == opaux->noperation)
                {
                    printf("machine %p", machine);
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
    return prs;
}
#pragma endregion

float MeanLow(Process *process, int processMeanLow)
{
    Process *prs = NULL;
    Operation *op = NULL;
    Machine *mch = NULL;
    float sum = 0;
    int count = 0;
    int lowTime;
    if (process != NULL)
    {
        prs = SearchProcessPlan(process, processMeanLow);
        op = prs->op;
        while (op != NULL)
        {
            mch = op->machine;
            lowTime = mch->time;
            while (mch != NULL)
            {
                if (mch->time < lowTime)
                {
                    lowTime = mch->time;
                }
                mch = mch->next;
            }
            sum = sum + lowTime;
            count++;
            op = op->next;
        }
    }

    return (sum / count);
}
/**
 * @brief Media de todos os tempos mais altos de um dado process
 *
 * @param process
 * @param processMeanHigh
 * @return float
 */
float MeanHigh(Process *process, int processMeanHigh)
{
    Process *prs = NULL;
    Operation *op = NULL;
    Machine *mch = NULL;
    float sum = 0;
    float mean = 0;
    int count = 0;
    int highTime;
    if (process != NULL)
    {
        prs = SearchProcessPlan(process, processMeanHigh);
        op = prs->op;
        while (op != NULL)
        {
            mch = op->machine;
            highTime = 0;
            while (mch != NULL)
            {
                if (mch->time > highTime)
                {
                    highTime = mch->time;
                }
                mch = mch->next;
            }
            sum = sum + highTime;
            count++;
            op = op->next;
        }
    }
    mean = sum / count;
    return mean;
}

/**
 * @brief Determinação da quantidade média de unidades de tempo necessárias para completar uma operation,
considerando todas as alternativas possíveis
 *
 * @param process
 * @param operationMean
 * @return float
 */
float MeanOperation(Process *process, int operationMean)
{
    Process *prs = process;
    Operation *op = NULL;
    Machine *mch = NULL;
    float sum = 0;
    float mean = 0;
    int count = 0;
    int time;

    if (process != NULL)
    {
        op = prs->op;
        while (op != NULL)
        {
            if (op->noperation == operationMean)
            {
                mch = op->machine;
                while (mch != NULL)
                {
                    sum = sum + mch->time;
                    count++;

                    mch = mch->next;
                }
            }
            op = op->next;
        }
    }
    printf("mean %f", mean);

    return (sum / count);
}

/**
 * @brief Determinação da quantidade média de unidades de tempo necessárias para completar uma processo,
considerando todas as alternativas possíveis
 *
 * @param process
 * @param processMean
 * @return float
 */
float MeanProcess(Process *process, int processMean)
{
    Process *prs = NULL;
    Operation *op = NULL;
    Machine *mch = NULL;
    float sum = 0;
    float mean = 0;
    int count = 0;
    int time;
    if (process != NULL)
    {
        prs = SearchProcessPlan(process, processMean);
        op = prs->op;
        while (op != NULL)
        {
            mch = op->machine;
            time = 0;
            while (mch != NULL)
            {
                time = mch->time;
                sum = sum + time;
                count++;
                mch = mch->next;
            }

            op = op->next;
        }
    }
    return (sum / count);
}

/**
 * @brief Determina da quantidade mínima de unidades de tempo necessárias para completar o process e listagem das
respetivas operations
 *
 * @param process
 * @param processSumLow
 * @return int
 */
int SumLow(Process *process, int processSumLow)
{
    Process *prs = NULL;
    Operation *op = NULL;
    Machine *mch = NULL;
    int lowTime;
    int sum = 0;
    if (process != NULL)
    {

        prs = SearchProcessPlan(process, processSumLow);
        op = prs->op;
        Show(process, prs->npp, op->noperation, 0, 1, 1);
        while (op != NULL)
        {
            mch = op->machine;
            lowTime = mch->time;
            while (mch != NULL)
            {
                if (mch->time < lowTime)
                {
                    lowTime = mch->time;
                }
                mch = mch->next;
            }
            sum = sum + lowTime;
            op = op->next;
        }
    }

    return sum;
}
/**
 * @brief Determina da quantidade maxima de unidades de tempo necessárias para completar o process e listagem das
respetivas operations
 *
 * @param process
 * @param processMeanHigh
 * @return int
 */
int SumHigh(Process *process, int processMeanHigh)
{
    Process *prs = NULL;
    Operation *op = NULL;
    Machine *mch = NULL;
    int sum = 0;
    float mean = 0;
    int count = 0;
    int highTime;
    if (process != NULL)
    {
        prs = SearchProcessPlan(process, processMeanHigh);
        op = prs->op;
        while (op != NULL)
        {
            mch = op->machine;
            highTime = 0;
            while (mch != NULL)
            {
                if (mch->time > highTime)
                {
                    highTime = mch->time;
                }
                mch = mch->next;
            }
            sum = sum + highTime;
            op = op->next;
        }
    }
    return sum;
}
#pragma endregion