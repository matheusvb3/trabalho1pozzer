#ifndef CHECKBOX_H
#define CHECKBOX_H

#include "gl_canvas2d.h"

class CheckBox {
private:
    float lado, x, y;  // CheckBox será quadrada

public:
    bool ativa;

    CheckBox(float _x, float _y, float _lado);

    void toggle();
    void render();
    bool Colidiu(int mx, int my);
};

#endif  // CHECKBOX_H
