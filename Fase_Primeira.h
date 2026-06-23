#pragma once
#include "Fase.h"

namespace Fases
{

    class Fase_Primeira :
        public Fase
    {
    private:
        const int maxInimMedios;


    public:
        Fase_Primeira(Entidades::Personagens::Jogador* pJ, Entidades::Personagens::Jogador* pJ2,
            sf::Vector2f pos = sf::Vector2f(0.f, 0.f),
            sf::Vector2f tam = sf::Vector2f(0.f, 0.f),
            const std::string& textura = "Hanamura_fase1.png",
            int _id = 1, bool carregando = false);

        ~Fase_Primeira();

        void criarInimigos() override;
        
		void criarDragoes();
        
        void criarObstaculos() override;
		
        void criarBlocosMagma();

        void criarProjeteis() override;

    };
}

