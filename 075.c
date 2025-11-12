#include <stdio.h>

// Função de partição usando o esquema de Lomuto
int particao(int v[], int inicio, int fim) {
    int pivo = v[fim]; // pivô é o último elemento
    int i = inicio - 1; // índice do menor elemento
    int temp;

    for (int j = inicio; j < fim; j++) {
        if (v[j] < pivo) {
            i++;
            // troca v[i] e v[j]
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }

    // coloca o pivô na posição correta
    temp = v[i + 1];
    v[i + 1] = v[fim];
    v[fim] = temp;

    return i + 1; // retorna a posição final do pivô
}

// Função recursiva do Quick Sort
void quicksort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int p = particao(v, inicio, fim);
        quicksort(v, inicio, p - 1); // ordena a parte esquerda
        quicksort(v, p + 1, fim);    // ordena a parte direita
    }
}

int main() {
    int n;
    scanf("%d", &n); // lê a quantidade de jogadores

    int v[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]); // lê os MMRs
    }

    quicksort(v, 0, n - 1); // ordena os MMRs

    // imprime o vetor ordenado
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    printf("\n");
    return 0;
}
