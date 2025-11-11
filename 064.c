#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int poder[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &poder[i]);
    }

    // Insertion Sort
    for(int i = 1; i < n; i++) {
        int key = poder[i];
        int j = i - 1;

        // Desloca elementos maiores que key para a direita
        while(j >= 0 && poder[j] > key) {
            poder[j + 1] = poder[j];
            j--;
        }

        // Insere key na posição correta
        poder[j + 1] = key;
    }

    // Imprimir vetor ordenado
    for(int i = 0; i < n; i++) {
        printf("%d", poder[i]);
        if(i != n - 1) printf(" ");
    }
    printf("\n");

    return 0;
}
