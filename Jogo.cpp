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

    Entidades::Personagens::Jogador* jogador = new Entidades::Personagens::Jogador(sf::Vector2f(100.f, 675.f),
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
    delete fase1;
    fase1 = NULL;
    GE->setJogador(NULL);
    std::cout << "fase deletada" << std::endl;
}

void Jogo::executar()
{
    while (GG->verificaJanelaAberta())
    {        
        GE->executar();
        GG->getWindow()->clear();

        switch (menu->getTipoMenu())
        {
        case MENU_PRINCIPAL:
            menu->executar();
            break;

        case MENU_PAUSA:
            fase1->desenhar();
            menu->executar();
            break;

        case NO_JOGO:
            fase1->executar();
            break;
        }

        GG->getWindow()->display();
        GG->resetarRelogio();
    }
}
