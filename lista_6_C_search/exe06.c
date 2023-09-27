#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <locale.h>
#include "global.h"

#define MAX_EXERCISES 11

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
   <p>  Implemente duas funções, uma que devolve o vetor ordenado por preços e outra que devolve
    o vetor ordenado pela quantidade de itens no estoque. Os protótipos são:
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

   <p>  Implemente um algoritmo que receba um vetor de Datas como parâmetro e que retorne as datas em ordem cronológica.

    <p>  Protótipo da função : void ordena(struct Data vet[], int tam);

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
   <p>  Crie funções para cada uma das operações abaixo:
<p>
   <p>  a) Cria base: esta função devolve uma Base onde o campo armazenado ? inicializado
    com 0.
  <p>   Base cria_base();
<p>
  <p>   b) Inclui Pessoa: esta função recebe como parâmetro um dado do tipo Pessoa e o inclui
    na base (também passada por parâmetro) caso já não exista na base uma pessoa com
    o mesmo RG. A função devolve 1 caso a incluso tenha ocorrido, devolve 0 caso a
    Base esteja cheia e devolve -1 caso já exista uma pessoa com o RG informado.
  <p>   int insere_base(Pessoa p, Base base);
<p>
  <p>   c) Exclui Pessoa: esta função recebe como parâmetro um dado do tipo int representando
    o RG de uma pessoa e o exclui da base caso esteja presente. A função devolve 1 caso a
    exclusão tenha ocorrido, e devolve 0 caso não exista uma pessoa com o RG informado.
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
    /*
     * 4. Suponha que criamos uma estrutura para armazenar dados de pessoas e uma outra estrutura
     *
     * typedef struct Pessoa{
     *     int rg;
     *     int cpf;
     *     char nome[80];
     * }Pessoa;
     *
     * Pessoa cadastro[100];
     *
     * Suponha que o vetor esteja ordenado em ordem crescente por valor de RG.
     * Implemente uma função de busca por RG, que opera como a busca binária, e que caso exista uma
     * pessoa no cadastro com o RG a ser buscado, devolve o índice deste no cadastro, e devolve -1
     * caso não exista uma pessoa com o RG a ser buscado
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
/**  Refaça as funções de busca sequencial e busca binária vistas em aula assumindo que o
vetor possui chaves que podem aparecer repetidas. Neste caso, você deve retornar em um
outro vetor todas as posições onde a chave foi encontrada.

<p> Protótipo da função:
<p> void busca(int vet[], int tam, int chave, int posicoes[], int n)

<p> Você deve devolver em posicoes[] as posições de vet que possuem a chave, e devolver
em n o número de ocorrências da chave.
<p> OBS: Na chamada desta função, o vetor posições deve ter espaço suficiente
<p>(por exemplo, tam) para guardar todas as possíveis ocorrências da chave.
 */

    int vet[10] = {
            1, 2, 3,
            4, 5, 6,
            7, 7, 7, 10
    };
    int posicoes[10];
    int n = 0;
    buscar(vet, 10, 7, posicoes, (int) *&n);

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
    <p> Esta função faz a leitura dos dados de um registro Aluno e devolve o
    registro lido.
<p>
    <p>void imprimeAluno (struct Aluno a) ;
    <p>Esta função recebe como par?metro um registro Aluno e imprime os
    dados do registro.
<p>
   <p> void listarTurma (struc t Aluno turma [ ], int n ) ;
   <p> Esta função recebe como parâmetros um vetor do tipo Aluno
   <p> representando uma turma, e também um inteiro n indicando o
   <p> tamanho do vetor. A função imprime os dados de todos os alunos.
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
     <p> faça a leitura de 5 alunos em uma função.
     <p> Função Calcule e imprima a média das idades dos alunos.
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
    
    <p>Crie um novo tipo de registro para armazenar coordenadas no plano
    cartesiano.
    <p>Crie uma Função para imprimir um ponto do tipo criado.
    <p>Crie uma Função para cada uma destas operações: soma de dois
    pontos, subtraçõo de dois pontos, multiplicação por um escalar.
    */

    printf("Enter the coordinates of point 1:\n");
    Ponto p1 = lePonto();

    printf("Enter the coordinates of point 2:\n");
    Ponto p2 = lePonto();

    printf("Point 1:\n");
    imprimePonto(p1);

    printf("Point 2:\n");
    imprimePonto(p2);

    printf("Sum of the points:\n");
    imprimePonto(somaPonto(p1, p2));

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
    Defina uma variável do tipo registro que tenha dois campinas, senodo o  1 um vetor de 3 elementos do tipo inteiro
    e o 2 campo um valor inteiro. Faça:
    <p>
    <p>a) Crie uma função para leitura dos valores do 1 campo(vetor)
   <p>b) Some os valores do vetor e coloque o resultao no 2 campo
    <p>c) Crie uma função para imprimir os valores de registro
     */

    Reg minhaReg;

    minhaReg = leReg();

    minhaReg = somaVetorSegundoAtributo(minhaReg);

    imprimeReg(minhaReg);

    return 0;
}

int exercise11(void) {

    /** Crie uma função que recebe duas strings de tamanhos quaisqueres e que devolve a concatenação destas
     * lembre-se que uma função não pode devolver um vetor, mas ela pode devolver um ponteiro,
     *
     * o protótipo da função será
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
