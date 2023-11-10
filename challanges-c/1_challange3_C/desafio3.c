#include <stdio.h>
// #include <stdlib.h> //Função usada para ler documentos de modo automático

#define MAX_LINHAS 50
#define MAX_COLUNAS 50

#define VAZIO 0
#define HUMANO 1
#define ZUMBI 2

void leitorArquivoTxt(
        const char *nomeArquivo,
        int matriz[][MAX_COLUNAS],
        int *numLinhas,
        int *numColunas,
        int *numDias
);
void leituraManualMatriz(int matriz[][MAX_COLUNAS], int numLinhas, int numColunas);
void imprimeMatriz(int matrix[][MAX_COLUNAS], int numLinhas, int numColunas);
void atualizaMatriz(int matrix[][MAX_COLUNAS], int numLinhas, int numColunas);
int contadorVizinhos(int matrix[][MAX_COLUNAS], int linha, int coluna, int numLinhas, int numColunas, int value);
int contadorVizinhosHumanos(int matrix[][MAX_COLUNAS], int linha, int coluna, int numLinhas, int numColunas);
int contadorVizinhosZumbis(int matrix[][MAX_COLUNAS], int linha, int coluna, int numLinhas, int numColunas);

/**
    - MEMBROS DO GRUPO:
    @ALUNO 1: Vinícius dos Santos Andrade  RA: 2760482311026
    @ALUNO 2: Gianlucca Fadiga Rissato     RA: 2760482311014
*/

/**
    O objetivo desse desafio é elaborar um algortimo de detecção de variáveis dentro de uma matriz
    <p> considerando que nessa matriz os vizinhos são considerados como uma matriz circular.
<p>
    <p> A matriz é composta por 3 tipos de variáveis:
    <p> 0 - vazio
    <p> 1 - humano
    <p> 2 - zumbi
<p>
    <p> As regras de negócio são:
    <p> 1- Se X for humano e possuir pelo menos um vizinho zumbi, então X é infectado e se torna um zumbi no dia seguinte;
    <p> 2- Se X for zumbi e possuir dois ou mais vizinhos humanos, ele é caçado e morto pelos humanos;
    <p> 3- Se X for zumbi e não possuir nenhum vizinho humano, ele morre de fome e fica vazio no dia seguinte;
   <p>  4- Se X estiver vazio e possuir exatamente dois vizinhos humanos, independente dos demais vizinhos serem zumbis ou vazio, então um humano nasce em X no dia seguinte.
    <p> 5- Se nenhuma das alternativas anteriores for verdade, então X permanece como está.
<p>
    <p> O programa deve receber como entrada um arquivo texto com a seguinte estrutura:
   <p>  1ª linha: número de linhas e colunas da matriz
   <p>  2ª linha: número de dias que a simulação deve ser executada
   <p>  3ª linha em diante: matriz com o estado inicial da população
<p>
   <p>  Após a leitura dos dados do arquivo, o programa deve imprimir na tela o estado inicial da matriz
    e em seguida deve simular o estado da população para cada dia imprimindo o resultado a cada iteração.
*/

int main(void) {
    int numLinhas, numColunas, numDias;
    int matriz[MAX_LINHAS][MAX_COLUNAS];

    /*
        Leitura da matriz a partir do arquivo
        leitorArquivo("enunciado/teste7.txt", matriz, &numLinhas, &numColunas, &numDias);
        leitorArquivo("enunciado/teste8.txt", matriz, &numLinhas, &numColunas, &numDias);
        leitorArquivoTxt("enunciado/teste9.txt", matriz, &numLinhas, &numColunas, &numDias);
    */

    printf("Digite o numero de linhas e colunas: ");
    scanf("%d %d", &numLinhas, &numColunas);

    printf("Digite o numero de dias: ");
    scanf("%d", &numDias);

    leituraManualMatriz(matriz, numLinhas, numColunas);

    printf("Linhas:  %d\n", numLinhas);
    printf("Colunas: %d\n", numColunas);
    printf("Dias:    %d\n", numDias);

    printf("iteracao 0\n");
    imprimeMatriz(matriz, numLinhas, numColunas);

    for (int k = 1; k < numDias; k++) {
        atualizaMatriz(matriz, numLinhas, numColunas);

        printf("iteracao %d\n", k);
        imprimeMatriz(matriz, numLinhas, numColunas);
    }

    return 0;
}

