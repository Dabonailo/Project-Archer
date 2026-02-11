#pragma once
#include <vector>
#include "Jogador.h"
#include "Inimigo.h"

class GerenciadorColisoes
{
private:
	Jogador* jogador;
	std::vector<Inimigo*> LIs;

public:
	GerenciadorColisoes();
	~GerenciadorColisoes();

	const bool verificarColisao(Entidade* pE1, Entidade* pE2) const;

	template <typename Container, typename Func>
	void verificaColisaoEntidades(Container& lista1, Container& lista2, Func func);

};

template<typename Container, typename Func>
inline void GerenciadorColisoes::verificaColisaoEntidades(Container& lista1, Container& lista2, Func func)
{
	for (auto& elemento1 : lista1) {
		for (auto& elemento2 : lista2) {
			if (this->verificarColisao(elemento1, elemento2)) {
				func(elemento1, elemento2);
			}
		}
	}
}
