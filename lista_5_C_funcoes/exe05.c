#include <stdio.h>
#include <locale.h>
#include "global.c"

#define MAX_EXERCISES 12
#define MAX_DIMENSION 30

int exercise01(void) {

    /**
     1. Considere o código em C abaixo (assuma que no lugar de D seja usado o último dígito de
       <p> seu RA):
      <p>  #include <stdio.h>
      <p>  int fun1(int a, int b);
<p>
       <p> int j=1;
       <p> int main(){
        <p>    int i, j;
         <p>   int a = D;///Use o último dígito de seu RA.
          <p>  if(a % 2 == 0)
          <p>      a = 2;
           <p> else
           <p>     a = 3;
          <p>  printf("%d\n", fun1(2,4));
         <p>   for(i = 1; i<3; i++){
         <p>       for(j= 1; j <3; j++){
         <p>               printf("%d\n", fun1(a, i+j));
         <p>      }
         <p>   }
       <p> }
      <p>  int pot(int a, int b){
        <p>    int i, p=1;
         <p>   for(i=1; i<=b; i++){
         <p>       p = p*a;
         <p>   }
         <p>   return p+j;
      <p>  }
<p>
        <p>(a) (0.5 pontos) Determine quais são as variáveis locais e globais deste programa. Para
        <p>cada variável local identifique a que função esta pertence.
<p>
        <p>(b) (1.5 pontos) Mostre o que será impresso na tela do computador quando for executado
        <p>este programa (lembre-se de usar o último dígito de seu RA no lugar de D).
     */

    int i, j;
    int a = 6;///Use o último dígito de seu RA.
    if (a % 2 == 0)
        a = 2;
    else
        a = 3;
    printf("%d\n", pot(2, 4));
    for (i = 1; i < 3; i++) {
        for (j = 1; j < 3; j++) {
            printf("%d\n", pot(a, i + j));
        }
    }
    return 0;
}

int exercise02(void) {

    /**
     2. Escreva uma função que recebe dois números inteiros positivos a e b por parâmetro e
  determina se eles são amigos ou não, devolvendo 1 caso sejam amigos, e 0 caso contrário.
<p>
    <p>Dois números são amigos se cada número é igual à soma dos divisores próprios do outro
(os divisores próprios de um número m são os divisores estritamente menores que m).
<p>
   <p> Por exemplo:
<p>
    <p>os divisores próprios de 220 são 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 e 110,
cuja soma é 284;
    <p>e os divisores próprios de 284 são 1, 2, 4, 71 e 142, cuja soma é 220. Logo, 220 e
284 são números amigos.
<p>
   <p> O protótipo da função deve ser: int amigos(int a, int b);
     */

    int a, b;
    printf("Enter the value of a: ");
    scanf("%d", &a);

    printf("Enter the value of b: ");
    scanf("%d", &b);

    if (amigos(a, b))
        printf("%d and %d are friends\n", a, b);
    else
        printf("%d and %d are not friends\n", a, b);

    return 0;

}

int exercise03(void) {

    /**
    3. Escreva uma função que calcule o máximo divisor comum de dois números m e n
    passados por parâmetro.

    <p>Você deve utilizar a seguinte regra do cálculo do mdc onde m e n são números inteiros positivos:
    <p>mdc(m; n) = m se n = 0
    <p>mdc(m; n) = mdc(n, m%n) se n > 0
    <p> O protótipo da função deve ser: int mdc(int m, int n);
     */
    int m, n;
    printf("Enter the value of m: ");
    scanf("%d", &m);

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("MDC(%d,%d) = %d\n", m, n, mdc(m, n));

    return 0;
}

int exercise04(void) {

    /**
     4. Escreva uma função que recebe um valor inteiro positivo n como parâmetro
     e devolve um valor inteiro b tal que bk = n para algum inteiro k,
     e b seja o menor possível.
<p>
     Por exemplo: se n = 27 então o valor devolvido deve ser 3,
     já se n = 12 então o valor devolvido deve ser 12.
<p>
     Não use funções de bibliotecas na sua solução.
<p>
     O protótipo da função deve ser: int menor_base_log(int n);
     */

    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("The smallest value of b such that b^k = %d --> %d\n", n, menor_base_log(n));

    return 0;
}

