#include "Fase.h"

namespace Fases {
    Fase::Fase(Entidades::Personagens::Jogador* pJ, Entidades::Personagens::Jogador* pJ2,
        sf::Vector2f pos, sf::Vector2f tam, const std::string& textura, int _id) :

        Ente(pos == sf::Vector2f(0.f, 0.f) ? pGG->getWindowCentro() : pos,
            tam == sf::Vector2f(0.f, 0.f) ? pGG->getWindowTam() : tam,
            textura,
            _id),
        acabouDeCarregar(false),
        ListaEntFase(),
        GC(),
        pJogador(NULL),
        pJogador2(NULL)
    {
        body.setFillColor(sf::Color(255, 255, 255, 150));

        if (pJ != NULL)
        {
            ListaEntFase.incluir(pJ);
            lJogs.incluir(pJ);
            GC.incluirJogadores(pJ);
            pJogador = pJ;
        }

        if (pJ2 != NULL)
        {
            ListaEntFase.incluir(pJ2);
            lJogs.incluir(pJ2);
            GC.incluirJogadores(pJ2);
            pJogador2 = pJ2;
        }
    }

	Fase::~Fase() {}

	Listas::ListaEntidades* Fase::getListaEntFase()
	{
		return &ListaEntFase;
	}

    int Fase::getNumeroInimigos()
    {
        return GC.getTamanhoLIs();
    }

    void Fase::executar() 
    {
        Ente::desenhar();
        if (acabouDeCarregar)
        {
            GC.executar();
            ListaEntFase.desenharLista();

            acabouDeCarregar = false;
            return;
        }
        ListaEntFase.percorrerLista();
        GC.executar();
        atualizalJogs();
    }

	void Fase::desenhar() {
        Ente::desenhar();
		ListaEntFase.desenharLista();
	}

    void Fase::criarOnis()
    {
        Entidades::Personagens::Oni* inimigo;

        inimigo = new Entidades::Personagens::Oni();
        inimigo->setPosicao(sf::Vector2f(440.f, 680.f));
        inimigo->setListaJogadores(&lJogs);
        ListaEntFase.incluir(inimigo);
        GC.incluirInimigo(inimigo);

        inimigo = new Entidades::Personagens::Oni();
        inimigo->setPosicao(sf::Vector2f(350.f, 420.f));
        inimigo->setListaJogadores(&lJogs);
        ListaEntFase.incluir(inimigo);
        GC.incluirInimigo(inimigo);

        inimigo = new Entidades::Personagens::Oni();
        inimigo->setPosicao(sf::Vector2f(630.f, 680.f));
        inimigo->setListaJogadores(&lJogs);
        ListaEntFase.incluir(inimigo);
        GC.incluirInimigo(inimigo);

        if (rand()%2==0)
        {
            inimigo = new Entidades::Personagens::Oni();
            inimigo->setPosicao(sf::Vector2f(310.f, 700.f));
            inimigo->setListaJogadores(&lJogs);
            ListaEntFase.incluir(inimigo);
            GC.incluirInimigo(inimigo);
        }
   
        if (rand() % 2 == 0)
        {
            inimigo = new Entidades::Personagens::Oni();
            inimigo->setPosicao(sf::Vector2f(1250.f, 675.f));
            inimigo->setListaJogadores(&lJogs);
            ListaEntFase.incluir(inimigo);
            GC.incluirInimigo(inimigo);
        }
    }

    void Fase::criarPlataformas()
    {
        // Plataforma fixa 1
        Entidades::Obstaculos::Plataforma* p =
            new Entidades::Obstaculos::Plataforma(
                sf::Vector2f(280.f, 750.f),
                sf::Vector2f(250.f, 35.f),
                "ginger_brand/Plataforma.png",
                sf::Vector2f(0.f, 0.f),
                false);

        ListaEntFase.incluir(p);
        GC.incluirObstaculo(p);

        p = new Entidades::Obstaculos::Plataforma(
                sf::Vector2f(1200.f, 725.f),
                sf::Vector2f(250.f, 35.f),
                "ginger_brand/Plataforma.png",
                sf::Vector2f(0.f, 0.f),
                false);

        ListaEntFase.incluir(p);
        GC.incluirObstaculo(p);

        p = new Entidades::Obstaculos::Plataforma(
            sf::Vector2f(950.f, 575.f),
            sf::Vector2f(250.f, 35.f),
            "ginger_brand/Plataforma.png",
            sf::Vector2f(0.f, 0.f),
            false);

        ListaEntFase.incluir(p);
        GC.incluirObstaculo(p);

    }

