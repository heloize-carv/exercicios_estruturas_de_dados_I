#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para trocar dois elementos
void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função de partição com pivô aleatório
int particao(int v[], int e, int d) {
    // Escolhe um índice aleatório entre e e d
    int indice_pivo = e + rand() % (d - e + 1);
    
    // Move o pivô escolhido para o final (posição d)
    troca(&v[indice_pivo], &v[d]);
    
    int pivo = v[d];
    int j = e - 1;
    
    for (int i = e; i < d; i++) {
        if (v[i] <= pivo) {
            j++;
            troca(&v[i], &v[j]);
        }
    }
    
    troca(&v[j + 1], &v[d]);
    return j + 1; // Retorna a posição final do pivô
}

// Função recursiva do Quick Sort
void quicksort(int v[], int e, int d) {
    if (e < d) {
        int p = particao(v, e, d);
        quicksort(v, e, p - 1);
        quicksort(v, p + 1, d);
    }
}

int main() {
    int n;
    
    // Inicializa o gerador de números aleatórios
    srand(time(NULL));
    
    // Lê o número de jogadores
    scanf("%d", &n);
    
    int v[n];
    
    // Lê as pontuações dos jogadores
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    
    // Chama o Quick Sort
    quicksort(v, 0, n - 1);
    
    // Imprime o vetor ordenado
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    
    return 0;
}
