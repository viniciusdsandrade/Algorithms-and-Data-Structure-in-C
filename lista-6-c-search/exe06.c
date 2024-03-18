#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <locale.h>
#include "global.h"
#include <time.h>

#define TAMANHO 1000
#define MAXIMO 1000
#define MAX_EXERCISES 31

int exercise01(void) {
    /**
    1. Suponha que criamos uma estrutura para armazenar produtos de um supermercado:
<p>
    <p>  typedef struct Produto{
      <p>   char nome[80];
      <p>   double preco;
      <p>   int quantidade;
   <p>  }Produto;
<p>
   <p>  Implemente duas fun��es, uma que devolve o vetor ordenado por pre�os e outra que devolve
    o vetor ordenado pela quantidade de itens no estoque. Os prot�tipos s�o:
<p>
   <p>  void ordenaPreco(Produto vet[], int n);
   <p> void ordenaQuantidade(Produto vet[], int n);
     */

    printf("Enter the quantity of products: ");
    int n;
    scanf("%d", &n);

    Produto *produtos = lerProdutos(n);

    ordenaPreco(produtos, n);
    printf("Products sorted by price:\n");
    imprimeProduto(produtos, n);
    printf("\n");

    ordenaQtd(produtos, n);
    printf("Products sorted by quantity:\n");
    imprimeProduto(produtos, n);
    printf("\n");

    free(produtos);

    return 0;
}

int exercise02(void) {
    /**
     2. Suponha que criamos uma estrutura para armazenar Datas:
<p>
    <p>  typedef struct Data{
   <p>      int dia;
    <p>     int mes;
     <p>    int ano;
    <p> }Data;
     <p>

   <p>  Implemente um algoritmo que receba um vetor de Datas como par�metro e que retorne as datas em ordem cronol�gica.

    <p>  Prot�tipo da fun��o : void ordena(struct Data vet[], int tam);

    <p> Dica: Ordene o vetor separadamente por cada um dos campos.
    */

    printf("Enter the quantity of dates: ");
    int n;
    scanf("%d", &n);

    Data datas[n];

    for (int i = 0; i < n; ++i) {
        printf("Enter data %d details:\n", i + 1);
        datas[i] = leData();
    }

    ordena(datas, n);

    printf("Sorted dates:\n");
    imprimeDatas(datas, n);

    return 0;
}

int exercise03(void) {
    /**
    3. Suponha que criamos uma estrutura para armazenar dados de pessoas e uma outra estrutura
    para armazenar dados de várias pessoas como uma base de dados.
<p>
  <p>   typedef struct Pessoa{
   <p>      int rg;
  <p>       int cpf;
   <p>      char nome[80];
   <p>  }Pessoa;
<p>
   <p>  typedef struct Base{
   <p>     int armazenado; //Deve sempre corresponder ao número de pessoas na base
   <p>      Pessoa pessoas[100];
   <p>  }Base;
<p>
   <p>  Crie fun��es para cada uma das operações abaixo:
<p>
   <p>  a) Cria base: esta função devolve uma Base onde o campo armazenado ? inicializado
    com 0.
  <p>   Base cria_base();
<p>
  <p>   b) Inclui Pessoa: esta função recebe como parâmetro um dado do tipo Pessoa e o inclui
    na base (também passada por par�metro) caso já não exista na base uma pessoa com
    o mesmo RG. A função devolve 1 caso a incluso tenha ocorrido, devolve 0 caso a
    Base esteja cheia e devolve -1 caso j� exista uma pessoa com o RG informado.
  <p>   int insere_base(Pessoa p, Base base);
<p>
  <p>   c) Exclui Pessoa: esta função recebe como par�metro um dado do tipo int representando
    o RG de uma pessoa e o exclui da base caso esteja presente. A fun��o devolve 1 caso a
    exclus�o tenha ocorrido, e devolve 0 caso n�o exista uma pessoa com o RG informado.
   <p>  int remove_base(int rg, Base base);
    */

    Base base = cria_base();

    Pessoa p1 = lePessoa();
    Pessoa p2 = lePessoa();
    Pessoa p3 = lePessoa();

    insere_base(p1, base);
    insere_base(p2, base);
    insere_base(p3, base);

    remove_base(1, base);

    return 0;
}

