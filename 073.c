#include <stdio.h>

void particao(int n, int v[]) {
    int s[n]; // vetor secundário
    int i, inicio = 0, fim = n - 1;
    int pivo = v[n - 1]; // último elemento é o pivô

    // percorre o vetor e separa conforme o pivô
    for (i = 0; i < n - 1; i++) {
        if (v[i] <= pivo) {
            s[inicio] = v[i];
            inicio++;
        } else {
            s[fim] = v[i];
            fim--;
        }
    }

    // adiciona o pivô na posição final correta
    s[inicio] = pivo;

    // copia o vetor secundário de volta para o original
    for (i = 0; i < n; i++) {
        v[i] = s[i];
    }
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
