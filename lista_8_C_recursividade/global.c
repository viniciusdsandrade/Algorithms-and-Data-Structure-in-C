

/* Função recursiva para calcular o fatorial de um número */
long fatr(long n) {
    long x, r;
    if (n == 1) {
        return 1;
    } else {
        x = n - 1;
        r = fatr(x);
        return n * r;
    }
}
