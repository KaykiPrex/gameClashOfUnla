#ifndef MINA_H_INCLUDED
#define MINA_H_INCLUDED

#define MAXSEC 5
#include "Cola.h"
#include "Caja.h"

/* Tipo de dato y atributos */

typedef struct {

        int id;
        int posx;
        int posy;
        Cola cajas;
        int intervalo;
        Caja* secuencia;
        bool vacia ;

        }Mina;

/* Crear y Destruir */
/**
    PRE: La mina no debe haber sido creado ni destruido con anterioridad.
    POST: Devuelve la mina creado con ID, pos X e Y, cola cajas, intervalo
    de produccion , secuencia y si esta vacia.
*/
void mina_Crear(Mina &mina);
/**
    PRE: La mina debe haber sido creada.
    POST: El mina queda inutilizable.
*/
void mina_Destruir(Mina &mina);

/* Setter y Getter */
/**
    PRE: La mina debe haber sido creada. El id debe ser mayor a cero.
    POST: El id queda registrado en la mina.
*/
void mina_SetId(Mina &mina , int dato );
/**
    PRE: La mina debe haber sido creada. La pos X debe ser mayor o igual a cero.
    POST: La pos X  queda registrado en la mina.
*/
void mina_SetPosx(Mina &mina , int dato );
/**
    PRE: La mina debe haber sido creada. La pos Y debe ser mayor o igual a cero.
    POST: La pos Y queda registrado en la mina.
*/
void mina_SetPosy(Mina &mina , int dato );
/**
    PRE: La mina debe haber sido creada.
    POST: Agrega caja a la cola de la mina.
*/
void mina_agregarCajas(Mina &mina,Caja* &dato);
/**
    PRE: La mina debe haber sido creada. El intervalo debe ser mayor a cero.
    POST: El intervalo queda registrado en la mina.
*/
void mina_SetIntervalo(Mina &mina , int dato );
/**
    PRE: La mina debe haber sido creada. La secuencia debe ser mayor a cero.
    POST: La secuencia queda registrado en la mina.
*/
void mina_SetSecuencia(Mina &mina , int pos ,int dato1 , e_recurso dato2 );
/**
    PRE: La mina debe haber sido creada.
    POST: Si la mina esta vacia queda registrado en la mina.
*/
void mina_SetVacia(Mina &mina , bool dato);


/**
    PRE: La mina debe haber sido creada.
    POST: Devuelve el id de la mina. La mina queda inalterable.
*/
int mina_GetId(Mina &mina);
/**
    PRE: La mina debe haber sido creada.
    POST: Devuelve la posicion x de la mina. La mina queda inalterable.
*/
int mina_GetPosx(Mina &mina);
/**
    PRE: La mina debe haber sido creada.
    POST: Devuelve la posicion y de la mina. La mina queda inalterable.
*/
int mina_GetPosy(Mina &mina);
/**
    PRE: La mina debe haber sido creada.
    POST: Devuelve la primer caja de la mina sin sacarla.
*/
Caja mina_GetCajita(Mina &mina);
/**
    PRE: La mina debe haber sido creada.
    POST: Devuelve la cola de cajas.
*/
Cola mina_GetColaCajas (Mina mina);
/**
    PRE: La mina debe haber sido creada.
    POST: Devuelve el intervalo de la mina. La mina queda inalterable.
*/
int mina_GetIntervalo(Mina &mina);
/**
    PRE: La mina debe haber sido creada.
    POST: Devuelve el vector secuencia de cajas de la mina. La mina queda inalterable.
*/
Caja* mina_GetSecuencia(Mina &mina);//-
/**
    PRE: La mina debe haber sido creada.
    POST: Saca una caja de la cola.
*/
void mina_EliminarRecurso(Mina &mina);
/**
    PRE: La mina debe haber sido creada.
    POST: Devuelve si la mina esta vacia.
*/
bool mina_GetVacia(Mina &mina );

#endif // MINA_H_INCLUDED
