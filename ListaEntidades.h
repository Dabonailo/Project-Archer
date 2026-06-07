#pragma once
#include "Entidade.h"
#include "Personagem.h"
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
		void percorrerLista();

		Lista<Entidades::Entidade>::Elemento<Entidades::Entidade>* getPrimeiro()
		{
			return LEs.getPrimeiro();
		}
	};
}
