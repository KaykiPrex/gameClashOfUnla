#ifndef ADMINISTRARBANDIDOS_H_INCLUDED
#define ADMINISTRARBANDIDOS_H_INCLUDED

#include "Mapa.h"
#include "Lista.h"
#include "Bandido.h"
#include "SDL.h"
#include "Tren.h"
#include "AdministrarEventos.h"
#include <stdlib.h>

/**
    PRE: La lista de bandido debe haber sido creada.
    POST: Agrega un bandido a la lista .
*/
void agregarBandidos(Lista &listaBandido, int &idbandido, int intervaloMax , int duracionMax ,Uint32 intervaloActual, Uint32 &tiempo_intervalo ,Mapa mapa[][MPOSY], int randMax);
/**
    PRE: La lista de bandido debe haber sido creada.
    POST: Muestra todos los bandidos y los eventos que conllevan (interaccion pausa).
*/
void mostrarBandidos(Lista listaBandido,int inventario[], Uint32 intervaloActual , Tren* ptrTren ,Mapa [][MPOSY] ,bool &gameover,SDL_Texture *&img_bandido,SDL_Renderer *renderer, SDL_Event* evento,Uint32 pausa,SDL_Texture *&img_bg,SDL_Texture *&img_stop,SDL_Texture *&img_tributoBg,SDL_Texture *&img_tributoDer ,SDL_Texture *&img_tributoIzq ,SDL_Texture *&img_tributoBandido ,Mix_Music *&bgm,Mix_Music *&bgmTributo);
/**
    PRE: La lista de vagones debe haber sido creada.
    POST: Recorre la lista de vagones buscando los recursos pedidos por el bandido y los saca .
*/
void robarRecursos(Lista &vagones , int cantOro, int cantPlata , int cantBronce,int inventario[]);
/**
    PRE: El vagon debe haber sido creado.
    POST: Desapila las cajas de un vagon con los recursos pedidos por el bandido .
*/
void robarRecursos_desapilarCajas(Vagon* &vagon ,int &cantRecursoPedido ,bool &flag , int inventario[]);

#endif // ADMINISTRARBANDIDOS_H_INCLUDED
