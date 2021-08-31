#ifndef ADMINISTRAREVENTOS_H_INCLUDED
#define ADMINISTRAREVENTOS_H_INCLUDED

#include "SDL.h"
#include "Game.h"
#include "Tren.h"
#include "AdministrarTiempos.h"

/**
    PRE: Se debe haber inicializado el evento.
    POST: Evalua si se presiono una tecla como entrada y detiene la musica .
*/
void eventos_MenuEspera(SDL_Event* evento, bool &salir ,Uint32 &intervalogame ,Uint32 &tiempoIntervalo , Uint32 &timePersonaje , Uint32 &frame , Uint32 startTime,Mix_Music *&bgm , Uint32 pausa);
/**
    PRE: El tren debe haber sido creado.
    POST: Evalua las teclas direccionales presionadas y las guarda en el sentido correspondiente del tren.
*/
void eventos_EntradaTrenSentido(SDL_Event* evento , Tren &ptrTren);
/**
    PRE: Se debe haber inicializado el evento.
    POST: Dibuja la animacion de robo de un bandido.
*/
void eventos_Pausa(SDL_Event* evento,Uint32 &pausedTicks,SDL_Renderer *renderer ,SDL_Texture *&img ,SDL_Texture *&img_bandido,Bandido &bandido,SDL_Texture *&img_stop,SDL_Texture *&img_tributoBg,SDL_Texture *&img_tributoDer ,SDL_Texture *&img_tributoIzq ,SDL_Texture *&img_tributoBandido ,Mix_Music *&bgmTributo);
/**
    PRE: Se debe haber inicializado el evento.
    POST: Evalua si se presiono alguna tecla.
*/
void evento_keyPress(SDL_Event* evento ,bool &flag);













#endif // ADMINISTRAREVENTOS_H_INCLUDED
