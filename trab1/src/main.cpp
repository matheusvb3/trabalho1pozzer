#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "gl_canvas2d.h"
#include "bmp.h"
#include "Botao.h"
#include "Checkbox.h"
#include "Camada.h"
#include "PainelDeCamadas.h"

int mouseX, mouseY;

PainelDeCamadas *painelCamadas;

int largPainelUsuario = 200;

Camada camadas;

unsigned char *data = NULL;

int a = 0;

int tam = 4;
int ordem[] = {3, 2, 1, 4};


//largura e altura inicial da tela . Alteram com o redimensionamento de tela.
int screenWidth = 1500, screenHeight = 700;

inline void change(Bmp *teste)
{
	teste = new Bmp(".\\__LAB2\\images\\c.bmp");
	teste->convertBGRtoRGB();
	teste->data = teste->getImage();
	teste->positionX = (screenWidth - teste->width) / 2;
	teste->positionY = (screenHeight - teste->height) / 2;
}



void renderiza(Bmp *teste)
{
	teste->render();

}

void renderizaFlippedH(Bmp *teste)
{
	teste->renderFlippedH();

}
void renderizaFlippedV(Bmp *teste)
{
	teste->renderFlippedV();

}
void renderizaFlippedHV(Bmp *teste)
{
	teste->renderFlippedHV();

}

void movimenta(Bmp *teste, int d)
{
	if(d == 200)  teste->positionX -= 60;
	if(d == 201)  teste->positionY += 60;
	if(d == 203)  teste->positionY -= 60;
	if(d == 202)  teste->positionX += 60;


}


void render()
{
    CV::translate(largPainelUsuario, 0);
    int tamQuadriculado = 8;
    for (int linha = 0; linha < screenHeight / (tamQuadriculado - 1); linha++)
    {
        for (int coluna = 0; coluna < screenWidth / tamQuadriculado; coluna++)
        {
            ((linha + coluna) % 2 == 0) ? CV::color(13) : CV::color(1);
            CV::rectFill(coluna * tamQuadriculado, linha * tamQuadriculado,
                         coluna * tamQuadriculado + tamQuadriculado, linha * tamQuadriculado + tamQuadriculado);
        }
    }
    CV::translate(0, 0);

	if(a == 1)
	{
		CV::text(1250, 600, "teste");
	}

	camadas.render();

	painelCamadas->render();


	//img1->render();
	// if(exibition == 2)  img2 ->render();
	//teste->render(posX, posY);
}

