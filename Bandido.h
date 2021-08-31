#ifndef BANDIDO_H_INCLUDED
#define BANDIDO_H_INCLUDED

#include "SDL.h"



/* Tipo de dato y atributos */

typedef struct {
        int id ;
        int posx;
        int posy;
        int duracion;
        bool activo ;
        SDL_Rect rect;
        int* recursos ;
    //  TDA pos vect rango
        }Bandido;

/* Crear y Destruir */
/**
    PRE: El bandido no debe haber sido creado ni destruido con anterioridad.
    POST: Devuelve el bandido creado con el ID, la pocision, recurso y su tipo.*/
void bandido_Crear(Bandido &bandido);
/**
    PRE: El bandido debe haber sido creado.
    POST: El bandido queda inutilizable.
*/
void bandido_Destruir(Bandido &bandido);
/**
    PRE: El bandido debe haber sido creado. El id debe ser mayor a cero.
    POST: El id queda registrado en el bandido.
*/

/* Setter y Getter */
void bandido_SetId(Bandido &bandido, int dato);
/**
    PRE: El bandido debe haber sido creado. La posicion x debe ser mayor a cero.
    POST: La posicion x del bandido queda registrado.
*/
void bandido_SetPosx(Bandido &bandido , int dato );
/**
    PRE: El bandido debe haber sido creado. La posicion y debe ser mayor a cero.
    POST: La pocision y del bandido queda registrado.
*/
void bandido_SetPosy(Bandido &bandido , int dato );
/**
    PRE: El bandido debe haber sido creado. La duracion debe ser mayor a cero.
    POST: La duracion del bandido queda registrado.
*/
void bandido_SetDuracion(Bandido &bandido , int dato );
/**
    PRE: El bandido debe haber sido creado.
    POST: Queda registrado la actividad del bandido.
*/
void bandido_SetActivo(Bandido &bandido , bool dato );
/**
    PRE: El bandido debe haber sido creado. La rectangulo del area del bandido debe ser mayor a cero.
    POST: La area del rectangulo del bandido queda registrado.
*/
void bandido_SetRect(Bandido &bandido,int h,int w,int x,int y );
/**
    PRE: El bandido debe haber sido creado. El numero de recursos a pedir del bandido debe ser mayor a cero.
    POST: El recurso del bandido queda registrado.
*/
void bandido_SetRecursos(Bandido &bandido, int recurso , int dato);



/**
    PRE: El bandido debe haber sido creado.
    POST: Devuelve el id del bandido. El bandido queda inalterado.
*/
int bandido_GetId(Bandido &bandido);
/**
    PRE: El bandido debe haber sido creado.
    POST: Devuelve la posicion x del bandido. El bandido queda inalterado.
*/
int bandido_GetPosx(Bandido &bandido);
/**
    PRE: El bandido debe haber sido creado.
    POST: Devuelve la posicion y del bandido. El bandido queda inalterado.
*/
int bandido_GetPosy(Bandido &bandido);
/**
    PRE: El bandido debe haber sido creado.
    POST: Devuelve la duracion del bandido. El bandido queda inalterado.
*/
int bandido_GetDuracion(Bandido &bandido);
/**
    PRE: El bandido debe haber sido creado.
    POST: Devuelve el area del rectangulo del bandido. El bandido queda inalterado.
*/
SDL_Rect* bandido_GetRect(Bandido &bandido);
/**
    PRE: El bandido debe haber sido creado.
    POST: Devuelve si el bandido esta activo del bandido. El bandido queda inalterado.
*/
bool bandido_GetActivo(Bandido &bandido);
/**
    PRE: El bandido debe haber sido creado.
    POST: Devuelve el vector de recursos del bandido. El bandido queda inalterado.
*/
int* bandido_GetRecursos(Bandido &bandido);


#endif // BANDIDO_H_INCLUDED
