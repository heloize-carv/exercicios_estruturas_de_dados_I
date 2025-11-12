#include <stdio.h>

typedef struct {
    int id;
    int pontuacao;
} Jogador;

int main() {
    int n;
    scanf("%d", &n);

    Jogador jogadores[n];

    // Leitura dos dados dos jogadores
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &jogadores[i].id, &jogadores[i].pontuacao);
    }

    // Bubble Sort em ordem decrescente de pontuação
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (jogadores[j].pontuacao < jogadores[j + 1].pontuacao) {
                Jogador temp = jogadores[j];
                jogadores[j] = jogadores[j + 1];
                jogadores[j + 1] = temp;
            }
        }
    }

    // Impressão da lista ordenada
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", jogadores[i].id, jogadores[i].pontuacao);
    }

    return 0;
}
