#include "Jogo.h"
#include "Ente.h"


Jogo::Jogo(): jogador(sf::Vector2f(0.f, 0.f),
    sf::Vector2f(ENT_TAM_DEFAULT_X, ENT_TAM_DEFAULT_Y),
    "hanzo_spray.png"), GG(), fase1()
{   
    fase1.adicionarJogador(&jogador);
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

        GG.executar(fase1.getListaEntFase());

        fase1.executar();
        fase1.executarGC();
    }
}
