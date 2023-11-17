#define MAX 100

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
        printf("vetor[%d] : ", i);
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
 * Encontra o valor mínimo em um array de inteiros.
 *
 * @param v Um array de inteiros no qual o valor mínimo será encontrado.
 * @param n O número de elementos no array.
 * @return O valor mínimo no array.
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
 * Calcula a média dos elementos em um array de inteiros.
 *
 * @param v Um array de inteiros para calcular a média.
 * @param n O número de elementos no array.
 * @return A média dos elementos no array.
 */
float media(int v[], int n) {
    if (n == 1)
        return v[0];
    else
        return (v[n - 1] + media(v, n - 1) * (n - 1)) / n;
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
    int i, t1 = 0, t2 = 1, proximo;

    for (i = 1; i <= n; ++i) {
        proximo = t1 + t2;
        t1 = t2;
        t2 = proximo;
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

/**
 * Função para calcular o máximo divisor comum (MDC) de dois números inteiros não negativos.
 *
 * @param x O primeiro número
 * @param y O segundo número
 * @return O MDC de x e y
 */
int mdc(int x, int y) {
    if (y == 0)
        return x;
    else
        return mdc(y, x % y);
}

/**
 * Esta função calcula a potência de uma base dada elevada a um expoente inteiro não negativo
 * usando uma abordagem recursiva.
 *
 * @param x A base da operação de potência.
 * @param n O expoente inteiro não negativo.
 * @return O resultado de elevar a base (x) à potência do expoente (n).
 * @throws Um aviso se o expoente (n) for negativo (não há exceções em C, mas o comentário indica a condição).
 */
long potenciaRecursiva(long x, long n) {
    if (n < 0) {
        printf("Aviso: O expoente deve ser um inteiro não negativo.\n");
        return -1; // Retorna -1 para indicar um erro
    }

    if (n == 0)
        return 1;
    else
        return x * potenciaRecursiva(x, n - 1);
}

/**
 * Solução para o problema das Torres de Hanoi
 *
 * @param n O número de discos
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
 * @param n O número de elementos no vetor.
 * @param x O valor a ser buscado.
 * @return O índice do elemento no vetor, ou -1 se o elemento não for encontrado.
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
 * Busca binária em um vetor de inteiros.
 * @param v Um vetor de inteiros ordenado.
 * @param n O número de elementos no vetor.
 * @param x O valor a ser buscado.
 * @return O índice do elemento no vetor, ou -1 se o elemento não for encontrado.
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
 * Função recursiva que calcula a soma dos números de 1 até n.
 *
 * @param n O número até o qual a soma deve ser calculada.
 * @return A soma dos números de 1 até n.
 */
long f(long n) {
    if (n == 0)
        return 0;
    else
        return n + f(n - 1);
}

/**
 * Encontra todas as cidades alcançáveis a partir de uma cidade específica em uma matriz de estradas.
 *
 * @param M Matriz binária que representa a ligação entre as cidades.
 * @param n Número total de cidades na matriz.
 * @param cidadeInicial A cidade a partir da qual deseja-se encontrar as cidades alcançáveis.
 * @param visitadas Array que rastreia as cidades já visitadas durante a execução da função.
 */
void cidadesAlcancaveis(int M[][MAX], int n, int cidadeInicial, int visitadas[]) {
    // Verificações de parâmetros
    if (cidadeInicial < 0 || cidadeInicial >= n) {
        printf("Cidade inicial inválida.\n");
        return;
    }

    // Marca a cidade atual como visitada
    visitadas[cidadeInicial] = 1;

    for (int i = 0; i < n; i++) {
        // Verifica se há uma estrada da cidadeInicial para a cidade i e se a cidade i ainda não foi visitada
        if (M[cidadeInicial][i] == 1 && !visitadas[i]) {
            cidadesAlcancaveis(M, n, i, visitadas); // Chama a função recursiva para a cidade i
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