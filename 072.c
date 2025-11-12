#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int posicao;
    char nome[100];
} Piloto;

void intercala(Piloto v[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    Piloto *esq = malloc(n1 * sizeof(Piloto));
    Piloto *dir = malloc(n2 * sizeof(Piloto));

    // Copia os dados para os vetores temporários
    for (int i = 0; i < n1; i++) {
        esq[i] = v[inicio + i];
    }
    for (int j = 0; j < n2; j++) {
        dir[j] = v[meio + 1 + j];
    }

    int i = 0, j = 0, k = inicio;

    // Junta os dois subvetores ordenados
    while (i < n1 && j < n2) {
        if (esq[i].posicao <= dir[j].posicao) {
            v[k] = esq[i];
            i++;
        } else {
            v[k] = dir[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes (se houver)
    while (i < n1) {
        v[k] = esq[i];
        i++;
        k++;
    }

    while (j < n2) {
        v[k] = dir[j];
        j++;
        k++;
    }

    free(esq);
    free(dir);
}

void mergeSort(Piloto v[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);
        intercala(v, inicio, meio, fim);
    }
}

int main() {
    int n;
    printf("Digite o número de pilotos: ");
    scanf("%d", &n);

    Piloto *pilotos = malloc(n * sizeof(Piloto));

    for (int i = 0; i < n; i++) {
        printf("Digite a posição e o nome do piloto %d: ", i + 1);
        scanf("%d %s", &pilotos[i].posicao, pilotos[i].nome);
    }

    mergeSort(pilotos, 0, n - 1);

    printf("\nClassificação final:\n");
    for (int i = 0; i < n; i++) {
        printf("%d %s\n", pilotos[i].posicao, pilotos[i].nome);
    }

    free(pilotos);
    return 0;
}