int exercise04(void) {
    /**
     * 4. Suponha que criamos uma estrutura para armazenar dados de pessoas e uma outra estrutura
     * <p>
     * <p>typedef struct Pessoa{
     *<p>     int rg;
     * <p>    int cpf;
     * <p>    char nome[80];
     * <p>}Pessoa;
     *<p>
     * <p>Pessoa cadastro[100];
     *<p>
     * <p>Suponha que o vetor esteja ordenado em ordem crescente por valor de RG.
     * <p>Implemente uma fun��o de busca por RG, que opera como a busca bin�ria, e que caso exista uma
     * <p>pessoa no cadastro com o RG a ser buscado, devolve o �ndice deste no cadastro, e devolve -1
     * <p>caso n�o exista uma pessoa com o RG a ser buscado
     * */

    Pessoa cadastro[100];
    int n;

    printf("Enter the quantity of people: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        printf("Enter details for person %d:\n", i + 1);
        cadastro[i] = lePessoa();
    }

    int rg;
    printf("Enter the RG to be searched: ");
    scanf("%d", &rg);

    int indice = buscaBinaria(cadastro, 3, rg);

    if (indice != -1)
        printf("Person found at index %d\n", indice);
    else
        printf("Person not found!\n");

    return 0;
}

int exercise05(void) {
/**  Refaca as funcoes de busca sequencial e busca binaria vistas em aula assumindo que o
vetor possui chaves que podem aparecer repetidas. Neste caso, voce deve retornar em um
outro vetor todas as posicoes onde a chave foi encontrada.

<p> Prototipo da funcoo:
<p> void busca(int vet[], int tam, int chave, int posicoes[], int n)

<p> Voce deve devolver em posicoes[] as posicoes de vet que possuem a chave, e devolver
em n o numero de ocorrencias da chave.
<p> OBS: Na chamada desta funcao, o vetor posicoes deve ter espaco suficiente
<p>(por exemplo, tam) para guardar todas as possiveis ocorrencias da chave.
 */

    int vet[10] = {
            1, 2, 3,
            4, 5, 6,
            7, 7, 7,
            10
    };
    int posicoes[10];
    int n = 0;
    //buscar(vet, 10, 7, posicoes, (int) *&n);

    printf("The number 7 appears %d times in the array.\n", n);
    printf("The positions where the number 7 appears are: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", posicoes[i]);
    }
    printf("\n");

    return 0;
}

int exercise06(void) {

    /**
     6. O que ser? impresso pelo programa abaixo?
     <p>#include <stdio.h>
    <p> struct T{
     <p>    int x;
     <p>    int y;
    <p> };
     <p> typedef struct T T;
    <p> void f1(T *a);
    <p> void f2(int *b);
   <p>  int main(){
   <p>  T a, b, *c, *d;
    <p> c = &a;
   <p>  a.x = 2;
    <p> a.y = 4;
     <p>b.x = 2;
    <p> b.y = 2;
    <p> d = c;
   <p>  f1(d);
   <p>  b = *d;
   <p>      printf("x: %d --- y: %d\n",b.x,b.y);
   <p>  }
   <p>  void f1(T *a){
    <p>    f2(&(a->x));
    <p>    f2(&(a->y));
   <p>  }
   <p>  void f2(int *b){
   <p>     *b = 2*(*b);
  <p>  }
  <p>  */
    return 0;
}

int exercise07(void) {

    /**
    struct Aluno leAluno ( ) ;
    <p> Esta funcao faz a leitura dos dados de um registro Aluno e devolve o
    registro lido.
<p>
    <p>void imprimeAluno (struct Aluno a) ;
    <p>Esta funcao recebe como parametro um registro Aluno e imprime os
    dados do registro.
<p>
   <p> void listarTurma (struc t Aluno turma [ ], int n ) ;
   <p> Esta funcao recebe como parametros um vetor do tipo Aluno
   <p> representando uma turma, e tambem um inteiro n indicando o
   <p> tamanho do vetor. A funcao imprime os dados de todos os alunos.
    */

    int numAlunos;
    printf("Enter the number of students: ");
    scanf("%d", &numAlunos);
    Aluno *alunos = leAlunos(numAlunos);

    for (int i = 0; i < 5; i++) {
        imprimeAluno(alunos[i]);
    }

    listarTurma(alunos, 5);

    free(alunos);
    return 0;
}

