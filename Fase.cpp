#include "Fase.h"

namespace Fases {
	Fase::Fase():ListaEntFase(), GC(){}

	Fase::~Fase() {}

	Listas::ListaEntidades* Fase::getListaEntFase()
	{
		return &ListaEntFase;
	}

	void Fase::desenhar() {
		ListaEntFase.desenharLista();
	}


}
