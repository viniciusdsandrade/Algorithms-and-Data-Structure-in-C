#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <Windows.h>
#include <locale.h>


/**
 * @brief Estrutura que representa um nó em uma árvore binária de busca.
 */
struct Node {
    int key;          /**< A chave do nó. */
    struct Node *left;  /**< Ponteiro para o filho esquerdo do nó. */
    struct Node *right; /**< Ponteiro para o filho direito do nó. */
};

/**
 * @brief Cria um novo nó de árvore binária de busca.
 *
 * @param key A chave a ser armazenada no novo nó.
 *
 * @return Um ponteiro para o novo nó criado ou NULL se a alocação de memória falhar.
 */
struct Node *createNode(int key) {
    // Tenta alocar memória para o novo nó
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    // Verifica se a alocação de memória foi bem-sucedida
    if (newNode == NULL) {
        perror("Erro na alocação de memória em createNode");
        exit(EXIT_FAILURE);
    }
    // Inicializa os membros do novo nó
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    // Retorna o novo nó criado
    return newNode;
}

/**
 * @brief Insere um novo nó em uma árvore binária de busca.
 *
 * Esta função insere um novo nó com a chave fornecida na árvore binária de busca
 * enraizada no nó fornecido. Se a árvore estiver vazia, um novo nó será criado
 * como o nó raiz.
 *
 * @param node Um ponteiro para o nó raiz da árvore binária de busca.
 * @param key A chave do novo nó a ser inserido.
 *
 * @return Um ponteiro para o nó raiz da árvore binária de busca.
 */
struct Node *insert(struct Node *node, int key) {
    // Se a árvore estiver vazia, crie um novo nó como a raiz
    if (node == NULL) return createNode(key);


    // Caso contrário, percorra a árvore recursivamente
    if (key < node->key) node->left = insert(node->left, key);
    else if (key > node->key) node->right = insert(node->right, key);
        // Se a chave já existir na árvore, não faça nada
    else return node;


    // Retorna o nó raiz da árvore
    return node;
}

/**
 * @brief Busca um nó em uma árvore binária de busca.
 *
 * @param root Um ponteiro para o nó raiz da árvore binária de busca.
 * @param key A chave do nó a ser pesquisado.
 *
 * @return Um ponteiro para o nó que contém a chave ou NULL se a chave não for encontrada.
 */
struct Node *search(struct Node *root, int key) {
    // Se a árvore estiver vazia ou a chave for encontrada no nó atual, retorne o nó
    if (root == NULL || root->key == key) return root;


    // Se a chave for menor que a chave do nó atual, pesquise na subárvore esquerda
    if (root->key < key) return search(root->right, key);


    // Caso contrário, pesquise na subárvore direita
    return search(root->left, key);
}

/**
 * @brief Percorre uma árvore binária de busca em ordem.
 *
 * @param node Um ponteiro para o nó raiz da árvore binária de busca.
 */
void inorderTraversal(struct Node *node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->key);
        inorderTraversal(node->right);
    }
}

/**
 * @brief Libera a memória alocada para uma árvore binária de busca.
 *
 * @param node Um ponteiro para o nó raiz da árvore binária de busca.
 */
