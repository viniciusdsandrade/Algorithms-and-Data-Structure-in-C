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
            printf("Exercicio não encontrado\n");
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
    fclose(arq1); // Não esquecer de fechar o arquivo

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

    char texto[100];  // Tamanho arbitrário do array, ajuste conforme necessário

    // Lê o conteúdo atual do arquivo
    printf("Conteudo atual do arquivo:\n");
    while (fscanf(arq1, "%s", texto) != EOF) {
        printf("%s ", texto);
    }
    printf("\n");

    // Move o ponteiro para o início do arquivo para sobrescrever o conteúdo
    fseek(arq1, 0, SEEK_SET);

    printf("Digite o novo texto que deseja escrever no arquivo:\n");
    scanf("%s", texto);

    // Escreve o novo conteúdo no arquivo
    fprintf(arq1, "%s", texto);

    // Fecha o arquivo após a escrita
    fclose(arq1);

    // Abre o arquivo para leitura
    arq1 = fopen(caminho, "r");

    if (arq1 == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return -1;
    }

    // Lê e imprime os dados atualizados do arquivo
    printf("Conteúdo atualizado do arquivo:\n");
    while (fscanf(arq1, "%s", texto) != EOF) {
        printf("%s ", texto);
    }
    printf("\n");

    // Fecha o arquivo após a leitura
    fclose(arq1);

    return 0;
}
