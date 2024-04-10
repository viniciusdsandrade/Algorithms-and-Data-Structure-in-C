#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    void *elemento;
    struct Node *proximo;
} Node;

typedef struct LinkedListDisordered {
    Node *primeiro;
    int tamanho;
} LinkedListDisordered;

Node *createNode(void *elemento) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->elemento = elemento;
    newNode->proximo = NULL;
    return newNode;
}

LinkedListDisordered *createLinkedList() {
    LinkedListDisordered *newLinkedList = (LinkedListDisordered *) malloc(sizeof(LinkedListDisordered));
    newLinkedList->primeiro = NULL;
    newLinkedList->tamanho = 0;
    return newLinkedList;
}

void addFirst(LinkedListDisordered *list, Node *node) {

    if (node == NULL) {
        printf("Memory allocation failed. Unable to add new node.\n");
        return;
    }

    node->proximo = list->primeiro;
    list->primeiro = node;
    list->tamanho++;
}

void addLast(LinkedListDisordered *list, Node *node) {
    // Check if memory was successfully allocated for the new node
    if (node == NULL) {
        printf("Memory allocation failed. Unable to add new node.\n");
        return;
    }

    if (list->primeiro == NULL) {
        list->primeiro = node;
        list->tamanho++;
        return;
    }

    Node *current = list->primeiro;
    while (current->proximo != NULL)
        current = current->proximo;

    current->proximo = node;

    list->tamanho++;
}

void *getElemento(Node *node) {
    return node->elemento;
}

void *getProximo(Node *node) {
    if (node == NULL || node->proximo == NULL) return NULL;

    return node->proximo->elemento;
}

LinkedListDisordered *cloneLinkedList(LinkedListDisordered *list) {
    if (list == NULL) {
        printf("List cannot be null\n");
        return NULL;
    }

    LinkedListDisordered *cloneList = createLinkedList();
    Node *current = list->primeiro;

    while (current != NULL) {
        Node *cloneNode = createNode(strdup(current->elemento));
        addLast(cloneList, cloneNode);
        current = current->proximo;
    }

    return cloneList;
}

bool equals(Node *this, Node *obj) {
    if (this == obj) return true;
    if (obj == NULL) return false;
    if (strcmp(this->elemento, obj->elemento) == 0) return true;
    return false;
}

int hashCode(Node *this) {
    const int prime = 31;
    int hash = 1;

    hash *= prime + ((this->elemento == NULL) ? 0 : strlen(this->elemento));

    if (hash < 0) hash = -hash;

    return hash;
}

void toString(Node *this) {
    printf("[");
    while (this != NULL) {
        printf("%s", (char *) this->elemento);
        if (this->proximo != NULL)
            printf(" -> ");
        this = this->proximo;
    }
    printf("]\n");
}
