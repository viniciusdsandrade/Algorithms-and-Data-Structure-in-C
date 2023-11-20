#include <stdio.h>

/*
 * 1 - Como abir, ler e printar dados de um arquivo txt?
 * 2 - Como abrir, escrever e printar dados de um arquivo txt?
 */

int exercise01(void);

int exercise02(void);

int main(void) {
    printf("Qual exercicios vc quer executar?\n");
    printf("1 - Como abir, ler e printar dados de um arquivo txt?\n");
    printf("2 - Como abrir, escrever e printar dados de um arquivo txt?\n");


    int exercicio;
    scanf("%d", &exercicio);

    switch (exercicio) {
        case 1:
            exercise01();
            break;
        case 2:
            exercise02();
            break;
        default:
            printf("Exercicio n�o encontrado\n");
            break;
    }
}


int exercise01(void) {

    FILE *arq1;
    char aux;

    const char *caminho = "C:\\Users\\Pichau\\Desktop\\CStudy\\c-algorithms\\challanges-c\\2_lp\\p2-lp\\teste-11.txt";

    arq1 = fopen(caminho, "r");
    if (arq1 == NULL) {
        printf("Error opening file!\n");
        return -1;
    } else {
        while (fscanf(arq1, "%c", &aux) != EOF) {
            printf("%c", aux);
        }
    }
    fclose(arq1); // N�o esquecer de fechar o arquivo

    return 0;
}

int exercise02(void) {
    /* 2 - Como abrir, escrever e printar dados de um arquivo txt? */
    FILE *arq1;
    const char *caminho = "C:\\Users\\Pichau\\Desktop\\CStudy\\c-algorithms\\challanges-c\\2_lp\\p2-lp\\teste-11.txt";

    // Abre o arquivo para leitura e escrita
    arq1 = fopen(caminho, "w+");

    if (arq1 == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return -1;
    }

    char texto[100];  // Tamanho arbitr�rio do array, ajuste conforme necess�rio

    // L� o conte�do atual do arquivo
    printf("Conteudo atual do arquivo:\n");
    while (fscanf(arq1, "%s", texto) != EOF) {
        printf("%s ", texto);
    }
    printf("\n");

    // Move o ponteiro para o in�cio do arquivo para sobrescrever o conte�do
    fseek(arq1, 0, SEEK_SET);

    printf("Digite o novo texto que deseja escrever no arquivo:\n");
    scanf("%s", texto);

    // Escreve o novo conte�do no arquivo
    fprintf(arq1, "%s", texto);

    // Fecha o arquivo ap�s a escrita
    fclose(arq1);

    // Abre o arquivo para leitura
    arq1 = fopen(caminho, "r");

    if (arq1 == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return -1;
    }

    // L� e imprime os dados atualizados do arquivo
    printf("Conte�do atualizado do arquivo:\n");
    while (fscanf(arq1, "%s", texto) != EOF) {
        printf("%s ", texto);
    }
    printf("\n");

    // Fecha o arquivo ap�s a leitura
    fclose(arq1);

    return 0;
}
