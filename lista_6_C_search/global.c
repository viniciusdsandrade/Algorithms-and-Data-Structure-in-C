#include <math.h>
#include <malloc.h>
#include "global.h"

/**
 * @struct Produto
 * 
 * Estrutura que representa um produto com nome, preço e quantidade.
 */
typedef struct Produto {
    char nome[80];      /**< Nome do produto. */
    double preco;       /**< Preço do produto. */
    int quantidade;     /**< Quantidade disponível do produto. */
} Produto;

/**
 * @struct Aluno
 * 
 * Estrutura que representa um aluno com nome e nota.
 */
typedef struct Aluno {
    char nome[80];      /**< Nome do aluno. */
    float nota;         /**< Nota do aluno. */
} Aluno;

/**
 * @struct Alune
 * 
 * Estrutura que representa um aluno com RA (Registro Acadêmico) e nota.
 */
typedef struct Alune {
    int ra;             /**< Registro Acadêmico (RA) do aluno. */
    double nota;        /**< Nota do aluno. */
} Alune;

/**
 * @struct Ponto
 * 
 * Estrutura que representa um ponto no plano cartesiano com coordenadas x e y.
 */
typedef struct Ponto {
    double x;           /**< Coordenada x do ponto. */
    double y;           /**< Coordenada y do ponto. */
} Ponto;


/**
 * @struct Reg
 * 
 * Estrutura que representa um registro com um vetor de inteiros com 3 elementos
 * e uma variável inteira.
 */
typedef struct Reg {
    int vet[3];  /**< Vetor de inteiros com 3 elementos. */
    int n;       /**< Variável inteira. */
} Reg;

/**
 * @struct Data
 * 
 * Estrutura que representa uma data com dia, mês e ano.
 */
typedef struct Data {
    int dia; /**< Dia da data. */
    int mes; /**< Mês da data. */
    int ano; /**< Ano da data. */
} Data;

/**
 * @struct Pessoa
 * 
 * Estrutura que representa uma pessoa com RG, CPF e nome.
 */
typedef struct Pessoa {
    int rg; /**< Registro Geral (RG) da pessoa. */
    int cpf; /**< Cadastro de Pessoa Física (CPF) da pessoa. */
    char nome[80]; /**< Nome da pessoa. */
} Pessoa;

/**
 * @struct Base
 * 
 * Estrutura que representa uma base de dados de pessoas.
 */
typedef struct Base {
    int armazenado; /**< Número de pessoas armazenadas na base. Deve sempre corresponder ao número de pessoas na base. */
    Pessoa pessoas[100]; /**< Array de pessoas armazenadas na base. */
} Base;

/**
 * Lê os dados de um vetor de produtos da entrada padrão.
 *
 * Esta função aloca memória para o vetor de produtos e preenche seus elementos
 * com os dados lidos da entrada padrão.
 *
 * @param n O número de produtos a serem lidos.
 * @return Um ponteiro para o vetor de produtos preenchido.
 */
Produto *lerProdutos(int n) {
    Produto *produtos = malloc(n * sizeof(Produto));
    for (int i = 0; i < n; i++) {
        printf("Digite o nome do produto %d: ", i + 1);
        scanf("%s", produtos[i].nome);
        printf("Digite o preço do produto %d: ", i + 1);
        scanf("%lf", &produtos[i].preco);
        printf("Digite a quantidade do produto %d: ", i + 1);
        scanf("%d", &produtos[i].quantidade);
    }
    return produtos;
}

/**
 * Ordena um array de produtos por preço em ordem crescente.
 *
 * Esta função utiliza o algoritmo de ordenação "Selection Sort" para ordenar
 * um array de produtos por preço em ordem crescente.
 *
 * @param vet O array de produtos a ser ordenado.
 * @param n O número de elementos no array.
 */
