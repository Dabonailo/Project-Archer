#include "Jogo.h"
#include "Ente.h"


Jogo::Jogo(): pjogador(NULL), GG(), GE(), fase1(NULL), menu(NULL)
{   
    GG = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico();
    GE = Gerenciadores::GerenciadorEventos::getGerenciadorEventos();
    Ente::setGG(GG);


    menu = new Menu();
    GE->setMenu(menu);
    menu->setJogo(this);
}

Jogo::~Jogo()
{
}

void Jogo::criarFasePrimeira()
{
    if (fase1) {
        deletarFasePrimeira();
    }

    Entidades::Personagens::Jogador* jogador = new Entidades::Personagens::Jogador(sf::Vector2f(100.f, 0.f),
        sf::Vector2f(ENT_TAM_DEFAULT_X, ENT_TAM_DEFAULT_Y),
        "hanzo_spray.png");

    pjogador = jogador;

    fase1 = new Fases::Fase_Primeira();
    fase1->adicionarJogador(pjogador);

    GE->setJogador(pjogador);

    std::cout << "fase 1 criada" << std::endl;
}

void Jogo::deletarFasePrimeira()
{
    if (fase1) {
        delete fase1;
        fase1 = NULL;
        pjogador = NULL;
        GE->setJogador(NULL);
        std::cout << "fase deletada" << std::endl;
    }
}

void Jogo::executarMenu()
{
    if (pjogador && !pjogador->getVivo() && menu->getTipoMenu() != MENU_GAME_OVER)
    {
        menu->mudarMenu(MENU_GAME_OVER);
    }

    switch (menu->getTipoMenu())
    {
    case MENU_PRINCIPAL:
    case MENU_FASES:
        menu->executar();
        break;

    case MENU_PAUSA:
        fase1->desenhar();
        menu->executar();
        break;

    case MENU_GAME_OVER:
    case NO_JOGO:
        fase1->executar();
        menu->executar();
        break;
    }
}

void Jogo::executar()
{
    while (GG->verificaJanelaAberta())
    {        
        GE->executar();
        GG->getWindow()->clear();

        executarMenu();
        
        GG->getWindow()->display();
        GG->resetarRelogio();
    }
}
