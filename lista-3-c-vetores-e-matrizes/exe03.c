#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include "global.h"

int exercicio01(void) {

    /*
     1 - Escreva um programa que leia um vetor de ate 50 numeros reais e calcule a
     media destes valores.
     */

    printf("\nExe01 - Lista03\n");

    double vetor[MAX], sum = 0.0, media = 0.0;
    int n;

    printf("Digite um valor entre 1 e 50: ");
    scanf("%d", &n);

    verifyInput(n, 1, 50) == false ? printf("Valor invalido"), 0 : 1;
    sum = sumArray(n, vetor);
    imprimeVetorDouble(vetor, n);

    printf("Soma: %.2lf\n", sum);

    media = mediaVetorDouble(vetor, n);
    printf("%.2lf / %d =  %.2lf\n", sum, n, media);

    return 0;
}

int exercicio02(void) {

    /*
     2 - Escreva um programa que leia um vetor de ate 50 numeros reais e calcule o
     desvio padrao destes valores.
     */

    printf("\nExe02 - Lista03\n");
    double vetor[MAX], dp = 0.0;
    int n;

    printf("Digite um valor entre 1 e 50: ");
    scanf("%d", &n);

    verifyInput(n, 1, 50) == false ? printf("Valor invalido"), 0 : 1;

    if (n < 8)
        preencheVetorDouble(vetor, n);
    else
        preencheVetorDoubleRandom(vetor, n, n, 0);

    double media = mediaVetorDouble(vetor, n);

    for (int i = 0; i < n; i++)
        // desvioPadrao += (vetor[i] - media)*(vetor[i] - media) ;
        dp += potenciaDouble(vetor[i] - media, 2);

    dp = raizQuadradaDouble(dp / n);

    printf("Vetor: ");
    imprimeVetorDouble(vetor, n);

    printf("media: %.2lf\n", media);
    printf("Desvio padrao: %.2lf\n", dp);

    return 0;
}

int exercicio03(void) {
    /*
     3 - Mostre o que o programa abaixo ir? imprimir caso seja executado (execute o
     programa na m?o).

     #include <stdio.h>
     int main(){
     int v1[9], v2[9], n=123456789;
     int i, j, k;
     for(i = 0; n !=0; i++){
     v1[i] = n % 10;
     n = n / 10;
     v2[i] = 1;
     }
     for(j=0; j<i; j++){
     printf("%d", v1[j]);
     }
     printf("\n");
     for(j=0; j<i; j++){
     for(k=1; k <= v1[j]; k++){
     v2[j] = v2[j]*2;
     }
     }
     for(j=0; j<i; j++){
     printf("%d\n", v2[j]);
     }
     }
     */

    printf("\nExe03 - Lista03\n");

    int v1[9], v2[9], n = 123456789;

    int i, j, k;

    for (i = 0; n != 0; i++) {
        v1[i] = n % 10;
        n = n / 10;
        v2[i] = 1;
    }

    for (j = 0; j < i; j++) {
        printf("%d", v1[j]);

    }
    printf("\n");

    for (j = 0; j < i; j++) {
        for (k = 1; k <= v1[j]; k++) {
            v2[j] = v2[j] * 2;

        }
    }

    for (j = 0; j < i; j++) {
        printf("%d\n", v2[j]);
    }

    return 0;
}

int exercicio04(void) {

    /*
     4 - Dadas duas sequencias de n e m valores inteiros, onde n e m, escreva um
     programa que verifica quantas vezes a primeira sequ?ncia ocorre na segunda.

     Exemplo:
     primeira sequencia: 1 0 1
     segunda sequencia: 1 1 0 1 0 1 0 0 1 1 0 1 0
     Resultado: 3
     */

    printf("\nExe04 - Lista03\n");
    int sequencia1[MAX], sequencia2[MAX];
    int m, n, count = 0;

    printf("Digite o tamanho da primeira sequencia: ");
    scanf("%d", &n);

    printf("Digite o tamanho da segunda sequencia: ");
    scanf("%d", &m);

    printf("Digite os valores da primeira sequencia: \n");
    preencheVetorInt(sequencia1, n);

    printf("Digite os valores da segunda sequencia: \n");
    preencheVetorInt(sequencia2, m);

    int ocorrencias = verificaOcorrenciaVetorInt(sequencia1, n, sequencia2, m);
    printf("Resultado: %d\n", count);

    return 0;
}

