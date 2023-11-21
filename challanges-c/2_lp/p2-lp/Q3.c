#include <stdio.h>

void contagemRegressiva(int n) {
    if (n == 0) {
        printf("0, \n");
    } else {
        printf("%d, ", n);
        contagemRegressiva(n - 1);
    }
}

int main(void) {

    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);
    contagemRegressiva(n);

    return 0;
}