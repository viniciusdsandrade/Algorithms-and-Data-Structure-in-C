#include <stdio.h>
#include <locale.h>
#include "global.c"

#define MAX_EXERCISES 12
#define MAX_DIMENSAO 30

int exercicio01(void) {

    /**
     <p>1. Considere o c�digo em C abaixo (assuma que no lugar de D seja usado o �ltimo d�gito de
       <p> seu RA):
      <p>  #include <stdio.h>
      <p>  int fun1(int a, int b);
<p>
       <p> int j=1;
       <p> int main(){
        <p>    int i, j;
         <p>   int a = D;///Use o �ltimo d�gito de seu RA.
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
        <p>(a) (0.5 pontos) Determine quais s�o as vari�veis locais e globais deste programa. Para
        <p>cada vari�vel local identifique a que fun��o esta pertence.
<p>
        <p>(b) (1.5 pontos) Mostre o que ser� impresso na tela do computador quando for executado
        <p>este programa (lembre-se de usar o �ltimo d�gito de seu RA no lugar de D).
     */

    int i, j;
    int a = 6;///Use o �ltimo d�gito de seu RA.
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
     <p>2. Escreva uma fun��o que recebe dois n�meros inteiros positivos a e b por par�metro e
  determina se eles s�o amigos ou n�o, devolvendo 1 caso sejam amigos, e 0 caso contr�rio.
<p>
    <p>Dois n�meros s�o amigos se cada n�mero � igual � soma dos divisores pr�prios do outro
(os divisores pr�prios de um n�mero m s�o os divisores estritamente menores que m).
<p>
   <p> Por exemplo:
<p>
    <p>os divisores pr�prios de 220 s�o 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 e 110,
cuja soma � 284;
    <p>e os divisores pr�prios de 284 s�o 1, 2, 4, 71 e 142, cuja soma � 220. Logo, 220 e
284 s�o n�meros amigos.
<p>
   <p> O prot�tipo da fun��o deve ser: int amigos(int a, int b);
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

    /**
    3. Escreva uma fun��o que calcule o m�ximo divisor comum de dois n�meros m e n
    passados por par�metro.

    <p>Voc� deve utilizar a seguinte regra do c�lculo do mdc onde m e n s�o n�meros inteiros positivos:
    <p>mdc(m; n) = m se n = 0
    <p>mdc(m; n) = mdc(n, m%n) se n > 0
    <p> O prot�tipo da fun��o deve ser: int mdc(int m, int n);
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

    /**
     4. Escreva uma fun��o que recebe um valor inteiro positivo n como par�metro
     e devolve um valor inteiro b tal que bk = n para algum inteiro k,
     e b seja o menor poss�vel.
<p>
     Por exemplo: se n = 27 ent�o o valor devolvido deve ser 3,
     j� se n = 12 ent�o o valor devolvido deve ser 12.
<p>
     N�o use fun��es de bibliotecas na sua solu��o.
<p>
     O prot�tipo da fun��o deve ser: int menor_base_log(int n);
     */

    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    printf("O menor valor de b tal que bk = %d � %d", n, menor_base_log(n));

    return 0;
}

