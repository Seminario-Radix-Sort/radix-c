#include "radixSort.h"
#include "arquivos.h"

int main(){
    int tamanhos[4] = { 10000, 100000, 500000, 1000000 };
    // início da string que representa a tabela de saída dos tempos de execução do Radix Sort em C, em cada cenário
    char *tabelaSaida = (char *)malloc(1200 * sizeof(char));
    strcat(tabelaSaida, "Tamanho/Tipo,Aleatorio,Aleatorio-RangeMenor,Aleatorio-RangeMaior,Aleatorio-CEP,Aleatorio-Iguais,Aleatorio-Extremo,Crescente,Crescente-RangeMenor,Crescente-RangeMaior,Crescente-CEP,Crescente-Iguais,Crescente-Extremo,Decrescente,Decrescente-RangeMenor,Decrescente-RangeMaior,Decrescente-CEP,Decrescente-Iguais,Decrescente-Extremo\n");

    printf("Iniciando execucao do Radix Sort\n");
    
    controleRadixSort(tamanhos, tabelaSaida);
    
    char nomeArquivoSaida[50];
    sprintf(nomeArquivoSaida, "datasets/tempoExecucao-C");
    escritaArquivo(nomeArquivoSaida, tabelaSaida);
    
    printf("Execucao do Radix Sort finalizada\n");

    return 0;
}