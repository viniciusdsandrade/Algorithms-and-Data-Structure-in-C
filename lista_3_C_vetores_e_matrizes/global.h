#ifndef LISTA_3_GLOBAL_H
#define LISTA_3_GLOBAL_H
#include "global.c"

void linha(int tamanho, char caractere);
void limparTela();

void preencheVetorDouble(double vet[], int tamanho);
void preencheVetorDoubleRandom(double vetor[], int tamanho, int limite);
void mediaVetorDouble(double vetor[], int tamanho);
float raizQuadradaDouble(float num);
float potenciaDouble(double num, int potencia);
int mdc(int a, int b);

void preencheVetorInt(int vet[], int tamanho);
void preencheVetorIntRandom(int vetor[], int tamanho, int limite);

void preencheMatrizInt(int matriz[][100], int linhas, int colunas);
void preencheMatrizIntRandom(int matriz[][100], int linhas, int colunas, int limite);
void preencherMatrizIntRandom2(int **matriz, int linhas, int colunas, int limite);
void imprimirMatrizInt(int **matriz, int linhas, int colunas);

void imprimeMatrizInt(int matriz[][100], int linhas, int colunas);
void imprimirMatrizInt(int **matriz, int linhas, int colunas);
void imprimeVetorInt(int vetor[], int tamanho);
void imprimeVetorDouble(double vetor[], int tamanho);
void imprimeVetorFloat(float vetor[], int tamanho);

void somaMatrizInt(int matriz1[][100], int matriz2[][100], int l1, int c1, int l2, int c2);
int **somarMatrizInt(int **matriz1, int **matriz2, int l1, int c1, int l2, int c2);
void subtraiMatrizInt(int matriz1[][100], int matriz2[][100], int l1, int c1, int l2, int c2);
int **subtrairMatrizInt(int **matriz1, int **matriz2, int l1, int c1, int l2, int c2);
void multiplicaMatrizInt(int a, int d, int m1[][100], int m2[][100], int m3[][100]);
int **multiplicarMatrizInt(int **matriz1, int **matriz2, int l1, int c1, int l2, int c2);
int **multiplicaMatrizInt2(int **matriz, int n);
int ** preenchendoMatrizInt(int linhas, int colunas);
// int **multiplicaMatrizInt(int **m1, int **m2, int l1, int c1, int l2, int c2);
int **matrizIdentidadeCalculo(int n);

void matrizTranspostaInt(int matriz[][100], int linhas, int colunas);
int **matrizTranspostaInt2(int **matriz, int linhas, int colunas);
int *determinanteMatrizInt(int matriz[][100], int linhas, int colunas);

void redimensionaVetorInt(int vetor[], int tamanho);

int encontraMenorElementoMatrizInt(int matriz[][100], int linhas, int colunas);
int encontraMaiorElementoMatrizInt(int matriz[][100], int linhas, int colunas);
void liberarMatrizInt(int **matriz, int linhas);

int verificaOcorrenciaVetorInt(int sequencia1[], int n1, int sequencia2[], int n2);

#endif // LISTA_3_GLOBAL_H
