#include <iostream>
#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#include "locale.h"
#define tamanho 5000

/*Para testes
for (i = 0; i < tamanho; i++)
{
	printf("%d \n", num[i]);
}*/
//Declaração de variaveis 
clock_t t, t2;
int num[tamanho], cmp, j, i, min, x, k;
//Método de inserção
void insercao( int num[tamanho])
{
	t = clock();
	for (j = 1; j< tamanho; j++)
	{
		min = num[j];
		i = j - 1;
		while (i >= 0 && num[i]>min)
		{
			num[i + 1] = num[i];
			i = i - 1;
		}
		num[i + 1] = min;
	}
	t = clock() - t;
	printf("Tempo para o método de INSERÇÃO		é	%f segundos.\n", ((float)t) / CLOCKS_PER_SEC);
}
//Método de bolha
void bolha(int num[tamanho])
{
	t = clock();
	for (i = 0; i < tamanho; i++)
	{
		for (j = 0; j < tamanho; j++)
		{
			if (num[j] > num[j + 1])
			{
				cmp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = cmp;
			}
		}
	}
	t = clock() - t;
	printf("Tempo para o método de BOLHA		é	%f segundos.\n", ((float)t) / CLOCKS_PER_SEC);
}
//método de seleção
void selecao(int num[tamanho])
{
	t = clock();
	for (i = 0; i < tamanho - 1; i++)
	{
		min = i;
		for (j = (i + 1); j < tamanho; j++)
		{
			if (num[j] < num[min])
			{
				min = j;
			}
		}
		if (i != min)
		{
			cmp = num[i];
			num[i] = num[min];
			num[min] = cmp;
		}
	}
	t = clock() - t;
	printf("Tempo para o método de SELEÇÃO		é	%f segundos.\n", ((float)t) / CLOCKS_PER_SEC);
}
// método shellsort
void shellsort(int num[tamanho])
{
	t = clock();
	do {
		k = 3 * k + 1;
	} while (k < tamanho);
	do {
		k /= 3;
		for (i = k; i < tamanho; i++) {
			cmp = num[i];
			j = i - k;
			while (j >= 0 && cmp < num[j]) {
				num[j + k] = num[j]; 
				j -= k; 
			}
			num[j + k] = cmp;
		}
	} while (k > 1);
	t = clock() - t;
	printf("Tempo para o método de SHELLSORT	é	%f segundos.\n", ((float)t) / CLOCKS_PER_SEC); 
}
void desconhecido(int num[tamanho])
{
	t = clock();
	for (i = 0; i < tamanho; i++)
	{
		for (j = i; j < tamanho; j++)
		{
			if (num[j] < num[i])
			{
				cmp = num[j];
				num[j] = num[i];
				num[i] = cmp;
			}
		}
	}
	t = clock() - t;
	printf("Tempo para o método DESCONHECIDO	é	%f segundos.\n", ((float)t) / CLOCKS_PER_SEC);
}
//Ordenando vetor aleatorio
void aleatorio()
{
	for (i = 0; i < tamanho; i++)
	{
		num[i] = rand() % tamanho;
	}
	insercao(num);
	bolha(num);
	selecao(num);
	shellsort(num);
	desconhecido(num);
}	
//Ordenando vetor em ordem crescente
void ordemcrescente()
{	
	for (i = 0; i < tamanho; i++)
	{
		num[i] = rand() % tamanho;
	}
	for (j = 1; j< tamanho; j++)
	{
		min = num[j];
		i = j - 1;
		while (i >= 0 && num[i]>min)
		{
			num[i + 1] = num[i];
			i = i - 1;
		}
		num[i + 1] = min;
	}
	insercao(num);
	bolha(num);
	selecao(num);
	shellsort(num);
	desconhecido(num);
}	
//Ordenando vetor em ordem decrescente
void ordemdecrescente()
{	
	for (i = 0; i < tamanho; i++)
	{
		num[i] = rand() % tamanho;
	}
	for (i = 0; i < tamanho; i++)
	{
		for (j = i; j < tamanho; j++)
		{
			if (num[j] > num[i])
			{
				cmp = num[j];
				num[j] = num[i];
				num[i] = cmp;
			}
		}
	}
	insercao(num);
	bolha(num);
	selecao(num);
	shellsort(num);
	desconhecido(num);
}	
// menu
int main ()
{
	setlocale(LC_ALL, "Portuguese");
	int opcao;
	do 
	{
		printf("\n\nTempo para ordenar um vetor:\n");
		printf("	0-Sair\n");
		printf("	1-Ordem crescente\n");
		printf("	2-Ordem descrescente\n");
		printf("	3-Aleatório\n");
		printf("Opção: ");
		scanf("%d", &opcao);	
		switch (opcao)
		{
		case 0:
			printf("SAINDO\n\n");
			break;
		case 1:
			ordemcrescente();
			break;
		case 2:
			ordemdecrescente();
			break;	
		case 3:
			aleatorio();
			break;
		default:
			printf("Opção Invalida");
			break;
		}
	} while (opcao != 0);
	system("pause");
	return 0;
}
