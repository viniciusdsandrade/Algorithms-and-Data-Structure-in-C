#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

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
 * Função para calcular o determinante de uma matriz quadrada de inteiros.
 *
 * Esta função recebe uma matriz de inteiros, seu número de linhas e colunas e calcula
 * o determinante da matriz. A função é capaz de calcular o determinante de matrizes
 * de tamanho 1x1, 2x2, 3x3, 4x4 e 5x5 usando as regras de Laplace ou regra de Sarrus
 * (para matrizes 3x3) e a expansão por cofatores.
 *
 * @param matriz Um ponteiro para a matriz de inteiros.
 * @param linhas O número de linhas da matriz.
 * @param colunas O número de colunas da matriz.
 * @return O determinante da matriz ou 0 se a matriz não for quadrada ou tiver tamanho
 * maior que 5x5.
 */
int determinanteMatrizInt(int **matriz, int linhas, int colunas) {
    if (linha != colunas) {
        printf("Não é possível calcular o determinante de uma matriz não quadrada.\n");
        return 0;
    }

    if (linhas == 1 || colunas == 1) {
        return (int) matriz[0][0];
    }

    if (linhas == 2 && colunas == 2) {
        return (int) (matriz[0][0] * matriz[1][1] -
                      matriz[0][1] * matriz[1][0]);
    }

    if (linhas == 3 && colunas == 3) {
        // utilizando a regra de Sarrus
        return (int) (matriz[0][0] * matriz[1][1] * matriz[2][2] +
                      matriz[0][1] * matriz[1][2] * matriz[2][0] +
                      matriz[0][2] * matriz[1][0] * matriz[2][1] -
                      matriz[0][2] * matriz[1][1] * matriz[2][0] -
                      matriz[0][1] * matriz[1][0] * matriz[2][2] -
                      matriz[0][0] * matriz[1][2] * matriz[2][1]);
    }

    if (linhas == 4 && colunas == 4) {
        // utilizando a regra de Sarrus
        return (int) (matriz[0][0] * matriz[1][1] * matriz[2][2] * matriz[3][3] +
                      matriz[0][1] * matriz[1][2] * matriz[2][3] * matriz[3][0] +
                      matriz[0][2] * matriz[1][3] * matriz[2][0] * matriz[3][1] +
                      matriz[0][3] * matriz[1][0] * matriz[2][1] * matriz[3][2] -
                      matriz[0][3] * matriz[1][2] * matriz[2][1] * matriz[3][0] -
                      matriz[0][2] * matriz[1][1] * matriz[2][0] * matriz[3][3] -
                      matriz[0][1] * matriz[1][0] * matriz[2][3] * matriz[3][2] -
                      matriz[0][0] * matriz[1][3] * matriz[2][2] * matriz[3][1]);
    }

    if (linhas == 5 && colunas == 5) {
        // utilizando a regra de Sarrs
        return (int) (matriz[0][0] * matriz[1][1] * matriz[2][2] * matriz[3][3] * matriz[4][4] +
                      matriz[0][1] * matriz[1][2] * matriz[2][3] * matriz[3][4] * matriz[4][0] +
                      matriz[0][2] * matriz[1][3] * matriz[2][4] * matriz[3][0] * matriz[4][1] +
                      matriz[0][3] * matriz[1][4] * matriz[2][0] * matriz[3][1] * matriz[4][2] +
                      matriz[0][4] * matriz[1][0] * matriz[2][1] * matriz[3][2] * matriz[4][3] -
                      matriz[0][4] * matriz[1][3] * matriz[2][2] * matriz[3][1] * matriz[4][0] -
                      matriz[0][3] * matriz[1][2] * matriz[2][1] * matriz[3][0] * matriz[4][4] -
                      matriz[0][2] * matriz[1][1] * matriz[2][0] * matriz[3][4] * matriz[4][3] -
                      matriz[0][1] * matriz[1][0] * matriz[2][4] * matriz[3][3] * matriz[4][2] -
                      matriz[0][0] * matriz[1][4] * matriz[2][3] * matriz[3][2] * matriz[4][1]);
    }
}

