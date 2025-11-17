#include <stdio.h>
#include "combate.h"

int main() {
    int ataque_base, bonus, vida_inimigo;

    scanf("%d %d %d", &ataque_base, &bonus, &vida_inimigo);

    int ataque_total = calcular_ataque_total(ataque_base, bonus);
    int vida_restante = aplicar_dano(vida_inimigo, ataque_total);

    printf("Ataque total: %d\n", ataque_total);
    printf("Vida restante do inimigo: %d\n", vida_restante);

    return 0;
}
