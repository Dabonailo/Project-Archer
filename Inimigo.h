#pragma once

#include "Personagem.h"
#include "Jogador.h"

class Inimigo : public Personagem
{
private:

public:
    Inimigo(sf::Vector2f pos, sf::Vector2f tam, const std::string& textura, sf::Vector2f v);

    ~Inimigo();

    virtual void danificar(Jogador* p) = 0;

    virtual void mover() = 0;

    virtual void executar() override;
};

