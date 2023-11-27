#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "global.h"

#define MAX 100

/**
 * Imprime um vetor de inteiros.
 *
 * Esta função imprime os elementos de um vetor de inteiros no formato [elem1, elem2, ..., elemN].
 *
 * @param vetor O vetor de inteiros a ser impresso.
 * @param tamanho O tamanho do vetor.
 */
void imprimeVetorInt(const int vetor[], int tamanho) {
    if (vetor == NULL || tamanho <= 0) {
        fprintf(stderr, "Erro: Vetor nulo ou tamanho inválido.\n");
        return;
    }

    printf("[");
    for (int i = 0; i < tamanho; i++) {
        printf("%d", vetor[i]);

        if (i < tamanho - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

/**
 * Calcula o produto interno entre dois vetores de números reais.
 *
 * Esta função recebe dois vetores de números reais e calcula o produto interno
 * entre eles. O produto interno é a soma do produto de cada par de elementos
 * correspondentes dos dois vetores.
 *
 * @param vet1 O primeiro vetor.
 * @param vet2 O segundo vetor.
 * @param tam O tamanho dos vetores.
 * @return O resultado do produto interno.
 */
double produtoInternoDouble(
        const double *vet1,
        const double *vet2,
        double *produtoInterno,
        double soma,
        int tam
) {
    for (int i = 0; i < tam; ++i) {
        produtoInterno[i] = vet1[i] * vet2[i];
        soma += vet1[i] * vet2[i];
    }
    return soma;
}

/**
 * Ordena um array de inteiros utilizando o algoritmo Bubble Sort.
 *
 * @param v3 O array a ser ordenado.
 * @param tam O tamanho do array.
 */
void buubleSort(int *v3, int tam) {
    int temp;
    for (int i = 0; i < 2 * tam; i++) {
        for (int j = 0; j < 2 * tam - 1; j++) {
            if (v3[j] > v3[j + 1]) {
                temp = v3[j];
                v3[j] = v3[j + 1];
                v3[j + 1] = temp;
            }
        }
    }
}

/**
 * Imprime uma matriz de inteiros na saída padrão.
 *
 * @param matriz A matriz a ser impressa.
 * @param linhas O número de linhas na matriz.
 * @param colunas O número de colunas na matriz.
 */
void imprimeMatrizInt(int matriz[][100], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        printf("[");
        for (int j = 0; j < colunas; j++) {
            if (j < colunas - 1)
                printf("%d \t", matriz[i][j]);
            else
                printf("%d", matriz[i][j]);
        }
        printf("]\n");
    }
}

/**
 * Calcula a soma dos elementos de um array de números double.
 *
 * @param n O tamanho do array.
 * @param vetor O array de números double.
 *
 * @return A soma dos elementos do array.
 */
double sumArray(int n, double vetor[]) {
    double sum = 0;

    for (int i = 0; i < n; i++) {
        printf("vetor[%d]: ", i + 1);
        scanf("%lf", &vetor[i]);
        sum += vetor[i];
    }
    return sum;
}

/**
 * Verifica se um valor está dentro de um intervalo especificado.
 *
 * @param input O valor a ser verificado.
 * @param inicio O limite inferior do intervalo.
 * @param fim O limite superior do intervalo.
 *
 * @return true se o valor está dentro do intervalo, false caso contrário.
 */
bool verifyInput(int input, int inicio, int fim) {
    return input >= inicio && input <= fim;
}

/**
 * Função para imprimir uma linha de caracteres.
 *
 * Esta função recebe um tamanho e um character como entrada e imprime uma linha
 * composta pelo caractere fornecido, repetido pelo número de vezes especificado
 * pelo tamanho.
 *
 * @param tamanho O tamanho da linha (quantidade de caracteres).
 * @param caractere O caractere a ser repetido na linha.
 */
void linha(int tamanho, char caractere) {

    for (int i = 0; i < tamanho; i++)
        printf("%c", caractere);

    printf("\n");
}

/**
 * Função para calcular o Máximo Divisor Comum (MDC) de dois números inteiros.
 *
 * Esta função recebe dois números inteiros, a e b, como entrada e calcula o MDC
 * entre esses dois números usando o algoritmo de Euclides.
 *
 * @param a O primeiro número inteiro.
 * @param b O segundo número inteiro.
 * @return O MDC entre a e b.
 */
int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

/**
 * Calcula o determinante de uma matriz quadrada de inteiros.
 *
 * Esta função utiliza a regra de Sarrus para calcular o determinante de matrizes de ordem 2, 3, 4, 5, 6, 7, 8 e 9.
 * Para matrizes de ordens diferentes, a função imprime uma mensagem indicando que o cálculo não é suportado.
 *
 * @param matriz A matriz de entrada.
 * @param linhas O número de linhas na matriz.
 * @param colunas O número de colunas na matriz.
 *
 * @return O determinante da matriz, ou 0 se a matriz não for quadrada ou se a ordem não for suportada.
 */
int determinanteMatrizInt(int matriz[MAX][MAX], int linhas, int colunas) {

    if (linhas > 9 || colunas > 9) {
        printf("Nao e possivel calcular o determinante de uma matriz de ordem maior que 9.\n");
        return 0;
    }

    if (linhas != colunas) {
        printf("Nao e possível calcular o determinante de uma matriz nao quadrada.\n");
        return 0;
    }

    if (linhas == 1 || colunas == 1) {
        return (int) matriz[0][0];
    }

    if (linhas == 2 && colunas == 2) {
        return (int) (
                matriz[0][0] * matriz[1][1] -
                matriz[0][1] * matriz[1][0]
        );
    }

    if (linhas == 3 && colunas == 3) {
        // utilizando a regra de Sarrus
        return (int) (
                matriz[0][0] * matriz[1][1] * matriz[2][2] +
                matriz[0][1] * matriz[1][2] * matriz[2][0] +
                matriz[0][2] * matriz[1][0] * matriz[2][1] -
                matriz[0][2] * matriz[1][1] * matriz[2][0] -
                matriz[0][1] * matriz[1][0] * matriz[2][2] -
                matriz[0][0] * matriz[1][2] * matriz[2][1]
        );
    }

    if (linhas == 4 && colunas == 4) {
        // utilizando a regra de Sarrus
        return (int) (
                matriz[0][0] * matriz[1][1] * matriz[2][2] * matriz[3][3] +
                matriz[0][1] * matriz[1][2] * matriz[2][3] * matriz[3][0] +
                matriz[0][2] * matriz[1][3] * matriz[2][0] * matriz[3][1] +
                matriz[0][3] * matriz[1][0] * matriz[2][1] * matriz[3][2] -
                matriz[0][3] * matriz[1][2] * matriz[2][1] * matriz[3][0] -
                matriz[0][2] * matriz[1][1] * matriz[2][0] * matriz[3][3] -
                matriz[0][1] * matriz[1][0] * matriz[2][3] * matriz[3][2] -
                matriz[0][0] * matriz[1][3] * matriz[2][2] * matriz[3][1]
        );
    }

    if (linhas == 5 && colunas == 5) {
        // utilizando a regra de Sarrs
        return (int) (
                matriz[0][0] * matriz[1][1] * matriz[2][2] * matriz[3][3] * matriz[4][4] +
                matriz[0][1] * matriz[1][2] * matriz[2][3] * matriz[3][4] * matriz[4][0] +
                matriz[0][2] * matriz[1][3] * matriz[2][4] * matriz[3][0] * matriz[4][1] +
                matriz[0][3] * matriz[1][4] * matriz[2][0] * matriz[3][1] * matriz[4][2] +
                matriz[0][4] * matriz[1][0] * matriz[2][1] * matriz[3][2] * matriz[4][3] -
                matriz[0][4] * matriz[1][3] * matriz[2][2] * matriz[3][1] * matriz[4][0] -
                matriz[0][3] * matriz[1][2] * matriz[2][1] * matriz[3][0] * matriz[4][4] -
                matriz[0][2] * matriz[1][1] * matriz[2][0] * matriz[3][4] * matriz[4][3] -
                matriz[0][1] * matriz[1][0] * matriz[2][4] * matriz[3][3] * matriz[4][2] -
                matriz[0][0] * matriz[1][4] * matriz[2][3] * matriz[3][2] * matriz[4][1]
        );
    }

    if (linhas == 6 && colunas == 6) {
        // utilizando a regra de Sarrus
        return (int) (
                matriz[0][0] * matriz[1][1] * matriz[2][2] * matriz[3][3] * matriz[4][4] * matriz[5][5] +
                matriz[0][1] * matriz[1][2] * matriz[2][3] * matriz[3][4] * matriz[4][5] * matriz[5][0] +
                matriz[0][2] * matriz[1][3] * matriz[2][4] * matriz[3][5] * matriz[4][0] * matriz[5][1] +
                matriz[0][3] * matriz[1][4] * matriz[2][5] * matriz[3][0] * matriz[4][1] * matriz[5][2] +
                matriz[0][4] * matriz[1][5] * matriz[2][0] * matriz[3][1] * matriz[4][2] * matriz[5][3] +
                matriz[0][5] * matriz[1][0] * matriz[2][1] * matriz[3][2] * matriz[4][3] * matriz[5][4] -
                matriz[0][5] * matriz[1][4] * matriz[2][3] * matriz[3][2] * matriz[4][1] * matriz[5][0] -
                matriz[0][4] * matriz[1][3] * matriz[2][2] * matriz[3][1] * matriz[4][0] * matriz[5][5] -
                matriz[0][3] * matriz[1][2] * matriz[2][1] * matriz[3][0] * matriz[4][5] * matriz[5][4] -
                matriz[0][2] * matriz[1][1] * matriz[2][0] * matriz[3][5] * matriz[4][4] * matriz[5][3] -
                matriz[0][1] * matriz[1][0] * matriz[2][5] * matriz[3][4] * matriz[4][3] * matriz[5][2] -
                matriz[0][0] * matriz[1][5] * matriz[2][4] * matriz[3][3] * matriz[4][2] * matriz[5][1]
        );
    }

    if (linhas == 7 && colunas == 7) {
        // utilizando a regra de Sarrus
        return (int) (
                matriz[0][0] * matriz[1][1] * matriz[2][2] * matriz[3][3] * matriz[4][4] * matriz[5][5] * matriz[6][6] +
                matriz[0][1] * matriz[1][2] * matriz[2][3] * matriz[3][4] * matriz[4][5] * matriz[5][6] * matriz[6][0] +
                matriz[0][2] * matriz[1][3] * matriz[2][4] * matriz[3][5] * matriz[4][6] * matriz[5][0] * matriz[6][1] +
                matriz[0][3] * matriz[1][4] * matriz[2][5] * matriz[3][6] * matriz[4][0] * matriz[5][1] * matriz[6][2] +
                matriz[0][4] * matriz[1][5] * matriz[2][6] * matriz[3][0] * matriz[4][1] * matriz[5][2] * matriz[6][3] +
                matriz[0][5] * matriz[1][6] * matriz[2][0] * matriz[3][1] * matriz[4][2] * matriz[5][3] * matriz[6][4] +
                matriz[0][6] * matriz[1][0] * matriz[2][1] * matriz[3][2] * matriz[4][3] * matriz[5][4] * matriz[6][5] -
                matriz[0][6] * matriz[1][5] * matriz[2][4] * matriz[3][3] * matriz[4][2] * matriz[5][1] * matriz[6][0] -
                matriz[0][5] * matriz[1][4] * matriz[2][3] * matriz[3][2] * matriz[4][1] * matriz[5][0] * matriz[6][6] -
                matriz[0][4] * matriz[1][3] * matriz[2][2] * matriz[3][1] * matriz[4][0] * matriz[5][6] * matriz[6][5] -
                matriz[0][3] * matriz[1][2] * matriz[2][1] * matriz[3][0] * matriz[4][6] * matriz[5][5] * matriz[6][4] -
                matriz[0][2] * matriz[1][1] * matriz[2][0] * matriz[3][6] * matriz[4][5] * matriz[5][4] * matriz[6][3] -
                matriz[0][1] * matriz[1][0] * matriz[2][6] * matriz[3][5] * matriz[4][4] * matriz[5][3] * matriz[6][2] -
                matriz[0][0] * matriz[1][6] * matriz[2][5] * matriz[3][4] * matriz[4][3] * matriz[5][2] * matriz[6][1]
        );
    }

    if (linhas == 8 && colunas == 8) {
        // utilizando a regra de Sarrus
        return (int) (
                matriz[0][0] * matriz[1][1] * matriz[2][2] * matriz[3][3] * matriz[4][4] * matriz[5][5] * matriz[6][6] *
                matriz[7][7] +
                matriz[0][1] * matriz[1][2] * matriz[2][3] * matriz[3][4] * matriz[4][5] * matriz[5][6] * matriz[6][7] *
                matriz[7][0] +
                matriz[0][2] * matriz[1][3] * matriz[2][4] * matriz[3][5] * matriz[4][6] * matriz[5][7] * matriz[6][0] *
                matriz[7][1] +
                matriz[0][3] * matriz[1][4] * matriz[2][5] * matriz[3][6] * matriz[4][7] * matriz[5][0] * matriz[6][1] *
                matriz[7][2] +
                matriz[0][4] * matriz[1][5] * matriz[2][6] * matriz[3][7] * matriz[4][0] * matriz[5][1] * matriz[6][2] *
                matriz[7][3] +
                matriz[0][5] * matriz[1][6] * matriz[2][7] * matriz[3][0] * matriz[4][1] * matriz[5][2] * matriz[6][3] *
                matriz[7][4] +
                matriz[0][6] * matriz[1][7] * matriz[2][0] * matriz[3][1] * matriz[4][2] * matriz[5][3] * matriz[6][4] *
                matriz[7][5] +
                matriz[0][7] * matriz[1][0] * matriz[2][1] * matriz[3][2] * matriz[4][3] * matriz[5][4] * matriz[6][5] *
                matriz[7][6] -
                matriz[0][7] * matriz[1][6] * matriz[2][5] * matriz[3][4] * matriz[4][3] * matriz[5][2] * matriz[6][1] *
                matriz[7][0] -
                matriz[0][6] * matriz[1][5] * matriz[2][4] * matriz[3][3] * matriz[4][2] * matriz[5][1] * matriz[6][0] *
                matriz[7][7] -
                matriz[0][5] * matriz[1][4] * matriz[2][3] * matriz[3][2] * matriz[4][1] * matriz[5][0] * matriz[6][7] *
                matriz[7][6] -
                matriz[0][4] * matriz[1][3] * matriz[2][2] * matriz[3][1] * matriz[4][0] * matriz[5][7] * matriz[6][6] *
                matriz[7][5] -
                matriz[0][3] * matriz[1][2] * matriz[2][1] * matriz[3][0] * matriz[4][7] * matriz[5][6] * matriz[6][5] *
                matriz[7][4] -
                matriz[0][2] * matriz[1][1] * matriz[2][0] * matriz[3][7] * matriz[4][6] * matriz[5][5] * matriz[6][4] *
                matriz[7][3] -
                matriz[0][1] * matriz[1][0] * matriz[2][7] * matriz[3][6] * matriz[4][5] * matriz[5][4] * matriz[6][3] *
                matriz[7][2] -
                matriz[0][0] * matriz[1][7] * matriz[2][6] * matriz[3][5] * matriz[4][4] * matriz[5][3] * matriz[6][2] *
                matriz[7][1]
        );
    }

    if (linhas == 9 && colunas == 9) {
        // utilizando a regra de Sarrus
        return (int) (
                matriz[0][0] * matriz[1][1] * matriz[2][2] * matriz[3][3] * matriz[4][4] * matriz[5][5] * matriz[6][6] *
                matriz[7][7] * matriz[8][8] +
                matriz[0][1] * matriz[1][2] * matriz[2][3] * matriz[3][4] * matriz[4][5] * matriz[5][6] * matriz[6][7] *
                matriz[7][8] * matriz[8][0] +
                matriz[0][2] * matriz[1][3] * matriz[2][4] * matriz[3][5] * matriz[4][6] * matriz[5][7] * matriz[6][8] *
                matriz[7][0] * matriz[8][1] +
                matriz[0][3] * matriz[1][4] * matriz[2][5] * matriz[3][6] * matriz[4][7] * matriz[5][8] * matriz[6][0] *
                matriz[7][1] * matriz[8][2] +
                matriz[0][4] * matriz[1][5] * matriz[2][6] * matriz[3][7] * matriz[4][8] * matriz[5][0] * matriz[6][1] *
                matriz[7][2] * matriz[8][3] +
                matriz[0][5] * matriz[1][6] * matriz[2][7] * matriz[3][8] * matriz[4][0] * matriz[5][1] * matriz[6][2] *
                matriz[7][3] * matriz[8][4] +
                matriz[0][6] * matriz[1][7] * matriz[2][8] * matriz[3][0] * matriz[4][1] * matriz[5][2] * matriz[6][3] *
                matriz[7][4] * matriz[8][5] +
                matriz[0][7] * matriz[1][8] * matriz[2][0] * matriz[3][1] * matriz[4][2] * matriz[5][3] * matriz[6][4] *
                matriz[7][5] * matriz[8][6] +
                matriz[0][8] * matriz[1][0] * matriz[2][1] * matriz[3][2] * matriz[4][3] * matriz[5][4] * matriz[6][5] *
                matriz[7][6] * matriz[8][7] -
                matriz[0][8] * matriz[1][7] * matriz[2][6] * matriz[3][5] * matriz[4][4] * matriz[5][3] * matriz[6][2] *
                matriz[7][1] * matriz[8][0] -
                matriz[0][7] * matriz[1][6] * matriz[2][5] * matriz[3][4] * matriz[4][3] * matriz[5][2] * matriz[6][1] *
                matriz[7][0] * matriz[8][8] -
                matriz[0][6] * matriz[1][5] * matriz[2][4] * matriz[3][3] * matriz[4][2] * matriz[5][1] * matriz[6][0] *
                matriz[7][8] * matriz[8][7] -
                matriz[0][5] * matriz[1][4] * matriz[2][3] * matriz[3][2] * matriz[4][1] * matriz[5][0] * matriz[6][8] *
                matriz[7][7] * matriz[8][6] -
                matriz[0][4] * matriz[1][3] * matriz[2][2] * matriz[3][1] * matriz[4][0] * matriz[5][8] * matriz[6][7] *
                matriz[7][6] * matriz[8][5] -
                matriz[0][3] * matriz[1][2] * matriz[2][1] * matriz[3][0] * matriz[4][8] * matriz[5][7] * matriz[6][6] *
                matriz[7][5] * matriz[8][4] -
                matriz[0][2] * matriz[1][1] * matriz[2][0] * matriz[3][8] * matriz[4][7] * matriz[5][6] * matriz[6][5] *
                matriz[7][4] * matriz[8][3] -
                matriz[0][1] * matriz[1][0] * matriz[2][8] * matriz[3][7] * matriz[4][6] * matriz[5][5] * matriz[6][4] *
                matriz[7][3] * matriz[8][2] -
                matriz[0][0] * matriz[1][8] * matriz[2][7] * matriz[3][6] * matriz[4][5] * matriz[5][4] * matriz[6][3] *
                matriz[7][2] * matriz[8][1]
        );
    }
}

/**
 * Função para preencher uma matriz de inteiros a partir da entrada padrão.
 *
 * Esta função recebe uma matriz de inteiros, seu número de linhas e colunas, e
 * preenche os elementos da matriz com valores fornecidos pelo usuário através da
 * entrada padrão (stdin).
 *
 * @param matriz A matriz de inteiros a ser preenchida.
 * @param linhas O número de linhas da matriz.
 * @param colunas O número de colunas da matriz.
 */
void preencheMatrizInt(int matriz[][100], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("matriz[%d,%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

/**
 * Preenche uma matriz de inteiros com valores aleatórios.
 *
 * Esta função preenche uma matriz de inteiros com valores aleatórios no intervalo [0, limite).
 * Se o limite fornecido for menor ou igual a 0, a função exibirá um erro no fluxo de erro padrão.
 * Se a semente (seed) for igual a 0, a função utilizará o tempo atual como semente para a geração
 * de números aleatórios; caso contrário, utilizará a semente fornecida.
 *
 * @param matriz A matriz a ser preenchida com valores aleatórios.
 * @param linhas O número de linhas na matriz.
 * @param colunas O número de colunas na matriz.
 * @param limite O limite superior para os valores aleatórios (exclusivo).
 * @param seed A semente para a geração de números aleatórios. Se 0, a função usará o tempo atual como semente.
 */
void preencheMatrizIntRandom(
        int matriz[][100],
        int linhas,
        int colunas,
        int limite,
        unsigned int seed
) {
    if (limite <= 0) {
        fprintf(stderr, "Erro: O limite deve ser um número positivo.\n");
        return;
    }

    if (seed == 0)
        srand((unsigned int) time(NULL));
    else
        srand(seed);

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; ++j)
            matriz[i][j] = rand() % limite;
    }
}

/**
 * Conta as posições não nulas em uma matriz, armazenando os valores em um vetor.
 *
 * Esta função percorre a matriz e identifica os elementos não nulos,
 * armazenando-os em um vetor e exibindo estatísticas sobre as posições não nulas.
 *
 * @param matriz Uma matriz de inteiros.
 * @param linhas O número de linhas na matriz.
 * @param colunas O número de colunas na matriz.
 */
void contaPosicoesNaoNulas(const int matriz[][MAX], int linhas, int colunas) {
    int pos[MAX], cont = 0;

    printf("Posicoes nao nulas: \n");

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; ++j) {
            if (matriz[i][j] != 0) {
                pos[cont] = matriz[i][j];
                cont++;
            }
        }
    }

    printf("Total de posicoes nao nulas: %d\n", cont);
    printf("Posicoes nao nulas: ");
    imprimeVetorInt(pos, cont);
    printf("\n");
}

