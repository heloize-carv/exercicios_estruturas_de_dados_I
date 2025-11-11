#include <stdio.h>
#include <string.h>

#define MAX_NOME 50

// Estrutura que representa um monstro no bestiário
typedef struct {
    int id;
    char nome[MAX_NOME];
    int hp;
    int ataque;
} Monstro;

// Função de busca binária recursiva
int buscaBinariaRecursiva(Monstro monstros[], int idBuscado, int inicio, int fim) {
    if (inicio > fim) {
        return -1; // Caso base: não encontrado
    }

    int meio = (inicio + fim) / 2;

    if (monstros[meio].id == idBuscado) {
        return meio; // Monstro encontrado
    } 
    else if (idBuscado < monstros[meio].id) {
        // Busca na metade esquerda
        return buscaBinariaRecursiva(monstros, idBuscado, inicio, meio - 1);
    } 
    else {
        // Busca na metade direita
        return buscaBinariaRecursiva(monstros, idBuscado, meio + 1, fim);
    }
}

int main() {
    int N;
    printf("Digite o numero de monstros: ");
    scanf("%d", &N);

    Monstro monstros[N];

    // Leitura dos dados dos monstros (já ordenados por ID)
    for (int i = 0; i < N; i++) {
        printf("\nMonstro %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &monstros[i].id);
        printf("Nome: ");
        scanf(" %[^\n]", monstros[i].nome);
        printf("HP: ");
        scanf("%d", &monstros[i].hp);
        printf("Ataque: ");
        scanf("%d", &monstros[i].ataque);
    }

    int idBuscado;
    printf("\nDigite um ID para buscar (0 para sair): ");
    scanf("%d", &idBuscado);

    // Loop de busca
    while (idBuscado != 0) {
        int resultado = buscaBinariaRecursiva(monstros, idBuscado, 0, N - 1);

        if (resultado != -1) {
            printf("Monstro Encontrado: %s (ID: %d) - HP: %d, Ataque: %d\n",
                   monstros[resultado].nome,
                   monstros[resultado].id,
                   monstros[resultado].hp,
                   monstros[resultado].ataque);
        } else {
            printf("Monstro com ID %d nao encontrado.\n", idBuscado);
        }

        printf("\nDigite outro ID para buscar (0 para sair): ");
        scanf("%d", &idBuscado);
    }

    printf("\nEncerrando sistema de busca do Bestiario...\n");
    return 0;
}
