#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char nickname[50];
    int reputacao;
} Jogador;

int buscaBinaria(Jogador jogadores[], int n, int idBusca) {
    int inicio = 0;
    int fim = n - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (jogadores[meio].id == idBusca)
            return meio;
        else if (jogadores[meio].id < idBusca)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }

    return -1; // não encontrado
}

int main() {
    int n, opcao, idBusca;

    printf("Digite o numero de jogadores: ");
    scanf("%d", &n);

    Jogador jogadores[n];

    printf("\n--- Cadastro dos jogadores (IDs em ordem crescente) ---\n");
    for (int i = 0; i < n; i++) {
        printf("\nJogador %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &jogadores[i].id);
        printf("Nickname: ");
        scanf("%s", jogadores[i].nickname);
        printf("Reputacao: ");
        scanf("%d", &jogadores[i].reputacao);
    }

    do {
        printf("\n--- MENU ---\n");
        printf("1 - Adicionar Reputacao\n");
        printf("2 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("Digite o ID do jogador: ");
            scanf("%d", &idBusca);

            int posicao = buscaBinaria(jogadores, n, idBusca);

            if (posicao != -1) {
                jogadores[posicao].reputacao += 100;
                printf("Nickname: %s, Nova Reputacao: %d\n",
                       jogadores[posicao].nickname,
                       jogadores[posicao].reputacao);
            } else {
                printf("Jogador com ID %d nao encontrado.\n", idBusca);
            }
        }

    } while (opcao != 2);

    printf("\nEncerrando o programa...\n");
    return 0;
}