/**
 * Preenche uma matriz de números double a partir da entrada do usuário.
 *
 * Esta função solicita que o usuário insira valores para cada elemento da matriz.
 *
 * @param matriz A matriz a ser preenchida.
 * @param linhas O número de linhas na matriz.
 * @param colunas O número de colunas na matriz.
 */
void preencheMatrizDouble(double matriz[][100], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; ++j) {
            printf("matriz[%d,%d]: ", i, j);
            scanf("%lf", &matriz[i][j]);
        }
    }
}

/**
 * Calcula a matriz transposta de uma matriz quadrada de inteiros.
 *
 * Se a matriz não for quadrada (número de linhas diferente do número de colunas),
 * imprime uma mensagem indicando que a transposta não pode ser calculada.
 *
 * @param matriz A matriz de entrada.
 * @param linhas O número de linhas na matriz.
 * @param colunas O número de colunas na matriz.
 */
void matrizTranspostaInt(int matriz[][MAX], int linhas, int colunas) {

    if (linhas != colunas) {
        printf("Não é possível calcular a transposta da matriz.\n");
        return;
    }
    int matrizT[100][100];

    for (int i = 0; i < linhas; i++) {
        printf("[");
        for (int j = 0; j < colunas; j++) {
            matrizT[i][j] = matriz[j][i];
            if (j < colunas - 1)
                printf("%d \t", matrizT[i][j]);
            else
                printf("%d", matrizT[i][j]);
        }
        printf("]\n");
    }
}

