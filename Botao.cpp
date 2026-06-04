#include "Botao.h"

Botao::Botao(AcaoBotao a, const sf::String& str, sf::Vector2f pos, sf::Vector2f tam, const std::string& textura):
	Ente(pos, tam, textura), texto(), fonte(), acao(a)
{
	if (!fonte.loadFromFile("ginger_brand/GingerBrand.ttf"))
	{
		std::cout << "Erro ao carregar fonte\n";
	}

	texto.setFont(fonte);
	texto.setString(str);
	texto.setPosition(body.getPosition());
}

Botao::~Botao()
{
}

AcaoBotao Botao::getAcao() const
{
	return acao;
}

void Botao::executar()
{
	desenhar();
	pGG->getWindow()->draw(texto);
}
