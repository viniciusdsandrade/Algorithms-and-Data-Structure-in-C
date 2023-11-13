/**
 * Preenche um vetor com valores fornecidos pelo usuário.
 *
 * Esta função solicita ao usuário que insira valores para cada elemento do vetor.
 *
 * @param v Um array de inteiros que será preenchido pelo usuário.
 * @param n O número de elementos no vetor.
 * @return A função não retorna nenhum valor, pois o preenchimento é feito diretamente no vetor.
 */
void preencherVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Digite o elemento %d do vetor: ", i + 1);
        scanf("%d", &v[i]);
    }
}

/**
 * Calcula a soma iterativa de dois números longos.
 *
 * @param a O primeiro número longo a ser somado.
 * @param b O segundo número longo, representando a quantidade de vezes que 'a' deve ser somado.
 * @return O resultado da soma iterativa de 'a' e 'b'.
 */
long somaIterativa(long a, long b) {
    long resultado = 0;

    for (int i = 0; i < b; i++)
        resultado += a;

    return resultado;
}

/**
 * Calcula a multiplicação recursiva de dois números longos.
 *
 * @param a O multiplicador, o primeiro número longo.
 * @param b O multiplicando, o segundo número longo.
 * @return O resultado da multiplicação recursiva de 'a' e 'b'.
 */
long multiplicacaoRecursiva(long a, long b) {
    // Caso base: se b for zero, o resultado é zero
    if (b == 0)
        return 0;
    else
        return a + multiplicacaoRecursiva(a, b - 1);
}

/**
 * Encontra o valor máximo em um array de inteiros.
 *
 * @param v Um array de inteiros no qual o valor máximo será encontrado.
 * @param n O número de elementos no array.
 * @return O valor máximo no array.
 */
int max(int v[], int n) {
    int x;

    // Caso base: se há apenas um elemento no array, retorne esse elemento
    if (n == 1)
        return v[0];
    else {
        // Caso recursivo: encontre o máximo no subarray excluindo o último elemento
        x = max(v, n - 1);

        // Compare o máximo do subarray com o último elemento do array
        if (x > v[n - 1])
            return x;
        else
            return v[n - 1];
    }
}

/**
 * Encontra o valor mínimo em um array de inteiros.
 *
 * @param v Um array de inteiros no qual o valor mínimo será encontrado.
 * @param n O número de elementos no array.
 * @return O valor mínimo no array.
 */
int min(int v[], int n) {
    int x;

    // Caso base: se há apenas um elemento no array, retorne esse elemento
    if (n == 1)
        return v[0];
    else {
        // Caso recursivo: encontre o mínimo no subarray excluindo o último elemento
        x = min(v, n - 1);

        // Compare o mínimo do subarray com o último elemento do array
        if (x < v[n - 1])
            return x;
        else
            return v[n - 1];
    }
}

/**
 * Calcula a média dos elementos em um array de inteiros.
 *
 * @param v Um array de inteiros para calcular a média.
 * @param n O número de elementos no array.
 * @return A média dos elementos no array.
 */
float media(int v[], int n) {
    if (n == 1)
        return v[0];  // Caso base: se há apenas um elemento no array, retorne esse elemento
    else
        return (v[n - 1] + (n - 1) * media(v, n - 1)) / n;
}

/**
* Calcula o fatorial de um número de forma iterativa.
*
* @param n O número para calcular o fatorial.
* @return O fatorial de n.
*/
long fatorialIterativo(long n) {
    long resultado = 1;

    for (int i = 1; i <= n; i++)
        resultado *= i;

    return resultado;
}

/**
 * Calcula o fatorial de um número de forma recursiva.
 *
 * @param n O número para calcular o fatorial.
 * @return O fatorial de n.
 */
long fatorialRecursivo(long n) {
    if (n <= 1)
        return 1;
    else
        return (n * fatorialRecursivo(n - 1));
}

/**
 * Calcula o n-ésimo termo da sequência de Fibonacci de forma iterativa.
 *
 * @param n O índice do termo desejado na sequência de Fibonacci.
 * @return O n-ésimo termo da sequência de Fibonacci.
 */
int fibonacciIterativo(int n) {
    int i, t1 = 0, t2 = 1, nextTerm;

    for (i = 1; i <= n; ++i) {
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }

    return t1;
}

/**
 * Calcula o n-ésimo termo da sequência de Fibonacci de forma recursiva.
 *
 * @param n O índice do termo desejado na sequência de Fibonacci.
 * @return O n-ésimo termo da sequência de Fibonacci.
 */
int fibonacciRecursivo(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
}

/**
 * Função recursiva que realiza operações em uma sequência específica.
 *
 * @param n O número inicial da sequência.
 * @param ind O índice utilizado na formatação da saída.
 * @return O resultado da operação específica na sequência.
 */
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

/**
 * Soma os elementos de um vetor de inteiros de forma recursiva.
 *
 * @param v Um vetor de inteiros.
 * @param n O número de elementos no vetor.
 * @return A soma dos elementos do vetor.
 */
int somaElementosVetorInt(int v[], int n) {
    if (n == 0)
        return v[0];
    else
        return v[n] + somaElementosVetorInt(v, n - 1);
}

/**
 * Imprime os elementos de um vetor de inteiros em ordem recursiva.
 *
 * @param v Um vetor de inteiros.
 * @param i O índice inicial para impressão.
 * @param n O número de elementos no vetor.
 */
void imprimeVetorIntEmOrderRecursivo(int v[], int i, int n) {
    if (i < n) {
        printf("%d ", v[i]);
        imprimeVetorIntEmOrderRecursivo(v, i + 1, n);
    }
}

/**
 * Calcula o logaritmo na base 2 de um número de forma recursiva.
 *
 * @param n O número para calcular o logaritmo.
 * @return O logaritmo na base 2 de n.
 */
long logaritmo(long n) {
    if (n == 1)
        return 0;
    else
        return 1 + logaritmo(n / 2);
}