/**
 * Preenche um vetor de números em ponto flutuante com valores aleatórios.
 *
 * Esta função recebe um vetor de números em ponto flutuante, seu tamanho e um limite
 * para os valores aleatórios a serem gerados. Ela preenche o vetor com valores
 * aleatórios de ponto flutuante no intervalo [0.0, limite).
 *
 * @param vetor     O vetor de números em ponto flutuante a ser preenchido.
 * @param tamanho   O tamanho do vetor.
 * @param limite    O limite superior (exclusive) dos valores aleatórios a serem gerados.
 * @param seed      (Opcional) Uma semente para a geração de números aleatórios.
 *                  Se for 0, a função utiliza o tempo atual como semente.
 */
void preencheVetorDoubleRandom(
        double vetor[],
        int tamanho,
        double limite,
        unsigned int seed
) {
    if (limite <= 0) {
        fprintf(stderr, "Erro: O limite deve ser um número positivo.\n");
        return;
    }

    if (seed == 0)
        srand((unsigned int) time(NULL));
    else
        srand(seed);

    for (int i = 0; i < tamanho; i++)
        vetor[i] = ((double) rand() / RAND_MAX) * limite;
}

/**
 * Função para calcular a média dos elementos de um vetor de números em ponto flutuante.
 *
 * Esta função recebe um vetor de números em ponto flutuante e seu tamanho, e calcula
 * a média aritmética dos elementos do vetor.
 *
 * @param vetor O vetor de números em ponto flutuante.
 * @param n O número de elementos no vetor.
 * @return A média dos elementos do vetor.
 */
