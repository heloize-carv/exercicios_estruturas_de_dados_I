#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar uma nave inimiga
typedef struct {
    int id;
    int nivel_ameaca;
} Nave;

// Função para intercalar (merge) duas metades ordenadas do vetor
void merge(Nave v[], int inicio, int meio, int fim) {
    int i = inicio;
    int j = meio + 1;
    int k = 0;

    // Aloca dinamicamente o vetor temporário
    Nave *temp = (Nave *)malloc((fim - inicio + 1) * sizeof(Nave));
    if (temp == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    // Intercala as duas metades mantendo a ordem crescente
    while (i <= meio && j <= fim) {
        if (v[i].nivel_ameaca <= v[j].nivel_ameaca) {
            temp[k++] = v[i++];
        } else {
            temp[k++] = v[j++];
        }
    }

    // Copia os elementos restantes da metade esquerda
    while (i <= meio) {
        temp[k++] = v[i++];
    }

    // Copia os elementos restantes da metade direita
    while (j <= fim) {
        temp[k++] = v[j++];
    }

    // Copia os elementos do vetor temporário de volta ao original
    for (i = inicio, k = 0; i <= fim; i++, k++) {
        v[i] = temp[k];
    }

    // Libera a memória alocada
    free(temp);
}

// Função recursiva do Merge Sort
void mergeSort(Nave v[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);
        merge(v, inicio, meio, fim);
    }
}

// Função principal
int main() {
    int n;
    scanf("%d", &n); // Lê a quantidade de naves

    // Aloca dinamicamente o vetor de naves
    Nave *naves = (Nave *)malloc(n * sizeof(Nave));
    if (naves == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Lê os dados das naves (id e nível de ameaça)
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &naves[i].id, &naves[i].nivel_ameaca);
    }

    // Ordena as naves pelo nível de ameaça (crescente)
    mergeSort(naves, 0, n - 1);

    // Imprime os IDs das naves na nova ordem
    for (int i = 0; i < n; i++) {
        printf("%d ", naves[i].id);
    }
    printf("\n");

    // Libera memória
    free(naves);

    return 0;
}