int exercise08(void) {
    /**
     Crie um novo tipo de registro para armazenar alunos com RA e idade.
     <p> faca a leitura de 5 alunos em uma funcao.
     <p> Funcao Calcule e imprima a media das idades dos alunos.
     */

    int numAlunes;
    printf("Enter the number of students: ");
    scanf("%d", &numAlunes);
    Alune *alunes = leAlunes(numAlunes);

    printf("The average of ages is: %.2f", mediaAlunes(alunes, 5));

    free(alunes);
    return 0;
}

int exercise09(void) {

    /**
    Crie um novo tipo de registro para armazenar coordenadas no plano
    cartesiano.
    <p>Crie uma Fun��o para imprimir um ponto do tipo criado.
    <p>Crie uma Fun��o para cada uma destas opera��es: soma de dois
    pontos, subtra��o de dois pontos, multiplica��o por um escalar.
    */

    Ponto *p3 = malloc(sizeof(Ponto));
    Ponto *p4 = malloc(sizeof(Ponto));
    p3->x = 1;
    p3->y = 2;
    p4->x = 3;
    p4->y = 4;

    printf("Enter the coordinates of point 1:\n");
    Ponto p1 = *lePonto();

    printf("Enter the coordinates of point 2:\n");
    Ponto p2 = *lePonto();

    printf("Point 1:\n");
    imprimePonto(p1);

    printf("Point 2:\n");
    imprimePonto(p2);

    printf("Sum of the points:\n");
    imprimePonto(somaPonto(p1, p2));

    Ponto *resultado = somaPonto2(p3, p4);
    printf("Sum of the points:\n");
    imprimePonto(*resultado);

    printf("Subtraction of the points:\n");
    imprimePonto(subtraiPonto(p1, p2));

    printf("Multiplication of point 1 by a scalar:\n");
    imprimePonto(multiplicaPonto(p1, 2));

    printf("Multiplication of point 2 by a scalar:\n");
    imprimePonto(multiplicaPonto(p2, 2));

    return 0;
}

int exercise10(void) {
    /**
    Defina uma vari�vel do tipo registro que tenha dois campinas, senodo o  1 um vetor de 3 elementos do tipo inteiro
    e o 2 campo um valor inteiro. Fa�a:
    <p>
    <p>a) Crie uma fun��o para leitura dos valores do 1 campo(vetor)
   <p>b) Some os valores do vetor e coloque o resultao no 2 campo
    <p>c) Crie uma fun��o para imprimir os valores de registro
     */

    Reg minhaReg;

    minhaReg = leReg();

    minhaReg = somaVetorSegundoAtributo(minhaReg);

    imprimeReg(minhaReg);

    return 0;
}

int exercise11(void) {

    /** Crie uma fun��o que recebe duas strings de tamanhos quaisqueres e que devolve a concatena��o destas
     * lembre-se que uma fun��o n�o pode devolver um vetor, mas ela pode devolver um ponteiro,
     *
     * o prot�tipo da fun��o ser�
     *
     * <p>char * concatena(char *s1, char *s2);
     */

    char *s1 = "Hello";
    char *s2 = "World";

    char *s3 = concatena(s1, s2);

    printf("%s", s3);

    free(s3);

    return 0;
}

int exercise12(void) {

    int vetor[10] = {14, 7, 8, 34, 56, 4, 0, 9, -8, 100};
    printf("Vetor desordenado:\n");
    for (int i = 0; i < 10; ++i)
        printf("%d ", vetor[i]);

    selectionSort(vetor, 10);

    printf("\nVetor ordenado:\n");
    for (int i = 0; i < 10; ++i)
        printf("%d ", vetor[i]);

    return 0;
}