//funcao chamada toda vez que uma tecla for pressionada.
void keyboard(int key)
{

	/*if(key == 200)
		switch(ordem[0])
		{
		case 1:
			movimenta(img1, 200);
			break;
		case 2:
			movimenta(img2, 200);
			break;
		case 3:
			movimenta(img3, 200);
			break;
		case 4:
			movimenta(img4, 200);
			break;
		}

	if(key == 201)

		switch(ordem[0])
		{
		case 1:
			movimenta(img1, 201);
			break;
		case 2:
			movimenta(img2, 201);
			break;
		case 3:
			movimenta(img3, 201);
			break;
		case 4:
			movimenta(img4, 201);
			break;
		}

	if(key == 203)
		switch(ordem[0])
		{
		case 1:
			movimenta(img1, 203);
			break;
		case 2:
			movimenta(img2, 203);
			break;
		case 3:
			movimenta(img3, 203);
			break;
		case 4:
			movimenta(img4, 203);
			break;
		}
	if(key == 202)
		switch(ordem[0])
		{
		case 1:
			movimenta(img1, 202);
			break;
		case 2:
			movimenta(img2, 202);
			break;
		case 3:
			movimenta(img3, 202);
			break;
		case 4:
			movimenta(img4, 202);
			break;
		}*/



	/*  if(key == 200)  img1->positionX -= 60;
	  if(key == 201)  img1->positionY += 60;
	  if(key == 203)  img1->positionY -= 60;
	  if(key == 202)  img1->positionX += 60;*/

	printf("%d ", key);



	if(key == 49)
	{
		for(int q = 0; q < tam; q++) if(ordem[q] == 1)
			{
				ordem[q] = ordem[0];
			}
		ordem[0] = 1;
		/* img1 = new Bmp(".\\__LAB2\\images\\a.bmp");
		 img1->convertBGRtoRGB();
		 data = img1->getImage();
		 img1->positionX = (screenWidth - img1->width)/2;
		  img1->positionY = (screenHeight - img1->height)/2; */
	}
	if(key == 50)
	{
		for(int q = 0; q < tam; q++) if(ordem[q] == 2)
			{
				ordem[q] = ordem[0];
			}
		ordem[0] = 2;


		/* img1 = new Bmp(".\\__LAB2\\images\\a.bmp");
		  img1->convertBGRtoRGB();
		  data = img1->getImage();
		  img1->positionX = (screenWidth - img1->width)/2;
		  img1->positionY = (screenHeight - img1->height)/2;*/

	}

	if(key == 51)
	{
		for(int q = 0; q < tam; q++) if(ordem[q] == 3)
			{
				ordem[q] = ordem[0];
			}
		ordem[0] = 3;
		/* img1 = new Bmp(".\\__LAB2\\images\\c.bmp");
		  img1->convertBGRtoRGB();
		  data = img1->getImage();
		img1->positionX = (screenWidth - img1->width)/2;
		  img1->positionY = (screenHeight - img1->height)/2;*/
	}
	if(key == 52)
	{
		for(int q = 0; q < tam; q++) if(ordem[q] == 4)
			{
				ordem[q] = ordem[0];
			}
		ordem[0] = 4;
	}
//	if(key == 32) img3->brilho += 0.1;


}

//funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key)
{

}

//funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int wheel, int direction, int x, int y)
{
    mouseX = x;
    mouseY = y;

    if (state == 0) { // Clique do mouse
        if (painelCamadas->btCima->Colidiu(x, y)) {
            painelCamadas->moverParaCima();
        }

        if (painelCamadas->btBaixo->Colidiu(x, y)) {
            painelCamadas->moverParaBaixo();
        }

        // Detecta se clicou em alguma camada e a seleciona
        int camadaSelecionada = (y - 20) / 50;
        painelCamadas->selecionar(camadaSelecionada);
    }
}

int main(void)
{
    auto img1 = std::make_shared<Bmp>(".\\trab1\\images\\a.bmp");
    img1->convertBGRtoRGB();
    img1->positionX = (screenWidth - img1->width) / 2;
    img1->positionY = (screenHeight - img1->height) / 2;

    auto img2 = std::make_shared<Bmp>(".\\trab1\\images\\b.bmp");
    img2->convertBGRtoRGB();
    img2->positionX = (screenWidth - img2->width) / 2;
    img2->positionY = (screenHeight - img2->height) / 2;

    auto img3 = std::make_shared<Bmp>(".\\trab1\\images\\c.bmp");
    img3->convertBGRtoRGB();
    img3->positionX = (screenWidth - img3->width) / 2;
    img3->positionY = (screenHeight - img3->height) / 2;

    auto img4 = std::make_shared<Bmp>(".\\trab1\\images\\d.bmp");
    img4->convertBGRtoRGB();
    img4->positionX = (screenWidth - img4->width) / 2;
    img4->positionY = (screenHeight - img4->height) / 2;

    camadas.adiciona(img1);
    camadas.adiciona(img2);
    camadas.adiciona(img3);
    camadas.adiciona(img4);

	painelCamadas = new PainelDeCamadas(0, 0, largPainelUsuario, screenHeight);

	painelCamadas->adiciona(img1);
    painelCamadas->adiciona(img2);
    painelCamadas->adiciona(img3);
    painelCamadas->adiciona(img4);

	CV::init(&screenWidth, &screenHeight, "Manipulador de imagem");
	CV::run();
}