int exercicio05(void) {

    /*
     5 - Faca um programa que leia duas sequencias de numeros inteiros distintos e
     salve cada sequencia em um vetor. Suponha que o numero maximo de elementos de
     uma sequencia e 50. Suponha que cada um destes vetores represente um conjunto
     contendo os  elementos nele armazenados. O programa deve entao salvar em um terceiro vetor
     o  resultado da intersesso dos dois primeiros vetores e imprimir o resultado.

     Exemplo:
     v1: [1, 2, 3, 4, 5]
     v2: [2, 5, 7, 1, -9, 18]
     Resultado: [1, 2, 5]
     */

    printf("Exe05 - Lista03\n");

    int v1[MAX], v2[MAX], tam1, tam2;

    printf("Dimensao vetor1: ");
    scanf("%d", &tam1);

    printf("Dimensao vetor2: ");
    scanf("%d", &tam2);

    verifyInput(tam1, 1, 50) == false ? printf("Valor invalido"), 0 : 1;
    verifyInput(tam2, 1, 50) == false ? printf("Valor invalido"), 0 : 1;

    if (tam1 < 8 || tam2 < 8) {
        printf("Vetor1\n");
        preencheVetorInt(v1, tam1);

        printf("Vetor2\n");
        preencheVetorInt(v2, tam2);

    } else {
        srand(time(NULL)); // inicializa semente para números aleatórios
        preencheVetorIntRandom(v1, tam1, tam1, 0);
        preencheVetorIntRandom(v2, tam2, tam2, 0);
    }

    linha(30, '*');

    printf("Vetor1: ");
    imprimeVetorInt(v1, tam1);

    printf("Vetor2: ");
    imprimeVetorInt(v2, tam2);

    // Algoritmo para detectar qual o menor vetor
    int index = 0, aux = 0;

    if (tam1 < tam2)
        index = tam1;
    else
        index = tam2;

    int v3[index];

    for (int i = 0; i < tam1; i++) {
        for (int j = 0; j < tam2; j++) {
            if (v1[i] == v2[j]) {
                v3[aux] = v1[i];
                aux++;
                break;
            }
        }
    }

    int contador = 0;
    for (int i = 0; i < index; ++i) {
        if (v3[i] != 0)
            contador++;
    }

    int indice = 0, novoVetor[contador];

    for (int i = 0; i < index; ++i) {
        if (v3[i] != 0) {
            novoVetor[indice] = v3[i];
            indice++;
        }
    }

    printf("Resultado: ");
    imprimeVetorInt(novoVetor, aux);
    linha(30, '*');

    return 0;
}

int exercicio06(void) {

    /*
    6 - Faca um programa que leia duas sequencias de numeros inteiros distintos e salve cada
    sequencia em um vetor. Suponha que o numero maximo de elementos de uma sequencia
    e 50. Suponha que cada um destes vetores represente um conjunto contendo os elementos
    nele armazenados. O programa deve entao salvar em um terceiro vetor o resultado da
    uni?o dos dois primeiros vetores e imprimir o resultado.

    Exemplo:
    v1: [1, 2, 3, 4, 5]
    v2: [2, 5, 7, 1, -9, 18]
    Resultado: [1, 2, 3, 4, 5, 7, -9, 18]
    */
    printf("\nExe06 - Lista03\n");

    int v1[MAX], v2[MAX], v3[MAX];
    int tam1 = 0, tam2 = 0;

    printf("Tamanho v1: ");
    scanf("%d", &tam1);

    printf("Tamanho v2: ");
    scanf("%d", &tam2);

    printf("Vetor1:\n");
    preencheVetorInt(v1, tam1);

    printf("Vetor2:\n");
    preencheVetorInt(v2, tam2);

    imprimeVetorInt(v1, tam1);
    linha(10, '*');

    imprimeVetorInt(v2, tam2);
    linha(10, '*');

    // Algoritmo para unir 2 vetores de dimens?es diferentes
    int tam3 = tam1 + tam2, index = 0;

    // Copia os elementos do vetor1 para o vetor3
    for (index = 0; index < tam1; index++)
        v3[index] = v1[index];

    // Copia os elementos do vetor2 para o vetor3
    for (int i = 0; i < tam2; i++) {
        v3[index] = v2[i];
        index++;
    }

    // Algoritmo para remover elementos duplicados
    int novoTam = 0, v3SemDuplicados[100];

    for (int i = 0; i < tam3; i++) {
        int duplicado = 0;
        for (int j = 0; j < novoTam; j++) {
            if (v3[i] == v3SemDuplicados[j]) {
                duplicado = 1;
                break;
            }
        }
        if (!duplicado) {
            v3SemDuplicados[novoTam] = v3[i];
            novoTam++;
        }
    }

    // algoritmos para pegar elementos do vetor3SemDuplicados e colocar no vetor3Final
    int v3Final[100];
    for (int i = 0; i < novoTam; i++)
        v3Final[i] = v3SemDuplicados[i];

    imprimeVetorInt(v3Final, novoTam);

    return 0;
}

