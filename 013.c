#include <stdio.h>
#include <string.h>
#include <locale.h>

// A Palavra Secreta da Porta Mágica

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    // Palavra secreta
    char palavra_secreta[] = "LUX";

    // Espaço para a tentativa do jogador
    char tentativa_jogador[50];

    // Solicita a palavra ao jogador
    printf("Uma voz ancestral ecoa... 'Diga a palavra e passe': ");
    scanf("%s", tentativa_jogador);  // Lê até o primeiro espaço

    // Compara a palavra secreta com a tentativa
    if (strcmp(palavra_secreta, tentativa_jogador) == 0) {
        printf("A porta mágica se abre!\n");
    } else {
        printf("Nada acontece... Parece que a palavra está incorreta.\n");
    }

    return 0;
}
