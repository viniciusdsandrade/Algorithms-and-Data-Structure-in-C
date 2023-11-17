#ifndef LISTA_3_GLOBAL_H
#define LISTA_3_GLOBAL_H
#include "global.c"

void linha(int tamanho, char caractere);

void preencheVetorDouble(double vet[], int tamanho);
void preencheVetorDoubleRandom(double vetor[], int tamanho, int limite);
int mdc(int a, int b);

void preencheVetorInt(int vet[], int tamanho);
void preencheVetorIntRandom(int vetor[], int tamanho, int limite);

void preencheMatrizInt(int matriz[][100], int linhas, int colunas);
void preencheMatrizIntRandom(int matriz[][100], int linhas, int colunas, int limite);

void imprimeMatrizInt(int matriz[][100], int linhas, int colunas);
void imprimeVetorInt(int vetor[], int tamanho);
void imprimeVetorDouble(double vetor[], int tamanho);

void somaMatrizInt(int matriz1[][100], int matriz2[][100], int l1, int c1, int l2, int c2);
void subtraiMatrizInt(int matriz1[][100], int matriz2[][100], int l1, int c1, int l2, int c2);
int **multiplicaMatrizInt2(int **matriz, int n);
int ** preenchendoMatrizInt(int linhas, int colunas);
int **matrizIdentidadeCalculo(int n);

void matrizTranspostaInt(int matriz[][100], int linhas, int colunas);

int encontraMenorElementoMatrizInt(int matriz[][100], int linhas, int colunas);
int encontraMaiorElementoMatrizInt(int matriz[][100], int linhas, int colunas);
void liberarMatrizInt(int **matriz, int linhas);


#endif // LISTA_3_GLOBAL_H
