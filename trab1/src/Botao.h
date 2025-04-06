#ifndef BOTAO_H
#define BOTAO_H

#include "gl_canvas2d.h"

class Botao {
public:
    int x, y, larg, alt;
    char *label;

    Botao(int x, int y, int larg, int alt, const char *label);
    void render();
};

#endif // BOTAO_H

