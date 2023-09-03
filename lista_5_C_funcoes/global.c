#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <malloc.h>
#include "global.h"

#define MAX_DIMENSAO 1000 // Defina o valor máximo que você deseja suportar

/**
 * Calcula o máximo divisor comum (MDC) de dois números inteiros.
 *
 * Esta função calcula o máximo divisor comum (MDC) de dois números inteiros
 * utilizando o algoritmo de Euclides.
 *
 * @param m Um número inteiro.
 * @param n Outro número inteiro.
 * @return O máximo divisor comum (MDC) entre 'm' e 'n'.
 *
 * Exemplo de uso:
 * int resultado = mdc(36, 48); // Calcula o MDC de 36 e 48
 */
int mdc(int m, int n) {
    return n == 0 ? m : mdc(n, m % n);
}

/**
 * Calcula a potência de um número inteiro 'a' elevado a 'b'.
 *
 * Esta função calcula a potência de um número inteiro 'a' elevado a 'b'. Ela
 * multiplica o valor de 'a' por si mesmo 'b' vezes para calcular o resultado.
 *
 * @param a O número inteiro a ser elevado à potência.
 * @param b O expoente inteiro.
 * @return O resultado da operação 'a' elevado a 'b'.
 *
 * Exemplo de uso:
 * int resultado = fun1(2, 3); // Calcula 2 elevado a 3 (2^3)
 */
int fun1(int a, int b) {
    int p = 1;
    for (int i = 0; i < b; i++) {
        p *= a;
    }
    return p;
}

/**
 * Verifica se dois números são amigáveis.
 *
 * Esta função verifica se dois números inteiros 'a' e 'i' são amigáveis. Dois
 * números são considerados amigáveis se a soma dos divisores próprios de 'a' é
 * igual a 'i' e a soma dos divisores próprios de 'i' é igual a 'a'.
 *
 * @param a Um número inteiro.
 * @param i Outro número inteiro para comparar com 'a'.
 * @return 'true' se os números forem amigáveis, 'false' caso contrário.
 *
 * Exemplo de uso:
 * bool resultado = amigos(220, 284); // Verifica se 220 e 284 são amigáveis
 */
bool amigos(int a, int i) {
    int somaDivisoresA = 0, somaDivisoresB = 0;
    for (int j = 1; j < a; j++) {
        if (a % j == 0) somaDivisoresA += j;
        if (i % j == 0) somaDivisoresB += j;
    }
    return somaDivisoresA == i && somaDivisoresB == a;
}

/**
 * Calcula a média dos valores em um array de números de ponto flutuante.
 *
 * Esta função calcula a média dos valores presentes em um array de números
 * de ponto flutuante. A quantidade de elementos no array é especificada pelo
 * parâmetro 'qtd'.
 *
 * @param pDouble Um array de números de ponto flutuante.
 * @param qtd A quantidade de elementos no array 'pDouble'.
 * @return A média dos valores presentes no array.
 *
 * Exemplo de uso:
 * double numeros[] = {10.5, 20.0, 15.3, 8.7};
 * double resultado = media(numeros, 4); // Calcula média dos 4 números
 */
double media(double pDouble[], int qtd) {
    double soma = 0;
    for (int i = 0; i < qtd; i++) {
        soma += pDouble[i];
    }
    return soma / qtd;
}

/**
 * Preenche uma matriz quadrada com valores inseridos pelo usuário.
 *
 * Esta função preenche uma matriz quadrada com valores inseridos pelo usuário.
 * A matriz deve ter a dimensão especificada.
 *
 * @param matriz Uma matriz quadrada a ser preenchida pelo usuário.
 * @param dimensao A dimensão da matriz quadrada (número de linhas e colunas).
 *
 * Exemplo de uso:
 * int minhaMatriz[MAX_DIMENSAO][MAX_DIMENSAO];
 * preencheMatrizQuadrada(minhaMatriz, 3); // Preenche matriz 3x3
 */
