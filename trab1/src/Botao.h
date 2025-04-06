#ifndef BOTAO_H
#define BOTAO_H

#include "gl_canvas2d.h"

class Botao {
public:
    int x, y, largura, altura;
    char *texto;

    Botao(int x, int y, int largura, int altura, const char *texto);
    void render();
};

#endif // BOTAO_H

