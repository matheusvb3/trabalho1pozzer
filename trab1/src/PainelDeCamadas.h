#ifndef PAINELDECAMADAS_H
#define PAINELDECAMADAS_H

#include <vector>
#include <memory>
#include "bmp.h"
#include "Botao.h"
#include "Camada.h"

class PainelDeCamadas {
private:
    Camada* ptrCamadas;
    std::vector<std::shared_ptr<Bmp>> camadas;
    std::vector<std::string> labels;
    int selecionada;  // Indice da camada selecionada

public:
    Botao *btCima;
    Botao *btBaixo;
    PainelDeCamadas(float x, float y, float largura, float altura, Camada* ptrCamadas);

    void adiciona(std::shared_ptr<Bmp> img, const std::string& nome);
    void moveParaCima();
    void moveParaBaixo();
    void render();
    void selecionar(int index);
    int obterSelecionado() { return selecionada; }
};

#endif
