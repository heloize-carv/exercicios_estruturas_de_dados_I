#include <stdio.h>

int main() {
    int n, i, j, temp;
    int trocou; // flag de controle

    scanf("%d", &n);
    int v[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    // Bubble Sort otimizado - ordem decrescente
    for (i = 0; i < n - 1; i++) {
        trocou = 0; // inicialmente nenhuma troca
        for (j = 0; j < n - i - 1; j++) {
            if (v[j] < v[j + 1]) { // ordem decrescente
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                trocou = 1; // houve troca
            }
        }
        if (trocou == 0) {
            break; // vetor já está ordenado
        }
    }

    // Saída do vetor ordenado
    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
