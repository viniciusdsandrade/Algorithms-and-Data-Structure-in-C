#include <stdio.h>
#include <locale.h>
#include "global.c"

int exercicio01(void) {

    /*
     1. Considere o c�digo em C abaixo (assuma que no lugar de D seja usado o �ltimo d�gito de
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
     2. Escreva uma fun��o que recebe dois n�meros inteiros positivos a e b por par�metro e
    determina se eles s�o amigos ou n�o, devolvendo 1 caso sejam amigos, e 0 caso contr�rio.
    Dois n�meros s�o amigos se cada n�mero � igual � soma dos divisores pr�prios do outro
    (os divisores pr�prios de um n�mero m s�o os divisores estritamente menores que m). Por
    exemplo, os divisores pr�prios de 220 s�o 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 e 110, cuja soma
    � 284; e os divisores pr�prios de 284 s�o 1, 2, 4, 71 e 142, cuja soma � 220. Logo, 220 e
    284 s�o n�meros amigos. O prot�tipo da fun��o deve ser:
    int amigos(int a, int b);
     */

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
     3. Escreva uma fun��o que calcule o m�ximo divisor comum de dois n�meros m e n passados
    por par�metro. Voc� deve utilizar a seguinte regra do c�lculo do mdc onde m  n
    mdc(m; n) = m se n = 0
    mdc(m; n) = mdc(n, m%n) se n > 0
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

    /*
     4. Escreva uma fun��o que recebe um valor inteiro positivo n como par�metro e devolve um
    valor inteiro b tal que bk = n para algum inteiro k, e b seja o menor poss�vel. Por exemplo,
    se n = 27 ent�o o valor devolvido deve ser 3, j� se n = 12 ent�o o valor devolvido deve ser
    12. N�o use fun��es de bibliotecas na sua solu��o. O prot�tipo da fun��o deve ser:
    int menor_base_log(int n);
     */

    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    printf("O menor valor de b tal que bk = %d � %d", n, menor_base_log(n));

    return 0;
}

int exercicio05(void) {

    /*
    5. Um inteiro positivo n � pitag�rico se existem inteiros positivos a e b tais que a^2+b^2 = n.
    Por exemplo, 13 � pitag�rico pois 2^2 + 3^2 = 13.

    (a) Escreva uma fun��o que recebe como par�metro tr�s inteiros a, b e n, e que devolve
    1 caso a^2+b^2 = n e devolve 0 caso contr�rio. O prot�tipo da fun��o deve ser:
    int teste(int a, int b, int n);

    (b) Utilize a fun��o do item anterior e escreva uma outra fun��o que recebe como par�metro
    um inteiro positivo n e verifica se n � pitag�rico, devolvendo 1 caso n seja
    pitag�rico e 0 caso contr�rio. O prot�tipo da fun��o deve ser:
    int pitagorico(int n);
     */

    int a, b, n;
    printf("Digite o valor de a: ");
    scanf("%d", &a);

    printf("Digite o valor de b: ");
    scanf("%d", &b);

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    printf("Digite um n�mero inteiro positivo: ");
    scanf("%d", &n);

    if (pitagorico(n)) {
        printf("%d � um n�mero pitag�rico.\n", n);
    } else {
        printf("%d n�o � um n�mero pitag�rico.\n", n);
    }

    return 0;
}

int exercicio06(void) {

    /*
     6. Escreva uma fun��o que recebe um vetor de n�meros reais e o seu tamanho por par�metro
     e devolve a m�dia aritm�tica dos n�meros do vetor. O prot�tipo da fun��o deve ser:
     double media(double v[], int tam);
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

int exercicio07(void) {

    /*
    7. Escreva uma fun��o que recebe um vetor de n�meros reais e o seu tamanho por par�metro
    e devolve o desvio padr�o dos n�meros do vetor usando a seguinte f�rmula:
    Desvio padr�o = ?(?(xi ? x)�/(n ? 1))
    onde n � o n�mero de elementos.
     O prot�tipo da fun��o deve ser:
     */

    int qtd;
    printf("Quantos numeros voc� quer digitar? ");
    scanf("%d", &qtd);

    double numeros[qtd];
    preencheVetorDouble(qtd, numeros);

    printf("O desvio padr�o dos n�meros digitados � %lf", desvioPadrao(numeros, qtd));

    return 0;
}