/**
 * Função para calcular a matriz inversa de uma matriz quadrada.
 *
 * Esta função recebe uma matriz quadrada de números em ponto flutuante (float) e
 * seu tamanho (número de linhas/colunas) como entrada. Ela calcula a matriz adjunta
 * da matriz de entrada, o determinante da matriz de entrada e verifica se a matriz
 * é inversível (determinante diferente de zero). Se a matriz for inversível, a
 * função calcula e retorna a matriz inversa. Caso contrário, retorna NULL.
 *
 * @param matriz A matriz de entrada (ponteiro para array 2D).
 * @param lenght O tamanho da matriz (número de linhas/colunas).
 * @return Um ponteiro para a matriz inversa se a matriz for inversível, ou NULL
 * caso contrário.
 */
int **calcularInversa(float matriz[][100], int lenght) {
    float adjunta[lenght][lenght];
    float cofator[lenght][lenght];
    float determinante = 0;

    for (int i = 0; i < lenght; i++) {
        for (int j = 0; j < lenght; j++) {
            adjunta[i][j] = pow(-1, i + j) * matriz[j][i];
            cofator[i][j] = adjunta[i][j];
        }
    }

    for (int i = 0; i < lenght; i++)
        determinante += matriz[0][i] * cofator[0][i];

    if (determinante == 0) {
        printf("A matriz não é inversível.\n");
        return NULL;
    }

    for (int i = 0; i < lenght; i++) {
        for (int j = 0; j < lenght; j++)
            matriz[i][j] = adjunta[i][j] / determinante;
    }

    return matriz;
}

/**
 * Função para criar uma matriz identidade de inteiros.
 *
 * Esta função cria e retorna uma matriz identidade de inteiros com a dimensão
 * especificada. A matriz identidade possui 1s na diagonal principal e 0s em
 * todas as outras posições.
 *
 * @param n A dimensão da matriz identidade (número de linhas e colunas).
 * @return Um ponteiro para a matriz identidade.
 */
int **matrizIdentidadeInt(int n) {
    int **matriz = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
    return matriz;
}

/**
 * Função para criar e calcular uma matriz identidade de inteiros.
 *
 * Esta função cria e retorna uma matriz identidade de inteiros com a dimensão
 * especificada. A matriz identidade possui 1s na diagonal principal e 0s em
 * todas as outras posições. É uma versão mais completa da função `matrizIdentidadeInt`.
 *
 * @param n A dimensão da matriz identidade (número de linhas e colunas).
 * @return Um ponteiro para a matriz identidade.
 */
int **matrizIdentidadeCalculo(int n) {
    int **matriz = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matriz[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            if (i == j)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
    return matriz;
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
 * Função para criar e preencher uma matriz de inteiros a partir da entrada padrão.
 *
 * Esta função cria uma matriz de inteiros com o número de linhas e colunas
 * especificado, preenche os elementos da matriz com valores fornecidos pelo
 * usuário através da entrada padrão (stdin) e retorna a matriz preenchida.
 *
 * @param linhas O número de linhas da matriz.
 * @param colunas O número de colunas da matriz.
 * @return Um ponteiro para a matriz preenchida.
 */
int **preenchendoMatrizInt(int linhas, int colunas) {
    int matrizPreenchida[linhas][colunas];

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("matriz[%d,%d]: ", i, j);
            scanf("%d", &matrizPreenchida[i][j]);
        }
    }
    return matrizPreenchida;
}

/**
 * Função para preencher uma matriz de inteiros com valores aleatórios.
 *
 * Esta função recebe uma matriz de inteiros, seu número de linhas e colunas, e
 * um limite para os valores aleatórios a serem gerados. Ela preenche a matriz
 * com valores inteiros aleatórios entre 0 e o limite (inclusive).
 *
 * @param matriz A matriz de inteiros a ser preenchida.
 * @param linhas O número de linhas da matriz.
 * @param colunas O número de colunas da matriz.
 * @param limite O limite superior dos valores aleatórios a serem gerados.
 */
