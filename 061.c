#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int scores[N];
    for(int i = 0; i < N; i++) {
        scanf("%d", &scores[i]);
    }

    // Selection Sort
    for(int i = 0; i < N - 1; i++) {
        int min_idx = i;
        for(int j = i + 1; j < N; j++) {
            if(scores[j] < scores[min_idx]) {
                min_idx = j;
            }
        }
        int temp = scores[i];
        scores[i] = scores[min_idx];
        scores[min_idx] = temp;
    }

    // Imprimir vetor ordenado
    for(int i = 0; i < N; i++) {
        printf("%d", scores[i]);
        if(i != N - 1) printf(" ");
    }
    printf("\n");

    return 0;
}
