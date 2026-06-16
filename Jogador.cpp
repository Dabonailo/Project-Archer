#include "Jogador.h"
#include "GerenciadorGrafico.h" 
#include "Inimigo.h"
#include "Ninja.h"

namespace Entidades
{
    namespace Personagens
    {

        Jogador::Jogador(
            sf::Vector2f pos,
            sf::Vector2f tam,
            const std::string& textura,
            sf::Vector2f v,
            float e, 
            int n
        )
            : Personagem(pos, tam, textura, v, e, n), movDir(false), movEsq(false), coolDownTiro(0.f),
            projetil(NULL), pontuacao(0)
        {
            texturaEntidade.loadFromFile(textura);
            body.setTexture(&texturaEntidade);

            body.setOrigin(
                body.getSize().x / 2.f,
                body.getSize().y / 2.f
            );

            noChao = false;

            velocidade = sf::Vector2f(0.f, 0.f);
            velocidadeKnockback = sf::Vector2f(0.f, 0.f);
        }

        Jogador::~Jogador()
        {
        }

        void Jogador::setMovDir(bool b)
        {
            movDir = b;
        }

        void Jogador::setMovEsq(bool b) {
            movEsq = b;
        }

        void Jogador::atirar()
        {
            projetil->setAtivo(true);
            projetil->reiniciarProjetil();
        }

        void Jogador::setProjetil(Projetil* p)
        {
            projetil = p;
        }

        bool Jogador::getProjetilAtivo()
        {
            return projetil->getAtivo();
        }

        void Jogador::setCooldownTiro(float cd)
        {
            coolDownTiro = cd;
        }

        float Jogador::getCooldownTiro()
        {
            return coolDownTiro;
        }

        int Jogador::getPontuacao()
        {
            return pontuacao;
        }

        void Jogador::mover()
        {
            if (cooldownKnockback > 0.f)
                return;

            // ATRITO
            if (!movDir && !movEsq)
            {
                if (velocidade.x > 0.f)
                {
                    velocidade.x -= ATRITO * getTempo();
                    if (velocidade.x < 0.f) velocidade.x = 0.f;
                }
                else if (velocidade.x < 0.f)
                {
                    velocidade.x += ATRITO * getTempo();
                    if (velocidade.x > 0.f) velocidade.x = 0.f;
                }
            }

            // MOVIMENTO
            if (movDir)
            {
                velocidade.x += JOG_ACELERACAO;
                if (velocidade.x > JOG_VELOCIDADE_MAX)
                    velocidade.x = JOG_VELOCIDADE_MAX;

                body.setScale(1.f, 1.f);
            }

            if (movEsq)
            {
                velocidade.x -= JOG_ACELERACAO;
                if (velocidade.x < -JOG_VELOCIDADE_MAX)
                    velocidade.x = -JOG_VELOCIDADE_MAX;

                body.setScale(-1.f, 1.f);
            }
        }

        void Jogador::pular()
        {
            if (tempoNoChao > 0.f)
            {
                velocidade.y = -FORCA_PULO;
                tempoNoChao = 0.f;
                noChao = false;
            }
        }

        void Jogador::colidir(Inimigo* pIn)
        {
            pIn->recebeDano(10);

            pontuacao = pontuacao + 100 * pIn->getNivelMaldade();

            if (pIn->getBounds().left < getBounds().left) {

                pIn->aplicarKnockback(sf::Vector2f(-KNOCKBACK_X, 0.f));
                pIn->setVelocidade(sf::Vector2f(0.f, -KNOCKBACK_Y));
            }
            else {

                pIn->aplicarKnockback(sf::Vector2f(KNOCKBACK_X, 0.f));
                pIn->setVelocidade(sf::Vector2f(0.f, -KNOCKBACK_Y));
            }
        }



        void Jogador::executar()
        {
            if (noChao)
                tempoNoChao = 0.1f; // 100 ms
            else if (tempoNoChao > 0.f)
                tempoNoChao -= getTempo();

            mover();
            gravitar();

            body.move(
                (velocidade.x + velocidadeKnockback.x) * getTempo(),
                (velocidade.y + velocidadeKnockback.y) * getTempo()
            );

            velocidadeKnockback *= 0.995f;

            if (tempoInvulneravel > 0.f)
                tempoInvulneravel -= getTempo();

            if (cooldownKnockback > 0.f)
                cooldownKnockback -= getTempo();

            if (coolDownTiro > 0.f) {
                coolDownTiro -= getTempo();
            }
            desenhar();

			//std::cout << getBody().getPosition().x << " " << getBody().getPosition().y << std::endl; 

        }

    }
}