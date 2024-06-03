#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <Windows.h>
#include <locale.h>

// Estrutura para representar um nó da árvore binária de busca
struct Node {
    int key;          // Chave do nó
    struct Node *left;  // Ponteiro para o filho esquerdo
    struct Node *right; // Ponteiro para o filho direito
};

// Função para criar um novo nó
// Parâmetros: key - A chave do novo nó
// Retorno: Um ponteiro para o novo nó criado
struct Node *createNode(int key) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Erro na alocação de memória em createNode");
        exit(EXIT_FAILURE);
    }
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Função para inserir um nó na árvore binária de busca
// Parâmetros: node - Ponteiro para o nó raiz da árvore
//             key - A chave do novo nó a ser inserido
// Retorno: Ponteiro para o nó raiz da árvore
struct Node *insert(struct Node *node, int key) {
    if (node == NULL) return createNode(key);

    if (key < node->key) node->left = insert(node->left, key);
    else if (key > node->key) node->right = insert(node->right, key);
    else return node;

    return node;
}

// Função para buscar um nó na árvore binária de busca
// Parâmetros: root - Ponteiro para o nó raiz da árvore
//             key - A chave do nó a ser buscado
// Retorno: Ponteiro para o nó encontrado ou NULL se o nó não for encontrado
struct Node *search(struct Node *root, int key) {
    if (root == NULL || root->key == key) return root;

    if (root->key < key) return search(root->right, key);

    return search(root->left, key);
}

// Função para imprimir a árvore em ordem (percurso em ordem simétrica)
// Parâmetros: node - Ponteiro para o nó raiz da árvore
void inorderTraversal(struct Node *node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->key);
        inorderTraversal(node->right);
    }
}

