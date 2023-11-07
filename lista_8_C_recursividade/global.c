

/* Função recursiva para calcular o fatorial de um número */
long fatr(long n) {
    if (n <= 1)
        return 1;
    else
        return (n * fatr(n - 1));
}

/* Função com iterações 'for' para calcular o fatorial de um número */
long fat(long n) {
    long r = 1;

    for (int i = 1; i <= n; i++)
        r *= i;

    return r;
}
int somaElementosVetorInt(int v[], int n) {
    if (n == 0) {
        return v[0];
    } else {
        return v[n] + somaElementosVetorInt(v, n - 1);
    }
}