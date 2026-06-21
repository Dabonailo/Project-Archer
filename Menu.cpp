#include "Menu.h"
#include "Jogo.h"

Menu::Menu(sf::Vector2f pos, sf::Vector2f tam, const std::string& texturaFundo, int _id) :
    Ente(pos == sf::Vector2f(0.f, 0.f) ? pGG->getWindowCentro() : pos,
         tam == sf::Vector2f(0.f, 0.f) ? pGG->getWindowTam() : tam, texturaFundo, _id),
    pJogo(NULL), vecBotao(), botaoSelecionado(), vecTexto(), fonte(), jogadorSalvando(1)
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
    case NO_JOGO:
        criarHUDJogo();
        break;
        
    case MENU_PRINCIPAL:
        criarMenuPrincipal();
        break;

    case MENU_RANKING:
        criarMenuRanking();
        break;

    case MENU_JOGADORES:
        criarMenuSelecionarJogadores();
        break;

    case MENU_FASES:
        criarMenuFases();
        break;

    case MENU_PAUSA:
        criarMenuPausa();
        break;

    case MENU_GAME_OVER:
        criarMenuGameOver();
        break;

    case MENU_VITORIA:
        criarMenuVitoria();
        break;

    case MENU_SALVAR_PONTUACAO:
        criarMenuSalvarPontuacao();
        break;

    default:
        std::cout << "Sem Menu definido" << std::endl;
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

void Menu::digitarNome(sf::Uint32 unicode)
{
    if (menuAtual != MENU_SALVAR_PONTUACAO)
        return;

    if (unicode == 8) // BACKSPACE
    {
        if (!nomeDigitado.empty())
            nomeDigitado.pop_back();
    }

    else if (unicode >= 32 && unicode <= 126 && nomeDigitado.size() < 12)
    {
        nomeDigitado += static_cast<char>(unicode);
    }
}

void Menu::centralizarTexto(sf::Text& texto)
{
    sf::FloatRect bounds = texto.getLocalBounds();

    texto.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
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

void Menu::limparMenu()
{
    limparvecBotao();
    limparvecTexto();
    body.setFillColor(sf::Color(0, 0, 0, 0));
}

void Menu::adicionarTexto(sf::String s, sf::Vector2f pos, unsigned int tam)
{
    sf::Text texto;

    texto.setFont(fonte);
    texto.setString(s);
    texto.setCharacterSize(tam);
    texto.setOutlineColor(sf::Color::Black);
    texto.setOutlineThickness(3.f);

    sf::FloatRect bounds = texto.getLocalBounds();

    texto.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);

    texto.setPosition(pos);

    vecTexto.push_back(texto);
}

void Menu::criarHUDJogo()
{
    limparMenu();

    adicionarTexto("", sf::Vector2f(10.f, 10.f));
    idxVidaP1 = vecTexto.size() - 1;

    adicionarTexto("", sf::Vector2f(200.f, 10.f));
    idxPontuacaoP1 = vecTexto.size() - 1;

    if (pJogo->getNumJogadores() == 2) {
        adicionarTexto("", sf::Vector2f(1070.f, 10.f));
        idxVidaP2 = vecTexto.size() - 1;

        adicionarTexto("", sf::Vector2f(780.f, 10.f));
        idxPontuacaoP2 = vecTexto.size() - 1;
    }
}

void Menu::criarMenuPrincipal()
{
    body.setFillColor(sf::Color(255, 255, 255, 255));

    limparvecTexto();

    adicionarTexto("JOGO", sf::Vector2f(pGG->getWindowCentro().x, pGG->getWindowCentro().y - 200.f), 100);

    vecBotao.push_back(new Botao(ACAO_MENU_JOGADORES,
        sf::String("Jogar"),
        pGG->getWindowCentro()
    ));

    vecBotao.push_back(new Botao(ACAO_MENU_RANKING,
        sf::String("Ranking"),
        sf::Vector2f(pGG->getWindowCentro().x, pGG->getWindowCentro().y + 100.f)
    ));
   
    vecBotao.push_back(new Botao(ACAO_SAIR,
        sf::String("Sair"),
        sf::Vector2f(pGG->getWindowCentro().x, pGG->getWindowCentro().y + 200.f)
    ));
}

