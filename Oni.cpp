#include "Oni.h"

namespace Entidades
{
    namespace Personagens
    {

        Oni::Oni(
            sf::Vector2f pos,
            sf::Vector2f tam,
            const std::string& textura,
            sf::Vector2f v, float e, int n, int nm)

            :Inimigo(pos, tam, textura, v, e, n, nm), forcaEmpurro(sf::Vector2f(400.f, 250.f))
        {
        }

        Oni::~Oni()
        {
        }

        void Oni::danificar(Jogador* p)
        {
            if (p->getTempoInvulneravel() <= 0.f) {
				p->recebeDano(5+nivel_maldade);

                if (p->getBounds().left < getBounds().left) {

                    p->aplicarKnockback(sf::Vector2f(-forcaEmpurro.x, 0.f));
                    p->setVelocidade(sf::Vector2f(0.f, -forcaEmpurro.y));
                }
                else {

                    p->aplicarKnockback(sf::Vector2f(forcaEmpurro.x, 0.f));
                    p->setVelocidade(sf::Vector2f(0.f, -forcaEmpurro.y));
                }

                p->setTempoInvulneravel(2.f);
            }
        }
       

        void Oni::atualizarCooldowns()
        {
            velocidadeKnockback *= 0.995f;

            if (cooldownKnockback > 0.f)
                cooldownKnockback -= getTempo();

            if (cooldownMovimento > 0.f) {
                cooldownMovimento -= getTempo();
            }

            if (tempoInvulneravel > 0.f) {
                tempoInvulneravel -= getTempo();
            }
        }

      

        void Oni::executar()
        {
            mover();
            gravitar();
            atualizarCooldowns();

            body.move(
                (velocidade.x + velocidadeKnockback.x) * getTempo(),
                (velocidade.y + velocidadeKnockback.y) * getTempo()
            );

            desenhar();
        }
    }
}
