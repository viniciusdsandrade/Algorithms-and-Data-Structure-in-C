#include <stdio.h>

int f1(int v[], int n);
void swap(int *a, int *b);

int main(void) {
    int v[] = {3, 1, 1, 0, 2, 6};
    int i, p = 1, aux;

    for (i = 0; i < 6; i++) {
        if (v[i] % 2 == 1) {
            p = p * 2;
        }
    }

    printf("%d\n", p);

    aux = f1(v, 6);
    printf("%d\n", aux);

    printf("v = ");
    for (i = 0; i < 6; i++) {
        printf("%d ", v[i]);
    }
    putchar('\n');
}

int f1(int v[], int n) {
    int i, j, aux = 0;

    for (i = 0, (j = n - 1); i < j; i++, j--) {
        swap(&v[i], &v[j]);
        aux = aux + v[i] + v[j];
    }
    return aux;
}

void swap(int *a, int *b) {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}