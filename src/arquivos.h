#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void leituraArquivo(char *nomeArquivo, unsigned long long int *numeros);
void escritaArquivo(char *nomeArquivo, char *tabelaSaida);

#endif