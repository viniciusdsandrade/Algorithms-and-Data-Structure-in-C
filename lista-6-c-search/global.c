#include <math.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>

typedef struct Cell {
    char car;
    int peso;
} Cell;

char *replicarStringComEspacos(const char *vetor, int vezes) {
    if (vetor == NULL || vezes <= 0) {
        return NULL;
    }

    size_t tamanhoOriginal = strlen(vetor);
    size_t tamanhoReplicado = (tamanhoOriginal + 1) * vezes;
    tamanhoReplicado--;

    char *resultado = (char *) malloc(tamanhoReplicado + 1);

    if (resultado == NULL) {
        return NULL;
    }

    resultado[0] = '\0';

    for (int i = 0; i < vezes; i++) {
        strcat(resultado, vetor);
        if (i < vezes - 1) {
            strcat(resultado, " ");
        }
    }

    return resultado;
}

int somaPeso(Cell vet[], int n) {

    int pesoTotal = 0;

    for (int i = 0; i < n; i++) {
        char letraAtual = vet[i].car;
        int pesoAtual = vet[i].peso;
        int sequencia = 1;

        while (i + 1 < n && vet[i + 1].car == letraAtual) {
            sequencia++;
            i++;
        }
        pesoTotal += sequencia * pesoAtual;
    }
    return pesoTotal;
}

/**
 * @struct Produto
 *
 * Estrutura que representa um produto com nome, preço e quantidade.
 */
typedef struct Produto {
    char nome[80];
    double preco;
    int quantidade;
} Produto;

/**
 * @struct Aluno
 *
 * Estrutura que representa um aluno com nome e nota.
 */
typedef struct Aluno {
    char nome[80];
    float nota;
} Aluno;

/**
 * @struct Alune
 *
 * Estrutura que representa um aluno com RA (Registro Acadêmico) e nota.
 */
typedef struct Alune {
    int ra;
    double nota;
} Alune;

/**
 * @struct Ponto
 *
 * Estrutura que representa um ponto no plano cartesiano com coordenadas x e y.
 */
typedef struct Ponto {
    double x;
    double y;
} Ponto;

/**
 * @struct Reg
 *
 * Estrutura que representa um registro com um vetor de inteiros com 3 elementos
 * e uma variável inteira.
 */
typedef struct Reg {
    int vet[3];
    int n;
} Reg;

/**
 * @struct Data
 *
 * Estrutura que representa uma data com dia, mês e ano.
 */
typedef struct Data {
    int dia;
    int mes;
    int ano;
} Data;

/**
 * @struct Pessoa
 *
 * Estrutura que representa uma pessoa com RG, CPF e nome.
 */
typedef struct Pessoa {
    int rg;
    int cpf;
    char nome[80];
} Pessoa;

/**
 * @struct Base
 *
 * Estrutura que representa uma base de dados de pessoas.
 */
typedef struct Base {
    int armazenado;
    Pessoa pessoas[100];
} Base;

/**
 * Troca os valores de duas variáveis inteiras.
 *
 * Esta função recebe dois ponteiros para inteiros, 'a' e 'b', e troca os valores das variáveis
 * para que 'a' contenha o valor original de 'b' e 'b' contenha o valor original de 'a'.
 *
 * @param a Ponteiro para o primeiro inteiro a ser trocado.
 * @param b Ponteiro para o segundo inteiro a ser trocado.
 */
void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

/**
 * Encontra o índice do menor valor em um vetor a partir de uma posição inicial.
 *
 * Esta função recebe um vetor 'vet', seu tamanho 'tam' e um índice 'ini' como argumentos.
 * Ela busca o menor valor no vetor 'vet' a partir da posição 'ini' e retorna o índice do menor valor encontrado.
 *
 * @param vet O vetor de inteiros onde a busca é realizada.
 * @param tam O tamanho do vetor 'vet'.
 * @param ini O índice inicial a partir do qual a busca pelo menor valor é feita.
 * @return O índice do menor valor encontrado no vetor 'vet'.
 */
int indiceMenor(const int vet[], int tam, int ini) {
    int menor = ini;
    int j;
    for (j = ini + 1; j < tam; j++) {
        if (vet[j] < vet[menor])
            menor = j;
    }
    return menor;
}

/**
 * Ordena um vetor de inteiros usando o algoritmo Selection Sort.
 *
 * Esta função recebe um vetor 'vet' de inteiros e seu tamanho 'tam'. Ela ordena o vetor 'vet'
 * em ordem crescente usando o algoritmo Selection Sort. O algoritmo divide o vetor em uma
 * parte ordenada e outra não ordenada, encontrando repetidamente o menor valor da parte não
 * ordenada e movendo-o para a parte ordenada.
 *
 * @param vet O vetor de inteiros a ser ordenado.
 * @param tam O tamanho do vetor 'vet'.
 */
