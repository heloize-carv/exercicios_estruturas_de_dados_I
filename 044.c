#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int pontos;
} Conquista;

int main() {
    FILE *arquivo;
    int N, i, total_pontos = 0;

    // Abre o arquivo em modo leitura e escrita ("r+")
    arquivo = fopen("player_log.txt", "r+");
    if (arquivo == NULL) {
        printf("Erro: Arquivo player_log.txt nao encontrado!\n");
        return 1;
    }

    // Lê a quantidade de conquistas
    fscanf(arquivo, "%d", &N);

    Conquista c;

    // Lê cada conquista e soma os pontos
    for (i = 0; i < N; i++) {
        fscanf(arquivo, "%d %d", &c.id, &c.pontos);
        total_pontos += c.pontos;
    }

    printf("Total de pontos ganhos na sessao: %d\n", total_pontos);

    // Posiciona o ponteiro no final do arquivo para escrever
    fseek(arquivo, 0, SEEK_END);

    // Acrescenta a mensagem de sessão concluída
    fprintf(arquivo, "\n--- SESSION CONCLUDED ---\n");

    fclose(arquivo);

    return 0;
}
