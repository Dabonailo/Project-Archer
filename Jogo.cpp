#include "Jogo.h"
#include "Ente.h"


Jogo::Jogo(): pjogador(NULL), pjogador2(NULL), pontuacaoFinalP1(0), pontuacaoFinalP2(0), ranking(),
numJogadores(1), faseAtual(-1), GG(), GE(), fase1(NULL), fase2(NULL), menu(NULL)
{   
    carregarRanking();

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

void Jogo::setNumJogadores(int n)
{
    numJogadores = n;
}

int Jogo::getNumJogadores()
{
    return numJogadores;
}

int Jogo::getFaseAtual()
{
    return faseAtual;
}

void Jogo::salvarPontuacao(const std::string& nome, int jogador)
{
    Ranking novo;

    novo.nome = nome;

    if (jogador == 1)
        novo.pontuacao = pontuacaoFinalP1;
    else
        novo.pontuacao = pontuacaoFinalP2;

    ranking.push_back(novo);

    std::sort(ranking.begin(), ranking.end()); //ordena as pontuacoes de maior para menor

    if (ranking.size() > 10) { //pega o top 10
        ranking.resize(10);
    }

    std::ofstream arquivo("ranking.txt");

    if (!arquivo.is_open())
        return;

    for (unsigned int i = 0; i < ranking.size(); i++)
    {
        arquivo
            << ranking[i].nome
            << " "
            << ranking[i].pontuacao
            << std::endl;
    }

    arquivo.close();
}

void Jogo::carregarRanking()
{
    ranking.clear();

    std::ifstream arquivo("ranking.txt");

    if (!arquivo.is_open())
        return;

    Ranking r;

    while (arquivo >> r.nome >> r.pontuacao)
    {
        ranking.push_back(r);
    }

    arquivo.close();
}

const std::vector<Ranking>& Jogo::getRanking() const
{
    return ranking;
}

int Jogo::getPontuacaoFinal(int j)
{
    switch (j)
    {
    case 1:
        return pjogador->getPontuacao();

    case 2:
        return pjogador2->getPontuacao();

    default:
        return -1;  
    }

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

    if (fase2) {
        deletarFaseSegunda();
    }

    Entidades::Personagens::Jogador* jogador = new Entidades::Personagens::Jogador(sf::Vector2f(100.f, 0.f),
        sf::Vector2f(ENT_TAM_DEFAULT_X, ENT_TAM_DEFAULT_Y),
        "hanzo_spray.png");

    pjogador = jogador;

    if (numJogadores == 2) {
        Entidades::Personagens::Jogador* jogador2 = new Entidades::Personagens::Jogador(sf::Vector2f(100.f, 0.f),
            sf::Vector2f(ENT_TAM_DEFAULT_X, ENT_TAM_DEFAULT_Y),
            "hanzo2_spray.png");

        pjogador2 = jogador2;
    }

    fase1 = new Fases::Fase_Primeira(pjogador, pjogador2);

    GE->setJogador(pjogador);
    GE->setJogador(pjogador2);

    faseAtual = 1;

    std::cout << "fase 1 criada" << std::endl;
}

void Jogo::deletarFasePrimeira()
{
    if (fase1) {
        delete fase1;
        fase1 = NULL;

        pjogador = NULL;
        pjogador2 = NULL;

        pontuacaoFinalP1 = 0;
        pontuacaoFinalP2 = 0;

        GE->deletarJogadores();

        faseAtual = -1;
        std::cout << "fase deletada" << std::endl;
    }
}

void Jogo::criarFaseSegunda()
{
    if (fase2) {
        deletarFaseSegunda();
    }

    if (fase1) {
        deletarFasePrimeira();
    }

    Entidades::Personagens::Jogador* jogador = new Entidades::Personagens::Jogador(sf::Vector2f(100.f, 0.f),
        sf::Vector2f(ENT_TAM_DEFAULT_X, ENT_TAM_DEFAULT_Y),
        "hanzo_spray.png");

    pjogador = jogador;

    if (numJogadores == 2) {
        Entidades::Personagens::Jogador* jogador2 = new Entidades::Personagens::Jogador(sf::Vector2f(100.f, 0.f),
            sf::Vector2f(ENT_TAM_DEFAULT_X, ENT_TAM_DEFAULT_Y),
            "hanzo2_spray.png");

        pjogador2 = jogador2;
    }

    fase2 = new Fases::Fase_segunda(pjogador, pjogador2);

    GE->setJogador(pjogador);
    GE->setJogador(pjogador2);

    faseAtual = 2;

    std::cout << "fase 2 criada" << std::endl;
}

void Jogo::deletarFaseSegunda()
{
    if (fase2) {
        delete fase2;
        fase2 = NULL;

        pjogador = NULL;
        pjogador2 = NULL;

        pontuacaoFinalP1 = 0;
        pontuacaoFinalP2 = 0;

        GE->deletarJogadores();

        faseAtual = -1;
        std::cout << "fase 2 deletada" << std::endl;
    }
}

void Jogo::executarMenu()
{
    if (numJogadores == 1)
    {
        if (pjogador && !pjogador->getVivo() && menu->getTipoMenu() != MENU_GAME_OVER 
            && menu->getTipoMenu() != MENU_SALVAR_PONTUACAO) 
        {
            pontuacaoFinalP1 = pjogador->getPontuacao();

            menu->mudarMenu(MENU_GAME_OVER);
        }
        if (fase1) {
            if (fase1->getNumeroInimigos() <= 0 &&
                menu->getTipoMenu() != MENU_VITORIA && menu->getTipoMenu() != MENU_SALVAR_PONTUACAO)
            {
                pontuacaoFinalP1 = pjogador->getPontuacao();

                menu->mudarMenu(MENU_VITORIA);
            }
        }
        else if(fase2){
            if (fase2->getNumeroInimigos() <= 0 &&
                menu->getTipoMenu() != MENU_VITORIA && menu->getTipoMenu() != MENU_SALVAR_PONTUACAO)
            {
                pontuacaoFinalP1 = pjogador->getPontuacao();

                menu->mudarMenu(MENU_VITORIA);
            }
        }
    }
    else if (numJogadores == 2) {
        if (pjogador && !pjogador->getVivo() && pjogador2 && !pjogador2->getVivo() 
            && menu->getTipoMenu() != MENU_GAME_OVER && menu->getTipoMenu() != MENU_SALVAR_PONTUACAO)
        {
            pontuacaoFinalP1 = pjogador->getPontuacao();
            pontuacaoFinalP2 = pjogador2->getPontuacao();

            menu->mudarMenu(MENU_GAME_OVER);
        }
        if (fase1) {
            if (fase1->getNumeroInimigos() <= 0 &&
                menu->getTipoMenu() != MENU_VITORIA && menu->getTipoMenu() != MENU_SALVAR_PONTUACAO)
            {
                pontuacaoFinalP1 = pjogador->getPontuacao();
                pontuacaoFinalP2 = pjogador2->getPontuacao();

                menu->mudarMenu(MENU_VITORIA);
            }
        }
        else if (fase2) {
            if (fase2->getNumeroInimigos() <= 0 &&
                menu->getTipoMenu() != MENU_VITORIA && menu->getTipoMenu() != MENU_SALVAR_PONTUACAO)
            {
                pontuacaoFinalP1 = pjogador->getPontuacao();
                pontuacaoFinalP2 = pjogador2->getPontuacao();

                menu->mudarMenu(MENU_VITORIA);
            }
        }
    }

    switch (menu->getTipoMenu())
    {
    case MENU_PRINCIPAL:
    case MENU_FASES:
    case MENU_JOGADORES:
    case MENU_RANKING:
        menu->executar();
        break;

    case MENU_PAUSA:
        if (fase1) {
            fase1->desenhar();
        }
        else if (fase2) {
            fase2->desenhar();
        }

        menu->executar();
        break;

    case MENU_GAME_OVER:
    case NO_JOGO:
    case MENU_SALVAR_PONTUACAO:
    case MENU_VITORIA:
        if (fase1) {
            fase1->executar();
        }
        else if (fase2) {
            fase2->executar();
        }
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
