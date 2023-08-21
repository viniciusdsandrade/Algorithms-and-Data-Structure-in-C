#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int exercicio01(void) {
    /*
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
}

int exercicio02(void) {
    /*
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
     * */
    return 0;
}

int exercicio03(void) {
    /*
     * 3. Suponha que criamos uma estrutura para armazenar dados de pessoas e uma outra estrutura
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
    /*
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
    return 0;
}

int exercicio06(void) {
    return 0;
}


int main(void){

    return 0;
}

