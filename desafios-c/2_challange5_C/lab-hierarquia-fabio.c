/* Nome: Fabio Luis Ortolan
 * RA: 2760482311006
 *
 * Esta tarefa tem como objetivo exercitar o processamento de matrizes,
 * alocação dinâmica e ordenação.
 *
 * A matriz de entrada representa a hierarquia entre os funcionários. Seja i o
 * indice das linhas e j os elementos das colunas, ainda temos que i e j
 * começam do zero. As colunas com um da i-éssima linha mostram quais
 * funcionarios são subordinados ao funcionario i.
 *
 * Vamos a um exemplo:
 * 0 1 1 0 0
 * 0 0 0 1 1
 * 0 0 0 0 0
 * 0 0 0 0 0
 * 0 0 0 0 0
 *
 * Este exemplo mostra que os funcionários 1 e 2 são subordinados ao funcionário 0,
 * e os funcionários 3 e 4 são subordinados ao funcionário 1. Assim, podemos montar
 * uma árvore hierárquica entre os funcionários.
 *
 * Ainda temos que, por definição, o funcionário 0 não é subordinado a nenhum
 * outro funcionário.
 *
 * Entrada:
 * A entrada é composta por 3 elementos:
 *
 * 5 0 <- O tamanho da matriz e de qual funcionario se quer a hierarquia.
 * 0 1 1 0 0 <- Matriz das relações.
 * 0 0 0 1 1
 * 0 0 0 0 0
 * 0 0 0 0 0
 * 0 0 0 0 0
 *
 * Saída:
 * A saída é composta por:
 *
 * 0 1 2 3 4 <- O funcionário escolhido e os seus subordinados diretos e
 *              indiretos em ordem crescente.
 *
 * Funções:
 * - traverseWorkers: Função recursiva que percorre a lista de funcionários e
 * escreve a hierarquia na lista de subordinados.
 *
 * - printList: Função que imprime na tela uma lista.
 *
 * - freeList: Função que libera os ponteiros de uma lista.
 *
 * A ideia para resolver este exercício é criar um vetor de funcionários aonde
 * guardaremos a lista de seus subordinados diretos.
 *
 * Depois de preenchido este vetor criamos uma lista para guardar os
 * subordinados diretos e indiretos do funcionário escolhido e guardaremos seus
 * subordinados em ordem crescente.
 *
 * Depois disto percorremos o vetor de funcionarios usando uma função
 * recursiva que entra na entrada do vetor do funcionario k e percorremos a
 * lista de seus subordinados adicionando, já em ordem crescente, na lista de
 * subordinados diretos e indiretos. Fazemos isto até exaurir todos os indices
 * e finalmente imprimimos a lista de subordinados diretos e indiretos como
 * pedido.
 */
#include <stdio.h>
#include <stdlib.h>

/* Para resolver o ultimo lab. decidi usar listas encadeadas que é uma boa
 * estrutura para guardar vetores sem um tamanho definido. As restrições são
 * bem claras (de 3 a 30 entradas), mas cada funcionario tem um tamanho varivel
 * de relações. Não é nescessário usar listas encadeadas para resolver este
 * lab. Tambem estou fazendo com listas encadeada como um pequeno desafio
 * pessoal.
 */

// Criando a estrutura de nós para a listas encadeadas.
typedef struct Node {
    int value;
    struct Node *next;
} Node;

// Declaração dos prototipos.
void transverseWorkers(int k, Node workers[], Node subs[]);
void printList(Node *list);
void freeList(Node *list);

int main() {
    // Variáveis do problema.
    int n, k;

    // Variáveis auxiliares.
    int i, j, d;

    /* Lendo as variáveis principais
     * n -> tamanho da matriz
     * k -> funcionario desejado
     */
    scanf("%d %d\n", &n, &k);

    /* Criamos a lista de relações. Como explicado acima ele vai guardar quem é
     * subordinado ao i-éssimo funcionário.
     */
    Node *workers = malloc(n*sizeof(Node));

    for (i = 0; i < n; i++) {
        // Inicialização de cada trabalhador
        workers[i].value = 0;
        workers[i].next = NULL;

        // Ponteiro auxiliar
        Node *worker;
        worker = &workers[i];

        // Lendo a matriz
        for (j = 0; j < n; j++) {
            scanf("%d ", &d);

            // Se d == 1 então temos um relação de subordinação de j com i.
            if (d) {

                // Criando e inicializando nó.
                Node *new = malloc(sizeof(Node));

                new->value = j;
                new->next = NULL;

                // Colocando o nó na lista
                worker->next = new;
                worker = new;
            }
        }
    }

    // Inicialização do nó que guarda os subordinados diretros e indiretos.
    Node *subs = malloc(sizeof(Node));
    subs->value = 0;
    subs->next = NULL;

    // Executando a função recursiva
    transverseWorkers(k, workers, subs);

    /* Usarmos a raiz da lista para colocar o k para que possamos imprimir a
     * saida desejada de forma mais simples.
     */
    subs->value = k;

    // Imprime a saida
    printList(subs);

    // Finalizamos librando toda a memoria alocada.
    for (i = 0; i < n; i++) {
        if (workers[i].next) {
            freeList(workers[i].next);
        }
    }
    free(workers);
    freeList(subs);

    return 0;
}

void printList(Node *list) {
    while (list) {
        printf("%d ", list->value);
        list = list->next;
    }
    printf("\n");
}

void freeList(Node *list) {
    if (list->next) {
        freeList(list->next);
    }
    free(list);
}

void transverseWorkers(int k, Node workers[], Node subs[]) {
    // Nó auxiliar para percorrer a lista de subordinados de um funcionário.
    Node *worker;
    worker = workers[k].next;

    while (worker) {
        // Criando e inicializando nó.
        Node *new = malloc(sizeof(Node));
        new->value = worker->value;

        /* Nó auxiliar para percorrer a lista de subordinados diretos e
         * indiretos do funcionário pedido.
         */
        Node *sub;
        sub = subs;

        /* Percorre a lista até o fim ou até encontrar uma posição
         * que tem valor inferior a que temos atualmente.
         */
        while (sub->next && sub->next->value < new->value) {
            sub = sub->next;
        }

        // Adicionando o nó na lista.
        new->next = sub->next;
        sub->next = new;

        // Agora percorremos o funcionário subordinado.
        transverseWorkers(worker->value, workers, subs);

        // Proximo funcionário
        worker = worker->next;
    }
}
