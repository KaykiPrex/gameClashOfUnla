#include "Moneda.h"

void moneda_Crear(Moneda &moneda){
    moneda.id = 0 ;  //******
    moneda.posx = 0  ;
    moneda.posy = 0 ;
    //moneda.aparicion = 0 ;
    moneda.duracion = 0 ;
    moneda.activo = true;

    moneda.rect.h = 0 ;
    moneda.rect.w = 0 ;
    moneda.rect.x = 0 ;
    moneda.rect.y = 0 ;

}
void moneda_Destruir(Moneda &moneda){  // Moneda *moneda   ... delete moneda;
    delete &moneda;
}

//-----------/* Setter  */-----------------------//
void moneda_SetId(Moneda &moneda , int dato ){
    moneda.id = dato;
}
void moneda_SetPosx(Moneda &moneda , int dato ){
    moneda.posx = dato ;
}
void moneda_SetPosy(Moneda &moneda , int dato ){
    moneda.posy = dato ;
}
//void moneda_SetAparicion(Moneda &moneda , int dato ){
 //   moneda.aparicion = dato;
//}
void moneda_SetDuracion(Moneda &moneda , int dato ){
    moneda.duracion = dato ;
}
void moneda_SetActivo(Moneda &moneda , bool dato ){
    moneda.activo = dato;
}
void moneda_SetRect(Moneda &moneda , int h , int w, int x, int y  ){
    moneda.rect.h = h ;
    moneda.rect.w = w ;
    moneda.rect.x = x ;
    moneda.rect.y = y ;
}

//-----------/* Getter */------------------------//
int moneda_GetId(Moneda &moneda){
    return moneda.id;
}
int moneda_GetPosx(Moneda &moneda){
    return moneda.posx;
}
int moneda_GetPosy(Moneda &moneda){
    return moneda.posy;
}
//int moneda_GetAparicion(Moneda &moneda){
    //return moneda.aparicion;
//}
int moneda_GetDuracion(Moneda &moneda){
    return moneda.duracion;
}
bool moneda_GetActivo(Moneda &moneda){
    return moneda.activo;
}
SDL_Rect* moneda_GetRect(Moneda &moneda){ //*************
    return &moneda.rect;
}




