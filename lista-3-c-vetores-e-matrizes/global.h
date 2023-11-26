#ifndef LISTA_3_GLOBAL_H
#define LISTA_3_GLOBAL_H
#include "global.c"

#define MAX 100

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
int mdc(int a, int b);
void preencheVetorIntRandom(int vetor[], int tamanho, unsigned int limite, unsigned int seed);
void preencheMatrizInt(int matriz[][MAX], int linhas, int colunas);
void preencheMatrizDouble(double matriz[][MAX], int linhas, int colunas);
void imprimeMatrizInt(int matriz[][MAX], int linhas, int colunas);
void imprimeVetorInt(const int vetor[], int tamanho);
void imprimeVetorDouble(double vetor[], int tamanho);
void imprimeMatrizDouble(double matriz[][MAX], int linhas, int colunas);
float somaElementosVetorFloat(float pDouble[10], int i);
void multiplicaMatrizInt(int m1[][MAX], int m2[][MAX], int m3[][MAX], int n);
double mediaVetorDouble(double vetor[], int n);
double raizQuadradaDouble(double num);
double potenciaDouble(double base, int exp);
void liberarMatrizInt(int **matriz, int linhas);

#endif // LISTA_3_GLOBAL_H