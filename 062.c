#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[51]; // 50 caracteres + '\0'
    int kills;
} Jogador;

int main() {
    int N;
    scanf("%d", &N);

    // Alocação dinâmica do vetor de jogadores
    Jogador *vetor = (Jogador*) malloc(N * sizeof(Jogador));
    if (vetor == NULL) {
        printf("Erro na alocacao de memoria.\n");
        return 1;
    }

    // Leitura dos dados
    for (int i = 0; i < N; i++) {
        scanf("%s %d", vetor[i].nome, &vetor[i].kills);
    }

    // Ordenação por seleção (Selection Sort) decrescente
    for (int i = 0; i < N - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < N; j++) {
            if (vetor[j].kills > vetor[max_idx].kills) {
                max_idx = j;
            }
        }
        // Troca os jogadores
        if (max_idx != i) {
            Jogador temp = vetor[i];
            vetor[i] = vetor[max_idx];
            vetor[max_idx] = temp;
        }
    }

    // Impressão do leaderboard
    for (int i = 0; i < N; i++) {
        printf("%s %d\n", vetor[i].nome, vetor[i].kills);
    }

    // Liberar memória
    free(vetor);

    return 0;
}
