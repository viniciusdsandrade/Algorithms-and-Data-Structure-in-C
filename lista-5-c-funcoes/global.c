#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX_DIMENSION 30

/**
 * Multiplica duas matrizes quadradas de dimensão 'n' e armazena o resultado em uma terceira matriz.
 *
 * Esta função recebe duas matrizes quadradas 'mat1' e 'mat2' de dimensão 'n' e calcula o produto
 * de matriz 'mat1' x 'mat2', armazenando o resultado na matriz 'matRes'. Ela utiliza loops aninhados
 * para realizar a multiplicação de matrizes.
 *
 * @param mat1 A primeira matriz de entrada.
 * @param mat2 A segunda matriz de entrada.
 * @param matRes A matriz onde o resultado da multiplicação será armazenado.
 * @param n A dimensão das matrizes e o número de linhas/colunas.
 */
void multiplicaMatriz(
        double mat1[MAX_DIMENSION][MAX_DIMENSION],
        double mat2[MAX_DIMENSION][MAX_DIMENSION],
        double matRes[MAX_DIMENSION][MAX_DIMENSION],
        int n
) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matRes[i][j] = 0;
            for (int k = 0; k < n; k++) {
                matRes[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

/**
 * Soma duas matrizes de dimensão 'n' e armazena o resultado em uma terceira matriz.
 *
 * Esta função recebe duas matrizes 'mat1' e 'mat2' de dimensão 'n' e calcula a soma
 * 'mat1' + 'mat2', armazenando o resultado na matriz 'matRes'. Ela utiliza loops aninhados
 * para realizar a adicao de matrizes.
 *
 * @param mat1 A primeira matriz de entrada.
 * @param mat2 A segunda matriz de entrada.
 * @param matRes A matriz onde o resultado da adicao será armazenado.
 * @param n A dimensão das matrizes e o número de linhas/colunas.
 */
void somaMatriz(
        double mat1[MAX_DIMENSION][MAX_DIMENSION],
        double mat2[MAX_DIMENSION][MAX_DIMENSION],
        double matRes[MAX_DIMENSION][MAX_DIMENSION],
        int n
) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matRes[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

/**
 * Lê valores inteiros de um vetor de tamanho 'tam' a partir da entrada padrão.
 *
 * Esta função lê valores inteiros do usuário e os armazena em um vetor 'vet' de tamanho 'tam'.
 *
 * @param vet O vetor onde os valores serão armazenados.
 * @param tam O tamanho do vetor 'vet'.
 */
void leVetor(int vet[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("Digite numero: ");
        scanf("%d", &vet[i]);
    }
}

/**
 * Imprime os elementos de uma matriz com 'linha' linhas e 'coluna' colunas.
 *
 * Esta função imprime os elementos de uma matriz 'mat' com 'linha' linhas e 'coluna' colunas.
 * Os elementos são impressos em formato de matriz.
 *
 * @param mat A matriz a ser impressa.
 * @param linha O número de linhas da matriz.
 * @param coluna O número de colunas da matriz.
 */
void imprimeMatriz(
        int mat[MAX_DIMENSION][MAX_DIMENSION],
        int linha,
        int coluna
) {
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

/**
 * Imprime os elementos de um vetor de tamanho 'tam'.
 *
 * Esta função imprime os elementos de um vetor 'vet' de tamanho 'tam'. Os elementos são
 * impressos no formato "vet[i] = valor".
 *
 * @param vet O vetor a ser impresso.
 * @param tam O tamanho do vetor 'vet'.
 */
void imprimeVetor(int vet[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("vet[%d] = %d", i, vet[i]);
    }
}

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
 * Calcula a potência de um número inteiro.
 *
 * Esta função calcula a potência de um número inteiro 'a' elevado a um expoente
 * inteiro 'b'. Ela trata de maneira adequada os casos em que 'b' é 0 (retorna 1),
 * 'b' é negativo (calcula a potência inversa) e 'b' é positivo (usando um loop).
 *
 * @param a O número base.
 * @param b O expoente.
 * @return O resultado da operação 'a' elevado a 'b'.
 */
int pot(int a, int b) {
    if (b == 0) return 1;
    if (b < 0) return 1 / pot(a, -b);

    int result = a;
    for (int i = 1; i < b; i++)
        result = result * a;

    return result;
}

/**
 * Calcula o fatorial de um número inteiro não negativo.
 *
 * Esta função calcula o fatorial de um número inteiro 'n'. Ela trata de maneira
 * adequada o caso em que 'n' é negativo (retorna -1 como erro) e o caso em que
 * 'n' é igual a 0 (retorna 1, pois o fatorial de 0 é 1). Usa recursao para calcular
 * o fatorial de 'n'.
 *
 * @param n O número para calcular o fatorial.
 * @return O fatorial de 'n' ou -1 em caso de erro.
 */
long fat(long n) {
    if (n < 0)
        return -1;

    if (n == 0)
        return 1;

    return n * fat(n - 1);
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
double calcularSomaQuadradosDasDiferencas(
        const double numeros[],
        int quantidade,
        double media
) {
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
 * de dispersao que indica o quanto os valores do conjunto se desviam da média.
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

    printf("Media: %.2lf\n", media);
    printf("Variancia amostral: %.2lf\n", varianciaAmostral);

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
    if (dimension > MAX_DIMENSION) {
        printf("Erro: A dimensão da matriz excede o máximo permitido.\n");
        return;
    }

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
                printf(" "); // Espaço entre os elementos
            }
        }
        printf("]\n");
    }
}

/**
 * Calcula a matriz transposta de uma matriz quadrada.
 *
 * @param inputMatrix A matriz de entrada.
 * @param resultMatrix A matriz que contera a transposta após a execucao.
 * @param dim A dimensão da matriz (número de linhas e colunas).
 */
void transpose(
        int inputMatrix[MAX_DIMENSION][MAX_DIMENSION],
        int resultMatrix[MAX_DIMENSION][MAX_DIMENSION],
        int dim
) {
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            resultMatrix[i][j] = inputMatrix[j][i];
        }
    }
}

