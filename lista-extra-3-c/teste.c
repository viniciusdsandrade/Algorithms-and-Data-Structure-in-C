#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>

int multiplication(int a, int b) {
    int total = 0;

    if (a > 1) total = multiplication(a - 1, b);

    return total + b;
}

int sum(int a, int b) {
    return a + b;
}

int main(void) {
    // Configura a localidade para Português do Brasil
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // Define a página de código do console para UTF-8
    SetConsoleOutputCP(CP_UTF8);

    int z, k;
    char input[100];
    char *endptr;

    // Entrada para 'k'
    printf("\nDigite valor inteiro para k: ");
    if (!fgets(input, sizeof(input), stdin)) {
        printf("Erro na leitura de entrada.\n");
        return 1;
    }
    k = strtol(input, &endptr, 10);
    if (*endptr != '\n' && *endptr != '\0') {
        printf("Entrada inválida para k.\n");
        return 1;
    }

    // Entrada para 'z'
    printf("Digite valor inteiro para z: ");
    if (!fgets(input, sizeof(input), stdin)) {
        printf("Erro na leitura de entrada.\n");
        return 1;
    }
    z = strtol(input, &endptr, 10);
    if (*endptr != '\n' && *endptr != '\0') {
        printf("Entrada inválida para z.\n");
        return 1;
    }

    // Saída do resultado
    printf("\nResultado da operação é = %d\n", sum(z, k));
    getch();

    return 0;
}