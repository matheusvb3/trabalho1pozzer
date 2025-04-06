#include "CheckBox.h"

CheckBox::CheckBox(float _x, float _y, float _lado) {
    lado = _lado;
    x = _x;
    y = _y;
    ativa = false;  // Inicialmente desativada
}

void CheckBox::toggle() {
    if (ativa)
    {
        !ativa;
    }
    else
    {
        ativa;
    }
}

void CheckBox::render() {
    CV::color(0, 0, 1);
    CV::rectFill(x, y, x + lado, y + lado);

    // Controla o display de estado
    if (ativa) {
        CV::color(1, 0.647, 0);
        CV::rectFill(x + (lado * 0.1), y + (lado * 0.1), x + lado - (lado * 0.1), y + lado - (lado * 0.1));
    } else {
        CV::color(1, 1, 1);
        CV::rectFill(x + (lado * 0.1), y + (lado * 0.1), x + lado - (lado * 0.1), y + lado - (lado * 0.1));
    }
}

bool CheckBox::Colidiu(int mx, int my) {
    return (mx >= x && mx <= (x + lado) && my >= y && my <= (y + lado));
}
