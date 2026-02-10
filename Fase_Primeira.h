#pragma once
#include "Fase.h"
#include "Jogador.h"

class Fase_Primeira :
    public Fase
{
private:
    const int max_inimigos;


public:
    Fase_Primeira();
    ~Fase_Primeira();

    void criarInimigos() override;
    void criarObstaculos() override{}
    void executar() override;
};

