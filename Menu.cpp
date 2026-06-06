#include "Menu.h"
#include "Jogo.h"

Menu::Menu(sf::Vector2f pos, sf::Vector2f tam, const std::string& texturaFundo) :
    Ente(pos == sf::Vector2f(0.f, 0.f) ? pGG->getWindowCentro() : pos,
         tam == sf::Vector2f(0.f, 0.f) ? pGG->getWindowTam() : tam, texturaFundo), 
    pJogo(NULL), vecBotao(), botaoSelecionado(), vecTexto(), fonte()
{
    if (!fonte.loadFromFile("ginger_brand/GingerBrand.ttf"))
    {
        std::cout << "Erro ao carregar fonte" << std::endl;
    }

    mudarMenu(MENU_PRINCIPAL);
}

Menu::~Menu()
{
    limparvecBotao();
}

void Menu::setJogo(Jogo* pJ)
{
    pJogo = pJ;
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

    case MENU_PAUSA:
        criarMenuPausa();
        break;
    }

    if (!vecBotao.empty()) {
        botaoSelecionado = vecBotao.begin();
        (*botaoSelecionado)->setSelecionado(true);
    }
}

tipoMenu Menu::getTipoMenu()
{
    return menuAtual;
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

void Menu::limparvecTexto()
{
    vecTexto.clear();
}

void Menu::adicionarTexto(sf::String s, sf::Vector2f pos, unsigned int tam)
{
    sf::Text texto;

    texto.setFont(fonte);
    texto.setString(s);
    texto.setCharacterSize(tam);

    sf::FloatRect bounds = texto.getLocalBounds();

    texto.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);

    texto.setPosition(pos);

    vecTexto.push_back(texto);
}

void Menu::criarMenuPrincipal()
{
    body.setFillColor(sf::Color(255, 255, 255, 255));

    limparvecTexto();

    adicionarTexto("JOGO", sf::Vector2f(pGG->getWindowCentro().x, pGG->getWindowCentro().y - 200.f), 100);

    vecBotao.push_back(new Botao(ACAO_JOGAR, //mudar assim que adicionar o menu fases
        sf::String("Jogar"),
        pGG->getWindowCentro()
    ));
   
    vecBotao.push_back(new Botao(ACAO_SAIR,
        sf::String("Sair"),
        sf::Vector2f(pGG->getWindowCentro().x, pGG->getWindowCentro().y + 100.f)
    ));
}

void Menu::criarMenuPausa()
{
    body.setFillColor(sf::Color(0, 0, 0, 150));

    limparvecTexto();

    adicionarTexto("JOGO PAUSADO", sf::Vector2f(pGG->getWindowCentro().x, pGG->getWindowCentro().y - 200.f), 100);

    vecBotao.push_back(new Botao(ACAO_RESUMIR,
        sf::String("Resumir"),
        pGG->getWindowCentro()
    ));

    vecBotao.push_back(new Botao(ACAO_VOLTAR,
        sf::String("Voltar para o Menu Principal"),
        sf::Vector2f(pGG->getWindowCentro().x, pGG->getWindowCentro().y + 100.f)
    ));
}

void Menu::selecionarBotoes(Direcao d)
{
    if (vecBotao.empty())
        return;

    if (d == CIMA) {
        if (botaoSelecionado != vecBotao.begin()) {
            (*botaoSelecionado)->setSelecionado(false);
            --botaoSelecionado;
            (*botaoSelecionado)->setSelecionado(true);
        }
    }
    if (d == BAIXO) {
        std::vector<Botao*>::iterator ultimo = vecBotao.end();
        --ultimo; // ultimo botao valido

        if (botaoSelecionado != ultimo) {
            (*botaoSelecionado)->setSelecionado(false);
            ++botaoSelecionado;
            (*botaoSelecionado)->setSelecionado(true);
        }
    }
}

void Menu::executarBotao()
{
    switch ((*botaoSelecionado)->getAcao())
    {
    case ACAO_JOGAR:
        pJogo->criarFasePrimeira();
        mudarMenu(NO_JOGO);
        break;

    case ACAO_SAIR:
        pGG->fecharJanela();
        break;

    case ACAO_VOLTAR:
        mudarMenu(MENU_PRINCIPAL);
        pJogo->deletarFasePrimeira();
        break;

    case ACAO_RESUMIR:
        mudarMenu(NO_JOGO);
        break;
    }

}

void Menu::executar()
{
    desenhar(); // desenha o fundo

    for (std::vector<Botao*>::iterator it = vecBotao.begin(); it != vecBotao.end(); ++it)
    {
        (*it)->executar();
    }

    for (std::vector<sf::Text>::iterator it = vecTexto.begin(); it != vecTexto.end(); ++it)
    {
        desenhar((*it));
    }
}
