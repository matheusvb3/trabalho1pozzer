#include "PainelDeCamadas.h"

PainelDeCamadas::PainelDeCamadas(float x, float y, float largura, float altura, Camada* ptrCamadas) : ptrCamadas(ptrCamadas)
{
    selecionada = 0;

    // Criando os botões de mover camada
    btCima = new Botao(x + 20, y + altura - 50, 58, 30, "Cima");
    btBaixo = new Botao(x + 100, y + altura - 50, 66, 30, "Baixo");
    btVisibilidade = new Botao(x + 45, y + altura - 100, 90, 30, "Visivel");
}

void PainelDeCamadas::adiciona(std::shared_ptr<Bmp> img, const std::string& nome)
{
    camadas.push_back(img);
    labels.push_back(nome);
    visibilidade.push_back(true);
}

void PainelDeCamadas::moveParaCima()
{
    if (selecionada < camadas.size() - 1)
    {
        std::swap(camadas[selecionada], camadas[selecionada + 1]);
        std::swap(labels[selecionada], labels[selecionada + 1]);
        std::swap(visibilidade[selecionada], visibilidade[selecionada + 1]);
        selecionada++;
        if (ptrCamadas)
        {
            ptrCamadas->moveParaCima(ptrCamadas->getCamada(selecionada));
        }
    }
}

void PainelDeCamadas::moveParaBaixo()
{
    if (selecionada > 0)
    {
        std::swap(camadas[selecionada], camadas[selecionada - 1]);
        std::swap(labels[selecionada], labels[selecionada - 1]);
        std::swap(visibilidade[selecionada], visibilidade[selecionada - 1]);
        selecionada--;
        if (ptrCamadas)
        {
            ptrCamadas->moveParaBaixo(ptrCamadas->getCamada(selecionada));
        }
    }
}

void PainelDeCamadas::selecionar(int index)
{
    if (index >= 0 && index < camadas.size())
    {
        selecionada = index;
    }
}

void PainelDeCamadas::alternarVisibilidade()
{
    if (selecionada >= 0 && selecionada < visibilidade.size())
    {
        visibilidade[selecionada] = !visibilidade[selecionada];
    }
}

void PainelDeCamadas::render()
{
    float yBase = 20;
    for (size_t i = 0; i < camadas.size(); i++)
    {
        //if (!visibilidade[i]) continue;

        if (selecionada == i)
        {
            CV::color(1); // Cor para a camada selecionada
        }
        else if (!visibilidade[i])
        {
            CV::color(3); // Cor para camadas invisiveis
        }
        else
        {
            CV::color(5); // Cor para camadas visiveis
        }

        CV::rectFill(10, yBase, 190, yBase + 40);

        CV::color(0, 0, 0);
        CV::text(15, yBase + 25, labels[i].c_str());

        yBase += 50;
    }

    btCima->render();
    btBaixo->render();
    btVisibilidade->render();
}
