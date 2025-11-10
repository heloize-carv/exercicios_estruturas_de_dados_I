#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int vida;
    int ataque;
} Unidade;

int main() {
    int n;
    printf("Quantas unidades deseja incluir no esquadrão? ");
    scanf("%d", &n);

    Unidade *esquadrao = (Unidade*) malloc(n * sizeof(Unidade));
    if (esquadrao == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Unidade %d\n", i + 1);
        printf("Nome: ");
        scanf("%s", esquadrao[i].nome);
        printf("Vida (HP): ");
        scanf("%d", &esquadrao[i].vida);
        printf("Ataque (ATK): ");
        scanf("%d", &esquadrao[i].ataque);
    }

    FILE *arquivo = fopen("squad.dat", "wb");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo!\n");
        free(esquadrao);
        return 1;
    }

    fwrite(esquadrao, sizeof(Unidade), n, arquivo);
    fclose(arquivo);

    Unidade maisForte = esquadrao[0];
    for (int i = 1; i < n; i++) {
        if (esquadrao[i].ataque > maisForte.ataque) {
            maisForte = esquadrao[i];
        }
    }

    printf("Unidade com maior ATK: %s\n", maisForte.nome);

    free(esquadrao);
    return 0;
}
