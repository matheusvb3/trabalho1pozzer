#ifndef PAINELDECAMADAS_H
#define PAINELDECAMADAS_H

#include <vector>
#include <memory>
#include "bmp.h"
#include "Botao.h"
#include "Camada.h"

class PainelDeCamadas {
private:
    std::vector<std::shared_ptr<Bmp>> camadas;
    int selecionada;  // Indice da camada selecionada
    Camada* ptrCamadas;

public:
    Botao *btCima;
    Botao *btBaixo;
    PainelDeCamadas(float x, float y, float largura, float altura, Camada* ptrCamadas);

    void adiciona(std::shared_ptr<Bmp> img);
    void moveParaCima();
    void moveParaBaixo();
    void render();
    void selecionar(int index);
    int obterSelecionado() { return selecionada; }
};

#endif



/*class PainelDeCamadas
{
public:
	int x, y, largura, altura, nmrCamadas;


	PainelDeCamadas(int _x, int _y, int _largura, int _altura, int _nmrCamadas)
	{
		x =  _x;
		y =  _y;



		largura = _largura;
		altura = _altura;

		nmrCamadas = _nmrCamadas;

	}

	void renderizaCamada(int x1, int y1, int x2, int y2, int c)
	{
		char temp[8] = "Camada ";
		temp[7] = 48 + (nmrCamadas - c);
		CV::color(0, 0, 0);
		if(nmrCamadas - c == 1)
		{
			CV::color(1, 0, 0);
			CV::rectFill(x1, y1, x2, y2);
			CV::color(0, 0, 0);
		}
		CV::rect(x1, y1, x2, y2);
		CV::text(x1 + (x2 - x1) * 0.1, y1 + (y2 - y1) * 0.4, temp);



	}

	void render()
	{

		CV::color(0, 0, 0);
		CV::rect(x, y, x + largura, y + altura); //fundo do painel

		//renderiza o painel de camadas com base no numero de camadas
		for(int i = 0; i < nmrCamadas; i++)
		{

			renderizaCamada(x, y + altura * 1 / nmrCamadas * i, x + largura, y + altura * 1 / nmrCamadas * (i + 1), i);

		}


	}


};*/