void selectionSort(int vet[], int tam) {
    int i, min;
    for (i = 0; i < tam - 1; i++) {
        min = indiceMenor(vet, tam, i);
        troca(&vet[i], &vet[min]);
    }
}

/**
 * Ordena um vetor de inteiros usando o algoritmo Selection Sort.
 *
 * Esta função recebe um vetor 'vet' de inteiros e seu tamanho 'tam'. Ela ordena o vetor 'vet'
 * em ordem crescente usando o algoritmo Selection Sort. O algoritmo divide o vetor em uma
 * parte ordenada e outra não ordenada, encontrando repetidamente o menor valor da parte não
 * ordenada e movendo-o para a parte ordenada.
 *
 * @param vet O vetor de inteiros a ser ordenado.
 * @param tam O tamanho do vetor 'vet'.
 */
void selectionSortAbstrato(int vet[], int tam) {
    int i, min, aux;
    for (i = 0; i < tam; i++) {
        min = i;
        for (int j = i + 1; j < tam; j++) {
            if (vet[j] < vet[min]) {
                min = j;
            }
        }
        aux = vet[i];
        vet[i] = vet[min];
        vet[min] = aux;
    }
}

/**
 * Ordena um vetor de inteiros usando o algoritmo Bubble Sort.
 *
 * Esta função recebe um vetor 'vet' de inteiros e seu tamanho 'tam'. Ela ordena o vetor 'vet'
 * em ordem crescente usando o algoritmo Bubble Sort. O algoritmo compara repetidamente pares
 * de elementos adjacentes e os troca se estiverem fora de ordem, empurrando os maiores valores
 * para o final do vetor em cada passagem.
 *
 * @param vet O vetor de inteiros a ser ordenado.
 * @param tam O tamanho do vetor 'vet'.
 */
void bubbleSort(int vet[], int tam) {
    int i, j;
    for (i = tam - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (vet[j] > vet[j + 1]) {
                int aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
                //troca(&vet[j], &vet[j + 1]);
            }
        }
    }
}

/**
 * Ordena um vetor de inteiros usando o algoritmo Insertion Sort.
 *
 * Esta função recebe um vetor 'vet' de inteiros e seu tamanho 'tam'. Ela ordena o vetor 'vet'
 * em ordem crescente usando o algoritmo Insertion Sort, que constrói uma parte ordenada do vetor
 * um elemento por vez, inserindo cada elemento na posição correta.
 *
 * @param vet O vetor de inteiros a ser ordenado.
 * @param tam O tamanho do vetor 'vet'.
 */
void insertionSort(int vet[], int tam) {
    int i, j, aux;
    for (i = 1; i < tam; i++) {
        aux = vet[i];
        for (j = i; j > 0 && aux < vet[j - 1]; j--) {
            vet[j] = vet[j - 1];
        }
        vet[j] = aux;
    }
}

/**
 * Realiza uma busca linear por uma chave em um vetor de inteiros.
 *
 * Esta função recebe um vetor 'vet' de inteiros, seu tamanho 'tam' e uma chave de busca 'chave'.
 * Ela realiza uma busca linear no vetor 'vet' para encontrar a posição da chave, se exists.
 *
 * @param vet O vetor de inteiros onde a busca é realizada.
 * @param tam O tamanho do vetor 'vet'.
 * @param chave A chave de busca a ser encontrada.
 * @return A posição da chave no vetor ou -1 se a chave não for encontrada.
 */
int linearSearch(const int vet[], int tam, int chave) {
    for (int i = 0; i < tam; i++) {
        if (vet[i] == chave) {
            return i;
        }
    }
    return -1; // Chave não encontrada.
}

/**
 * Realiza uma busca binária por uma chave em um vetor de inteiros ordenado.
 *
 * Esta função recebe um vetor 'vet' de inteiros ordenado, seu tamanho 'tam' e uma chave de busca 'chave'.
 * Ela realiza uma busca binária no vetor 'vet' para encontrar a posição da chave, se existir.
 *
 * @param vet O vetor de inteiros ordenado onde a busca é realizada.
 * @param tam O tamanho do vetor 'vet'.
 * @param chave A chave de busca a ser encontrada.
 * @return A posição da chave no vetor ou -1 se a chave não for encontrada.
 */
