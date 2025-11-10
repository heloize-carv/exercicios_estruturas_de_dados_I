#include <stdio.h>

int main() {
    int energia;

    printf("Digite o nivel de energia inicial do Golem: ");
    scanf("%d", &energia);

    printf("\nIniciando o Ritual de Diminuição Arcana...\n");

    while (energia > 1) {
        printf("Energia atual: %d\n", energia);
        energia = energia / 2;  // Reduz pela metade a cada pulso
    }

    printf("Energia final: %d\n", energia);
    printf("\nRitual concluido.\n");

    return 0;
}