/**
 * Calcula a matriz transposta de uma matriz quadrada.
 *
 * @param inputMatrix A matriz de entrada.
 * @param resultMatrix A matriz que contera a transposta após a execucao.
 * @param dim A dimensão da matriz (número de linhas e colunas).
 */
void multiplySquareMatrix(
        int matrixA[MAX_DIMENSION][MAX_DIMENSION],
        int matrixB[MAX_DIMENSION][MAX_DIMENSION],
        int resultMatrix[MAX_DIMENSION][MAX_DIMENSION],
        int dim
) {
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < dim; ++k) {
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
int calculaSoma(
        int matriz[30][30],
        int tamanho,
        int linha,
        int indice
) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        if (linha)
            soma += matriz[indice][i];
        else
            soma += matriz[i][indice];
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
 * Verifica se um número pode ser inserido em uma linha especifica do tabuleiro Sudoku.
 *
 * @param linha O índice da linha que será verificada.
 * @param numero O número a ser inserido.
 * @param tabuleiro O tabuleiro Sudoku.
 * @return Verdadeiro se o número puder ser inserido na linha; caso contrário, falso.
 */
bool verificaLinha(
        int linha,
        int numero,
        int tabuleiro[9][9]
) {
    for (int coluna = 0; coluna < 9; coluna++) {
        if (tabuleiro[linha][coluna] == numero) {
            return false; // Número já existe na linha
        }
    }
    return true;
}

/**
 * Verifica se um número pode ser inserido em uma coluna especifica do tabuleiro Sudoku.
 *
 * @param coluna O índice da coluna que será verificada.
 * @param numero O número a ser inserido.
 * @param tabuleiro O tabuleiro Sudoku.
 * @return Verdadeiro se o número puder ser inserido na coluna; caso contrário, falso.
 */
bool verificaColuna(
        int coluna,
        int numero,
        int tabuleiro[9][9]
) {
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
bool verificaQuadrante(
        int linha,
        int coluna,
        int numero,
        int tabuleiro[9][9]
) {
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
void cidadesComEntradaSemSaida(
        int mat[30][30],
        int n,
        int resposta[]
) {
    for (int i = 0; i < n; i++) {
        resposta[i] = 1; // Inicializa como 1, ou seja, assume que a cidade i tem entrada.

        for (int j = 0; j < n; j++) {
            if (mat[j][i] == 1) {
                resposta[i] = 0; // A cidade i tem uma estrada de entrada, então não atende ao criterio.
                break;
            }
        }

        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1) {
                resposta[i] = 1; // A cidade i tem uma estrada de saída, atende ao criterio.
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
void cidadesComSaidaSemEntrada(
        int mat[30][30],
        int n,
        int resposta[]
) {
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
                resposta[i] = 1; // A cidade i tem uma estrada de entrada, atende ao criterio.
                break;
            }
        }
    }
}