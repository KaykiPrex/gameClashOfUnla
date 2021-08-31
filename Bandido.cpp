#include "Bandido.h"

void bandido_Crear(Bandido &bandido){
    bandido.id = 0 ;
    bandido.posx = 0 ; // posicion fuera de la pantalla 800 x 600
    bandido.posy = 0 ;
    bandido.duracion = 0 ;
    bandido.activo = true ;
    bandido.rect.h = 0 ;
    bandido.rect.w = 0 ;
    bandido.rect.x = 0 ;
    bandido.rect.y = 0 ;
    bandido.recursos = new int[6] ;
    bandido.recursos[0] = 0 ;
    bandido.recursos[1] = 0 ;
    bandido.recursos[2] = 0 ;
    bandido.recursos[3] = 0 ;
    bandido.recursos[4] = 0 ;
    bandido.recursos[5] = 0 ;

}
void bandido_Destruir(Bandido &bandido){
    delete &bandido;
}


void bandido_SetId(Bandido &bandido, int dato){
    bandido.id = dato;
}
void bandido_SetPosx(Bandido &bandido , int dato ){
    bandido.posx = dato ;
}
void bandido_SetPosy(Bandido &bandido , int dato ){
    bandido.posy = dato;
}
void bandido_SetDuracion(Bandido &bandido , int dato ){
    bandido.duracion = dato ;
}
void bandido_SetActivo(Bandido &bandido , bool dato ){
    bandido.activo = dato;
}
void bandido_SetRect(Bandido &bandido , int h , int w, int x, int y  ){
    bandido.rect.h = h ;
    bandido.rect.w = w ;
    bandido.rect.x = x ;
    bandido.rect.y = y ;
}
void bandido_SetRecursos(Bandido &bandido, int recurso , int dato){
    bandido.recursos[recurso] = dato ;
}
/*void bandido_SetNumRecurso(Bandido &bandido , int dato ){
    bandido.numRecurso = dato ;
}
void bandido_SetTipoRecurso(Bandido &bandido , int dato ){
    bandido.tipoRecurso = dato ;
}
*/

int bandido_GetId(Bandido &bandido){
    return bandido.id;
}
int bandido_GetPosx(Bandido &bandido){
    return bandido.posx;
}
int bandido_GetPosy(Bandido &bandido){
    return bandido.posy;
}
int bandido_GetDuracion(Bandido &bandido){
    return bandido.duracion;
}
bool bandido_GetActivo(Bandido &bandido){
    return bandido.activo;
}
SDL_Rect* bandido_GetRect(Bandido &bandido){ //*************
    return &bandido.rect;
}
int* bandido_GetRecursos(Bandido &bandido){
    return bandido.recursos;
}
/*int bandido_GetNumRecurso(Bandido &bandido){
    return bandido.numRecurso;
}
int bandido_GetTipoRecurso(Bandido &bandido){
    return bandido.tipoRecurso;
}
*/
