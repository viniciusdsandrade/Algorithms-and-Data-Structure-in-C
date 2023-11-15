#ifndef C_ALGORITHMS_GLOBAL_H
#define C_ALGORITHMS_GLOBAL_H
#include "global.c"

void f1(const int v[], int n, int *a);
void menor_base_log(int n, int *b, int *k);
int ehPrimo(int num);
int primo(int n, int *p1, int *p2);
double media(const double vet[], int n, int *i);
double media(const double vet[], int n, int *i);
void frequencias(int v[], int n, int *f1, int *f2);
void swap(int *a, int *b);
void maxAndMin(const int vet[], int tam, int *min, int *max);
void zeraVet(int vet[], int tam);
void strcat_custom(char *s1, char *s2, char *s3);
void strcat_custom2(const char *s1, const char *s2, char *s3);
void imprimeVetorDouble(double v[], int n);

#endif //C_ALGORITHMS_GLOBAL_H