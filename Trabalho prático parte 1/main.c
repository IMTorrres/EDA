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
#include <time.h>

#define TAM 1000

int main()
{
	int opSub;
	int prsSub;
	int mchSub;
	int timeSub;
	//	Showlist(process);
	int option = 0;
	Process *process = NULL;
	ABP abp = NULL;
	do
	{
		int nprocess = 1;
		int nop = 3;
		int time = 5;
		int pc = 32;

		printf("\nInsira a opcao:\nOption:");
		scanf("%d", &option);
		switch (option)
		{
		case 300:
			process=ReadFile(process);
			Showlist(process); 
			break;
		case 1:
		
			/*process = ReadFile(process);*/
			// Lista ligada vazia
			process = InsertData(process);
			Showlist(process);
			break;
		case 2:
			printf("\nInsira o processo\nProcesso:");
			scanf("%d", &prsSub);

			printf("\nInsira a operação a remover\nOperação:");
			scanf("%d", &opSub);

			RemoveOperation(process, prsSub, opSub);
 //.....
			break;
		case 3: // Alterar
			int rtr = 0;

			printf("\nInsira o processo a alterar\nProcesso:");
			scanf("%d", &prsSub);

			printf("\nInsira a operação a alterar\nOperação:");
			scanf("%d", &opSub);

			rtr = Show(process, prsSub, opSub, 0, 0, 1);

			if (rtr == 0)
				printf("\nOpções inválida");

			printf("\nInsira a maquina a alterar\nOperação:");
			scanf("%d", &mchSub);

			printf("Novo numero de maquina:\nMaquina:");
			scanf("%d", &mchSub);
			printf("Novo tempo da maquina %d:\nMaquina:", mchSub);
			scanf("%d", &timeSub);
			Machine *objMchSubs = NULL;
			objMchSubs = ChangeOperation(process, prsSub, opSub, mchSub, timeSub, mchSub);

			break;
		case 4: // Media mais baixa
			int processMeanLow;
			printf("Insira o processo a calcular: ");
			scanf("%d", &processMeanLow);
			printf("\n A media mais baixa é: %.2f", MeanLow(process, processMeanLow));
			break;

		case 5: // Media mais baixa
			int processMeanHigh;
			printf("Insira o processo a calcular: ");
			scanf("%d", &processMeanHigh);
			printf("\n A media mais baixa é: %.2f", MeanHigh(process, processMeanHigh));
			break;
		case 6:
			int processMean;
			printf("Insira o processo a calcular: ");
			scanf("%d", &processMean);
			printf("\n A media do process é é: %.2f", MeanProcess(process, processMean));
			break;
		case 7:
			int operationMean;
			printf("Insira a operation a calcular: ");
			scanf("%d", &operationMean);

			printf("ola a s%p", process);
			printf("\n A da operation é: %.2f", MeanOperation(process, operationMean));
			break;
		case 8:
			int processSumLow;
			printf("Insira o processo a calcular: ");
			scanf("%d", &processSumLow);
			printf("\n Quantidade mínima de unidades de tempo : %d", SumLow(process, processSumLow));
			break;
		case 9:
			int processSumHigh;
			printf("Insira o processo a calcular: ");
			scanf("%d", &processSumHigh);
			printf("\n Quantidade maxima de unidades de tempo : %d", SumHigh(process, processSumHigh));
			break;
		case 10:
			Showlist(process);
			break;
		case 11:
			ShowAll(process, 1, 1, 0);
			break;
case 12:

break;
			case 13:
				 consultar(ABP abp, int valor);
		break;
		
		default:
			break;
		}
	} while (option != 0);
}
