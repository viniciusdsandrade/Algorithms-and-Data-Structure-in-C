#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include "global.h"

#define MAX_EXERCISES 10

int exercicio01(void) {
    /**
    1. Suponha que criamos uma estrutura para armazenar produtos de um supermercado:

     typedef struct Produto{
        char nome[80];
        double preco;
        int quantidade;
    }Produto;

    Implemente duas fun??es, uma que devolve o vetor ordenado por pre?os e outra que devolve
    o vetor ordenado pela quantidade de itens no estoque. Os prot?tipos s?o:

    void ordenaPreco(Produto vet[], int n);
    void ordenaQuant(Produto vet[], int n);
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

    Implemente um algoritmo que receba um vetor de Datas como par?metro e que retorne as
    datas em ordem cronol?gica. Prot?tipo da fun??o ?:

    void ordena(struct Data vet[], int tam);

    Dica: Ordene o vetor separadamente por cada um dos campos.
    */

    printf("Digite a quantidade de datas: ");
    int n;

    scanf("%d", &n);
    return 0;
}

int exercicio03(void) {
    /**
    3. Suponha que criamos uma estrutura para armazenar dados de pessoas e uma outra estrutura
    para armazenar dados de v?rias pessoas como uma base de dados.

    typedef struct Pessoa{
        int rg;
        int cpf;
        char nome[80];
    }Pessoa;

    typedef struct Base{
        int armazenado; //Deve sempre corresponder ao n?mero de pessoas na base
        Pessoa pessoas[100];
    }Base;

    Crie fun??es para cada uma das opera??es abaixo:

     a) Cria base: esta fun??o devolve uma Base onde o campo armazenado ? inicializado
    com 0.
    Base cria_base();

    b) Inclui Pessoa: esta fun??o recebe como par?metro um dado do tipo Pessoa e o inclui
    na base (tamb?m passada por par?metro) caso j? n?o exista na base uma pessoa com
    o mesmo RG. A fun??o devolve 1 caso a inclus?o tenha ocorrido, devolve 0 caso a
    Base esteja cheia e devolve -1 caso j? exista uma pessoa com o RG informado.
    int insere_base(Pessoa p, Base base);

    c) Exclui Pessoa: esta fun??o recebe como par?metro um dado do tipo int representando
    o RG de uma pessoa e o exclui da base caso esteja presente. A fun??o devolve 1 caso a
    exclus?o tenha ocorrido, e devolve 0 caso n?o exista uma pessoa com o RG informado.
    int remove_base(int rg, Base base);
    */
    return 0;
}

int exercicio04(void) {
    /**
    4. Suponha que criamos uma estrutura para armazenar dados de pessoas e um vetor para
    armazenar dados de v?rias pessoas:

    typedef struct Pessoa{
        int rg;
        int cpf;
        char nome[80];
    }Pessoa;

    Pessoa cadastro[100];

    Suponha que o vetor esteja ordenado em ordem crescente por valor de RG. Implemente
    uma fun??o de busca por RG, que opera como a busca bin?ria, e que caso exista uma
    pessoa no cadastro com o RG a ser buscado, devolve o ?ndice deste no cadastro, e devolve
    -1 caso n?o exista uma pessoa com o RG a ser buscado.
     */
    return 0;
}

int exercicio05(void) {
    /**
    5. Refa?a as fun??es de busca sequencial e busca bin?ria vistas em aula assumindo que o
    vetor possui chaves que podem aparecer repetidas. Neste caso, voc? deve retornar em um
    outro vetor todas as posi??es onde a chave foi encontrada.
    Prot?tipo da fun??o: void busca(int vet[], int tam, int chave, int posicoes[], int
        *n)
    ? Voc? deve devolver em posicoes[] as posi??es de vet que possuem a chave, e devolver
    em *n o n?mero de ocorr?ncias da chave.
    ? OBS: Na chamada desta fun??o, o vetor posi??es deve ter espa?o suficiente
    (por exemplo, tam) para guardar todas as poss?veis ocorr?ncias da chave.
     */
    return 0;
}

int exercicio06(void) {

    /**
     6. O que ser? impresso pelo programa abaixo?
     #include <stdio.h>
     struct T{
         int x;
         int y;
     };
     typedef struct T T;
     void f1(T *a);
     void f2(int *b);
     int main(){
     T a, b, *c, *d;
     c = &a;
     a.x = 2;
     a.y = 4;
     b.x = 2;
     b.y = 2;
     d = c;
     f1(d);
     b = *d;
         printf("x: %d --- y: %d\n",b.x,b.y);
     }
     void f1(T *a){
        f2(&(a->x));
        f2(&(a->y));
     }
     void f2(int *b){
        *b = 2*(*b);
    }
    */
    return 0;
}

int exercicio07(void) {

    /**
    struct Aluno leAluno ( ) ;
    Esta fun??o faz a leitura dos dados de um registro Aluno e devolve o
    registro lido.

    void imprimeAluno (struct Aluno a) ;
    Esta fun??o recebe como par?metro um registro Aluno e imprime os
    dados do registro.

    void listarTurma (struc t Aluno turma [ ], int n ) ;
    Esta fun??o recebe como par?metros um vetor do tipo Aluno
    representando uma turma, e tamb?m um inteiro n indicando o
    tamanho do vetor. A fun??o imprime os dados de todos os alunos.
    */

    int numAlunos;
    printf("Digite o n?mero de alunos: ");
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
     fa?a a leitura de 5 alunos em uma fun??o.
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
    
    a) Crie uma função para leitura dos valores do 1 campo(vetor)    
    b) Some os valores do vetor e coloque o resultao no 2 campo
    c) Crie uma função para imprimir os valores de registro
    
     */

    Reg minhaReg;

    // Preencha minhaReg com valores
    minhaReg = leReg();

    // Realize a soma e atualize minhaReg
    minhaReg = somaVetorSegundoAtributo(minhaReg);

    // Imprima os valores da estrutura
    imprimeReg(minhaReg);

    return 0;
}

int displayMenuAndGetChoice() {
    printf("Exerc?cio 01:\n");
    printf("Exerc?cio 02:\n");
    printf("Exerc?cio 03:\n");
    printf("Exerc?cio 04:\n");
    printf("Exerc?cio 05:\n");
    printf("Exerc?cio 06:\n");
    printf("Exerc?cio 07:\n");
    printf("Exerc?cio 08:\n");
    printf("Exerc?cio 09:\n");
    printf("Exercício 10: \n");
    printf("Digite o n?mero do exerc?cio que deseja executar");

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
        default:
            printf("Op??o inv?lida!\n");
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