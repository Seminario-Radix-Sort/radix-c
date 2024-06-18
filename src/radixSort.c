#include "radixSort.h"

unsigned long long int achaMaior(unsigned long long int *vetor, int tamanho) {
    unsigned long long int maior = vetor[0];
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
    }
    return maior;
}

void countingSort(unsigned long long int *vetor, int tamanho, unsigned long long int exp) {
    unsigned long long int saida[tamanho];
    int i, contagem[10] = {0};

    for (i = 0; i < tamanho; i++) {
        contagem[(vetor[i] / exp) % 10]++;
    }

    for (i = 1; i < 10; i++) {
        contagem[i] += contagem[i - 1];
    }

    for (i = tamanho - 1; i >= 0; i--) {
        saida[contagem[(vetor[i] / exp) % 10] - 1] = vetor[i];
        contagem[(vetor[i] / exp) % 10]--;
    }

    for (i = 0; i < tamanho; i++) {
        vetor[i] = saida[i];
    }
}

void radixSort(unsigned long long int *vetor, int tamanho) {
    unsigned long long int maior = achaMaior(vetor, tamanho);
    unsigned long long int exp = 1;

    while (maior / exp > 0) {        
        countingSort(vetor, tamanho, exp);
        exp *= 10;
    }
}

void controleRadixSort(int *tamanhos, char *tabelaSaida) {
    unsigned long long int *vetor;
    float somaTempo = 0;
    for(int i = 0; i < 4; i++){
        char tamanhoString[10];
        sprintf(tamanhoString, "%d,", tamanhos[i]); 
        strcat(tabelaSaida, tamanhoString);
        for(int j = 0; j < 3; j++){
            char nomeArquivo[150];
            sprintf(nomeArquivo, "datasets/");
            char nomeOrdem[25], dirOrdem[15];
            sprintf(dirOrdem, j == 0 ? "aleatorios/" : j == 1 ? "crescentes/" : "decrescentes/");
            sprintf(nomeOrdem, j == 0 ? "%dAleatorio" : j == 1 ? "%dCrescente" : "%dDecrescente", tamanhos[i]);
            strcat(nomeArquivo, dirOrdem);
            strcat(nomeArquivo, nomeOrdem);
            for(int k = 0; k < 6; k++){
                vetor = (unsigned long long int *)malloc(tamanhos[i] * sizeof(unsigned long long int));
                char nomeTipo[15];
                sprintf(nomeTipo, k == 0 ? "" : k == 1 ? "-RangeMenor" : k == 2 ? "-RangeMaior" : k == 3 ? "-CEP" : k == 4 ? "-Iguais" : "-Extremo");
                strcat(nomeArquivo, nomeTipo);
                strcat(nomeArquivo, ".txt");
                leituraArquivo(nomeArquivo, vetor);
                float mediaTempo = 0;
                for(int l = 0; l < 10; l++){
                    clock_t inicio = clock();
                    radixSort(vetor, tamanhos[i]);
                    clock_t fim = clock();
                    mediaTempo += (float)(fim - inicio) / CLOCKS_PER_SEC;
                    somaTempo += (float)(fim - inicio) / CLOCKS_PER_SEC;
                }
                mediaTempo /= 10;
                char mediaTempoString[11];
                sprintf(mediaTempoString, "%f,", mediaTempo);
                strcat(tabelaSaida, mediaTempoString);
                sprintf(nomeArquivo, "datasets/");
                strcat(nomeArquivo, dirOrdem);
                strcat(nomeArquivo, nomeOrdem);
                free(vetor);
            }
            sprintf(nomeArquivo, "datasets/");
        }
        strcat(tabelaSaida, "\n");
    }
    strcat(tabelaSaida, "Tempo Total,");
    char somaTempoString[11];
    sprintf(somaTempoString, "%f\n", somaTempo);
    strcat(tabelaSaida, somaTempoString);
    strcat(tabelaSaida, "Tempo Medio Total,");
    sprintf(somaTempoString, "%f", (somaTempo / 720));
    strcat(tabelaSaida, somaTempoString);
}
    