int exercise13(void) {

    int vetor[10] = {14, 7, 8, 34, 56, 4, 0, 9, -8, 100};
    printf("Vetor desordenado:\n");
    for (int i = 0; i < 10; ++i) {
        printf("%d ", vetor[i]);
    }

    bubbleSort(vetor, 10);

    printf("\nVetor ordenado:\n");
    for (int i = 0; i < 10; ++i) {
        printf("%d ", vetor[i]);
    }

    return 0;
}

int exercise14(void) {

    int vetor[10] = {14, 7, 8, 34, 56, 4, 0, 9, -8, 100};
    printf("Vetor desordenado:\n");
    for (int i = 0; i < 10; ++i) {
        printf("%d ", vetor[i]);
    }

    insertionSort(vetor, 10);

    printf("\nVetor ordenado:\n");
    for (int i = 0; i < 10; ++i) {
        printf("%d ", vetor[i]);
    }

    return 0;
}

int exercise15(void) {

    int vetor[10] = {14, 7, 8, 34, 56, 4, 0, 9, -8, 100};
    printf("Vetor desordenado:\n");
    for (int i = 0; i < 10; ++i) {
        printf("%d ", vetor[i]);
    }

    binarySearch(vetor, 10, 100);

    printf("\nVetor ordenado:\n");
    for (int i = 0; i < 10; ++i) {
        printf("%d ", vetor[i]);
    }

    return 0;
}

int exercise16(void) {

    int vetor[10] = {14, 7, 8, 34, 56, 4, 0, 9, -8, 100};
    printf("Vetor desordenado:\n");
    for (int i = 0; i < 10; ++i) {
        printf("%d ", vetor[i]);
    }

    linearSearch(vetor, 10, 100);

    printf("\nVetor ordenado:\n");
    for (int i = 0; i < 10; ++i) {
        printf("%d ", vetor[i]);
    }

    printf("\n");

    return 0;
}

int exercise17(void) {

    int num, q = 1;
    int *p;

    num = 100;
    p = &num;
    q = *p;

    printf("\n%d\n", q);

    return 0;
}

int exercise18(void) {

    int b;
    int *c;

    b = 10;
    c = &b;
    *c = 11;

    printf("\n%d\n", b);

    printf("\n");

    return 0;
}

int exercise19(void) {
    int b, a;
    int *c;

    b = 10;
    c = &a;
    *c = 11;
    a = b * (*c);

    printf("\n%d\n", a);

    return 0;
}

void nao_troca(int x, int y) {
    int aux;
    aux = x;
    x = y;
    y = aux;
}

int exercise20(void) {

    int x = 4, y = 5;
    nao_troca(x, y);

    printf("\n%d %d\n", x, y);

    return 0;
}

int exercise21(void) {
    int x = 4, y = 5;
    troca(&x, &y);

    printf("\n%d %d\n", x, y);

    return 0;
}

void maxAndMin(const int vet[],
               int tam,
               int *min,
               int *max) {

    *min = vet[0];
    *max = vet[0];

    for (int i = 0; i < tam; ++i) {
        if (vet[i] < *min)
            *min = vet[i];
        if (vet[i] > *max)
            *max = vet[i];
    }
}

int exercise22(void) {

    int vet[] = {10, 80, 5, -10, 45, -20, 100, 200, 10};
    int min, max;

    maxAndMin(vet, 9, &min, &max);
    printf("O menor valor %d, o maior valor %d\n", min, max);

    printf("\n");

    return 0;
}

int exercise23(void) {

    int a[] = {1, 2, 3, 4, 5};
    int *b, i;

    b = a;
    printf("Conteudo de B\n");
    for (i = 0; i < 5; i++) {
        printf("%d\n", b[i]);
        b[i] = i * i;
    }

    printf("Conteudo de A\n");
    for (i = 0; i < 5; i++)
        printf("%d\n", a[i]);

    printf("\n");

    return 0;
}

