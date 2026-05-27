#include "Inimigo_facil.h"

namespace Entidades
{
    namespace Personagens
    {

        Inimigo_facil::Inimigo_facil(
            sf::Vector2f pos,
            sf::Vector2f tam,
            const std::string& textura,
            sf::Vector2f v)

            :Inimigo(pos, tam, textura, v), raio(0.f)
        {
        }

        Inimigo_facil::~Inimigo_facil()
        {
        }

        void Inimigo_facil::danificar(Jogador* p)
        {
            if (p->getTempoInvulneravel() <= 0.f) {
                p->operator--();

                if (p->getBounds().left < getBounds().left) {

                    p->aplicarKnockback(sf::Vector2f(-KNOCKBACK_X, 0.f));
                    p->setVelocidade(sf::Vector2f(0.f, -KNOCKBACK_Y));
                }
                else {

                    p->aplicarKnockback(sf::Vector2f(KNOCKBACK_X, 0.f));
                    p->setVelocidade(sf::Vector2f(0.f, -KNOCKBACK_Y));
                }

                p->setTempoInvulneravel(2.f);
            }
        }

        void Inimigo_facil::mover() {
            if (cooldownMovimento <= 0.f) {
                movimento = rand() % 4 + 1;

                switch(movimento)
                {
                case 1:
                    velocidade.x = INIMIGO_FACIL_VELOCIDADE_X;
                    break;

                case 2:
                    velocidade.x = -INIMIGO_FACIL_VELOCIDADE_X;
                    break;

                case 3:
                    if (noChao)
                    {
                        velocidade.y = -FORCA_PULO;
                        noChao = false;
                    }
                    break;

                case 4:
                    velocidade.x = 0.f;
                    break;
                }
                cooldownMovimento = 5.f;
            }
        }

        void Inimigo_facil::executar()
        {
            desenhar();
            mover();
            gravitar();
            body.move(velocidade.x /** pGG->getTempo()*/, velocidade.y /** pGG->getTempo()*/);

            if (cooldownMovimento > 0.f) {
                cooldownMovimento -= pGG->getTempo();
            }
        }
    }
}
