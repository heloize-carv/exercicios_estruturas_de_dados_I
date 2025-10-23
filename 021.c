#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// A Bomba de Fumaça do Ninja

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    // Ponteiro para armazenar a duração da fumaça
    int *duracao_fumaca = NULL;

    // Alocando memória para armazenar um inteiro
    duracao_fumaca = (int *) malloc(sizeof(int));

    // Verificando se a alocação foi bem-sucedida
    if (duracao_fumaca != NULL) {
        // Definindo a duração da fumaça
        *duracao_fumaca = 5;

        // Imprimindo a ativação da bomba
        printf("Bomba de fumaça ativada! Duração: %d segundos.\n", *duracao_fumaca);

        // Liberando a memória alocada
        free(duracao_fumaca);

        // Evitando ponteiro pendurado
        duracao_fumaca = NULL;

        // Imprimindo a finalização
        printf("A fumaça se dissipou.\n");
    } else {
        printf("Erro ao alocar memória para a fumaça.\n");
    }

    return 0;
}
