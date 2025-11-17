#ifndef PERSONAGEM_H
#define PERSONAGEM_H

// Tipo opaco (main não vê os campos)
typedef struct personagem Personagem;

// Aloca memória para a party
Personagem* cria_party(int num_membros);

// Lê os dados de cada membro
void registra_membros(Personagem* party, int num_membros);

// Exibe todos os membros
void exibe_relatorio(const Personagem* party, int num_membros);

// Libera memória da party
void libera_party(Personagem* party);

#endif
