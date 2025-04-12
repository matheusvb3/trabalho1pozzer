/* Manipulador de imagens
 * Feito por Matheus Venturini Bortoluzzi
 *
 * O programa carrega 4 imagens BMP em 4 camadas. O painel a esquerda
 * traz as camadas em ordens diferentes, e os botoes "cima" e "baixo"
 * permitem alterar a ordem. Ha tambem um botao de alternar a visibilidade
 * da camada atualmente selecionada, e quando a camada esta escondida o seu
 * botao fica verde no painel, mas a funcionalidade nao esta funcionando corretamente.
 */

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
}

//funcao chamada toda vez que uma tecla for pressionada.
void keyboard(int key)
{

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
            painelCamadas->moveParaCima();
        }

        if (painelCamadas->btBaixo->Colidiu(x, y)) {
            painelCamadas->moveParaBaixo();
        }

        if (painelCamadas->btVisibilidade->Colidiu(x, y))
        {
            painelCamadas->alternarVisibilidade();
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

	painelCamadas = new PainelDeCamadas(0, 0, largPainelUsuario, screenHeight, &camadas);

    painelCamadas->adiciona(img1, "Camada 1");
    painelCamadas->adiciona(img2, "Camada 2");
    painelCamadas->adiciona(img3, "Camada 3");
    painelCamadas->adiciona(img4, "Camada 4");

	CV::init(&screenWidth, &screenHeight, "Manipulador de imagens - Matheus Venturini Bortoluzzi");
	CV::run();
}
