#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct {
    char nome[50];
    int pontuacao;
} Jogador;

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    int n;
    printf("Digite o número de jogadores: ");
    scanf("%d", &n);

    Jogador jogadores[n];

    // Leitura dos dados dos jogadores
    for (int i = 0; i < n; i++) {
        printf("Digite o nome do jogador %d: ", i + 1);
        scanf(" %49[^\n]", jogadores[i].nome); // Lê até 49 caracteres, incluindo espaços
        printf("Digite a pontuação de %s: ", jogadores[i].nome);
        scanf("%d", &jogadores[i].pontuacao);
    }

    // Encontrar o jogador com a maior pontuação
    Jogador recordista = jogadores[0];
    for (int i = 1; i < n; i++) {
        if (jogadores[i].pontuacao > recordista.pontuacao) {
            recordista = jogadores[i];
        }
    }

    // Abrir arquivo para escrita
    FILE *arquivo = fopen("../highscore.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }

    // Escrever o recordista no arquivo
    fprintf(arquivo, "Nome: %s, Pontuacao: %d\n", recordista.nome, recordista.pontuacao);

    fclose(arquivo);

    printf("Recorde salvo no arquivo highscore.txt com sucesso!\n");

    return 0;
}
