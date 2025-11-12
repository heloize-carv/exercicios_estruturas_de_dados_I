#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;

    // Leitura do Portal Alfa
    scanf("%d", &n);
    int *alfa = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &alfa[i]);
    }

    // Leitura do Portal Beta
    scanf("%d", &m);
    int *beta = (int*) malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        scanf("%d", &beta[i]);
    }

    // Criação do vetor combinado
    int *combinado = (int*) malloc((n + m) * sizeof(int));
    int i = 0, j = 0, k = 0;

    // Intercalação
    while (i < n && j < m) {
        if (alfa[i] < beta[j]) combinado[k++] = alfa[i++];
        else combinado[k++] = beta[j++];
    }

    // Restante de Alfa
    while (i < n) combinado[k++] = alfa[i++];
    // Restante de Beta
    while (j < m) combinado[k++] = beta[j++];

    // Impressão
    for (int x = 0; x < n + m; x++) {
        printf("%d", combinado[x]);
        if (x < n + m - 1) printf(" ");
    }
    printf("\n");

    // Liberação da memória
    free(alfa);
    free(beta);
    free(combinado);

    return 0;
}
