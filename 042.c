#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    int resolucao_x;
    int resolucao_y;
    float volume_som;
} Configuracao;

int main() {
    setlocale(LC_ALL, ""); // Ativa suporte a acentuação

    FILE *arquivo;
    Configuracao config;

    // Tenta abrir o arquivo config.txt em modo leitura
    arquivo = fopen("config.txt", "r");
    if (arquivo == NULL) {
        printf("Erro: Arquivo config.txt nao encontrado!\n");
        return 1; // Encerra o programa com erro
    }

    // Lê os valores do arquivo
    fscanf(arquivo, "%d %d %f", &config.resolucao_x, &config.resolucao_y, &config.volume_som);

    // Fecha o arquivo
    fclose(arquivo);

    // Exibe as configurações carregadas
    printf("Configuracoes carregadas:\n");
    printf("Resolucao: %dx%d\n", config.resolucao_x, config.resolucao_y);
    printf("Volume: %.1f\n", config.volume_som);

    return 0;
}