int exercicio07(void) {

    /*
     7 - Faca um programa que leia duas sequencias de numeros inteiros ordenados e
     salve cada sequencia em um vetor. Suponha que o numero maximo de elementos de
     uma  sequencia e 50. Escreva um programa para intercalar os valores dos dois
     vetores em um  terceiro vetor, em ordem crescente.

     Exemplo:
     v1 = [1, 3, 5, 5, 7, 9, 10]
     v2 = [2, 2, 4, 6, 8, 8, 10]
     v3 = [1, 2, 2, 3, 4, 5, 5, 6, 7, 8, 8, 9, 10, 10]
     */

    printf("\nExe07 - Lista03\n");

    int v1[MAX], v2[MAX], v3[50];
    int tam = 0;

    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &tam);

    verifyInput(tam, 1, 50) == false ? printf("Valor invalido"), 0 : 1;

    int index = 0;

    if (tam < 8) {
        printf("Vetor1\n");
        preencheVetorInt(v1, tam);

        printf("Vetor2\n");
        preencheVetorInt(v2, tam);
    } else {
        preencheVetorIntRandom(v1, tam, tam, 0);
        preencheVetorIntRandom(v2, tam, tam, 0);
    }

    printf("Vetor1: ");
    imprimeVetorInt(v1, tam);

    printf("Vetor2: ");
    imprimeVetorInt(v2, tam);

    // Intercalação dos vetores em v3
    for (int i = 0; i < tam; ++i) {
        v3[2 * i] = v1[i];
        v3[2 * i + 1] = v2[i];
    }

    // bubbleSort com intuito de ordernar o vetor
    buubleSort(v3, tam);

    printf("VetorUnicaoCrescente: ");
    imprimeVetorInt(v3, index);

    return 0;
}

int exercicio08(void) {

    /*
     8 - Faca um programa que calcule o produto interno de dois vetores u e v de
     mesmo tamanho n lidos do teclado. O programa deve ler primeiramente o valor
     de n e em seguida deve ler duas sequencias de mesmo tamanho de numeros reais
     e  salvar cada sequencia em um vetor. Suponha que o numero maximo de elementos
     de uma sequencia e 50. O programa deve entao calcular o produto interno dos vetores
     lidos.
     */

    printf("\nExe08 - Lista03\n");

    double vet1[MAX], vet2[MAX], produtoInterno[MAX], soma = 0.0;
    int tam = 0;

    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &tam);

    verifyInput(tam, 1, 50) == false ? printf("Valor invalido"), 0 : 1;

    if (tam < 4) {
        preencheVetorDouble(vet1, tam);
        preencheVetorDouble(vet2, tam);
    } else {
        preencheVetorDoubleRandom(vet1, tam, tam, 0);
        preencheVetorDoubleRandom(vet2, tam, tam, 0);
    }

    soma = produtoInternoDouble(vet1, vet2, produtoInterno, soma, tam);

    linha(tam * 15, '*');
    printf("vet1: ");
    imprimeVetorDouble(vet1, tam);

    printf("vet2: ");
    imprimeVetorDouble(vet2, tam);

    printf("produtoInternoDouble: ");
    imprimeVetorDouble(produtoInterno, tam);

    printf("soma dos produtos: %.02lf\n", soma);
    linha(tam * 15, '*');

    return 0;
}

int exercicio09(void) {

    /*
     9 - Escreva um programa que leia uma sequencia de numeros inteiros e os salva
     em um vetor. Assuma que o tamanho maximo da sequencia e 50. Em seguida o programa
     deve ler um outro numero inteiro C. O programa deve entao encontrar dois numeros
     de 2  posicoes distintas do vetor cuja multiplicacao seja C e imprimi-los. Caso nao
     existam tais numeros, o programa deve informar isto.

     Exemplo: Se vetor = [2, 4, 5,10, 7] e C = 35 entao o programa deve imprimir
     5 e 7". Se C = 31 entao o programa deve imprimir nao existem tais numeros".
     */

    printf("\nExe09 - Lista03\n");

    int tam = 0, comum = 0, cont = 0;
    int vet[MAX], multiplo[MAX];

    printf("Digite o tamanho do vetor:");
    scanf("%d", &tam);

    verifyInput(tam, 1, 50) == false ? printf("Valor invalido"), 0 : 1;

    preencheVetorInt(vet, tam);

    printf("Digite um valor para comum:");
    scanf("%d", &comum);

    for (int i = 0; i < tam; ++i) {
        for (int j = i + 1; j < tam; ++j) {
            if (vet[i] * vet[j] == comum) {
                printf("%d x %d = %d\n", vet[i], vet[j], comum);
                multiplo[cont] = vet[i];
                cont = cont + 2;
            }
        }
    }

    if (cont == 0)
        printf("Nao existem multiplos de %d\n", comum);
    else
        printf("total de multiplos: %d\n", cont);

    return 0;
}