void preencheMatrizIntRandom(int matriz[][100], int linhas, int colunas, int limite) {
    srand(time(NULL));

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++)
            matriz[i][j] = rand() % (limite + 1);
    }
}

/**
 * Função para preencher uma matriz de inteiros com valores aleatórios.
 *
 * Esta função recebe uma matriz de inteiros alocada dinamicamente, seu número de
 * linhas e colunas, e um limite para os valores aleatórios a serem gerados. Ela
 * preenche a matriz com valores inteiros aleatórios entre 0 e o limite (exclusive).
 *
 * @param matriz Um ponteiro para a matriz de inteiros a ser preenchida.
 * @param linhas O número de linhas da matriz.
 * @param colunas O número de colunas da matriz.
 * @param limite O limite superior dos valores aleatórios a serem gerados.
 */
void preencherMatrizIntRandom2(int **matriz, int linhas, int colunas, int limite) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++)
            matriz[i][j] = rand() % limite;
    }
}

/**
 * Função para preencher um vetor de números em ponto flutuante com valores aleatórios.
 *
 * Esta função recebe um vetor de números em ponto flutuante, seu tamanho e um limite
 * para os valores aleatórios a serem gerados. Ela preenche o vetor com valores
 * aleatórios de ponto flutuante entre 0.0 (inclusive) e limite (exclusive).
 *
 * @param vetor O vetor de números em ponto flutuante a ser preenchido.
 * @param tamanho O tamanho do vetor.
 * @param limite O limite superior dos valores aleatórios a serem gerados.
 */
