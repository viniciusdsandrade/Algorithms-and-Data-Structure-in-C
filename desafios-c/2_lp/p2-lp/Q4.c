#include <stdio.h>

int main(void) {
    FILE *arquivo;
    char nomeCidade[100];  // Tamanho arbitrário do array, ajuste conforme necessário
    int contador = 1;

    // Abre o arquivo para leitura
    arquivo = fopen("cidades.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return -1;
    }

    // Lê e exibe as cidades do arquivo com números relativos
    while (fgets(nomeCidade, sizeof(nomeCidade), arquivo) != NULL) {
        printf("%d - %s", contador, nomeCidade);
        contador++;
    }

    // Fecha o arquivo
    fclose(arquivo);

    return 0;
}
