#include <stdio.h>

// Definição da estrutura do jogador
typedef struct {
    int id;
    int pontuacao;
} Jogador;

// Função para trocar dois jogadores de posição
void troca(Jogador *a, Jogador *b) {
    Jogador temp = *a;
    *a = *b;
    *b = temp;
}

// Função de partição (usando o pivô como o último elemento)
int particao(Jogador v[], int e, int d) {
    int pivo = v[d].pontuacao; // pivô é a pontuação do último jogador
    int j = e - 1;

    for (int i = e; i < d; i++) {
        // Comparação invertida (para ordem DECRESCENTE)
        if (v[i].pontuacao > pivo) {
            j++;
            troca(&v[i], &v[j]);
        }
    }

    // Coloca o pivô na posição correta
    troca(&v[j + 1], &v[d]);
    return j + 1;
}

// Implementação recursiva do Quick Sort
void quicksort(Jogador v[], int e, int d) {
    if (e < d) {
        int q = particao(v, e, d);
        quicksort(v, e, q - 1);
        quicksort(v, q + 1, d);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Jogador jogadores[n];

    // Leitura dos dados dos jogadores
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &jogadores[i].id, &jogadores[i].pontuacao);
    }

    // Ordenação usando Quick Sort
    quicksort(jogadores, 0, n - 1);

    // Impressão do ranking (ordem decrescente de pontuação)
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", jogadores[i].id, jogadores[i].pontuacao);
    }

    return 0;
}
