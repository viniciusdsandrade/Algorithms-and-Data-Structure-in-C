void f1(int v[], int n, int *a) {
    int i;
    *a = v[0];
    for (i = 1; i < n; i++) {
        if (v[i] % 2 == 0 && (*a) < v[i])
            *a = v[i];
    }
}

void menor_base_log(int n, int *b, int *k) {

}

int primo(int n, int *p1, int *p2) {

    return 0;
}

double media(double vet[], int n, int *i) {
    int j;
    double soma = 0;
    for (j = 0; j < n; j++) {
        soma += vet[j];
    }
    *i = soma / n;
    return soma / n;
}

void frequencias(int v[], int n, int *f1, int *f2) {
    int i, j, aux, cont = 0;
    for (i = 0; i < n; i++) {
        aux = v[i];
        for (j = 0; j < n; j++) {
            if (v[j] == aux)
                cont++;
        }
        if (cont > *f1) {
            *f1 = cont;
            *f2 = aux;
        }
        cont = 0;
    }
}