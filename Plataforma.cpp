#include "Plataforma.h"

namespace Entidades
{
	namespace Obstaculos
	{
		
		Plataforma::Plataforma(sf::Vector2f pos, sf::Vector2f tam, const std::string& textura, sf::Vector2f v, bool d, float e, int _id)
			: Obstaculo(pos, tam, textura, v, d, e, _id), seMove(false),
            posOriginal(pos),
			direcao(1)
		{
		}
		Plataforma::~Plataforma()
		{
		}

        void Plataforma::obstaculizar(Entidades::Personagens::Personagem* p)
        {
            sf::Vector2f posPlat = getPosicao();
            sf::Vector2f posJog = p->getPosicao();

            sf::Vector2f tamPlat = getTamanho();
            sf::Vector2f tamJog = p->getTamanho();

            float dx = posJog.x - posPlat.x;
            float dy = posJog.y - posPlat.y;

            float overlapX =
                (tamJog.x / 2.f + tamPlat.x / 2.f) - std::abs(dx);

            float overlapY =
                (tamJog.y / 2.f + tamPlat.y / 2.f) - std::abs(dy);

            if (overlapX < overlapY)
            {
                //horizontal

                if (dx > 0)
                {
                    p->setPosicao(sf::Vector2f(
                        posPlat.x + tamPlat.x / 2.f + tamJog.x / 2.f,
                        posJog.y
                    ));
                }
                else
                {
                    p->setPosicao(sf::Vector2f(
                        posPlat.x - tamPlat.x / 2.f - tamJog.x / 2.f,
                        posJog.y
                    ));
                }

                p->setVelocidade(sf::Vector2f(
                    0.f,
                    p->getVelocidade().y
                ));
            }
            else
            {
                //vertical

                if (dy > 0)
                {
                    // jogador embaixo

                    p->setPosicao(sf::Vector2f(
                        posJog.x,
                        posPlat.y + tamPlat.y / 2.f + tamJog.y / 2.f
                    ));
                }
                else
                {
                    // jogador em cima

                    p->setPosicao(sf::Vector2f(
                        posJog.x,
                        posPlat.y - tamPlat.y / 2.f - tamJog.y / 2.f
                    ));

                    p->setnoChao(true);
                }

                p->setVelocidade(sf::Vector2f(
                    p->getVelocidade().x,
                    0.f
                ));
            }
        }

		void Plataforma::executar()
		{
            gravitar();
            if (seMove)
            {
                body.move(direcao * PLATAFORMA_VEL * getTempo(), 0.f);

                if (body.getPosition().x >= posOriginal.x + PLATAFORMA_DIST)
                    direcao = -1;

                if (body.getPosition().x <= posOriginal.x - PLATAFORMA_DIST)
                    direcao = 1;
            }
			desenhar();
		}
        void Plataforma::salvarDataBuffer()
        {
            Obstaculo::salvarDataBuffer();

            buffer << seMove << ' '

                << posOriginal.x << ' '
                << posOriginal.y << ' '

                << direcao << ' '
                << std::endl;
        }

        void Plataforma::salvar()
        {
            bufferInterno.str("");
            buffer.clear();
            salvarDataBuffer();
        }

        void Plataforma::carregar(std::istream& in)
        {
            Obstaculo::carregar(in);

            in >> seMove;

            in >> posOriginal.x;
            in >> posOriginal.y;

            in >> direcao;
        }
	}
}