#pragma once
#include "Entidade.h"
class Personagem :
    public Entidade
{
private:
    int numVidas;

public:
    Personagem(sf::Vector2f pos, sf::Vector2f tam, const std::string& textura, sf::Vector2f v);
    ~Personagem();

    virtual void operator--() {
        if (numVidas > 0) {
            numVidas--;
        }
    }

    const int getVida() const;

    virtual void executar() = 0;

};

