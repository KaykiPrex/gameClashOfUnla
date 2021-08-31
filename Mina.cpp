#include "Mina.h"

void mina_Crear(Mina &mina){
    mina.id = 0 ;
    mina.posx = 0 ;
    mina.posy = 0 ;
    crearCola(mina.cajas);
    mina.intervalo = 0 ;
    mina.secuencia = new Caja[4];
    mina.vacia = true ;
}
void mina_Destruir(Mina &mina){
    delete &mina;
}


void mina_SetId(Mina &mina , int dato ){
    mina.id = dato;
}
void mina_SetPosx(Mina &mina , int dato ){
    mina.posx = dato ;
}
void mina_SetPosy(Mina &mina , int dato ){
    mina.posy = dato ;
}
void mina_agregarCajas(Mina &mina , Caja* dato ){
    encolar(mina.cajas,dato)  ;
}
void mina_SetIntervalo(Mina &mina , int dato ){
    mina.intervalo = dato ;
}
void mina_SetSecuencia(Mina &mina , int pos ,int dato1 , e_recurso dato2 ){//------------
        caja_SetCantItem(mina.secuencia[pos],dato1) ;
        caja_SetRecurso(mina.secuencia[pos],dato2)  ;
}
void mina_SetVacia(Mina &mina , bool dato){
    mina.vacia = dato ;
}


int mina_GetId(Mina &mina){
    return mina.id;
}
int mina_GetPosx(Mina &mina){
    return mina.posx;
}
int mina_GetPosy(Mina &mina){
    return mina.posy;
}
Caja mina_GetCajita(Mina &mina){ //-------------
    return *((Caja*)colaFrente(mina.cajas));
}
Cola mina_GetColaCajas (Mina mina){
    return mina.cajas;
}
int mina_GetIntervalo(Mina &mina){
    return mina.intervalo;
}
Caja* mina_GetSecuencia(Mina &mina){
    return mina.secuencia; //---------------------
}
void mina_EliminarRecurso(Mina &mina){
    desencolar(mina.cajas);
}
bool mina_GetVacia(Mina &mina ){
    return mina.vacia;
}
