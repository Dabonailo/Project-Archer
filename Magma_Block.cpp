#include "Magma_Block.h"

namespace Entidades
{
    namespace Obstaculos
    {

        Magma_Block::Magma_Block(
            sf::Vector2f pos,
            sf::Vector2f tam,
            const std::string& textura,
            sf::Vector2f vel,
            bool d,
            float emp)

            : Obstaculo(pos, tam, textura, vel, d, emp)
        {
            yOriginal = pos.y;
            yLimite = pos.y + 120.f;

            velocidadeMovimento = 80.f;

            jogadorEmCima = false;

            cooldownDano = 0.f;
            tempoSemJogador = 0.f;
        }

        Magma_Block::~Magma_Block()
        {
        }

        void Magma_Block::obstaculizar(Personagens::Personagem* p)
        {
            if (!p)
                return;

            //--------------------------------
            // DANO CONTÍNUO
            //--------------------------------

            if (cooldownDano <= 0.f)
            {
                p->recebeDano(1);
                cooldownDano = 0.35f;
            }

            //--------------------------------
            // COLISÃO
            //--------------------------------

            sf::Vector2f posPlat = getPosicao();
            sf::Vector2f posJog = p->getPosicao();

            sf::Vector2f tamPlat = getTamanho();
            sf::Vector2f tamJog = p->getTamanho();

            float dx = posJog.x - posPlat.x;
            float dy = posJog.y - posPlat.y;

            float overlapX =
                (tamJog.x / 2.f + tamPlat.x / 2.f) - abs(dx);

            float overlapY =
                (tamJog.y / 2.f + tamPlat.y / 2.f) - abs(dy);

            if (overlapX < overlapY)
            {
                //-------------------------
                // lateral
                //-------------------------

                if (dx > 0)
                {
                    p->setPosicao(sf::Vector2f(
                        posPlat.x + tamPlat.x / 2.f + tamJog.x / 2.f,
                        posJog.y));
                }
                else
                {
                    p->setPosicao(sf::Vector2f(
                        posPlat.x - tamPlat.x / 2.f - tamJog.x / 2.f,
                        posJog.y));
                }

                p->setVelocidade(
                    sf::Vector2f(
                        0.f,
                        p->getVelocidade().y));
            }
            else
            {
                //-------------------------
                // vertical
                //-------------------------

                if (dy > 0)
                {
                    // bateu por baixo

                    p->setPosicao(sf::Vector2f(
                        posJog.x,
                        posPlat.y + tamPlat.y / 2.f + tamJog.y / 2.f));
                }
                else
                {
                    // pisou em cima

                    jogadorEmCima = true;
                    tempoSemJogador = 0.f;

                    p->setPosicao(sf::Vector2f(
                        posJog.x,
                        posPlat.y - tamPlat.y / 2.f - tamJog.y / 2.f));

                    p->setnoChao(true);
                }

                p->setVelocidade(
                    sf::Vector2f(
                        p->getVelocidade().x,
                        0.f));
            }
        }

        void Magma_Block::executar()
        {
            if (cooldownDano > 0.f)
                cooldownDano -= getTempo();

            //--------------------------------
            // DESCE
            //--------------------------------

            if (jogadorEmCima)
            {
                if (getPosicao().y < yLimite)
                {
                    body.move(
                        0.f,
                        velocidadeMovimento * getTempo());
                }
            }
            else
            {
                tempoSemJogador += getTempo();

                //--------------------------------
                // SOBE APÓS 0.5s
                //--------------------------------

                if (tempoSemJogador > 0.5f)
                {
                    if (getPosicao().y > yOriginal)
                    {
                        body.move(
                            0.f,
                            -velocidadeMovimento * getTempo());

                        if (getPosicao().y < yOriginal)
                        {
                            body.setPosition(
                                getPosicao().x,
                                yOriginal);
                        }
                    }
                }
            }

            desenhar();

            // prepara para o próximo frame
            jogadorEmCima = false;
        }

    }
}