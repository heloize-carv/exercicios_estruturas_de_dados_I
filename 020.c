#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// O Temporizador do Power-Up "Super Salto"

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    // Ponteiro genérico para armazenar a duração do power-up
    void *ponteiro_duracao = NULL;

    // Alocando memória suficiente para um inteiro (duração em segundos)
    ponteiro_duracao = malloc(sizeof(int));

    // Verificando se a alocação foi bem-sucedida
    if (ponteiro_duracao != NULL) {

        // Definindo a duração inicial (10 segundos)
        *(int *)ponteiro_duracao = 10;

        // Exibindo a duração inicial do power-up
        printf("Power-up 'Super Salto' ativado! Duração: %d segundos.\n", *(int *)ponteiro_duracao);

        // Simulando a passagem de 3 segundos
        *(int *)ponteiro_duracao = *(int *)ponteiro_duracao - 3;

        // Exibindo a duração restante
        printf("3 segundos se passaram... Duracao restante: %d segundos.\n", *(int *)ponteiro_duracao);

        // Liberando a memória alocada
        free(ponteiro_duracao);
        // Em um jogo real, liberaríamos essa memória quando o efeito terminasse.
    } else {
        printf("Erro ao alocar memória para o temporizador do Power-up.\n");
    }

    return 0;
}
