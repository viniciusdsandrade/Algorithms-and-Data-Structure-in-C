#include <stdio.h>
#include <locale.h>
#include "global.c"

int solveSudoku(int pInt[9][9]);

int exercicio01(void) {

    /*Considere o código em C abaixo (assuma que no lugar de D seja usado o último dígito de
        seu RA):
        #include <stdio.h>
        int fun1(int a, int b);

        int j=1;
        int main(){
            int i, j;
            int a = D;///Use o último dígito de seu RA.
            if(a % 2 == 0)
                a = 2;
            else
                a = 3;
            printf("%d\n", fun1(2,4));
            for(i = 1; i<3; i++){
                for(j= 1; j <3; j++){
                        printf("%d\n", fun1(a, i+j));
                }
            }
        }
        int fun1(int a, int b){
            int i, p=1;
            for(i=1; i<=b; i++){
                p = p*a;
            }
            return p+j;
        }

        (a) (0.5 pontos) Determine quais são as variáveis locais e globais deste programa. Para
        cada variável local identifique a que função esta pertence.

        (b) (1.5 pontos) Mostre o que será impresso na tela do computador quando for executado
        este programa (lembre-se de usar o último dígito de seu RA no lugar de D).
     */

    int i, j;
    int a = 6;///Use o último dígito de seu RA.
    if (a % 2 == 0)
        a = 2;
    else
        a = 3;
    printf("%d\n", fun1(2, 4));
    for (i = 1; i < 3; i++) {
        for (j = 1; j < 3; j++) {
            printf("%d\n", fun1(a, i + j));
        }
    }

    return 0;
}


int exercicio02(void) {

    /*
     * 2. Escreva uma função que recebe dois números inteiros positivos a e b por parâmetro e
        determina se eles são amigos ou não, devolvendo 1 caso sejam amigos, e 0 caso contrário.
        Dois números são amigos se cada número é igual à soma dos divisores próprios do outro
        (os divisores próprios de um número m são os divisores estritamente menores que m). Por
        exemplo, os divisores próprios de 220 são 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 e 110, cuja soma
        é 284; e os divisores próprios de 284 são 1, 2, 4, 71 e 142, cuja soma é 220. Logo, 220 e
        284 são números amigos. O protótipo da função deve ser:
        int amigos(int a, int b);
     * */

    int a, b;
    printf("Digite o valor de a: ");
    scanf("%d", &a);

    printf("Digite o valor de b: ");
    scanf("%d", &b);

    if (amigos(a, b)) {
        printf("%d e %d são amigos", a, b);
    } else {
        printf("%d e %d não são amigos", a, b);
    }
    return 0;
}

int exercicio03(void) {

    /*
     * Escreva uma função que calcule o máximo divisor comum de dois números m e n passados
    por parâmetro. Você deve utilizar a seguinte regra do cálculo do mdc onde m  n
    mdc(m; n) = m se n = 0
    mdc(m; n) = mdc(n;m%n) se n > 0
    O protótipo da função deve ser:
    int mdc(int m, int n);
     */

    int m, n;
    printf("Digite o valor de m: ");
    scanf("%d", &m);

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    printf("O MDC de %d e %d é %d", m, n, mdc(m, n));

    return 0;
}

int exercicio04(void) {
    return 0;
}

int exercicio05(void) {

    /*
     * Escreva uma função que receba uma lista de números reais e devolva a média aritmética
    dos números da lista.
    A seguinte função deve ser implementada:
     */

    int qtd;
    printf("Quantos numeros você quer digitar? ");
    scanf("%d", &qtd);

    double numeros[qtd];
    int i;

    for (i = 0; i < qtd; i++) {
        printf("Digite o %dº número: ", i + 1);
        scanf("%lf", &numeros[i]);
    }

    printf("A média dos números digitados é %lf", media(numeros, qtd));
    return 0;
}

int exercicio06(void) {
    return 0;
}

int exercicio07(void) {
    return 0;
}


int exercicio08(void) {
    return 0;
}

int exercicio09(void) {
    return 0;
}

int exercicio10(void) {
    /*
     No jogo Sudoku temos uma matriz 9  9 dividida em 9 quadrados de 3  3 preenchidos
    previamente com alguns números entre 1 e 9 (veja o exemplo à esquerda abaixo). Uma
    solução para uma instância do jogo consiste no preenchimento de todas as posições vazias
    com números entre 1 e 9 respeitando-se as seguintes regras:

    (a) Não pode haver números repetidos em um mesmo quadrado, ou seja, cada número
    entre 1 e 9 deve aparecer exatamente uma vez em cada quadrado.
    (b) Não pode haver números repetidos em nenhuma linha da matriz.
    (c) Não pode haver números repetidos em nenhuma coluna da matriz.

    Escreva uma função que receba uma matriz 9  9 como parâmetro, que represente uma
    proposta de solução para um Sudoku, e teste se a matriz é uma solução válida para o jogo,
    devolvendo True em caso verdadeiro e False, caso contrário.
    A seguinte função deve ser implementada:

     */

    int matriz[9][9];

    preencheMatriz(matriz);

    return 0;
}



int main(void) {
    setlocale(LC_ALL, "Portuguese");

    return 0;
}