int exercicio05(void) {

    /**
    5. Um inteiro positivo n � pitag�rico se existem inteiros positivos a e b tais que a^2+b^2 = n.
    Por exemplo, 13 � pitag�rico pois 2^2 + 3^2 = 13.
<p>
    <p>(a) Escreva uma fun��o que recebe como par�metro tr�s inteiros a, b e n, e que devolve
    1 caso a^2+b^2 = n e devolve 0 caso contr�rio.
<p>
    O prot�tipo da fun��o deve ser: int teste(int a, int b, int n);
<p>
    (b) Utilize a fun��o do item anterior e escreva uma outra fun��o que recebe como par�metro
    um inteiro positivo n e verifica se n � pitag�rico, devolvendo 1 caso n seja
    pitag�rico e 0 caso contr�rio.
<p>
    O prot�tipo da fun��o deve ser: int pitagorico(int n);
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

    if (pitagorico(n))
        printf("%d � um n�mero pitag�rico.\n", n);
    else
        printf("%d n�o � um n�mero pitag�rico.\n", n);

    return 0;
}

int exercicio06(void) {

    /**
     6. Escreva uma fun��o que recebe um vetor de n�meros reais e o seu tamanho por par�metro
     e devolve a m�dia aritm�tica dos n�meros do vetor.

     <p> O prot�tipo da fun��o deve ser: double media(double v[], int tam);
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

    /**
    7. Escreva uma fun��o que recebe um vetor de n�meros reais e o seu tamanho
    por par�metro e devolve o desvio padr�o dos n�meros do vetor usando a
    seguinte f�rmula:
<p>
     Desvio padr�o = ?((?(xi - x)�) / (n - 1))
<p>
     onde n � o n�mero de elementos.
     <p>
     O prot�tipo da fun��o deve ser: double desvioPadrao(double v[], int tam);
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

    /**
    8. Escreva uma fun��o que recebe como par�metro duas matrizes quadradas de tamanho
    no m�ximo 30 X 30, onde a primeira matriz corresponde a uma matriz de entrada e a
    segunda corresponde a uma matriz resposta.
<p>
   <p> A fun��o deve calcular a transposta da matriz de entrada e guardar o resultado na matriz resposta.
    <p>A fun��o tamb�m recebe como par�metro um inteiro n que indica as dimens�es das matrizes.
<p>
    O prot�tipo da fun��o deve ser:
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
    <p> 9. Uma matriz quadrada de inteiros � um quadrado m�gico se
    <p> a) a soma dos elementos de cada linha,
    <p> b) a soma dos elementos de cada coluna,
    <p> c) a soma dos elementos da diagonal principal
    <p> e a soma da diagonal secund�ria s�o todos iguais.
<p>
     <p>A matriz abaixo � um exemplo de quadrado m�gico:
<p>
    <p>[3  4  8]
    <p>[10 5  0]
    <p>[2  6  7]
<p><p>

    Escreva uma fun��o que recebe como par�metro uma matriz quadrada de tamanho no
    m�ximo 30 X 30, e suas dimens�es n, e determina se ela � um quadrado m�gico devolvendo
    1 caso seja e 0 caso contr�rio.
<p>
     O prot�tipo da fun��o deve ser: int magico(int mat[30][30], int n);
     */

    int matriz[30][30];
    preencheMatrizQuadrada(matriz, 30);

    if (isMagico(matriz, 30))
        printf("A matriz � um quadrado m�gico");
    else
        printf("A matriz n�o � um quadrado m�gico");

    return 0;
}

int exercicio10(void) {
    /**
    10. No jogo Sudoku temos uma matriz 9 X 9 dividida em 9 quadrados de 3 X 3 preenchidos
    previamente com alguns n�meros entre 1 e 9 (veja o exemplo � esquerda abaixo).
<p>
    Uma solu��o para uma inst�ncia do jogo consiste no preenchimento de todas as posi��es vazias
    com n�meros entre 1 e 9 respeitando-se as seguintes regras:
<p>
    <p>(a) N�o pode haver n�meros repetidos em um mesmo quadrado, ou seja, cada n�mero
    entre 1 e 9 deve aparecer exatamente uma vez em cada quadrado.
    <p>(b) N�o pode haver n�meros repetidos em nenhuma linha da matriz.
    <p>(c) N�o pode haver n�meros repetidos em nenhuma coluna da matriz.
<p>
    Escreva uma fun��o que receba uma matriz 9 X 9 como par�metro, que represente uma
    proposta de solu��o para um Sudoku, e teste se a matriz � uma solu��o v�lida para o jogo,
    devolvendo True em caso verdadeiro e False, caso contr�rio.
     <p>
    A seguinte fun��o deve ser implementada:
    */

    printf("Digite os valores do seu Sudoku:\n");

    int tabuleiro[9][9];
    bool tabuleiroValido = true; // Assume que o tabuleiro � v�lido at� encontrar uma viola��o

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
        printf("O tabuleiro Sudoku � v�lido!\n");
    else
        printf("O tabuleiro Sudoku n�o � v�lido!\n");

    return 0;
}

