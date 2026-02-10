#include "Jogo.h"
#include "Ente.h"


Jogo::Jogo(): jogador(), GG(), fase1(), ListaEntFixa(false)
{
    ListaEntFixa.adicionarElemento(&jogador);
    fase1.executar();
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

        GG.executar(fase1.getListaEntFase(), &ListaEntFixa);

        jogador.executar();

    }
}
