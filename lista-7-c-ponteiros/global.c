void f1(const int v[], int n, int *a) {
    int i;
    *a = v[0];
    for (i = 1; i < n; i++) {
        if (v[i] % 2 == 0 && (*a) < v[i])
            *a = v[i];
    }
}

void menor_base_log(int n, int *b, int *k) {
    int i = 0;
    while (n > 1) {
        n /= 2;
        i++;
    }
    *b = 2;
    *k = i;
}

int primo(int n, int *p1, int *p2) {

    return 0;
}

double media(const double vet[], int n, int *i) {
    int j;
    double soma = 0;
    for (j = 0; j < n; j++) {
        soma += vet[j];
    }
    *i = soma / n;
    return soma / n;
}

void frequencias(const int v[], int n, int *f1, int *f2) {
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

void swap(int *a, int *b) {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void maxAndMin(const int vet[], int tam, int *min, int *max) {
    int i;
    *max = vet[0];
    *min = vet[0];

    for (i = 1; i < tam; i++) {
        if (vet[i] > *max)
            *max = vet[i];
        if (vet[i] < *min)
            *min = vet[i];
    }
}

void zeraVet(int vet[], int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        vet[i] = 0;
    }
}

void strcat_custom(char *s1, char *s2, char *s3) {
    strcpy(s3, s1);
    strcat(s3, s2);
}

void strcat_custom2(const char *s1, const char *s2, char *s3) {
    int i, j;
    for (i = 0; s1[i] != '\0'; i++) {
        s3[i] = s1[i];
    }
    for (j = 0; s2[j] != '\0'; j++) {
        s3[i + j] = s2[j];
    }
    s3[i + j] = '\0';
}