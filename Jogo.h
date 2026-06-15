#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>

#include "Jogador.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "ListaEntidades.h"
#include "Fase_Primeira.h"
#include "Menu.h"

struct Ranking
{
	std::string nome;
	int pontuacao;

	bool operator<(const Ranking& outro) const
	{
		return pontuacao > outro.pontuacao;
	}
};

class Jogo
{
private:
	Entidades::Personagens::Jogador* pjogador;
	Entidades::Personagens::Jogador* pjogador2;

	int pontuacaoFinalP1;
	int pontuacaoFinalP2;

	std::vector<Ranking> ranking;

	int numJogadores;

	Gerenciadores::GerenciadorGrafico* GG;
	Gerenciadores::GerenciadorEventos* GE;

	Fases::Fase_Primeira* fase1;
	Menu* menu;

public:
	Jogo();
	~Jogo();

	void setNumJogadores(int n);
	int getNumJogadores();

	void salvarPontuacao(const std::string& nome, int jogador);

	void carregarRanking();

	const std::vector<Ranking>& getRanking() const;

	int getPontuacaoFinal(int j);

	int getVidaJogador(int j);
	int getPontuacaoJogador(int j);

	void criarFasePrimeira();
	void deletarFasePrimeira();

	void executarMenu();

	void executar();
};

