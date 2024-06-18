#ifndef RADIXSORT_H
#define RADIXSORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "arquivos.h"

unsigned long long int achaMaior(unsigned long long int *vetor, int tamanho);
void radixSort(unsigned long long int *vetor, int tamanho);
void countingSort(unsigned long long int *vetor, int tamanho, unsigned long long int exp);
void controleRadixSort(int *tamanhos, char *tabelaSaida);

#endif