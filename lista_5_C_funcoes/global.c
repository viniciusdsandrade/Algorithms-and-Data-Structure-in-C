#include <stdbool.h>
#include "global.h"

int mdc(int m, int n) {
    if (n == 0) {
        return m;
    } else {
        return mdc(n, m % n);
    }
}

int fun1(int a, int b) {
    int i, p = 1;
    for (i = 1; i <= b; i++) {
        p = p * a;
    }
    return p;
}

bool amigos(int a, int i) {
    int somaDivisoresA = 0;
    int somaDivisoresB = 0;
    int j;
    for (j = 1; j < a; j++) {
        if (a % j == 0) {
            somaDivisoresA += j;
        }
    }
    for (j = 1; j < i; j++) {
        if (i % j == 0) {
            somaDivisoresB += j;
        }
    }
    return somaDivisoresA == i && somaDivisoresB == a;
}
