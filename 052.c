#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} Unidade;

int main() {
    int n, i, j, contador = 0;
    float raio, distancia;

    printf("Digite o numero de unidades inimigas: ");
    scanf("%d", &n);

    // Alocação dinâmica do vetor
    Unidade *inimigos = (Unidade *) malloc(n * sizeof(Unidade));
    if (inimigos == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    // Leitura das coordenadas
    for (i = 0; i < n; i++) {
        printf("Digite as coordenadas do inimigo %d (x y): ", i + 1);
        scanf("%d %d", &inimigos[i].x, &inimigos[i].y);
    }

    printf("Digite o raio de explosao: ");
    scanf("%f", &raio);

    // Comparação entre todos os pares (tempo quadrático O(n²))
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            distancia = sqrt(pow(inimigos[j].x - inimigos[i].x, 2) +
                             pow(inimigos[j].y - inimigos[i].y, 2));
            if (distancia <= raio) {
                contador++;
            }
        }
    }

    printf("Total de duplas proximas: %d\n", contador);

    free(inimigos);
    return 0;
}
