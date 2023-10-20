/*
 * 02 - Implemente uma função que cria dinamicamente uma nova string com n "cópias" da
 * string original, separadas por espaço,e xceto a última ocorrência. Utilize o protótipo abaixo
 *
 * char *repete(char *string, int n);
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *repete(char *string, int n) {
    if (n <= 0) {
        char *result = (char *) malloc(1);
        result[0] = '\0';
        return result;
    }
    size_t tamS = strlen(string);
    size_t tamR = tamS * n + (n - 1);
    char *result = malloc((tamR + 1) * sizeof(char));

    strcpy(result, string);
    for (int i = 1; i < n; i++) {
        strcat(result, " ");
        strcat(result, string);
    }
    return result;
}

char *repete2(const char *string, int n) {

    int posR = 0;
    int tamS;

    if (n <= 0) {
        char *result = (char *) malloc(1);
        result[0] = '\0';
        return result;
    }

    for (tamS = 0; string[tamS] != '\0'; tamS++); // Calcula o tamanho da string

    int tamR = tamS * n + (n - 1); // Calcula o tamanho da string resultante
    char *result = (char *) malloc((tamR + 1) * sizeof(char)); // Aloca a string resultante

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < tamS; posR++, j++)
            result[posR] = string[j];

        if (i < n - 1) {
            result[posR] = ' ';
            posR++;
        }
    }

    result[posR] = '\0';
    return result;
}

int main(void) {
    char *string = "Fatec";
    int n = 3;
    char *nova = repete(string, n);
    char *nova2 = repete2(string, n);
    printf("%s", nova);
    printf("\n%s", nova2);
    free(nova);
    return 0;
}