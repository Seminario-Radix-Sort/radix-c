#include "arquivos.h"

void leituraArquivo(char *nomeArquivo, unsigned long long int *numeros) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        exit(1);
    }

    // ignora 2 linhas
    char c;
    int qtdLinhas = 0;
    while ((c = fgetc(arquivo))){
        if (c == '\n') {
            qtdLinhas++;
        }
        if (qtdLinhas == 2) {
            break;
        }
    }

    int i = 0;

    while (fscanf(arquivo, "%llu, ", &numeros[i]) != EOF) {
        i++;
    }

    fclose(arquivo);
}

void escritaArquivo(char *nomeArquivo, char *tabelaSaida) {
    time_t timer;
    char buffer[26];
    struct tm* tm_info;

    timer = time(NULL);
    tm_info = localtime(&timer);
    strftime(buffer, 26, "-%d-%m-%Y-%H-%M-%S", tm_info);
    
    strcat(nomeArquivo, buffer);
    strcat(nomeArquivo, ".csv");

    FILE *arquivo = fopen(nomeArquivo, "w");

    
    fprintf(arquivo, "Data e Hora de Geracao: %s\n", buffer);
    fprintf(arquivo, "Tempos em segundos:\n");
    fprintf(arquivo, "%s", tabelaSaida);

    fclose(arquivo);
}