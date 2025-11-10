#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    char nome[50];
    float hp;
    float atk;
} Inimigo;

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    FILE *arquivo;
    arquivo = fopen("inimigos.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    Inimigo inimigos[3];

    // Leitura dos dados do arquivo
    for (int i = 0; i < 3; i++) {
        fscanf(arquivo, "%s %f %f", inimigos[i].nome, &inimigos[i].hp, &inimigos[i].atk);
    }

    fclose(arquivo);

    printf("Inimigos elite:\n");
    for (int i = 0; i < 3; i++) {
        float nivel_ameaca = inimigos[i].hp + inimigos[i].atk;
        if (nivel_ameaca >= 200) {
            printf("Nome: %s | Nível de Ameaça: %.1f\n", inimigos[i].nome, nivel_ameaca);
        }
    }

    return 0;
}
