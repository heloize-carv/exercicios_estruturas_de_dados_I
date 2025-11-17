#include <stdio.h>
#include <stdlib.h>
#include "heroi.h"

int main() {
    int qtd;

    printf("Quantos heróis na equipe? ");
    scanf("%d", &qtd);

    Heroi* equipe = alocar_herois(qtd);

    ler_herois(equipe, qtd);

    imprimir_herois(equipe, qtd);

    free(equipe);
    return 0;
}
