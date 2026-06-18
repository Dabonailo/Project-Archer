#pragma once

#include <SFML/Graphics.hpp>

#include <string>

#include <iostream>

#include <cstdlib>

namespace Gerenciadores {
	class GerenciadorGrafico;
}

enum ID
{
	vazio = -1,
	jogador = 0,
	oni = 1,
	dragao = 2,
	ninja = 3,
	plataforma = 4,
	blocomagma = 5,
	espinho = 6,
	projetil = 7,
	fase1 = 8,
	fase2 = 9,
	menu = 10
};

class Ente
{
protected:
	int id;
	static Gerenciadores::GerenciadorGrafico* pGG;
	sf::RectangleShape body;
	sf::Texture texturaEntidade;

public:
	Ente(sf::Vector2f pos = sf::Vector2f(0.f, 0.f),
		sf::Vector2f tam = sf::Vector2f(0.f, 0.f),
		const std::string& textura = "",
		ID _id = ID::vazio);

	virtual ~Ente();

	void setId(int i) { id = i; }
	int getId() const { return id; }
	//TAMANHO E POSICAO

	void setTamanho(sf::Vector2f tam);
	void setPosicao(sf::Vector2f pos);

	const sf::Vector2f getTamanho() const;
	const sf::Vector2f getPosicao() const;

	//TEMPO

	float getTempo() const;

	//TEXTURA

	void setTextura(const std::string& textura);
	void setCor(sf::Color cor);

	//CORPO

	const sf::RectangleShape& getBody() const;
	const sf::FloatRect getBounds() const;

	virtual void executar() = 0;

	void desenhar();
	void desenhar(sf::Text t); //para botões

	static void setGG(Gerenciadores::GerenciadorGrafico* pG) {
		pGG = pG;
	}
};

