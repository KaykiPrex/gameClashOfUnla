#ifndef ADMINISTRARMONEDAS_H_INCLUDED
#define ADMINISTRARMONEDAS_H_INCLUDED

#include "Mapa.h"
#include "Lista.h"
#include "Moneda.h"
#include "SDL.h"
#include "Tren.h"
#include <stdlib.h>

/**
    PRE: La lista de monedas debe haber sido creada.
    POST: Agrega una moneda a la lista .
*/
void agregarMonedas(Lista &listaMoneda,int &idMoneda, int intervaloMax , int duracionMax , Uint32 intervaloActual , Uint32 &tiempo_intervalo ,Mapa [][MPOSY]);
/**
    PRE: La lista de monedas debe haber sido creada.
    POST: Muestra todas las monedas .
*/
void mostrarMonedas(Lista listaMoneda, Uint32 intervaloActual , Tren* ptrTren ,Mapa [][MPOSY] ,SDL_Texture *&img_coin,SDL_Renderer *renderer );
#endif // ADMINISTRARMONEDAS_H_INCLUDED
