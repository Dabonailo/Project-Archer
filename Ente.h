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
	int id;
	/*
	vazio = -1
	menu = 0
	fase1 = 1
	fase2 = 2
	jogador = 3
	oni = 4
	dragao = 5
	ninja = 6
	plataforma = 7
	blocomagma = 8
	espinho = 9
	projetil = 10
	*/

	static Gerenciadores::GerenciadorGrafico* pGG;
	sf::RectangleShape body;
	sf::Texture texturaEntidade;

public:
	Ente(sf::Vector2f pos = sf::Vector2f(0.f, 0.f),
		sf::Vector2f tam = sf::Vector2f(0.f, 0.f),
		const std::string& textura = "",
		int _id = -1);

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

