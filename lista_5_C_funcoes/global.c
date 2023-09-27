#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <malloc.h>
#include "global.h"

#define MAX_DIMENSION 30

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
 * @param a  O número inteiro a ser elevado à potência.
 * @param b  O expoente inteiro.
 * @return O resultado da operação 'a' elevado a 'b'.
 *
 * Exemplo de uso:
 * int resultado = pot(2, 3); // Calcula 2 elevado a 3 (2^3)
 */
int pot(int a, int b) {
    int p = 1;
    for (int i = 0; i < b; i++) {
        p *= a;
    }
    return p;
}

/**
 * Verifica se dois números são amigáveis.
 *
 * Esta função verifica se dois números inteiros 'a' e 'b' são amigáveis. Dois
 * números são considerados amigáveis se a soma dos divisores próprios de 'a' é
 * igual a 'b' e a soma dos divisores próprios de 'b' é igual a 'a'.
 *
 * @param a Um número inteiro.
 * @param b Outro número inteiro para comparar com 'a'.
 * @return 'true' se os números forem amigáveis, 'false' caso contrário.
 *
 * Exemplo de uso:
 * bool resultado = amigos(220, 284); // Verifica se 220 e 284 são amigáveis
 */
bool amigos(int a, int b) {
    int somaDivisoresA = 0, somaDivisoresB = 0;
    for (int i = 1; i < a; i++) {
        if (a % i == 0) somaDivisoresA += i;
        if (b % i == 0) somaDivisoresB += i;
    }
    return somaDivisoresA == b &&
           somaDivisoresB == a;
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
double media(const double pDouble[], int qtd) {
    double soma = 0;
    for (int i = 0; i < qtd; i++) {
        soma += pDouble[i];
    }
    return soma / qtd;
}

/**
 * Calcula a média aritmética de um conjunto de números.
 *
 * Esta função calcula a média aritmética de um conjunto de números representados
 * pelo array 'numeros' com 'quantidade' elementos.
 *
 * @param numeros Um array contendo os números para os quais deseja-se calcular a média.
 * @param quantidade A quantidade de elementos no array 'numeros'.
 * @return A média aritmética dos números no array 'numeros'.
 */
double calcularMedia(const double numeros[], int quantidade) {
    double soma = 0;
    for (int i = 0; i < quantidade; i++) {
        soma += numeros[i];
    }
    return soma / quantidade;
}

/**
 * Calcula a soma dos quadrados das diferenças entre cada número e a média.
 *
 * Esta função calcula a soma dos quadrados das diferenças entre cada número no array
 * 'numeros' e a média 'media' fornecida, com base na quantidade de elementos 'quantidade'.
 *
 * @param numeros Um array contendo os números para os quais deseja-se calcular a soma dos quadrados das diferenças.
 * @param quantidade A quantidade de elementos no array 'numeros'.
 * @param media A média dos números no array 'numeros'.
 * @return A soma dos quadrados das diferenças entre cada número e a média.
 */
double calcularSomaQuadradosDasDiferencas(const double numeros[],
                                          int quantidade,
                                          double media) {
    double somaQuadrados = 0;
    for (int i = 0; i < quantidade; i++) {
        double diferenca = numeros[i] - media;
        somaQuadrados += diferenca * diferenca;
    }
    return somaQuadrados;
}

/**
 * Calcula o desvio padrão amostral de um conjunto de números.
 *
 * Esta função calcula o desvio padrão amostral de um conjunto de números representados
 * pelo array 'numeros' com 'quantidade' elementos. O desvio padrão amostral é uma medida
 * de dispersão que indica o quanto os valores do conjunto se desviam da média.
 *
 * @param numeros Um array contendo os números para os quais deseja-se calcular o desvio padrão amostral.
 * @param quantidade A quantidade de elementos no array 'numeros'.
 * @return O desvio padrão amostral dos números no array 'numeros'. Retorna 0 se houver menos de dois valores.
 * @note O desvio padrão amostral não é definido para menos de dois valores.
 */
double desvioPadrao(double numeros[], int quantidade) {
    if (quantidade <= 1) {
        printf("O desvio padrão amostral não é definido para menos de dois valores.\n");
        return 0;
    }

    double media = calcularMedia(numeros, quantidade);
    double somaQuadradosDasDiferencas = calcularSomaQuadradosDasDiferencas(numeros, quantidade, media);
    double varianciaAmostral = somaQuadradosDasDiferencas / (quantidade - 1);
    double desvioPadraoAmostral = sqrt(varianciaAmostral);

    printf("Média: %.2lf\n", media);
    printf("Variância amostral: %.2lf\n", varianciaAmostral);

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
 * Lê os elementos de uma matriz quadrada da entrada padrão.
 *
 * @param matrix A matriz a ser preenchida com os elementos lidos.
 * @param dimension A dimensão da matriz (número de linhas e colunas).
 */
void readMatrix(int matrix[MAX_DIMENSION][MAX_DIMENSION], int dimension) {
    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

/**
 * Imprime os elementos de uma matriz quadrada.
 *
 * @param matrix A matriz a ser impressa.
 * @param dimension A dimensão da matriz (número de linhas e colunas).
 */
void printMatrix(int matrix[MAX_DIMENSION][MAX_DIMENSION], int dimension) {
    for (int i = 0; i < dimension; ++i) {
        printf("[");
        for (int j = 0; j < dimension; ++j) {
            printf("%d", matrix[i][j]);
            if (j < dimension - 1) {
                printf("\t"); // Espaço entre os elementos
            }
        }
        printf("]\n");
    }
}

/**
 * Calcula a matriz transposta de uma matriz quadrada.
 *
 * @param inputMatrix A matriz de entrada.
 * @param resultMatrix A matriz que conterá a transposta após a execução.
 * @param dimension A dimensão da matriz (número de linhas e colunas).
 */
void transpose(int inputMatrix[MAX_DIMENSION][MAX_DIMENSION],
               int resultMatrix[MAX_DIMENSION][MAX_DIMENSION],
               int dimension) {
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            resultMatrix[i][j] = inputMatrix[j][i];
        }
    }
}

/**
 * Calcula a matriz transposta de uma matriz quadrada.
 *
 * @param inputMatrix A matriz de entrada.
 * @param resultMatrix A matriz que conterá a transposta após a execução.
 * @param dimension A dimensão da matriz (número de linhas e colunas).
 */
void multiplySquareMatrix(int matrixA[MAX_DIMENSION][MAX_DIMENSION],
                          int matrixB[MAX_DIMENSION][MAX_DIMENSION],
                          int resultMatrix[MAX_DIMENSION][MAX_DIMENSION],
                          int dimension) {
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < dimension; ++k) {
                resultMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
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
int isSumSquare(int a, int b, int n) {
    return (a * a + b * b == n) ? 1 : 0;
}

/**
 * Verifica se um inteiro é um número pitagórico.
 *
 * @param n Inteiro a ser verificado.
 * @return Verdadeiro se n for um número pitagórico, falso caso contrário.
 */
bool pitagorico(int n) {
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            if (isSumSquare(a, b, n)) {
                return true;
            }
        }
    }
    return false; // Se nenhum par de a e b satisfizer a^2 + b^2 = n, retorna 0
}