void Menu::criarMenuRanking()
{
    body.setFillColor(sf::Color(255, 255, 255, 255));

    limparvecTexto();

    adicionarTexto(sf::String("TOP 10"), sf::Vector2f(pGG->getWindowCentro().x, 70.f), 80);

    const std::vector<Ranking>& ranking = pJogo->getRanking();

    float y = 155.f;

    for (unsigned int i = 0; i < ranking.size(); i++)
    {
        std::stringstream ss;

        ss << i + 1
            << ". "
            << ranking[i].nome
            << " - "
            << ranking[i].pontuacao;

        adicionarTexto(ss.str(), sf::Vector2f(pGG->getWindowCentro().x, y), 40);

        y += 50.f;
    }

    vecBotao.push_back(new Botao(ACAO_VOLTAR,
        sf::String("Voltar"),
        sf::Vector2f(pGG->getWindowCentro().x, 680.f)
    ));
}

void Menu::criarMenuFases()
{
    body.setFillColor(sf::Color(255, 255, 255, 255));

    limparvecTexto();

    adicionarTexto("SELECIONE UMA FASE", sf::Vector2f(pGG->getWindowCentro().x, pGG->getWindowCentro().y - 200.f), 100);

    vecBotao.push_back(new Botao(ACAO_JOGAR_FASE_1,
        sf::String("FASE 1"),
        pGG->getWindowCentro()
    ));

    vecBotao.push_back(new Botao(ACAO_JOGAR_FASE_2,
        sf::String("FASE 2"),
        sf::Vector2f(pGG->getWindowCentro().x, pGG->getWindowCentro().y + 100.f)
    ));

    vecBotao.push_back(new Botao(ACAO_VOLTAR_MENU_JOGADORES,
        sf::String("Voltar"),
        sf::Vector2f(pGG->getWindowCentro().x, pGG->getWindowCentro().y + 200.f)
    ));
}

