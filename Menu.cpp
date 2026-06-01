#include "Menu.h"

Menu::Menu(sf::Vector2f pos, sf::Vector2f tam, const std::string& texturaFundo):
	Ente(pos, tam == sf::Vector2f(0.f, 0.f) ? pGG->getWindowTam() : tam, texturaFundo), vecBotao(), titulo()
{
}

Menu::~Menu()
{
    for (std::vector<Botao*>::iterator it = vecBotao.begin(); it != vecBotao.end(); ++it)
    {
        delete *it;
    }
}

void Menu::adicionarBotoes()
{
    //botoes
}

void Menu::executarMenuPrincipal()
{
    desenhar(); // desenha o fundo

    for (std::vector<Botao*>::iterator it = vecBotao.begin(); it != vecBotao.end(); ++it)
    {
        (*it)->desenhar();
    }

    pGG->getWindow()->draw(titulo);
}