void freeTree(struct Node *node) {
    if (node != NULL) {
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
}

/**
 * @brief Função recursiva auxiliar para converter a árvore em uma string.
 *
 * @param level O nível atual na árvore.
 * @param no O nó atual a ser processado.
 * @param prefixo O prefixo a ser adicionado à string de saída para o nó atual.
 * @param isUltimoFilho Um valor booleano indicando se o nó atual é o último filho de seu pai.
 * @param str Um ponteiro para a string de saída.
 * @param tamanho Um ponteiro para o tamanho atual da string de saída.
 * @param tamanho_inicial Um ponteiro para o tamanho alocado para a string de saída.
 */
void toStringRecursivo(int level, struct Node *no, char *prefixo, bool isUltimoFilho, char **str, int *tamanho,
                       size_t *tamanho_inicial) {
    // Se o nó atual for nulo, retorne
    if (no == NULL) return;


    // Calcula o tamanho necessário para a string de saída
    size_t tamanho_necessario = *tamanho + strlen(prefixo) + 100;


    // Se o tamanho necessário for maior ou igual ao tamanho alocado, realoca a string de saída
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


    // Adiciona a representação do nó atual à string de saída
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

/**
 * @brief Converte uma árvore binária de busca em uma string.
 *
 * @param raiz Um ponteiro para o nó raiz da árvore binária de busca.
 *
 * @return Uma string que representa a árvore binária de busca.
 */
char *toString(struct Node *raiz) {
    // Se a raiz for nula, retorne "{ }"
    if (raiz == NULL) return "{ }";


    // Aloca memória para a string
    size_t tamanho_inicial = 128;
    char *str = (char *) malloc(tamanho_inicial);
    if (str == NULL) {
        perror("Erro de alocação de memoria em toString");
        exit(EXIT_FAILURE);
    }


    // Inicializa o tamanho da string
    int tamanho = 0;
    // Chama a função recursiva para converter a árvore em uma string
    toStringRecursivo(0, raiz, "", true, &str, &tamanho, &tamanho_inicial);


    // Retorna a string
    return str;
}

/**
 * @brief Calcula a altura de uma árvore binária.
 *
 * @param no Um ponteiro para o nó raiz da árvore binária.
 *
 * @return A altura da árvore binária.
 */
int altura(struct Node *no) {
    if (no == NULL) return 0;


    int alturaEsquerda = altura(no->left);
    int alturaDireita = altura(no->right);
    return (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita) + 1;
}

/**
 * @brief Executa uma rotação à direita em um nó em uma árvore de busca binária.
 *
 * @param y O nó no qual executar a rotação à direita.
 *
 * @return O novo nó raiz da subárvore após a rotação.
 */
struct Node *rotacaoDireita(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;


    // Executa a rotação
    x->right = y;
    y->left = T2;


    // Retorna a nova raiz
    return x;
}

/**
 * @brief Executa uma rotação à esquerda em um nó em uma árvore de busca binária.
 *
 * @param x O nó no qual executar a rotação à esquerda.
 *
 * @return O novo nó raiz da subárvore após a rotação.
 */
struct Node *rotacaoEsquerda(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;


    // Executa a rotação
    y->left = x;
    x->right = T2;


    // Retorna a nova raiz
    return y;
}

/**
 * @brief Equilibra uma árvore de busca binária usando o algoritmo AVL.
 *
 * @param no O nó raiz da árvore a ser balanceada.
 *
 * @return O nó raiz da árvore balanceada.
 */
struct Node *balancear(struct Node *no) {
    // Caso base: se a árvore estiver vazia, retorne
    if (no == NULL) return NULL;


    // Percorre recursivamente a árvore e balanceia as superstores
    no->left = balancear(no->left);
    no->right = balancear(no->right);


    // Calcula o fator de balanceamento do nó atual
    int fatorBalanceamento = altura(no->left) - altura(no->right);


    // Se o nó estiver desbalanceado, executa as rotações apropriadas
    if (fatorBalanceamento > 1) {
        if (altura(no->left->right) > altura(no->left->left))
            no->left = rotacaoEsquerda(no->left);
        return rotacaoDireita(no);
    } else if (fatorBalanceamento < -1) {
        if (altura(no->right->left) > altura(no->right->right))
            no->right = rotacaoDireita(no->right);
        return rotacaoEsquerda(no);
    }

    // Se o nó estiver balanceado, retorne o nó
    return no;
}

/**
 * @brief Função principal do programa.
 *
 * @return 0 se o programa for executado com sucesso.
 */
int main(void) {

    setlocale(LC_ALL, "en_US.UTF-8"); // Define a localidade para UTF-8
    system("chcp 65001"); // Define a página de código do console para UTF-8

    struct Node *root = NULL;
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
                if (result != NULL) printf("Valor %d encontrado na árvore.\n", chaveBusca);
                else printf("Valor %d não encontrado na árvore.\n", chaveBusca);

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