void preencheVetorDoubleRandom(double vetor[], int tamanho, int limite) {
    srand(time(NULL));

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
 */
void preencheVetorIntRandom(int vetor[], int tamanho, int limite) {

    srand(time(NULL));

    for (int i = 0; i < tamanho; ++i)
        vetor[i] = (rand() % (limite + 1));
}

/**
 * Imprime uma matriz de inteiros.
 *
 * Esta função recebe uma matriz de inteiros, seu número de linhas e colunas, e a
 * imprime na saída padrão formatada.
 *
 * @param matriz A matriz de inteiros a ser impressa.
 * @param linhas O número de linhas da matriz.
 * @param colunas O número de colunas da matriz.
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
        printf("]");
        putchar('\n');
    }
}

/**
 * Imprime uma matriz de inteiros alocada dinamicamente.
 *
 * Esta função recebe uma matriz de inteiros alocada dinamicamente, seu número de
 * linhas e colunas, e a imprime na saída padrão formatada.
 *
 * @param matriz Um ponteiro para a matriz de inteiros a ser impressa.
 * @param linhas O número de linhas da matriz.
 * @param colunas O número de colunas da matriz.
 */
void imprimirMatrizInt(int **matriz, int linhas, int colunas) {

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

/**
 * Soma duas matrizes de inteiros.
 *
 * Esta função recebe duas matrizes de inteiros, seus números de linhas e colunas,
 * e as soma elemento por elemento, gerando uma terceira matriz resultants da soma.
 * A função imprime as matrizes de entrada e a matriz resultante na saída padrão.
 * Se as matrizes de entrada não tiverem as mesmas dimensões, a função imprime uma
 * mensagem de erro e não realiza a soma.
 *
 * @param matriz1 A primeira matriz de inteiros a ser somada.
 * @param matriz2 A segunda matriz de inteiros a ser somada.
 * @param l1 O número de linhas da primeira matriz.
 * @param c1 O número de colunas da primeira matriz.
 * @param l2 O número de linhas da segunda matriz.
 * @param c2 O número de colunas da segunda matriz.
 */
void somaMatrizInt(int matriz1[][100], int matriz2[][100], int l1, int c1, int l2, int c2) {
    if (l1 != l2 || c1 != c2) {
        printf("Não é possível somar as matrizes.\n");
        return;
    }

    int matriz3[100][100];

    printf("Matriz 1:\n");
    imprimeMatrizInt(matriz1, l1, c1);
    printf("\nMatriz 2:\n");
    imprimeMatrizInt(matriz2, l2, c2);

    printf("\nMatriz1 + Matriz2:\n");
    for (int i = 0; i < l1; i++) {
        printf("[");
        for (int j = 0; j < c2; j++) {
            matriz3[i][j] = matriz1[i][j] + matriz2[i][j];
            if (j < c2 - 1)
                printf("%d \t", matriz3[i][j]);
            else
                printf("%d", matriz3[i][j]);
        }
        printf("]");
        putchar('\n');
    }
}

/**
 * Subtrai duas matrizes de inteiros.
 *
 * Esta função recebe duas matrizes de inteiros, seus números de linhas e colunas,
 * e as subtrai elemento por elemento, gerando uma terceira matriz resultante da subtração.
 * A função imprime as matrizes de entrada e a matriz resultante na saída padrão.
 * Se as matrizes de entrada não tiverem as mesmas dimensões, a função imprime uma
 * mensagem de erro e não realiza a subtração.
 *
 * @param matriz1 A primeira matriz de inteiros a ser subtraída.
 * @param matriz2 A segunda matriz de inteiros a ser subtraída.
 * @param l1 O número de linhas da primeira matriz.
 * @param c1 O número de colunas da primeira matriz.
 * @param l2 O número de linhas da segunda matriz.
 * @param c2 O número de colunas da segunda matriz.
 */
void subtraiMatrizInt(int matriz1[][100], int matriz2[][100], int l1, int c1, int l2, int c2) {
    if (l1 != l2 || c1 != c2) {
        printf("Não é possível subtrair as matrizes.\n");
        return;
    }

    int matriz3[100][100];

    printf("Matriz1:\n");
    imprimeMatrizInt(matriz1, l1, c1);
    printf("\nMatriz2:\n");
    imprimeMatrizInt(matriz2, l2, c2);

    printf("\nMatriz1 - Matriz2:\n");
    for (int i = 0; i < l1; i++) {
        printf("[");
        for (int j = 0; j < c2; j++) {
            matriz3[i][j] = matriz1[i][j] - matriz2[i][j];
            if (j < c1 - 1)
                printf("%d \t", matriz3[i][j]);
            else
                printf("%d", matriz3[i][j]);
        }
        printf("]");
        putchar('\n');
    }
}

/**
 * Multiplica uma matriz de inteiros por um escalar.
 *
 * Esta função recebe uma matriz de inteiros e um valor inteiro (escalar), e
 * multiplica cada elemento da matriz pelo escalar, gerando uma matriz resultante.
 * A função aloca dinamicamente a matriz resultante e a retorna.
 *
 * @param matriz A matriz de inteiros a ser multiplicada pelo escalar.
 * @param n O valor inteiro pelo qual a matriz será multiplicada.
 * @return A matriz resultante da multiplicação.
 */
 int **multiplicaMatrizInt2(int **matriz, int n) {
    int **matrizMultiplicacao = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrizMultiplicacao[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
            matrizMultiplicacao[i][j] = matriz[i][j] * n;
    }
    return matrizMultiplicacao;
}

/**
 * Multiplica duas matrizes de inteiros.
 *
 * Esta função recebe duas matrizes de inteiros, seus números de linhas e colunas,
 * e as multiplica utilizando o algoritmo de multiplicação de matrizes. A função
 * imprime as matrizes de entrada e a matriz resultante na saída padrão.
 * Se as matrizes de entrada não tiverem as dimensões apropriadas para multiplicação,
 * a função imprime uma mensagem de erro e não realiza a multiplicação.
 *
 * @param m1 A primeira matriz de inteiros a ser multiplicada.
 * @param m2 A segunda matriz de inteiros a ser multiplicada.
 * @param l1 O número de linhas da primeira matriz.
 * @param c1 O número de colunas da primeira matriz.
 * @param l2 O número de linhas da segunda matriz.
 * @param c2 O número de colunas da segunda matriz.
 */
void multiplicaMatrizInt(int m1[][100], int m2[][100], int l1, int c1, int l2, int c2) {

    if (c1 != l2) {
        printf("Não é possível multiplicar as matrizes.\n");
        return;
    }

    int m3[100][100];

    printf("Matriz 1:\n");
    imprimeMatrizInt(m1, l1, c1);

    printf("\nMatriz 2:\n");
    imprimeMatrizInt(m2, l2, c2);

    printf("\nMatriz1 X Matriz2:\n");
    for (int i = 0; i < l1; i++) {
        printf("[");
        for (int j = 0; j < c2; j++) {
            m3[i][j] = 0;

            for (int k = 0; k < c1; k++)
                m3[i][j] += m1[i][k] * m2[k][j];

            if (j < c2 - 1)
                printf("%d \t", m3[i][j]);
            else
                printf("%d", m3[i][j]);
        }
        printf("]");
        putchar('\n');
    }
}

/**
 * Imprime um vetor de inteiros.
 *
 * Esta função recebe um vetor de inteiros e seu tamanho e imprime os elementos
 * do vetor na saída padrão, formatando-os entre colchetes e separados por regulars.
 *
 * @param vetor O vetor de inteiros a ser impresso.
 * @param tamanho O tamanho do vetor.
 */
void imprimeVetorInt(int vetor[], int tamanho) {
    printf("[");
    for (int i = 0; i < tamanho; i++) {

        if (i < tamanho - 1)
            printf("%d, ", vetor[i]);
        else
            printf("%d]", vetor[i]);
    }
    printf("\n");
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
        if (i < tamanho - 1)
            printf("%.02lf ,\t", vetor[i]);
        else
            printf("%.02lf]", vetor[i]);
    }
    printf("\n");
}

/**
 * Imprime um vetor de números em ponto flutuante de precisão simples (float).
 *
 * Esta função recebe um vetor de números em ponto flutuante de precisão simples (float)
 * e seu tamanho, e imprime os elementos do vetor na saída padrão, formatando-os com duas
 * casas decimais e mostrando o índice de cada elemento.
 *
 * @param vetor O vetor de números em ponto flutuante a ser impresso.
 * @param tamanho O tamanho do vetor.
 */
void imprimeVetorFloat(float vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++)
        printf("vetor[%d]: %.2f\n", i + 1, vetor[i]);

    putchar('\n');
}

