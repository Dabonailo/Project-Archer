#pragma once
#include "Ente.h"

#define TAMANHO_BOTAO_DEFAUlT_X 100.f
#define TAMANHO_BOTAO_DEFAULT_Y 50.f

class Botao : public Ente
{
private:
	sf::Text texto;
	sf::Font fonte;

public:
	Botao(
		sf::Vector2f pos = sf::Vector2f(0.f, 0.f),
		sf::Vector2f tam = sf::Vector2f(TAMANHO_BOTAO_DEFAUlT_X, TAMANHO_BOTAO_DEFAULT_Y),
		const std::string& textura = "ginger_brand/Plataforma.png",
		const sf::String& str = "Inserir Texto"
	);

	~Botao();
};

