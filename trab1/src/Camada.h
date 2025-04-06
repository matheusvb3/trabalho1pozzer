#include <list>
#include <memory>
#include "Bmp.h"

class Camada {
private:
    std::list<std::shared_ptr<Bmp>> layers; // Lista para armazenar camadas

public:
    void addImage(const std::shared_ptr<Bmp>& img); // Adiciona nova imagem ao topo
    void removeImage(const std::shared_ptr<Bmp>& img); // Remove uma imagem
    void moveUp(const std::shared_ptr<Bmp>& img); // Move uma camada para frente
    void moveDown(const std::shared_ptr<Bmp>& img); // Move uma camada para tras
    void render(); // Renderiza as camadas na ordem correta
};
