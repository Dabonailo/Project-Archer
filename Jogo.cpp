#include "Jogo.h"
#include "Ente.h"


Jogo::Jogo(): pjogador(NULL), pjogador2(NULL), GG(), GE(), fase1(NULL), menu(NULL)
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

int Jogo::getVidaJogador(int j)
{
    if (pjogador && j == 1) {
        if (pjogador->getVida() >= 0) {
            return pjogador->getVida();
        }
        else {
            return 0;
        }
    }

    else if (pjogador2 && j == 2) {
        if (pjogador2->getVida() >= 0) {
            return pjogador2->getVida();
        }
        else {
            return 0;
        }
    }

    else {
        return -1;
    }
}

int Jogo::getPontuacaoJogador(int j)
{
    if (pjogador && j == 1) {
        return pjogador->getPontuacao();
    }

    else if (pjogador2 && j == 2) {
        return pjogador2->getPontuacao();
    }
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

    Entidades::Personagens::Jogador* jogador2 = new Entidades::Personagens::Jogador(sf::Vector2f(100.f, 0.f),
        sf::Vector2f(ENT_TAM_DEFAULT_X, ENT_TAM_DEFAULT_Y),
        "hanzo2_spray.png");

    pjogador2 = jogador2;

    fase1 = new Fases::Fase_Primeira(pjogador, pjogador2);

    GE->setJogador(pjogador);
    GE->setJogador(pjogador2);

    std::cout << "fase 1 criada" << std::endl;
}

void Jogo::deletarFasePrimeira()
{
    if (fase1) {
        delete fase1;
        fase1 = NULL;
        pjogador = NULL;
        GE->deletarJogadores();
        std::cout << "fase deletada" << std::endl;
    }
}

void Jogo::executarMenu()
{
    if (pjogador && !pjogador->getVivo() && pjogador2 && !pjogador2->getVivo() && menu->getTipoMenu() != MENU_GAME_OVER)
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
