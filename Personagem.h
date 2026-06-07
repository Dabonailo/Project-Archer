#pragma once
#include "Entidade.h"
#include "direcao.h"

#define KNOCKBACK_X 550.f
#define KNOCKBACK_Y 200.f
#define FORCA_PULO 650.f

namespace Entidades
{
    namespace Personagens
    {

        class Personagem :
            public Entidade
        {
        protected:
            int numVidas;

            sf::Vector2f velocidadeKnockback;
            float cooldownKnockback;

            bool esquerda;
            bool direita;

            float tempoNoChao;

            float tempoInvulneravel;

        public:
            Personagem(sf::Vector2f pos, sf::Vector2f tam, const std::string& textura, sf::Vector2f v);
            ~Personagem();

            const int getVida() const;

            const bool getVivo() const;

            void aplicarKnockback(sf::Vector2f forca);

            void recebeDano(int dano);

            virtual void mover() = 0;                                                   

            virtual void executar() = 0;

            const float getTempoInvulneravel() const;

            void setTempoInvulneravel(float t);

            void setDirecao(Direcao d);
            Direcao getDirecao();

        };
    }
}
