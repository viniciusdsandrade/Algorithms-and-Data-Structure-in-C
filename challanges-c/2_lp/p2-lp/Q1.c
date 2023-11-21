#include <stdio.h>
#include <string.h>

typedef struct {
    char placa[8];
    char modelo[12];
    char marca[12];
} Carro;

// Fun��o para alterar o modelo e a marca de um carro com base na placa
void alterarModeloMarca(Carro carros[], char placa[]) {
    int i;
    int aux = -1; // Inicializa aux como -1 para indicar que a placa n�o foi encontrada
    int tam = sizeof(Carro) / sizeof(carros[0]);

    for (i = 0; i < tam; i++) {
        if (strcmp(carros[i].placa, placa) == 0) {
            // Se a placa for encontrada, atribui o �ndice � vari�vel aux
            aux = i;
            break; // N�o h� necessidade de continuar o loop
        }
    }

    if (aux == -1) {
        // Se a placa n�o foi encontrada, exibe mensagem e retorna
        printf("Placa nao encontrada.\n");
        return;
    }

    // Solicita ao usu�rio o novo modelo
    printf("Digite o novo modelo: ");
    scanf("%11s", carros[aux].modelo);

    // Solicita ao usu�rio a nova marca
    printf("Digite a nova marca: ");
    scanf("%11s", carros[aux].marca);
}


int main(void) {
    // Exemplo de uso
    Carro carros[3] = {
            {"ABC1234", "Fusca", "Volkswagen"},
            {"XYZ5678", "Civic", "Honda"},
            {"DEF9012", "Corolla", "Toyota"}
    };

    int tam = sizeof(carros) / sizeof(carros[0]);

    char placa[8];

    // Solicita ao usu�rio a placa do carro que deseja alterar o modelo e a marca
    printf("Digite a placa do carro que deseja alterar o modelo e a marca: ");
    scanf("%s", placa);

    // Chama a fun��o para alterar o modelo e a marca do carro com a placa informada
    alterarModeloMarca(carros, placa);

    // Exibe os carros ap�s as altera��es
    printf("\nCarros apos as alteracoes:\n");
    for (int i = 0; i < tam; i++) {
        printf("Placa: %s, Modelo: %s, Marca: %s\n", carros[i].placa, carros[i].modelo, carros[i].marca);
    }

    return 0;
}
