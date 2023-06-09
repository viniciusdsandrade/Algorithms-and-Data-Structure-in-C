#include <stdio.h>
// #include <stdlib.h> //Função usada para ler documentos de modo automático

#define MAX_LINHAS 50  // Definindo o tamanho máximo de linhas
#define MAX_COLUNAS 50 // Definindo o tamanho máximo de colunas

void leitorArquivo(const char *nomeArquivo, int matriz[][MAX_COLUNAS], int *numLinhas, int *numColunas, int *numDias);
void leituraManualMatriz(int matriz[][MAX_COLUNAS], int numLinhas, int numColunas);
void imprimeMatriz(int matrix[][MAX_COLUNAS], int linha, int coluna);
void atualizaMatriz(int matrix[][MAX_COLUNAS], int numLinhas, int numColunas);
int contadorVizinhosHumanos(int matrix[][MAX_COLUNAS], int linha, int coluna, int numLinhas, int numColunas);
int contadorVizinhosZumbis(int matrix[][MAX_COLUNAS], int linha, int coluna, int numLinhas, int numColunas);

/*
    MEMBROS DO GRUPO:
    ALUNO 1: Vinícius dos Santos Andrade  RA: 2760482311026
    ALUNO 2:                              RA:
    ALUNO 3:                              RA:
    ALUNO 4:                              RA:
*/

/*
    O objetivo desse desafio é elaborar um algortimo de detecção de variáveis dentro de uma matriz
    considerando que nessa matriz os vizinhos são considerados como uma matriz circular.

    A matriz é composta por 3 tipos de variáveis:
    0 - vazio
    1 - humano
    2 - zumbi

    As regras de negócio são:
    1- Se X for humano e possuir pelo menos um vizinho zumbi, então X é infectado e se torna um zumbi no dia seguinte;
    2- Se X for zumbi e possuir dois ou mais vizinhos humanos, ele é caçado e morto pelos humanos;
    3- Se X for zumbi e não possuir nenhum vizinho humano, ele morre de fome e fica vazio no dia seguinte;
    4- Se X estiver vazio e possuir exatamente dois vizinhos humanos, independente dos demais vizinhos serem zumbis ou vazio, então um humano nasce em X no dia seguinte.
    5- Se nenhuma das alternativas anteriores for verdade, então X permanece como está.

    O programa deve receber como entrada um arquivo texto com a seguinte estrutura:
    1ª linha: número de linhas e colunas da matriz
    2ª linha: número de dias que a simulação deve ser executada
    3ª linha em diante: matriz com o estado inicial da população

    Após a leitura dos dados do arquivo, o programa deve imprimir na tela o estado inicial da matriz
    e em seguida deve simular o estado da população para cada dia imprimindo o resultado a cada iteração.
*/

int main(void)
{
    // Definindo variáveis globais
    int numLinhas, numColunas, numDias;
    int matriz[MAX_LINHAS][MAX_COLUNAS];

    /*
        Leitura da matriz a partir do arquivo
        leitorArquivo("enunciado/teste7.txt", matriz, &numLinhas, &numColunas, &numDias); //
        leitorArquivo("enunciado/teste8.txt", matriz, &numLinhas, &numColunas, &numDias);
        leitorArquivo("enunciado/teste9.txt", matriz, &numLinhas, &numColunas, &numDias);
    */

    // digitador das variaveis de entrada manualmente
    printf("Digite o numero de linhas e colunas: ");
    scanf("%d %d", &numLinhas, &numColunas);

    printf("Digite o numero de dias: ");
    scanf("%d", &numDias);

    // Leitura manual da matriz
    leituraManualMatriz(matriz, numLinhas, numColunas);

    // Impressão dos dados
    printf("Linhas:  %d\n", numLinhas);
    printf("Colunas: %d\n", numColunas);
    printf("Dias:    %d\n", numDias);

    // Imprime o estado inicial
    printf("iteracao 0\n");
    imprimeMatriz(matriz, numLinhas, numColunas);

    // Simula o estado da população para cada dia
    for (int k = 1; k < numDias; k++)
    {
        atualizaMatriz(matriz, numLinhas, numColunas);

        // Imprime o estado atual
        printf("iteracao %d\n", k);
        imprimeMatriz(matriz, numLinhas, numColunas);
    }

    return 0;
}

