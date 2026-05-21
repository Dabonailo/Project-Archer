#pragma once
#include <vector>
#include "ListaEntidades.h"
#include "Jogador.h"
#include "Inimigo.h"

class GerenciadorColisoes
{
private:
	Jogador* jogador1;
	Jogador* jogador2;
	std::vector<Inimigo*> LIs;

public:
	GerenciadorColisoes();
	~GerenciadorColisoes();

	const int getTamanhoLIs() const;

	const bool verificarColisao(Entidade* pE1, Entidade* pE2) const;

	void incluirJogadores(Jogador* pJ);
	void incluirInimigo(Inimigo* pI);

	void tratarColisoesJogsInimigs();

	void executar();

};