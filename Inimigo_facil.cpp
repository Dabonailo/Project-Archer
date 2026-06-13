#include "Inimigo_facil.h"

namespace Entidades
{
    namespace Personagens
    {

        Oni::Oni(
            sf::Vector2f pos,
            sf::Vector2f tam,
            const std::string& textura,
            sf::Vector2f v, float e, int n, int nm)

            :Inimigo(pos, tam, textura, v, e, n, nm), raio(250.f)
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

        void Oni::mover()
        {
            if (cooldownKnockback > 0.f)
                return;

            bool achou = false;

            Listas::Lista<Entidades::Entidade>::Elemento<Entidades::Entidade>* atual =
                lJogs->getPrimeiro();

            while (atual && !achou)
            {
                Jogador* pJog =
                    dynamic_cast<Jogador*>(atual->getInfo());

                if (pJog)
                {

                    float dx = pJog->getPosicao().x - getPosicao().x;
                    float dy = pJog->getPosicao().y - getPosicao().y;

                    float dist = sqrt(dx * dx + dy * dy);

                    if (dist <= raio)

                    {
                        perseguir(pJog);
                        achou = true;
                    }
                }

                atual = atual->getProximo();
            }

            if (!achou)
                movimentoAleatorio();
        }

        void Oni::perseguir(Jogador* pJog)
        {
            if (!pJog)
                return;

            if (pJog->getPosicao().x > getPosicao().x)
            {
                velocidade.x = INIMIGO_FACIL_VELOCIDADE_X;
                body.setScale(-1.f, 1.f);
            }
            else
            {
                velocidade.x = -INIMIGO_FACIL_VELOCIDADE_X;
                body.setScale(1.f, 1.f);
            }

            if (pJog->getPosicao().y < getPosicao().y - 40.f)
            {
                if (noChao)
                {
                    velocidade.y = -FORCA_PULO;
                    noChao = false;
                }
            }
        }

        void Oni::movimentoAleatorio()
        {
            if (cooldownMovimento <= 0.f) {
                movimento = rand() % 4 + 1;

                switch (movimento)
                {
                case 1:
                    velocidade.x = INIMIGO_FACIL_VELOCIDADE_X;
                    body.setScale(-1.f, 1.f);
                    setDirecao(DIREITA);
                    break;

                case 2:
                    velocidade.x = -INIMIGO_FACIL_VELOCIDADE_X;
                    body.setScale(1.f, 1.f);
                    setDirecao(ESQUERDA);
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

        void Oni::executar()
        {
            desenhar();
            mover();
            gravitar();
            body.move(
                (velocidade.x + velocidadeKnockback.x) * getTempo(),
                (velocidade.y + velocidadeKnockback.y) * getTempo()
            );

            velocidadeKnockback *= 0.995f;

            if (cooldownKnockback > 0.f)
                cooldownKnockback -= getTempo();

            if (cooldownMovimento > 0.f) {
                cooldownMovimento -= getTempo();
            }

            if (tempoInvulneravel > 0.f) {
                tempoInvulneravel -= getTempo();
            }

            //std::cout << tempoInvulneravel << std::endl;

        }
    }
}
