#include <stdio.h>
#include <stdlib.h>

// Definição da struct para armazenar os dados de cada personagem
typedef struct {
    int id;
    char nome[50];
    int forca;
    int agilidade;
    int inteligencia;
} Personagem;

// Função de busca linear
int buscarPersonagem(Personagem personagens[], int n, int idBuscado) {
    for (int i = 0; i < n; i++) {
        if (personagens[i].id == idBuscado) {
            return i; // Retorna a posição do personagem encontrado
        }
    }
    return -1; // Retorna -1 se o personagem não for encontrado
}

int main() {
    int n;

    printf("=== Cadastro de Personagens ===\n");
    printf("Digite o número total de personagens: ");
    scanf("%d", &n);

    // Alocando vetor de personagens
    Personagem *personagens = (Personagem *)malloc(n * sizeof(Personagem));
    if (personagens == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Leitura dos dados dos personagens
    for (int i = 0; i < n; i++) {
        printf("\nPersonagem %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &personagens[i].id);
        printf("Nome: ");
        scanf("%s", personagens[i].nome);
        printf("Força: ");
        scanf("%d", &personagens[i].forca);
        printf("Agilidade: ");
        scanf("%d", &personagens[i].agilidade);
        printf("Inteligência: ");
        scanf("%d", &personagens[i].inteligencia);
    }

    // Menu de consulta
    int opcao;
    while (1) {
        printf("\n=== Menu ===\n");
        printf("1 - Consultar Personagem\n");
        printf("2 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int idBuscado;
            printf("Digite a ID do personagem: ");
            scanf("%d", &idBuscado);

            int pos = buscarPersonagem(personagens, n, idBuscado);

            if (pos != -1) {
                float media = (personagens[pos].forca +
                               personagens[pos].agilidade +
                               personagens[pos].inteligencia) / 3.0;

                printf("\nPersonagem encontrado!\n");
                printf("Nome: %s\n", personagens[pos].nome);
                printf("Média de Atributos: %.2f\n", media);
            } else {
                printf("\nPersonagem não encontrado.\n");
            }
        } 
        else if (opcao == 2) {
            printf("Encerrando o programa...\n");
            break;
        } 
        else {
            printf("Opção inválida! Tente novamente.\n");
        }
    }

    // Libera a memória alocada
    free(personagens);

    return 0;
}
