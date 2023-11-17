#define MAX 100

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
        printf("vetor[%d] : ", i);
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

/**
 * Encontra o valor m�nimo em um array de inteiros.
 *
 * @param v Um array de inteiros no qual o valor m�nimo ser� encontrado.
 * @param n O n�mero de elementos no array.
 * @return O valor m�nimo no array.
 */
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

/**
 * Calcula a m�dia dos elementos em um array de inteiros.
 *
 * @param v Um array de inteiros para calcular a m�dia.
 * @param n O n�mero de elementos no array.
 * @return A m�dia dos elementos no array.
 */
float media(int v[], int n) {
    if (n == 1)
        return v[0];
    else
        return (v[n - 1] + media(v, n - 1) * (n - 1)) / n;
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
    int i, t1 = 0, t2 = 1, proximo;

    for (i = 1; i <= n; ++i) {
        proximo = t1 + t2;
        t1 = t2;
        t2 = proximo;
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

/**
 * Fun��o para calcular o m�ximo divisor comum (MDC) de dois n�meros inteiros n�o negativos.
 *
 * @param x O primeiro n�mero
 * @param y O segundo n�mero
 * @return O MDC de x e y
 */
int mdc(int x, int y) {
    if (y == 0)
        return x;
    else
        return mdc(y, x % y);
}

/**
 * Esta fun��o calcula a pot�ncia de uma base dada elevada a um expoente inteiro n�o negativo
 * usando uma abordagem recursiva.
 *
 * @param x A base da opera��o de pot�ncia.
 * @param n O expoente inteiro n�o negativo.
 * @return O resultado de elevar a base (x) � pot�ncia do expoente (n).
 * @throws Um aviso se o expoente (n) for negativo (n�o h� exce��es em C, mas o coment�rio indica a condi��o).
 */
long potenciaRecursiva(long x, long n) {
    if (n < 0) {
        printf("Aviso: O expoente deve ser um inteiro n�o negativo.\n");
        return -1; // Retorna -1 para indicar um erro
    }

    if (n == 0)
        return 1;
    else
        return x * potenciaRecursiva(x, n - 1);
}

/**
 * Solu��o para o problema das Torres de Hanoi
 *
 * @param n O n�mero de discos
 * @param origem A torre de origem
 * @param destino A torre de destino
 * @param auxiliar A torre auxiliar
 */
void hanoi(int n, char origem, char destino, char auxiliar) {
    if (n == 1)
        printf("Mova o disco %c da torre %c para a torre %c\n", n, origem, destino);
    else {
        hanoi(n - 1, origem, auxiliar, destino);
        printf("Mova o disco %d da torre %c para a torre %c\n", n, origem, destino);
        hanoi(n - 1, auxiliar, destino, origem);
    }
}

/**
 * Busca sequencial em um vetor de inteiros.
 * @param v Um vetor de inteiros.
 * @param n O n�mero de elementos no vetor.
 * @param x O valor a ser buscado.
 * @return O �ndice do elemento no vetor, ou -1 se o elemento n�o for encontrado.
 */
int buscaSequencial(int v[], int n, int x) {
    if (n == 0)
        return -1;
    else if (v[n - 1] == x)
        return n - 1;
    else
        return buscaSequencial(v, n - 1, x);
}

/**
 * Busca bin�ria em um vetor de inteiros.
 * @param v Um vetor de inteiros ordenado.
 * @param n O n�mero de elementos no vetor.
 * @param x O valor a ser buscado.
 * @return O �ndice do elemento no vetor, ou -1 se o elemento n�o for encontrado.
 */
int buscaBinaria(int v[], int n, int x) {
    if (n == 0)
        return -1;
    else {
        int meio = n / 2;

        if (v[meio] == x)
            return meio;
        else if (v[meio] < x)
            return meio + buscaBinaria(v + meio + 1, n - meio - 1, x);
        else
            return buscaBinaria(v, meio, x);
    }
}

/**
 * Fun��o recursiva que calcula a soma dos n�meros de 1 at� n.
 *
 * @param n O n�mero at� o qual a soma deve ser calculada.
 * @return A soma dos n�meros de 1 at� n.
 */
long f(long n) {
    if (n == 0)
        return 0;
    else
        return n + f(n - 1);
}

/**
 * Encontra todas as cidades alcan��veis a partir de uma cidade espec�fica em uma matriz de estradas.
 *
 * @param M Matriz bin�ria que representa a liga��o entre as cidades.
 * @param n N�mero total de cidades na matriz.
 * @param cidadeInicial A cidade a partir da qual deseja-se encontrar as cidades alcan��veis.
 * @param visitadas Array que rastreia as cidades j� visitadas durante a execu��o da fun��o.
 */
void cidadesAlcancaveis(int M[][MAX], int n, int cidadeInicial, int visitadas[]) {
    // Verifica��es de par�metros
    if (cidadeInicial < 0 || cidadeInicial >= n) {
        printf("Cidade inicial inv�lida.\n");
        return;
    }

    // Marca a cidade atual como visitada
    visitadas[cidadeInicial] = 1;

    for (int i = 0; i < n; i++) {
        // Verifica se h� uma estrada da cidadeInicial para a cidade i e se a cidade i ainda n�o foi visitada
        if (M[cidadeInicial][i] == 1 && !visitadas[i]) {
            cidadesAlcancaveis(M, n, i, visitadas); // Chama a fun��o recursiva para a cidade i
        }
    }
}

int bb_rec(int v[], int ini, int fim, int chave) {

    int meio = (ini + fim) / 2;

    if (chave == v[meio])
        return meio;
    else if (ini > fim)
        return -1;
    else if (chave < v[meio])
        return bb_rec(v, ini, meio - 1, chave);
    else
        return bb_rec(v, meio + 1, fim, chave);
}