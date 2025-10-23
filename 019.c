#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Power-up de Salto Duplo

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    // Ponteiro para armazenar a altura do salto duplo (inicialmente sem habilidade)
    float *ponteiro_altura_salto_duplo = NULL;

    // Status inicial do jogador
    printf("Jogador ainda não possui o Salto Duplo.\n");

    // Simulando a coleta da "Pena Dourada"
    ponteiro_altura_salto_duplo = (float *) malloc(sizeof(float));

    // Verificação se a alocação foi bem-sucedida
    if (ponteiro_altura_salto_duplo != NULL) {
        // Atribuindo o valor da altura do salto duplo
        *ponteiro_altura_salto_duplo = 15.5;

        // Exibindo o novo status do jogador
        printf("Pena Dourada coletada! Altura do Salto Duplo: %.2f\n", *ponteiro_altura_salto_duplo);

        // Liberando a memória alocada
        free(ponteiro_altura_salto_duplo);
        // Em um jogo real, liberaríamos a memória quando o power-up não fosse mais necessário.
    } else {
        printf("Erro ao alocar memória para o Salto Duplo.\n");
    }

    return 0;
}
