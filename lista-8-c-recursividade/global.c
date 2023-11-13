/**
 * Preenche um vetor com valores fornecidos pelo usu�rio.
 *
 * Esta fun��o solicita ao usu�rio que insira valores para cada elemento do vetor.
 *
 * @param v Um array de inteiros que ser� preenchido pelo usu�rio.
 * @param n O n�mero de elementos no vetor.
 * @return A fun��o n�o retorna nenhum valor, pois o preenchimento � feito diretamente no vetor.
 */
void preencherVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Digite o elemento %d do vetor: ", i + 1);
        scanf("%d", &v[i]);
    }
}

/**
 * Calcula a soma iterativa de dois n�meros longos.
 *
 * @param a O primeiro n�mero longo a ser somado.
 * @param b O segundo n�mero longo, representando a quantidade de vezes que 'a' deve ser somado.
 * @return O resultado da soma iterativa de 'a' e 'b'.
 */
long somaIterativa(long a, long b) {
    long resultado = 0;

    for (int i = 0; i < b; i++)
        resultado += a;

    return resultado;
}

/**
 * Calcula a multiplica��o recursiva de dois n�meros longos.
 *
 * @param a O multiplicador, o primeiro n�mero longo.
 * @param b O multiplicando, o segundo n�mero longo.
 * @return O resultado da multiplica��o recursiva de 'a' e 'b'.
 */
long multiplicacaoRecursiva(long a, long b) {
    // Caso base: se b for zero, o resultado � zero
    if (b == 0)
        return 0;
    else
        return a + multiplicacaoRecursiva(a, b - 1);
}

/**
 * Encontra o valor m�ximo em um array de inteiros.
 *
 * @param v Um array de inteiros no qual o valor m�ximo ser� encontrado.
 * @param n O n�mero de elementos no array.
 * @return O valor m�ximo no array.
 */
int max(int v[], int n) {
    int x;

    // Caso base: se h� apenas um elemento no array, retorne esse elemento
    if (n == 1)
        return v[0];
    else {
        // Caso recursivo: encontre o m�ximo no subarray excluindo o �ltimo elemento
        x = max(v, n - 1);

        // Compare o m�ximo do subarray com o �ltimo elemento do array
        if (x > v[n - 1])
            return x;
        else
            return v[n - 1];
    }
}

/**
 * Encontra o valor m�nimo em um array de inteiros.
 *
 * @param v Um array de inteiros no qual o valor m�nimo ser� encontrado.
 * @param n O n�mero de elementos no array.
 * @return O valor m�nimo no array.
 */
int min(int v[], int n) {
    int x;

    // Caso base: se h� apenas um elemento no array, retorne esse elemento
    if (n == 1)
        return v[0];
    else {
        // Caso recursivo: encontre o m�nimo no subarray excluindo o �ltimo elemento
        x = min(v, n - 1);

        // Compare o m�nimo do subarray com o �ltimo elemento do array
        if (x < v[n - 1])
            return x;
        else
            return v[n - 1];
    }
}

/**
 * Calcula a m�dia dos elementos em um array de inteiros.
 *
 * @param v Um array de inteiros para calcular a m�dia.
 * @param n O n�mero de elementos no array.
 * @return A m�dia dos elementos no array.
 */
float media(int v[], int n) {
    if (n == 1)
        return v[0];  // Caso base: se h� apenas um elemento no array, retorne esse elemento
    else
        return (v[n - 1] + (n - 1) * media(v, n - 1)) / n;
}

/**
* Calcula o fatorial de um n�mero de forma iterativa.
*
* @param n O n�mero para calcular o fatorial.
* @return O fatorial de n.
*/
long fatorialIterativo(long n) {
    long resultado = 1;

    for (int i = 1; i <= n; i++)
        resultado *= i;

    return resultado;
}

/**
 * Calcula o fatorial de um n�mero de forma recursiva.
 *
 * @param n O n�mero para calcular o fatorial.
 * @return O fatorial de n.
 */
long fatorialRecursivo(long n) {
    if (n <= 1)
        return 1;
    else
        return (n * fatorialRecursivo(n - 1));
}

/**
 * Calcula o n-�simo termo da sequ�ncia de Fibonacci de forma iterativa.
 *
 * @param n O �ndice do termo desejado na sequ�ncia de Fibonacci.
 * @return O n-�simo termo da sequ�ncia de Fibonacci.
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
 * Calcula o n-�simo termo da sequ�ncia de Fibonacci de forma recursiva.
 *
 * @param n O �ndice do termo desejado na sequ�ncia de Fibonacci.
 * @return O n-�simo termo da sequ�ncia de Fibonacci.
 */
int fibonacciRecursivo(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
}

/**
 * Fun��o recursiva que realiza opera��es em uma sequ�ncia espec�fica.
 *
 * @param n O n�mero inicial da sequ�ncia.
 * @param ind O �ndice utilizado na formata��o da sa�da.
 * @return O resultado da opera��o espec�fica na sequ�ncia.
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
 * @param n O n�mero de elementos no vetor.
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
 * @param i O �ndice inicial para impress�o.
 * @param n O n�mero de elementos no vetor.
 */
void imprimeVetorIntEmOrderRecursivo(int v[], int i, int n) {
    if (i < n) {
        printf("%d ", v[i]);
        imprimeVetorIntEmOrderRecursivo(v, i + 1, n);
    }
}

/**
 * Calcula o logaritmo na base 2 de um n�mero de forma recursiva.
 *
 * @param n O n�mero para calcular o logaritmo.
 * @return O logaritmo na base 2 de n.
 */
long logaritmo(long n) {
    if (n == 1)
        return 0;
    else
        return 1 + logaritmo(n / 2);
}