int exercicio10(void) {

    /*
     10 - Escreva um programa que leia uma sequencia de numeros inteiros positivos
     maiores que 1 e os salva em um vetor. O programa deve ler um numero inteiro n que
     representa o  numero de elementos da sequencia, depois em seguida os n numeros e os salvar
     em um  vetor v. Assuma que o tamanho maximo da sequencia e 50.
     O programa deve entao imprimir um quadrado de n linhas por n colunas onde em
     cada posicao (i, j) (onde i = 0, . . . ,n?1 e j = 0, . . . ,n?1) deste quadrado
     devera ser impresso 1 caso os numeros v[i] e v[j] sejam coprimos e 0 caso contrario.
     Os pares de numeros v[i] e v[j] sao coprimos se nao ha nenhum divisor d > 1
     que seja comum a ambos. Por exemplo 15 e 8 sao coprimos, pois os divisores de 8, que
     sao 2, 4 e 8, nao sao divisores de 15. Abaixo temos um exemplo de execucao do programa para
     n = 6
     e v = [2, 3, 4, 5, 6, 7].
          v[0] v[1] v[2] v[3] v[4] v[5]
     v[0]  0    1    0    1    0    1
     v[1]  1    0    1    1    0    1
     v[2]  0    1    0    1    0    1
     v[3]  1    1    1    0    1    1
     v[4]  0    0    0    1    0    1
     v[5]  1    1    1    1    1    0


     Note no exemplo que 2 (v[0]) e coprimo de 3 (v[1]), 5 (v[3]) e 7 (v[5]).
     */

    printf("\nExe10 - Lista03");
    int vetor[MAX], n;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    printf("Digite os valores do vetor: \n");
    preencheVetorInt(vetor, n);

    printf("Matriz: \n");
    for (int i = 0; i < n; i++) {
        printf("vetor[%d] ", i + 1);
        for (int j = 0; j < n; j++) {
            if (i == j)
                printf("0 ");
            else {
                if (mdc(vetor[i], vetor[j]) == 1)
                    printf("1 ");
                else
                    printf("0 ");
            }
        }
        putchar('\n');
    }
    return 0;
}

int exercicio11(void) {

    /*
    11 - Faca um programa que peca para o usuario digitar 5 valores inteiros em 2 vetores distintos.
    Em Seguida descubra quais sao os elementos que estao em comum nos dois vetores e seus respectivos indices;
    */

    printf("\nExercicio 01\n");
    int vetor1[MAX], vetor2[MAX], umEmComum = 0;

    preencheVetorInt(vetor1, 5);
    preencheVetorInt(vetor2, 5);

    printf("Elementos iguais nos dois vetores\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (vetor1[i] == vetor2[j]) {
                printf("elemento: [%d] | vetor2[%d]=vetor1[%d] \n", vetor2[j], j, i);
                umEmComum++;
            }
        }
    }
    if (umEmComum == 0)
        printf("nao ha elementos iguais em suas respectivas posicoes\n");

    return 0;
}

int exercicio12(void) {

    /*
    12 - Faca um programa que peca para o usuario digitar 5 valores reais em 2 vetores distintos.
    Em seguida calcule o produto interno entre os dois vetores.
    */

    printf("\nExercicio 02\n");
    double vetor1[5], vetor2[5], res = 0.0;

    printf("Digite os valores do vetor1: \n");
    preencheVetorDouble(vetor1, 5);
    linha(30, '*');

    printf("Digite os valores do vetor2: \n");
    preencheVetorDouble(vetor2, 5);
    linha(30, '*');

    res = produtoInternoDouble(vetor1, vetor2, vetor1, res, 5);

    printf("Produto Interno: %.2lf\n", res);

    return 0;
}

int exercicio13(void) {

    /*
     13 - Codigo para fazer a leitura e impressao de uma matriz
    */

    printf("\nExercicio 03\n");
    double mat1[MAX][MAX];
    int n;

    printf("Digite o tamanho da matriz: ");
    scanf("%d", &n);

    printf("Digite os valores da matriz: \n");
    preencheMatrizDouble(mat1, n, n);

    printf("Matriz: \n");
    imprimeMatrizDouble(mat1, n, n);

    linha(30, '*');

    return 0;
}