/**
 * Encontra a menor base b tal que b^k = n.
 *
 * @param n Inteiro alvo.
 * @return A menor base b possível para a qual b^k = n.
 */
int menor_base_log(int n) {
    if (n <= 1) {
        return n;
    }

    int menor_base = n;

    while (n % 2 == 0) {
        n = n / 2;
        menor_base = 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            n = n / i;
            menor_base = i;
        }
    }

    return menor_base;
}

/**
 * Calcula a soma de uma linha ou coluna de uma matriz.
 *
 * @param matrix A matriz para a qual a soma será calculada.
 * @param size O tamanho da matriz (número de linhas e colunas).
 * @param isRow Indica se a soma será calculada para uma linha (1) ou coluna (0).
 * @param index O índice da linha ou coluna para o qual a soma será calculada.
 * @return A soma da linha ou coluna especificada na matriz.
 */
int calculaSoma(int matriz[30][30], int tamanho, int linha, int indice) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        if (linha) {
            soma += matriz[indice][i];
        } else {
            soma += matriz[i][indice];
        }
    }
    return soma;
}

/**
 * Verifica se uma matriz é um "quadrado mágico".
 *
 * Um "quadrado mágico" é uma matriz quadrada na qual a soma de cada linha, coluna e ambas as diagonais
 * é a mesma.
 *
 * @param matrix A matriz a ser verificada.
 * @param size O tamanho da matriz quadrada (número de linhas e colunas).
 * @return Verdadeiro se a matriz for um "quadrado mágico"; caso contrário, falso.
 */
bool isMagico(int matriz[30][30], int tamanho) {
    int soma = calculaSoma(matriz, tamanho, 1, 0); // Calcula a soma da primeira linha
    int diagonalPrincipal = 0, diagonalSecundaria = 0;

    for (int i = 0; i < tamanho; i++) {
        int somaLinha = calculaSoma(matriz, tamanho, 1, i);
        int somaColuna = calculaSoma(matriz, tamanho, 0, i);

        diagonalPrincipal += matriz[i][i];
        diagonalSecundaria += matriz[i][tamanho - i - 1];

        if (somaLinha != soma || somaColuna != soma) {
            return false; // Se alguma linha ou coluna não tiver a soma correta, não é um quadrado mágico
        }
    }

    return (diagonalPrincipal == soma && diagonalSecundaria == soma);
}

/**
 * Verifica se um número pode ser inserido em uma linha específica do tabuleiro Sudoku.
 *
 * @param linha O índice da linha que será verificada.
 * @param numero O número a ser inserido.
 * @param tabuleiro O tabuleiro Sudoku.
 * @return Verdadeiro se o número puder ser inserido na linha; caso contrário, falso.
 */
bool verificaLinha(int linha, int numero, int tabuleiro[9][9]) {
    for (int coluna = 0; coluna < 9; coluna++) {
        if (tabuleiro[linha][coluna] == numero) {
            return false; // Número já existe na linha
        }
    }
    return true;
}

