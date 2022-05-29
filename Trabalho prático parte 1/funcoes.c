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
#define TAM 1000

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
        Operation *operationObj = CreateOperation(nop);
        process = InsertOperationProcess(operationObj, process, nprocess);

        Machine *machineObj = CreateMachine(pc, time);
        process = InsertMachineOperationProcess(process, machineObj, nop, nprocess);*/

    Operation *operationObj = CreateOperation(1);
    process = InsertOperationProcess(operationObj, process, 1);
    operationObj = CreateOperation(2);
    process = InsertOperationProcess(operationObj, process, 1);
    operationObj = CreateOperation(3);
    process = InsertOperationProcess(operationObj, process, 1);
    operationObj = CreateOperation(4);
    process = InsertOperationProcess(operationObj, process, 1);

    Machine *machineObj = CreateMachine(1, 4);
    process = InsertMachineOperationProcess(process, machineObj, 1, nprocess);

    machineObj = CreateMachine(3, 5);
    process = InsertMachineOperationProcess(process, machineObj, 1, nprocess);

    machineObj = CreateMachine(2, 4);
    process = InsertMachineOperationProcess(process, machineObj, 2, nprocess);

    machineObj = CreateMachine(4, 5);
    process = InsertMachineOperationProcess(process, machineObj, 2, nprocess);

    machineObj = CreateMachine(2, 4);
    process = InsertMachineOperationProcess(process, machineObj, 2, nprocess);

    machineObj = CreateMachine(4, 5);
    process = InsertMachineOperationProcess(process, machineObj, 2, nprocess);

    machineObj = CreateMachine(3, 5);
    process = InsertMachineOperationProcess(process, machineObj, 3, nprocess);

    machineObj = CreateMachine(5, 6);
    process = InsertMachineOperationProcess(process, machineObj, 3, nprocess);

    machineObj = CreateMachine(4, 5);
    process = InsertMachineOperationProcess(process, machineObj, 4, nprocess);

    machineObj = CreateMachine(5, 5);
    process = InsertMachineOperationProcess(process, machineObj, 4, nprocess);
    machineObj = CreateMachine(6, 4);
    process = InsertMachineOperationProcess(process, machineObj, 4, nprocess);

    machineObj = CreateMachine(7, 5);
    process = InsertMachineOperationProcess(process, machineObj, 4, nprocess);
    machineObj = CreateMachine(8, 9);
    process = InsertMachineOperationProcess(process, machineObj, 4, nprocess);
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
    Process *prs = CreateProcessPlan(1);
    process = InsertProcessPlan(prs, process);
    Operation *operationObj = NULL;
    Machine *machineObj = NULL;
    {
        FILE *fp = fopen("dados.txt", "rt");
        int op;
        char str[50];
        char *pch;
        int mch[TAM];
        int time[TAM];
        int i = 0;
        int t = 0;

        if (fp != NULL)
            while (!feof(fp))
            {
                fscanf(fp, "%d\n", &op);
                i = 0;
                t = 0;

                operationObj = CreateOperation(op);
                process = InsertOperationProcess(operationObj, process, op);
                fscanf(fp, "%s\n", str);
                pch = strtok(str, "[,]");
                while (pch != NULL)
                {

                    mch[i] = atoi(pch);
                    pch = strtok(NULL, "[,]");
                    i++;
                }

                fscanf(fp, "%s\n", str);

                pch = strtok(str, "(,)");
                while (pch != NULL)
                {

                    time[t] = atoi(pch);
                    pch = strtok(NULL, "(,)");
                    t++;
                }
                for (int z = 0; z < i; z++)
                {
                    machineObj = NULL;
                    machineObj = CreateMachine(mch[z], time[z]);
                    process = InsertMachineOperationProcess(process, machineObj, op, 1);
                }
            }
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
    return NULL;
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
Machine *ChangeOperation(Process *process, int nProcess, int nOperation, int nMachine, int newTime, int newPc)
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
    mch->pc = newPc;
    mch->time = newTime;
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
Process *InsertProcessPlan(Process *prsObj, Process *process)
{
    if (prsObj != NULL)
    {
        prsObj->op = NULL;
        prsObj->next = process;
        return (prsObj);
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
    return prs;
}

/**
 * @brief Romove uma operation de um process
 *
 * @param prs
 * @param prsSubs
 * @param opSubs
 */
Process *RemoveOperation(Process *prs, int prsSubs, int opSubs)
{
    Operation *op = NULL;

    //.....
    op = prs->op;
    Operation *nodoAtual = op, *nodoAnterior;
    if (nodoAtual->noperation == opSubs)
    {
        op = nodoAtual->next;

        free(nodoAtual);
    }
    else
    {
        nodoAnterior = op;
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
    prs->op = op;
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
    Process *auxPrs = prs;
    auxPrs = SearchProcessPlan(prs, nprocess);

    Operation *opaux = auxPrs->op;
    opaux = SearchOperation(opaux, nop);

    if (machine != NULL)
    {
        // machine->next = opaux->machine;

        Machine *aux = opaux->machine;
        opaux->machine = machine;
        machine->next = aux;
        return prs;
    }

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

Job CreateNodoBtree(Job jobs, int processId) // entra aqui apos ter recebido o op
{
    /// Job novo;
    Process *prs = CreateProcessPlan(processId);
    if (jobs == NULL)
    {

        Job novo = (Job)calloc(1, sizeof(Job));
        if (novo != NULL)
        {
            novo->prs = prs;
            novo->right = NULL;
            novo->left = NULL;

            return (novo);
        }
        else
            return (jobs);

    } // printf( "\n ola %d",i);//printf( "\nola %d",jobs->prs->op->noperation);
    else if (processId < jobs->prs->npp)
    {
        jobs->right = CreateNodoBtree(jobs->right, processId);
        return (jobs);
    }
    else
    {
        jobs->left = CreateNodoBtree(jobs->left, processId);
        return (jobs);
    }
}

Job InserNewDataTree(Job jobs, int processId, int operationId, int machineId, int timeMachine)
{

    Operation *op = CreateOperation(operationId);
    Machine *mch = CreateMachine(machineId, timeMachine);

    Job jobAux = SerchJob(jobs, processId);

    if (jobAux == NULL)
    {
        jobs = CreateNodoBtree(jobs, processId);
        jobAux = SerchJob(jobs, processId);
        jobAux->prs->op = op;
        ;
        jobAux->prs->op->machine = mch;
    }
    else
    {

        Operation *opVerific = SearchOperation(jobAux->prs->op, operationId);
        if (opVerific == NULL)
        {
            InsertOperationProcess(op, jobAux->prs, operationId);
            InsertMachineOperationProcess(jobAux->prs, mch, operationId, processId);
        }
        else
        {
            if (SearchMachine(opVerific->machine, machineId) == NULL)
            {
                InsertMachineOperationProcess(jobAux->prs, mch, operationId, processId);
            }
        }
    }

    return jobs;
} /*
 Job InserNewDataTree(Job jobs, int processId, int operationId, int machineId, int timeMachine)
 {

     Operation *op = CreateOperation(operationId);
     Machine *mch = CreateMachine(machineId, timeMachine);

     Job jobAux = SerchJob(jobs, processId);

     if (jobAux == NULL)
     {
         jobs = CreateNodoBtree(jobs, processId);
         jobs->prs->op = op;
         jobs->prs->op->machine = mch;
     }
     else
     {
         Operation *opVerific = SearchOperation(jobAux->prs->op, operationId);
         if (opVerific != NULL)
         {
             InsertMachineOperationProcess(jobAux->prs, mch, operationId, processId);
         }
         else
         {
             InsertOperationProcess(op, jobs->prs, processId);
         }
         printf("operationId %d", operationId);
     }

     return jobs;
 }*/

void preorder(Job jobs)
{
    if (jobs != NULL)
    {
        printf("\n\n\n\nProcess%d", jobs->prs->npp);
        Operation *opAux = jobs->prs->op;
        while (opAux != NULL)
        {
            printf("\n Operacao:%d", opAux->noperation);
            Machine *mchAux = opAux->machine;
            while (mchAux != NULL)
            {
                printf("\n    Machine:%d", mchAux->pc);
                printf("\n   Time:%d", mchAux->time);
                mchAux = mchAux->next;
            }
            opAux = opAux->next;
        }

        preorder(jobs->right);
        preorder(jobs->left);
    }
}
int altura(Job jobs)
{
    int altEsq, altDir;
    if (jobs == NULL)
        return (0);
    else
    {
        altEsq = altura(jobs->right);
        altDir = altura(jobs->left);
        if (altEsq > altDir)
            return (altEsq + 1);
        else
            return (altDir + 1);
    }
}

// Consulta do endereço de memória
Job SerchJob(Job jobs, int prs)
{
    while (jobs != NULL)
    {
        if (jobs->prs->npp == prs)
            return (jobs);
        else if (jobs->prs->npp < prs)
            jobs = jobs->left;
        else
            jobs = jobs->right;
    }
    return (NULL);
}

Job ReadFileBtree(Job jobs)
{
    Process *processObj = NULL;
    Process *process = NULL;
    Operation *operationObj = NULL;
    Machine *machineObj = NULL;
    {
        FILE *fp = fopen("btree.txt", "rt");
        int opFile;
        int prsFile;
        char str[50];
        char *pch;
        int mch[TAM];
        int time[TAM];
        int i = 0;
        int t = 0;

        if (fp != NULL)
            while (!feof(fp))
            {
                fscanf(fp, "%d\n", &prsFile);
                processObj = CreateProcessPlan(prsFile);
                process = InsertProcessPlan(processObj, process);
                fscanf(fp, "%d\n", &opFile);
                i = 0;
                t = 0;

                operationObj = CreateOperation(opFile);
                process = InsertOperationProcess(operationObj, process, opFile);
                fscanf(fp, "%s\n", str);
                pch = strtok(str, "[,]");
                while (pch != NULL)
                {

                    mch[i] = atoi(pch);
                    pch = strtok(NULL, "[,]");
                    i++;
                }

                fscanf(fp, "%s\n", str);

                pch = strtok(str, "(,)");
                while (pch != NULL)
                {

                    time[t] = atoi(pch);
                    pch = strtok(NULL, "(,)");
                    t++;
                }
                for (int z = 0; z < i; z++)
                {
                    machineObj = NULL;
                    machineObj = CreateMachine(mch[z], time[z]);
                    // process = InsertMachineOperationProcess(process, machineObj, opFile, prsFile);
                    jobs = InserNewDataTree(jobs, prsFile, opFile, mch[z], time[z]);
                }
            }
    }
    return jobs;
}

FILE *PreOrderjob(Job jobs, FILE *fpwrite)
{

    if (jobs != NULL)
    {
        Operation *opAux = jobs->prs->op;
        while (opAux != NULL)
        {
            fprintf(fpwrite, "%d\n", jobs->prs->npp);
            fprintf(fpwrite, "%d\n", opAux->noperation);
            Machine *mchAux = opAux->machine;
            fprintf(fpwrite, "[");
            while (mchAux != NULL)
            {
                fprintf(fpwrite, "%d", mchAux->pc);
                mchAux = mchAux->next;
                if (mchAux != NULL)
                    fprintf(fpwrite, ",");
            }
            fprintf(fpwrite, "]\n");

            mchAux = opAux->machine;
            fprintf(fpwrite, "(");
            while (mchAux != NULL)
            {
                fprintf(fpwrite, "%d", mchAux->time);
                mchAux = mchAux->next;
                if (mchAux != NULL)
                    fprintf(fpwrite, ",");
            }
            fprintf(fpwrite, ")\n");

            opAux = opAux->next;
        }

        PreOrderjob(jobs->right, fpwrite);
        PreOrderjob(jobs->left, fpwrite);
    }
    return fpwrite;
}

Job WriteFileBtree(Job jobs)
{

    {
        FILE *fpwrite = fopen("btreewrite.txt", "w");
        int opFile;
        int prsFile;
        char str[50];
        char *pch;
        int mch[TAM];
        int time[TAM];
        int i = 0;
        int t = 0;
        while (!feof(fpwrite))
        {
            printf("ASDASD");
            fpwrite = PreOrderjob(jobs, fpwrite);
            fclose(fpwrite);
        }
    }
    return jobs;
}

Job EditJob(Job jobs,int process, int operation,int machine, int time,int machineWantSub)
{
    Job jobAux=NULL;
    jobAux=SerchJob(jobs,process);

Operation *opObj=SearchOperation(jobAux->prs->op,operation);
Machine *machineObj=SearchMachine(opObj->machine,machineWantSub);
machineObj->pc=machine;
machineObj->time=time;

}
 