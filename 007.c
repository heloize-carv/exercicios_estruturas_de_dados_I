#include <stdio.h>
#include <locale.h>

// Posicionando um Power-up no Cenário

// Função que lê o cenário usando aritmética de ponteiros
void ler_cenario(int n, int *cenario) {
    for (int i = 0; i < n; i++) {
        printf("Digite o valor do bloco %d (0 = vazio, 1 = plataforma): ", i);
        scanf("%d", (cenario + i)); // aritmética de ponteiros
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    int n;

    // Lê o tamanho do cenário
    printf("Digite o número de blocos do cenário: ");
    scanf("%d", &n);

    // Declara o vetor do cenário
    int cenario[n];

    // Chama a função para preencher o cenário
    ler_cenario(n, cenario);

    // Substitui o primeiro bloco de plataforma (1) por um power-up (2)
    for (int i = 0; i < n; i++) {
        if (*(cenario + i) == 1) {   // acesso via aritmética de ponteiros
            *(cenario + i) = 2;
            break; // para ao encontrar o primeiro
        }
    }

    // Imprime o cenário modificado
    printf("\nCenário final: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(cenario + i)); // acesso via aritmética de ponteiros
    }
    printf("\n");

    return 0;
}