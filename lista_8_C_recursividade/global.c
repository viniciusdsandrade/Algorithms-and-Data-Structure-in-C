/*Escreva um algoritmo iterativo em C para avaliar a * b usando a adição, onde a e b são
inteiros não negativos.*/
long somaIterativa(long a, long b) {
    long r = 0;

    for (int i = 0; i < b; i++)
        r += a;

    return r;
}

/*
Escreva uma definição recursiva para o cálculo de a * b e em seguida escreva um algoritmo
recursivo para o calculo de a* b, onde a e b são inteiros não-negativos.
 */

long multiplicacaoRecursiva(long a, long b) {
    if (b == 0)
        return 0;
    else
        return a + multiplicacaoRecursiva(a, b - 1);
}

/*3. Faça uma função recursiva em C que calcula o elemento máximo em um vetor.*/

int max(int v[], int n) {
    int x;
    if (n == 1)
        return v[0];
    else {
        x = max(v, n - 1);
        if (x > v[n - 1])
            return x;
        else
            return v[n - 1];
    }
}

/*4. Faça uma função recursiva em C que calcula o elemento mínimo em um vetor.*/
int min(int v[], int n) {
    int x;
    if (n == 1)
        return v[0];
    else {
        x = min(v, n - 1);
        if (x < v[n - 1])
            return x;
        else
            return v[n - 1];
    }
}

/*5. Faça uma função recursiva em C que calcula a média dos elementos de um vetor.*/
float media(int v[], int n) {
    if (n == 1)
        return v[0];
    else
        return (v[n - 1] + media(v, n - 1)) / n;
}

/* Função com iterações 'for' para calcular o fatorial de um número */
long fatorialIterativo(long n) {
    long r = 1;

    for (int i = 1; i <= n; i++)
        r *= i;

    return r;
}

/* Função recursiva para calcular o fatorial de um número */
long fatorialRecursivo(long n) {
    if (n <= 1)
        return 1;
    else
        return (n * fatorialRecursivo(n - 1));
}

int fibonacciIterativo(int n) {
    int i, t1 = 0, t2 = 1, nextTerm;

    for (i = 1; i <= n; ++i) {
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    return t1;
}

int fibonacciRecursivo(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
}

int ff(int n, int ind) {
    int i;
    for (i = 0; i < ind; i++)
        printf(" ");
    printf("ff (%d, %d) \n", n, ind);
    if (n == 1)
        return 1;
    if (n % 2 == 0)
        return ff(n / 2, ind + 1);
    return ff((n - 1) / 2, ind + 1) + ff((n + 1) / 2, ind + 1);
}

int somaElementosVetorInt(int v[], int n) {
    if (n == 0) {
        return v[0];
    } else {
        return v[n] + somaElementosVetorInt(v, n - 1);
    }
}

void imprimeVetorIntEmOrderRecursivo(int v[], int i, int n) {
    if (i < n) {
        printf("%d ", v[i]);
        imprimeVetorIntEmOrderRecursivo(v, i + 1, n);
    }
}

/*9. Escreva uma função recursiva que calcule blg nc, ou seja, o piso do logaritmo de n na base
2.*/

long logaritmo(long n) {
    if (n == 1)
        return 0;
    else
        return 1 + logaritmo(n / 2);
}

