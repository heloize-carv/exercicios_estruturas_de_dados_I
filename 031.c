#include <stdio.h>
#include <locale.h>

// Coletável de Pontuação no Jogo

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    // Definição do tipo Coletavel usando typedef struct
    typedef struct {
        int pontos;
        float pos_x;
        float pos_y;
    } Coletavel;

    // Declaração da variável do tipo Coletavel
    Coletavel gema_rara;

    // Entrada de dados
    printf("Digite o valor em pontos da gema rara: ");
    scanf("%d", &gema_rara.pontos);

    printf("Digite a posição X da gema rara: ");
    scanf("%f", &gema_rara.pos_x);

    printf("Digite a posição Y da gema rara: ");
    scanf("%f", &gema_rara.pos_y);

    // Saída formatada
    printf("Coletável criado! Valor: %d pontos. Posição: (X=%.2f, Y=%.2f)\n",
           gema_rara.pontos, gema_rara.pos_x, gema_rara.pos_y);

    return 0;
}
