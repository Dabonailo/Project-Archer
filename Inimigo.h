#pragma once

#include "Personagem.h"
#include "Jogador.h"
#include "ListaEntidades.h"
#include "math.h"

namespace Entidades
{
    namespace Personagens
    {
        class Inimigo : public Personagem
        {
        protected:
            float cooldownMovimento;
            int movimento;
			Listas::ListaEntidades* lJogs;
            int nivel_maldade;

        public:
            Inimigo(sf::Vector2f pos, sf::Vector2f tam, const std::string& textura, sf::Vector2f v, float e, int n, int nm);

            ~Inimigo();

            virtual void danificar(Jogador* p) = 0;

            void setCooldownMovimento(float c);
            float getCooldownMovimento();

            void recebeDano(int dano);

			virtual void perseguir(Jogador* pJog) = 0;
			virtual void movimentoAleatorio() = 0;
            void setMovimento(int m);
            int getMovimento();
			void setListaJogadores(Listas::ListaEntidades* lJ) { lJogs = lJ; }
            virtual void mover() = 0;

            virtual void executar() override;
        };

    }
}
