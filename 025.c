#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Gerenciamento de Inimigos em uma Fase

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    int quantidade;
    int *status_inimigos;

    // 1. Perguntar a quantidade de inimigos
    printf("Digite a quantidade de inimigos na fase: ");
    scanf("%d", &quantidade);

    // 2. Alocar memória com calloc
    status_inimigos = (int *)calloc(quantidade, sizeof(int));

    // 3. Verificar se a alocação foi bem-sucedida
    if (status_inimigos == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // 4. Mostrar o status inicial (todos 0 - Inativos)
    printf("\nStatus inicial dos inimigos:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("Inimigo %d: Inativo (%d)\n", i + 1, status_inimigos[i]);
    }

    // 5. Ativar todos os inimigos (mudar 0 para 1)
    for (int i = 0; i < quantidade; i++) {
        status_inimigos[i] = 1;
    }

    // 6. Mostrar o novo status (todos 1 - Ativos)
    printf("\nStatus após ativação:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("Inimigo %d: Ativo (%d)\n", i + 1, status_inimigos[i]);
    }

    // 7. Liberar memória alocada
    free(status_inimigos);

    printf("\nMemória liberada com sucesso!\n");

    return 0;
}
