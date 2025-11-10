#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int nivel;
    float vida;
    float mana;
} Personagem;

int main() {
    int opcao;
    FILE *arquivo;

    do {
        printf("\n===== Menu =====\n");
        printf("1. Criar Novo Personagem\n");
        printf("2. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o \n do buffer do teclado

        if (opcao == 1) {
            Personagem p;

            // Solicita dados do usuário
            printf("Digite o nome do personagem: ");
            fgets(p.nome, sizeof(p.nome), stdin);
            p.nome[strcspn(p.nome, "\n")] = '\0'; // Remove o \n do fgets

            printf("Digite o nivel do personagem: ");
            scanf("%d", &p.nivel);
            printf("Digite a vida do personagem: ");
            scanf("%f", &p.vida);
            printf("Digite a mana do personagem: ");
            scanf("%f", &p.mana);
            getchar(); // Limpar o \n do buffer

            // Abre o arquivo em modo binário para escrita (sobrescreve existente)
            arquivo = fopen("savegame.sav", "wb");
            if (arquivo == NULL) {
                printf("Erro ao abrir o arquivo para escrita!\n");
                return 1;
            }

            // Grava a struct Personagem no arquivo
            fwrite(&p, sizeof(Personagem), 1, arquivo);

            // Fecha o arquivo
            fclose(arquivo);

            printf("Personagem salvo com sucesso!\n");
        }

    } while (opcao != 2);

    printf("Programa encerrado.\n");
    return 0;
}