int binarySearch(const int vet[], int tam, int chave) {
    int inicio = 0;
    int fim = tam - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (vet[meio] == chave)
            return meio;
        else if (vet[meio] < chave)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }
    return -1;
}

/**
 * Lê informações de um aluno da entrada padrão.
 *
 * Esta função solicita ao usuário que digite o nome e a nota de um aluno.
 * Ela lê o nome como uma linha de até 80 caracteres e a nota como um número
 * em ponto flutuante. Após a leitura, ela remove o caractere de nova linha ('\n')
 * do final do nome e retorna uma estrutura "Aluno" preenchida com os dados lidos.
 *
 * @return Uma estrutura "Aluno" preenchida com o nome e a nota lidos da entrada padrão.
 */
Aluno leAluno() {
    Aluno aux;

    printf("Digite o nome do aluno: ");
    fgets(aux.nome, 80, stdin);
    aux.nome[strlen(aux.nome) - 1] = '\0';
    printf("Digite a nota do aluno: ");
    scanf("%f", &aux.nota);
    getchar();
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
void listarTurma(Aluno alunos[], int n) {
    for (int i = 0; i < n; i++) {
        imprimeAluno(alunos[i]);
    }
}

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
        printf("Name of product %d:     ", i + 1);
        scanf("%s", produtos[i].nome);
        printf("Price of product %d:    ", i + 1);
        scanf("%lf", &produtos[i].preco);
        printf("Quantity of product %d: ", i + 1);
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
void ordenaQtd(Produto vet[], int n) {
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
        printf("Name:     %s\n", vet[i].nome);
        printf("Price:    %.2lf\n", vet[i].preco);
        printf("Quantity: %d\n", vet[i].quantidade);
        putchar('\n');
    }
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
 * Calcula a média das notas dos alunos em uma estrutura Alune.
 *
 * @param alunos O array de estruturas Alune contendo os dados dos alunos.
 * @param n O número de alunos na estrutura.
 * @return A média das notas dos alunos.
 */
double mediaAlunes(struct Alune alunes[], int n) {
    double soma = 0;
    for (int i = 0; i < n; i++) {
        soma += alunes[i].nota;
    }
    return soma / n;
}

/**
 * Lê as coordenadas de um ponto da entrada padrão.
 *
 * @return Uma estrutura Ponto preenchida com as coordenadas lidas.
 */
Ponto *lePonto() {

    Ponto *ponto = malloc(sizeof(Ponto));

    if (ponto == NULL) {
        fprintf(stderr, "Erro na alocação de memória\n");
        exit(1);
    }

    printf("Digite a coordenada x: ");
    scanf("%lf", &ponto->x);

    printf("Digite a coordenada y: ");
    scanf("%lf", &ponto->y);

    return ponto;
}

/**
 * Imprime as coordenadas de um ponto na saída padrão.
 *
 * @param p A estrutura Ponto a ser impressa.
 */
void imprimePonto(Ponto p) {
    printf("x: %.2lf\n", p.x);
    printf("y: %.2lf\n", p.y);
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
 * Soma dois pontos e retorna um novo ponto.
 *
 * Esta função aloca dinamicamente memória para armazenar o resultado da soma dos
 * pontos `p1` e `p2`. Certifique-se de liberar essa memória usando `free` quando
 * o resultado não for mais necessário para evitar vazamentos de memória.
 *
 * @param p1 - O primeiro ponto a ser somado.
 * @param p2 - O segundo ponto a ser somado.
 * @return Um novo ponto que é a soma de `p1` e `p2`, ou NULL em caso de erro de alocação.
 */
Ponto *somaPonto2(Ponto *p1, Ponto *p2) {
    Ponto *soma = malloc(sizeof(Ponto));
    if (soma == NULL) {
        fprintf(stderr, "Erro na alocação de memória\n");
        exit(1);
    }
    soma->x = p1->x + p2->x;
    soma->y = p1->y + p2->y;
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

    for (int i = 0; i < 3; i++) {
        soma += reg.vet[i];
    }

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

/**
 * Função que concatena duas strings.
 *
 * Esta função concatena duas strings e retorna uma nova string com o resultado.
 *
 * @param s1 A primeira string a ser concatenada.
 * @param s2 A segunda string a ser concatenada.
 * @return Uma nova string com o resultado da concatenação.
 */
char *concatena(char *s1, char *s2) {
    char *sres = NULL;
    int t1, t2, i;

    t1 = strlen(s1);
    t2 = strlen(s2);

    sres = malloc((t1 + t2 + 1) * sizeof(char));

    for (i = 0; i < t1; i++)
        sres[i] = s1[i];
    for (i = 0; i < t2; i++)
        sres[t1 + i] = s2[i];
    sres[t1 + t2] = '\0';

    return sres;
}

/**
 * Função que realiza a troca de duas estruturas Data.
 *
 * @param a O ponteiro para a primeira estrutura Data.
 * @param b O ponteiro para a segunda estrutura Data.
 */
void swapData(Data *a, Data *b) {
    Data temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Função que ordena um vetor de estruturas Data por dia.
 *
 * @param vet Um vetor de estruturas Data.
 * @param tam O tamanho do vetor.
 */
void ordenaPorDia(Data vet[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (vet[j].ano > vet[j + 1].ano ||
                (vet[j].ano == vet[j + 1].ano && vet[j].mes > vet[j + 1].mes) ||
                (vet[j].ano == vet[j + 1].ano && vet[j].mes == vet[j + 1].mes && vet[j].dia > vet[j + 1].dia)) {
                swapData(&vet[j], &vet[j + 1]);
            }
        }
    }
}

/**
 * Função que ordena um vetor de estruturas Data por mês.
 *
 * @param vet Um vetor de estruturas Data.
 * @param tam O tamanho do vetor.
 */
void ordenaPorMes(Data vet[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (vet[j].ano > vet[j + 1].ano ||
                (vet[j].ano == vet[j + 1].ano &&
                 vet[j].mes > vet[j + 1].mes)) {
                swapData(&vet[j], &vet[j + 1]);
            }
        }
    }
}

/**
 * Função que ordena um vetor de estruturas Data por ano.
 *
 * @param vet Um vetor de estruturas Data.
 * @param tam O tamanho do vetor.
 */
void ordenaPorAno(Data vet[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (vet[j].ano > vet[j + 1].ano) {
                swapData(&vet[j], &vet[j + 1]);
            }
        }
    }
}

/**
 * Função que ordena um vetor de estruturas Data por ano, mês e dia.
 *
 * @param vet Um vetor de estruturas Data.
 * @param tam O tamanho do vetor.
 */
void ordena(Data vet[], int tam) {
    ordenaPorAno(vet, tam);

    int i = 0;
    while (i < tam) {
        int j = i;
        while (j < tam && vet[j].ano == vet[i].ano) {
            j++;
        }
        ordenaPorMes(&vet[i], j - i);
        i = j;
    }

    i = 0;
    while (i < tam) {
        int j = i;
        while (j < tam && vet[j].ano == vet[i].ano && vet[j].mes == vet[i].mes) {
            j++;
        }
        ordenaPorDia(&vet[i], j - i);
        i = j;
    }
}

/**
 * Função que lê os dados de uma estrutura Data a partir da entrada padrão.
 *
 * @return A estrutura Data preenchida.
 */
Data leData(void) {
    struct Data data;

    printf("Day: ");
    scanf("%d", &(data.dia));

    printf("Month: ");
    scanf("%d", &(data.mes));

    printf("Year: ");
    scanf("%d", &(data.ano));

    return data;
}

/**
 * Função que imprime as datas contidas em um vetor de estruturas Data.
 *
 * @param datas Um vetor de estruturas Data.
 * @param tam O tamanho do vetor.
 */
void imprimeDatas(Data datas[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("Dia: %d, Mês: %d, Ano: %d\n", datas[i].dia, datas[i].mes, datas[i].ano);
    }
}

Base cria_base() {
    Base base;
    base.armazenado = 0;
    return base;
}

int insere_base(Pessoa p, Base base) {
    if (base.armazenado < 100) {
        base.pessoas[base.armazenado] = p;
        base.armazenado++;
        return 1;
    }
    return 0;
}

int remove_base(int rg, Base base) {
    for (int i = 0; i < base.armazenado; i++) {
        if (base.pessoas[i].rg == rg) {
            for (int j = i; j < base.armazenado - 1; j++) {
                base.pessoas[j] = base.pessoas[j + 1];
            }
            base.armazenado--;
            return 1;
        }
    }
    return 0;
}

int buscaBinaria(Pessoa cadastro[], int tamanho, int rg) {
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (cadastro[meio].rg == rg)
            return meio; // Encontrou o RG, retorna o índice
        else if (cadastro[meio].rg < rg)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }

    return -1; // RG não encontrado
}

Pessoa lePessoa() {
    Pessoa pessoa;
    printf("Digite o RG: ");
    scanf("%d", &pessoa.rg);
    printf("Digite o CPF: ");
    scanf("%d", &pessoa.cpf);
    printf("Digite o nome: ");
    scanf("%s", pessoa.nome);
    return pessoa;
}