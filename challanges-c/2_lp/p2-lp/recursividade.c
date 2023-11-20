#include <stdio.h>

long fatorialRecursivo(long n);
int fibonacciRecursivo(int n);
long superFatorialRecursivo(long n);
long multiplicacaoRecursiva(long a, long b);
int somaElementosVetorInt(int v[], int n);
long potenciaRecursiva(long x, long n);
int bb_rec(int v[], int ini, int fim, int chave);
int buscaSequencial(int v[], int n, int x);
void imprimirPilha(int v[], int n);
void imprimeVetorIntEmOrderRecursivo(int v[], int i, int n);

void imprimeVetorIntEmOrderRecursivo(int v[], int i, int n) {
    if (i < n) {
        printf("%d ", v[i]);
        imprimeVetorIntEmOrderRecursivo(v, i + 1, n);
    }
}
void imprimirPilha(int v[], int n) {
    printf("Pilha de execucao: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}
int buscaSequencial(int v[], int n, int x) {
    imprimirPilha(v, n); // Imprime a pilha de execução

    // Verifica se o vetor está vazio (caso base)
    if (n == 0) {
        printf("Caso base: Vetor esta vazio. Elemento nao encontrado.\n");
        return -1; // Retorna -1 indicando que o elemento não foi encontrado
    }
        // Verifica se o último elemento do vetor é igual ao elemento procurado
    else if (v[n - 1] == x) {
        printf("Elemento %d encontrado na posicao %d.\n", x, n - 1);
        return n - 1; // Retorna a posição do elemento no vetor
    } else {
        // Se o último elemento não for igual, faz uma chamada recursiva
        // excluindo o último elemento do vetor (n - 1)
        printf("Chamando buscaSequencial para procurar %d no restante do vetor.\n", x);
        return buscaSequencial(v, n - 1, x);
    }
}
int bb_rec(int v[], int ini, int fim, int chave) {
    int meio = (ini + fim) / 2;

    printf("Chamando bb_rec(v, %d, %d, %d)\n", ini, fim, chave);

    if (chave == v[meio]) {
        printf("Chave encontrada em bb_rec(v, %d, %d, %d) - Posicao: %d\n", ini, fim, chave, meio);
        return meio;
    } else if (ini > fim) {
        printf("Intervalo invalido em bb_rec(v, %d, %d, %d)\n", ini, fim, chave);
        return -1;
    } else if (chave < v[meio]) {
        printf("Chamando bb_rec(v, %d, %d, %d)\n", ini, meio - 1, chave);
        return bb_rec(v, ini, meio - 1, chave);
    } else {
        printf("Chamando bb_rec(v, %d, %d, %d)\n", meio + 1, fim, chave);
        return bb_rec(v, meio + 1, fim, chave);
    }
}
long potenciaRecursiva(long x, long n) {
    if (n < 0) {
        printf("Aviso: O expoente deve ser um inteiro não negativo.\n");
        return -1; // Retorna -1 para indicar um erro
    }

    if (n == 0) {
        printf("Base da recursao alcancada: potenciaRecursiva(%ld, 0) = 1\n", x);
        return 1;
    } else {
        printf("Chamando potenciaRecursiva(%ld, %ld - 1)\n", x, n);
        long resultado = x * potenciaRecursiva(x, n - 1);
        printf("Resultado de potenciaRecursiva(%ld, %ld) = %ld * potenciaRecursiva(%ld, %ld - 1) = %ld\n", x, n, x, x,
               n, resultado);
        return resultado;
    }
}
int somaElementosVetorInt(int v[], int n) {
    if (n == 0) {
        printf("Base da recursão alcançada: somaElementosVetorInt(v, 0) = %d\n", v[0]);
        return v[0];
    } else {
        printf("Chamando somaElementosVetorInt(v, %d - 1)\n", n);
        int resultado = v[n] + somaElementosVetorInt(v, n - 1);
        printf("Resultado de somaElementosVetorInt(v, %d) = v[%d] + somaElementosVetorInt(v, %d - 1) = %d + %d = %d\n",
               n, n, n, v[n], resultado, v[n] + resultado);
        return resultado;
    }
}
long multiplicacaoRecursiva(long a, long b) {
    if (b == 0) {
        printf("Base da recursao alcancada: multiplicacaoRecursiva(%ld, 0) = 0\n", a);
        return 0;
    } else {
        printf("Chamando multiplicacaoRecursiva(%ld, %ld - 1)\n", a, b);
        int resultado = a + multiplicacaoRecursiva(a, b - 1);
        printf("Resultado de multiplicacaoRecursiva(%ld, %ld) = %ld + multiplicacaoRecursiva(%ld, %ld - 1) = %d\n", a,
               b, a, a, b, resultado);
        return resultado;
    }
}
long superFatorialRecursivo(long n) {
    if (n == 0 || n == 1) {
        printf("Base da recursão alcançada: superFatorialRecursivo(1) = 1\n");
        return 1;
    } else {
        printf("Chamando superFatorialRecursivo(%ld) * superFatorialRecursivo(%ld - 1)\n", n, n);
        long resultado = fatorialRecursivo(n) * superFatorialRecursivo(n - 1);
        printf("Resultado de superFatorialRecursivo(%ld) = %ld * superFatorialRecursivo(%ld - 1) = %ld\n", n,
               fatorialRecursivo(n), n, resultado);
        return resultado;
    }
}
long fatorialRecursivo(long n) {
    if (n == 0 || n == 1) {
        printf("Base da recursao alcancada: fatorialRecursivo(1) = 1\n");
        return 1;
    } else {
        printf("Chamando fatorialRecursivo(%ld)\n", n - 1);
        long resultado = n * fatorialRecursivo(n - 1);
        printf("Resultado de fatorial(%ld) = %ld * fatorialRecursivo(%ld - 1) = %ld\n", n, n, n, resultado);
        return resultado;
    }
}
int fibonacciRecursivo(int n) {
    if (n <= 1) {
        printf("Base da recursao alcancada: fibonacci(%d) = %d\n", n, n);
        return n;
    } else {
        printf("Chamando fibonacciRecursivo(%d) + fibonacciRecursivo(%d)\n", n - 1, n - 2);
        int resultado = fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
        printf("Resultado de fibonacciRecursivo(%d) + fibonacciRecursivo(%d) = %d\n", n - 1, n - 2, resultado);
        return resultado;
    }
}

int main(void) {

    printf("Imprime vetor de inteiros em ordem recursiva\n");
    int v3[] = {1, 2, 3, 4, 5};
    int tam3 = sizeof v3 / sizeof v3[0];
    imprimeVetorIntEmOrderRecursivo(v3, 0, tam3);
    putchar('\n');

    printf("===========================================================================================\n");

    int v2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22};
    int tam2 = sizeof v2 / sizeof v2[0];
    int chave2 = 12;
    int resultado7 = buscaSequencial(v2, tam2, chave2);
    printf("Busca sequencial\n");
    printf("buscaSequencial(v, 0, 7, 5) = %d\n", resultado7);

    printf("===========================================================================================\n");

    printf("Busca binaria recursiva\n");
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21};
    int tam = sizeof v / sizeof v[0];
    int chave = 1;
    int resultado1 = bb_rec(v, 0, tam, chave);
    printf("bb_rec(v, 0, 7, 5) = %d\n", resultado1);

    printf("===========================================================================================\n");

    printf("Potencia de : ");
    long x, n;
    scanf("%ld %ld", &x, &n);
    long resultado5 = potenciaRecursiva(x, n);
    printf("potenciaRecursiva(%ld, %ld) = %ld\n", x, n, resultado5);

    printf("===========================================================================================\n");

    printf("Multiplicacao de : ");
    long a, b;
    scanf("%ld %ld", &a, &b);
    long resultado4 = multiplicacaoRecursiva(a, b);
    printf("multiplicacaoRecursiva(%ld, %ld) = %ld\n", a, b, resultado4);

    printf("===========================================================================================\n");

    printf("Super Fatorial de : ");
    long n3;
    scanf("%ld", &n3);
    long resultado3 = superFatorialRecursivo(n3);
    printf("superFatorialRecursivo(%ld) = %ld\n", n3, resultado3);

    printf("===========================================================================================\n");

    printf("Fatorial de : ");
    scanf("%ld", &n);
    long resultado6 = fatorialRecursivo(n);
    printf("%ld! = %ld\n", n, resultado6);

    printf("===========================================================================================\n");

    printf("Fibonacci de : ");
    int n2;
    scanf("%d", &n2);
    int resultado2 = fibonacciRecursivo(n2);
    printf("fibonacciRecursivo(%d) = %d\n", n2, resultado2);

    return 0;
}