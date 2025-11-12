#include <stdio.h>

// Função recursiva que implementa o paradigma de Divisão e Conquista
int encontraMax(int v[], int inicio, int fim) {
    // Caso base: apenas um elemento
    if (inicio == fim)
        return v[inicio];

    // Divisão
    int meio = (inicio + fim) / 2;

    // Conquista
    int max_esquerda = encontraMax(v, inicio, meio);
    int max_direita = encontraMax(v, meio + 1, fim);

    // Combinação
    if (max_esquerda > max_direita)
        return max_esquerda;
    else
        return max_direita;
}

int main() {
    int n;
    scanf("%d", &n);

    int v[n];

    // Leitura dos níveis de poder
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    // Chamada da função recursiva
    int maximo = encontraMax(v, 0, n - 1);

    // Saída: maior valor encontrado
    printf("%d\n", maximo);

    return 0;
}
