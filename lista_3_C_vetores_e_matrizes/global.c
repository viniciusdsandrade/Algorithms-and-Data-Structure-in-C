#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void linha(int tamanho, char caractere) {

    for (int i = 0; i < tamanho; i++)
        printf("%c", caractere);

    printf("\n");
}

int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

/*
    Consideremos o conjunto das matrizes quadradas de elementos reais. Seja
    M uma matriz de ordem n desse conjunto. Chamamos determinante da matriz M (e
    indicamos por det M) o número que podemos obter operando com os elementos de
    M da seguinte forma:
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

// Funcao que recebe uma matriz quadrada e calcula a sua inversa
//  Função para calcular a matriz inversa
int **calcularInversa(float matriz[][100], int lenght) {
    float adjunta[lenght][lenght];
    float cofator[lenght][lenght];
    float determinante = 0;

    // Calcula a matriz adjunta e o determinante
    for (int i = 0; i < lenght; i++) {
        for (int j = 0; j < lenght; j++) {
            adjunta[i][j] = pow(-1, i + j) * matriz[j][i];
            cofator[i][j] = adjunta[i][j];
        }
    }

    for (int i = 0; i < lenght; i++)
        determinante += matriz[0][i] * cofator[0][i];

    // Verifica se a matriz é inversível (determinante diferente de zero)
    if (determinante == 0) {
        printf("A matriz não é inversível.\n");
        return NULL;
    }

    // Divide a matriz adjunta pelo determinante para obter a matriz inversa
    for (int i = 0; i < lenght; i++) {
        for (int j = 0; j < lenght; j++)
            matriz[i][j] = adjunta[i][j] / determinante;
    }

    return matriz;
}

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

// Recebe a dimensão e imprime a matriz identidade
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

void preencheMatrizInt(int matriz[][100], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("matriz[%d,%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

}

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


void preencheMatrizIntRandom(int matriz[][100], int linhas, int colunas, int limite) {
    srand(time(NULL));

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++)
            matriz[i][j] = rand() % (limite + 1);
    }
}

void preencherMatrizIntRandom2(int **matriz, int linhas, int colunas, int limite) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++)
            matriz[i][j] = rand() % limite;
    }
}

void preencheVetorDoubleRandom(double vetor[], int tamanho, int limite) {
    srand(time(NULL));

    for (int i = 0; i < tamanho; i++)
        vetor[i] = ((double) rand() / RAND_MAX) * limite;
}

double mediaVetorDouble(double vetor[], int n) {

    double soma = 0;

    for (int i = 0; i < n; ++i)
        soma += vetor[i];

    return soma / n;
}

float raizQuadradaDouble(float num) {
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

void preencheVetorIntRandom(int vetor[], int tamanho, int limite) {

    srand(time(NULL));

    for (int i = 0; i < tamanho; ++i)
        vetor[i] = (rand() % (limite + 1));
}

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

// Faça um algoritmo que multiplica uma matriz quadrada por um inteiro n, e retorne a matrizMultiplicacao resultante
int **multiplicaMatrizInt2(int **matriz, int n) {
    int **matrizMultiplicacao = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrizMultiplicacao[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
            matrizMultiplicacao[i][j] = matriz[i][j] * n;
    }
    return matrizMultiplicacao;
}

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

void imprimeVetorFloat(float vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++)
        printf("vetor[%d]: %.2f\n", i + 1, vetor[i]);

    putchar('\n');
}

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

void preencheVetorInt(int vet[], int tamanho) {
    for (int i = 0; i < tamanho; ++i) {
        printf("vetor[%d] = ", i + 1);
        scanf("%d", &vet[i]);
    }
}

void preencheVetorDouble(double vet[], int tamanho) {
    for (int i = 0; i < tamanho; ++i) {
        printf("vetor[%d] = ", i + 1);
        scanf("%lf", &vet[i]);
    }
}

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

void inicializaVetorInteiros(int s[], int n) {
    for (int i = 0; i < n; ++i) {
        s[i] = 0;
    }
}

void limparTela() {
    system("cls");
}

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

void liberarMatrizInt(int **matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

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
