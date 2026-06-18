#include "Projetil.h"
#include "Personagem.h"
#include "Jogador.h"
#include "Ninja.h"

Entidades::Projetil::Projetil(sf::Vector2f pos,
	sf::Vector2f tam,
	const std::string& textura,
	sf::Vector2f velocidade, float e,
	ID _id) :
	Entidade(pos, tam, textura, velocidade, e),
	ativo(true), pJogador(NULL), pNinja(NULL), alvo(NULL), offset(sf::Vector2f(0.f, 0.f)), cravado(false), tempoCravado(0.f)
{
}

Entidades::Projetil::~Projetil()
{
	ativo = false;
}

void Entidades::Projetil::setPersonagem(Personagens::Personagem* pP)
{
	if (Entidades::Personagens::Jogador* pJ = dynamic_cast<Entidades::Personagens::Jogador*>(pP)) {
		pJogador = pJ;
	}
	else if (Entidades::Personagens::Ninja* pN = dynamic_cast<Entidades::Personagens::Ninja*>(pP)) {
		pNinja = pN;
	}
}

Entidades::Personagens::Jogador* Entidades::Projetil::getJogador()
{
	return pJogador;
}

Entidades::Personagens::Ninja* Entidades::Projetil::getNinja()
{
	return pNinja;
}

void Entidades::Projetil::reiniciarProjetil()
{
	if (pJogador) {
		sf::Vector2f pos = pJogador->getPosicao();
		sf::Vector2f velP;

		if (pJogador->getDirecao() == Direcao::DIREITA) {
			pos.x += pJogador->getBody().getSize().x;
			velP = sf::Vector2f(VELOCIDADE_PROJETIL_X, VELOCIDADE_PROJETIL_Y);
		}
		if (pJogador->getDirecao() == Direcao::ESQUERDA) {
			pos.x -= pJogador->getBody().getSize().x;
			velP = sf::Vector2f(-VELOCIDADE_PROJETIL_X, VELOCIDADE_PROJETIL_Y);
		}

		setPosicao(pos);
		setVelocidade(velP);
	}

	else if (pNinja) {
		sf::Vector2f pos = pNinja->getPosicao();
		sf::Vector2f velP;

		if (pNinja->getDirecao() == Direcao::DIREITA) {
			pos.x += pNinja->getBody().getSize().x;
			velP = sf::Vector2f(VELOCIDADE_PROJETIL_X, VELOCIDADE_PROJETIL_Y);
		}
		if (pNinja->getDirecao() == Direcao::ESQUERDA) {
			pos.x -= pNinja->getBody().getSize().x;
			velP = sf::Vector2f(-VELOCIDADE_PROJETIL_X, VELOCIDADE_PROJETIL_Y);
		}

		setPosicao(pos);
		setVelocidade(velP);
	}
}

void Entidades::Projetil::tratarAlvoNocauteado()
{
	if (Personagens::Personagem* p = dynamic_cast<Personagens::Personagem*>(alvo)) {
		if (!p->getVivo()) {
			alvo = NULL;
			cravado = false;
			ativo = true;
			if (pJogador) {
				if (pJogador->getDirecao() == DIREITA) {
					velocidade = sf::Vector2f(200.f, VELOCIDADE_PROJETIL_Y);
				}
				else if (pJogador->getDirecao() == ESQUERDA) {
					velocidade = sf::Vector2f(-200.f, VELOCIDADE_PROJETIL_Y);
				}
			}
			else if (pNinja) {
				if (pNinja->getDirecao() == DIREITA) {
					velocidade = sf::Vector2f(200.f, VELOCIDADE_PROJETIL_Y);
				}
				else if (pNinja->getDirecao() == ESQUERDA) {
					velocidade = sf::Vector2f(-200.f, VELOCIDADE_PROJETIL_Y);
				}
			}
		}
	}
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

	tratarAlvoNocauteado();

	gravitar();
	desenhar();
}
