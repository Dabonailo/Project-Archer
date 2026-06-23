#pragma once

#include "Obstaculo.h"
#include "Jogador.h"

namespace Entidades
{
    namespace Obstaculos
    {
        class Magma_Block : public Obstaculo
        {
        private:
            float yOriginal;
            float yLimite;

            float velocidadeMovimento;

            bool jogadorEmCima;

            float tempoSemJogador;

        public:
            Magma_Block(
                sf::Vector2f pos = sf::Vector2f(),
                sf::Vector2f tam = sf::Vector2f(35.f, 35.f),
                const std::string& textura = "magma.png",
                sf::Vector2f vel = sf::Vector2f(0.f, 0.f),
                bool d = false,
                float e = 0.f,
                int _id = 8
            );

            ~Magma_Block();

            void obstaculizar(Personagens::Personagem* p);

            void executar();
            void salvarDataBuffer();
            virtual void salvar();
            void carregar(std::istream& in);
        };
    }
}