int exercicio11(void) {
    /**
    11. Suponha que uma matriz bin�ria represente liga��es entre cidades, e que, se uma posi��o
    (i,j) possui o valor 1, ent�o h� uma estrada da cidade i para a cidade j. Seja o seguinte

    <p>exemplo de matriz:
 <p>
    <p>[0 1 1]
   <p> [0 0 0]
    <p>[1 0 0]
 <p>
  <p>  Neste caso, h� caminhos dispon�veis da cidade 0 para a 1 e 2, e da 2 para 0.
    Para cada item abaixo escreva uma fun��o que recebe como par�metro uma matriz quadrada
    indicando as estradas entre as cidades, um inteiro n correspondendo as dimens�es
    da matriz e um vetor resposta (que ter� tamanho n).
 <p>
    <p>  O prot�tipo da fun��o deve ser:
      <p>void verifica(int mat[30][30], int n, int resposta[]);
 <p>
   <p> a) A fun��o deve determinar as cidades com entrada e sem sa�da, indicando isto no vetor
    resposta, tal que resposta[i] recebe 1 caso a cidade i satisfa�a esta propriedade e 0
    caso contr�rio.
<p>
    <p>b) A fun��o deve determinar as cidades com sa�da mas sem entrada, indicando isto no
    vetor resposta, tal que resposta[i] recebe 1 caso a cidade i satisfa�a esta propriedade
    e 0 caso contr�rio.
    */

    int matriz[MAX_DIMENSAO][MAX_DIMENSAO];
    int dimensao;

    printf("Digite a dimens�o da matriz: ");
    scanf("%d", &dimensao);
    preencheMatrizQuadrada(matriz, dimensao);

    int resposta[dimensao];

    cidadesComEntradaSemSaida(matriz, dimensao, resposta);
    printf("Cidades com entrada e sem sa�da:\n");
    for (int i = 0; i < dimensao; i++) {
        if (resposta[i]) {
            printf("%d ", i);
        }
    }

    printf("\n");

    cidadesComSaidaSemEntrada(matriz, dimensao, resposta);
    printf("Cidades com sa�da e sem entrada:\n");
    for (int i = 0; i < dimensao; i++) {
        if (resposta[i]) {
            printf("%d ", i);
        }
    }

    return 0;
}

int exercicio12(void) {

    /**
    10. Escreva uma fun��o que recebe como par�metro tr�s matrizes quadradas de tamanho no
    m�ximo 30 X 30, onde a primeira e a segunda matriz correspondem a entrada e a terceira
    corresponde a uma matriz resposta.
    <p>A fun��o deve calcular a multiplica��o da primeira pela segunda matriz e guardar o resultado na matriz resposta.
    <p> A fun��o tamb�m recebe como par�metro um inteiro n que indica as dimens�es das matrizes.
    <p>
   <p>  O prot�tipo da fun��o deve ser:
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

    printf("O resultado da multiplica��o das matrizes A e B �:\n");
    imprimeMatrizQuadrada((int **) matrizResultado, 30);

    return 0;
}

int displayMenuAndGetChoice(void) {
    printf("Exerc�cio 01:\n");
    printf("Exerc�cio 02:\n");
    printf("Exerc�cio 03:\n");
    printf("Exerc�cio 04:\n");
    printf("Exerc�cio 05:\n");
    printf("Exerc�cio 06:\n");
    printf("Exerc�cio 07:\n");
    printf("Exerc�cio 08:\n");
    printf("Exerc�cio 09:\n");
    printf("Exerc�cio 10: \n");
    printf("Exerc�cio 11: \n");
    printf("Exerc�cio 12: \n");
    printf("Digite o n�mero do Exerc�cio que deseja executar");

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
            printf("Op��o invalida!\n");
            break;
    }
}

bool getExitChoice(void) {
    int sair;
    do {
        printf("Deseja sair? Digite (1) para Sim ou (0) para N�o: ");
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
            printf("Op��o inv�lida!\n");
        }
        sair = getExitChoice();
    } while (!sair);
    printf("Obrigado por usar o programa!\n");
    return 0;
}