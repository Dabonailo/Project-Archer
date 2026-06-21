#pragma once
#define RANGE_INIMIGO 250.f
#define INIMIGO_VELOCIDADE_X 50.f

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
            Inimigo(sf::Vector2f pos, sf::Vector2f tam, const std::string& textura, sf::Vector2f v, float e, int n, int nm, int _id);

            ~Inimigo();

            virtual void danificar(Jogador* p) = 0;

            void setCooldownMovimento(float c);
            float getCooldownMovimento();

            void recebeDano(int dano);

            int getNivelMaldade();

            virtual void perseguir(Jogador* pJog);
            virtual void movimentoAleatorio();
            void setMovimento(int m);
            int getMovimento();
            void setListaJogadores(Listas::ListaEntidades* lJ) { lJogs = lJ; }
            virtual void mover();

            virtual void executar() = 0;
            void salvarDataBuffer();
            virtual void salvar() = 0;
            virtual void carregar(std::istream& in);
        };

    }
}
