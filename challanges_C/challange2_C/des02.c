/* 
Nome: Gianlucca Fadiga Rissato - ADS Manhã
RA: 2760482311014

Descrição: O programa consiste em um cálculo referente ao triênio
com maior crescimento de pib em n anos

Entrada: a entrada consiste em um número inteiro n para anos e 
n números de ponto flutuante referente ao pib de cada ano

Saída: a saída consiste no número de ponto flutuante com uma casa decimal
referente ao triênio com maior crescimento de pib (em caso de triênios iguais,
o mais antigo persiste), bem como os anos do triênio com o maior crescimento.
*/

#include <stdio.h>

int main() {

    // Inicialização das variáveis 
    int n, ano_inicial, controle = 0;
    float media_pib;
    // Poderia ser feito utilizando variáveis independentes
    float pib_0, pib_1, pib_2;

    // Scan da variável dos anos que serão dados de entrada
    scanf("%d", &n);

    float ano_0, ano_1, ano_2, ano_cont;
    float maiorMedia = 0;

    // scanf("%f\n%f\n%f", &ano_0, &ano_1, &ano_2);
    scanf("%f", &ano_0);
    scanf("%f", &ano_1);
    scanf("%f", &ano_2);

    do {

        // Laço de repetição para calcular o crescimento do pib entre anos
        if (ano_1 > ano_0) {
            pib_1 = (100 * (ano_1 - ano_0)) / ano_0;
        } else {
            pib_1 = (100 - (((ano_1 * 100) / ano_0))) * -1;
        }

        if (ano_2 > ano_1) {
            pib_2 = (100 * (ano_2 - ano_1)) / ano_1;
        } else {
            pib_2 = (100 - (((ano_2 * 100) / ano_1))) * -1;
        }

        media_pib = (pib_0 + pib_1 + pib_2) / 3;
        pib_0 = pib_1;

        /* 
        Só há alteração da media se for diferente de 0 (que é a inicialização)
        No caso, só há alteração dos anos se a media nova for maior, evitando substituição
        por conta de igualdade de medias
        */
        if (maiorMedia == 0 || media_pib > maiorMedia) {
            ano_inicial = controle;
            maiorMedia = media_pib;
        }

        // Scan do próximo ano
        if (controle < n - 3)
            scanf("%f", &ano_cont);

        // Alteração dos anos
        ano_0 = ano_1;
        ano_1 = ano_2;
        ano_2 = ano_cont;

        controle++;
    } while (controle < n - 2);   

    // Print final
    printf("a maior média de crescimento foi entre os anos %d e %d: %.1f\n",
        ano_inicial, ano_inicial + 2, maiorMedia);

    return 0;
}

/* Pegar 3 variáveis, calcular e então resetar */