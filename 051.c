#include <stdio.h>

// Definindo a struct para armazenar os dados do inimigo
typedef struct {
    char tipo[50];
    int hp;
} Inimigo;

int main() {
    int n;
    
    printf("Digite a quantidade de inimigos: ");
    scanf("%d", &n);

    Inimigo inimigos[n]; // cria um vetor com n inimigos

    for (int i = 0; i < n; i++) {
        printf("Digite o tipo e o HP do inimigo %d: ", i + 1);
        scanf("%s %d", inimigos[i].tipo, &inimigos[i].hp);
        printf("Inimigo: %s, HP: %d\n", inimigos[i].tipo, inimigos[i].hp);
    }

    return 0;
}
