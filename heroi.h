#ifndef HEROI_H
#define HEROI_H

// Declaração opaca (tipo incompleto)
typedef struct Heroi Heroi;

/*
 * Função: alocar_herois
 * ---------------------
 * Aloca dinamicamente um vetor de heróis.
 *
 * qtd: número de heróis desejado
 *
 * retorna: ponteiro para o vetor alocado
 */
Heroi* alocar_herois(int qtd);

/*
 * Função: ler_herois
 * ------------------
 * Lê do teclado os dados de cada herói.
 *
 * vetor: vetor de heróis
 * qtd: quantidade de heróis
 */
void ler_herois(Heroi* vetor, int qtd);

/*
 * Função: imprimir_herois
 * -----------------------
 * Exibe os dados dos heróis na tela.
 *
 * vetor: vetor de heróis
 * qtd: quantidade de heróis
 */
void imprimir_herois(Heroi* vetor, int qtd);

#endif
