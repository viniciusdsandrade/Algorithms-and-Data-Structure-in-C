#include <stdbool.h>
#include "global.h"

int mdc(int m, int n) {
    return n == 0 ? m : mdc(n, m % n);
}

int fun1(int a, int b) {
    int p = 1;
    for (int i = 0; i < b; i++) {
        p *= a;
    }
    return p;
}

bool amigos(int a, int i) {
    int somaDivisoresA = 0, somaDivisoresB = 0;
    for (int j = 1; j < a; j++) {
        if (a % j == 0) somaDivisoresA += j;
        if (i % j == 0) somaDivisoresB += j;
    }
    return somaDivisoresA == i && somaDivisoresB == a;
}

double media(double pDouble[], int qtd) {
    double soma = 0;
    for (int i = 0; i < qtd; i++) {
        soma += pDouble[i];
    }
    return soma / qtd;
}

void preencheMatriz(int matriz[9][9]) {
    printf("Digite os valores da matriz 9x9: ");
    for (int i = 0; i < 9; i++) {
        printf("Digite os valores da linha %d: ", i + 1);
        for (int j = 0; j < 9; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
}



