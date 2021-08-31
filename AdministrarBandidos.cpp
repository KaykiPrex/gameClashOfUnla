#include "AdministrarBandidos.h"

//------------------------------------------------------------------------------------------------------------------------------
void agregarBandidos(Lista &listaBandido, int &idbandido, int intervaloMax , int duracionMax ,Uint32 intervaloActual, Uint32 &tiempo_intervalo ,Mapa mapa[][MPOSY], int randMax)
{
    int mirandomA, mirandomB;

    if(intervalo_PASSED(intervaloActual,tiempo_intervalo))
    {
        Bandido *ptrbandido = new Bandido;
        bandido_Crear(*ptrbandido);
        bandido_SetId(*ptrbandido,idbandido);
        idbandido+= 1 ;
        bandido_SetDuracion(*ptrbandido, intervalo_ADDTIME(rand()%duracionMax,intervaloActual));
        /*posicionAleatoria(*ptrmoneda); o por PosA y PosB ?*/
        mirandomA = rand()%(MPOSX-1);
        mirandomB = rand()%(MPOSY-1);
        bandido_SetPosx(*ptrbandido,mirandomA);
        bandido_SetPosy(*ptrbandido,mirandomB);
        bandido_SetRect(*ptrbandido,40 ,50,mapa[mirandomA][mirandomB].blit_posy,mapa[mirandomA][mirandomB].blit_posx) ;
        bandido_SetRecursos(*ptrbandido,oro,rand()%randMax)    ;  //1-oro    randMax = cantidad maxima que pide el bandido
        bandido_SetRecursos(*ptrbandido,plata,rand()%randMax)  ;  //2-plata
        bandido_SetRecursos(*ptrbandido,bronce,rand()%randMax) ;  //3-bronce
        //
        adicionarFinal(listaBandido, ptrbandido);
        //reordenar(listaBandido);

        tiempo_intervalo = intervalo_ADDTIME((1+rand()%intervaloMax),intervaloActual);

    }

}
void mostrarBandidos(Lista listaBandido,int inventario[], Uint32 intervaloActual , Tren* ptrTren ,Mapa mapa[][MPOSY] ,bool &gameover,SDL_Texture *&img_bandido ,SDL_Renderer *renderer ,SDL_Event* evento,Uint32 pausa,SDL_Texture *&img_bg,SDL_Texture *&img_stop,SDL_Texture *&img_tributoBg ,SDL_Texture *&img_tributoDer ,SDL_Texture *&img_tributoIzq ,SDL_Texture *&img_tributoBandido ,Mix_Music *&bgm ,Mix_Music *&bgmTributo)
{
    SDL_Rect result;
    SDL_Rect rectangle;
    rectangle.x = 0;
    rectangle.y = 0;
    rectangle.w = 40;
    rectangle.h = 40;
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, 255,0, 0, 80);

    PtrNodoLista nodo = primero(listaBandido);
    while(nodo != finLista())
    {
        Bandido* bandido = (Bandido*) nodo->ptrDato;

        rectangle.x = mapa[bandido_GetPosx(*bandido)-1][bandido_GetPosy(*bandido)-1].blit_posy;
        rectangle.y = mapa[bandido_GetPosx(*bandido)-1][bandido_GetPosy(*bandido)-1].blit_posx;
        rectangle.w = (rectangle.w * 2) +rectangle.w ;
        rectangle.h = (rectangle.h * 2) +rectangle.h ;

        if( (intervalo_PASSED(intervaloActual,bandido_GetDuracion(*bandido))) || SDL_IntersectRect(tren_GetRect(*ptrTren) ,&rectangle,&result)/*(mapa[bandido_GetPosx(*bandido)][bandido_GetPosy(*bandido)].ocupado) */)
        {
            if (bandido_GetActivo(*bandido))
            {
                bandido_SetActivo(*bandido,false);
                if(  !(intervalo_PASSED(intervaloActual,bandido_GetDuracion(*bandido)  ) )  )
                {
                    Mix_PlayMusic(bgm,0);
                    Mix_HaltMusic();
                    // if (tieneRecursos) descontarRecursos(vagon);  else eliminarVagon();
                    if(  (inventario[oro] >= bandido_GetRecursos(*bandido)[oro]) &&(inventario[plata] >= bandido_GetRecursos(*bandido)[plata]) &&(inventario[bronce] >= bandido_GetRecursos(*bandido)[bronce])   )
                    {
                        std::cout<<"\n BANDIDO : Hay recursos ->robar ! || Bandido pedido: OROx"<<bandido_GetRecursos(*bandido)[oro]<<" PLATAx"<<bandido_GetRecursos(*bandido)[plata]<<" BRONCEx"<<bandido_GetRecursos(*bandido)[bronce];
                        std::cout<<"\n BANDIDO : Inventario : OROx"<<inventario[oro]<<"PLATAx"<<inventario[plata] <<"BRONCEx"<<inventario[bronce];
                        robarRecursos(ptrTren->vagones, bandido_GetRecursos(*bandido)[oro],bandido_GetRecursos(*bandido)[plata],bandido_GetRecursos(*bandido)[bronce],inventario);

                    }
                    else
                    {
                        std::cout<<"\n BANDIDO : No hay recursos ->destruir vagon";
                        if ( longitud(ptrTren->vagones)== 0 ) gameover = true ;
                        else
                        {
                            Vagon* mivagon =(Vagon*) ultimo(ptrTren->vagones)->ptrDato;
                            if (mivagon->recurso == oro)   inventario[oro] -= mivagon->cantItem ;
                            else if (mivagon->recurso == plata)   inventario[plata] -= mivagon->cantItem ;
                            else if (mivagon->recurso == bronce)   inventario[bronce] -= mivagon->cantItem ;
                            tren_EliminarVagon(*ptrTren);
                        }
                    }


                    eventos_Pausa(evento,pausa,renderer,img_bg,img_bandido,*bandido,img_stop,img_tributoBg,img_tributoDer,img_tributoIzq,img_tributoBandido,bgmTributo);
                    Mix_PlayMusic(bgmTributo,0);
                    Mix_HaltMusic();
                }
                //std::cout<<"\n -Bandido Eliminado- \n";
            }

            //eliminarNodo(listaBandido,&bandido);
            //bandido_Destruir(*bandido);
        }
        else
        {
            if (bandido_GetActivo(*bandido))
            {
                if((bandido_GetPosx(*bandido)>0)&&(bandido_GetPosy(*bandido)>0))  //controla el rango en los bordes , falta terminar
                {
                    SDL_RenderFillRect(renderer, &rectangle);
                }
                SDL_RenderCopy(renderer, img_bandido,NULL,bandido_GetRect(*bandido));
            }
        }
        rectangle.w = 40;
        rectangle.h = 40;

        nodo = siguiente(listaBandido, nodo);
    }

}

