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
            : Personagem(pos, tam, textura, v)
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
        }

        Jogador::~Jogador()
        {
        }

        

        void Jogador::mover()
        {
            velocidade.x = 0.f;

            if (cooldownKnockback > 0.f)
                return;


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
				if (velocidade.x < JOG_VELOCIDADE_MAX) 
                    velocidade.x += JOG_ACELERACAO;

                body.setScale(1.f, 1.f);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                if (velocidade.x > -JOG_VELOCIDADE_MAX)
                    velocidade.x -= JOG_ACELERACAO;

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
                (velocidade.x + velocidadeKnockback.x) /** pGG->getTempo()*/,
                (velocidade.y + velocidadeKnockback.y) /** pGG->getTempo()*/
            );

            velocidadeKnockback *= 0.995f;

            if (tempoInvulneravel > 0.f)
                tempoInvulneravel -= pGG->getTempo();

            if (cooldownKnockback > 0.f)
                cooldownKnockback -= pGG->getTempo();

            desenhar();

			std::cout << getVelocidade().y << std::endl;    
        }

    }
}