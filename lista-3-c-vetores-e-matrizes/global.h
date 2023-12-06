#ifndef LISTA_3_GLOBAL_H
#define LISTA_3_GLOBAL_H
#include "global.c"

#define MAX 100

void linha(int tamanho, char caractere);
bool verifyInput(int input, int inicio, int fim);
void preencheVetorInt(int vet[], int tamanho);
void preencheVetorDouble(double vet[], int tamanho);
void preencheVetorFloat(float vet[], int tamanho);
void encontrarMultiplos(int vet[], int tam, int comum);
void combinacoesMultiplicacao(int n);
void fatoracaoPrimos(int num);
void preencheVetorIntRandom(int vetor[], int tamanho, unsigned int limite, unsigned int seed);
void preencheMatrizInt(int matriz[][MAX], int linhas, int colunas);
void preencheMatrizIntRandom(int matriz[][MAX], int linhas, int colunas, int limite, unsigned int seed);
void preencheMatrizDouble(double matriz[][MAX], int linhas, int colunas);
void imprimeVetorInt(const int vetor[], int tamanho);
void imprimeVetorDouble(double vetor[], int tamanho);
void intercalarVetores(int v1[], int v2[], int v3[], int tam);
void imprimeMatrizInt(int matriz[][MAX], int linhas, int colunas);
void imprimeMatrizDouble(const double matriz[][MAX], int linhas, int colunas);
int obterPivoNaoZero(int matriz[MAX][MAX], int linhas, int colunas, int coluna);
void trocarLinhas(int matriz[MAX][MAX], int linhas, int colunas, int linha1, int linha2);
int eliminacaoGauss(int matriz[][MAX], int linhas, int colunas);
void unirVetores(const int v1[], int tam1, const int v2[], int tam2, int v3[]);
void bubbleSort(int *v3, int tam);
double sumArray(int n, double vetor[]);
float somaElementosVetorFloat(float pDouble[10], int i);
int verificaOcorrenciaVetorInt(const int sequencia1[], int n1, const int sequencia2[], int n2);
void preencheVetorInt(int vet[], int tamanho);
void matrizTranspostaInt(int matriz[][MAX], int linhas, int colunas);
int determinanteMatrizInt(int matriz[][MAX], int linhas, int colunas);
double produtoInternoDouble(const double *vet1, const double *vet2, double *produtoInterno, double soma, int tam);
int mdc(int a, int b);
void preencheVetorIntRandom(int vetor[], int tamanho, unsigned int limite, unsigned int seed);
void preencheMatrizInt(int matriz[][MAX], int linhas, int colunas);
void preencheMatrizIntRandom(int matriz[][100], int linhas, int colunas, int limite, unsigned int seed);
void contaPosicoesNaoNulas(const int matriz[][MAX], int linhas, int colunas);
void preencheMatrizDouble(double matriz[][MAX], int linhas, int colunas);
void imprimeMatrizInt(int matriz[][MAX], int linhas, int colunas);
void imprimeVetorInt(const int vetor[], int tamanho);
void imprimeVetorDouble(double vetor[], int tamanho);
void imprimeMatrizDouble(const double matriz[][MAX], int linhas, int colunas);
float somaElementosVetorFloat(float pDouble[10], int i);
void somaMatrizInt(const int matriz1[][MAX], const int matriz2[][MAX], int matriz3[][MAX], int linhas, int colunas);
void subtracaoMatrizInt(const int matriz1[][MAX], const int matriz2[][MAX], int matriz3[][MAX], int linhas, int colunas);
void somaMatrizesDouble(const double matriz1[][MAX], const double matriz2[][MAX], double resultado[][MAX], int linhas, int colunas);
void multiplicaMatrizInt(int matriz1[][MAX], int matriz2[][MAX], int matriz3[][MAX], int n);
void multiplicacaoMatrizIntGenerica(const int matriz1[][MAX], const int matriz2[][MAX], int matriz3[][MAX], int linhas1, int colunas1, int linhas2, int colunas2);
int somaDiagonalPrincipal(int matriz[][MAX], int ordem);
int somaDiagonalSecundaria(int matriz[][MAX], int ordem);
double mediaVetorDouble(double vetor[], int n);
double raizQuadradaDouble(double num);
double potenciaDouble(double base, int exp);
void liberarMatrizInt(int **matriz, int linhas);

#endif // LISTA_3_GLOBAL_H