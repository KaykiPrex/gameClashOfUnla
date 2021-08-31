#include "Caja.h"

void caja_Crear(Caja &caja){
}
void caja_Destruir(Caja &caja){
    caja.id = 0 ;
    caja.recurso = noAsignado ;
    caja.cantItem = 0 ;
}

/* Setter y Getter */
void caja_SetId(Caja &caja , int dato ){
    caja.id = dato;
}
void caja_SetRecurso(Caja &caja , e_recurso dato ){
    caja.recurso = dato ;
}
void caja_SetCantItem(Caja &caja , int dato ){
    caja.cantItem = dato;
}

int caja_GetId(Caja &caja){
    return caja.id;
}
e_recurso caja_GetRecurso(Caja &caja){
    return caja.recurso;
}
int caja_GetCantItem(Caja &caja){
    return caja.cantItem;
}
