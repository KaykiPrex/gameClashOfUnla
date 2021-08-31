#ifndef TEXTURA_H_INCLUDED
#define TEXTURA_H_INCLUDED


#include <string>
#include <iostream>
//-----------------SDL------------------------------------------
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
//---------------Path Images------------------------------------
//fondo//
#define IMG_BG_PATH "./img/mapa.png"
#define IMG_CUADRICULA_PATH "./img/mapa_cuadricula.png"
#define IMG_MENU_PATH "./img/menu.png"
#define IMG_PRESS_START_PATH "./img/Press-start.png"
#define IMG_GAMEOVER_F0_PATH "./img/gameover/pantallagameover0.png"
#define IMG_GAMEOVER_F1_PATH "./img/gameover/pantallagameover1.png"
#define IMG_GAMEOVER_F2_PATH "./img/gameover/pantallagameover2.png"
#define IMG_GAMEOVER_F3_PATH "./img/gameover/pantallagameover3.png"
#define IMG_INTERFAZSCORE_PATH "./img/interfazrecursos.png"
#define IMG_BG_BLACK_PATH "./img/bgblack.png"
#define IMG_WINGAME_PATH "./img/victoria/wingame.png"
//Pausa//
#define IMG_STOP_PATH "./img/stop.png"
#define IMG_TRIBUTO_BG_PATH "./img/tributo_bg.png"
#define IMG_TRIBUTO_DER_PATH "./img/tributo_escoltaDer.png"
#define IMG_TRIBUTO_IZQ_PATH "./img/tributo_escoltaIzq.png"
#define IMG_TRIBUTO_BANDIDO_PATH "./img/tributo_bandido.png"

//tren//
#define IMG_TRENRIGHT1_PATH "./img/trenright1.png"
#define IMG_TRENRIGHT2_PATH "./img/trenright2.png"
#define IMG_TRENLEFT1_PATH "./img/trenleft1.png"
#define IMG_TRENLEFT2_PATH "./img/trenleft2.png"
#define IMG_TRENUP1_PATH "./img/trenup1.png"
#define IMG_TRENUP2_PATH "./img/trenup2.png"
#define IMG_TRENDOWN1_PATH "./img/trendown1.png"
#define IMG_TRENDOWN2_PATH "./img/trendown2.png"
//moneda//
#define IMG_COIN_PATH "./img/moneda.png"
//bandido//
#define IMG_BANDIDO_PATH "./img/bandido.png"
#define IMG_BANDIDO_LLAMA_PATH "./img/llama/frame_0.png"
#define IMG_BANDIDO_LLAMA1_PATH "./img/llama/frame_1.png"
#define IMG_BANDIDO_LLAMA2_PATH "./img/llama/frame_2.png"
#define IMG_BANDIDO_LLAMA3_PATH "./img/llama/frame_3.png"
#define IMG_BANDIDO_LLAMA4_PATH "./img/llama/frame_4.png"
#define IMG_BANDIDO_LLAMA5_PATH "./img/llama/frame_5.png"
#define IMG_BANDIDO_LLAMA6_PATH "./img/llama/frame_6.png"
#define IMG_BANDIDO_LLAMA7_PATH "./img/llama/frame_7.png"
//estacion//
#define IMG_ESTACION_PATH"./img/estacion.png"
//mina//
#define IMG_MINA_PATH"./img/mina_llena.png"
#define IMG_MINA_VACIA_PATH"./img/mina_vacia.png"
//vagon//
#define IMG_VAGON_PATH"./img/vagon.png"
#define IMG_VAGON00_PATH"./img/vagones/vagon00.png"
#define IMG_VAGON01_PATH"./img/vagones/vagon01.png"
#define IMG_VAGON02_PATH"./img/vagones/vagon02.png"
#define IMG_VAGON03_PATH"./img/vagones/vagon03.png"
#define IMG_VAGON04_PATH"./img/vagones/vagon04.png"
#define IMG_VAGON05_PATH"./img/vagones/vagon05.png"
#define IMG_VAGON06_PATH"./img/vagones/vagon06.png"
#define IMG_VAGON07_PATH"./img/vagones/vagon07.png"
#define IMG_VAGON08_PATH"./img/vagones/vagon08.png"
#define IMG_VAGON09_PATH"./img/vagones/vagon09.png"
#define IMG_VAGON010_PATH"./img/vagones/vagon010.png"
#define IMG_VAGON011_PATH"./img/vagones/vagon011.png"
#define IMG_VAGON012_PATH"./img/vagones/vagon012.png"
#define IMG_VAGON013_PATH"./img/vagones/vagon013.png"
#define IMG_VAGON014_PATH"./img/vagones/vagon014.png"
#define IMG_VAGON015_PATH"./img/vagones/vagon015.png"
#define IMG_VAGON016_PATH"./img/vagones/vagon016.png"
#define IMG_VAGON017_PATH"./img/vagones/vagon017.png"
#define IMG_VAGON018_PATH"./img/vagones/vagon018.png"
#define IMG_VAGON019_PATH"./img/vagones/vagon019.png"
#define IMG_VAGON020_PATH"./img/vagones/vagon020.png"
#define IMG_VAGON021_PATH"./img/vagones/vagon021.png"
#define IMG_VAGON022_PATH"./img/vagones/vagon022.png"
#define IMG_VAGON023_PATH"./img/vagones/vagon023.png"
#define IMG_VAGON024_PATH"./img/vagones/vagon024.png"
#define IMG_VAGON025_PATH"./img/vagones/vagon025.png"
#define IMG_VAGON026_PATH"./img/vagones/vagon026.png"
#define IMG_VAGON027_PATH"./img/vagones/vagon027.png"
#define IMG_VAGON028_PATH"./img/vagones/vagon028.png"



//--------------------------------------------------------------

/**
    PRE: Los multiplicadores deben ser mayor a 0. En 1 es el valor por defecto .
    POST: Carga la textura a una imagen pudiendo modificar el tamanio.

    img: Imagen donde se almacenara la textura.
    path: Ruta de la imagen.
    multiplicador: Para incrementar o disminuir el tamanio de imagen , por defecto en 1.
*/
void cargarTextura( SDL_Texture *&img , SDL_Rect &rect ,std::string path ,SDL_Renderer *renderer , float multiplicadorW , float multiplicadorH) ;
/**
    PRE:
    POST: Carga la textura a una imagen.

    img: Imagen donde se almacenara la textura.
    path: Ruta de la imagen.
*/
void cargarTexturaCopia( SDL_Texture *&img ,std::string path ,SDL_Renderer *renderer );
/**
    PRE: Los frames deben ser mayor que 0 .
    POST: Dibuja la imagen en el frame seleccionado.

    frameADibujar: Numero de cuadro donde se quiere dibujar la imagen.
    frameActual: Numero actual de cuadro dentro del tiempo del juego.
*/
void dibujarTexturaxFrame(int frameADibujar , int frameActual ,SDL_Rect &rect ,SDL_Renderer *renderer, SDL_Texture *img);
/**
    PRE: Los frames y los rangos deben ser mayor que 0 .
    POST: Dibuja la imagen en los rangos de frames seleccionados.

    frameActual: Numero actual de cuadro dentro del tiempo del juego.
    valor1Rango: Rango del frame inicial.
    valor2Rango: Rango del frame final.
*/
void dibujarTexturaxRangoFrame(int valor1Rango , int valor2Rango , int frameActual ,SDL_Rect *rect ,SDL_Renderer *renderer, SDL_Texture *img);



#endif // TEXTURA_H_INCLUDED
