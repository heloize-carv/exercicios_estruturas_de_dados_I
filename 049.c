#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("level_1_map.dat", "r"); // tenta abrir o arquivo em modo leitura

    if (file == NULL) {
        // Mensagem amigável ao usuário
        printf("ERRO CRITICO: Nao foi possivel carregar os dados do mapa.\n");
        // Mensagem técnica do sistema (perror usa errno internamente)
        perror("Detalhes do erro");
        // Encerra o programa com código de erro
        exit(1);
    }

    // Se entrou aqui, o arquivo foi aberto com sucesso
    printf("Arquivo carregado com sucesso!\n");
    fclose(file);
    return 0;
}
