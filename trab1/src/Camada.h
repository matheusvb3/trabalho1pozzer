#include <list>
#include <memory>
#include "Bmp.h"

class Camada {
private:
    std::list<std::shared_ptr<Bmp>> layers; // Lista para armazenar camadas

public:
    void adiciona(const std::shared_ptr<Bmp>& img); // Adiciona nova imagem ao topo
    void remove(const std::shared_ptr<Bmp>& img); // Remove uma imagem
    void moveParaCima(const std::shared_ptr<Bmp>& img); // Move uma camada para frente
    void moveParaBaixo(const std::shared_ptr<Bmp>& img); // Move uma camada para tras
    std::shared_ptr<Bmp> getCamada(int indice);
    void render(); // Renderiza as camadas na ordem correta
};
