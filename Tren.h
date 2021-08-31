#ifndef TREN_H_INCLUDED
#define TREN_H_INCLUDED


#include "lista.h"
#include "Mapa.h"
#include "AdministrarTiempos.h"
#include "Vagon.h"

#include <stdlib.h>
#include <cstdlib>
#include "stdio.h"
#include <sstream>




/* Tipo de dato y atributos */
typedef enum  {
    arriba,
    abajo,
    izq,
    der,
    centro,
}e_sentido;


typedef enum  {
    bMinX,
    bMaxX,
    bMinY,
    bMaxY,
    sinBorde,
}e_borde;


typedef struct {
        int id;
        int posx;
        int posy;
        int posPreviox;
        int posPrevioy;
        int cantCoin;
        e_sentido sentido ;
        e_borde borde;
        Lista vagones;
        SDL_Rect rect;
        //bool activo;

        }Tren;

/* Crear y Destruir */
/**
    PRE: El tren no debe haber sido creado ni destruido con anterioridad.
    POST: Devuelve el tren creado con el ID, la posicion, posicion previa, cantidad de monedas , sentido ,borde
    lista de vagones y rectangulo.
*/
void tren_Crear(Tren &tren);
/**
    PRE: El tren debe haber sido creado.
    POST: la tren queda inutilizable.
*/
void tren_Destruir(Tren &tren);

/* Setter y Getter */
/**
    PRE: El tren debe haber sido creado. El id debe ser mayor a cero.
    POST: El id queda registrado en el tren.
*/
void tren_SetId(Tren &tren, int dato);
/**
    PRE: El tren debe haber sido creado. La posicion x debe ser mayor o igual a cero.
    POST: La posicion x queda registrado en el tren.
*/
void tren_SetPosx(Tren &tren , int dato );
/**
    PRE: El tren debe haber sido creado. La posicion y debe ser mayor o igual a cero.
    POST: La posicion y queda registrado en el tren.
*/
void tren_SetPosy(Tren &tren , int dato );
/**
    PRE: El tren debe haber sido creado. La posicion previa x  debe ser mayor o igual a cero.
    POST: La posicion previa x queda registrado en el tren.
*/
void tren_SetPosPreviox(Tren &tren , int dato );
/**
    PRE: El tren debe haber sido creado.La posicion previa y debe ser mayor o igual a cero.
    POST: La posicion previa y queda registrado en el tren.
*/
void tren_SetPosPrevioy(Tren &tren , int dato );
/**
    PRE: El tren debe haber sido creado. La cantidad de monedas debe ser mayor a cero.
    POST: La cantidad de monedas queda registrado en el tren.
*/
void tren_SetCantCoin(Tren &tren , int dato );
/**
    PRE: El tren debe haber sido creado. El sentido es un enumerado definido.
    POST: El sentido queda registrado en el tren.
*/
void tren_SetSentido(Tren &tren , e_sentido dato );
/**
    PRE: El tren debe haber sido creado. El borde debe es un enumerado definido.
    POST: El borde queda registrado en el tren.
*/
void tren_SetBorde(Tren &tren , e_borde dato );
/**
    PRE: El tren debe haber sido creado. El rectangulo del tren debe ser mayor a cero.
    POST: El rectangulo del tren queda registrado en el tren.
*/
void tren_SetRect(Tren &tren,int h,int w,int x,int y );

/**
    PRE: El tren debe haber sido creado.
    POST: Devuelve el ID del tren.El tren queda inalterable.
*/
int tren_GetId(Tren &tren);
/**
    PRE: El tren debe haber sido creado.
    POST: Devuelve la posicion x del tren.El tren queda inalterable.
*/
int tren_GetPosx(Tren &tren);
/**
    PRE: El tren debe haber sido creado.
    POST: Devuelve la posicion y del tren.El tren queda inalterable.
*/
int tren_GetPosy(Tren &tren);
/**
    PRE: El tren debe haber sido creado.
    POST: Devuelve la posicion x previa del tren.El tren queda inalterable.
*/
int tren_GetPosPreviox(Tren &tren);
/**
    PRE: El tren debe haber sido creado.
    POST: Devuelve la posicion y previa del tren.El tren queda inalterable.
*/
int tren_GetPosPrevioy(Tren &tren);
/**
    PRE: El tren debe haber sido creado.
    POST: Devuelve la cantidad de monedas del tren.El tren queda inalterable.
*/
int tren_GetCantCoin(Tren &tren);
/**
    PRE: El tren debe haber sido creado.
    POST: Devuelve el sentido del tren.El tren queda inalterable.
*/
e_sentido tren_GetSentido(Tren &tren);
/**
    PRE: El tren debe haber sido creado.
    POST: Devuelve el borde del tren.El tren queda inalterable.
*/
e_borde tren_GetBorde(Tren &tren);
/**
    PRE: El tren debe haber sido creado.
    POST: Devuelve la lista de vagones del tren.El tren queda inalterable.
*/
Lista tren_GetVagones(Tren &tren);
/**
    PRE: El tren debe haber sido creado.
    POST: Devuelve el rectangulo del tren.El tren queda inalterable.
*/
SDL_Rect* tren_GetRect(Tren &tren);


/**
    PRE: El tren debe haber sido creado.
    POST: Realiza el movimiento del tren
*/
void tren_Movimiento(Tren &tren , Uint32 &tiempoPersonaje , Uint32 startTime ,Uint32 pausa);
/**
    PRE: El tren debe haber sido creado.
    POST: Agrega un vagon al final del tren.

    setcantcoin : 0 - Si no se quiere setear las monedas (circunstancia normal), para test puede tener cualquier valor mayor a 0
*/
void tren_AgregarVagon(Tren &tren, int setcantcoin);
/**
    PRE: El tren debe haber sido creado.
    POST: El vagon del tren queda inutilizable.
*/
void tren_EliminarVagon(Tren &tren);
/**
    PRE: El tren debe haber sido creado.
    POST: Actualiza todas las posiciones de los vagones del tren.
*/
void tren_ActualizarVagones(Tren &tren,Mapa [][MPOSY]);
/**
    PRE : La lista de vagones debe haber sido creada.
    POST: Muestra todos los vagones .

    img_vagon: las imagenes de todos los vagones
*/
void tren_MostrarVagones(Tren &tren ,SDL_Texture *img_vagon[] ,SDL_Renderer *renderer);


#endif // TREN_H_INCLUDED