void robarRecursos(Lista &vagones , int cantOro, int cantPlata , int cantBronce,int inventario[]) // pasar el vector int* como parametro quizas?
{
    int auxOroB , auxPlataB , auxBronceB ;
    bool salir=false;
    auxOroB    = cantOro    ;
    auxPlataB    = cantPlata    ;
    auxBronceB   = cantBronce    ;

    PtrNodoLista minodo = primero(vagones);
    while(   (minodo != finLista()) && (auxOroB+auxPlataB+auxBronceB > 0 )   )
    {
        Vagon* vagon = (Vagon*) minodo->ptrDato;
        if (vagon->recurso == oro )
        {
            salir = false ;
            robarRecursos_desapilarCajas(vagon,auxOroB,salir,inventario);
            std::cout<<"\n Siguiente Vagon";
        }
        else if (vagon->recurso == plata )
        {
            salir = false ;
            robarRecursos_desapilarCajas(vagon,auxPlataB,salir,inventario);
            std::cout<<"\n Siguiente Vagon";
        }
        else if (vagon->recurso == bronce )
        {
            salir = false ;
            robarRecursos_desapilarCajas(vagon,auxBronceB,salir,inventario);
            std::cout<<"\n F Siguiente Vagon";
        }

        minodo = siguiente(vagones, minodo);
    }
}

void robarRecursos_desapilarCajas(Vagon* &vagon ,int &cantRecursoPedido ,bool &flag , int inventario[])
{
    PtrDato datoAux ;
    int auxCajaItem = 0 ;

    while (( cantRecursoPedido > 0 ) && (!flag))        // hacer funcion desapilarCajas(vagon,cantOro); es todo el while
    {
        std::cout<<"\n C ";

        if (!pilaVacia(vagon->cajas))
        {
            datoAux = sacar(vagon->cajas);
            auxCajaItem = caja_GetCantItem( *((Caja*)datoAux) );
            std::cout<<"\n D Recursos en Caja: "<<auxCajaItem<<" Recursos a robar: "<<cantRecursoPedido;
            if (  auxCajaItem > cantRecursoPedido  )// setear en algun lado la cantidad de item del vagon  y el inventarios osea RESTAR
            {
                caja_SetCantItem(  *((Caja*)datoAux) , auxCajaItem - cantRecursoPedido   );
                std::cout<<"\n E ";
                vagon_ApilarCaja(*vagon,(Caja*)datoAux );
                vagon_SetCantItem(*vagon,vagon->cantItem - cantRecursoPedido);
                inventario[vagon->recurso] -= cantRecursoPedido;
                cantRecursoPedido -= cantRecursoPedido;
                std::cout<<"\n cantRecursoPedido "<<cantRecursoPedido<<"\n";
            }
            else
            {
                cantRecursoPedido -= auxCajaItem ;
                vagon_SetCantItem(*vagon,vagon->cantItem - auxCajaItem);
                inventario[vagon->recurso] -= auxCajaItem;

            }
        }
        else flag = true ;
    }
}