int exercise24(void) {

    int a = 3, b = 2, *p = NULL, *q = NULL;

    p = &a;
    q = p;
    *q = *q + 1;
    q = &b;
    b = b + 1;

    printf("%d\n", *q);
    printf("%d\n", *p);

    printf("\n");

    return 0;
}


int exercise25(void) {

    double *v1, *v2, prodEsc;
    int n, i;

    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &n);

    v1 = malloc(n * sizeof(double));
    v2 = malloc(n * sizeof(double));

    printf("Digite os elementos do vetor 1: ");
    for (i = 0; i < n; i++)
        scanf("%lf", &v1[i]);

    printf("Digite os elementos do vetor 2: ");
    for (i = 0; i < n; i++)
        scanf("%lf", &v2[i]);

    prodEsc = 0;
    for (i = 0; i < n; i++)
        prodEsc += v1[i] * v2[i];

    printf("Produto escalar: %lf\n", prodEsc);
    free(v1);
    free(v2);

    return 0;
}

int exercise26(void) {

    char s1[100], s2[100], *s3;
    fgets(s1, 100, stdin);
    s1[strlen(s1) - 1] = '\0';
    fgets(s2, 100, stdin);
    s2[strlen(s2) - 1] = '\0';

    s3 = concatena(s1, s2);
    printf("%s\n", s3);
    free(s3);
    return 0;
}

int *uniao(const int vet1[],
           int n1,
           const int vet2[],
           int n2) {

    int *vet3 = malloc((n1 + n2) * sizeof(int));
    int i, j, k;

    for (i = 0; i < n1; i++)
        vet3[i] = vet1[i];

    for (j = 0; j < n2; j++) {
        for (k = 0; k < n1; k++) {
            if (vet2[j] == vet1[k])
                break;
        }
        if (k == n1) {
            vet3[i] = vet2[j];
            i++;
        }
    }
    return vet3;
}

int exercise27(void) {

    int vet1[] = {1, 2, 3, 4, 5};
    int vet2[] = {4, 5, 6, 7, 8};

    int *vet3 = uniao(vet1, 5, vet2, 5);

    for (int i = 0; i < 8; i++)
        printf("%d ", vet3[i]);

    printf("\n");

    free(vet3);
    return 0;
}


int exercise28(void) {

    int *vet, size, maxSize;

    vet = initVet(&size, &maxSize);

    for (int i = 0; i < 20; i++) {
        vet = addVet(vet, &size, &maxSize, i);
    }

    printVet(vet, size, maxSize);

    vet = removeVet(vet, &size, &maxSize, 14);
    printVet(vet, size, maxSize);

    for (int i = 5; i < 15; i++) {
        vet = removeVet(vet, &size, &maxSize, i);
    }

    for (int i = 0; i < 20; i++) {
        vet = removeVet(vet, &size, &maxSize, i);
    }

    printVet(vet, size, maxSize);

    free(vet);
    return 0;
}

int exercise29(int argc, char *argv[]) {

    FILE *arq = fopen(argv[1], "r");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    char aux;
    int size = 0;
    while (fscanf(arq, "%c", &aux) != EOF) {
        size++;
    }

    char *texto = malloc(size * sizeof(char));

    rewind(arq);
    int i = 0;
    while (fscanf(arq, "%c", &aux) != EOF) {
        texto[i] = aux;
        i++;
    }

    texto[i] = '\0';
    printf("%s", texto);

    rewind(arq);
    i = 0;
    while (texto[i] != '\0') {
        if (texto[i] == 'a')
            texto[i] = 'A';

        fprintf(arq, "%c", texto[i]);
        i++;
    }

    free(texto);
    fclose(arq);
    return 0;
}

