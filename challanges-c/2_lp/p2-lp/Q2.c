#include <stdio.h>

float serieSoma(int n) {
    if (n == 1)
        return 1.0;
    else
        return (float)n / (n + n - 1) + serieSoma(n - 1);
}

int main(void) {

    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);
    printf("Soma: %.2f\n", serieSoma(n));

    return 0;
}