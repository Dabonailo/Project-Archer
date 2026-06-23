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
            int n,
            int _id
        )
            : Personagem(pos, tam, textura, v, e, n, _id), movDir(false), movEsq(false), coolDownTiro(0.f),
            congelado(false), tempoCongelado(0.f), fatorLentidao(1.f), projetil(NULL), queimando(false), 
            tempoQueimadura(0.f), contadorQueimadura(0.f), danoQueimadura(0),
			pontuacao(0)
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

        void Jogador::atualizarCooldowns()
        {
            velocidadeKnockback.x *= 0.995f;

            if (tempoInvulneravel > 0.f) {
                if (!queimando && !congelado) {
                    body.setFillColor(sf::Color(255, 255, 255, 150.f + 105.f * std::sin(tempoInvulneravel * 10.f)));
                }

                tempoInvulneravel -= getTempo();
            }
            else {
                if (!queimando && !congelado) {
                    body.setFillColor(sf::Color::White);
                }
            }

            if (cooldownKnockback > 0.f)
                cooldownKnockback -= getTempo();

            if (coolDownTiro > 0.f) {
                coolDownTiro -= getTempo();
            }
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
                float fator = congelado ? fatorLentidao : 1.f;

                velocidade.x += JOG_ACELERACAO * fator;

                if (velocidade.x > JOG_VELOCIDADE_MAX * fator)
                    velocidade.x = JOG_VELOCIDADE_MAX * fator;

                body.setScale(1.f, 1.f);
            }

            if (movEsq)
            {
                float fator = congelado ? fatorLentidao : 1.f;

                velocidade.x -= JOG_ACELERACAO * fator;

                if (velocidade.x < -JOG_VELOCIDADE_MAX * fator)
                    velocidade.x = -JOG_VELOCIDADE_MAX * fator;

                body.setScale(-1.f, 1.f);
            }
        }

        void Jogador::pular()
        {
            if (tempoNoChao > 0.f)
            {
                float fator = congelado ? fatorLentidao : 1.f;

                velocidade.y = -FORCA_PULO * fator;
                tempoNoChao = 0.f;
                noChao = false;
            }
        }

        void Jogador::colidir(Inimigo* pIn)
        {
            pIn->recebeDano(10);

            if (!pIn->getVivo()) {
                pontuacao = pontuacao + 100 * pIn->getNivelMaldade();
            }

            if (pIn->getBounds().left < getBounds().left) {

                pIn->aplicarKnockback(sf::Vector2f(-KNOCKBACK_X, 0.f));
                pIn->setVelocidade(sf::Vector2f(0.f, -KNOCKBACK_Y));
            }
            else {

                pIn->aplicarKnockback(sf::Vector2f(KNOCKBACK_X, 0.f));
                pIn->setVelocidade(sf::Vector2f(0.f, -KNOCKBACK_Y));
            }
        }

        void Jogador::aplicarCongelamento(float duracao, float lentidao)
        {
            congelado = true;
            tempoCongelado = duracao;
            fatorLentidao = lentidao;
            
            velocidade.x *= lentidao;
        }

        void Jogador::atualizarCongelamento()
        {
            if (!congelado)
                return;

            tempoCongelado -= getTempo();

            body.setFillColor(sf::Color(150, 200, 255));

            if (tempoCongelado <= 0.f)
            {
                congelado = false;
                fatorLentidao = 1.f;
                body.setFillColor(sf::Color::White);
            }
        }

        void Jogador::aplicarQueimadura(float duracao, int dps)
        {
            queimando = true;
            tempoQueimadura = duracao;
            danoQueimadura = dps;
            contadorQueimadura = 0.f;
        }

        void Jogador::atualizarQueimadura()
        {
            if (!queimando)
                return;

            tempoQueimadura -= getTempo();
            contadorQueimadura += getTempo();

            if (contadorQueimadura >= 1.f)
            {
                recebeDano(danoQueimadura);
                contadorQueimadura = 0.f;
            }

            if (tempoQueimadura <= 0.f)
            {
                queimando = false;
            }

            if (queimando)
            {
                body.setFillColor(sf::Color(255,
                    127.5f + 127.5f * std::sin(tempoQueimadura * 10.f),
                    127.5f + 127.5f * std::sin(tempoQueimadura * 10.f)
                ));
            }
            else
            {
                body.setFillColor(sf::Color::White);
            }
        }

        bool Jogador::getQueimando()
        {
            return queimando;
        }

        void Jogador::executar()
        {
            if (noChao)
                tempoNoChao = 0.1f; // 100 ms
            else if (tempoNoChao > 0.f)
                tempoNoChao -= getTempo();

            mover();
            gravitar();
            atualizarQueimadura();
            atualizarCongelamento();

            atualizarCooldowns();

            body.move(
                (velocidade.x + velocidadeKnockback.x) * getTempo(),
                (velocidade.y + velocidadeKnockback.y) * getTempo()
            );
            
            desenhar();
        }
        void Jogador::salvar()
        {
            bufferInterno.str("");
            buffer.clear();

            salvarDataBuffer();
        }

        void Jogador::salvarDataBuffer()
        {
            Personagem::salvarDataBuffer();

            buffer << movDir << ' '
                << movEsq << ' '

                << coolDownTiro << ' '

                << congelado << ' '
                << tempoCongelado << ' '
                << fatorLentidao << ' '

                << queimando << ' '
                << tempoQueimadura << ' '
                << contadorQueimadura << ' '
                << danoQueimadura << ' '

                << pontuacao << ' '
                << std::endl;

            if (!getnoChao())
            {
                sf::Vector2f vel = getVelocidade();
                vel.y = 0.f;
                setVelocidade(vel);

                velocidadeKnockback.y = 0.f;
            }
        }

        void Jogador::carregar(std::istream& in)
        {
            Personagem::carregar(in);

            in >> movDir;
            in >> movEsq;

            in >> coolDownTiro;

            in >> congelado;
            in >> tempoCongelado;
            in >> fatorLentidao;

            in >> queimando;
            in >> tempoQueimadura;
            in >> contadorQueimadura;
            in >> danoQueimadura;

            in >> pontuacao;

            projetil = NULL;


        }
    }
}