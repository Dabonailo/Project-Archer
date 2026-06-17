#include "Ente.h"
#include "GerenciadorGrafico.h"

Ente::Ente(sf::Vector2f pos, sf::Vector2f tam, const std::string& textura)
    : body(), texturaEntidade()
{
    body.setSize(tam);

    body.setOrigin(
        tam.x / 2.f,
        tam.y / 2.f
    );

    body.setPosition(pos);

    if (textura != "")
    {
        texturaEntidade.loadFromFile(textura);
        body.setTexture(&texturaEntidade);
    }
    else
    {
        body.setFillColor(sf::Color::Red);
        std::cout << "textura nao carregada" << std::endl;
    }
}

Ente::~Ente()
{
}

void Ente::setTamanho(sf::Vector2f tam)
{
    body.setSize(tam);

    body.setOrigin(
        tam.x / 2.f,
        tam.y / 2.f
    );
}

void Ente::setPosicao(sf::Vector2f pos)
{
	body.setPosition(pos);
}

const sf::Vector2f Ente::getTamanho() const
{
	return body.getSize();
}

const sf::Vector2f Ente::getPosicao() const
{
	return body.getPosition();
}

float Ente::getTempo() const
{
    return pGG->getTempo();
}

void Ente::setTextura(const std::string& textura)
{
	texturaEntidade.loadFromFile(textura);
	body.setTexture(&texturaEntidade);
}

void Ente::setCor(sf::Color cor)
{
    body.setFillColor(cor);
}

const sf::RectangleShape& Ente::getBody() const
{
	return body;
}

const sf::FloatRect Ente::getBounds() const
{
	return body.getGlobalBounds();
}

void Ente::desenhar()
{
	pGG->desenharEnte(this);
}

void Ente::desenhar(sf::Text t) {
    pGG->desenharTexto(t);
}


Gerenciadores::GerenciadorGrafico* Ente::pGG = NULL;
