#include <stdio.h>

int main() {
    // Passo 1: vetor dos 5 melhores tempos já ordenados
    int placar[5] = {120, 125, 130, 142, 150};
    
    // Passo 2: ler o novo tempo
    int novo_tempo;
    scanf("%d", &novo_tempo);
    
    // Passo 3 e 4: inserir novo tempo na posição correta
    if (novo_tempo < placar[4]) { // só insere se for melhor que o último
        int i = 4;
        // deslocar os tempos maiores para a direita
        while (i > 0 && placar[i-1] > novo_tempo) {
            placar[i] = placar[i-1];
            i--;
        }
        // inserir o novo tempo na posição correta
        placar[i] = novo_tempo;
    }
    
    // Passo 6: imprimir o placar atualizado
    for(int i = 0; i < 5; i++) {
        printf("%d", placar[i]);
        if(i != 4) printf(" ");
    }
    printf("\n");
    
    return 0;
}
