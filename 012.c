#include <stdio.h>
#include <string.h>
#include <locale.h>

// Validação do Nome do Personagem

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    char nome_jogador[50];

    printf("Digite um nome: ");
    // Lê uma linha inteira, incluindo espaços
    scanf("%[^\n]s", nome_jogador);

    // Verifica o tamanho do nome
    if (strlen(nome_jogador) <= 15) {
        printf("Nome valido! Bem-vindo ao jogo, %s!\n", nome_jogador);
    } else {
        printf("Nome muito longo! Por favor, escolha um nome com ate 15 caracteres.\n");
    }

    return 0;
}
