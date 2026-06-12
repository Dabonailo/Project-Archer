#include "Projetil.h"

Entidades::Projetil::Projetil(sf::Vector2f pos,
	sf::Vector2f tam,
	const std::string& textura,
	sf::Vector2f velocidade, float e) :
	Entidade(pos, tam, textura, velocidade, e),
	ativo(true), alvo(NULL), offset(sf::Vector2f(0.f,0.f)), cravado(false), tempoCravado(0.f)
{
}

Entidades::Projetil::~Projetil()
{
	ativo = false;
}

void Entidades::Projetil::setAtivo(bool a)
{
	cravado = false;
	alvo = NULL;
	offset = sf::Vector2f(0.f, 0.f);
	ativo = a;
}

bool Entidades::Projetil::getAtivo()
{
	return ativo;
}

void Entidades::Projetil::verificaForaDaTela()
{
	if (getPosicao().x < 0.f ||
		getPosicao().x > pGG->getWindowTam().x ||
		getPosicao().y < 0.f ||
		getPosicao().y > pGG->getWindowTam().y)
	{
		ativo = false;
	}
}

void Entidades::Projetil::cravarProjetil(Entidade* e)
{
	ativo = false;
	cravado = true;
	alvo = e;

	offset = getPosicao() - e->getPosicao();

	velocidade = sf::Vector2f(0.f, 0.f);
}

void Entidades::Projetil::mover()
{
	body.move(velocidade.x * getTempo(), velocidade.y * getTempo());

	if (velocidade.x > 0.f)
	{
		velocidade.x -= RESISTENCIA_DO_AR * getTempo();
		if (velocidade.x < 0.f) velocidade.x = 0.f;
	}
	else if (velocidade.x < 0.f)
	{
		velocidade.x += RESISTENCIA_DO_AR * getTempo();
		if (velocidade.x > 0.f) velocidade.x = 0.f;
	}	
	body.setRotation((std::atan2(velocidade.y, velocidade.x)) * 180.f / 3.14159265f);
}

void Entidades::Projetil::executar()
{
	if (cravado && alvo)
	{
		setPosicao(alvo->getPosicao() + offset);
	}

	else {
		mover();
		verificaForaDaTela();
	}

	gravitar();
	desenhar();
}
