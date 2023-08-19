#include <stdio.h>
#include <locale.h>
#include "global.c"

int solveSudoku(int pInt[9][9]);

int exercicio01(void) {

    /*Considere o c�digo em C abaixo (assuma que no lugar de D seja usado o �ltimo d�gito de
        seu RA):
        #include <stdio.h>
        int fun1(int a, int b);

        int j=1;
        int main(){
            int i, j;
            int a = D;///Use o �ltimo d�gito de seu RA.
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

        (a) (0.5 pontos) Determine quais s�o as vari�veis locais e globais deste programa. Para
        cada vari�vel local identifique a que fun��o esta pertence.

        (b) (1.5 pontos) Mostre o que ser� impresso na tela do computador quando for executado
        este programa (lembre-se de usar o �ltimo d�gito de seu RA no lugar de D).
     */

    int i, j;
    int a = 6;///Use o �ltimo d�gito de seu RA.
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
     * 2. Escreva uma fun��o que recebe dois n�meros inteiros positivos a e b por par�metro e
        determina se eles s�o amigos ou n�o, devolvendo 1 caso sejam amigos, e 0 caso contr�rio.
        Dois n�meros s�o amigos se cada n�mero � igual � soma dos divisores pr�prios do outro
        (os divisores pr�prios de um n�mero m s�o os divisores estritamente menores que m). Por
        exemplo, os divisores pr�prios de 220 s�o 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 e 110, cuja soma
        � 284; e os divisores pr�prios de 284 s�o 1, 2, 4, 71 e 142, cuja soma � 220. Logo, 220 e
        284 s�o n�meros amigos. O prot�tipo da fun��o deve ser:
        int amigos(int a, int b);
     * */

    int a, b;
    printf("Digite o valor de a: ");
    scanf("%d", &a);

    printf("Digite o valor de b: ");
    scanf("%d", &b);

    if (amigos(a, b)) {
        printf("%d e %d s�o amigos", a, b);
    } else {
        printf("%d e %d n�o s�o amigos", a, b);
    }
    return 0;
}

int exercicio03(void) {

    /*
     * Escreva uma fun��o que calcule o m�ximo divisor comum de dois n�meros m e n passados
    por par�metro. Voc� deve utilizar a seguinte regra do c�lculo do mdc onde m  n
    mdc(m; n) = m se n = 0
    mdc(m; n) = mdc(n;m%n) se n > 0
    O prot�tipo da fun��o deve ser:
    int mdc(int m, int n);
     */

    int m, n;
    printf("Digite o valor de m: ");
    scanf("%d", &m);

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    printf("O MDC de %d e %d � %d", m, n, mdc(m, n));

    return 0;
}

int exercicio04(void) {
    return 0;
}

int exercicio05(void) {

    /*
     * Escreva uma fun��o que receba uma lista de n�meros reais e devolva a m�dia aritm�tica
    dos n�meros da lista.
    A seguinte fun��o deve ser implementada:
     */

    int qtd;
    printf("Quantos numeros voc� quer digitar? ");
    scanf("%d", &qtd);

    double numeros[qtd];
    int i;

    for (i = 0; i < qtd; i++) {
        printf("Digite o %d� n�mero: ", i + 1);
        scanf("%lf", &numeros[i]);
    }

    printf("A m�dia dos n�meros digitados � %lf", media(numeros, qtd));
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
    previamente com alguns n�meros entre 1 e 9 (veja o exemplo � esquerda abaixo). Uma
    solu��o para uma inst�ncia do jogo consiste no preenchimento de todas as posi��es vazias
    com n�meros entre 1 e 9 respeitando-se as seguintes regras:

    (a) N�o pode haver n�meros repetidos em um mesmo quadrado, ou seja, cada n�mero
    entre 1 e 9 deve aparecer exatamente uma vez em cada quadrado.
    (b) N�o pode haver n�meros repetidos em nenhuma linha da matriz.
    (c) N�o pode haver n�meros repetidos em nenhuma coluna da matriz.

    Escreva uma fun��o que receba uma matriz 9  9 como par�metro, que represente uma
    proposta de solu��o para um Sudoku, e teste se a matriz � uma solu��o v�lida para o jogo,
    devolvendo True em caso verdadeiro e False, caso contr�rio.
    A seguinte fun��o deve ser implementada:

     */

    int matriz[9][9];

    preencheMatriz(matriz);

    return 0;
}



int main(void) {
    setlocale(LC_ALL, "Portuguese");

    return 0;
}