int exercise30(void) {

    int vet_1[] = {10, 8, 9, 5, 4, 6, 7, 3, 2, 1};
    int vet_2[] = {10, 8, 9, 5, 4, 6, 7, 3, 2, 1};
    int vet_3[] = {10, 8, 9, 5, 4, 6, 7, 3, 2, 1};
    int vet_4[] = {10, 8, 9, 5, 4, 6, 7, 3, 2, 1};
    int vet_5[] = {10, 8, 9, 5, 4, 6, 7, 3, 2, 1};
    int vet_6[] = {10, 8, 9, 5, 4, 6, 7, 3, 2, 1};
    int vet_7[] = {10, 8, 9, 5, 4, 6, 7, 3, 2, 1};
    int vet_8[] = {10, 8, 9, 5, 4, 6, 7, 3, 2, 1};
    int vet_9[] = {10, 8, 9, 5, 4, 6, 7, 3, 2, 1};
    int vet_10[] = {10, 8, 9, 5, 4, 6, 7, 3, 2, 1};
    int vet_11[] = {10, 8, 9, 5, 4, 6, 7, 3, 2, 1};

    printf("Vetor:       ");
    imprimirVetor(vet_1, 10);

    bubbleSort(vet_2, 10);
    selectionSort(vet_3, 10);
    insertionSort(vet_4, 10);
    mergeSort(vet_5, 0, 9);
    quickSort(vet_6, 0, 9);
    heapSort(vet_7, 10);
    shellSort(vet_8, 10);
    countingSort(vet_9, 10);
    radixSort(vet_10, 10);
    bucketSort(vet_11, 10);

    int tamanho = sizeof(vet_1) / sizeof(vet_1[0]);

    printf("bsort:         ");
    imprimirVetor(vet_1, tamanho);

    printf("bubbleSort:    ");
    imprimirVetor(vet_2, tamanho);

    printf("selectionSort: ");
    imprimirVetor(vet_3, tamanho);

    printf("insertionSort: ");
    imprimirVetor(vet_4, tamanho);

    printf("mergeSort:     ");
    imprimirVetor(vet_5, tamanho);

    printf("quickSort:     ");
    imprimirVetor(vet_6, tamanho);

    printf("heapSort:      ");
    imprimirVetor(vet_7, tamanho);

    printf("shellSort:     ");
    imprimirVetor(vet_8, tamanho);

    printf("countingSort:  ");
    imprimirVetor(vet_9, tamanho);

    printf("radixSort:     ");
    imprimirVetor(vet_10, tamanho);

    printf("bucketSort:    ");
    imprimirVetor(vet_11, tamanho);

    return 0;
}

