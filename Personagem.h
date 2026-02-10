#pragma once
#include "Entidade.h"
class Personagem :
    public Entidade
{
private:
    int numVidas;

public:
    Personagem();
    ~Personagem();

    virtual void executar() = 0;

};

