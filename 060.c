#include <stdio.h>
#include <string.h>

// Cria um tipo Monstro com nome e HP
typedef struct {
    char nome[50];
    int hp;
} Monstro;

int main() {
    int n, i, indiceMenor;
    
    // Lê a quantidade de monstros
    printf("Digite a quantidade de monstros: ");
    scanf("%d", &n);
    
    Monstro monstros[n];
    
    // Lê os dados dos monstros
    for (i = 0; i < n; i++) {
        printf("Digite o nome e o HP do monstro %d: ", i + 1);
        scanf("%s %d", monstros[i].nome, &monstros[i].hp);
    }
    
    // Inicializa o índice do menor HP como o primeiro
    indiceMenor = 0;
    
    // Percorre o vetor para encontrar o menor HP
    for (i = 1; i < n; i++) {
        if (monstros[i].hp < monstros[indiceMenor].hp) {
            indiceMenor = i;
        }
    }
    
    // Exibe o resultado
    printf("Alvo prioritario: %s (%d HP)\n", monstros[indiceMenor].nome, monstros[indiceMenor].hp);
    
    return 0;
}
