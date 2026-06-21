#pragma once
#include "Entidade.h"
#include "direcao.h"

#define KNOCKBACK_X 350.f
#define KNOCKBACK_Y 200.f
#define FORCA_PULO 680.f

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

			static int proximoUid;
			int uId;    

        public:
            Personagem(sf::Vector2f pos, sf::Vector2f tam, const std::string& textura, sf::Vector2f v, float e, int n, int _id);
            ~Personagem();

			void setUid(int id) { uId = id; }
            int getUid() const { return uId; }

            const int getVida() const;

            const bool getVivo() const;

            void aplicarKnockback(sf::Vector2f forca);

            virtual void atualizarCooldowns();

            virtual void recebeDano(int dano);

            virtual void mover() = 0;                                                   

            virtual void executar() = 0;

            const float getTempoInvulneravel() const;

            void setTempoInvulneravel(float t);

            void setDirecao(Direcao d);
            Direcao getDirecao();

			void salvarDataBuffer();
			virtual void salvar() = 0;
            virtual void carregar(std::istream& in);

        };
    }
}