int exercicio08(void) {

    /*
     8. Escreva uma fun��o que recebe como par�metro duas matrizes quadradas de tamanho
    no m�ximo 30 X 30, onde a primeira matriz corresponde a uma matriz de entrada e a
    segunda corresponde a uma matriz resposta. A fun��o deve calcular a transposta da
    matriz de entrada e guardar o resultado na matriz resposta. A fun��o tamb�m recebe
    como par�metro um inteiro n que indica as dimens�es das matrizes. O prot�tipo da
    fun��o deve ser:
    void transposta(double mat1[30][30], double matRes[30][30], int n);
     */

    int matriz[30][30];
    preencheMatrizQuadrada(matriz, 30);

    int matrizTransposta[30][30];

    transposta(matriz, matrizTransposta, 30);

    imprimeMatrizQuadrada(matrizTransposta, 30);

    return 0;
}

int exercicio09(void) {

    /*
    9. Uma matriz quadrada de inteiros � um quadrado m�gico se a soma dos elementos de cada
    linha, a soma dos elementos de cada coluna, a soma dos elementos da diagonal principal
    e da diagonal secund�ria s�o todos iguais. A matriz abaixo � um exemplo de quadrado
    m�gico:

    3 4  8
    10 5 0
    2 6  7

    Escreva uma fun��o que recebe como par�metro uma matriz quadrada de tamanho no
    m�ximo 30 X 30, e suas dimens�es n, e determina se ela � um quadrado m�gico devolvendo
    1 caso seja e 0 caso contr�rio. O prot�tipo da fun��o deve ser:
     */

    int matriz[30][30];
    preencheMatrizQuadrada(matriz, 30);


    return 0;
}

int exercicio10(void) {
    /*
    10. No jogo Sudoku temos uma matriz 9 X 9 dividida em 9 quadrados de 3 X 3 preenchidos
    previamente com alguns n�meros entre 1 e 9 (veja o exemplo � esquerda abaixo). Uma
    solu��o para uma inst�ncia do jogo consiste no preenchimento de todas as posi��es vazias
    com n�meros entre 1 e 9 respeitando-se as seguintes regras:

    (a) N�o pode haver n�meros repetidos em um mesmo quadrado, ou seja, cada n�mero
    entre 1 e 9 deve aparecer exatamente uma vez em cada quadrado.
    (b) N�o pode haver n�meros repetidos em nenhuma linha da matriz.
    (c) N�o pode haver n�meros repetidos em nenhuma coluna da matriz.

    Escreva uma fun��o que receba uma matriz 9 X 9 como par�metro, que represente uma
    proposta de solu��o para um Sudoku, e teste se a matriz � uma solu��o v�lida para o jogo,
    devolvendo True em caso verdadeiro e False, caso contr�rio.
    A seguinte fun��o deve ser implementada:
     */

    int matriz[9][9];
    preencheMatrizQuadrada(matriz, 9);

    return 0;
}

int exercicio11(void) {
    /*
     11. Suponha que uma matriz bin�ria represente liga��es entre cidades, e que, se uma posi��o
    (i,j) possui o valor 1, ent�o h� uma estrada da cidade i para a cidade j. Seja o seguinte
    exemplo de matriz:

    0 1 1
    0 0 0
    1 0 0

    Neste caso, h� caminhos dispon�veis da cidade 0 para a 1 e 2, e da 2 para 0.
    Para cada item abaixo escreva uma fun��o que recebe como par�metro uma matriz quadrada
    indicando as estradas entre as cidades, um inteiro n correspondendo as dimens�es
    da matriz e um vetor resposta (que ter� tamanho n). O prot�tipo da fun��o deve ser:

    void verifica(int mat[30][30], int n, int resposta[]);

    a) A fun��o deve determinar as cidades com entrada e sem sa�da, indicando isto no vetor
    resposta, tal que resposta[i] recebe 1 caso a cidade i satisfa�a esta propriedade e 0
    caso contr�rio.

    b) A fun��o deve determinar as cidades com sa�da mas sem entrada, indicando isto no
    vetor resposta, tal que resposta[i] recebe 1 caso a cidade i satisfa�a esta propriedade
    e 0 caso contr�rio.
    */

    return 0;
}


int main(void) {
    setlocale(LC_ALL, "Portuguese");

    printf("Exerc�cio 01\n");

    return 0;
}
