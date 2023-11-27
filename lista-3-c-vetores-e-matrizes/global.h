#ifndef LISTA_3_GLOBAL_H
#define LISTA_3_GLOBAL_H
#include "global.c"

#define MAX 100

void buubleSort(int *v3, int tam);
bool verifyInput(int input, int inicio, int fim);
double sumArray(int n, double vetor[]);
void linha(int tamanho, char caractere);
void preencheVetorDouble(double vet[], int tamanho);
void preencheVetorFloat(float vet[], int tamanho);
float somaElementosVetorFloat(float pDouble[10], int i);
void preencheVetorDoubleRandom(double vetor[], int tamanho, double limite, unsigned int seed);
int verificaOcorrenciaVetorInt(const int sequencia1[], int n1, const int sequencia2[], int n2);
void preencheVetorInt(int vet[], int tamanho);
void matrizTranspostaInt(int matriz[][MAX], int linhas, int colunas);
int determinanteMatrizInt(int matriz[MAX][MAX], int linhas, int colunas);
double produtoInternoDouble(const double *vet1, const double *vet2, double *produtoInterno, double soma, int tam);
int mdc(int a, int b);
void preencheVetorIntRandom(int vetor[], int tamanho, unsigned int limite, unsigned int seed);
void preencheMatrizInt(int matriz[][MAX], int linhas, int colunas);
void preencheMatrizIntRandom(int matriz[][100],int linhas,int colunas,int limite,unsigned int seed);
void contaPosicoesNaoNulas(const int matriz[][MAX], int linhas, int colunas);
void preencheMatrizDouble(double matriz[][MAX], int linhas, int colunas);
void imprimeMatrizInt(int matriz[][MAX], int linhas, int colunas);
void imprimeVetorInt(const int vetor[], int tamanho);
void imprimeVetorDouble(double vetor[], int tamanho);
void imprimeMatrizDouble(const double matriz[][MAX], int linhas, int colunas);
float somaElementosVetorFloat(float pDouble[10], int i);
void somaMatrizesDouble(const double matriz1[][MAX], const double matriz2[][MAX], double resultado[][MAX], int linhas, int colunas);
void multiplicaMatrizInt(int matriz1[][MAX], int matriz2[][MAX], int matriz3[][MAX], int n);
double mediaVetorDouble(double vetor[], int n);
double raizQuadradaDouble(double num);
double potenciaDouble(double base, int exp);
void liberarMatrizInt(int **matriz, int linhas);

#endif // LISTA_3_GLOBAL_H