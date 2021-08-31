#include "Tren.h"

void tren_Crear(Tren &tren)
{
    tren.id = 0 ;
    tren.posx = 0 ;
    tren.posy = 0 ;
    tren.posPreviox = 0 ;
    tren.posPrevioy = 0 ;
    tren.cantCoin = 0 ;
    tren.sentido = abajo;
    tren.borde = sinBorde;
    crearLista(tren.vagones,compararListaVagon );
    tren.rect.h = 40 ;
    tren.rect.w = 40 ;
    tren.rect.x = 0 ;
    tren.rect.y = 0 ;
}
void tren_Destruir(Tren &tren)
{
    delete &tren;
}

//-----------/* Setter  */-----------------------//
void tren_SetId(Tren &tren, int dato)
{
    tren.id = dato ;
}
void tren_SetPosx(Tren &tren , int dato )
{
    tren.posPreviox = tren.posx ;
    tren.posx = dato ;
}
void tren_SetPosy(Tren &tren , int dato )
{
    tren.posPrevioy = tren.posy;
    tren.posy = dato ;
}
void tren_SetPosPreviox(Tren &tren , int dato )
{
    tren.posPreviox = dato ;
}
void tren_SetPosPrevioy(Tren &tren , int dato )
{
    tren.posPrevioy = dato ;
}
void tren_SetCantCoin(Tren &tren , int dato )
{
    tren.cantCoin = dato;
}
void tren_SetSentido(Tren &tren , e_sentido dato )
{
    tren.sentido = dato;
}
void tren_SetBorde(Tren &tren , e_borde dato )
{
    tren.borde = dato;
}
void tren_SetRect(Tren &tren ,int h,int w,int x,int y ){
    tren.rect.h = h ;
    tren.rect.w = w ;
    tren.rect.x = x ;
    tren.rect.y = y ;
}

//-----------/* Getter */------------------------//
int tren_GetId(Tren &tren)
{
    return tren.id;
}
int tren_GetPosx(Tren &tren)
{
    return tren.posx ;
}
int tren_GetPosy(Tren &tren)
{
    return tren.posy;
}
int tren_GetPosPreviox(Tren &tren)
{
    return tren.posPreviox ;
}
int tren_GetPosPrevioy(Tren &tren)
{
    return tren.posPrevioy;
}
int tren_GetCantCoin(Tren &tren)
{
    return tren.cantCoin;
}
e_sentido tren_GetSentido(Tren &tren)
{
    return tren.sentido;
}
e_borde tren_GetBorde(Tren &tren)
{
    return tren.borde;
}
Lista tren_GetVagones(Tren &tren)
{
    return tren.vagones;
}
SDL_Rect* tren_GetRect(Tren &tren){
    return &tren.rect;
}
//-----------/*  */------------------------//

void tren_Movimiento(Tren &tren , Uint32 &tiempoPersonaje , Uint32 startTime ,Uint32 pausa)
{

    if ((tren_GetPosx(tren)>=0) && (tren_GetPosy(tren)>=0)/*&& !(mapa[tren_GetPosx(*ptrTren)][tren_GetPosy(*ptrTren)].ocupado)*/ )  // Si se encuentra dentro del rango del mapa  <Maximos ancho y alto
    {
        // y no esta la posicion ocupada
        if ((tren_GetSentido(tren) == abajo ) && (tren_GetBorde(tren)!= bMaxX) )       // COMPARA EL VALOR MAXIMO ,PARA QUE NO SALGA DEL MAPA
        {
            if (tren_GetPosx(tren)==MPOSX-1)
            {
                tren_SetPosx(tren,MPOSX-1);
                tren_SetBorde(tren,bMaxX);         // borde = bMaxX
            }
            else
            {
                tren_SetPosx(tren,tren_GetPosx(tren)+1) ; // aca tendria que inicializar los 3 bordes
                tren_SetBorde(tren,sinBorde);
            }
        }
        if ((tren_GetSentido(tren) == arriba )&& (tren_GetBorde(tren)!= bMinX))
        {
            if (tren_GetPosx(tren)==0)    // COMPARA EL VALOR MINIMO ,PARA QUE NO SALGA DEL MAPA
            {
                tren_SetPosx(tren,0);
                tren_SetBorde(tren,bMinX);
            }
            else
            {
                tren_SetPosx(tren,tren_GetPosx(tren)-1) ;
                tren_SetBorde(tren,sinBorde);
            }
        }
        if ((tren_GetSentido(tren) == izq ) && (tren_GetBorde(tren)!= bMinY))
        {
            if (tren_GetPosy(tren)==0)     // COMPARA EL VALOR MINIMO ,PARA QUE NO SALGA DEL MAPA
            {
                tren_SetPosy(tren,0);
                tren_SetBorde(tren,bMinY);
            }
            else
            {
                tren_SetPosy(tren,tren_GetPosy(tren)-1);
                tren_SetBorde(tren,sinBorde);
            }
        }
        if ((tren_GetSentido(tren) == der )&& (tren_GetBorde(tren)!= bMaxY))    // COMPARA EL VALOR MAXIMO ,PARA QUE NO SALGA DEL MAPA
        {
            if (tren_GetPosy(tren)==MPOSY-1)
            {
                tren_SetPosy(tren,MPOSY-1);
                tren_SetBorde(tren,bMaxY);
            }
            else
            {
                tren_SetPosy(tren,tren_GetPosy(tren)+1);
                tren_SetBorde(tren,sinBorde);
            }
        }
        tiempoPersonaje =  intervaloSeg(velocidadTren, startTime ,pausa);    // luego se suma 1 segundo al tiempo del personaje //  para aparecer en la proxima pasada
    }                                                                               //intervaloSeg(duracion,timegame())<-- Ej para la moneda o bandido

}