double mediaVetorDouble(double vetor[], int n) {

    double soma = 0;

    for (int i = 0; i < n; ++i)
        soma += vetor[i];

    return (double) soma / n;
}

/**
 * Calcula a raiz quadrada de um número em ponto flutuante.
 *
 * Esta função calcula a raiz quadrada de um número em ponto flutuante. Se o
 * número for negativo, a função imprime um erro e retorna 0.0. Para números
 * iguais a zero, a função retorna 0.0.
 *
 * @param num O número para o qual se deseja calcular a raiz quadrada.
 * @return A raiz quadrada do número, ou 0.0 em caso de erro.
 */
double raizQuadradaDouble(double num) {
    if (num < 0) {
        printf("Erro: Não é possível calcular a raiz quadrada de um número negativo.\n");
        return 0.0;
    }

    if (num == 0)
        return 0.0;

    float resBefore = num;
    float resActual = (resBefore + num / resBefore) / 2.0;
    float precisao = 0.0001; // Precisão desejada

    while (resBefore - resActual > precisao || resActual - resBefore > precisao) {
        resBefore = resActual;
        resActual = (resBefore + num / resBefore) / 2.0;
    }

    return resActual;
}

/**
 * Calcula a potência de um número em ponto flutuante.
 *
 * Esta função calcula a potência de um número em ponto flutuante elevado a um
 * expoente inteiro. Se o expoente for zero, a função retorna 1.0. Se o expoente
 * for negativo, a função calcula a potência inversa.
 *
 * @param base A base da potência.
 * @param exp O expoente ao qual a base será elevada.
 * @return O resultado da operação de potenciação.
 */
