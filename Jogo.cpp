#include "Jogo.h"
#include "Ente.h"


Jogo::Jogo(): jogador(), GG()
{
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
                if (event.key.code == sf::Keyboard::Escape)
                    GG.fecharJanela();
            }
        }

        //GG.executar();

        GG.limpaJanela();
        GG.getWindow()->draw(jogador.getBody());
        GG.mostraElementos();
        jogador.executar();

    }
}
