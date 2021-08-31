#include "AdministrarMonedas.h"

//----------------NUEVO AGREGAR MONEDAS ----------------------------------------------------------------------------------------
void agregarMonedas(Lista &listaMoneda,int &idMoneda, int intervaloMax , int duracionMax , Uint32 intervaloActual , Uint32 &tiempo_intervalo ,Mapa mapa[][MPOSY]){//FALTA VERIFICAR QUE LA POSICION RANDOM NO ESTE OCUPADA
int mirandomA, mirandomB;
    if(intervalo_PASSED(intervaloActual,tiempo_intervalo)){
            Moneda *ptrmoneda = new Moneda;
            moneda_Crear(*ptrmoneda);
            moneda_SetId(*ptrmoneda,idMoneda);
            idMoneda+= 1 ;
            moneda_SetDuracion(*ptrmoneda, intervalo_ADDTIME(rand()%duracionMax,intervaloActual));
            /*posicionAleatoria(*ptrmoneda); o por PosA y PosB ?*/
            mirandomA = rand()%(MPOSX-1);
            mirandomB = rand()%(MPOSY-1);
            moneda_SetPosx(*ptrmoneda,mirandomA);//texrBandido.y = mapa[i][j].blit_posx;
            moneda_SetPosy(*ptrmoneda,mirandomB);
            moneda_SetRect(*ptrmoneda,40 ,50,mapa[mirandomA][mirandomB].blit_posy,mapa[mirandomA][mirandomB].blit_posx) ;

            //*******
            adicionarFinal(listaMoneda, ptrmoneda);
            //reordenar(listaMoneda);

            tiempo_intervalo = intervalo_ADDTIME((1+rand()%intervaloMax),intervaloActual);
            //delete ptrmoneda;
    }
}
//FIX------------------------FIX-----------------------------------FIX---------------------------------------------------------------------------------------------------//
void mostrarMonedas(Lista listaMoneda, Uint32 intervaloActual , Tren* ptrTren ,Mapa mapa[][MPOSY] ,SDL_Texture *&img_coin ,SDL_Renderer *renderer ) {
                                                                                                            // en Lista cambia fin() y nodo->ptrdato
    PtrNodoLista nodoAux = NULL ;
    PtrNodoLista nodo = primero(listaMoneda);
    while(nodo != finLista()){
            Moneda* moneda = (Moneda*) nodo->ptrDato;
            //std::cout<<"| LISTA |";
            if( (intervalo_PASSED(intervaloActual,moneda_GetDuracion(*moneda))) || (mapa[moneda_GetPosx(*moneda)][moneda_GetPosy(*moneda)].ocupado) ){
                    if (moneda_GetActivo(*moneda)){
                        moneda_SetActivo(*moneda,false);
                      /**/
                        if (mapa[moneda_GetPosx(*moneda)][moneda_GetPosy(*moneda)].ocupado){  //AL 7 SE MUERE !!! POR QUE , NOSE !!!!!!!
                            tren_SetCantCoin(*ptrTren,tren_GetCantCoin(*ptrTren)+1);
                            moneda_SetActivo(*moneda,false);}
                      /**/
                    }
                   /* nodoAux = nodo ;
                    nodo = anterior(listaMoneda,nodo);
                    nodo->sgte = nodoAux->sgte;
                    eliminarNodo(listaMoneda,nodoAux);*/
                  //  nodoAux = nodo ;
                    //eliminarNodo(listaMoneda,nodo); nodo = siguiente(listaMoneda,nodoAux);
                    //eliminarDato(listaMoneda,&moneda);  // OJO DA ERROR SIN & ,con " & " no lo borra pero sin error (solo para que funcione) //eliminarNodo pasa lo mismo
                    //moneda_Destruir(*moneda);
            }
            else{
                if (moneda_GetActivo(*moneda))
                    SDL_RenderCopy(renderer, img_coin,NULL,moneda_GetRect(*moneda));
            }
            nodo = siguiente(listaMoneda, nodo);
        }
   // std::cout<<"|LISTA |: "<<longitud(listaMoneda)<<"\n";
}
//FIX------------------------FIX-----------------------------------FIX---------------------------------------------------------------------------------------------------//
