#include "Bloco_Magma.h"

namespace Entidades
{
    namespace Obstaculos
    {

        Bloco_Magma::Bloco_Magma(
            sf::Vector2f pos,
            sf::Vector2f tam,
            const std::string& textura,
            sf::Vector2f vel,
            bool d,
            float e,
			int _id)

			: Obstaculo(pos, tam, textura, vel, d, e, _id)
        {
            yOriginal = pos.y;
            yLimite = pos.y + 120.f;

            velocidadeMovimento = 80.f;

            jogadorEmCima = false;

            tempoSemJogador = 0.f;
        }

        Bloco_Magma::~Bloco_Magma()
        {
        }

        void Bloco_Magma::obstaculizar(Personagens::Personagem* p)
        {
            if (!p)
                return;

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

                if (dy > 0)
                {

                    p->setPosicao(sf::Vector2f(
                        posJog.x,
                        posPlat.y + tamPlat.y / 2.f + tamJog.y / 2.f));
                }
                else
                {

                    if (Entidades::Personagens::Jogador* j = dynamic_cast<Entidades::Personagens::Jogador*>(p)) {
                        if (!j->getQueimando()) {
                            j->aplicarQueimadura(3.f, 2);
                        }
                    }

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

        void Bloco_Magma::executar()
        {

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
            jogadorEmCima = false;
        }

        void Bloco_Magma::salvarDataBuffer()
        {
            Obstaculo::salvarDataBuffer();

            buffer << yOriginal << ' '
                << yLimite << ' '

                << velocidadeMovimento << ' '

                << jogadorEmCima << ' '

                << tempoSemJogador << ' '
                << std::endl;
        }

        void Bloco_Magma::salvar()
        {
            bufferInterno.str("");
            buffer.clear();
            salvarDataBuffer();
		}

        void Bloco_Magma::carregar(std::istream& in)
        {
            Obstaculo::carregar(in);

            in >> yOriginal;
            in >> yLimite;
            in >> velocidadeMovimento;
            in >> jogadorEmCima;
            in >> tempoSemJogador;
        }
    }
}