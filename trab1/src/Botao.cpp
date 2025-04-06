#include "Botao.h"
#include <string.h>

Botao::Botao(int x, int y, int larg, int alt, const char *label)
{
    this->x = x;
    this->y = y;
    this->larg = larg;
    this->alt = alt;
    this->label = new char[strlen(label) + 1];
    strcpy(this->label, label);
}

void Botao::render()
{
    CV::color(0.7, 0.7, 0.7);
    CV::rectFill(x, y, x + larg, y + alt);
    CV::color(0, 0, 0);
    CV::text(x + 10, y + alt / 2, label);
}

bool Botao::Colidiu(int mouseX, int mouseY)
{
    return (mouseX >= x && mouseX <= x + larg && mouseY >= y && mouseY <= y + alt);
}