void tren_AgregarVagon(Tren &tren, int setcantcoin)
{   //cantcoin 0 seteoAutomatico, cantcoin>0 otro numero seteo manual por parametro
    if (setcantcoin == 0) setcantcoin = tren.cantCoin;

    Vagon *ptrvagon = new Vagon;
    vagon_Crear(*ptrvagon);
    ptrvagon->rect.x = tren.posx;
    ptrvagon->rect.y = tren.posy;
    ptrvagon->capacidad = 5*setcantcoin;
    ptrvagon->recurso = noAsignado;
    ptrvagon->cantItem = 0 ;
    if (tren.cantCoin==0)   ptrvagon->nroImg = 0 ; /**  */
    else if (tren.cantCoin==1)   ptrvagon->nroImg = rand()%29 ; /**  */
    else if (tren.cantCoin==2)   ptrvagon->nroImg = 7 ; /**  */
    else if (tren.cantCoin==3)   ptrvagon->nroImg = 9 ; /**  */
    else if (tren.cantCoin==4)   ptrvagon->nroImg = 21 ; /**  */
    else if (tren.cantCoin>4)   ptrvagon->nroImg = 1  ; /**  */
    adicionarFinal(tren.vagones,ptrvagon);
}

void tren_EliminarVagon(Tren &tren)
{
    eliminarNodoUltimo(tren.vagones);
}

void tren_ActualizarVagones(Tren &tren,Mapa mapa[][MPOSY])
{
    int posxAux=0 , posyAux=0 ,posxAnterior=0 , posyAnterior=0 ;

    if(longitud(tren.vagones)!=0)
    {
        PtrNodoLista minodo = primero(tren.vagones);
        Vagon* vagon = (Vagon*) minodo->ptrDato;
        posxAnterior = vagon->posx;
        posyAnterior = vagon->posy;
        vagon->posx = tren.posx;
        vagon->posy = tren.posy;
        vagon->rect.y = mapa[tren.posx][tren.posy].blit_posx;
        vagon->rect.x = mapa[tren.posx][tren.posy].blit_posy;

        minodo = siguiente(tren.vagones, minodo);
        while(minodo != finLista())
        {
            Vagon* vagon = (Vagon*) minodo->ptrDato;
            posxAux = vagon->posx;
            posyAux = vagon->posy;
            vagon->posx = posxAnterior;
            vagon->posy = posyAnterior;
            vagon->rect.y = mapa[vagon->posx][vagon->posy].blit_posx;
            vagon->rect.x = mapa[vagon->posx][vagon->posy].blit_posy;
            posxAnterior = posxAux ;
            posyAnterior = posyAux ;

            minodo = siguiente(tren.vagones, minodo);
        }

    }
}

void tren_MostrarVagones(Tren &tren ,SDL_Texture *img_vagon[] ,SDL_Renderer *renderer)
{
    PtrNodoLista minodo = primero(tren.vagones);
    while(minodo != finLista())
        {
            Vagon* vagon = (Vagon*) minodo->ptrDato;
            SDL_RenderCopy(renderer,img_vagon[vagon->nroImg],NULL,&vagon->rect);

            minodo = siguiente(tren.vagones, minodo);
        }

}




