#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include "global.h"

#define MAX_EXERCISES 9

int exercicio01(void) {
    /**
    1. Suponha que criamos uma estrutura para armazenar produtos de um supermercado:

     typedef struct Produto{
        char nome[80];
        double preco;
        int quantidade;
    }Produto;

    Implemente duas funções, uma que devolve o vetor ordenado por preços e outra que devolve
    o vetor ordenado pela quantidade de itens no estoque. Os protótipos são:

    void ordenaPreco(Produto vet[], int n);
    void ordenaQuant(Produto vet[], int n);
     */

    printf("Digite a quantidade de produtos: ");
    int n;
    scanf("%d", &n);

    Produto *produtos = lerProdutos(n);

    ordenaPreco(produtos, n);
    printf("Produtos ordenados por preço:\n");
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

    Implemente um algoritmo que receba um vetor de Datas como parâmetro e que retorne as
    datas em ordem cronológica. Protótipo da função é:

    void ordena(struct Data vet[], int tam);

    Dica: Ordene o vetor separadamente por cada um dos campos.
    */
    return 0;
}

int exercicio03(void) {
    /**
    3. Suponha que criamos uma estrutura para armazenar dados de pessoas e uma outra estrutura
    para armazenar dados de várias pessoas como uma base de dados.

    typedef struct Pessoa{
        int rg;
        int cpf;
        char nome[80];
    }Pessoa;

    typedef struct Base{
        int armazenado; //Deve sempre corresponder ao número de pessoas na base
        Pessoa pessoas[100];
    }Base;

    Crie funções para cada uma das operações abaixo:

     a) Cria base: esta função devolve uma Base onde o campo armazenado é inicializado
    com 0.
    Base cria_base();

    b) Inclui Pessoa: esta função recebe como parâmetro um dado do tipo Pessoa e o inclui
    na base (também passada por parâmetro) caso já não exista na base uma pessoa com
    o mesmo RG. A função devolve 1 caso a inclusão tenha ocorrido, devolve 0 caso a
    Base esteja cheia e devolve -1 caso já exista uma pessoa com o RG informado.
    int insere_base(Pessoa p, Base base);

    c) Exclui Pessoa: esta função recebe como parâmetro um dado do tipo int representando
    o RG de uma pessoa e o exclui da base caso esteja presente. A função devolve 1 caso a
    exclusão tenha ocorrido, e devolve 0 caso não exista uma pessoa com o RG informado.
    int remove_base(int rg, Base base);
    */
    return 0;
}

int exercicio04(void) {
    /**
    4. Suponha que criamos uma estrutura para armazenar dados de pessoas e um vetor para
    armazenar dados de várias pessoas:

    typedef struct Pessoa{
        int rg;
        int cpf;
        char nome[80];
    }Pessoa;

    Pessoa cadastro[100];

    Suponha que o vetor esteja ordenado em ordem crescente por valor de RG. Implemente
    uma função de busca por RG, que opera como a busca binária, e que caso exista uma
    pessoa no cadastro com o RG a ser buscado, devolve o índice deste no cadastro, e devolve
    -1 caso não exista uma pessoa com o RG a ser buscado.
     */
    return 0;
}

int exercicio05(void) {
    /**
    5. Refaça as funções de busca sequencial e busca binária vistas em aula assumindo que o
    vetor possui chaves que podem aparecer repetidas. Neste caso, você deve retornar em um
    outro vetor todas as posições onde a chave foi encontrada.
    Protótipo da função: void busca(int vet[], int tam, int chave, int posicoes[], int
        *n)
    ? Você deve devolver em posicoes[] as posições de vet que possuem a chave, e devolver
    em *n o número de ocorrências da chave.
    ? OBS: Na chamada desta função, o vetor posições deve ter espaço suficiente
    (por exemplo, tam) para guardar todas as possíveis ocorrências da chave.
     */
    return 0;
}

int exercicio06(void) {

    /*
     6. O que será impresso pelo programa abaixo?
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

    /*
    struct Aluno leAluno ( ) ;
    Esta função faz a leitura dos dados de um registro Aluno e devolve o
    registro lido.

    void imprimeAluno (struct Aluno a) ;
    Esta função recebe como parâmetro um registro Aluno e imprime os
    dados do registro.

    void listarTurma (struc t Aluno turma [ ], int n ) ;
    Esta função recebe como parâmetros um vetor do tipo Aluno
    representando uma turma, e também um inteiro n indicando o
    tamanho do vetor. A função imprime os dados de todos os alunos.
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
     faça a leitura de 5 alunos em uma função.
     Calcule e imprima a média das idades dos alunos.
     */

    int numAlunes;
    printf("Digite o número de alunos: ");
    scanf("%d", &numAlunes);
    Alune *alunes = leAlunes(numAlunes);

    printf("A média das idades é: %.2f", mediaAlunes(alunes, 5));

    free(alunes);
    return 0;
}

int exercicio09(void) {
    /**
    Crie um novo tipo de registro para armazenar coordenadas no plano
    cartesiano.
    Crie uma Função para imprimir um ponto do tipo criado.
    Crie uma Função para cada uma destas operações: soma de dois
    pontos, subtração de dois pontos, multiplicação por um escalar.
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

// Function to display exercise menu and get user choice
int displayMenuAndGetChoice() {
    printf("Exercício 01:\n");
    printf("Exercício 02:\n");
    printf("Exercício 03:\n");
    printf("Exercício 04:\n");
    printf("Exercício 05:\n");
    printf("Exercício 06:\n");
    printf("Exercício 07:\n");
    printf("Exercício 08:\n");
    printf("Exercício 09:\n");
    printf("Digite o número do exercício que deseja executar");

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
        default:
            printf("Opção inválida!\n");
            break;
    }
}


// Function to validate and get user's exit choice
bool getExitChoice() {
    int sair;
    do {
        printf("Deseja sair? Digite (1) para Sim ou (0) para Não: ");
        scanf("%d", &sair);
    } while (sair != 0 && sair != 1);
    return sair;
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    bool sair = false;  // Use boolean instead of int for exit choice
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



