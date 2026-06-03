#include "Botao.h"

Botao::Botao(sf::Vector2f pos, sf::Vector2f tam, const std::string& textura, const sf::String& str):
	Ente(pos, tam, textura), texto(), fonte()
{
	fonte.loadFromFile("ginger_brand/GingerBrand.ttf");

	texto.setFont(fonte);
	texto.setString(str);
}

Botao::~Botao()
{
}
