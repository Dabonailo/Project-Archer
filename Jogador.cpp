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
            : Personagem(pos, tam, textura, v),
            tempoInvulneravel(0.f)
        {
            texturaEntidade.loadFromFile(textura);
            body.setTexture(&texturaEntidade);

            body.setOrigin(
                body.getSize().x / 2.f,
                body.getSize().y / 2.f
            );

            direcao = sf::Vector2f(1.f, 1.f);

            noChao = false;

            velocidade = sf::Vector2f(0.f, 0.f);
            velocidadeKnockback = sf::Vector2f(0.f, 0.f);

            cooldownKnockback = 0.f;
        }

        Jogador::~Jogador()
        {
        }

        const float Jogador::getTempoInvulneravel() const
        {
            return tempoInvulneravel;
        }

        void Jogador::setTempoInvulneravel(float t)
        {
            tempoInvulneravel = t;
        }

        void Jogador::mover()
        {
            velocidade.x = 0.f;

            //if (cooldownKnockback > 0.f)
               // return;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                velocidade.x = JOG_VELOCIDADE_DEFAULT_X;

                body.setScale(1.f, 1.f);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                velocidade.x = -JOG_VELOCIDADE_DEFAULT_X;

                body.setScale(-1.f, 1.f);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && noChao)
            {
                velocidade.y = -FORCA_PULO;

                noChao = false;
            }
        }

        void Jogador::executar()
        {
            mover();
            gravitar();

            body.move(
                velocidade.x + velocidadeKnockback.x,
                velocidade.y + velocidadeKnockback.y
            );

            velocidadeKnockback *= 0.995f;

            if (cooldownKnockback > 0.f)
                cooldownKnockback -= 0.016f;

            if (tempoInvulneravel > 0.f)
                tempoInvulneravel -= 0.016f;

            desenhar();
        }

    }
}