double potenciaDouble(double base, int exp) {
    double res = 1.0;

    if (exp == 0)
        return 1.0;

    if (exp < 0) {
        base = 1 / base;
        exp = -exp;
    }

    for (int i = 0; i < exp; i++)
        res *= base;

    return res;
}

/**
 * Preenche um vetor de inteiros com valores aleatórios.
 *
 * Esta função recebe um vetor de inteiros, seu tamanho e um limite superior
 * para os valores aleatórios a serem gerados. Ela preenche o vetor com valores
 * inteiros aleatórios entre 0 e o limite (inclusive).
 *
 * @param vetor O vetor de inteiros a ser preenchido.
 * @param tamanho O tamanho do vetor.
 * @param limite O limite superior dos valores aleatórios a serem gerados.
 * @param seed (Opcional) Uma semente para a geração de números aleatórios.
 *             Se for 0, a função utiliza o tempo atual como semente.
 */
void preencheVetorIntRandom(
        int vetor[],
        int tamanho,
        unsigned int limite,
        unsigned int seed
) {
    if (vetor == NULL || tamanho <= 0) {
        fprintf(stderr, "Erro: Vetor nulo ou tamanho inválido.\n");
        return;
    }

    if (seed == 0)
        srand((unsigned int) time(NULL));
    else
        srand(seed);

    for (int i = 0; i < tamanho; ++i)
        vetor[i] = rand() % (limite + 1);
}

