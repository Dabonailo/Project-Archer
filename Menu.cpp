#include "Menu.h"

Menu::Menu(sf::Vector2f pos, sf::Vector2f tam, const std::string& texturaFundo):
	Ente(pos, tam == sf::Vector2f(0.f, 0.f) ? pGG->getWindowTam() : tam, texturaFundo), vecBotao(), botaoSelecionado(),
    titulo()
{
    mudarMenu(MENU_PRINCIPAL);
}

Menu::~Menu()
{
    limparvecBotao();
}

void Menu::mudarMenu(tipoMenu menu)
{
    limparvecBotao();

    menuAtual = menu;

    switch (menuAtual)
    {
    case MENU_PRINCIPAL:
        criarMenuPrincipal();
        break;

    case MENU_FASES:
        //criarMenuFases();
        break;
    }

    botaoSelecionado = vecBotao.begin();
}

void Menu::limparvecBotao()
{
    if (!vecBotao.empty()) {
        for (std::vector<Botao*>::iterator it = vecBotao.begin(); it != vecBotao.end(); ++it) {
            delete* it;
        }
        vecBotao.clear();
    }
}

void Menu::criarMenuPrincipal()
{
    vecBotao.push_back(new Botao(ACAO_MENU_FASES, sf::String("Jogar")));
    vecBotao.push_back(new Botao(ACAO_SAIR, sf::String("Sair")));
}

void Menu::selecionarBotoes(Direcao d)
{
    if (vecBotao.empty())
        return;

    if (d == CIMA) {
        if (botaoSelecionado != vecBotao.begin()) {
            --botaoSelecionado;
        }
    }
    if (d == BAIXO) {
        std::vector<Botao*>::iterator ultimo = vecBotao.end();
        --ultimo; // ultimo botao valido

        if (botaoSelecionado != ultimo) {
            ++botaoSelecionado;
        }
    }
}

void Menu::executar()
{
    desenhar(); // desenha o fundo

    for (std::vector<Botao*>::iterator it = vecBotao.begin(); it != vecBotao.end(); ++it)
    {
        (*it)->executar();
    }

    //pGG->getWindow()->draw(titulo);
}
