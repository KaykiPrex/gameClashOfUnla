#include "Textura.h"



void cargarTextura( SDL_Texture *&img , SDL_Rect &rect ,std::string path ,SDL_Renderer *renderer , float multiplicadorW , float multiplicadorH){
    int wImg , hImg ;
    img = IMG_LoadTexture(renderer , path.c_str());

    SDL_QueryTexture(img, NULL, NULL, &wImg, &hImg);
    rect.x = 0;
	rect.y = 0;
	rect.w = wImg/multiplicadorW;
	rect.h = hImg/multiplicadorH;
}

void cargarTexturaCopia( SDL_Texture *&img ,std::string path ,SDL_Renderer *renderer ){

    img = IMG_LoadTexture(renderer , path.c_str());
}

void dibujarTexturaxFrame(int frameADibujar , int frameActual ,SDL_Rect &rect ,SDL_Renderer *renderer, SDL_Texture *img){
   if (frameADibujar == frameActual) SDL_RenderCopy(renderer, img, NULL, &rect);
}

void dibujarTexturaxRangoFrame(int valor1Rango , int valor2Rango , int frameActual ,SDL_Rect *rect ,SDL_Renderer *renderer, SDL_Texture *img){
   if ((frameActual >= valor1Rango) && (frameActual <= valor2Rango )) SDL_RenderCopy(renderer, img, NULL, rect);
}
