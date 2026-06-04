#include "Jogo.h"
#include "Ente.h"


Jogo::Jogo(): pjogador(NULL), GG(), GE(), fase1(), menu(NULL)
{   
    GG = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico();
    GE = Gerenciadores::GerenciadorEventos::getGerenciadorEventos();
    Ente::setGG(GG);

    menu = new Menu();

    Entidades::Personagens::Jogador* jogador = new Entidades::Personagens::Jogador(sf::Vector2f(100.f, 675.f),
        sf::Vector2f(ENT_TAM_DEFAULT_X, ENT_TAM_DEFAULT_Y),
        "hanzo_spray.png");

    pjogador = jogador;

    GE->setJogador(pjogador);
    fase1.adicionarJogador(pjogador);
}

Jogo::~Jogo()
{
}

void Jogo::executar()
{
    while (GG->verificaJanelaAberta())
    {        
        GE->executar();
        GG->getWindow()->clear();
        //menu->executar();
        fase1.executar();
        GG->getWindow()->display();
        GG->resetarRelogio();
    }
}
