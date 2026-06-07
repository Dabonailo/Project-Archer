#pragma once
#include "Fase.h"
#include "Jogador.h"

namespace Fases
{

    class Fase_Primeira :
        public Fase
    {
    private:
        const int max_inimigos;


    public:
        Fase_Primeira();
        ~Fase_Primeira();

        void criarInimigos() override;
        void criarInimgosFaceis();
		void criarInimgosMedios();
        
        void criarObstaculos() override;
		void criarPlataformas();
		void criarEspinhos();

        void executar() override;
    };
}