int exercicio14(void) {

    /*
    14 - Faca um programa que leia valores de 2 matriz nxn sendo n um valor inteiro
    digitado pelo usuario. Em seguida atribua valores para cada uma das posicoes
    dessas matrizes E faca a soma dessas matrizes.
    */

    printf("\nExercicio 04\n");

    double m1[MAX][MAX], m2[MAX][MAX], s3[MAX][MAX];
    int n;

    printf("Digite a dimensao nxn da matriz: ");
    scanf("%d", &n);

    printf("1º Matriz: \n");
    preencheMatrizDouble(m1, n, n);
    linha(30, '*');

    printf("2º Matriz: \n");
    preencheMatrizDouble(m2, n, n);

    somaMatrizesDouble(m1, m2, s3, n, n);

    imprimeMatrizDouble(s3, n, n);

    putchar('\n');

    linha(30, '*');
    return 0;
}


int exercicio15(void) {

    /*
    15 - Faca um algoritmo para multiplicar duas matrizes de dimensao nxn
    */

    printf("\nExercicio 15\n");
    int m1[MAX][MAX], m2[MAX][MAX], m3[MAX][MAX], n;

    printf("Digite a dimensao nxn da matriz: ");
    scanf("%d", &n);

    printf("Matriz 1: \n");
    preencheMatrizInt(m1, n, n);

    printf("Matriz 2: \n");
    preencheMatrizInt(m2, n, n);

    multiplicaMatrizInt(m1, m2, m3, n);

    printf("*********************************\n");
    printf("Matriz 1: \n");
    imprimeMatrizInt(m1, n, n);

    printf("*********************************\n");
    printf("Matriz 2: \n");
    imprimeMatrizInt(m2, n, n);

    printf("*********************************\n");
    printf("Matriz multiplicao\n");
    imprimeMatrizInt(m3, n, n);

    return 0;
}


int exercicio16(void) {

    /*
     16 - Faca um algoritmo para calcular a matriz transposta de dimensao nxn
     */

    printf("\nExercicio 06\n");

    printf("Digite a dimensao nxn da matriz: ");
    int m1[MAX][MAX], mt1[MAX][MAX], n;

    scanf("%d", &n);

    printf("Matriz 1: \n");
    preencheMatrizInt(m1, n, n);

    printf("Matriz 1: \n");
    imprimeMatrizInt(m1, n, n);

    printf("Matriz transposta: \n");
    matrizTranspostaInt(m1, n, n);

    linha(30, '*');
    return 0;
}

int exercicio17(void) {
    /*
     17 - Escreva um programa que le 10 numeros inteiros e os salva em um
     vetor. Em seguida o programa deve encontrar a posicao do maior
     elemento do vetor e imprimir esta posicao.
     */

    printf("\nExercicio 07\n");

    int vetor[MAX];

    preencheVetorInt(vetor, 10);

    int maior = vetor[0];
    int menor = vetor[0];

    for (int i = 0; i < 10; i++) {
        if (vetor[i] > maior)
            maior = vetor[i];

        if (vetor[i] < menor)
            menor = vetor[i];
    }

    printf("Maior elemento: %d\n", maior);
    printf("Menor elemento: %d\n", menor);

    return 0;
}

int exercicio18(void) {

    /*
     18 - Escreva um programa que le 10 numeros ponto
     flutuante e os salva em um vetor. Em seguida o
     programa deve calcular a media dos valores armazenados
     no vetor e imprimir este valor.
     */

    printf("\nExercicio 18\n");

    float vetor[10], soma = 0.0, media;

    preencheVetorFloat(vetor, 10);
    soma = somaElementosVetorFloat(vetor, 10);
    media = soma / 10;

    printf("%.2lf / %d =  %.2lf\n", soma, 10, media);

    return 0;
}

int exercicio19(void) {

    /*
    19 - Escreva um programa que le 10 numeros inteiros e os salva em um vetor.
    Em seguida o programa deve encontrar a posicao do maior e do menor elemento
    elemento do vetor e imprimir esta posicao.
    */

    printf("\nExercicio 19\n");

    printf("Digite 10 numero inteiros: \n");

    int vetor[MAX], maior, menor, pMaior = 0, pMenor = 0;

    preencheVetorInt(vetor, 10);

    maior = vetor[0];
    menor = vetor[0];

    for (int i = 1; i < 10; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
            pMaior = i;
        }
        if (vetor[i] < menor) {
            menor = vetor[i];
            pMenor = i;
        }
    }

    printf("Maior elemento: vetor[%d] = %d\n", pMaior, maior);
    printf("Menor elemento: vetor[%d] = %d\n", pMenor, maior);

    return 0;
}

int exercicio20(void) {
    return 0;
}