/**
 * Calcula a matriz transposta de uma matriz de inteiros.
 *
 * Esta função recebe uma matriz de inteiros, seu número de linhas e colunas, e calcula
 * a matriz transposta, ou seja, troca as linhas pelas colunas e imprime a matriz resultante
 * na saída padrão. Se a matriz de entrada não for quadrada, a função imprime uma mensagem de erro.
 *
 * @param matriz A matriz de inteiros a ter a transposta calculada.
 * @param linhas O número de linhas da matriz.
 * @param colunas O número de colunas da matriz.
 */
void matrizTranspostaInt(int matriz[][100], int linhas, int colunas) {

    if (linhas != colunas) {
        printf("Não é possível calcular a transposta da matriz.\n");
        return;
    }
    int matrizT[100][100];

    printf("Matriz:\n");
    imprimeMatrizInt(matriz, linhas, colunas);

    printf("\nMatriz Transposta:\n");

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
 * Redimensiona um vetor de inteiros removendo os elementos iguais a zero.
 *
 * Esta função recebe um vetor de inteiros e seu tamanho, e cria um novo vetor
 * com tamanho reduzido, eliminando os elementos iguais a zero do vetor original.
 *
 * @param vetor O vetor de inteiros a ser redimensionado.
 * @param tamanho O tamanho do vetor original.
 */
void redimensionaVetorInt(int vetor[], int tamanho) {
    int count = 0;

    for (int i = 0; i < tamanho; ++i) {
        if (vetor[i] != 0) {
            count++;
        }
    }

    int novoVetor[count];
    int index = 0;

    for (int i = 0; i < tamanho; ++i) {
        if (vetor[i] != 0) {
            novoVetor[index] = vetor[i];
            index++;
        }
    }
}

/**
 * Encontra o maior elemento em uma matriz de inteiros.
 *
 * Esta função recebe uma matriz de inteiros, seu número de linhas e colunas, e encontra
 * o maior elemento presente na matriz.
 *
 * @param matriz A matriz de inteiros a ser analisada.
 * @param linhas O número de linhas da matriz.
 * @param colunas O número de colunas da matriz.
 * @return O maior elemento encontrado na matriz.
 */
int encontraMaiorElementoMatrizInt(int matriz[][100], int linhas, int colunas) {

    int maior = matriz[0][0];

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
            }
        }
    }

    return maior;
}

