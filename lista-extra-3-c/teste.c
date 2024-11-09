#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>

/**
 * @brief Realiza a multiplicação de dois números inteiros de forma recursiva.
 *
 * Esta função multiplica dois números inteiros `a` e `b` utilizando adição repetida.
 * A multiplicação é implementada de forma recursiva, onde `a` é decrementado até 1,
 * somando `b` em cada chamada recursiva.
 *
 * @param a O primeiro número inteiro (multiplicador).
 * @param b O segundo número inteiro (multiplicando).
 * @return O resultado da multiplicação de `a` por `b`.
 */
int multiplication(int a, int b) {
    int total = 0;

    if (a > 1)
        total = multiplication(a - 1, b);

    return total + b;
}

/**
 * @brief Calcula a soma de dois números inteiros.
 *
 * Esta função recebe dois inteiros e retorna a sua soma.
 *
 * @param a O primeiro número inteiro.
 * @param b O segundo número inteiro.
 * @return A soma de `a` e `b`.
 */
int sum(int a, int b) {
    return a + b;
}

/**
 * @brief Função principal do programa.
 *
 * Esta função configura a localidade e a página de código para suportar caracteres
 * em Português do Brasil e UTF-8. Em seguida, solicita ao usuário que insira dois
 * valores inteiros (`k` e `z`), valida as entradas e exibe a soma desses valores.
 *
 * @return Retorna 0 se a execução for bem-sucedida, ou 1 em caso de erro na leitura das entradas.
 */
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

/*
================================================================================
Descrição Geral

Este programa em C realiza operações matemáticas básicas, permitindo que o
usuário insira dois valores inteiros (`k` e `z`). Após a entrada dos valores,
o programa calcula a soma desses números e exibe o resultado. Além disso, há uma
função de multiplicação implementada de forma recursiva, embora não seja utilizada
no fluxo principal do programa.

================================================================================
Comentários Adicionais

- Inclusão de Bibliotecas:
  - <stdio.h>: Necessária para operações de entrada e saída, como `printf` e `fgets`.
  - <conio.h>: Utilizada para a função `getch()`, que aguarda a entrada de uma tecla.
  - <locale.h>: Permite a configuração da localidade para suportar caracteres específicos.
  - <windows.h>: Necessária para funções específicas do Windows, como `SetConsoleOutputCP`.

- Observação sober a Função `multiplication`:
  - Embora a função `multiplication` esteja implementada, ela não é utilizada no fluxo
    principal do programa (`main`). Caso seja necessária, você pode integrá-la chamando
    `multiplication(z, k)` ou conforme a lógica desejada.

- Validação de Entrada:
  - A validação das entradas assegura que apenas números inteiros válidos sejam processados,
    prevenindo erros na execução.

- Compatibilidade:
  - O uso de <conio.h> e `SetConsoleOutputCP` torna o programa específico para sistemas
    Windows. Se houver a necessidade de portabilidade para outros sistemas operacionais,
    será necessário ajustar ou remover essas partes.

================================================================================
*/
