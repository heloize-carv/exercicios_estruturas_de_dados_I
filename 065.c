#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int pontuacao;
} Jogador;

int main() {
    int N;
    scanf("%d", &N);

    Jogador jogadores[N];

    // Leitura dos dados dos jogadores
    for (int i = 0; i < N; i++) {
        scanf("%s %d", jogadores[i].nome, &jogadores[i].pontuacao);
    }

    // Ordenação por Inserção (Insertion Sort) - ordem decrescente
    for (int i = 1; i < N; i++) {
        Jogador atual = jogadores[i];
        int j = i - 1;

        // Mover elementos com pontuação menor para a direita
        while (j >= 0 && jogadores[j].pontuacao < atual.pontuacao) {
            jogadores[j + 1] = jogadores[j];
            j--;
        }
        jogadores[j + 1] = atual;
    }

    // Impressão do ranking final
    for (int i = 0; i < N; i++) {
        printf("%d %s\n", jogadores[i].pontuacao, jogadores[i].nome);
    }

    return 0;
}