int exercise31(void) {
    int vetor_1[TAMANHO];
    int i;

    // Inicializa o gerador de números aleatórios com o tempo atual
    srand(time(NULL));

    // Preenche o vetor com números aleatórios entre 0 e 1000
    for (i = 0; i < TAMANHO; i++) {
        vetor_1[i] = rand() % (MAXIMO + 1);
    }

    printf("Vetor desordenado:\n");
    imprimirVetor(vetor_1, TAMANHO);
    bubbleSort(vetor_1, TAMANHO);
    printf("Vetor ordenado:\n");
    imprimirVetor(vetor_1, TAMANHO);

    int value_1 = vetor_1[500];
    printf("vetor_1[500] = %d\n", value_1);

    struct timespec start, end;
    printf("linearSearch: ");
    clock_gettime(CLOCK_REALTIME, &start);
    int value_2 = linearSearch(vetor_1, TAMANHO, value_1);
    clock_gettime(CLOCK_REALTIME, &end);
    double elapsed_time = (long)(end.tv_sec - start.tv_sec) +
                          (end.tv_nsec - start.tv_nsec);
    printf("linearSearch(vetor_1, TAMANHO, %d): %d, Tempo:        %.3f ns\n", value_1, value_2, elapsed_time);

    printf("binarySearch: ");
    clock_gettime(CLOCK_REALTIME, &start);
    int value_3 = binarySearch(vetor_1, TAMANHO, value_1);
    clock_gettime(CLOCK_REALTIME, &end);
    elapsed_time = (long)(end.tv_sec - start.tv_sec) +
                   (end.tv_nsec - start.tv_nsec);
    printf("binarySearch(vetor_1, TAMANHO, %d): %d, Tempo:        %.3f ns\n", value_1, value_3, elapsed_time);

    printf("ternarySearch: ");
    clock_gettime(CLOCK_REALTIME, &start);
    int value_4 = ternarySearch(vetor_1, TAMANHO, value_1);
    clock_gettime(CLOCK_REALTIME, &end);
    elapsed_time = (long)(end.tv_sec - start.tv_sec) +
                   (end.tv_nsec - start.tv_nsec);
    printf("ternarySearch(vetor_1, TAMANHO, %d): %d, Tempo:       %.3f ns\n", value_1, value_4, elapsed_time);

    printf("interpolationSearch: ");
    clock_gettime(CLOCK_REALTIME, &start);
    int value_5 = interpolationSearch(vetor_1, TAMANHO, value_1);
    clock_gettime(CLOCK_REALTIME, &end);
    elapsed_time = (long)(end.tv_sec - start.tv_sec) +
                   (end.tv_nsec - start.tv_nsec);
    printf("interpolationSearch(vetor_1, TAMANHO, %d): %d, Tempo: %.3f ns\n", value_1, value_5, elapsed_time);

    printf("exponentialSearch: ");
    clock_gettime(CLOCK_REALTIME, &start);
    int value_6 = exponentialSearch(vetor_1, TAMANHO, value_1);
    clock_gettime(CLOCK_REALTIME, &end);
    elapsed_time = (long)(end.tv_sec - start.tv_sec) +
                   (end.tv_nsec - start.tv_nsec);
    printf("exponentialSearch(vetor_1, TAMANHO, %d): %d, Tempo:  %.3f ns\n", value_1, value_6, elapsed_time);

    printf("jumpSearch: ");
    clock_gettime(CLOCK_REALTIME, &start);
    int value_7 = jumpSearch(vetor_1, TAMANHO, value_1);
    clock_gettime(CLOCK_REALTIME, &end);
    elapsed_time = (long)(end.tv_sec - start.tv_sec) +
                   (end.tv_nsec - start.tv_nsec);
    printf("jumpSearch(vetor_1, TAMANHO, %d): %d, Tempo:        %.3f ns\n", value_1, value_7, elapsed_time);

    printf("fibonacciSearch: ");
    clock_gettime(CLOCK_REALTIME, &start);
    int value_8 = fibonacciSearch(vetor_1, 1000, value_1);
    clock_gettime(CLOCK_REALTIME, &end);
    elapsed_time = (long)(end.tv_sec - start.tv_sec) +
                   (end.tv_nsec - start.tv_nsec);
    printf("fibonacciSearch(vetor_1, 1000, %d): %d, Tempo:      %.3f ns\n", value_1, value_8, elapsed_time);

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
    printf("Exercise 13:\n");
    printf("Exercise 14:\n");
    printf("Exercise 15:\n");
    printf("Exercise 16:\n");
    printf("Exercise 17:\n");
    printf("Exercise 18:\n");
    printf("Exercise 19:\n");
    printf("Exercise 20:\n");
    printf("Exercise 21:\n");
    printf("Exercise 22:\n");
    printf("Exercise 23:\n");
    printf("Exercise 24:\n");
    printf("Exercise 25:\n");
    printf("Exercise 26:\n");
    printf("Exercise 27:\n");
    printf("Exercise 28:\n");
    printf("Exercise 29:\n");
    printf("Exercise 30:\n");
    printf("Exercise 31:\n");

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
        case 13:
            exercise13();
            break;
        case 14:
            exercise14();
            break;
        case 15:
            exercise15();
            break;
        case 16:
            exercise16();
            break;
        case 17:
            exercise17();
            break;
        case 18:
            exercise18();
            break;
        case 19:
            exercise19();
            break;
        case 20:
            exercise20();
            break;
        case 21:
            exercise21();
            break;
        case 22:
            exercise22();
            break;
        case 23:
            exercise23();
            break;
        case 24:
            exercise24();
            break;
        case 25:
            exercise25();
            break;
        case 26:
            exercise26();
            break;
        case 27:
            exercise27();
            break;
        case 28:
            exercise28();
            break;
        case 29:
            //exercise29(null, null);
            break;
        case 30:
            exercise30();
            break;
        case 31:
            exercise31();
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