// Função para leitura manual da matriz
void leituraManualMatriz(int matriz[][MAX_COLUNAS], int numLinhas, int numColunas)
{
    printf("\nDigite a Matriz:\n");
    for (int i = 0; i < numLinhas; i++)
    {
        for (int j = 0; j < numColunas; j++)
        {
            printf("Matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

// Função para leitura da matriz a partir de um arquivo
void leitorArquivo(const char *nomeArquivo, int matriz[][MAX_COLUNAS], int *numLinhas, int *numColunas, int *numDias)
{
    // Abertura do arquivo
    FILE *arquivo = fopen(nomeArquivo, "r");

    // Verificação da abertura do arquivo
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Leitura da primeira linha do arquivo
    fscanf(arquivo, "%d %d\n", numLinhas, numColunas);
    fscanf(arquivo, "%d\n", numDias);

    // Leitura dos elementos da matriz
    for (int i = 0; i < *numLinhas; i++)
    {
        for (int j = 0; j < *numColunas; j++)
        {
            fscanf(arquivo, "%d ", &matriz[i][j]);
        }
    }

    // Fechamento do arquivo
    fclose(arquivo);
}

// Função para imprimir o estado atual da matriz
void imprimeMatriz(int matrix[][MAX_COLUNAS], int linha, int coluna)
{
    int i, j;

    for (i = 0; i < linha; i++)
    {
        printf("[");
        for (j = 0; j < coluna; j++)
        {
            if (j < coluna - 1)
            {
                printf("%d  ", matrix[i][j]);
            }
            else
            {
                printf("%d", matrix[i][j]);
            }
        }
        printf("]\n");
    }
}

// Função para contar o número de vizinhos humanos
int contadorVizinhosHumanos(int matrix[][MAX_COLUNAS], int linha, int coluna, int numLinhas, int numColunas)
{
    int contador = 0;

    // Verifica os vizinhos em volta de X
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if (i == 0 && j == 0)
                continue; // Pula a posição atual X

            // Calcula a posição do vizinho considerando ser uma matriz circular
            int linhaVizinhos = (linha + i + numLinhas) % numLinhas;
            int colunaVizinhos = (coluna + j + numColunas) % numColunas;

            // Verifica se o vizinho é humano
            if (matrix[linhaVizinhos][colunaVizinhos] == 1)
                contador++;
        }
    }
    return contador;
}

// Função para contar o número de vizinhos zumbi
int contadorVizinhosZumbis(int matrix[][MAX_COLUNAS], int linha, int coluna, int numLinhas, int numColunas)
{
    int contador = 0;

    // Verifica os vizinhos em volta de X
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if (i == 0 && j == 0)
                continue; // Pula a posição atual X

            // Calcula a posição do vizinho considerando ser uma matriz circular
            int linhaVizinhos = (linha + i + numLinhas) % numLinhas;
            int colunaVizinhos = (coluna + j + numColunas) % numColunas;

            // Verifica se o vizinho é humano
            if (matrix[linhaVizinhos][colunaVizinhos] == 2)
                contador++;
        }
    }
    return contador;
}

// Função para atualizar o estado da matriz de acordo com as regras de negócio
void atualizaMatriz(int matrix[][MAX_COLUNAS], int numLinhas, int numColunas)
{
    int matrizAux[numLinhas][numColunas];

    // Copia o estado atual da matriz para uma nova matriz
    for (int i = 0; i < numLinhas; i++)
    {
        for (int j = 0; j < numColunas; j++)
        {
            matrizAux[i][j] = matrix[i][j];
        }
    }

    // Atualiza o estado de cada posição na nova matriz
    for (int i = 0; i < numLinhas; i++)
    {
        for (int j = 0; j < numColunas; j++)
        {
            int qtdVizinhosHumanos = contadorVizinhosHumanos(matrix, i, j, numLinhas, numColunas); // Conta o número de vizinhos humanos
            int qtdVizinhosZumbis = contadorVizinhosZumbis(matrix, i, j, numLinhas, numColunas);   // Conta o número de vizinhos zumbis

            //  Se X estiver vazio e possuir exatamente dois vizinhos humanos, independente dos demais vizinhos serem zumbis ou vazio, então um humano nasce em X no dia seguinte.
            if (matrix[i][j] == 0)
            {
                // Se estiver vazio e possuir exatamente dois vizinhos humanos, nasce um humano
                if (qtdVizinhosHumanos == 2)
                    matrizAux[i][j] = 1;
                // Se nenhuma das alternativas anteriores for verdade, permanece como está
                else
                    matrizAux[i][j] = matrix[i][j];
            }
            // Se X for humano e possuir pelo menos um vizinho zumbi, então X é infectado e se torna um zumbi no dia seguinte;
            else if (matrix[i][j] == 1)
            {
                // Se for humano e possuir pelo menos um vizinho zumbi, é infectado e se torna um zumbi
                if (qtdVizinhosZumbis >= 1)
                    matrizAux[i][j] = 2;
                // Se nenhuma das alternativas anteriores for verdade, permanece como está
                else
                    matrizAux[i][j] = matrix[i][j];
            }
            // Se X for zumbi e possuir dois ou mais vizinhos humanos, ele é caçado e morto pelos humanos;
            // Se X for zumbi e não possuir nenhum vizinho humano, ele morre de fome e fica vazio no dia seguinte;
            else
            {
                // Se for zumbi e possuir dois ou mais vizinhos humanos, é caçado e morto pelos humanos
                if (qtdVizinhosHumanos >= 2)
                    matrizAux[i][j] = 0;
                // Se for zumbi e não possuir nenhum vizinho humano, morre de fome e fica vazio
                else if (qtdVizinhosHumanos == 0)
                    matrizAux[i][j] = 0;

                // Se nenhuma das alternativas anteriores for verdade, permanece como está
                else
                    matrizAux[i][j] = matrix[i][j];
            }
            // Verificação dos dados
            // printf("matrix[%d][%d] = %d, vizinhos_humanos = %d, vizinhos_zumbis =  %d\n", i, j, matrix[i][j], qtdVizinhosHumanos, qtdVizinhosZumbis);
        }
    }

    // Atualiza a matriz original com o novo estado
    for (int i = 0; i < numLinhas; i++)
    {
        for (int j = 0; j < numColunas; j++)
        {
            matrix[i][j] = matrizAux[i][j];
        }
    }
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
