#ifndef VAGON_H_INCLUDED
#define VAGON_H_INCLUDED

#include "SDL.h"
#include "Caja.h"
#include "Pila.h"
/* Tipo de dato y atributos */

typedef struct {

        int id;
        int capacidad;
        SDL_Rect rect;
        int posx;
        int posy;
        int posPreviax ;
        int posPreviay;
        Pila cajas;
        int cantItem;
        e_recurso recurso ;
        int nroImg;
        }Vagon;

/* Crear y Destruir */
/**
    PRE: El Vagon no debe haber sido creado ni destruido con anterioridad.
    POST: Devuelve el vagon creado con el ID, las posiciones , cajas , cantidad de items ,
    recurso ocupado , numero de imagen correspondiente al vagon .
*/
void vagon_Crear(Vagon &vagon);
/**
    PRE: El vagon debe haber sido creado.
    POST: El vagon queda inutilizable.
*/
void vagon_Destruir(Vagon &vagon);

/* Setter y Getter */
/**
    PRE: El vagon debe haber sido creado. El id debe ser mayor a cero.
    POST: El id queda registrado en el vagon.
*/
void vagon_SetId(Vagon &vagon , int dato );
/**
    PRE: El vagon debe haber sido creado.La capacidad debe ser mayor o igual a cero.
    POST: La capacidad queda registrado en el vagon.
*/
void vagon_SetCapacidad(Vagon &vagon , int dato );
/**
    PRE: El vagon debe haber sido creado. El rectangulo del vagon debe ser mayor a cero.
    POST: El rectangulo del vagon queda registrado en el vagon.
*/
void vagon_SetRect(Vagon &vagon,int h,int w,int x,int y );
/**
    PRE: El vagon debe haber sido creado. La posicion x debe ser mayor o igual a cero.
    POST: La pos x queda registrado en el vagon.
*/
void vagon_SetPosx(Vagon &vagon , int dato );
/**
    PRE: El vagon debe haber sido creado. La posicion y debe ser mayor o igual a cero.
    POST: La pos y queda registrado en el vagon.
*/
void vagon_SetPosy(Vagon &vagon , int dato );
/**
    PRE: El vagon debe haber sido creado. La posicion previa x debe ser mayor o igual a cero.
    POST: La posicion x previa queda registrado en el vagon.
*/
void vagon_SetPosPreviax(Vagon &vagon , int dato );
/**
    PRE: El vagon debe haber sido creado.La posicion previa y debe ser mayor o igual a cero.
    POST: La posicion previa y  queda registrado en el vagon.
*/
void vagon_SetPosPreviay(Vagon &vagon , int dato );
/**
    PRE: El vagon debe haber sido creado. La caja debe haber sido creada.
    POST: Apila las cajas en el vagon.
*/
void vagon_ApilarCaja(Vagon &vagon , Caja* dato );
/**
    PRE: El vagon debe haber sido creado. la cantidad de items debe ser mayor o igual a 0.
    POST: La cantidad de items queda registrado en el vagon.
*/
void vagon_SetCantItem(Vagon &vagon , int dato );
/**
    PRE: El vagon debe haber sido creado. El recurso es un enumerado definido.
    POST: El recurso queda registrado en el vagon.
*/
void vagon_SetRecurso(Vagon &vagon , e_recurso dato );
/**
    PRE: El vagon debe haber sido creado. El dato debe ser mayor o igual a cero.
    POST: El numero de imagen correspondiente queda registrado en el vagon.
*/
void vagon_SetNroImg(Vagon &vagon , int dato );

/**
    PRE: El vagon debe haber sido creado.
    POST: Devuelve el ID del vagon.El vagon queda inalterable.
*/
int vagon_GetId(Vagon &vagon);
/**
    PRE: El vagon debe haber sido creado.
    POST: Devuelve la capacidad del vagon.El vagon queda inalterable.
*/
int vagon_GetCapacidad(Vagon &vagon);
/**
    PRE: El tren debe haber sido creado.
    POST: Devuelve el rectangulo del vagon.El vagon queda inalterable.
*/
SDL_Rect* vagon_GetRect(Vagon &vagon);
/**
    PRE: El vagon debe haber sido creado.
    POST: Devuelve la posicion x del vagon.El vagon queda inalterable.
*/
int vagon_GetPosx(Vagon &vagon);
/**
    PRE: El vagon debe haber sido creado.
    POST: Devuelve la posicion y del vagon.El vagon queda inalterable.
*/
int vagon_GetPosy(Vagon &vagon);
/**
    PRE: El vagon debe haber sido creado.
    POST: Devuelve la posicion previa x del vagon.El vagon queda inalterable.
*/
int vagon_GetPosPreviax(Vagon &vagon);
/**
    PRE: El vagon debe haber sido creado.
    POST: Devuelve la posicion previa y del vagon.El vagon queda inalterable.
*/
int vagon_GetPosPreviay(Vagon &vagon);
/**
    PRE: El vagon debe haber sido creado.
    POST: Devuelve la pila de cajas del vagon.El vagon queda inalterable.
*/
Pila vagon_GetPilaCajas(Vagon &vagon);
/**
    PRE: El vagon debe haber sido creado.
    POST: Devuelve la primera caja del vagon sin sacarla.El vagon queda inalterable.
*/
Caja* vagon_GetCimaCaja(Vagon &vagon);
/**
    PRE: El vagon debe haber sido creado.
    POST: Devuelve la cantidad de items del vagon.El vagon queda inalterable.
*/
int vagon_GetCantItem(Vagon &vagon);
/**
    PRE: El vagon debe haber sido creado.
    POST: Devuelve el recurso del vagon.El vagon queda inalterable.
*/
e_recurso vagon_GetRecurso(Vagon &vagon);
/**
    PRE: El vagon debe haber sido creado.
    POST: Devuelve el numero de imagen correspondiente al vagon.El vagon queda inalterable.
*/
int vagon_GetNroImg(Vagon &vagon);

/**
    PRE: El vagon debe haber sido creado.
    POST: Actualiza todas las posiciones del vagon .
*/
void vagon_ActualizarPosVagon(Vagon &vagon, int datoX , int datoY);
/**
    PRE: El vagon debe haber sido creado.
    POST: Actualiza el rectangulo del vagon .
*/
void vagon_ActualizarRect(Vagon &vagon, int blitx, int blity);

#endif // VAGON_H_INCLUDED
