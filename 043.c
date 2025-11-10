#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct {
    char nome[50];
    int vida;
    int ataque;
} Inimigo;

int main() {
    setlocale(LC_ALL, ""); // Para suportar acentuação

    FILE *arquivo;
    Inimigo inimigo, maisForte;
    int primeiro = 1; // Flag para identificar o primeiro inimigo lido

    // Tenta abrir o arquivo para leitura
    arquivo = fopen("wave_data.txt", "r");
    if (arquivo == NULL) {
        printf("Erro: Arquivo wave_data.txt nao encontrado!\n");
        return 1;
    }

    // Lê cada inimigo do arquivo até EOF
    while (fscanf(arquivo, "%s %d %d", inimigo.nome, &inimigo.vida, &inimigo.ataque) != EOF) {
        if (primeiro) {
            // Inicializa o mais forte com o primeiro inimigo
            maisForte = inimigo;
            primeiro = 0;
        } else if (inimigo.ataque > maisForte.ataque) {
            maisForte = inimigo; // Atualiza se encontrar inimigo mais forte
        }
    }

    fclose(arquivo);

    // Exibe o inimigo com maior ataque
    printf("Maior Ameaça: %s, Vida: %d, Ataque: %d\n",
           maisForte.nome, maisForte.vida, maisForte.ataque);

    return 0;
}