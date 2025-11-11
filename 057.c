#include <stdio.h>

// Função recursiva para contar cristais carregados
int contarPositivos(int vetor[], int tamanho, int indice) {
    // Caso base: chegou ao fim do vetor
    if (indice == tamanho)
        return 0;

    // Passo recursivo: soma 1 se o atual for positivo + chama o próximo
    if (vetor[indice] > 0)
        return 1 + contarPositivos(vetor, tamanho, indice + 1);
    else
        return contarPositivos(vetor, tamanho, indice + 1);
}

int main() {
    int n;
    
    printf("Digite o numero de cristais: ");
    scanf("%d", &n);

    int cristais[n];

    // Leitura dos níveis de carga
    printf("Digite os niveis de carga dos cristais:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &cristais[i]);
    }

    // Chamada recursiva inicial
    int total = contarPositivos(cristais, n, 0);

    printf("Quantidade de cristais carregados: %d\n", total);

    return 0;
}
