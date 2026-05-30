#pragma once

#include <SFML/Graphics.hpp>

#include <string>

#include <iostream>

#include <cstdlib>

namespace Gerenciadores {
	class GerenciadorGrafico;
}

class Ente
{
protected:
	static Gerenciadores::GerenciadorGrafico* pGG;
	sf::RectangleShape body;
	sf::Texture texturaEntidade;

public:
	Ente(sf::Vector2f pos = sf::Vector2f(0.f, 0.f),
		sf::Vector2f tam = sf::Vector2f(0.f, 0.f),
		const std::string& textura = "");

	virtual ~Ente();

	//TAMANHO E POSICAO

	void setTamanho(sf::Vector2f tam);
	void setPosicao(sf::Vector2f pos);

	const sf::Vector2f getTamanho() const;
	const sf::Vector2f getPosicao() const;

	//TEXTURA

	void setTextura(const std::string& textura);

	//CORPO

	const sf::RectangleShape& getBody() const;
	const sf::FloatRect getBounds() const;

	virtual void executar() = 0;

	void desenhar();

	static void setGG(Gerenciadores::GerenciadorGrafico* pG) {
		pGG = pG;
	}
};

