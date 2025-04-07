#include "PainelDeCamadas.h"

PainelDeCamadas::PainelDeCamadas(float x, float y, float largura, float altura) {
    selecionada = 0;

    // Criando os bot�es de mover camada
    btCima = new Botao(x + 20, y + altura - 50, 58, 30, "Cima");
    btBaixo = new Botao(x + 100, y + altura - 50, 66, 30, "Baixo");
}

void PainelDeCamadas::adiciona(std::shared_ptr<Bmp> img) {
    camadas.push_back(img);
}

void PainelDeCamadas::moverParaCima() {
    if (selecionada > 0) {
        std::swap(camadas[selecionada], camadas[selecionada - 1]);
        selecionada--;  // Atualiza a sele��o
    }
}

void PainelDeCamadas::moverParaBaixo() {
    if (selecionada < camadas.size() - 1) {
        std::swap(camadas[selecionada], camadas[selecionada + 1]);
        selecionada++;  // Atualiza a sele��o
    }
}

void PainelDeCamadas::selecionar(int index) {
    if (index >= 0 && index < camadas.size()) {
        selecionada = index;
    }
}

void PainelDeCamadas::render() {
    float yBase = 20;
    for (size_t i = 0; i < camadas.size(); i++) {
        CV::color(selecionada == i ? 1 : 0.5, 1, 1);
        CV::rectFill(10, yBase, 190, yBase + 40);
        yBase += 50;
    }

    btCima->render();
    btBaixo->render();
}
