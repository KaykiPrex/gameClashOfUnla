#include "Vagon.h"

void vagon_Crear(Vagon &vagon){
    vagon.id = 0;
    vagon.capacidad = 0 ;
    vagon.rect.h = 40 ;
    vagon.rect.w = 50 ;
    vagon.rect.x = 0 ;
    vagon.rect.y = 0 ;
    vagon.posx = 0 ;
    vagon.posy = 0 ;
    vagon.posPreviax = 0 ;
    vagon.posPreviay = 0 ;
    vagon.cantItem = 0 ;
    crearPila(vagon.cajas);
    vagon.recurso = noAsignado;
    vagon.nroImg = 0 ;
}
void vagon_Destruir(Vagon &vagon){
    delete &vagon;
}

/* Setter y Getter */
void vagon_SetId(Vagon &vagon , int dato ){
    vagon.id = dato;
}
void vagon_SetCapacidad(Vagon &vagon , int dato ){
    vagon.capacidad = dato;
}
void vagon_SetRect(Vagon &vagon,int h,int w,int x,int y ){
    vagon.rect.h = h ;
    vagon.rect.w = w ;
    vagon.rect.x = x ;
    vagon.rect.y = y ;
}
void vagon_SetPosPreviax(Vagon &vagon , int dato ){
    vagon.posPreviax = dato ;
}
void vagon_SetPosPreviay(Vagon &vagon , int dato ){
    vagon.posPreviay = dato ;
}
void vagon_SetPosx(Vagon &vagon , int dato ){
    vagon.posx = dato ;
}
void vagon_SetPosy(Vagon &vagon , int dato ){
    vagon.posy = dato ;
}
void vagon_ApilarCaja(Vagon &vagon , Caja* dato ){
    agregar(vagon.cajas,dato);
}
void vagon_SetCantItem(Vagon &vagon , int dato ){
    vagon.cantItem = dato ;
}
void vagon_SetRecurso(Vagon &vagon , e_recurso dato ){
    vagon.recurso = dato ;
}
void vagon_SetNroImg(Vagon &vagon , int dato ){
    vagon.nroImg = dato ;
}

int vagon_GetId(Vagon &vagon){
    return vagon.id;
}
int vagon_GetCapacidad(Vagon &vagon){
    return vagon.capacidad;
}
SDL_Rect* vagon_GetRect(Vagon &vagon){
    return &vagon.rect;
}
int vagon_GetPosPreviax(Vagon &vagon){
    return vagon.posPreviax;
}
int vagon_GetPosPreviay(Vagon &vagon){
    return vagon.posPreviay;
}
int vagon_GetPosx(Vagon &vagon){
    return vagon.posx;
}
int vagon_GetPosy(Vagon &vagon){
    return vagon.posy;
}
Pila vagon_GetPilaCajas(Vagon &vagon){
    return vagon.cajas;
}
Caja* vagon_GetCimaCaja(Vagon &vagon){
    return  (Caja*)cima(vagon.cajas)->ptrDato   ;
}
int vagon_GetCantItem(Vagon &vagon){
    return vagon.cantItem;
}
e_recurso vagon_GetRecurso(Vagon &vagon){
    return vagon.recurso;
}
int vagon_GetNroImg(Vagon &vagon){
    return vagon.nroImg;
}

void vagon_ActualizarPosVagon(Vagon &vagon, int datoX , int datoY){
    vagon.posPreviax = vagon.posx;
    vagon.posPreviay = vagon.posy;
    vagon.posx = datoX;
    vagon.posy = datoY;
}

void vagon_ActualizarRect(Vagon &vagon, int blitx, int blity){
    vagon.rect.x = blity ;
    vagon.rect.y = blitx ;
}




