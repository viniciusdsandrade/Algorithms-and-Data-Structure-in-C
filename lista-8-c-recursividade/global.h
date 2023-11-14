#include "global.c"

#ifndef ALGORITHMS_AND_DATA_STRUCTURE_IN_C_GLOBAL_H
#define ALGORITHMS_AND_DATA_STRUCTURE_IN_C_GLOBAL_H

void preencherVetor(int v[], int n);
long somaIterativa(long a, long b);
long multiplicacaoRecursiva(long a, long b);
long fatorialIterativo(long n);
long fatorialRecursivo(long n);
int fibonacciIterativo(int n);
int fibonacciRecursivo(int n);
int ff(int n, int ind);
int min(int v[], int n);
int somaElementosVetorInt(int v[], int n);
float media(int v[], int n);
long logaritmo(long n);
long potenciaRecursiva(long x, long n);
void hanoi(int n, char origem, char destino, char auxiliar);
void imprimeVetorIntEmOrderRecursivo(int v[], int i, int n);
int mdc(int x, int y);
int buscaSequencial(int v[], int n, int x);
int buscaBinaria(int v[], int n, int x);

#endif //ALGORITHMS_AND_DATA_STRUCTURE_IN_C_GLOBAL_H