#include "Camada.h"
#include <algorithm>

void Camada::addImage(const std::shared_ptr<Bmp>& img) {
    layers.push_back(img); // Adiciona ao topo (última posição)
}

void Camada::removeImage(const std::shared_ptr<Bmp>& img) {
    layers.remove(img); // Remove diretamente a imagem da lista
}

void Camada::moveUp(const std::shared_ptr<Bmp>& img) {
    auto it = std::find(layers.begin(), layers.end(), img);
    if (it != layers.end()) {
        auto next = std::next(it);
        if (next != layers.end()) {
            std::iter_swap(it, next); // Troca com a próxima para subir
        }
    }
}

void Camada::moveDown(const std::shared_ptr<Bmp>& img) {
    auto it = std::find(layers.begin(), layers.end(), img);
    if (it != layers.begin() && it != layers.end()) {
        auto prev = std::prev(it);
        std::iter_swap(it, prev); // Troca com a anterior para descer
    }
}

void Camada::render() {
    for (const auto& img : layers) {
        img->render(); // Renderiza todas as imagens na ordem da lista
    }
}
