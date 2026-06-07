#include "Botao.h"

Botao::Botao(AcaoBotao a, const sf::String& str, sf::Vector2f pos, sf::Vector2f tam, const std::string& textura) :
	Ente(pos, tam, textura), texto(), fonte(), acao(a), selecionado(false), tempoAnimacao(0.f)
{
	if (!fonte.loadFromFile("ginger_brand/GingerBrand.ttf"))
	{
		std::cout << "Erro ao carregar fonte" << std::endl;
	}

	texto.setFont(fonte);
	texto.setString(str);
	centralizarTexto();
}

Botao::~Botao()
{
}

AcaoBotao Botao::getAcao() const
{
	return acao;
}

void Botao::centralizarTexto()
{
	sf::FloatRect bounds = texto.getLocalBounds();
	texto.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
	texto.setPosition(getPosicao());
}

void Botao::setSelecionado(bool s)
{
	selecionado = s;
}

bool Botao::getSelecionado()
{
	return selecionado;
}

void Botao::executar()
{
	tempoAnimacao += pGG->getTempo();

	float escala = 1.f;

	if (selecionado)
	{
		escala = 1.15f + 0.05f * std::sin(tempoAnimacao * 5.f);
	}

	body.setScale(escala, escala);
	texto.setScale(escala, escala);

	desenhar();
	desenhar(texto);
}
