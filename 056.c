#include <stdio.h>

// Função recursiva que calcula o dano total
int danoTotal(int nivel) {
    // Caso base: se o nível for 1, o dano é 1
    if (nivel == 1) {
        return 1;
    } 
    // Passo recursivo: soma o nível atual com o dano total dos níveis anteriores
    else {
        return nivel + danoTotal(nivel - 1);
    }
}

int main() {
    int nivel;
    
    printf("Digite o nivel do mago: ");
    scanf("%d", &nivel);
    
    // Chama a função e exibe o resultado
    int resultado = danoTotal(nivel);
    printf("Dano total do Ataque em Cascata: %d\n", resultado);
    
    return 0;
}