/**
 * Encontra o menor elemento em uma matriz de inteiros.
 *
 * Esta função recebe uma matriz de inteiros, seu número de linhas e colunas, e encontra
 * o menor elemento presente na matriz.
 *
 * @param matriz A matriz de inteiros a ser analisada.
 * @param linhas O número de linhas da matriz.
 * @param colunas O número de colunas da matriz.
 * @return O menor elemento encontrado na matriz.
 */
int encontraMenorElementoMatrizInt(int matriz[][100], int linhas, int colunas) {

    int menor = matriz[0][0];

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] < menor) {
                menor = matriz[i][j];
            }
        }
    }
    return menor;
}

/**
 * Inicializa um vetor de inteiros com zeros.
 *
 * Esta função recebe um vetor de inteiros e seu tamanho, e inicializa todos os elementos
 * do vetor com o valor zero.
 *
 * @param s O vetor de inteiros a ser inicializado.
 * @param n O tamanho do vetor.
 */
void inicializaVetorInteiros(int s[], int n) {
    for (int i = 0; i < n; ++i) {
        s[i] = 0;
    }
}

/**
 * Limpa a tela do console.
 *
 * Esta função utiliza o comando do sistema para limpar a tela do console.
 */
void limparTela() {
    system("cls");
}

/**
 * Preenche uma matriz de inteiros a partir da entrada padrão.
 *
 * Esta função recebe o número de linhas e colunas da matriz, aloca memória
 * para a matriz, e preenche os elementos da matriz com valores inseridos
 * pelo usuário na entrada padrão.
 *
 * @param linhas O número de linhas da matriz.
 * @param colunas O número de colunas da matriz.
 * @return Um ponteiro para a matriz preenchida.
 */
