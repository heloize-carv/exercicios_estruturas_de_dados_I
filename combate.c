#include "combate.h"

int calcular_ataque_total(int ataque_base, int bonus) {
    return ataque_base + bonus;
}

int aplicar_dano(int vida_inimigo, int ataque_total) {
    int vida_restante = vida_inimigo - ataque_total;

    if (vida_restante < 0) {
        vida_restante = 0;
    }

    return vida_restante;
}
