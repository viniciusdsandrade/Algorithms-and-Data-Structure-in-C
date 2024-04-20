/*
 * 03 - Mostre a execução passo a passo do algoritmo de ordenção Selection-Sort para o seguinte vetor
 *  v = {21,56,-6,33}. Ordem crescente.
*/

#include <stdio.h>

void selectionSort(int *v, int n) {
    int i, j, min, aux;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i; j < n; j++) {
            if (v[j] < v[min]) {
                min = j;
            }
        }
        aux = v[i];
        v[i] = v[min];
        v[min] = aux;
    }
}

int main(void) {
    int v[] = {21, 56, -6, 33};
    selectionSort(v, 4);
    for (int i = 0; i < 4; i++) {
        printf("%d ", v[i]);
    }
    return 0;
}