void preencheMatrizQuadrada(int matriz[][MAX_DIMENSAO], int dimensao) {
    printf("Digite os valores da matriz de dimensao %d x %d: ", dimensao, dimensao);
    for (int i = 0; i < dimensao; i++) {
        printf("Digite os valores da linha %d: ", i + 1);
        for (int j = 0; j < dimensao; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
}

/**
 * Calcula a soma de um array de números.
 *
 * @param numeros Array contendo os números para os quais deseja-se calcular a soma.
 * @param quantidade A quantidade de elementos no array 'numeros'.
 * @return A soma dos números no array.
 */
double calcularSoma(double numeros[], int quantidade) {
    double soma = 0;
    for (int i = 0; i < quantidade; i++) {
        soma += numeros[i];
    }
    return soma;
}

/**
 * Calcula a soma dos quadrados das diferenças em relação à média.
 *
 * @param numeros Array contendo os números para os quais deseja-se calcular a soma dos quadrados das diferenças.
 * @param quantidade A quantidade de elementos no array 'numeros'.
 * @param media A média dos números no array 'numeros'.
 * @return A soma dos quadrados das diferenças entre os números e a média.
 */
double calcularSomaQuadradosDasDiferencas(double numeros[], int quantidade, double media) {
    double somaQuadradosDasDiferencas = 0;
    for (int i = 0; i < quantidade; i++) {
        double diferenca = numeros[i] - media;
        somaQuadradosDasDiferencas += diferenca * diferenca;
    }
    return somaQuadradosDasDiferencas;
}

/**
 * Calcula o desvio padrão amostral de um array de números.
 *
 * @param numeros Array contendo os números para os quais deseja-se calcular o desvio padrão amostral.
 * @param quantidade A quantidade de elementos no array 'numeros'.
 * @return O desvio padrão amostral dos números no array.
 * @note O desvio padrão amostral não é definido para menos de dois valores, nesse caso o valor retornado será 0.
 */
double desvioPadrao(double numeros[], int quantidade) {
    if (quantidade <= 1) {
        return 0;
    }

    double media = calcularSoma(numeros, quantidade) / quantidade;
    double somaQuadradosDasDiferencas = calcularSomaQuadradosDasDiferencas(numeros, quantidade, media);
    double varianciaAmostral = somaQuadradosDasDiferencas / (quantidade - 1);
    double desvioPadraoAmostral = sqrt(varianciaAmostral);

    return desvioPadraoAmostral;
}

/**
 * Preenche um vetor de números de ponto flutuante com valores fornecidos pelo usuário.
 *
 * Esta função solicita ao usuário que insira valores para cada posição do vetor de números de ponto flutuante.
 *
 * @param qtd O número de elementos a serem preenchidos no vetor.
 * @param pDouble O vetor de números de ponto flutuante a ser preenchido.
 */
void preencheVetorDouble(int qtd, double pDouble[qtd]) {
    for (int i = 0; i < qtd; i++) {
        printf("Digite o %dº número: ", i + 1);
        scanf("%lf", &pDouble[i]);
    }
}


/**
 * Preenche um vetor de números de ponto flutuante com valores fornecidos pelo usuário.
 *
 * Esta função solicita ao usuário que insira valores para cada posição do vetor de números de ponto flutuante.
 *
 * @param qtd O número de elementos a serem preenchidos no vetor.
 * @return Um vetor alocado dinamicamente contendo os valores inseridos pelo usuário.
 */
double *preencheVetorDoubleReturn(int qtd) {
    double *pDouble = (double *) malloc(qtd * sizeof(double));

    if (pDouble == NULL) {
        printf("Erro: Falha na alocação de memória.\n");
        return NULL;
    }

    for (int i = 0; i < qtd; i++) {
        printf("Digite o %dº número: ", i + 1);
        scanf("%lf", &pDouble[i]);
    }

    return pDouble;
}

/**
 * Calcula a matriz transposta de uma matriz quadrada.
 *
 * Esta função calcula a matriz transposta de uma matriz quadrada fornecida e a armazena na matriz
 * transposta especificada.
 *
 * @param matriz A matriz de entrada da qual será calculada a matriz transposta.
 * @param matrizTransposta A matriz onde a matriz transposta será armazenada.
 * @param dimensao A dimensão da matriz (número de linhas e colunas).
 */
void transposta(double matriz[30][30], double matrizTransposta[30][30], int dimensao) {
    for (int i = 0; i < dimensao; i++) {
        for (int j = 0; j < dimensao; j++) {
            matrizTransposta[i][j] = matriz[j][i];
        }
    }
}

/**
 * Imprime uma matriz quadrada.
 *
 * Esta função imprime os elementos de uma matriz quadrada com a dimensão especificada.
 *
 * @param matriz A matriz a ser impressa.
 * @param dimensao A dimensão da matriz (número de linhas e colunas).
 */
void imprimeMatrizQuadrada(double matriz[][MAX_DIMENSAO], int dimensao) {
    printf("Matriz %d x %d:\n", dimensao, dimensao);

    for (int i = 0; i < dimensao; i++) {
        for (int j = 0; j < dimensao; j++) {
            printf("%.2lf\t", matriz[i][j]); // Usando "\t" para espaçamento entre elementos
        }
        printf("\n");
    }
}

/**
 * Verifica se a soma dos quadrados de a e b é igual a n.
 *
 * @param a Primeiro inteiro.
 * @param b Segundo inteiro.
 * @param n Inteiro alvo.
 * @return Verdadeiro se a^2 + b^2 for igual a n, falso caso contrário.
 */
int test(int a, int b, int n) {
    return a * a + b * b == n;
}

/**
 * Verifica se n é um número pitagórico.
 *
 * @param n Inteiro alvo.
 * @return Verdadeiro se n for pitagórico, falso caso contrário.
 */
int pitagorico(int n) {
    for (int a = 1; a * a < n; a++) {
        int b_quadrado = n - a * a;
        int b = (int) sqrt(b_quadrado);
        if (test(a, b, n)) {
            return 1;  // n é um número pitagórico
        }
    }
    return 0;  // n não é um número pitagórico
}

/**
 * Encontra a menor base b tal que b^k = n.
 *
 * @param n Inteiro alvo.
 * @return A menor base b possível para a qual b^k = n.
 */
int menor_base_log(int n) {
    if (n <= 1) {
        return n;  // Para n <= 1, o resultado é n
    }

    int menor_base = n;  // Inicializa com um valor maior do que n

    // Encontra os fatores primos de 2
    while (n % 2 == 0) {
        n /= 2;
        menor_base = 2;
    }

    // Encontra os fatores primos ímpares
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            n /= i;
            menor_base = i;
        }
    }

    return menor_base;
}











