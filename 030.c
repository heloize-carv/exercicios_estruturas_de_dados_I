#include <stdio.h>
#include <string.h>
#include <locale.h>

// Criando o Personagem do Jogo

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    // Definição da estrutura
    struct Jogador {
        char nome[50];
        int vidas;
        int pontuacao;
    };

    // Declaração da variável do tipo Jogador
    struct Jogador player1;

    // Inicialização dos atributos
    player1.vidas = 3;
    player1.pontuacao = 0;

    // Variável temporária para armazenar o nome digitado
    char nome_digitado[50];

    // Solicita o nome ao usuário
    printf("Digite o nome do seu personagem: ");
    scanf("%49s", nome_digitado); // Limita a leitura a 49 caracteres para evitar overflow

    // Copia o nome digitado para a estrutura
    strcpy(player1.nome, nome_digitado);

    // Exibe mensagem de confirmação
    printf("Personagem criado! Bem-vindo, %s! Vidas: %d, Pontuação: %d\n",
           player1.nome, player1.vidas, player1.pontuacao);

    return 0;
}
