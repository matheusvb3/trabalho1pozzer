#include "Camada.h"
#include <algorithm>

// Adiciona no topo da lista
void Camada::adiciona(const std::shared_ptr<Bmp>& img)
{
    layers.push_back(img);
}

void Camada::moveParaCima(const std::shared_ptr<Bmp>& img)
{
    auto it = std::find(layers.begin(), layers.end(), img);
    if (it != layers.end())
    {
        auto next = std::next(it);
        if (next != layers.end())
        {
            std::iter_swap(it, next);
        }
    }
}

void Camada::moveParaBaixo(const std::shared_ptr<Bmp>& img)
{
    auto it = std::find(layers.begin(), layers.end(), img);
    if (it != layers.begin() && it != layers.end())
    {
        auto prev = std::prev(it);
        std::iter_swap(it, prev);
    }
}

std::shared_ptr<Bmp> Camada::getCamada(int indice) {
    if (indice < 0 || indice >= layers.size())
    {
        return nullptr; // Retorna nullptr se o indice for invalido
    }
    auto it = layers.begin();
    std::advance(it, indice); // Avanca ate a posicao correta
    return *it;
}

// Renderiza todas as imagens na ordem da lista
void Camada::render()
{
    for (const auto& img : layers)
    {
        img->render();
    }
}