/**
 * Verifica se um número pode ser inserido em uma coluna específica do tabuleiro Sudoku.
 *
 * @param coluna O índice da coluna que será verificada.
 * @param numero O número a ser inserido.
 * @param tabuleiro O tabuleiro Sudoku.
 * @return Verdadeiro se o número puder ser inserido na coluna; caso contrário, falso.
 */
bool verificaColuna(int coluna, int numero, int tabuleiro[9][9]) {
    for (int linha = 0; linha < 9; linha++) {
        if (tabuleiro[linha][coluna] == numero) {
            return false; // Número já existe na coluna
        }
    }
    return true;
}

/**
 * Verifica se um número pode ser inserido em um quadrante específico do tabuleiro Sudoku.
 *
 * @param linha O índice da linha na qual o número está sendo inserido.
 * @param coluna O índice da coluna na qual o número está sendo inserido.
 * @param numero O número a ser inserido.
 * @param tabuleiro O tabuleiro Sudoku.
 * @return Verdadeiro se o número puder ser inserido no quadrante; caso contrário, falso.
 */
bool verificaQuadrante(int linha, int coluna, int numero, int tabuleiro[9][9]) {
    int linhaInicial = (linha / 3) * 3;
    int colunaInicial = (coluna / 3) * 3;

    for (int i = linhaInicial; i < linhaInicial + 3; i++) {
        for (int j = colunaInicial; j < colunaInicial + 3; j++) {
            if (tabuleiro[i][j] == numero) {
                return false; // Número já existe no quadrante
            }
        }
    }
    return true;
}

/**
 * Realiza a multiplicação de duas matrizes quadradas e armazena o resultado em uma terceira matriz.
 *
 * Esta função recebe duas matrizes quadradas de dimensão 'n x n', mat1 e mat2, e calcula o produto das
 * duas matrizes, armazenando o resultado na matriz matRes.
 *
 * @param mat1 A primeira matriz quadrada de entrada a ser multiplicada.
 * @param mat2 A segunda matriz quadrada de entrada a ser multiplicada.
 * @param matRes A matriz onde o resultado da multiplicação será armazenado.
 * @param n A dimensão das matrizes quadradas (número de linhas e colunas).
 */
void multiplica(double mat1[30][30], double mat2[30][30], double matRes[30][30], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matRes[i][j] = 0; // Inicializa o elemento da matriz resultante como 0.
            for (int k = 0; k < n; k++) {
                matRes[i][j] += mat1[i][k] * mat2[k][j]; // Calcula o produto e acumula na matriz resultante.
            }
        }
    }
}

/**
 * Determina as cidades com entrada e sem saída.
 *
 * Esta função recebe como parâmetros uma matriz quadrada 'mat' indicando as estradas entre as cidades,
 * um inteiro 'n' correspondendo às dimensões da matriz e um vetor 'resposta' de tamanho 'n'.
 * O vetor 'resposta' é preenchido de tal forma que resposta[i] recebe 1 se a cidade i satisfizer a propriedade
 * de ter entrada e não ter saída, caso contrário, resposta[i] recebe 0.
 *
 * @param mat A matriz representando as estradas entre as cidades.
 * @param n O número de cidades.
 * @param resposta O vetor de resposta.
 */
void cidadesComEntradaSemSaida(int mat[30][30], int n, int resposta[]) {
    for (int i = 0; i < n; i++) {
        resposta[i] = 1; // Inicializa como 1, ou seja, assume que a cidade i tem entrada.

        for (int j = 0; j < n; j++) {
            if (mat[j][i] == 1) {
                resposta[i] = 0; // A cidade i tem uma estrada de entrada, então não atende ao critério.
                break;
            }
        }

        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1) {
                resposta[i] = 1; // A cidade i tem uma estrada de saída, atende ao critério.
                break;
            }
        }
    }
}

/**
 * Determina as cidades com saída mas sem entrada.
 *
 * Esta função recebe como parâmetros uma matriz quadrada 'mat' indicando as estradas entre as cidades,
 * um inteiro 'n' correspondendo às dimensões da matriz e um vetor 'resposta' de tamanho 'n'.
 * O vetor 'resposta' é preenchido de tal forma que resposta[i] recebe 1 se a cidade i satisfizer a propriedade
 * de ter saída mas não ter entrada, caso contrário, resposta[i] recebe 0.
 *
 * @param mat A matriz representando as estradas entre as cidades.
 * @param n O número de cidades.
 * @param resposta O vetor de resposta.
 */
void cidadesComSaidaSemEntrada(int mat[30][30], int n, int resposta[]) {
    for (int i = 0; i < n; i++) {
        resposta[i] = 1; // Inicializa como 1, ou seja, assume que a cidade i tem saída.

        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1) {
                resposta[i] = 0; // A cidade i tem uma estrada de saída, então não atende ao critério.
                break;
            }
        }

        for (int j = 0; j < n; j++) {
            if (mat[j][i] == 1) {
                resposta[i] = 1; // A cidade i tem uma estrada de entrada, atende ao critério.
                break;
            }
        }
    }
}