void ordenaPreco(Produto vet[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (vet[i].preco > vet[j].preco) {
                Produto aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
}

/**
 * Ordena um array de produtos por quantidade em ordem crescente.
 *
 * Esta função utiliza o algoritmo de ordenação "Selection Sort" para ordenar
 * um array de produtos por quantidade em ordem crescente.
 *
 * @param vet O array de produtos a ser ordenado.
 * @param n O número de elementos no array.
 */
void ordenaQuant(Produto vet[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (vet[i].quantidade > vet[j].quantidade) {
                Produto aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
}

/**
 * Imprime os dados de uma lista de produtos na saída padrão.
 *
 * Esta função recebe um vetor de produtos e o número de elementos no vetor,
 * e imprime na saída padrão os detalhes de cada produto.
 *
 * @param vet O vetor de produtos a ser impresso.
 * @param n O número de elementos no vetor.
 */
void imprimeProduto(Produto vet[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nome: %s\n", vet[i].nome);
        printf("Preço: %.2lf\n", vet[i].preco);
        printf("Quantidade: %d\n", vet[i].quantidade);
    }
}

/**
 * Lê os dados de um produto (nome, preço e quantidade) da entrada padrão.
  @return Uma estrutura Produto preenchida com os dados lidos.
*/
Produto *leProdutos(int n) {
    Produto *produtos = malloc(n * sizeof(Produto));
    for (int i = 0; i < n; i++) {
        printf("Digite o nome do produto %d: ", i + 1);
        scanf("%s", produtos[i].nome);
        printf("Digite o preço do produto %d: ", i + 1);
        scanf("%lf", &produtos[i].preco);
        printf("Digite a quantidade do produto %d: ", i + 1);
        scanf("%d", &produtos[i].quantidade);
    }
    return produtos;
}


/**
 * Lê os dados de um vetor de alunos da entrada padrão.
 *
 * Esta função aloca memória para o vetor de alunos e preenche seus elementos
 * com os dados lidos da entrada padrão.
 *
 * @param n O número de alunos a serem lidos.
 * @return Um ponteiro para o vetor de alunos preenchido.
 */
Aluno *leAlunos(int n) {
    Aluno *alunos = malloc(n * sizeof(Aluno));
    if (alunos == NULL) {
        fprintf(stderr, "Erro na alocação de memória\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        printf("Nome: ");
        scanf("%s", alunos[i].nome);
        printf("Nota: ");
        scanf("%f", &alunos[i].nota);
    }
    return alunos;
}

/**
 * Lê os dados de um vetor de alunes da entrada padrão.
 *
 * Esta função aloca memória para o vetor de alunes e preenche seus elementos
 * com os dados lidos da entrada padrão.
 *
 * @param n O número de alunes a serem lidos.
 * @return Um ponteiro para o vetor de alunes preenchido.
 */
Alune *leAlunes(int n) {
    Alune *alunes = malloc(n * sizeof(Alune));
    if (alunes == NULL) {
        fprintf(stderr, "Erro na alocação de memória\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        printf("RA: ");
        scanf("%d", &alunes[i].ra);
        printf("Nota: ");
        scanf("%lf", &alunes[i].nota);
    }
    return alunes;
}

/**
 * Imprime os dados de um aluno na saída padrão.
 *
 * @param a A estrutura Aluno a ser impressa.
 */
void imprimeAluno(Aluno a) {
    printf("Nome: %s\n", a.nome);
    printf("Nota: %.2f\n", a.nota);
}

/**
 * Lista os dados de uma turma de alunos na saída padrão.
 *
 * @param turma O array de estruturas Aluno representando a turma.
 * @param n O número de alunos na turma.
 */
void listarTurma(Aluno turma[], int n) {
    for (int i = 0; i < n; i++) {
        imprimeAluno(turma[i]);
    }
}

/**
 * Calcula a média das notas dos alunos em uma estrutura Alune.
 *
 * @param alunos O array de estruturas Alune contendo os dados dos alunos.
 * @param n O número de alunos na estrutura.
 * @return A média das notas dos alunos.
 */
double mediaAlunes(struct Alune alunos[], int n) {
    double soma = 0;
    for (int i = 0; i < n; i++) {
        soma += alunos[i].nota;
    }
    return soma / n;
}

/**
 * Lê as coordenadas de um ponto da entrada padrão.
 *
 * @return Uma estrutura Ponto preenchida com as coordenadas lidas.
 */
Ponto lePonto() {
    Ponto p;
    printf("Digite o valor de x: ");
    scanf("%lf", &p.x);
    printf("Digite o valor de y: ");
    scanf("%lf", &p.y);
    return p;
}

/**
 * Imprime as coordenadas de um ponto na saída padrão.
 *
 * @param p A estrutura Ponto a ser impressa.
 */
void imprimePonto(Ponto p) {
    printf("x: %lf\n", p.x);
    printf("y: %lf\n", p.y);
}

/**
 * Calcula a soma de dois pontos.
 *
 * @param p1 O primeiro ponto.
 * @param p2 O segundo ponto.
 * @return Uma estrutura Ponto representando a soma dos dois pontos.
 */
Ponto somaPonto(Ponto p1, Ponto p2) {
    Ponto soma;
    soma.x = p1.x + p2.x;
    soma.y = p1.y + p2.y;
    return soma;
}

/**
 * Calcula a subtração de dois pontos.
 *
 * @param p1 O ponto do qual será subtraído.
 * @param p2 O ponto a ser subtraído.
 * @return Uma estrutura Ponto representando a subtração dos dois pontos.
 */
Ponto subtraiPonto(Ponto p1, Ponto p2) {
    Ponto subtrai;
    subtrai.x = p1.x - p2.x;
    subtrai.y = p1.y - p2.y;
    return subtrai;
}

/**
 * Calcula a multiplicação de um ponto por um escalar.
 *
 * @param p1 O ponto a ser multiplicado.
 * @param escalar O valor do escalar.
 * @return Uma estrutura Ponto representando a multiplicação do ponto pelo escalar.
 */
Ponto multiplicaPonto(Ponto p1, double escalar) {
    Ponto multiplica;
    multiplica.x = p1.x * escalar;
    multiplica.y = p1.y * escalar;
    return multiplica;
}

/**
 * Calcula a distância entre dois pontos.
 *
 * @param p1 O primeiro ponto.
 * @param p2 O segundo ponto.
 * @return A distância entre os dois pontos.
 */
double distanciaPonto(Ponto p1, Ponto p2) {
    double distancia;
    distancia = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    return distancia;
}


/**
 * Função que lê valores para a estrutura Reg e retorna a estrutura preenchida.
 *
 * Esta função solicita ao usuário que insira valores para o vetor de inteiros e a variável
 * inteira dentro da estrutura Reg. Em seguida, ela retorna a estrutura Reg preenchida.
 *
 * @return A estrutura Reg preenchida.
 */
Reg leReg(void) {
    Reg reg;

    for (int i = 0; i < 3; i++) {
        printf("Digite o valor para Reg.vet[%d]: ", i);
        scanf("%d", &(reg.vet[i]));
    }

    printf("Digite o valor para Reg.n: ");
    scanf("%d", &(reg.n));

    return reg;
}

/**
 * Função que soma os valores do vetor do primeiro atributo da estrutura Reg e armazena o resultado no segundo atributo.
 *
 * Esta função calcula a soma dos valores do vetor de inteiros no primeiro atributo da estrutura Reg
 * e armazena o resultado no segundo atributo da mesma estrutura.
 *
 * @param reg A estrutura Reg na qual os valores serão somados e armazenados.
 * @return A estrutura Reg com o segundo atributo atualizado.
 */
Reg somaVetorSegundoAtributo(Reg reg) {
    int soma = 0;

    // Calcula a soma dos valores do vetor do primeiro atributo
    for (int i = 0; i < 3; i++) {
        soma += reg.vet[i];
    }

    // Armazena o resultado no segundo atributo (reg.vet[1])
    Reg resultado = reg;
    resultado.vet[1] = soma;

    return resultado;
}

/**
 * Função que imprime os valores de uma estrutura Reg.
 *
 * Esta função imprime os valores do vetor de inteiros e da variável
 * inteira dentro da estrutura Reg.
 *
 * @param reg A estrutura Reg cujos valores serão impressos.
 */
void imprimeReg(Reg reg) {
    printf("Valores da estrutura Reg:\n");
    
    printf("Vetor de inteiros: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", reg.vet[i]);
    }
    printf("\n");

    printf("Variável inteira (n): %d\n", reg.n);
}