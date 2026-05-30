#pragma once

#include "Personagem.h"
#include "Jogador.h"

namespace Entidades
{
    namespace Personagens
    {
        class Inimigo : public Personagem
        {
        protected:
            float cooldownMovimento;
            int movimento;

        public:
            Inimigo(sf::Vector2f pos, sf::Vector2f tam, const std::string& textura, sf::Vector2f v);

            ~Inimigo();

            virtual void danificar(Jogador* p) = 0;

            void setCooldownMovimento(float c);
            float getCooldownMovimento();

            void setMovimento(int m);
            int getMovimento();

            virtual void mover() = 0;

            virtual void executar() override;
        };

    }
}
