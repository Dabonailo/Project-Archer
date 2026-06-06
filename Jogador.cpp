#include "Jogador.h"

namespace Entidades
{
    namespace Personagens
    {

        Jogador::Jogador(
            sf::Vector2f pos,
            sf::Vector2f tam,
            const std::string& textura,
            sf::Vector2f v
        )
            : Personagem(pos, tam, textura, v), movDir(false), movEsq(false)
        {
            texturaEntidade.loadFromFile(textura);
            body.setTexture(&texturaEntidade);

            body.setOrigin(
                body.getSize().x / 2.f,
                body.getSize().y / 2.f
            );

            noChao = false;

            velocidade = sf::Vector2f(0.f, 0.f);
            velocidadeKnockback = sf::Vector2f(0.f, 0.f);
        }

        Jogador::~Jogador()
        {
        }

        void Jogador::setMovDir(bool b)
        {
            movDir = b;
        }

        void Jogador::setMovEsq(bool b) {
            movEsq = b;
        }

        void Jogador::mover()
        {
            if (cooldownKnockback > 0.f)
                return;

            // ATRITO
            if (!movDir && !movEsq)
            {
                if (velocidade.x > 0.f)
                {
                    velocidade.x -= ATRITO * getTempo();
                    if (velocidade.x < 0.f) velocidade.x = 0.f;
                }
                else if (velocidade.x < 0.f)
                {
                    velocidade.x += ATRITO * getTempo();
                    if (velocidade.x > 0.f) velocidade.x = 0.f;
                }
            }

            // MOVIMENTO
            if (movDir)
            {
                velocidade.x += JOG_ACELERACAO;
                if (velocidade.x > JOG_VELOCIDADE_MAX)
                    velocidade.x = JOG_VELOCIDADE_MAX;

                body.setScale(1.f, 1.f);
            }

            if (movEsq)
            {
                velocidade.x -= JOG_ACELERACAO;
                if (velocidade.x < -JOG_VELOCIDADE_MAX)
                    velocidade.x = -JOG_VELOCIDADE_MAX;

                body.setScale(-1.f, 1.f);
            }
        }

        void Jogador::pular()
        {
            if (tempoNoChao > 0.f)
            {
                velocidade.y = -FORCA_PULO;
                tempoNoChao = 0.f;
                noChao = false;
            }
        }

        void Jogador::executar()
        {
            if (noChao)
                tempoNoChao = 0.1f; // 100 ms
            else if (tempoNoChao > 0.f)
                tempoNoChao -= getTempo();

            mover();
            gravitar();

            body.move(
                (velocidade.x + velocidadeKnockback.x) * getTempo(),
                (velocidade.y + velocidadeKnockback.y) * getTempo()
            );

            velocidadeKnockback *= 0.995f;

            if (tempoInvulneravel > 0.f)
                tempoInvulneravel -= getTempo();

            if (cooldownKnockback > 0.f)
                cooldownKnockback -= getTempo();

            desenhar();
        }

    }
}