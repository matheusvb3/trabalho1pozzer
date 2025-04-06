#include "Botao.h"
#include <string.h>

Botao::Botao(int x, int y, int largura, int altura, const char *texto) {
    this->x = x;
    this->y = y;
    this->largura = largura;
    this->altura = altura;
    this->texto = new char[strlen(texto) + 1];
    strcpy(this->texto, texto);
}

void Botao::render() {
    CV::color(0.7, 0.7, 0.7);
    CV::rectFill(x, y, x + largura, y + altura);
    CV::color(0, 0, 0);
    CV::text(x + 10, y + altura / 2, texto);
}
