#pragma once
#include "Fase.h"
#include "Jogador.h"
#include "Plataforma.h"

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

        void adicionarJogador(Entidades::Personagens::Jogador* p) override;
        void criarInimigos() override;
        void criarObstaculos() override;
        void criarInimgosFaceis();

        void executar() override;
    };
}