    void Fase::atualizalJogs()
    {
        auto* atual = lJogs.getPrimeiro();

        while (atual)
        {
            auto* proximo = atual->getProximo();

            Entidades::Personagens::Jogador* pJog =
                dynamic_cast<Entidades::Personagens::Jogador*>(atual->getInfo());

            if (pJog && !pJog->getVivo())
            {
                lJogs.remover(atual->getInfo());
            }

            atual = proximo;
        }
    }

    void Fase::salvarFase()
    {
        bool doisJogadores = (lJogs.getTamanho() == 2);

        ListaEntFase.salvarEntidades(id, doisJogadores);
    }

    void Fase::criarCenario()
    {
        criarObstaculos();
        criarInimigos();
	}

    void Fase::carregarFase()
    {
        std::ifstream arquivo("Salvamentos/Save.txt");

        if (!arquivo.is_open())
        {
            std::cout << "Erro ao abrir Salvamentos/Save.txt para carregar." << std::endl;
            return;
        }

        ListaEntFase.limparLista();
        lJogs.limparLista();

        GC = Gerenciadores::GerenciadorColisoes();

        pJogador = NULL;
        pJogador2 = NULL;

        int idFaseSalva = -1;
        int doisJogadores = 0;

        arquivo >> idFaseSalva >> doisJogadores;

        if (idFaseSalva != id)
        {
            std::cout << "Aviso: fase salva diferente da fase atual." << std::endl;
            std::cout << "Fase atual: " << id << " | Fase salva: " << idFaseSalva << std::endl;
        }

        std::string linha;
        std::getline(arquivo, linha);

        std::map<int, Entidades::Personagens::Personagem*> donosPorUid;
        std::vector<Entidades::Projetil*> projeteisCarregados;

        while (std::getline(arquivo, linha))
        {
            if (linha.size() == 0)
            {
                continue;
            }

            std::stringstream ss(linha);

            int idEntidade = -1;
            ss >> idEntidade;

            if (!ss)
            {
                continue;
            }

            switch (idEntidade)
            {
            case 3:
            {
                Entidades::Personagens::Jogador* jog = NULL;

                if (pJogador == NULL)
                {
                    jog = new Entidades::Personagens::Jogador(
                        sf::Vector2f(0.f, 0.f),
                        sf::Vector2f(ENT_TAM_DEFAULT_X, ENT_TAM_DEFAULT_Y),
                        "hanzo_spray.png"
                    );
                }
                else
                {
                    jog = new Entidades::Personagens::Jogador(
                        sf::Vector2f(0.f, 0.f),
                        sf::Vector2f(ENT_TAM_DEFAULT_X, ENT_TAM_DEFAULT_Y),
                        "hanzo2_spray.png"
                    );
                }

                jog->setId(3);
                jog->carregar(ss);

                ListaEntFase.incluir(jog);
                lJogs.incluir(jog);
                GC.incluirJogadores(jog);

                if (pJogador == NULL)
                {
                    pJogador = jog;
                }
                else if (pJogador2 == NULL)
                {
                    pJogador2 = jog;
                }

                donosPorUid[jog->getUid()] = jog;

                break;
            }

            case 4:
            {
                Entidades::Personagens::Oni* oni =
                    new Entidades::Personagens::Oni(
                        sf::Vector2f(0.f, 0.f),
                        sf::Vector2f(75.f, 75.f),
                        "Oni_spray.png"
                    );

                oni->setId(4);
                oni->carregar(ss);
                oni->setListaJogadores(&lJogs);

                ListaEntFase.incluir(oni);
                GC.incluirInimigo(oni);

                break;
            }

            case 5:
            {
                Entidades::Personagens::Dragao* dragao =
                    new Entidades::Personagens::Dragao(
                        sf::Vector2f(0.f, 0.f),
                        sf::Vector2f(ENT_TAM_DEFAULT_X, ENT_TAM_DEFAULT_Y),
                        "dragao.png"
                    );

                dragao->setId(5);
                dragao->carregar(ss);
                dragao->setListaJogadores(&lJogs);

                ListaEntFase.incluir(dragao);
                GC.incluirInimigo(dragao);

                break;
            }

            case 6:
            {
                Entidades::Personagens::Ninja* ninja =
                    new Entidades::Personagens::Ninja(
                        sf::Vector2f(0.f, 0.f),
                        sf::Vector2f(100.f, 100.f),
                        "ninja.png"
                    );

                ninja->setId(6);
                ninja->carregar(ss);
                ninja->setListaJogadores(&lJogs);

                ListaEntFase.incluir(ninja);
                GC.incluirInimigo(ninja);

                donosPorUid[ninja->getUid()] = ninja;

                break;
            }

            case 7:
            {
                Entidades::Obstaculos::Plataforma* plat =
                    new Entidades::Obstaculos::Plataforma(
                        sf::Vector2f(0.f, 0.f),
                        sf::Vector2f(250.f, 35.f),
                        "ginger_brand/Plataforma.png",
                        sf::Vector2f(0.f, 0.f),
                        false
                    );

                plat->setId(7);
                plat->carregar(ss);

                ListaEntFase.incluir(plat);
                GC.incluirObstaculo(plat);

                break;
            }

            case 8:
            {
                Entidades::Obstaculos::Bloco_Magma* magma =
                    new Entidades::Obstaculos::Bloco_Magma(
                        sf::Vector2f(0.f, 0.f),
                        sf::Vector2f(250.f, 35.f),
                        "ginger_brand/Magma_Block.png",
                        sf::Vector2f(0.f, 0.f),
                        false
                    );

                magma->setId(8);
                magma->carregar(ss);

                ListaEntFase.incluir(magma);
                GC.incluirObstaculo(magma);

                break;
            }

            case 9:
            {
                Entidades::Obstaculos::Espinho* esp =
                    new Entidades::Obstaculos::Espinho(
                        sf::Vector2f(0.f, 0.f),
                        sf::Vector2f(35.f, 35.f),
                        "espinhos.png"
                    );

                esp->setId(9);
                esp->carregar(ss);

                ListaEntFase.incluir(esp);
                GC.incluirObstaculo(esp);

                break;
            }

            case 10:
            {
                Entidades::Projetil* proj =
                    new Entidades::Projetil(
                        sf::Vector2f(-1000.f, 1000.f),
                        sf::Vector2f(28.f, 7.f),
                        "Flecha.png",
                        sf::Vector2f(0.f, 0.f)
                    );

                proj->setId(10);
                proj->carregar(ss);

                ListaEntFase.incluir(proj);
                GC.incluirProjetil(proj);

                projeteisCarregados.push_back(proj);

                break;
            }

            default:
            {
                std::cout << "ID desconhecido no carregamento: "
                    << idEntidade << std::endl;

                break;
            }
            }
        }

        arquivo.close();

        for (unsigned int i = 0; i < projeteisCarregados.size(); i++)
        {
            Entidades::Projetil* proj = projeteisCarregados[i];

            if (proj == NULL)
            {
                continue;
            }

            int uidDono = proj->getUIdDono();

            std::map<int, Entidades::Personagens::Personagem*>::iterator itDono =
                donosPorUid.find(uidDono);

            if (itDono == donosPorUid.end())
            {
                std::cout << "Dono do projetil nao encontrado. UID salvo: "
                    << uidDono << std::endl;

                proj->setAtivo(false);
                continue;
            }

            Entidades::Personagens::Personagem* dono = itDono->second;

            if (dono == NULL)
            {
                proj->setAtivo(false);
                continue;
            }

            proj->setPersonagem(dono);
            proj->setUIdDono(dono->getUid());

            Entidades::Personagens::Jogador* jog =
                dynamic_cast<Entidades::Personagens::Jogador*>(dono);

            if (jog != NULL)
            {
                jog->setProjetil(proj);
                continue;
            }

            Entidades::Personagens::Ninja* ninja =
                dynamic_cast<Entidades::Personagens::Ninja*>(dono);

            if (ninja != NULL)
            {
                ninja->setProjetil(proj);
                continue;
            }
        }

        std::cout << "Fase carregada com sucesso." << std::endl;
		acabouDeCarregar = true;
   
    }
        
}