int exercise05(void) {

    /**
    5. Um inteiro positivo n é pitagórico se existem inteiros positivos a e b tais que a^2+b^2 = n.
    Por exemplo, 13 é pitagórico pois 2^2 + 3^2 = 13.
<p>
    <p>(a) Escreva uma função que recebe como parâmetro três inteiros a, b e n, e que devolve
    1 caso a^2+b^2 = n e devolve 0 caso contrário.
<p>
    O protótipo da função deve ser: int teste(int a, int b, int n);
<p>
    (b) Utilize a função do item anterior e escreva uma outra função que recebe como parâmetro
    um inteiro positivo n e verifica se n é pitagórico, devolvendo 1 caso n seja
    pitagórico e 0 caso contrário.
<p>
    O protótipo da função deve ser: int pitagorico(int n);
     */

    int a, b, n;
    printf("Enter the value of a: ");
    scanf("%d", &a);

    printf("Enter the value of b: ");
    scanf("%d", &b);

    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (pitagorico(n))
        printf("%d is a Pythagorean number.\n", n);
    else
        printf("%d is not a Pythagorean number.\n", n);

    return 0;

}

int exercise06(void) {

    /**
     6. Escreva uma função que recebe um vetor de números reais e o seu tamanho por parâmetro
     e devolve a média aritmética dos números do vetor.

     <p> O protótipo da função deve ser: double media(double v[], int tam);
     */

    int qtd;
    printf("How many numbers do you want to enter? ");
    scanf("%d", &qtd);

    double numbers[qtd];
    int i;

    for (i = 0; i < qtd; i++) {
        printf("number[%d] = ", i + 1);
        scanf("%lf", &numbers[i]);
    }

    printf("average = %.2lf\n", media(numbers, qtd));
    return 0;

}

int exercise07(void) {

    /**
    7. Escreva uma função que recebe um vetor de números reais e o seu tamanho
    por parâmetro e devolve o desvio padrão dos números do vetor usando a
    seguinte fórmula:
<p>
     Desvio padrão = ?((?(xi - x)²) / (n - 1))
<p>
     onde n é o número de elementos.
     <p>
     O protótipo da função deve ser: double desvioPadrao(double v[], int tam);
     */

    int qtd;
    printf("How many numbers do you want to enter? ");
    scanf("%d", &qtd);

    double numbers[qtd];
    preencheVetorDouble(qtd, numbers);

    printf("The standard deviation of the entered numbers is %lf", desvioPadrao(numbers, qtd));

    return 0;
}

int exercise08(void) {

    /**
    8. Escreva uma função que recebe como parâmetro duas matrizes quadradas de tamanho
    no máximo 30 X 30, onde a primeira matriz corresponde a uma matriz de entrada e a
    segunda corresponde a uma matriz resposta.
<p>
   <p> A função deve calcular a transposta da matriz de entrada e guardar o resultado na matriz resposta.
    <p>A função também recebe como parâmetro um inteiro n que indica as dimensões das matrizes.
<p>
    O protótipo da função deve ser:
     <p>
    void transposta(double mat1[30][30], double matRes[30][30], int n);
     */

    int dimension;

    printf("Enter the dimension of the matrix (max %d): ", MAX_DIMENSION);
    scanf("%d", &dimension);

    if (dimension <= 0 || dimension > MAX_DIMENSION) {
        printf("Invalid dimension.\n");
        return 1;
    }

    int inputMatrix[MAX_DIMENSION][MAX_DIMENSION];
    int transposedMatrix[MAX_DIMENSION][MAX_DIMENSION];

    readMatrix(inputMatrix, dimension);

    printf("Original Matrix:\n");
    printMatrix(inputMatrix, dimension);

    transpose(inputMatrix, transposedMatrix, dimension);

    printf("Transposed Matrix:\n");
    printMatrix(transposedMatrix, dimension);

    return 0;
}

