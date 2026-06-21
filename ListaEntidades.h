#pragma once
#include "Entidade.h"
#include "Personagem.h"
#include "Projetil.h"
#include "Lista.h"

namespace Listas
{
	class ListaEntidades
	{
	private:
		Lista<Entidades::Entidade> LEs;

	public:
		ListaEntidades();
		~ListaEntidades();

		void incluir(Entidades::Entidade* pE);
		void remover(Entidades::Entidade* e);
		void percorrerLista();
		void desenharLista();
		int getTamanho() const { return LEs.getTamanho(); }
		void salvarEntidades(int idFase, bool doisJogadores);
		void limparLista() { LEs.limpar(); }
				
		Lista<Entidades::Entidade>::Elemento<Entidades::Entidade>* getPrimeiro()
		{
			return LEs.getPrimeiro();
		}
	};
}
