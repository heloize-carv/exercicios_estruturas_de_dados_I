#include <stdio.h>
#include <locale.h>

// A plataforma secreta e o tesouro

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    // Variável que representa o local do tesouro
    int tesouro_local = 0;

    // Ponteiro que representa a plataforma secreta
    int *plataforma_secreta = &tesouro_local;

    // Verificação inicial
    printf("O tesouro ainda não apareceu. Valor: %d\n", tesouro_local);

    // Ativando o tesouro (alterando o valor através do ponteiro)
    *plataforma_secreta = 1;

    // Verificação final
    printf("O personagem pisou na plataforma secreta! ");
    printf("O tesouro apareceu! Valor: %d\n", tesouro_local);

    return 0;
}