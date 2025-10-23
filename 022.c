#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Gerador de Ondas de Inimigos

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    int n_inimigos;       // Quantidade de inimigos da onda
    int *ponteiro_onda;   // Ponteiro para armazenar os IDs dos inimigos

    // Solicitando ao usuário a quantidade de inimigos
    printf("Digite a quantidade de inimigos da onda: ");
    scanf("%d", &n_inimigos);

    // Alocando dinamicamente memória para armazenar os IDs
    ponteiro_onda = (int *) malloc(n_inimigos * sizeof(int));

    // Verificando se a alocação foi bem-sucedida
    if (ponteiro_onda != NULL) {
        // Populando os IDs dos inimigos
        for (int i = 0; i < n_inimigos; i++) {
            printf("Digite o ID do inimigo %d: ", i + 1);
            scanf("%d", &ponteiro_onda[i]);
        }

        // Exibindo os IDs da onda de inimigos
        printf("Onda de inimigos criada com sucesso! IDs: ");
        for (int i = 0; i < n_inimigos; i++) {
            printf("%d ", ponteiro_onda[i]);
        }
        printf("\n");

        // Liberando a memória alocada
        free(ponteiro_onda);
        ponteiro_onda = NULL; // Evita ponteiro pendurado
    } else {
        printf("Erro ao alocar memória para a onda de inimigos.\n");
    }

    return 0;
}
