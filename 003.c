#include <stdio.h>
#include <locale.h>

// O Portal de Teletransporte e as Coordenadas do Jogador

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    // 1. Variável de coordenada
    float coordenada_x;

    // 2. Ponteiro para coordenada
    float *ponteiro_x;

    // 3. Conecta o ponteiro à variável
    ponteiro_x = &coordenada_x;

    // 4. Lê a coordenada do usuário
    printf("Digite a coordenada X do portal: ");
    scanf("%f", &coordenada_x);

    // 5. Imprime o valor da coordenada usando o ponteiro
    printf("Posicao do portal no eixo X: %f\n", *ponteiro_x);

    // 6. Imprime o endereço de memória da coordenada
    printf("Endereco do portal para teletransporte: %p\n", (void *)ponteiro_x);

    return 0;
}