int exercise09(void) {

    /**
    9. Uma matriz quadrada de inteiros é um quadrado mágico se
    <p> a) a soma dos elementos de cada linha,
    <p> b) a soma dos elementos de cada coluna,
    <p> c) a soma dos elementos da diagonal principal
    <p> e a soma da diagonal secundária são todos iguais.
<p>
     <p>A matriz abaixo é um exemplo de quadrado mágico:
<p>
    <p>[3  4  8]
    <p>[10 5  0]
    <p>[2  6  7]
<p><p>

    Escreva uma função que recebe como parâmetro uma matriz quadrada de tamanho no
    máximo 30 X 30, e suas dimensões n, e determina se ela é um quadrado mágico devolvendo
    1 caso seja e 0 caso contrário.
<p>
     O protótipo da função deve ser: int magico(int mat[30][30], int n);
     */

    int matrix[30][30];
    int dimension;

    printf("Enter the dimension of the matrix: ");
    scanf("%d", &dimension);

    readMatrix(matrix, dimension);

    if (isMagico(matrix, 30))
        printf("The matrix is a magic square");
    else
        printf("The matrix is not a magic square");

    return 0;
}

int exercise10(void) {
    /**
    10. No jogo Sudoku temos uma matriz 9 X 9 dividida em 9 quadrados de 3 X 3 preenchidos
    previamente com alguns números entre 1 e 9 (veja o exemplo à esquerda abaixo).
<p>
    Uma solução para uma instância do jogo consiste no preenchimento de todas as posições vazias
    com números entre 1 e 9 respeitando-se as seguintes regras:
<p>
    <p>(a) Não pode haver números repetidos em um mesmo quadrado, ou seja, cada número
    entre 1 e 9 deve aparecer exatamente uma vez em cada quadrado.
    <p>(b) Não pode haver números repetidos em nenhuma linha da matriz.
    <p>(c) Não pode haver números repetidos em nenhuma coluna da matriz.
<p>
    Escreva uma função que receba uma matriz 9 X 9 como parâmetro, que represente uma
    proposta de solução para um Sudoku, e teste se a matriz é uma solução válida para o jogo,
    devolvendo True em caso verdadeiro e False, caso contrário.
     <p>
    A seguinte função deve ser implementada:
    */

    printf("Enter the values of your Sudoku board:\n");

    int tabuleiro[9][9];
    bool tabuleiroValido = true; // Assume que o tabuleiro é válido até encontrar uma violação

    for (int i = 0; i < 9 && tabuleiroValido; i++) {
        for (int j = 0; j < 9; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &tabuleiro[i][j]);

            if (!verificaLinha(i, tabuleiro[i][j], tabuleiro) ||
                !verificaColuna(j, tabuleiro[i][j], tabuleiro) ||
                !verificaQuadrante(i, j, tabuleiro[i][j], tabuleiro)) {
                tabuleiroValido = false;
                break;
            }
        }
    }

    if (tabuleiroValido)
        printf("The Sudoku board is valid!\n");
    else
        printf("The Sudoku board is not valid!\n");

    return 0;
}

int exercise11(void) {
    /**
    11. Suponha que uma matriz binária represente ligações entre cidades, e que, se uma posição
    (i,j) possui o valor 1, então há uma estrada da cidade i para a cidade j. Seja o seguinte

    <p>exemplo de matriz:
 <p>
    <p>[0 1 1]
   <p> [0 0 0]
    <p>[1 0 0]
 <p>
  <p>  Neste caso, há caminhos disponíveis da cidade 0 para a 1 e 2, e da 2 para 0.
    Para cada item abaixo escreva uma função que recebe como parâmetro uma matriz quadrada
    indicando as estradas entre as cidades, um inteiro n correspondendo as dimensões
    da matriz e um vetor resposta (que terá tamanho n).
 <p>
    <p>  O protótipo da função deve ser:
      <p>void verifica(int mat[30][30], int n, int resposta[]);
 <p>
   <p> a) A função deve determinar as cidades com entrada e sem saída, indicando isto no vetor
    resposta, tal que resposta[i] recebe 1 caso a cidade i satisfaça esta propriedade e 0
    caso contrário.
<p>
    <p>b) A função deve determinar as cidades com saída mas sem entrada, indicando isto no
    vetor resposta, tal que resposta[i] recebe 1 caso a cidade i satisfaça esta propriedade
    e 0 caso contrário.
    */

    int matriz[MAX_DIMENSION][MAX_DIMENSION];
    int dimensao;

    printf("Enter the dimension of the matrix: ");
    scanf("%d", &dimensao);
    readMatrix(matriz, dimensao);

    int resposta[dimensao];

    cidadesComEntradaSemSaida(matriz, dimensao, resposta);
    printf("Cities with input and no output:\n");
    for (int i = 0; i < dimensao; i++) {
        if (resposta[i]) {
            printf("%d ", i);
        }
    }

    printf("\n");

    cidadesComSaidaSemEntrada(matriz, dimensao, resposta);
    printf("Cities with output and no input:\n");
    for (int i = 0; i < dimensao; i++) {
        if (resposta[i]) {
            printf("%d ", i);
        }
    }

    return 0;
}

