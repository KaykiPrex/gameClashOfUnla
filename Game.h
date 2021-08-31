#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

//SDL---------------------------------------
#include "SDL_mixer.h"
#include <time.h>

//TDA de estructuras(listas, pilas , colas)-
#include "lista.h"

//TDA de entidades--------------------------
#include "Tren.h"
#include "Moneda.h"
#include "Bandido.h"
#include "Mina.h"

//------------------------------------------
#include "Textura.h"
#include "Mapa.h"

//ADMINISTRADORES---------------------------------------
#include "AdministrarEventos.h"
#include "AdministrarTiempos.h"
#include "AdministrarMonedas.h"
#include "AdministrarBandidos.h"
//ARCHIVOS----------------------------------------------
#include "archivos.h"
//LIBRERIAS-GENERALES---------------------------------------
#include <cstdlib>
#include "stdio.h"
#include <sstream>


//-------------------------------------------------------
            /*DEFINICIONES*/
//-------------------------------------------------------
//----------------Init-----------------------------------
#define WIDTH 800
#define HEIGHT 600



//------------------------------------------------------------------------------------------------//
bool inicializar();
//------------------------------------------------------------------------------------------------//
void inicioGame();
//------------------------------------------------------------------------------------------------//
void terminarGame();
//------------------------------------------------------------------------------------------------//
/**
    PRE: Las posiciones deben ser mayor o igual a cero.
    POST: Crea el mapa inicializando todos sus valores .
*/
void crearMapa(Mapa [][MPOSY]);
//------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------//
                                /*  MINA  */
// -----------------------------------------------------------------------------------------------//
/**
    PRE: La mina y la caja deben haber sido creadas.
    POST: Genera la secuencia completa de cajas agregando todas a la cola.
*/
void generarSecuenciaCajas(Caja *&ptrCaja, Mina *&ptrMina , e_recurso recurso ,int seq1,int seq2,int seq3,int seq4,int seq5);
//------------------------------------------------------------------------------------------------//
/**
    PRE: La mina y la caja deben haber sido creadas.
    POST: Controla si paso el intervalo de produccion y produce el nuevo recurso.
*/
void generarRecurso(Caja *&ptrCaja ,Mina *&ptrMina , int intervaloProduccion , Uint32 intervaloActual , Uint32 &tiempoIntervaloProduccion, int &posProd) ;
//------------------------------------------------------------------------------------------------//
/**
    PRE: El tren y la mina deben haber sido creadas.
    POST: Controla la colision entre el tren y la mina . Si hay colision agrega al vagon correspondiente una caja.
*/
void colisionTrenMina(Tren &tren ,Mina* &ptrMina ,Caja* &vectorCajas ,int &posProd ,int vectorInventario[5]);
//------------------------------------------------------------------------------------------------//
/**
    PRE: El vagon y la caja deben haber sido creadas.
    POST: Agrega al vagon una caja con el recurso correspondiente.
*/
void sumarCajaEnVagon(Vagon &vagon, Caja* caja ,int vectorInventario[5] ,bool &flag);
//------------------------------------------------------------------------------------------------//
                                /*  MONEDA  */
//------------------------------------------------------------------------------------------------//
int id_borrarMoneda(Uint32 &aparicion, Uint32 intervaloActual, Moneda *ptrMoneda);// No se usa , borrar
//------------------------------------------------------------------------------------------------//
                                /*  COMPARACIONES  */
//------------------------------------------------------------------------------------------------//
ResultadoComparacion compararListaMoneda(PtrDato ptrDato1, PtrDato ptrDato2); // en Header lista
ResultadoComparacion compararListaBandido(PtrDato ptrDato1, PtrDato ptrDato2);// en Header lista
//------------------------------------------------------------------------------------------------//
                                /*  TIEMPOS DEL JUEGO   */
//------------------------------------------------------------------------------------------------//
void intervaloAleatorio(int &duracion , int &aparicion , int maxDuracion , int maxIntervalo); // No se usa borrar
void posicionAleatoria(int &posA , int &posB); // No se usa , borrar
//------------------------------------------------------------------------------------------------//
                                /* FIN DE TIEMPOS */
//------------------------------------------------------------------------------------------------//
#endif // GAME_H_INCLUDED