void leitorArquivoTxt(
        const char *nomeArquivo,
        int matriz[][MAX_COLUNAS],
        int *numLinhas,
        int *numColunas,
        int *numDias
) {
    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fscanf(arquivo, "%d %d\n", numLinhas, numColunas);
    fscanf(arquivo, "%d\n", numDias);

    for (int i = 0; i < *numLinhas; i++) {
        for (int j = 0; j < *numColunas; j++) {
            fscanf(arquivo, "%d ", &matriz[i][j]);
        }
    }

    fclose(arquivo);
}

void leituraManualMatriz(
        int matriz[][MAX_COLUNAS],
        int numLinhas,
        int numColunas
) {
    printf("\nDigite a Matriz:\n");
    for (int i = 0; i < numLinhas; i++) {
        for (int j = 0; j < numColunas; j++) {
            printf("Matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void imprimeMatriz(
        int matrix[][MAX_COLUNAS],
        int linha,
        int coluna
) {
    int i, j;

    for (i = 0; i < linha; i++) {
        printf("[");
        for (j = 0; j < coluna; j++) {
            if (j < coluna - 1) {
                printf("%d  ", matrix[i][j]);
            } else {
                printf("%d", matrix[i][j]);
            }
        }
        printf("]\n");
    }
}

int contadorVizinhos(
        int matrix[][MAX_COLUNAS],
        int linha,
        int coluna,
        int numLinhas,
        int numColunas,
        int value
) {
    int contador = 0;

    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (i == 0 && j == 0) {
                continue;
            }

            int linhaVizinhos = (linha + i + numLinhas) % numLinhas;
            int colunaVizinhos = (coluna + j + numColunas) % numColunas;

            if (matrix[linhaVizinhos][colunaVizinhos] == value) {
                contador++;
            }
        }
    }

    return contador;
}

void atualizaMatriz(
        int matrix[][MAX_COLUNAS],
        int numLinhas,
        int numColunas
) {
    int novaMatriz[MAX_LINHAS][MAX_COLUNAS];

    for (int i = 0; i < numLinhas; i++) {
        for (int j = 0; j < numColunas; j++) {
            int vizinhosHumanos = contadorVizinhos(matrix, i, j, numLinhas, numColunas, HUMANO);
            int vizinhosZumbis = contadorVizinhos(matrix, i, j, numLinhas, numColunas, ZUMBI);

            if (matrix[i][j] == HUMANO) {
                if (vizinhosZumbis >= 2)
                    novaMatriz[i][j] = ZUMBI;
                else
                    novaMatriz[i][j] = HUMANO;
            } else if (matrix[i][j] == ZUMBI) {
                if (vizinhosHumanos >= 2)
                    novaMatriz[i][j] = HUMANO;
                else
                    novaMatriz[i][j] = ZUMBI;
            } else {
                novaMatriz[i][j] = VAZIO;
            }
        }
    }

    for (int i = 0; i < numLinhas; i++) {
        for (int j = 0; j < numColunas; j++) {
            matrix[i][j] = novaMatriz[i][j];
        }
    }
}


int contadorVizinhosHumanos(
        int matrix[][MAX_COLUNAS],
        int linha,
        int coluna,
        int numLinhas,
        int numColunas
) {
    int contador = 0;

    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (i == 0 && j == 0)
                continue;

            int linhaVizinhos = (linha + i + numLinhas) % numLinhas;
            int colunaVizinhos = (coluna + j + numColunas) % numColunas;

            if (matrix[linhaVizinhos][colunaVizinhos] == HUMANO)
                contador++;
        }
    }
    return contador;
}

int contadorVizinhosZumbis(
        int matrix[][MAX_COLUNAS],
        int linha,
        int coluna,
        int numLinhas,
        int numColunas
) {
    int contador = 0;

    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (i == 0 && j == 0)
                continue;

            int linhaVizinhos = (linha + i + numLinhas) % numLinhas;
            int colunaVizinhos = (coluna + j + numColunas) % numColunas;

            if (matrix[linhaVizinhos][colunaVizinhos] == ZUMBI)
                contador++;
        }
    }
    return contador;
}

