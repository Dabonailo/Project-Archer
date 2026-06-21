#include "Dragao.h"

namespace Entidades
{
    namespace Personagens
    {
        Dragao::Dragao(
            sf::Vector2f pos,
            sf::Vector2f tam,
            const std::string& textura,
            sf::Vector2f v,
            float e,
            int n,
            int nm,
            int _id)

            : Inimigo(pos, tam, textura, v, e, n, nm, _id),
            delay_troca_direcao(3.f),
			direcao(1)
        {
        }

        Dragao::~Dragao()
        {
        }

        void Dragao::danificar(Jogador* p)
        {
            if (p->getTempoInvulneravel() <= 0.f)
            {
                p->recebeDano(10 * nivel_maldade);

                p->aplicarQueimadura(5.f, 2);

                if (p->getBounds().left < getBounds().left)
                {
                    p->aplicarKnockback(sf::Vector2f(-KNOCKBACK_X, 0.f));
                    p->setVelocidade(sf::Vector2f(0.f, -KNOCKBACK_Y));
                }
                else
                {
                    p->aplicarKnockback(sf::Vector2f(KNOCKBACK_X, 0.f));
                    p->setVelocidade(sf::Vector2f(0.f, -KNOCKBACK_Y));
                }

                p->setTempoInvulneravel(2.f);
            }
        }

        void Dragao::mover()
        {
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

                    if (dx < 0.f)
                        dx = -dx;

                    if (dy < 0.f)
                        dy = -dy;

                    if (dx <= RANGE_INIM_MEDIO_X &&
                        dy <= RANGE_INIM_MEDIO_Y)
                    {
                        perseguir(pJog);
                        achou = true;
                    }
                }

                atual = atual->getProximo();
            }

            if (!achou)
            {
                movimentoAleatorio();
            }
        }

        void Dragao::perseguir(Jogador* pJog)
        {
            if (!pJog)
                return;

            if (pJog->getPosicao().x > getPosicao().x)
            {
                velocidade.x = INIMIGO_MEDIO_VELOCIDADE_X;
                body.setScale(1.f, 1.f);
            }
            else
            {
                velocidade.x = -INIMIGO_MEDIO_VELOCIDADE_X;
                body.setScale(-1.f, 1.f);
            }

            velocidade.y = 0.f;
        }

        void Dragao::movimentoAleatorio()
        {
            velocidade.x = direcao * INIMIGO_MEDIO_VELOCIDADE_X;
            velocidade.y = 0.f;

            if (direcao > 0)
                body.setScale(1.f, 1.f);
            else
                body.setScale(-1.f, 1.f);

            delay_troca_direcao -= getTempo();

            if (delay_troca_direcao <= 0.f)
            {
                direcao *= -1;
                delay_troca_direcao = 3.f;
            }
        }

        void Dragao::executar()
        {
            mover();

            body.move(
                velocidade.x * getTempo(),
                velocidade.y * getTempo());

            desenhar();
        }
        
        void Dragao::salvarDataBuffer()
        {
            Inimigo::salvarDataBuffer();

            buffer << delay_troca_direcao << ' '
                << direcao << ' '
                << std::endl;
        }

        void Dragao::salvar()
        {
            bufferInterno.str("");
            buffer.clear();
            salvarDataBuffer();
        }

        void Dragao::carregar(std::istream& in)
        {
            Inimigo::carregar(in);

            in >> delay_troca_direcao;
            in >> direcao;
        }
    }
}