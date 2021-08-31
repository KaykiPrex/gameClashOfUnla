#ifndef ADMINISTRARTIEMPOS_H_INCLUDED
#define ADMINISTRARTIEMPOS_H_INCLUDED

#include "SDL.h"
#define FPS 30
#define velocidadTren 0.6

/**
    PRE: El valor de starttime y pausedticks debe ser mayor o igual a cero.
    POST: Devuelve el tiempo actual del juego .
*/
Uint32 timegame(Uint32 startTime , Uint32 pausedTicks);
/**
    PRE: El valor de starttime y pausedticks debe ser mayor o igual a cero.
    POST: Devuelve la duracion en segundos que se quiere esperar .
*/
Uint32 intervaloSeg(float seg ,Uint32 startTime, Uint32 pausedTicks);
/**
    PRE: El valor de los intervalos debe ser mayor o igual a cero.
    POST: Devuelve un intervalo agregado al intervalo actual.
*/
Uint32 intervalo_ADDTIME(Uint32 intervaloNuevo , Uint32 intervaloActual);
/**
    PRE: El valor de los intervalos debe ser mayor o igual a cero.
    POST: Devuelve verdadero o falso si el intervalo timeout se paso del intervalo del juego.
*/
bool intervalo_PASSED (Uint32 intervalo_timegame , Uint32 intervalo_timeout);
/**
    PRE: El valor de starttime y pausedticks debe ser mayor o igual a cero,
    el valor de los intervalos debe ser mayor o igual a cero.
    POST: Agrega un intervalo si el tiempo transcurrio . Es un controlador de los intervalos del juego.
*/
void intervalo_GAME(Uint32 &duracionIntervalo , Uint32 &tiempoIntervalo , Uint32 &IntervaloActual , Uint32 startTime, Uint32 pausedTicks);
/**
    PRE: El valor de starttime , pausedticks , frames y tiempo debe ser mayor o igual a cero.
    POST: Controla los frames por segundos que tiene el juego . Por defecto 30 .
*/
void fpsgame(Uint32 &frame , Uint32 &tiempoFPS , Uint32 framesPS , Uint32 startTime, Uint32 pausedTicks);


#endif // ADMINISTRARTIEMPOS_H_INCLUDED
