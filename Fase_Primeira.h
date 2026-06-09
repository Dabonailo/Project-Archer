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
        Fase_Primeira(sf::Vector2f pos = sf::Vector2f(0.f, 0.f),
            sf::Vector2f tam = sf::Vector2f(0.f, 0.f),
            const std::string& textura = "Hanamura_fase1.png");

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