int **preencherMatrizInt(int linhas, int colunas) {
    int **matriz = malloc(linhas * sizeof(int *));
    for (int i = 0; i < linhas; i++) {
        matriz[i] = malloc(colunas * sizeof(int));
        for (int j = 0; j < colunas; j++) {
            printf("Digite o valor para a posição [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    return matriz;
}

/**
 * Soma duas matrizes de inteiros.
 *
 * Esta função recebe duas matrizes de inteiros, seus números de linhas e colunas,
 * e realiza a soma das duas matrizes, desde que tenham dimensões compatíveis.
 *
 * @param matriz1 A primeira matriz de inteiros a ser somada.
 * @param matriz2 A segunda matriz de inteiros a ser somada.
 * @param linhas1 O número de linhas da primeira matriz.
 * @param colunas1 O número de colunas da primeira matriz.
 * @param linhas2 O número de linhas da segunda matriz.
 * @param colunas2 O número de colunas da segunda matriz.
 * @return Um ponteiro para a matriz resultante da soma ou NULL se as dimensões não forem compatíveis.
 */
int **somarMatrizInt(int **matriz1, int **matriz2, int linhas1, int colunas1, int linhas2, int colunas2) {
    if (linhas1 != linhas2 || colunas1 != colunas2) {
        printf("As matrizes não possuem dimensões compatíveis para a soma.\n");
        return NULL;
    }

    int **matrizSoma = malloc(linhas1 * sizeof(int *));
    for (int i = 0; i < linhas1; i++) {
        matrizSoma[i] = malloc(colunas1 * sizeof(int));
        for (int j = 0; j < colunas1; j++) {
            matrizSoma[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
    return matrizSoma;
}

/**
 * Multiplica duas matrizes de inteiros.
 *
 * Esta função recebe duas matrizes de inteiros, seus números de linhas e colunas,
 * e realiza a multiplicação das duas matrizes, desde que tenham dimensões compatíveis.
 *
 * @param matriz1 A primeira matriz de inteiros a ser multiplicada.
 * @param matriz2 A segunda matriz de inteiros a ser multiplicada.
 * @param linhas1 O número de linhas da primeira matriz.
 * @param colunas1 O número de colunas da primeira matriz.
 * @param linhas2 O número de linhas da segunda matriz.
 * @param colunas2 O número de colunas da segunda matriz.
 * @return Um ponteiro para a matriz resultante da multiplicação ou NULL se as dimensões não forem compatíveis.
 */
int **multiplicarMatrizInt(int **matriz1, int **matriz2, int linhas1, int colunas1, int linhas2, int colunas2) {
    if (colunas1 != linhas2) {
        printf("As matrizes não possuem dimensões compatíveis para a multiplicação.\n");
        return NULL;
    }

    int **matrizProduto = malloc(linhas1 * sizeof(int *));
    for (int i = 0; i < linhas1; i++) {
        matrizProduto[i] = malloc(colunas2 * sizeof(int));
        for (int j = 0; j < colunas2; j++) {
            matrizProduto[i][j] = 0;
            for (int k = 0; k < colunas1; k++) {
                matrizProduto[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
    return matrizProduto;
}

/**
 * Subtrai duas matrizes de inteiros.
 *
 * Esta função recebe duas matrizes de inteiros, seus números de linhas e colunas,
 * e realiza a subtração das duas matrizes, desde que tenham dimensões compatíveis.
 *
 * @param matriz1 A primeira matriz de inteiros a ser subtraída.
 * @param matriz2 A segunda matriz de inteiros a ser subtraída.
 * @param linhas1 O número de linhas da primeira matriz.
 * @param colunas1 O número de colunas da primeira matriz.
 * @param linhas2 O número de linhas da segunda matriz.
 * @param colunas2 O número de colunas da segunda matriz.
 * @return Um ponteiro para a matriz resultante da subtração ou NULL se as dimensões não forem compatíveis.
 */
int **subtrairMatrizInt(int **matriz1, int **matriz2, int linhas1, int colunas1, int linhas2, int colunas2) {
    if (linhas1 != linhas2 || colunas1 != colunas2) {
        printf("As matrizes não possuem dimensões compatíveis para a subtração.\n");
        return NULL;
    }

    int **matrizSubtracao = malloc(linhas1 * sizeof(int *));
    for (int i = 0; i < linhas1; i++) {
        matrizSubtracao[i] = malloc(colunas1 * sizeof(int));
        for (int j = 0; j < colunas1; j++) {
            matrizSubtracao[i][j] = matriz1[i][j] - matriz2[i][j];
        }
    }
    return matrizSubtracao;
}

/**
 * Calcula a matriz transposta de uma matriz de inteiros.
 *
 * Esta função recebe uma matriz de inteiros, seus números de linhas e colunas,
 * e calcula a matriz transposta.
 *
 * @param matriz A matriz de inteiros a ser transposta.
 * @param linhas O número de linhas da matriz.
 * @param colunas O número de colunas da matriz.
 * @return Um ponteiro para a matriz transposta resultante.
 */
int **matrizTranspostaInt2(int **matriz, int linhas, int colunas) {
    int **matrizTransposta = malloc(colunas * sizeof(int *));
    for (int i = 0; i < colunas; i++) {
        matrizTransposta[i] = malloc(linhas * sizeof(int));
        for (int j = 0; j < linhas; j++) {
            matrizTransposta[i][j] = matriz[j][i];
        }
    }
    return matrizTransposta;
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
int verificaOcorrenciaVetorInt(int sequencia1[], int n1, int sequencia2[], int n2) {
    int count = 0;
    int i, j;
    for (i = 0; i <= n2 - n1; i++) {
        int found = 1;
        for (j = 0; j < n1; j++) {
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