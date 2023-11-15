#define MAX 100000
#include <string.h>

/**
 * Encontra o maior n�mero par no vetor e atribui o valor a *a.
 *
 * @param v Um vetor de inteiros.
 * @param n O n�mero de elementos no vetor.
 * @param a Ponteiro para armazenar o maior n�mero par encontrado.
 */
void f1(const int v[], int n, int *a) {
    int i;
    *a = v[0];
    for (i = 1; i < n; i++) {
        if (v[i] % 2 == 0 && (*a) < v[i])
            *a = v[i];
    }
}

/**
 * Calcula a menor base de logaritmo inteiro e atribui os valores a *b e *k.
 *
 * @param n O n�mero para calcular o logaritmo.
 * @param b Ponteiro para armazenar a base do logaritmo.
 * @param k Ponteiro para armazenar o valor do logaritmo.
 */
void menor_base_log(int n, int *b, int *k) {
    int i = 0;
    while (n > 1) {
        n /= 2;
        i++;
    }
    *b = 2;
    *k = i;
}

/**
 * Verifica se um n�mero � primo.
 *
 * @param num O n�mero a ser verificado.
 * @return 1 se o n�mero � primo, 0 caso contr�rio.
 */
int ehPrimo(int num) {
    if (num <= 1) return 0;
    if (num <= 3) return 1;

    if (num % 2 == 0 || num % 3 == 0) return 0;

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    }

    return 1;
}

/**
 * Encontra o maior primo menor que n e o menor primo maior que n.
 *
 * @param n O n�mero de refer�ncia.
 * @param p1 Ponteiro para armazenar o maior primo menor que n.
 * @param p2 Ponteiro para armazenar o menor primo maior que n.
 * @return 0 se a fun��o for conclu�da com sucesso.
 */
int primo(int n, int *p1, int *p2) {
    int i, j;

    for (i = n - 1; i > 1; i--) {
        if (ehPrimo(i)) {
            *p1 = i;
            break;
        }
    }

    for (j = n + 1; ; j++) {
        if (ehPrimo(j)) {
            *p2 = j;
            break;
        }
    }

    return 0;
}

/**
 * Calcula a m�dia dos elementos em um vetor e atribui o resultado a *i.
 *
 * @param vet Um vetor de n�meros double.
 * @param n O n�mero de elementos no vetor.
 * @param i Ponteiro para armazenar a m�dia dos elementos.
 * @return A m�dia dos elementos no vetor.
 */
double media(const double vet[], int n, int *i) {
    int j;
    double soma = 0;
    for (j = 0; j < n; j++) {
        soma += vet[j];
    }
    *i = soma / n;
    return soma / n;
}


/**
 * Calcula as frequ�ncias dos elementos em um vetor e encontra o elemento de menor e maior frequ�ncia.
 *
 * @param v Um vetor de inteiros.
 * @param n O n�mero de elementos no vetor.
 * @param f1 Ponteiro para armazenar o elemento de menor frequ�ncia.
 * @param f2 Ponteiro para armazenar o elemento de maior frequ�ncia.
 */
void frequencias(int v[], int n, int *f1, int *f2) {
    if (n <= 0) {
        printf("Vetor inv�lido.\n");
        return;
    }

    int freq[MAX] = {0};
    int menorFreqElemento = v[0];
    int maiorFreqElemento = v[0];
    int menorFrequencia = n;
    int maiorFrequencia = 0;

    // Calcula as frequ�ncias
    for (int i = 0; i < n; i++) {
        freq[v[i]]++;
    }

    // Encontra os elementos de menor e maior frequ�ncia
    for (int i = 0; i < n; i++) {
        if (freq[v[i]] < menorFrequencia) {
            menorFrequencia = freq[v[i]];
            menorFreqElemento = v[i];
        }
        if (freq[v[i]] > maiorFrequencia) {
            maiorFrequencia = freq[v[i]];
            maiorFreqElemento = v[i];
        }
    }

    // Atribui os resultados aos ponteiros
    *f1 = menorFreqElemento;
    *f2 = maiorFreqElemento;
}

/**
 * Troca os valores de duas vari�veis inteiras.
 *
 * @param a Ponteiro para a primeira vari�vel.
 * @param b Ponteiro para a segunda vari�vel.
 */
void swap(int *a, int *b) {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

/**
 * Encontra o valor m�nimo e m�ximo em um vetor de inteiros.
 *
 * @param vet Um vetor de inteiros.
 * @param tam O n�mero de elementos no vetor.
 * @param min Ponteiro para armazenar o valor m�nimo.
 * @param max Ponteiro para armazenar o valor m�ximo.
 */
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

/**
 * Zera todos os elementos de um vetor de inteiros.
 *
 * @param vet Um vetor de inteiros.
 * @param tam O n�mero de elementos no vetor.
 */
void zeraVet(int vet[], int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        vet[i] = 0;
    }
}
/**
 * Concatena duas strings e armazena o resultado em uma terceira string.
 *
 * @param s1 Uma string de origem.
 * @param s2 Outra string a ser concatenada.
 * @param s3 Ponteiro para a string resultante. Deve ser grande o suficiente para armazenar s1 e s2.
 *
 * @note A fun��o utiliza a fun��o strcpy e strcat da biblioteca string.h para realizar a concatena��o.
 *       Certifique-se de que a string de destino (s3) tenha tamanho suficiente para armazenar ambas as strings.
 */
void strcat_custom(char *s1, char *s2, char *s3) {
    strcpy(s3, s1);
    strcat(s3, s2);
}

/**
 * Concatena duas strings e armazena o resultado em uma terceira string.
 *
 * @param s1 Uma string de origem (pode ser constante).
 * @param s2 Outra string a ser concatenada.
 * @param s3 Ponteiro para a string resultante. Deve ser grande o suficiente para armazenar s1 e s2.
 *
 * @note Esta vers�o da fun��o � projetada para aceitar uma string de origem constante (const char *s1),
 *       permitindo a concatena��o com strings literais.
 *       A fun��o utiliza loops manuais para realizar a concatena��o sem depender de fun��es da biblioteca string.h.
 *       Certifique-se de que a string de destino (s3) tenha tamanho suficiente para armazenar ambas as strings.
 */
void strcat_custom2(const char *s1, const char *s2, char *s3) {
    int i, j;

    // Copia os caracteres de s1 para s3
    for (i = 0; s1[i] != '\0'; i++) {
        s3[i] = s1[i];
    }

    // Concatena os caracteres de s2 em s3
    for (j = 0; s2[j] != '\0'; j++) {
        s3[i + j] = s2[j];
    }

    // Adiciona o caractere nulo ao final da string resultante
    s3[i + j] = '\0';
}


/**
 * Imprime um vetor de n�meros double formatado entre colchetes com v�rgulas.
 *
 * @param v Um vetor de n�meros double.
 * @param n O n�mero de elementos no vetor.
 */
void imprimeVetorDouble(double v[], int n) {
    int i;
    printf("[");
    for (i = 0; i < n; i++) {
        if (i == n - 1)
            printf("%.2lf]", v[i]);
        else
            printf("%.2lf , ", v[i]);
    }
    printf("\n");
}