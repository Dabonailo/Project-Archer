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

	void operator()(Entidade* e) {
		if (Inimigo* in = dynamic_cast<Inimigo*>(e)) {
			incluirInimigo(in);
		}

		else if (Jogador* j = dynamic_cast<Jogador*>(e)) {
			if (jogador1 == NULL) {
				jogador1 = j;
			}
			else if (jogador2 == NULL){
				jogador2 = j;
			}
		}
		//adicionar mais tipos quando forem adicionados no GC
	}
	const int getTamanhoLIs() const;

	void setEntidades(ListaEntidades& l);

	const bool verificarColisao(Entidade* pE1, Entidade* pE2) const;

	void incluirInimigo(Inimigo* in);

	void tratarColisoesJogsInimigs();

	void executar();

};