int exercicio21(void) {

    /*
     21 - Escreva um programa que leia todas as posicoes de uma matriz 10 x 10 de inteiros.
     O programa deve entao exibir o numero de posicoes nao nulas na matriz.
     */

    printf("\nExercicio 21\n");

    int matriz[MAX][MAX], pos[MAX], cont = 0, n;

    printf("Digite a dimensao da matriz nxn: ");
    scanf("%d", &n);

    printf("Digite os valores da matriz: \n");
    preencheMatrizIntRandom(matriz, n, n, 10, 0);

    printf("Matriz: \n");
    imprimeMatrizInt(matriz, n, n);

    contaPosicoesNaoNulas(matriz, n, n);

    return 0;
}

int exercicio22(void) {
    printf("\nExercicio 22\n");

    printf("Digite a dimensao da matriz nxn: ");
    int n, matriz[MAX][MAX];
    scanf("%d", &n);

    int maior = matriz[0][0];
    int menor = matriz[0][0];

    int freqMaior = 0;
    int freqMenor = 0;

    // Agora que temos o maior e o menor elementos,
    // basta percorrermos um loop para detectarmos a frequencia de cada elemento
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] == maior)
                freqMaior++;

            if (matriz[i][j] == menor)
                freqMenor++;
        }
    }

    linha(50, '*');
    printf("Maior elemento: %d\n", maior);
    printf("Menor elemento: %d\n", menor);
    printf("Frequencia do maior elemento: %d\n", freqMaior);
    printf("Frequencia do menor elemento: %d\n", freqMenor);
    linha(50, '*');

    return 0;
}

int exercicio23(void) {

    /*
     23 - Escreva um programa que le todos os elementos de uma matriz 4 x 4
     e mostra a matriz e a sua transposta na tela.
     */

    printf("\nExercicio 23\n");
    int matriz[MAX][MAX];

    printf("Digite os valores da matriz 4x4: \n");
    preencheMatrizInt(matriz, 4, 4);

    printf("Matriz: \n");
    imprimeMatrizInt(matriz, 4, 4);

    printf("Matriz transposta: \n");
    matrizTranspostaInt(matriz, 4, 4);

    return 0;
}

int exercicio24(void) {
    /*
    24 - Faca um programa que leia uma matriz de dimensao arbitraria definida pelo usuario
    a) encontre o elemento com maior frequencia na matriz
    b) a frequencia do maior elemento
    c) as posicoes que se encontram o maior elemento
    d) encontre o elemento com menor frequencia na matriz
    e) a frequencia do menor elemento
    f) as posicoes que se encontram o menor elemento
    g) faca uma matriz que mostre a frequencia dos seus respectivos elementos 1 a 1
    Caso  haja mais de um elemento com maior ou menor frequencia, printar os dois elementos, inclusive suas posi??es
     */
    printf("\nExerc?cio 24\n");

    int matriz[MAX][MAX], matrizFrequencia[MAX][MAX];
    int l, c;
    int maior_elemento, menor_elemento;
    int contagemMaiorElemento[MAX] = {0}, contagemMenorElemento[MAX] = {0};
    int frequenciaMaiorElemento = 0, frequenciaMenorElemento = MAX;

    printf("Numero de linhas da matriz: ");
    scanf("%d", &l);

    printf("Numero de colunas da matriz: ");
    scanf("%d", &c);

    // Algoritmo para calcular a frequencia de todos os elementos da matriz
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            int elementoAtual = matriz[i][j];
            int frequencia = 0;
            for (int k = 0; k < l; k++) {
                for (int m = 0; m < c; m++) {
                    if (matriz[k][m] == elementoAtual)
                        frequencia++;
                }
            }
            matrizFrequencia[i][j] = frequencia;
        }
    }
    printf("Matriz Frequencia:\n");

    linha(50, '*');

    maior_elemento = matriz[0][0];
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            int elemento = matriz[i][j];
            contagemMaiorElemento[elemento]++;
            if (contagemMaiorElemento[elemento] > frequenciaMaiorElemento) {
                frequenciaMaiorElemento = contagemMaiorElemento[elemento];
                maior_elemento = elemento;
            }
        }
    }

    printf("O elemento com maior frequencia: %d\n", maior_elemento);
    printf("Frequencia do maior elemento: %d\n", frequenciaMaiorElemento);
    printf("Posicoes do maior elemento:\n");

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            if (matriz[i][j] == maior_elemento)
                printf("(%d, %d)\n", i, j);
        }
    }

    linha(50, '*');

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; ++j) {
            int elemento = matriz[i][j];
            contagemMenorElemento[elemento]++;
        }
    }

    menor_elemento = matriz[0][0];
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; ++j) {
            int elemento = matriz[i][j];
            if (contagemMenorElemento[elemento] < frequenciaMenorElemento) {
                frequenciaMenorElemento = contagemMenorElemento[elemento];
                menor_elemento = elemento;
            }
        }
    }

    printf("O elemento com menor frequencia: %d\n", menor_elemento);
    printf("Frequencia do menor elemento: %d\n", frequenciaMenorElemento);
    printf("Posicoes do menor elemento:\n");

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            if (matriz[i][j] == menor_elemento)
                printf("(%d, %d)\n", i, j);
        }
    }

    linha(50, '*');

    return 0;
}

