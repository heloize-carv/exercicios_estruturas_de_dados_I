#include <stdio.h>

// Função recursiva para calcular o dano bônus do Golpe Ecoante
int calcularDanoEco(int n) {
    if (n == 1)
        return 0; // Caso base: primeiro golpe não tem bônus
    else if (n == 2)
        return 1; // Caso base: segundo golpe tem bônus de 1
    else
        // Passo recursivo: soma dos dois golpes anteriores
        return calcularDanoEco(n - 1) + calcularDanoEco(n - 2);
}

int main() {
    int N;

    printf("Digite o numero do golpe na sequencia: ");
    scanf("%d", &N);

    int dano = calcularDanoEco(N);
    printf("Dano bonus do golpe %d: %d\n", N, dano);

    return 0;
}