int exercise12(void) {

    /**
    10. Escreva uma função que recebe como parâmetro três matrizes quadradas de tamanho no
    máximo 30 X 30, onde a primeira e a segunda matriz correspondem a entrada e a terceira
    corresponde a uma matriz resposta.
    <p>A função deve calcular a multiplicação da primeira pela segunda matriz e guardar o resultado na matriz resposta.
    <p> A função também recebe como parâmetro um inteiro n que indica as dimensões das matrizes.
    <p>
   <p>  O protótipo da função deve ser:
    <p>

     */

    int matrizA[MAX_DIMENSION][MAX_DIMENSION];
    int matrizB[MAX_DIMENSION][MAX_DIMENSION];
    int matrizResultado[MAX_DIMENSION][MAX_DIMENSION];
    int dimensao;

    printf("Enter the dimension of the matrices: ");
    scanf("%d", &dimensao);

    readMatrix(matrizA, dimensao);
    printMatrix(matrizA, dimensao);

    readMatrix(matrizB, dimensao);
    printMatrix(matrizB, dimensao);

    multiplySquareMatrix(matrizA, matrizB, matrizResultado, dimensao);
    printf("The result of the multiplication of matrices A and B is:\n");
    printMatrix(matrizResultado, dimensao);

    return 0;
}

int displayMenuAndGetChoice(void) {
    printf("Exercise 01:\n");
    printf("Exercise 02:\n");
    printf("Exercise 03:\n");
    printf("Exercise 04:\n");
    printf("Exercise 05:\n");
    printf("Exercise 06:\n");
    printf("Exercise 07:\n");
    printf("Exercise 08:\n");
    printf("Exercise 09:\n");
    printf("Exercise 10:\n");
    printf("Exercise 11:\n");
    printf("Exercise 12:\n");
    printf("Enter the number of the exercise you want to execute: ");

    int choice;
    scanf("%d", &choice);
    return choice;
}

void executeExercise(int choice) {
    switch (choice) {
        case 1:
            exercise01();
            break;
        case 2:
            exercise02();
            break;
        case 3:
            exercise03();
            break;
        case 4:
            exercise04();
            break;
        case 5:
            exercise05();
            break;
        case 6:
            exercise06();
            break;
        case 7:
            exercise07();
            break;
        case 8:
            exercise08();
            break;
        case 9:
            exercise09();
            break;
        case 10:
            exercise10();
            break;
        case 11:
            exercise11();
            break;
        case 12:
            exercise12();
            break;
        default:
            printf("Invalid option!\n");
            break;
    }
}

bool getExitChoice(void) {
    int exitChoice;
    do {
        printf("Do you want to exit?\n"
               "Enter (1) for Yes or (0) for No: ");
        scanf("%d", &exitChoice);
    } while (exitChoice != 0 && exitChoice != 1);
    return exitChoice;
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    bool exitProgram = false;

    do {
        int choice = displayMenuAndGetChoice();

        if (choice >= 1 && choice <= MAX_EXERCISES) {
            executeExercise(choice);
        } else {
            printf("Invalid option!\n");
        }
        exitProgram = getExitChoice();
    } while (!exitProgram);
    printf("Thank you for using the program!\n");
    return 0;
}