int exercicio25(void) {

    /*
    25 - Faca um programa para realizar operacoes com matrizes que tenha as
    seguintes funcionalidades:
    I Um menu para escolher a operacao a ser realizada:
    1 - Leitura de uma matriz1.
    2 - Leitura de uma matriz2.
    3 - Impressao da matriz1 e matriz2.
    4 - Calculo da soma de matriz1 com matriz2, e impressao do resultado.
    5 - Calculo da multiplicacao de matriz1 com matriz2, e impress~ao do
    resultado.
    6 - Calculo da subtracao de matriz1 com matriz2, e impressao do resultado.
    7 - Impressao da transposta de matriz1 e matriz2.
    */

    printf("\nExercicio 25 \n");

    int choice = 0;
    int matriz1[MAX][MAX], matriz2[MAX][MAX], matrizSoma[MAX][MAX];
    int l1 = 0, c1 = 0, l2 = 0, c2 = 0;

    do {
        printf("Escolha uma opcao: \n");
        printf("0 - Sair\n");
        printf("1 - Leitura de uma matriz1.\n");
        printf("2 - Leitura de uma matriz2.\n");
        printf("3 - Impressao da matriz1 e matriz2.\n");
        printf("4 - Calculo da soma de matriz1 com matriz2, e impressao do resultado.\n");
        printf("5 - Calculo da multiplicacao de matriz1 com matriz2, e impressao do resultado.\n");
        printf("6 - Calculo da subtracao de matriz1 com matriz2, e impressao do resultado.\n");
        printf("7 - Impressao da transposta de matriz1 e matriz2.\n");

        printf("Digite a opcao: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Saindo...\n");
                break;
            case 1:
                printf("Digite o numero de linhas da matriz1: ");
                scanf("%d", &l1);
                printf("Digite o numero de colunas da matriz1: ");
                scanf("%d", &c1);

                putchar('\n');
                break;
            case 2:
                printf("Digite o numero de linhas da matriz2: ");
                scanf("%d", &l2);
                printf("Digite o numero de colunas da matriz2: ");
                scanf("%d", &c2);
                putchar('\n');
                break;
            case 3:
                printf("\nMatriz1:\n");
                printf("Matriz2:\n");
                putchar('\n');
                break;
            case 4:
                printf(" \nSoma das matrizes:\n");
                putchar('\n');
                break;
            case 5:
                printf(" \nMultiplicacao das matrizes:\n");
                putchar('\n');
                break;
            case 6:
                printf(" \nSubtracao das matrizes:\n");
                putchar('\n');
                break;
            case 7:
                printf(" \nTransposta da matriz1:\n");
                putchar('\n');
                break;
            default:
                printf("Opcao invalida. Por favor, tente novamente.\n");
                break;
        }

    } while (choice != 0);

    liberarMatrizInt((int **) matriz1, l1);
    liberarMatrizInt((int **) matriz2, l2);

    return 0;
}

int exercicio26(void) {

    /*
    26 - Faca um algoritmo que calcule o determinante de uma matriz quadrada de ordem nxn.
    */

    printf("\nexercicio 26\n");

    int n, matriz[MAX][MAX], matrizD[MAX][MAX];
    printf("Digite a dimensao da matriz: ");
    scanf("%d", &n);

    printf("Matriz:\n");
    preencheMatrizInt(matriz, n, n);

    printf("Matriz: ");
    imprimeMatrizInt(matriz, n, n);

    printf("Determinante: %d\n", determinanteMatrizInt(matriz, n, n));

    return 0;
}

int exercicio27(void) {

    /*
    27 - Faca um algoritmo que calcule a soma dos elementos da diagonal principal de uma matriz quadrada de ordem nxn.
    */

    printf("\nexercicio 27\n");
    int n, matriz[MAX][MAX];

    printf("Digite a dimensao da matriz: ");
    scanf("%d", &n);

    printf("Matriz:\n");

    int soma = 0;
    for (int i = 0; i < n; i++)
        soma += matriz[i][i];

    printf("Soma da diagonal principal: %d\n", soma);

    return 0;
}

