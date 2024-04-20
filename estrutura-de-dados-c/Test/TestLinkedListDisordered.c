#include <stdio.h>
#include <stdlib.h>
#include "../Disordered/LinkedListDisordered.c"

int main(void) {

    // Create new linked lists
    LinkedListDisordered *list_1 = createLinkedList();
    LinkedListDisordered *list_2 = createLinkedList();

    // Create nodes for list_1
    Node *node1_list_1 = createNode(strdup("Node 1"));
    Node *node2_list_1 = createNode(strdup("Node 2"));
    Node *node3_list_1 = createNode(strdup("Node 3"));

    // Link nodes to list_1
    addLast(list_1, node3_list_1);
    addLast(list_1, node2_list_1);
    addLast(list_1, node1_list_1);

    // Create nodes for list_2
    Node *node1_list_2 = createNode(strdup("Node 1"));
    Node *node2_list_2 = createNode(strdup("Node 2"));
    Node *node3_list_2 = createNode(strdup("Node 3"));

    // Link nodes to list_2
    addFirst(list_2, node1_list_2);
    addFirst(list_2, node2_list_2);
    addFirst(list_2, node3_list_2);

    printf("Elementos da lista: ");
    toString(list_1->primeiro);
    printf("Tamanho da lista: %d\n", list_1->tamanho);

    // Clone the list
    LinkedListDisordered *clone = cloneLinkedList(list_1);

    // Print the cloned list
    printf("Cloned list:        ");
    toString(clone->primeiro);
    printf("Tamanho da lista: %d\n", clone->tamanho);

    printf("Elementos da lista: ");
    toString(list_2->primeiro);
    printf("Tamanho da lista: %d\n", list_2->tamanho);

    // Quero pegar o HashCode
    printf("HashCode: %d\n", hashCode(list_1->primeiro));
    printf("HashCode: %d\n", hashCode(list_2->primeiro));

    printf("HashCode: %d\n", hashCode((Node *) list_1));
    printf("HashCode: %d\n", hashCode((Node *) list_2));

    //Quero testar o Equals
    printf("equals(list_1->primeiro, list_2->primeiro) = %d\n", equals(list_1->primeiro, list_2->primeiro));

    // Quero testar o getElemento()
    printf("getElemento(list_1->primeiro) = %s\n", (char *) getElemento(list_1->primeiro));
    printf("getElemento(list_2->primeiro) = %s\n", (char *) getElemento(list_2->primeiro));

    // Quero testar o getElementoProximo()
    printf("getElementoProximo(list_1->primeiro) = %s\n", (char *) getProximo(list_1->primeiro));
    printf("getElementoProximo(list_2->primeiro) = %s\n", (char *) getProximo(list_2->primeiro));

    // Free memory
    free(node1_list_1);
    free(node2_list_1);
    free(node3_list_1);
    free(list_1);
    free(clone);

    free(node1_list_2);
    free(node2_list_2);
    free(node3_list_2);
    free(list_2);

    return 0;
}
