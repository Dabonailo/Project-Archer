#include "Jogo.h"
#include "Ente.h"


Jogo::Jogo(): pjogador(NULL), GG(), fase1()
{   
    Ente::setGG(&GG);

    Jogador* jogador = new Jogador(sf::Vector2f(0.f, 0.f),
        sf::Vector2f(ENT_TAM_DEFAULT_X, ENT_TAM_DEFAULT_Y),
        "hanzo_spray.png");

    pjogador = jogador;

    fase1.adicionarJogador(pjogador);
}

Jogo::~Jogo()
{
}

void Jogo::executar()
{
    while (GG.verificaJanelaAberta())
    {
        sf::Event event;
        while (GG.getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                GG.fecharJanela();

            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape) {
                    GG.fecharJanela();
                }
            }
        }

        GG.getWindow()->clear();
        fase1.executar();
        GG.getWindow()->display();
    }
}