int exercicio28(void) {
    /*
    28 - Faca um algoritmo que calcule a soma dos elementos da diagonal secundaria de uma matriz quadrada de ordem nxn.
    */

    printf("\nexercicio 28\n");
    int n, soma = 0, matriz[MAX][MAX];

    printf("Digite a dimensao da matriz: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        soma += matriz[i][n - i - 1];

    printf("Soma da diagonal secundaria: %d\n", soma);

    return 0;
}

int exercicio29(void) {

    /*
    29 - Faca um algoritmo que verifique se uma matriz e inversivel. Em seguida calcule a sua inversa.
    */

    printf("\nexercicio 29\n");
    int n, matriz[MAX][MAX];

    printf("Digite a dimensao da matriz: ");
    scanf("%d", &n);

    int matrizInversa[n][n];

    printf("Matriz Inversa:\n");
    imprimeMatrizInt(matrizInversa, n, n);

    return 0;
}

int exercicio30(void) {

    /*
    30 - Verifica se uma matriz e triangular superior ou triangular inferior ou nenhuma das duas
    */

    printf("\nexercicio 30\n");
    int n, matriz[MAX][MAX];

    printf("Digite a dimensao da matriz: ");
    scanf("%d", &n);

    return 0;
}

int exercicio31(void) {

    /*
    31 - Escreva uma algoritmo que descubra qual a matriz identidade de uma matriz digitada pelo usuario
    */

    printf("\nexercicio 31\n");
    int matriz[MAX][MAX], matrizIdentidade[MAX][MAX];
    int matrizAux[MAX][MAX], matrizIdentidade2[MAX][MAX];
    int n;

    printf("Digite a dimensao da matriz: ");
    scanf("%d", &n);

    return 0;
}

int displayMenuGetChoice() {
    printf("Lista 3 - Matrizes\n");
    printf("Exercecio 1\n");
    printf("Exercicio 2\n");
    printf("Exercicio 3\n");
    printf("Exercicio 4\n");
    printf("Exercicio 5\n");
    printf("Exercicio 6\n");
    printf("Exercicio 7\n");
    printf("Exercicio 8\n");
    printf("Exercicio 9\n");
    printf("Exercicio 10\n");
    printf("Exercicio 11\n");
    printf("Exercicio 12\n");
    printf("Exercicio 13\n");
    printf("Exercicio 14\n");
    printf("Exercicio 15\n");
    printf("Exercicio 16\n");
    printf("Exercicio 17\n");
    printf("Exercicio 18\n");
    printf("Exercicio 19\n");
    printf("Exercicio 20\n");
    printf("Exercicio 21\n");
    printf("Exercicio 22\n");
    printf("Exercicio 23\n");
    printf("Exercicio 24\n");
    printf("Exercicio 25\n");
    printf("Exercicio 26\n");
    printf("Exercicio 27\n");
    printf("Exercicio 28\n");
    printf("Exercicio 29\n");
    printf("Exercicio 30\n");
    printf("Exercicio 31\n");
    printf("Digite o numero do exercicio: ");

    int choice;
    scanf("%d", &choice);
    return choice;
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
        case 13:
            exercicio13();
            break;
        case 14:
            exercicio14();
            break;
        case 15:
            exercicio15();
            break;
        case 16:
            exercicio16();
            break;
        case 17:
            exercicio17();
            break;
        case 18:
            exercicio18();
            break;
        case 19:
            exercicio19();
            break;
        case 20:
            exercicio20();
            break;
        case 21:
            exercicio21();
            break;
        case 22:
            exercicio22();
            break;
        case 23:
            exercicio23();
            break;
        case 24:
            exercicio24();
            break;
        case 25:
            exercicio25();
            break;
        case 26:
            exercicio26();
            break;
        case 27:
            exercicio27();
            break;
        case 28:
            exercicio28();
            break;
        case 29:
            exercicio29();
            break;
        case 30:
            exercicio30();
            break;
        case 31:
            exercicio31();
            break;
        default:
            printf("Exercicio nao existente na lista.\n");
            break;
    }
}

bool getExitChoice() {
    int exitChoice;
    printf("Deseja sair? (1) - Sim (0) - Nao");
    scanf("%d", &exitChoice);

    while (exitChoice != 0 && exitChoice != 1) {
        printf("Opcao invalida, digite novamente: ");
        scanf("%d", &exitChoice);
    }

    return exitChoice;
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    bool sair = false;
    do {
        int choice = displayMenuGetChoice();

        if (choice >= 0 && choice <= MAX) {
            executeExercise(choice);
        } else {
            printf("Opcao invalida, tente novamente.\n");
        }
        sair = getExitChoice();
    } while (!sair);
    printf("Obrigado por utilizar o programa.\n");
    return 0;
}