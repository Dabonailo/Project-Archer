#include "Jogador.h"
#include "GerenciadorGrafico.h" 

namespace Entidades
{
    namespace Personagens
    {

        Jogador::Jogador(
            sf::Vector2f pos,
            sf::Vector2f tam,
            const std::string& textura,
            sf::Vector2f v,
            float e
        )
            : Personagem(pos, tam, textura, v, e), movDir(false), movEsq(false)
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

            // Ataque: tamanho relativo ao corpo e origem no centro para facilitar o posicionamento
            ataque_corpo.setFillColor(sf::Color::Cyan);
            ataque_corpo.setSize(sf::Vector2f(body.getSize().x * ATQ_SCALE_X, body.getSize().y * ATQ_SCALE_Y));
            ataque_corpo.setOrigin(ataque_corpo.getSize().x / 2.f, ataque_corpo.getSize().y / 2.f);

            // Inicializa flags/tempos de ataque
            ataqueAtivo = false;
            tempoAtaque = 0.f;
            tempoCooldown = 0.f;
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

        void Jogador::atacar()
        {
            // Não inicia novo ataque enquanto estiver ativo ou em cooldown
            if (ataqueAtivo || tempoCooldown > 0.f)
                return;

            // posiciona inicialmente ao lado do corpo conforme direção
            if (body.getScale().x > 0.f)
            {
                ataque_corpo.setPosition(sf::Vector2f(body.getPosition().x + body.getSize().x / 2.f + ataque_corpo.getSize().x / 2.f, body.getPosition().y));
            }
            else
            {
                ataque_corpo.setPosition(sf::Vector2f(body.getPosition().x - body.getSize().x / 2.f - ataque_corpo.getSize().x / 2.f, body.getPosition().y));
            }

            ataqueAtivo = true;
            tempoAtaque = ATQ_TEMPO; // duração do ataque
            tempoCooldown = ATQ_COOLDOWN; // tempo até poder atacar de novo

            std::cout << "ataque acionado" << std::endl;
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

            // reduzir tempo de cooldown do ataque (sempre)
            if (tempoCooldown > 0.f)
                tempoCooldown -= getTempo();

            desenhar();

            if (ataqueAtivo)
            {
                // Mantém o ataque preso ao jogador enquanto ativo (atualiza posição a cada frame)
                if (body.getScale().x > 0.f)
                {
                    ataque_corpo.setPosition(sf::Vector2f(body.getPosition().x + body.getSize().x / 2.f + ataque_corpo.getSize().x / 2.f, body.getPosition().y));
                }
                else
                {
                    ataque_corpo.setPosition(sf::Vector2f(body.getPosition().x - body.getSize().x / 2.f - ataque_corpo.getSize().x / 2.f, body.getPosition().y));
                }

                pGG->desenharAtaque(&ataque_corpo);
                tempoAtaque -= getTempo();
                if (tempoAtaque <= 0.f)
                    ataqueAtivo = false;
            }
        }

    }
}