void Menu::criarMenuSelecionarJogadores()
{
    body.setFillColor(sf::Color(255, 255, 255, 255));

    limparvecTexto();

    adicionarTexto(
        "SELECIONE O NUMERO DE JOGADORES",
        sf::Vector2f(pGG->getWindowCentro().x, pGG->getWindowCentro().y - 200.f),
        60
    );

    vecBotao.push_back(
        new Botao(
            ACAO_1_JOGADOR,
            "1 Jogador",
            pGG->getWindowCentro()
        )
    );

    vecBotao.push_back(
        new Botao(ACAO_2_JOGADORES,
            "2 Jogadores",
            sf::Vector2f(pGG->getWindowCentro().x, pGG->getWindowCentro().y + 100.)
        )
    );

    vecBotao.push_back(new Botao(ACAO_VOLTAR,
        sf::String("Voltar"),
        sf::Vector2f(pGG->getWindowCentro().x, pGG->getWindowCentro().y + 200.f)
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

void Menu::criarMenuGameOver()
{
    body.setFillColor(sf::Color(0, 0, 0, 150));

    limparvecTexto();

    adicionarTexto("GAME OVER", sf::Vector2f(pGG->getWindowCentro().x, pGG->getWindowCentro().y - 250.f), 100);

    std::stringstream ss;

    ss << "PONTUACAO P1: " << pJogo->getPontuacaoFinal(1);
    adicionarTexto(ss.str(), sf::Vector2f(pGG->getWindowCentro().x, pGG->getWindowCentro().y - 150.f), 30);

    if (pJogo->getNumJogadores() == 2) {
        ss.str("");
        ss << "PONTUACAO P2: " << pJogo->getPontuacaoFinal(2);
        adicionarTexto(ss.str(), sf::Vector2f(pGG->getWindowCentro().x, pGG->getWindowCentro().y - 90.f), 30);
    }

    if (pJogo->getFaseAtual() == 1) {
        vecBotao.push_back(new Botao(ACAO_JOGAR_FASE_1,
            sf::String("Tentar de novo"),
            pGG->getWindowCentro()
        ));
    }
    else if (pJogo->getFaseAtual() == 2) {
        vecBotao.push_back(new Botao(ACAO_JOGAR_FASE_2,
            sf::String("Tentar de novo"),
            pGG->getWindowCentro()
        ));
    }

    vecBotao.push_back(new Botao(ACAO_MENU_SALVAR_PONTUACAO,
        sf::String("Salvar Pontuacao"),
        sf::Vector2f(pGG->getWindowCentro().x, pGG->getWindowCentro().y + 100.f)
    ));

    vecBotao.push_back(new Botao(ACAO_VOLTAR,
        sf::String("Voltar para o Menu Principal"),
        sf::Vector2f(pGG->getWindowCentro().x, pGG->getWindowCentro().y + 200.f)
    ));
}

void Menu::criarMenuVitoria()
{
    body.setFillColor(sf::Color(0, 0, 0, 150));

    limparvecTexto();

    adicionarTexto("FASE CONCLUIDA", sf::Vector2f(pGG->getWindowCentro().x, pGG->getWindowCentro().y - 250.f), 100);

    std::stringstream ss;

    ss << "PONTUACAO P1: " << pJogo->getPontuacaoFinal(1);
    adicionarTexto(ss.str(), sf::Vector2f(pGG->getWindowCentro().x, pGG->getWindowCentro().y - 150.f), 30);

    if (pJogo->getNumJogadores() == 2) {
        ss.str("");
        ss << "PONTUACAO P2: " << pJogo->getPontuacaoFinal(2);
        adicionarTexto(ss.str(), sf::Vector2f(pGG->getWindowCentro().x, pGG->getWindowCentro().y - 90.f), 30);
    }

    vecBotao.push_back(new Botao(ACAO_JOGAR_FASE_1,
        sf::String("Jogar Fase 1"),
        pGG->getWindowCentro()
    ));

    vecBotao.push_back(new Botao(ACAO_JOGAR_FASE_2,
        sf::String("Jogar Fase 2"),
        sf::Vector2f(pGG->getWindowCentro().x, pGG->getWindowCentro().y + 100.f)
    ));

    vecBotao.push_back(new Botao(ACAO_MENU_SALVAR_PONTUACAO,
        sf::String("Salvar Pontuacao"),
        sf::Vector2f(pGG->getWindowCentro().x, pGG->getWindowCentro().y + 200.f)
    ));

    vecBotao.push_back(new Botao(ACAO_VOLTAR,
        sf::String("Voltar para o Menu Principal"),
        sf::Vector2f(pGG->getWindowCentro().x, pGG->getWindowCentro().y + 300.f)
    ));
}

void Menu::criarMenuSalvarPontuacao()
{
    body.setFillColor(sf::Color(0, 0, 0, 150));

    limparvecTexto();

    adicionarTexto("DIGITE SEU NOME: ", sf::Vector2f(pGG->getWindowCentro().x, pGG->getWindowCentro().y - 300.f), 100);

    adicionarTexto("", sf::Vector2f(pGG->getWindowCentro().x, pGG->getWindowCentro().y - 100.f), 50);

    idxNomeJogador1 = vecTexto.size() - 1;

    vecBotao.push_back(new Botao(ACAO_SALVAR_PONTUACAO,
        sf::String("Salvar"),
        sf::Vector2f(pGG->getWindowCentro().x, pGG->getWindowCentro().y + 100.f)
    ));

    vecBotao.push_back(new Botao(ACAO_VOLTAR_MENU_GAME_OVER,
        sf::String("Voltar"),
        sf::Vector2f(pGG->getWindowCentro().x, pGG->getWindowCentro().y + 200.f)
    ));
}

void Menu::salvarPontuacao()
{
    if (nomeDigitado.empty()) {
        pJogo->salvarPontuacao("Sem Nome", jogadorSalvando);
    }

    pJogo->salvarPontuacao(nomeDigitado, jogadorSalvando);

    nomeDigitado.clear();

    if (jogadorSalvando == 1 && pJogo->getNumJogadores() == 2)
    {
        jogadorSalvando = 2;
    }

    else
    {
        mudarMenu(MENU_GAME_OVER);
    }
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
    case ACAO_JOGAR_FASE_1:
        pJogo->criarFasePrimeira();
        mudarMenu(NO_JOGO);
        break;

    case ACAO_JOGAR_FASE_2:
        //pJogo->criarFaseSegunda();
		pJogo->carregarJogo();
        mudarMenu(NO_JOGO);
        break;

    case ACAO_MENU_JOGADORES:
        mudarMenu(MENU_JOGADORES);
        break;

    case ACAO_1_JOGADOR:
        pJogo->setNumJogadores(1);
        mudarMenu(MENU_FASES);
        break;

    case ACAO_2_JOGADORES:
        pJogo->setNumJogadores(2);
        mudarMenu(MENU_FASES);
        break;

    case ACAO_MENU_FASES:
        mudarMenu(MENU_FASES);
        break;

    case ACAO_SAIR:
        pGG->fecharJanela();
        break;

    case ACAO_VOLTAR:
        mudarMenu(MENU_PRINCIPAL);
        pJogo->deletarFasePrimeira();
        pJogo->deletarFaseSegunda();
        break;

    case ACAO_VOLTAR_MENU_JOGADORES:
        mudarMenu(MENU_JOGADORES);
        break;

    case ACAO_VOLTAR_MENU_GAME_OVER:
        mudarMenu(MENU_GAME_OVER);
        break;

    case ACAO_RESUMIR:
        mudarMenu(NO_JOGO);
        break;

    case ACAO_MENU_SALVAR_PONTUACAO:
        mudarMenu(MENU_SALVAR_PONTUACAO);
        break;

    case ACAO_SALVAR_PONTUACAO:
        salvarPontuacao();
        break;

    case ACAO_MENU_RANKING:
        mudarMenu(MENU_RANKING);
        break;

    default:
        std::cout << "Botao sem acao definida" << std::endl;
    }
}

void Menu::executar()
{
    if (menuAtual == NO_JOGO)
    {
        std::stringstream ss;

        ss << "VIDA P1: " << pJogo->getVidaJogador(1);
        vecTexto[idxVidaP1].setString(ss.str());

        ss.str("");
        ss << "PONTUACAO P1: " << pJogo->getPontuacaoJogador(1);
        vecTexto[idxPontuacaoP1].setString(ss.str());

        if (pJogo->getNumJogadores() == 2)
        {
            ss.str("");
            ss << "VIDA P2: " << pJogo->getVidaJogador(2);
            vecTexto[idxVidaP2].setString(ss.str());

            ss.str("");
            ss << "PONTUACAO P2: " << pJogo->getPontuacaoJogador(2);
            vecTexto[idxPontuacaoP2].setString(ss.str());
        }
    }

    if (menuAtual == MENU_SALVAR_PONTUACAO)
    {
        vecTexto[idxNomeJogador1].setString(nomeDigitado + "_");
        centralizarTexto(vecTexto[idxNomeJogador1]);
    }

    desenhar();

    for (auto it = vecBotao.begin(); it != vecBotao.end(); ++it)
    {
        (*it)->executar();
    }

    for (auto it = vecTexto.begin(); it != vecTexto.end(); ++it)
    {
        desenhar(*it);
    }
}
