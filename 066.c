#include <stdio.h>

int main() {
    int n, i, j, aux;

    // Lê o número de jogadores
    printf("Digite a quantidade de jogadores: ");
    scanf("%d", &n);

    int pontuacoes[n];

    // Lê as pontuações dos jogadores
    printf("Digite as pontuacoes dos jogadores:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &pontuacoes[i]);
    }

    // Algoritmo Bubble Sort - ordenação decrescente
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (pontuacoes[j] < pontuacoes[j + 1]) {
                // Troca os elementos
                aux = pontuacoes[j];
                pontuacoes[j] = pontuacoes[j + 1];
                pontuacoes[j + 1] = aux;
            }
        }
    }

    // Exibe as pontuações ordenadas
    printf("Placar final (decrescente):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", pontuacoes[i]);
    }

    printf("\n");
    return 0;
}