/**
 * Multiplica duas matrizes de inteiros.
 *
 * Esta função realiza a multiplicação de duas matrizes quadradas de ordem 'n' e armazena
 * o resultado em uma terceira matriz.
 *
 * @param matriz1 A primeira matriz de entrada.
 * @param matriz2 A segunda matriz de entrada.
 * @param matriz3 A matriz de saída que armazenará o resultado da multiplicação.
 * @param n A ordem das matrizes (número de linhas/colunas).
 */
void multiplicaMatrizInt(
        int matriz1[][MAX],
        int matriz2[][MAX],
        int matriz3[][MAX],
        int n
) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz3[i][j] = 0;
            for (int k = 0; k < n; k++)
                matriz3[i][j] += matriz1[i][k] * matriz2[k][j];
        }
    }
}

/**
 * Soma duas matrizes de double.
 *
 * Esta função recebe duas matrizes de double, realiza a soma elemento a elemento
 * e armazena o resultado em uma terceira matriz.
 *
 * @param matriz1 A primeira matriz de entrada.
 * @param matriz2 A segunda matriz de entrada.
 * @param resultado A matriz que armazenará o resultado da soma.
 * @param linhas O número de linhas nas matrizes.
 * @param colunas O número de colunas nas matrizes.
 */
void somaMatrizesDouble(
        const double matriz1[][MAX],
        const double matriz2[][MAX],
        double resultado[][MAX],
        int linhas,
        int colunas
) {
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j)
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
    }
}


