#include <stdio.h>
#include <locale.h>

// O Rastro de Moedas do Jogador

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    int moedas_coletadas[] = {10, 50, 20, 5, 100};
    int pontuacao_total = 0;
    int *ponteiro_moeda;

    // O ponteiro come�a no in�cio do vetor
    for (ponteiro_moeda = moedas_coletadas; ponteiro_moeda < moedas_coletadas + 5; ponteiro_moeda++) {
        pontuacao_total += *ponteiro_moeda; // soma o valor apontado
    }

    printf("Pontua��o total do n�vel: %d\n", pontuacao_total);

    return 0;
}

