#ifndef CAJA_H_INCLUDED
#define CAJA_H_INCLUDED


/* Tipo de dato y atributos */
typedef enum  {
    noAsignado = 0,
    oro,
    plata,
    bronce,
    platino,
    roca,
    carbon,
}e_recurso;

typedef struct {
        int id;
        e_recurso recurso;
        int cantItem;

        }Caja;

/* Crear y Destruir */
/**
    PRE: La caja no debe haber sido creado ni destruido con anterioridad.
    POST: Devuelve la caja creado con ID, recurso y cantidad.
*/
void caja_Crear(Caja &caja);
/**
    PRE: La caja debe haber sido creado.
    POST: La caja queda inutilizable.
*/
void caja_Destruir(Caja &caja);

/* Setter y Getter */
/**
    PRE: La caja debe haber sido creada. El id debe ser mayor a cero.
    POST: El id queda registrado en la caja.
*/
void caja_SetId(Caja &caja , int dato );
/**
    PRE: La caja debe haber sido creada. El recurso debe ser mayor a cero.
    POST: El recurso queda registrado en la caja.
*/
void caja_SetRecurso(Caja &caja , e_recurso dato );
/**
    PRE: La caja debe haber sido creada. La cantidad debe ser mayor a cero.
    POST: La cantidad queda registrado en el caja.
*/
void caja_SetCantItem(Caja &caja , int dato );


/**
    PRE: La caja debe haber sido creada.
    POST: Devuelve el id de la caja. La caja queda inalterable.
*/
int caja_GetId(Caja &caja);
/**
    PRE: La caja debe haber sido creada.
    POST: Devuelve el recurso de la caja.
*/
e_recurso caja_GetRecurso(Caja &caja);
/**
    PRE: La caja debe haber sido creada.
    POST: Devuelve la cantidad de items de la caja. La caja queda inalterable.
*/
int caja_GetCantItem(Caja &caja);


#endif // CAJA_H_INCLUDED
