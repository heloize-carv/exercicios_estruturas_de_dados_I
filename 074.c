#include <stdio.h>

void particao(int n, int v[]) {
    int pivo = v[n - 1];  // o pivô é o último elemento
    int i = 0;            // índice do menor elemento
    int j, temp;

    for (j = 0; j < n - 1; j++) {
        if (v[j] < pivo) {
            // troca v[i] e v[j]
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
        }
    }

    // coloca o pivô na posição correta
    temp = v[i];
    v[i] = v[n - 1];
    v[n - 1] = temp;
}

int main() {
    int n, i;
    scanf("%d", &n);

    int v[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    particao(n, v);

    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
