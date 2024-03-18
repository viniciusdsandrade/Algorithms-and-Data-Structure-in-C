#include <math.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>

typedef struct Cell {
    char car;
    int peso;
} Cell;

int *initVet(int *size, int *maxSize) {
    int *v = malloc(*maxSize * sizeof(int));
    *size = 0;
    *maxSize = 4;
    return v;
}

void imprimirVetor(int vet[], int tamanho) {
    printf("[");
    for (int i = 0; i < tamanho; i++) {
        printf("%d", vet[i]);
        if (i < tamanho - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void printVet(int *vet, int size, int maxSize) {
    int i;
    printf("Vetor de tamanho %d (max alocado %d)\n", size, maxSize);
    for (i = 0; i < size; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

int *addVet(int *v, int *size, int *maxSize, int e) {
    if (*size < *maxSize) {
        v[*size] = e;
        (*size)++;
        return v;
    } else {
        int *vaux = malloc(2 * (*maxSize) * sizeof(int));
        for (int i = 0; i < *size; ++i) {
            vaux[i] = v[i];
        }
        vaux[*size] = e;
        (*size)++;
        *maxSize *= 2;
        free(v);
        return vaux;
    }
}

int find(const int *v, int size, int e) {
    for (int i = 0; i < size; i++) {
        if (v[i] == e)
            return i;
    }
    return -1;
}

int *removeVet(int *v, int *size, int *maxSize, int e) {
    int pos = find(v, *size, e);
    if (pos != -1) {
        for (int i = pos; i < *size - 1; i++) {
            v[i] = v[i + 1];
        }
        (*size)--;
        if (*size < *maxSize / 2) {
            int *vaux = malloc((*maxSize / 2) * sizeof(int));
            for (int i = 0; i < *size; ++i) {
                vaux[i] = v[i];
            }
            *maxSize /= 2;
            free(v);
            return vaux;
        }
    }
    return v;
}


char *replicarStringComEspacos(const char *vetor, int vezes) {
    if (vetor == NULL || vezes <= 0) {
        return NULL;
    }

    size_t tamanhoOriginal = strlen(vetor);
    size_t tamanhoReplicado = (tamanhoOriginal + 1) * vezes;
    tamanhoReplicado--;

    char *resultado = (char *) malloc(tamanhoReplicado + 1);

    if (resultado == NULL) {
        return NULL;
    }

    resultado[0] = '\0';

    for (int i = 0; i < vezes; i++) {
        strcat(resultado, vetor);
        if (i < vezes - 1) {
            strcat(resultado, " ");
        }
    }

    return resultado;
}

int somaPeso(Cell vet[], int n) {

    int pesoTotal = 0;

    for (int i = 0; i < n; i++) {
        char letraAtual = vet[i].car;
        int pesoAtual = vet[i].peso;
        int sequencia = 1;

        while (i + 1 < n && vet[i + 1].car == letraAtual) {
            sequencia++;
            i++;
        }
        pesoTotal += sequencia * pesoAtual;
    }
    return pesoTotal;
}

typedef struct Produto {
    char nome[80];
    double preco;
    int quantidade;
} Produto;


typedef struct Aluno {
    char nome[80];
    float nota;
} Aluno;


typedef struct Alune {
    int ra;
    double nota;
} Alune;


typedef struct Ponto {
    double x;
    double y;
} Ponto;


typedef struct Reg {
    int vet[3];
    int n;
} Reg;


typedef struct Data {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct Pessoa {
    int rg;
    int cpf;
    char nome[80];
} Pessoa;

typedef struct Base {
    int armazenado;
    Pessoa pessoas[100];
} Base;

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int indiceMenor(const int vet[], int tam, int ini) {
    int menor = ini;
    int j;
    for (j = ini + 1; j < tam; j++) {
        if (vet[j] < vet[menor])
            menor = j;
    }
    return menor;
}

void selectionSort(int *vet, int tam) {
    int i, min;
    for (i = 0; i < tam - 1; i++) {
        min = indiceMenor(vet, tam, i);
        troca(&vet[i], &vet[min]);
    }
}

void selectionSortAbstrato(int vet[], int tam) {
    int i, min, aux;
    for (i = 0; i < tam; i++) {
        min = i;
        for (int j = i + 1; j < tam; j++) {
            if (vet[j] < vet[min]) {
                min = j;
            }
        }
        aux = vet[i];
        vet[i] = vet[min];
        vet[min] = aux;
    }
}

void bubbleSort(int *vet, int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (vet[j] > vet[j + 1]) {
                int aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
        }
    }
}

void insertionSort(int *vet, int tam) {
    int i, j, aux;
    for (i = 1; i < tam; i++) {
        aux = vet[i];
        for (j = i; j > 0 && aux < vet[j - 1]; j--) {
            vet[j] = vet[j - 1];
        }
        vet[j] = aux;
    }
}

void merge(int *vet, int inicio, int meio, int fim) {
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;
    temp = (int *) malloc(tamanho * sizeof(int));
    if (temp != NULL) {
        for (i = 0; i < tamanho; i++) {
            if (!fim1 && !fim2) {
                if (vet[p1] < vet[p2])
                    temp[i] = vet[p1++];
                else
                    temp[i] = vet[p2++];
                if (p1 > meio) fim1 = 1;
                if (p2 > fim) fim2 = 1;
            } else {
                if (!fim1)
                    temp[i] = vet[p1++];
                else
                    temp[i] = vet[p2++];
            }
        }
        for (j = 0, k = inicio; j < tamanho; j++, k++)
            vet[k] = temp[j];
    }
    free(temp);
}

void mergeSort(int *vet, int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSort(vet, inicio, meio);
        mergeSort(vet, meio + 1, fim);
        merge(vet, inicio, meio, fim);
    }
}

void quickSort(int *vet, int inicio, int fim) {
    int pivo, aux, i, j, meio;
    i = inicio;
    j = fim;
    meio = (int) ((i + j) / 2);
    pivo = vet[meio];
    do {
        while (vet[i] < pivo) i = i + 1;
        while (vet[j] > pivo) j = j - 1;
        if (i <= j) {
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
            i = i + 1;
            j = j - 1;
        }
    } while (j > i);
    if (inicio < j) quickSort(vet, inicio, j);
    if (i < fim) quickSort(vet, i, fim);
}

void heapSort(int *vet, int n) {
    int i = n / 2, pai, filho, t;
    while (1) {
        if (i > 0) {
            i--;
            t = vet[i];
        } else {
            n--;
            if (n == 0) return;
            t = vet[n];
            vet[n] = vet[0];
        }
        pai = i;
        filho = i * 2 + 1;
        while (filho < n) {
            if ((filho + 1 < n) && (vet[filho + 1] > vet[filho]))
                filho++;
            if (vet[filho] > t) {
                vet[pai] = vet[filho];
                pai = filho;
                filho = pai * 2 + 1;
            } else {
                break;
            }
        }
        vet[pai] = t;
    }
}

void shellSort(int *vet, int n) {
    int i, j, value;
    int gap = 1;
    do {
        gap = 3 * gap + 1;
    } while (gap < n);
    do {
        gap /= 3;
        for (i = gap; i < n; i++) {
            value = vet[i];
            j = i - gap;
            while (j >= 0 && value < vet[j]) {
                vet[j + gap] = vet[j];
                j -= gap;
            }
            vet[j + gap] = value;
        }
    } while (gap > 1);
}

void countingSort(int *vet, int n) {
    int i, j, k;
    int *aux;
    int maior = vet[0];
    for (i = 1; i < n; i++) {
        if (vet[i] > maior)
            maior = vet[i];
    }
    aux = (int *) malloc((maior + 1) * sizeof(int));
    for (i = 0; i <= maior; i++)
        aux[i] = 0;

    for (i = 0; i < n; i++)
        aux[vet[i]]++;

    for (i = 0, j = 0; i <= maior; i++) {
        for (k = aux[i]; k > 0; k--)
            vet[j++] = i;
    }
    free(aux);
}

void radixSort(int *vet, int n) {
    int i, exp = 1;
    int *b;
    int maior = vet[0];
    int *vetAux;
    vetAux = (int *) malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        if (vet[i] > maior)
            maior = vet[i];
    }
    while (maior / exp > 0) {
        b = (int *) calloc(10, sizeof(int));

        for (i = 0; i < n; i++)
            b[(vet[i] / exp) % 10]++;

        for (i = 1; i < 10; i++)
            b[i] += b[i - 1];

        for (i = n - 1; i >= 0; i--)
            vetAux[--b[(vet[i] / exp) % 10]] = vet[i];

        for (i = 0; i < n; i++)
            vet[i] = vetAux[i];

        exp *= 10;
        free(b);
    }
    free(vetAux);
}

void bucketSort(int *vet, int n) {
    int i, j;
    int max_value = 0;

    // Encontrar o valor máximo no array
    for (i = 0; i < n; i++) {
        if (vet[i] > max_value) {
            max_value = vet[i];
        }
    }

    // Criar um array de contagem com tamanho baseado no valor máximo
    int *count = (int *) calloc(max_value + 1, sizeof(int));

    // Contar a frequência de cada elemento
    for (i = 0; i < n; i++) {
        count[vet[i]]++;
    }

    // Rearranjar o array original usando os elementos e suas frequências
    for (i = 0, j = 0; i <= max_value; i++) {
        while (count[i] > 0) {
            vet[j++] = i;
            count[i]--;
        }
    }

    free(count);
}

int linearSearch(const int vet[], int tam, int chave) {
    for (int i = 0; i < tam; i++) {
        if (vet[i] == chave) {
            return i;
        }
    }
    return -1; // Chave não encontrada.
}

int binarySearch(const int vet[], int tam, int chave) {
    int inicio = 0;
    int fim = tam - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (vet[meio] == chave)
            return meio;
        else if (vet[meio] < chave)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }
    return -1;
}

int exponentialSearch(int vet[], int tam, int chave) {
    if (vet[0] == chave)
        return 0;

    int i = 1;
    while (i < tam && vet[i] <= chave)
        i *= 2;

    return binarySearch(vet, (i < tam ? i : tam), chave);
}

int ternarySearch(const int vet[], int tam, int chave) {
    int inicio = 0;
    int fim = tam - 1;

    while (inicio <= fim) {
        int terco = (fim - inicio) / 3;
        int meio1 = inicio + terco;
        int meio2 = fim - terco;

        if (vet[meio1] == chave)
            return meio1;
        else if (vet[meio2] == chave)
            return meio2;
        else if (vet[meio1] > chave)
            fim = meio1 - 1;
        else if (vet[meio2] < chave)
            inicio = meio2 + 1;
        else {
            inicio = meio1 + 1;
            fim = meio2 - 1;
        }
    }
    return -1;
}

int interpolationSearch(const int vet[], int tam, int chave) {
    int inicio = 0;
    int fim = tam - 1;

    while (inicio <= fim && chave >= vet[inicio] && chave <= vet[fim]) {
        int pos = inicio + ((chave - vet[inicio]) * (fim - inicio)) / (vet[fim] - vet[inicio]);

        if (vet[pos] == chave)
            return pos;
        else if (vet[pos] < chave)
            inicio = pos + 1;
        else
            fim = pos - 1;
    }
    return -1;
}

int jumpSearch(const int vet[], int tam, int chave) {
    int salto = (int) sqrt(tam);
    int anterior = 0;

    while (vet[(salto < tam ? salto : tam) - 1] < chave) {
        anterior = salto;
        salto += (int) sqrt(tam);
        if (anterior >= tam)
            return -1;
    }

    for (int i = anterior; i < (salto < tam ? salto : tam); i++) {
        if (vet[i] == chave)
            return i;
    }

    return -1;
}

int fibonacciSearch(const int vet[], int tam, int chave) {
    int fibM2 = 0;
    int fibM1 = 1;
    int fibM = fibM2 + fibM1;

    while (fibM < tam) {
        fibM2 = fibM1;
        fibM1 = fibM;
        fibM = fibM2 + fibM1;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = (offset + fibM2) < (tam - 1) ? (offset + fibM2) : (tam - 1);

        if (vet[i] < chave) {
            fibM = fibM1;
            fibM1 = fibM2;
            fibM2 = fibM - fibM1;
            offset = i;
        } else if (vet[i] > chave) {
            fibM = fibM2;
            fibM1 -= fibM2;
            fibM2 = fibM - fibM1;
        } else {
            return i;
        }
    }

    if (fibM1 && vet[offset + 1] == chave)
        return offset + 1;

    return -1;
}

Aluno leAluno() {
    Aluno aux;

    printf("Digite o nome do aluno: ");
    fgets(aux.nome, 80, stdin);
    aux.nome[strlen(aux.nome) - 1] = '\0';
    printf("Digite a nota do aluno: ");
    scanf("%f", &aux.nota);
    getchar();
}

void imprimeAluno(Aluno a) {
    printf("Nome: %s\n", a.nome);
    printf("Nota: %.2f\n", a.nota);
}

void listarTurma(Aluno alunos[], int n) {
    for (int i = 0; i < n; i++) {
        imprimeAluno(alunos[i]);
    }
}

Produto *lerProdutos(int n) {
    Produto *produtos = malloc(n * sizeof(Produto));
    for (int i = 0; i < n; i++) {
        printf("Name of product %d:     ", i + 1);
        scanf("%s", produtos[i].nome);
        printf("Price of product %d:    ", i + 1);
        scanf("%lf", &produtos[i].preco);
        printf("Quantity of product %d: ", i + 1);
        scanf("%d", &produtos[i].quantidade);
    }
    return produtos;
}

void ordenaPreco(Produto vet[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (vet[i].preco > vet[j].preco) {
                Produto aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
}

void ordenaQtd(Produto vet[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (vet[i].quantidade > vet[j].quantidade) {
                Produto aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
}

void imprimeProduto(Produto vet[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Name:     %s\n", vet[i].nome);
        printf("Price:    %.2lf\n", vet[i].preco);
        printf("Quantity: %d\n", vet[i].quantidade);
        putchar('\n');
    }
}

Aluno *leAlunos(int n) {
    Aluno *alunos = malloc(n * sizeof(Aluno));
    if (alunos == NULL) {
        fprintf(stderr, "Erro na alocação de memória\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        printf("Nome: ");
        scanf("%s", alunos[i].nome);
        printf("Nota: ");
        scanf("%f", &alunos[i].nota);
    }
    return alunos;
}

Alune *leAlunes(int n) {
    Alune *alunes = malloc(n * sizeof(Alune));
    if (alunes == NULL) {
        fprintf(stderr, "Erro na alocação de memória\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        printf("RA: ");
        scanf("%d", &alunes[i].ra);
        printf("Nota: ");
        scanf("%lf", &alunes[i].nota);
    }
    return alunes;
}

double mediaAlunes(struct Alune alunes[], int n) {
    double soma = 0;
    for (int i = 0; i < n; i++) {
        soma += alunes[i].nota;
    }
    return soma / n;
}

Ponto *lePonto() {

    Ponto *ponto = malloc(sizeof(Ponto));

    if (ponto == NULL) {
        fprintf(stderr, "Erro na alocação de memória\n");
        exit(1);
    }

    printf("Digite a coordenada x: ");
    scanf("%lf", &ponto->x);

    printf("Digite a coordenada y: ");
    scanf("%lf", &ponto->y);

    return ponto;
}

void imprimePonto(Ponto p) {
    printf("x: %.2lf\n", p.x);
    printf("y: %.2lf\n", p.y);
}

Ponto somaPonto(Ponto p1, Ponto p2) {
    Ponto soma;
    soma.x = p1.x + p2.x;
    soma.y = p1.y + p2.y;
    return soma;
}

Ponto *somaPonto2(Ponto *p1, Ponto *p2) {
    Ponto *soma = malloc(sizeof(Ponto));
    if (soma == NULL) {
        fprintf(stderr, "Erro na alocação de memória\n");
        exit(1);
    }
    soma->x = p1->x + p2->x;
    soma->y = p1->y + p2->y;
    return soma;
}

Ponto subtraiPonto(Ponto p1, Ponto p2) {
    Ponto subtrai;
    subtrai.x = p1.x - p2.x;
    subtrai.y = p1.y - p2.y;
    return subtrai;
}

Ponto multiplicaPonto(Ponto p1, double escalar) {
    Ponto multiplica;
    multiplica.x = p1.x * escalar;
    multiplica.y = p1.y * escalar;
    return multiplica;
}

double distanciaPonto(Ponto p1, Ponto p2) {
    double distancia;
    distancia = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    return distancia;
}

Reg leReg(void) {
    Reg reg;

    for (int i = 0; i < 3; i++) {
        printf("Digite o valor para Reg.vet[%d]: ", i);
        scanf("%d", &(reg.vet[i]));
    }

    printf("Digite o valor para Reg.n: ");
    scanf("%d", &(reg.n));

    return reg;
}

Reg somaVetorSegundoAtributo(Reg reg) {
    int soma = 0;

    for (int i = 0; i < 3; i++) {
        soma += reg.vet[i];
    }

    Reg resultado = reg;
    resultado.vet[1] = soma;

    return resultado;
}

void imprimeReg(Reg reg) {
    printf("Valores da estrutura Reg:\n");

    printf("Vetor de inteiros: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", reg.vet[i]);
    }
    printf("\n");

    printf("Variável inteira (n): %d\n", reg.n);
}

char *concatena(char *s1, char *s2) {
    char *sres = NULL;
    int t1, t2, i;

    t1 = strlen(s1);
    t2 = strlen(s2);

    sres = malloc((t1 + t2 + 1) * sizeof(char));

    for (i = 0; i < t1; i++)
        sres[i] = s1[i];
    for (i = 0; i < t2; i++)
        sres[t1 + i] = s2[i];
    sres[t1 + t2] = '\0';

    return sres;
}

void swapData(Data *a, Data *b) {
    Data temp = *a;
    *a = *b;
    *b = temp;
}

void ordenaPorDia(Data vet[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (vet[j].ano > vet[j + 1].ano ||
                (vet[j].ano == vet[j + 1].ano && vet[j].mes > vet[j + 1].mes) ||
                (vet[j].ano == vet[j + 1].ano && vet[j].mes == vet[j + 1].mes && vet[j].dia > vet[j + 1].dia)) {
                swapData(&vet[j], &vet[j + 1]);
            }
        }
    }
}

void ordenaPorMes(Data vet[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (vet[j].ano > vet[j + 1].ano ||
                (vet[j].ano == vet[j + 1].ano &&
                 vet[j].mes > vet[j + 1].mes)) {
                swapData(&vet[j], &vet[j + 1]);
            }
        }
    }
}

void ordenaPorAno(Data vet[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (vet[j].ano > vet[j + 1].ano) {
                swapData(&vet[j], &vet[j + 1]);
            }
        }
    }
}

void ordena(Data vet[], int tam) {
    ordenaPorAno(vet, tam);

    int i = 0;
    while (i < tam) {
        int j = i;
        while (j < tam && vet[j].ano == vet[i].ano) {
            j++;
        }
        ordenaPorMes(&vet[i], j - i);
        i = j;
    }

    i = 0;
    while (i < tam) {
        int j = i;
        while (j < tam && vet[j].ano == vet[i].ano && vet[j].mes == vet[i].mes) {
            j++;
        }
        ordenaPorDia(&vet[i], j - i);
        i = j;
    }
}

Data leData(void) {
    struct Data data;

    printf("Day: ");
    scanf("%d", &(data.dia));

    printf("Month: ");
    scanf("%d", &(data.mes));

    printf("Year: ");
    scanf("%d", &(data.ano));

    return data;
}

void imprimeDatas(Data datas[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("Dia: %d, Mês: %d, Ano: %d\n", datas[i].dia, datas[i].mes, datas[i].ano);
    }
}

Base cria_base() {
    Base base;
    base.armazenado = 0;
    return base;
}

int insere_base(Pessoa p, Base base) {
    if (base.armazenado < 100) {
        base.pessoas[base.armazenado] = p;
        base.armazenado++;
        return 1;
    }
    return 0;
}

int remove_base(int rg, Base base) {
    for (int i = 0; i < base.armazenado; i++) {
        if (base.pessoas[i].rg == rg) {
            for (int j = i; j < base.armazenado - 1; j++) {
                base.pessoas[j] = base.pessoas[j + 1];
            }
            base.armazenado--;
            return 1;
        }
    }
    return 0;
}

int buscaBinaria(Pessoa cadastro[], int tamanho, int rg) {
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (cadastro[meio].rg == rg)
            return meio; // Encontrou o RG, retorna o índice
        else if (cadastro[meio].rg < rg)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }

    return -1; // RG não encontrado
}

Pessoa lePessoa() {
    Pessoa pessoa;
    printf("Digite o RG: ");
    scanf("%d", &pessoa.rg);
    printf("Digite o CPF: ");
    scanf("%d", &pessoa.cpf);
    printf("Digite o nome: ");
    scanf("%s", pessoa.nome);
    return pessoa;
}