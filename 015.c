#include <stdio.h>
#include <locale.h>
#include <string.h>

// O Nome e o Título do Herói

int main () {
    setlocale(LC_ALL, "Portuguese_Brazil");

    char nome_jogador[50];
    char titulo_conquistado[50];

    printf("Digite o nome do herói: ");
    scanf("%49s", nome_jogador); // evita overflow

    printf("Digite o título conquistado: ");
    scanf("%49s", titulo_conquistado);

    // Adiciona espaço após o nome
    strcat(nome_jogador, " ");

    // Junta o título ao final do nome
    strcat(nome_jogador, titulo_conquistado);

    // Mostra resultado
    printf("O herói agora é conhecido como: %s\n", nome_jogador);

    return 0;
}
