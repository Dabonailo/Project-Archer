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

                p->setTempoInvulneravel(1.f);
            }
        }

        void Inimigo_facil::mover() {
            body.move(velocidade);
        }

        void Inimigo_facil::executar()
        {
            desenhar();
            mover();
           gravitar();
        }
    }
}