/*
                    vizinho A
                    if (i == 0 && j == 0)
                        v1 = matriz[numLinhas - 1][numColunas - 1];
                        v2 = matriz[numLinhas - 1][j];
                        v3 = matriz[numLinhas - 1][j + 1];
                        v4 = matriz[i][numColunas - 1];
                        v5 = matriz[i][j + 1];
                        v6 = matriz[i + 1][numColunas - 1];
                        v7 = matriz[i + 1][j];
                        v8 = matriz[i + 1][j + 1];

                    vizinho B
                    if (i == 0 && j > 0 && j < numColunas - 1)
                        v1 = matriz[numLinhas - 1][j - 1];
                        v2 = matriz[numLinhas - 1][j];
                        v3 = matriz[numLinhas - 1][j + 1];
                        v4 = matriz[i][j - 1];
                        v5 = matriz[i][j + 1];
                        v6 = matriz[i + 1][j - 1];
                        v7 = matriz[i + 1][j];
                        v8 = matriz[i + 1][j + 1];

                    vizinho C
                    if (i == 0 && j == numColunas - 1)
                        v1 = matriz[numLinhas - 1][j - 1];
                        v2 = matriz[numLinhas - 1][j];
                        v3 = matriz[numLinhas - 1][0];
                        v4 = matriz[i][j - 1];
                        v5 = matriz[i][0];
                        v6 = matriz[i + 1][j - 1];
                        v7 = matriz[i + 1][j];
                        v8 = matriz[i + 1][0];

                    vizinho D
                    if (i > 0 && i < numLinhas - 1 && j == 0)
                        v1 = matriz[i - 1][numColunas - 1];
                        v2 = matriz[i - 1][j];
                        v3 = matriz[i - 1][j + 1];
                        v4 = matriz[i][numColunas - 1];
                        v5 = matriz[i][j + 1];
                        v6 = matriz[i + 1][numColunas - 1];
                        v7 = matriz[i + 1][j];
                        v8 = matriz[i + 1][j + 1];

                    vizinho E
                    if (i > 0 && i < numLinhas - 1 && j > 0 && j < numColunas - 1)
                        v1 = matriz[i - 1][j - 1];
                        v2 = matriz[i - 1][j];
                        v3 = matriz[i - 1][j + 1];
                        v4 = matriz[i][j - 1];
                        v5 = matriz[i][j + 1];
                        v6 = matriz[i + 1][j - 1];
                        v7 = matriz[i + 1][j];
                        v8 = matriz[i + 1][j + 1];

                    vizinho F
                    if (i > 0 && i < numLinhas - 1 && j == numColunas - 1)
                        v1 = matriz[i - 1][j - 1];
                        v2 = matriz[i - 1][j];
                        v3 = matriz[i - 1][0];
                        v4 = matriz[i][j - 1];
                        v5 = matriz[i][0];
                        v6 = matriz[i + 1][j - 1];
                        v7 = matriz[i + 1][j];
                        v8 = matriz[i + 1][0];

                    vizinho G
                    if (i == numLinhas - 1 && j == 0)
                        v1 = matriz[i - 1][numColunas - 1];
                        v2 = matriz[i - 1][j];
                        v3 = matriz[i - 1][j + 1];
                        v4 = matriz[i][numColunas - 1];
                        v5 = matriz[i][j + 1];
                        v6 = matriz[0][numColunas - 1];
                        v7 = matriz[0][j];
                        v8 = matriz[0][j + 1];

                    vizinho H
                    if (i == numLinhas - 1 && j > 0 && j < numColunas - 1)
                        v1 = matriz[i - 1][j - 1];
                        v2 = matriz[i - 1][j];
                        v3 = matriz[i - 1][j + 1];
                        v4 = matriz[i][j - 1];
                        v5 = matriz[i][j + 1];
                        v6 = matriz[0][j - 1];
                        v7 = matriz[0][j];
                        v8 = matriz[0][j + 1];

                    vizinho I
                    if (i == numDias - 1 && j == numColunas - 1)
                        v1 = matriz[i - 1][j - 1];
                        v2 = matriz[i - 1][j];
                        v3 = matriz[i - 1][0];
                        v4 = matriz[i][j - 1];
                        v5 = matriz[i][0];
                        v6 = matriz[0][j - 1];
                        v7 = matriz[0][j];
                        v8 = matriz[0][0];
*/