/**
 * Imprime um vetor de números em ponto flutuante de precisão dupla (double).
 *
 * Esta função recebe um vetor de números em ponto flutuante de precisão dupla (double)
 * e seu tamanho, e imprime os elementos do vetor na saída padrão, formatando-os entre
 * colchetes e separados por vírgulas. Os números são impressos com duas casas decimais.
 *
 * @param vetor O vetor de números em ponto flutuante a ser impresso.
 * @param tamanho O tamanho do vetor.
 */
void imprimeVetorDouble(double vetor[], int tamanho) {
    printf("[");
    for (int i = 0; i < tamanho; ++i) {
        printf("%.2lf", vetor[i]);

        if (i < tamanho - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

/**
 * Função para imprimir uma matriz de números double.
 *
 * Esta função percorre cada elemento da matriz e imprime seus valores formatados.
 *
 * @param matriz A matriz a ser impressa.
 * @param linhas O número de linhas na matriz.
 * @param colunas O número de colunas na matriz.
 */
void imprimeMatrizDouble(const double matriz[][MAX], int linhas, int colunas) {
    for (int i = 0; i < linhas; ++i) {
        printf("[");
        for (int j = 0; j < colunas; ++j) {
            printf("%.2lf", matriz[i][j]);
            if (j < colunas - 1)
                printf("\t");
        }
        printf("]\n");
    }
}

/**
 * Preenche um vetor de inteiros a partir da entrada padrão.
 *
 * Esta função recebe um vetor de inteiros e seu tamanho, e preenche o vetor
 * com valores inseridos pelo usuário na entrada padrão.
 *
 * @param vet O vetor de inteiros a ser preenchido.
 * @param tamanho O tamanho do vetor.
 */
void preencheVetorInt(int vet[], int tamanho) {
    for (int i = 0; i < tamanho; ++i) {
        printf("vetor[%d] = ", i + 1);
        scanf("%d", &vet[i]);
    }
}

/**
 * Preenche um vetor de números em ponto flutuante de precisão dupla (double)
 * a partir da entrada padrão.
 *
 * Esta função recebe um vetor de números em ponto flutuante de precisão dupla (double)
 * e seu tamanho, e preenche o vetor com valores inseridos pelo usuário na entrada padrão.
 *
 * @param vet O vetor de números em ponto flutuante a ser preenchido.
 * @param tamanho O tamanho do vetor.
 */
void preencheVetorDouble(double vet[], int tamanho) {
    for (int i = 0; i < tamanho; ++i) {
        printf("vetor[%d] = ", i + 1);
        scanf("%lf", &vet[i]);
    }
}

/**
 * Preenche um vetor de números em ponto flutuante com valores informados pelo usuário.
 *
 * Esta função solicita ao usuário que insira valores para preencher um vetor de números em ponto flutuante.
 *
 * @param vet O vetor de números em ponto flutuante a ser preenchido.
 * @param tamanho O tamanho do vetor.
 */
void preencheVetorFloat(float vet[], int tamanho) {
    for (int i = 0; i < tamanho; ++i) {
        printf("vetor[%d] = ", i + 1);
        scanf("%f", &vet[i]);
    }
}

/**
 * Calcula a soma dos elementos de um vetor de números em ponto flutuante.
 *
 * Esta função recebe um vetor de números em ponto flutuante e o tamanho do vetor,
 * e retorna a soma de todos os elementos do vetor.
 *
 * @param pDouble O vetor de números em ponto flutuante.
 * @param i O tamanho do vetor.
 * @return A soma dos elementos do vetor.
 */
float somaElementosVetorFloat(float pDouble[10], int i) {
    float soma = 0.0;
    for (int j = 0; j < i; j++)
        soma += pDouble[j];
    return soma;
}

/**
 * Libera a memória alocada para uma matriz de inteiros.
 *
 * Esta função recebe uma matriz de inteiros e o número de linhas, e libera
 * a memória alocada para a matriz, incluindo suas linhas.
 *
 * @param matriz A matriz de inteiros a ser liberada.
 * @param linhas O número de linhas da matriz.
 */
void liberarMatrizInt(int **matriz, int linhas) {
    for (int i = 0; i < linhas; i++)
        free(matriz[i]);

    free(matriz);
}

/**
 * Verifica a ocorrência de uma sequência em outra sequência.
 *
 * Esta função recebe duas sequências de inteiros e seus tamanhos, e verifica quantas vezes
 * a primeira sequência ocorre dentro da segunda sequência.
 *
 * @param sequencia1 A primeira sequência de inteiros.
 * @param n1 O tamanho da primeira sequência.
 * @param sequencia2 A segunda sequência de inteiros.
 * @param n2 O tamanho da segunda sequência.
 * @return O número de vezes que a primeira sequência ocorre dentro da segunda sequência.
 */
int verificaOcorrenciaVetorInt(const int sequencia1[], int n1, const int sequencia2[], int n2) {

    if (n1 > n2 || n1 <= 0 || n2 <= 0)
        return 0;

    int count = 0;

    for (int i = 0; i <= n2 - n1; i++) {
        int found = 1;

        for (int j = 0; j < n1; j++) {
            if (sequencia1[j] != sequencia2[i + j]) {
                found = 0;
                break;
            }
        }

        if (found)
            count++;
    }

    return count;
}