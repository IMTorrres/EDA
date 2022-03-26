/**
 * @file main.c
 * @author GonçaloTorres (gon.im.torres@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-03-23
 *
 * @copyright Copyright (c) 2022
 * Professor:
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int main()
{
/*
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
			fscanf(fl, "%d;%[^;];%[^;]", &op, str, str1);
			printf("ola %d %s %s",op,str, str1);
			fclose(fl);

		}
*/
	int nprocess = 1;
	int nop = 33;
	int nop1 = 53;
	// Lista ligada vazia
	Process *process;
	Process *prs = CreateProcessPlan(nprocess);
	process = InsertProcessPlan(prs, process);

	Operation *operationobj = CreateOperation(nop);
	process = InsertOperationProcess(operationobj, process, nprocess);

	operationobj = CreateOperation(3);
	process = InsertOperationProcess(operationobj, process, nprocess);

	printf("Insira PP");
	printf("Insira Operation");
	printf("Insira Maquina");
	int processo = 1;
	int maquina = 1;
	int operacao = 1;
	int pc = 111;
	int time = 222;
	Machine *machineobj = CreateMachine(pc, time);
	process = InsertMachineOperationProcess(process, machineobj, nop, nprocess);
	Machine *machine = CreateMachine(12, 21);
	process = InsertMachineOperationProcess(process, machineobj, 3, nprocess);
	Showlist(process);
}