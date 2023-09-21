#include <stdio.h>
#include <locale.h>
#include "global.c"

#define MAX_EXERCISES 12
#define MAX_DIMENSAO 30

int exercicio01(void) {

    /**
     <p>1. Considere o código em C abaixo (assuma que no lugar de D seja usado o último dígito de
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

int exercicio02(void) {

    /**
     <p>2. Escreva uma função que recebe dois números inteiros positivos a e b por parâmetro e
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

    /**
    3. Escreva uma função que calcule o máximo divisor comum de dois números m e n
    passados por parâmetro.

    <p>Você deve utilizar a seguinte regra do cálculo do mdc onde m e n são números inteiros positivos:
    <p>mdc(m; n) = m se n = 0
    <p>mdc(m; n) = mdc(n, m%n) se n > 0
    <p> O protótipo da função deve ser: int mdc(int m, int n);
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
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    printf("O menor valor de b tal que bk = %d é %d", n, menor_base_log(n));

    return 0;
}

int exercicio05(void) {

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
    printf("Digite o valor de a: ");
    scanf("%d", &a);

    printf("Digite o valor de b: ");
    scanf("%d", &b);

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    printf("Digite um número inteiro positivo: ");
    scanf("%d", &n);

    if (pitagorico(n))
        printf("%d é um número pitagórico.\n", n);
    else
        printf("%d não é um número pitagórico.\n", n);

    return 0;
}

int exercicio06(void) {

    /**
     6. Escreva uma função que recebe um vetor de números reais e o seu tamanho por parâmetro
     e devolve a média aritmética dos números do vetor.

     <p> O protótipo da função deve ser: double media(double v[], int tam);
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

int exercicio07(void) {

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
    printf("Quantos numeros você quer digitar? ");
    scanf("%d", &qtd);

    double numeros[qtd];
    preencheVetorDouble(qtd, numeros);

    printf("O desvio padrão dos números digitados é %lf", desvioPadrao(numeros, qtd));

    return 0;
}

int exercicio08(void) {

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

    int dimensao;
    printf("Digite a dimensao da matriz: ");
    scanf("%d", &dimensao);

    if (dimensao <= 0 || dimensao > MAX_DIMENSAO) {
        printf("Dimensao invalida.\n");
        return 1;
    }

    int **matriz = (int **) malloc(dimensao * sizeof(int *));
    int **matrizTransposta = (int **) malloc(dimensao * sizeof(int *));

    for (int i = 0; i < dimensao; i++) {
        matriz[i] = (int *) malloc(dimensao * sizeof(int));
        matrizTransposta[i] = (int *) malloc(dimensao * sizeof(int));
    }

    preencheMatrizQuadrada(matriz, dimensao);

    transposta(matriz, matrizTransposta, dimensao);

    imprimeMatrizQuadrada(matrizTransposta, dimensao);

    for (int i = 0; i < dimensao; i++) {
        free(matriz[i]);
        free(matrizTransposta[i]);
    }

    free(matriz);
    free(matrizTransposta);

    return 0;
}

int exercicio09(void) {

    /**
    <p> 9. Uma matriz quadrada de inteiros é um quadrado mágico se
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

    int matriz[30][30];
    preencheMatrizQuadrada(matriz, 30);

    if (isMagico(matriz, 30))
        printf("A matriz é um quadrado mágico");
    else
        printf("A matriz não é um quadrado mágico");

    return 0;
}

int exercicio10(void) {
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

    printf("Digite os valores do seu Sudoku:\n");

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
        printf("O tabuleiro Sudoku é válido!\n");
    else
        printf("O tabuleiro Sudoku não é válido!\n");

    return 0;
}

int exercicio11(void) {
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

    int matriz[MAX_DIMENSAO][MAX_DIMENSAO];
    int dimensao;

    printf("Digite a dimensão da matriz: ");
    scanf("%d", &dimensao);
    preencheMatrizQuadrada(matriz, dimensao);

    int resposta[dimensao];

    cidadesComEntradaSemSaida(matriz, dimensao, resposta);
    printf("Cidades com entrada e sem saída:\n");
    for (int i = 0; i < dimensao; i++) {
        if (resposta[i]) {
            printf("%d ", i);
        }
    }

    printf("\n");

    cidadesComSaidaSemEntrada(matriz, dimensao, resposta);
    printf("Cidades com saída e sem entrada:\n");
    for (int i = 0; i < dimensao; i++) {
        if (resposta[i]) {
            printf("%d ", i);
        }
    }

    return 0;
}

int exercicio12(void) {

    /**
    10. Escreva uma função que recebe como parâmetro três matrizes quadradas de tamanho no
    máximo 30 X 30, onde a primeira e a segunda matriz correspondem a entrada e a terceira
    corresponde a uma matriz resposta.
    <p>A função deve calcular a multiplicação da primeira pela segunda matriz e guardar o resultado na matriz resposta.
    <p> A função também recebe como parâmetro um inteiro n que indica as dimensões das matrizes.
    <p>
   <p>  O protótipo da função deve ser:
    <p>
   <p>  void transposta(double mat1[30][30], double matRes[30][30], int n);
     */

    int matrizA[30][30];
    int matrizB[30][30];
    int matrizResultado[30][30];

    printf("Preencha a matriz A:\n");
    preencheMatrizQuadrada(matrizA, 30);

    printf("Preencha a matriz B:\n");
    preencheMatrizQuadrada(matrizB, 30);

    multiplica(matrizA, matrizB, matrizResultado, 30);

    printf("O resultado da multiplicação das matrizes A e B é:\n");
    imprimeMatrizQuadrada((int **) matrizResultado, 30);

    return 0;
}

int displayMenuAndGetChoice(void) {
    printf("Exercício 01:\n");
    printf("Exercício 02:\n");
    printf("Exercício 03:\n");
    printf("Exercício 04:\n");
    printf("Exercício 05:\n");
    printf("Exercício 06:\n");
    printf("Exercício 07:\n");
    printf("Exercício 08:\n");
    printf("Exercício 09:\n");
    printf("Exercício 10: \n");
    printf("Exercício 11: \n");
    printf("Exercício 12: \n");
    printf("Digite o número do Exercício que deseja executar");

    int escolha;
    scanf("%d", &escolha);
    return escolha;
}

void executeExercise(int choice) {
    switch (choice) {
        case 1:
            exercicio01();
            break;
        case 2:
            exercicio02();
            break;
        case 3:
            exercicio03();
            break;
        case 4:
            exercicio04();
            break;
        case 5:
            exercicio05();
            break;
        case 6:
            exercicio06();
            break;
        case 7:
            exercicio07();
            break;
        case 8:
            exercicio08();
            break;
        case 9:
            exercicio09();
            break;
        case 10:
            exercicio10();
            break;
        case 11:
            exercicio11();
            break;
        case 12:
            exercicio12();
            break;
        default:
            printf("Opção invalida!\n");
            break;
    }
}

bool getExitChoice(void) {
    int sair;
    do {
        printf("Deseja sair? Digite (1) para Sim ou (0) para Não: ");
        scanf("%d", &sair);
    } while (sair != 0 && sair != 1);
    return sair;
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    bool sair = false;

    do {
        int escolha = displayMenuAndGetChoice();

        if (escolha >= 1 && escolha <= MAX_EXERCISES) {
            executeExercise(escolha);
        } else {
            printf("Opção inválida!\n");
        }
        sair = getExitChoice();
    } while (!sair);
    printf("Obrigado por usar o programa!\n");
    return 0;
}