#include <stdio.h>
#include <locale.h>

// O Estado do Personagem no Jogo de Plataforma

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    // Definição da enum para os estados do personagem
    enum EstadoPersonagem { PARADO, CORRENDO, PULANDO };

    // Variável para armazenar o estado atual
    enum EstadoPersonagem estado_atual;

    int entrada;

    // Entrada do usuário
    printf("Digite o estado do personagem (0=PARADO, 1=CORRENDO, 2=PULANDO): ");
    scanf("%d", &entrada);

    // Atribuindo o valor digitado à variável do tipo enum
    estado_atual = entrada;

    // Verificação do estado
    if (estado_atual == PARADO) {
        printf("O personagem está parado.\n");
    } else if (estado_atual == CORRENDO) {
        printf("O personagem está correndo!\n");
    } else if (estado_atual == PULANDO) {
        printf("O personagem está pulando no ar!\n");
    } else {
        printf("Estado inválido!\n");
    }

    return 0;
}