// Função para liberar a memória alocada para a árvore
// Parâmetros: node - Ponteiro para o nó raiz da árvore
void freeTree(struct Node *node) {
    if (node != NULL) {
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
}

// Função recursiva auxiliar para converter a árvore em uma string
// Parâmetros: level - Nível atual na árvore (usado para formatação)
//             no - Ponteiro para o nó atual
//             prefixo - String de prefixo para formatação
//             isUltimoFilho - Indica se o nó atual é o último filho de seu pai
//             str - Ponteiro para a string que está sendo construída
//             tamanho - Ponteiro para o tamanho atual da string
//             tamanho_inicial - Ponteiro para o tamanho alocado para a string
void toStringRecursivo(int level, struct Node *no, char *prefixo, bool isUltimoFilho, char **str, int *tamanho,
                       size_t *tamanho_inicial) {
    if (no == NULL) return;

    size_t tamanho_necessario = *tamanho + strlen(prefixo) + 100;

    if (tamanho_necessario >= *tamanho_inicial) {
        *tamanho_inicial = tamanho_necessario * 2;
        *str = (char *) realloc(*str, *tamanho_inicial);
        if (*str == NULL) {
            perror("Erro de alocação de memória em toStringRecursivo");
            exit(EXIT_FAILURE);
        }
    }

    // Define a codificação do console para UTF-8
    SetConsoleOutputCP(CP_UTF8);

    // Adiciona a representação do nó atual à string
    if (level == 0) { // Caso especial para a raiz
        *tamanho += sprintf(*str + *tamanho, "[%d]\n", no->key);
    } else {
        *tamanho += sprintf(*str + *tamanho, "%s%s[%d]\n",
                            prefixo,
                            isUltimoFilho ? "└─" : "├─",
                            no->key);
    }

    // Define o prefixo para os filhos
    char prefixoFilho[100];
    sprintf(prefixoFilho, "%s%s", prefixo, isUltimoFilho ? "  " : "│   ");

    // Chama recursivamente para os filhos
    toStringRecursivo(level + 1, no->left, prefixoFilho, false, str, tamanho, tamanho_inicial);
    toStringRecursivo(level + 1, no->right, prefixoFilho, true, str, tamanho, tamanho_inicial);
}

// Função para converter a árvore em uma string
// Parâmetros: raiz - Ponteiro para o nó raiz da árvore
// Retorno: Uma string que representa a árvore
char *toString(struct Node *raiz) {
    if (raiz == NULL) return "{ }";

    size_t tamanho_inicial = 128;
    char *str = (char *) malloc(tamanho_inicial);
    if (str == NULL) {
        perror("Erro de alocação de memoria em toString");
        exit(EXIT_FAILURE);
    }

    int tamanho = 0;
    toStringRecursivo(0, raiz, "", true, &str, &tamanho, &tamanho_inicial);

    return str;
}

// Função para calcular a altura da árvore
// Parâmetros: no - Ponteiro para o nó raiz da árvore
// Retorno: A altura da árvore
int altura(struct Node *no) {
    if (no == NULL) return 0;

    int alturaEsquerda = altura(no->left);
    int alturaDireita = altura(no->right);
    return (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita) + 1;
}

// Função para realizar uma rotação à direita na árvore
// Parâmetros: y - Ponteiro para o nó que será rotacionado
// Retorno: Ponteiro para o novo nó raiz após a rotação
struct Node *rotacaoDireita(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    return x;
}

// Função para realizar uma rotação à esquerda na árvore
// Parâmetros: x - Ponteiro para o nó que será rotacionado
// Retorno: Ponteiro para o novo nó raiz após a rotação
struct Node *rotacaoEsquerda(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    return y;
}

// Função para balancear a árvore usando o algoritmo AVL
// Parâmetros: no - Ponteiro para o nó raiz da árvore
// Retorno: Ponteiro para o novo nó raiz após o balanceamento
struct Node *balancear(struct Node *no) {
    if (no == NULL) return NULL;

    no->left = balancear(no->left);
    no->right = balancear(no->right);

    int fatorBalanceamento = altura(no->left) - altura(no->right);

    if (fatorBalanceamento > 1) {
        if (altura(no->left->right) > altura(no->left->left))
            no->left = rotacaoEsquerda(no->left);
        return rotacaoDireita(no);
    } else if (fatorBalanceamento < -1) {
        if (altura(no->right->left) > altura(no->right->right))
            no->right = rotacaoDireita(no->right);
        return rotacaoEsquerda(no);
    }

    return no;
}

// Função principal
int main(void) {
    // Define a localidade para UTF-8
    setlocale(LC_ALL, "en_US.UTF-8");
    system("chcp 65001"); // Define a página de código do console para UTF-8

    struct Node *root = NULL; // Inicializa a árvore como vazia
    int opcao, valor, chaveBusca;
    char input[100];
    char *endptr;

    // Loop principal do menu
    do {
        printf("\n===== Menu =====\n");
        printf("1. Inserir elemento\n");
        printf("2. Buscar elemento\n");
        printf("3. Imprimir Árvore\n"); // Opção para imprimir a árvore a qualquer momento
        printf("0. Sair\n");
        printf("Escolha uma opção: ");

        // Lê a entrada do usuário de forma segura
        fgets(input, sizeof(input), stdin);
        opcao = (int) strtol(input, &endptr, 10);

        switch (opcao) {
            case 1:
                // Inserir um novo elemento na árvore
                printf("Digite o valor a ser inserido: ");
                fgets(input, sizeof(input), stdin);
                valor = (int) strtol(input, &endptr, 10);
                root = insert(root, valor);

                // Imprime a árvore antes e depois do balanceamento
                printf("Árvore antes do balanceamento:\n");
                char *representacao = toString(root);
                printf("%s\n", representacao);
                free(representacao);

                root = balancear(root);

                printf("Árvore balanceada:\n");
                char *representacaoBalanceada = toString(root);
                printf("%s\n", representacaoBalanceada);
                free(representacaoBalanceada);

                break;
            case 2:
                // Buscar um elemento na árvore
                printf("Digite o valor a ser buscado: ");
                fgets(input, sizeof(input), stdin);
                chaveBusca = (int) strtol(input, &endptr, 10);

                struct Node *result = search(root, chaveBusca);
                if (result != NULL)
                    printf("Valor %d encontrado na árvore.\n", chaveBusca);
                else
                    printf("Valor %d não encontrado na árvore.\n", chaveBusca);

                // Imprime a árvore atual
                printf("Árvore atual:\n");
                representacao = toString(root);
                printf("%s\n", representacao);
                free(representacao);
                break;
            case 3:
                // Imprimir a árvore
                printf("Árvore atual:\n");
                representacao = toString(root);
                printf("%s\n", representacao);
                free(representacao);
                break;
            case 0:
                // Sair do programa
                printf("Saindo...\n");
                break;
            default:
                // Opção inválida
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    // Libera a memória alocada para a árvore antes de sair
    freeTree(root);
    return 0;
}