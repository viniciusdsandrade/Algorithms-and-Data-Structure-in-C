#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "global.h"

#define MAX 100

void imprimeMatrizInt(int matriz[][100], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        printf("[");
        for (int j = 0; j < colunas; j++) {
            if (j < colunas - 1)
                printf("%d \t", matriz[i][j]);
            else
                printf("%d", matriz[i][j]);
        }
        printf("]");
        putchar('\n');
    }
}

double sumArray(int n, double vetor[]) {
    double sum = 0;

    for (int i = 0; i < n; i++) {
        printf("vetor[%d]: ", i + 1);
        scanf("%lf", &vetor[i]);
        sum += vetor[i];
    }

    return sum;
};

bool verifyInput(int input, int inicio, int fim) {
    return input >= inicio && input <= fim;
};

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

int determinanteMatrizInt(int matriz[MAX][MAX], int linhas, int colunas) {
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

void preencheMatrizDouble(double matriz[][100], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; ++j) {
            printf("matriz[%d,%d]: ", i, j);
            scanf("%lf", &matriz[i][j]);
        }
    }
}
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
        printf("]");
        putchar('\n');
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

    return soma / n;
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
void preencheVetorIntRandom(int vetor[], int tamanho, unsigned int limite, unsigned int seed) {
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


void multiplicaMatrizInt(
        int m1[][MAX],
        int m2[][MAX],
        int m3[][MAX],
        int n
) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m3[i][j] = 0;
            for (int k = 0; k < n; k++) {
                m3[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
};

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

void imprimeMatrizDouble(double matriz[][MAX], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        printf("[");
        for (int j = 0; j < colunas; ++j) {
            printf("%.2lf", matriz[i][j]);
            if (j < colunas - 1)
                printf("\t");
        }
        printf("]");
        putchar('\n');
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
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
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
    if (n1 > n2 || n1 <= 0 || n2 <= 0) {
        return 0;
    }

    int count = 0;

    for (int i = 0; i <= n2 - n1; i++) {
        int found = 1;

        for (int j = 0; j < n1; j++) {
            if (sequencia1[j] != sequencia2[i + j]) {
                found = 0;
                break;
            }
        }

        if (found) {
            count++;
        }
    }

    return count;
}
