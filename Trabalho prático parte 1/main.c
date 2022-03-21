#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int main()
{
	int machArray[10] = {1, 3};
	int timehArray[10] = {4, 5};
	int noperation = 1;
	// Lista ligada vazia
	Process *process = NULL;
	process = MallocProcessPlan(process);
	process = InsertProcessPlan(process, 1);
	ShowList(process);

	Operation *operation = NULL;
	operation = MallocOperation(operation);
	operation = InsertOperation(operation, process, noperation);
	printf("Insira PP");
	printf("Insira Operation");
	printf("Insira Maquina");
	int processo = 1;
	int maquina = 1;
	int operacao = 1;
	int pc = 111;
	int time = 222;
	Machine *machine = NULL;
	machine = MallocMachine(machine);
	InsertMachine(process, processo, maquina, operacao, pc, time);
	ShowList(process);
}