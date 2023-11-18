/*
 * 01 - Considere o tipo Cell definido abaixo
 *
 * typedef struct cell {
 *  char car;
 *  int peso;
 *  } Cell;
 *
 *  Dado um vetor vet de n > 0 elementos do tipo Cell, uma sequência de dois ou mais elementos
 *  consecutivos no vetor tais que o valor em seus campos car são iguais é chamada de 'faixa'.
 *  Por exemplo, se os valores dos campos car de vet formam a sequência "yyzzzya", existem duas faixas no vetor: "yy"
 *  e "zzz".
 *
 *  Escreva uma função que receba, como entrada, um vetor de n > 0 elementos do tipo Cell e devolva como saída, a soma dos pesos de todos os elementos do vetor que pertencem a faixas.
 *  Por exemplo, para a sequência "yyzzzya", se os pesos destes elementos são 10,2,5,4,5,4,3, a sua função deve devolver o valor 26.
 */

#include <stdio.h>

typedef struct cell {
    char car;
    int peso;
} Cell;

int somaFaixa(Cell *vet, int n) {
    int sum = 0;
    int inFaixa = 0;

    for (int i = 0; i < n - 1; i++) {
        if (vet[i].car == vet[i + 1].car) {
            if (!inFaixa) {
                sum += vet[i].peso;
                inFaixa = 1;
            }
            sum += vet[i + 1].peso;
        } else {
            inFaixa = 0;
        }
    }
    return sum;
}

int main(void) {
    Cell vet[] = {
            {'y', 10},
            {'y', 02},
            {'z', 05},
            {'z', 04},
            {'z', 05},
            {'y', 04},
            {'a', 03}
    };
    printf("%d", somaFaixa(vet, 7));
    return 0;
}