#include <stdio.h>

int main(void) {
    FILE *arquivo;
    char nomeCidade[100];  // Tamanho arbitr�rio do array, ajuste conforme necess�rio
    int contador = 1;

    // Abre o arquivo para leitura
    arquivo = fopen("cidades.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return -1;
    }

    // L� e exibe as cidades do arquivo com n�meros relativos
    while (fgets(nomeCidade, sizeof(nomeCidade), arquivo) != NULL) {
        printf("%d - %s", contador, nomeCidade);
        contador++;
    }

    // Fecha o arquivo
    fclose(arquivo);

    return 0;
}
