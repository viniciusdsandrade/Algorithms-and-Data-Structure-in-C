#include <stdio.h>
#include <string.h>

typedef struct Aluno {
    char nome[100];
    int RA;
} Aluno;

/**
 * Copia o conte�do de um arquivo de origem para um arquivo de destino.
 *
 * @param nomeArquivoOrigem Nome do arquivo de origem.
 * @param nomeArquivoDestino Nome do arquivo de destino.
 */
void copiarArquivo(const char *nomeArquivoOrigem, const char *nomeArquivoDestino) {
    FILE *arquivoOrigem, *arquivoDestino;
    char buffer[1024]; // Tamanho do buffer de leitura/escrita

    // Abre o arquivo de origem para leitura
    arquivoOrigem = fopen(nomeArquivoOrigem, "rb");
    if (arquivoOrigem == NULL) {
        perror("Erro ao abrir arquivo de origem");
        return;
    }

    // Abre o arquivo de destino para escrita
    arquivoDestino = fopen(nomeArquivoDestino, "wb");
    if (arquivoDestino == NULL) {
        perror("Erro ao abrir arquivo de destino");
        fclose(arquivoOrigem); // Fecha o arquivo de origem
        return;
    }

    // Loop para copiar o conte�do
    size_t bytesLidos;
    while ((bytesLidos = fread(buffer, 1, sizeof(buffer), arquivoOrigem)) > 0) {
        size_t bytesEscritos = fwrite(buffer, 1, bytesLidos, arquivoDestino);
        if (bytesEscritos != bytesLidos) {
            perror("Erro ao escrever no arquivo de destino");
            break;
        }
    }

    fclose(arquivoOrigem);
    fclose(arquivoDestino);

    if (bytesLidos == 0)
        printf("Copia do arquivo concluida com sucesso!\n");
}

/**
 * Imprime o conte�do de um arquivo na tela.
 *
 * @param nomeArquivo Nome do arquivo a ser impresso.
 */
void imprimirConteudoArquivo(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    int caractere;
    while ((caractere = fgetc(arquivo)) != EOF) {
        putchar(caractere); // Imprime o caractere na tela
    }

    fclose(arquivo);
}

/**
 * Verifica se um arquivo pode ser aberto com sucesso.
 *
 * @param nomeArquivo Nome do arquivo a ser verificado.
 * @return Retorna 1 se o arquivo pode ser aberto com sucesso, 0 caso contr�rio.
 */
int verificarArquivo(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        return 0; // N�o foi poss�vel abrir o arquivo
    } else {
        fclose(arquivo);
        return 1; // O arquivo foi aberto com sucesso
    }
}

/**
 * Compara o conte�do de dois arquivos para verificar se s�o id�nticos.
 *
 * @param file1 Nome do primeiro arquivo.
 * @param file2 Nome do segundo arquivo.
 * @return Retorna verdadeiro se os arquivos s�o id�nticos, falso caso contr�rio.
 */
bool compareFiles(const char *file1, const char *file2) {
    FILE *f1, *f2;
    int ch1, ch2;

    f1 = fopen(file1, "rb");
    f2 = fopen(file2, "rb");

    if (f1 == NULL || f2 == NULL) {
        perror("Erro ao abrir os arquivos");
        if (f1 != NULL) fclose(f1);
        if (f2 != NULL) fclose(f2);
        return false; // Retorna falso para indicar erro
    }

    do {
        ch1 = fgetc(f1);
        ch2 = fgetc(f2);

        if (ch1 != ch2) {
            fclose(f1);
            fclose(f2);
            return false; // Retorna falso para indicar que os arquivos s�o diferentes
        }
    } while (ch1 != EOF && ch2 != EOF);

    fclose(f1);
    fclose(f2);

    if (ch1 == ch2)
        return true; // Retorna verdadeiro para indicar que os arquivos s�o id�nticos

    return false; // Retorna falso se os tamanhos dos arquivos forem diferentes
}

void cadastraAluno(char nomeArq[]) {
    FILE *arq;
    Aluno aux;

    arq = fopen(nomeArq, "ab");
    if (arq == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Digite o nome do aluno: ");
    scanf("%s", aux.nome);
    printf("Digite o RA do aluno: ");
    scanf("%d", &aux.RA);

    fwrite(&aux, sizeof(Aluno), 1, arq);

    fclose(arq);
}

void imprimeAluno(char nomeArq[]) {
    FILE *arq;
    Aluno aux;

    arq = fopen(nomeArq, "r+b");
    if (arq == NULL) {
        printf("Error opening file!\n");
        return;
    }

    while (fread(&aux, sizeof(Aluno), 1, arq) == 1) {
        printf("Nome: %s\n", aux.nome);
        printf("RA: %d\n", aux.RA);
        printf("--------------------\n");
    }

    fclose(arq);
}

void alteraNomeAluno(char nomeArq[], int ra, char nome[]) {
    FILE *arq;
    Aluno aux;

    arq = fopen(nomeArq, "r+b");

    if (arq == NULL) {
        printf("Error opening file!\n");
        return;
    }

    while (fread(&aux, sizeof(Aluno), 1, arq) == 1) {
        if (aux.RA == ra) {
            strcpy(aux.nome, nome);
            fseek(arq, -sizeof(Aluno), SEEK_CUR); // Volta o ponteiro para a posi��o anterior (antes da leitura
            fwrite(&aux, sizeof(Aluno), 1, arq);
            break;
        }
    }

    fclose(arq);
}
