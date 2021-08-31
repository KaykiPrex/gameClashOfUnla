#include "AdministrarTiempos.h"



Uint32 timegame(Uint32 startTime , Uint32 pausedTicks){
    return SDL_GetTicks() - startTime - pausedTicks;
}

Uint32 intervaloSeg(float seg ,Uint32 startTime , Uint32 pausedTicks){ // se usa para la aparicion y duracion
    return ((seg*1000)+timegame(startTime,pausedTicks))  ;
}

//----------------------------------------------------------------------------------------------------------------------------//
    /* INTERVALOS DEL JUEGO */
//----------------------------------------------------------------------------------------------------------------------------//
Uint32 intervalo_ADDTIME(Uint32 intervaloNuevo , Uint32 intervaloActual){
    return (intervaloNuevo+intervaloActual) ;
}
//----------------------------------------------------------------------------------------------------------------------------//
bool intervalo_PASSED (Uint32 intervalo_timegame , Uint32 intervalo_timeout){
    bool paso = false ;
        if ( ( (Sint32)(intervalo_timeout - intervalo_timegame )  ) <= 0 ) {
                paso = true;
        }
    return paso;
}
//----------------------------------------------------------------------------------------------------------------------------//
//                          duracion en Seg    ,Tiempo en milisegundos totales, numero del Intervalo actual que esta en marcha
void intervalo_GAME(Uint32 &duracionIntervalo , Uint32 &tiempoIntervalo , Uint32 &IntervaloActual , Uint32 startTime, Uint32 pausedTicks){

     if (SDL_TICKS_PASSED(timegame(startTime,pausedTicks),tiempoIntervalo )   ){
         tiempoIntervalo = intervaloSeg(duracionIntervalo,startTime,pausedTicks) ;
         IntervaloActual += 1 ;
     }
}
//----------------------------------------------------------------------------------------------------------------------------//

//----------------------------------------------------------------------------------------------------------------------------//
void fpsgame(Uint32 &frame , Uint32 &tiempoFPS , Uint32 framesPS , Uint32 startTime, Uint32 pausedTicks){

     if (SDL_TICKS_PASSED(timegame(startTime,pausedTicks),tiempoFPS )   ){
         tiempoFPS = intervaloSeg((1.0/FPS),startTime,pausedTicks) ;
         frame += 1 ;
     }

    if (frame==30){
        frame = 1 ;
    }
}
