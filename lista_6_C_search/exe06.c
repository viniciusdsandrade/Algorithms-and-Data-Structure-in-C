#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <locale.h>
#include "global.h"

#define MAX_EXERCISES 11

int exercicio01(void) {
    /**
    1. Suponha que criamos uma estrutura para armazenar produtos de um supermercado:

     typedef struct Produto{
        char nome[80];
        double preco;
        int quantidade;
    }Produto;

    Implemente duas fun��es, uma que devolve o vetor ordenado por pre�os e outra que devolve
    o vetor ordenado pela quantidade de itens no estoque. Os prot�tipos s?o:

    void ordenaPreco(Produto vet[], int n);
    void ordenaQuantidade(Produto vet[], int n);
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

     typedef struct Data{
        int dia;
        int mes;
        int ano;
    }Data;

    Implemente um algoritmo que receba um vetor de Datas como par�metro e que retorne as
    datas em ordem cronol�gica. Prot�tipo da fun��o ?:

    void ordena(struct Data vet[], int tam);

    Dica: Ordene o vetor separadamente por cada um dos campos.
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
    para armazenar dados de v�rias pessoas como uma base de dados.

    typedef struct Pessoa{
        int rg;
        int cpf;
        char nome[80];
    }Pessoa;

    typedef struct Base{
        int armazenado; //Deve sempre corresponder ao n�mero de pessoas na base
        Pessoa pessoas[100];
    }Base;

    Crie fun??es para cada uma das opera??es abaixo:

    a) Cria base: esta fun??o devolve uma Base onde o campo armazenado ? inicializado
    com 0.
    Base cria_base();

    b) Inclui Pessoa: esta fun��o recebe como par�metro um dado do tipo Pessoa e o inclui
    na base (tamb�m passada por par�metro) caso j� n�o exista na base uma pessoa com
    o mesmo RG. A fun��o devolve 1 caso a incluso tenha ocorrido, devolve 0 caso a
    Base esteja cheia e devolve -1 caso j? exista uma pessoa com o RG informado.
    int insere_base(Pessoa p, Base base);

    c) Exclui Pessoa: esta fun??o recebe como par�metro um dado do tipo int representando
    o RG de uma pessoa e o exclui da base caso esteja presente. A fun??o devolve 1 caso a
    exclus�o tenha ocorrido, e devolve 0 caso n?o exista uma pessoa com o RG informado.
    int remove_base(int rg, Base base);
    */
    return 0;
}

int exercicio04(void) {
    /**
 * Fun��o para buscar uma pessoa por RG em um vetor de cadastro ordenado por RG.
 *
 * Esta fun��o realize uma busca bin�ria em um vetor de cadastro de pessoas ordenado
 * em ordem crescente por valor de RG. Se uma pessoa com o RG especificado for encontrada,
 * a fun��o retorna o �ndice dessa pessoa no vetor de cadastro. Caso contr�rio, ela
 * retorna -1, indicando que a pessoa n�o foi encontrada.
 *
 * @param cadastro O vetor de cadastro de pessoas ordenado por RG.
 * @param tamanho O tamanho do vetor de cadastro.
 * @param rg O RG a ser buscado.
 * @return O �ndice da pessoa com o RG especificado no vetor de cadastro ou -1 se n�o
 * for encontrada.
 *
 * @note Para usar esta fun��o, � importante que o vetor de cadastro esteja ordenado
 * em ordem crescente por valor de RG.
 */
    return 0;
}

int exercicio05(void) {
    /**
 * Fun��o para buscar todas as ocorr�ncias de uma chave em um vetor.
 *
 * Esta fun��o realiza uma busca em um vetor 'vet' de tamanho 'tam' e procura pela
 * chave especificada. Ela registra todas as posi��es onde a chave foi encontrada no
 * vetor 'posicoes' e retorna o n�mero total de ocorr�ncias da chave em '*n'.
 *
 * @param vet O vetor no qual realizar a busca.
 * @param tam O tamanho do vetor 'vet'.
 * @param chave A chave a ser procurada no vetor.
 * @param posicoes Um vetor onde as posi��es da chave encontradas ser�o armazenadas.
 * @param n Um ponteiro para armazenar o n�mero de ocorr�ncias da chave.
 *
 * @note A chamada desta fun��o deve fornecer um vetor 'posicoes' com espa�o suficiente
 * para acomodar todas as poss�veis ocorr�ncias da chave (por exemplo, tamanho 'tam').
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
    <p>struct Aluno leAluno ( ) ;
    <p> Esta fun��o faz a leitura dos dados de um registro Aluno e devolve o
    registro lido.

    <p>void imprimeAluno (struct Aluno a) ;
    <p>Esta fun��o recebe como par?metro um registro Aluno e imprime os
    dados do registro.

   <p> void listarTurma (struc t Aluno turma [ ], int n ) ;
   <p> Esta fun��o recebe como par�metros um vetor do tipo Aluno
   <p> representando uma turma, e tamb�m um inteiro n indicando o
   <p> tamanho do vetor. A fun��o imprime os dados de todos os alunos.
    */

    int numAlunos;
    printf("Digite o n�mero de alunos: ");
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
     fa�a a leitura de 5 alunos em uma fun��o.
     Calcule e imprima a m?dia das idades dos alunos.
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
    
    Crie um novo tipo de registro para armazenar coordenadas no plano
    cartesiano.
    Crie uma Fun??o para imprimir um ponto do tipo criado.
    Crie uma Fun??o para cada uma destas opera??es: soma de dois
    pontos, subtra??o de dois pontos, multiplica??o por um escalar.
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

    printf("Subtra��o dos pontos:\n");
    imprimePonto(subtraiPonto(p1, p2));

    printf("Multiplica��o do ponto 1 por um escalar:\n");
    imprimePonto(multiplicaPonto(p1, 2));

    printf("Multiplica��o do ponto 2 por um escalar:\n");
    imprimePonto(multiplicaPonto(p2, 2));

    return 0;
}

int exercicio10(void) {
    /**
    Defina uma vari�vel do tipo registro que tenha dois campinas, senodo o  1 um vetor de 3 elementos do tipo inteiro
    e o 2 campo um valor inteiro. Fa�a:
    
    a) Crie uma fun��o para leitura dos valores do 1 campo(vetor)    
    b) Some os valores do vetor e coloque o resultao no 2 campo
    c) Crie uma fun��o para imprimir os valores de registro
     */

    Reg minhaReg;

    minhaReg = leReg();

    minhaReg = somaVetorSegundoAtributo(minhaReg);

    imprimeReg(minhaReg);

    return 0;
}

int exercicio11(void) {

    /** Crie uma fun��o que recebe duas strings de tamanhos quaisqueres e que devolve a concatena��o destas
     * lembre-se que uma fun��o n�o pode devolver um vetor, mas ela pode devolver um ponteiro, o prot�tipo da fun��o ser�
     *
     * char * concatena(char *s1, char *s2);
     */

    char *s1 = "Hello";
    char *s2 = "World";

    char *s3 = concatena(s1, s2);

    printf("%s", s3);

    free(s3);

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
    printf("Digite o n?n�mero do Exerc�cio que deseja executar");

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
            printf("Op��o inv�lida!\n");
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
            printf("Op��o inv�lida!\n");
        }
        sair = getExitChoice();
    } while (!sair);
    printf("Obrigado por utilizar o programa!\n");
    return 0;
}