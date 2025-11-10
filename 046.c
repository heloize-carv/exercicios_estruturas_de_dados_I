#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int nivel;
    int highScore;
} PlayerProfile;

int main() {
    FILE *arquivo = fopen("profiles.dat", "rb"); // leitura binária
    if (!arquivo) {
        printf("Erro: arquivo profiles.dat nao encontrado!\n");
        return 1;
    }

    PlayerProfile jogador;

    // lê enquanto houver structs no arquivo
    while (fread(&jogador, sizeof(PlayerProfile), 1, arquivo) == 1) {
        printf("Nome: %s | Nivel: %d | HighScore: %d | Rank: ", 
               jogador.nome, jogador.nivel, jogador.highScore);

        if (jogador.highScore > 10000) {
            printf("Mestre do Jogo\n");
        } else if (jogador.highScore > 5000) {
            printf("Veterano\n");
        } else {
            printf("Aspirante\n");
        }
    }

    fclose(arquivo);
    return 0;
}
