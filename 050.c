#include <stdio.h>

int main() {
    float forcaBase, bonusArma, bonusFeitico, danoTotal;

    printf("Digite a forca base do personagem: ");
    scanf("%f", &forcaBase);

    printf("Digite o bonus de dano da arma: ");
    scanf("%f", &bonusArma);

    printf("Digite o bonus do feitico: ");
    scanf("%f", &bonusFeitico);

    danoTotal = forcaBase + bonusArma + bonusFeitico;

    printf("Dano total do personagem: %.2f\n", danoTotal);

    return 0;
}
