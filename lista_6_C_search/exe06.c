#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <locale.h>
#include "global.h"

#define MAX_EXERCISES 11

int exercicio01(void) {
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

    printf("Digite a quantidade de produtos: ");
    int n;
    scanf("%d", &n);

    Produto *produtos = lerProdutos(n);

    ordenaPreco(produtos, n);
    printf("Produtos ordenados por pre?o:\n");
    imprimeProduto(produtos, n);

    ordenaQuant(produtos, n);
    printf("Produtos ordenados por quantidade:\n");
    imprimeProduto(produtos, n);

    return 0;
}

int exercicio02(void) {
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
    printf("Digite a quantidade de datas: ");
    int n;

    Data data;


    scanf("%d", &n);
    return 0;
}

int exercicio03(void) {
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
   <p>  a) Cria base: esta fun??o devolve uma Base onde o campo armazenado ? inicializado
    com 0.
  <p>   Base cria_base();
<p>
  <p>   b) Inclui Pessoa: esta função recebe como parâmetro um dado do tipo Pessoa e o inclui
    na base (também passada por parâmetro) caso já não exista na base uma pessoa com
    o mesmo RG. A função devolve 1 caso a incluso tenha ocorrido, devolve 0 caso a
    Base esteja cheia e devolve -1 caso j? exista uma pessoa com o RG informado.
  <p>   int insere_base(Pessoa p, Base base);
<p>
  <p>   c) Exclui Pessoa: esta fun??o recebe como parâmetro um dado do tipo int representando
    o RG de uma pessoa e o exclui da base caso esteja presente. A fun??o devolve 1 caso a
    exclusão tenha ocorrido, e devolve 0 caso n?o exista uma pessoa com o RG informado.
   <p>  int remove_base(int rg, Base base);
    */
    return 0;
}

int exercicio04(void) {
    /**
 * Função para buscar uma pessoa por RG em um vetor de cadastro ordenado por RG.
 *
 * Esta função realize uma busca binária em um vetor de cadastro de pessoas ordenado
 * em ordem crescente por valor de RG. Se uma pessoa com o RG especificado for encontrada,
 * a função retorna o índice dessa pessoa no vetor de cadastro. Caso contrário, ela
 * retorna -1, indicando que a pessoa não foi encontrada.
 *
 * @param cadastro O vetor de cadastro de pessoas ordenado por RG.
 * @param tamanho O tamanho do vetor de cadastro.
 * @param rg O RG a ser buscado.
 * @return O índice da pessoa com o RG especificado no vetor de cadastro ou -1 se não
 * for encontrada.
 *
 * @note Para usar esta função, é importante que o vetor de cadastro esteja ordenado
 * em ordem crescente por valor de RG.
 */
    return 0;
}

int exercicio05(void) {
    /**
 * Função para buscar todas as ocorrências de uma chave em um vetor.
 *
 * Esta função realiza uma busca em um vetor 'vet' de tamanho 'tam' e procura pela
 * chave especificada. Ela registra todas as posições onde a chave foi encontrada no
 * vetor 'posicoes' e retorna o número total de ocorrências da chave em '*n'.
 *
 * @param vet O vetor no qual realizar a busca.
 * @param tam O tamanho do vetor 'vet'.
 * @param chave A chave a ser procurada no vetor.
 * @param posicoes Um vetor onde as posições da chave encontradas serão armazenadas.
 * @param n Um ponteiro para armazenar o número de ocorrências da chave.
 *
 * @note A chamada desta função deve fornecer um vetor 'posicoes' com espaço suficiente
 * para acomodar todas as possíveis ocorrências da chave (por exemplo, tamanho 'tam').
 */

    return 0;
}

int exercicio06(void) {

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

int exercicio07(void) {

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
    printf("Digite o número de alunos: ");
    scanf("%d", &numAlunos);
    Aluno *alunos = leAlunos(numAlunos);

    for (int i = 0; i < 5; i++) {
        imprimeAluno(alunos[i]);
    }

    listarTurma(alunos, 5);

    free(alunos);
    return 0;
}

int exercicio08(void) {
    /**
     Crie um novo tipo de registro para armazenar alunos com RA e idade.
     <p> faça a leitura de 5 alunos em uma função.
     <p> Função Calcule e imprima a m?dia das idades dos alunos.
     */

    int numAlunes;
    printf("Digite o n?mero de alunos: ");
    scanf("%d", &numAlunes);
    Alune *alunes = leAlunes(numAlunes);

    printf("A m?dia das idades ?: %.2f", mediaAlunes(alunes, 5));

    free(alunes);
    return 0;
}

int exercicio09(void) {
    /**
    
    <p>Crie um novo tipo de registro para armazenar coordenadas no plano
    cartesiano.
    <p>Crie uma Função para imprimir um ponto do tipo criado.
    <p>Crie uma Função para cada uma destas operações: soma de dois
    pontos, subtraçõo de dois pontos, multiplicação por um escalar.
    */

    printf("Digite as coordenadas do ponto 1:\n");
    Ponto p1 = lePonto();

    printf("Digite as coordenadas do ponto 2:\n");
    Ponto p2 = lePonto();

    printf("Ponto 1:\n");
    imprimePonto(p1);

    printf("Ponto 2:\n");
    imprimePonto(p2);

    printf("Soma dos pontos:\n");
    imprimePonto(somaPonto(p1, p2));

    printf("Subtração dos pontos:\n");
    imprimePonto(subtraiPonto(p1, p2));

    printf("Multiplicação do ponto 1 por um escalar:\n");
    imprimePonto(multiplicaPonto(p1, 2));

    printf("Multiplicação do ponto 2 por um escalar:\n");
    imprimePonto(multiplicaPonto(p2, 2));

    return 0;
}

int exercicio10(void) {
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

int exercicio11(void) {

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
    printf("Digite o n?número do Exercício que deseja executar");

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
        default:
            printf("Opção inválida!\n");
            break;
    }
}


bool getExitChoice() {
    int sair;
    do {
        printf("Deseja sair? Digite (1) para Sim ou (0) para N?o: ");
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
    printf("Obrigado por utilizar o programa!\n");
    return 0;
}
