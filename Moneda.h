#ifndef MONEDA_H_INCLUDED
#define MONEDA_H_INCLUDED

#include "SDL.h"

/* Tipo de dato y atributos */

typedef struct {
        int id;
        int posx;
        int posy;
        int duracion;
        bool activo ;
        SDL_Rect rect;
        }Moneda;

/* Crear y Destruir */
/**
    PRE: La moneda no debe haber sido creada ni destruida con anterioridad.
    POST: Devuelve la moneda creada con el ID, la posicion, duracion , actividad y rectangulo.
*/
void moneda_Crear(Moneda &moneda);
/**
    PRE: La moneda debe haber sido creada.
    POST: la moneda queda inutilizable.
*/
void moneda_Destruir(Moneda &moneda);

/* Setter y Getter */
/**
    PRE: La moneda debe haber sido creada. El id debe ser mayor a cero.
    POST: El id queda registrado en la moneda.
*/
void moneda_SetId(Moneda &moneda , int dato );
/**
    PRE: La moneda debe haber sido creada. La Posicion x debe ser mayor o igual a cero.
    POST: La Posicion x  queda registrado en la moneda.
*/
void moneda_SetPosx(Moneda &moneda , int dato );
/**
    PRE: La moneda debe haber sido creada. La Posicion y debe ser mayor o igual a cero.
    POST: La Posicion y queda registrado en la moneda.
*/
void moneda_SetPosy(Moneda &moneda , int dato );
/**
    PRE: La moneda debe haber sido creada. La duracion debe ser mayor a cero.
    POST: La duracion queda registrado en la moneda.
*/
void moneda_SetDuracion(Moneda &moneda , int dato );
/**
    PRE: La moneda debe haber sido creada.
    POST: La actividad queda registrado en la moneda.
*/
void moneda_SetActivo(Moneda &moneda , bool dato );
/**
    PRE: La moneda debe haber sido creada.
    POST: El rectangulo queda registrado en la moneda.
*/
void moneda_SetRect(Moneda &moneda,int h,int w,int x,int y );

/**
    PRE: La moneda debe haber sido creada.
    POST: Devuelve el ID de la moneda.La moneda queda inalterable.
*/
int moneda_GetId(Moneda &moneda);
/**
    PRE: La moneda debe haber sido creada.
    POST: Devuelve la posicion x de la moneda.La moneda queda inalterable.
*/
int moneda_GetPosx(Moneda &moneda);
/**
    PRE: La moneda debe haber sido creada.
    POST: Devuelve la posicion y de la moneda.La moneda queda inalterable.
*/
int moneda_GetPosy(Moneda &moneda);
/**
    PRE: La moneda debe haber sido creada.
    POST: Devuelve la duracion de la moneda.La moneda queda inalterable.
*/
int moneda_GetDuracion(Moneda &moneda);
/**
    PRE: La moneda debe haber sido creada.
    POST: Devuelve la actividad de la moneda.La moneda queda inalterable.
*/
bool moneda_GetActivo(Moneda &moneda);
/**
    PRE: La moneda debe haber sido creada.
    POST: Devuelve el rectangulo de la moneda.La moneda queda inalterable.
*/
SDL_Rect* moneda_GetRect(Moneda &moneda);



#endif // MONEDA_H_INCLUDED
