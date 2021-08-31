/* TDA Lista
 * Implementación Simplemente Enlazada
 * Archivo : Lista.cpp
 * Versión : 1.1
 */


#include "Lista.h"


/******************************************************************************/
/* Definición de Tipos de Datos para manejo interno */
/*--------------------------------------------------*/


/******************************************************************************/
/* Funciones Adicionales */
/*-----------------------*/

/*
  pre : ninguna.
  post: compara ambos dato1 y dato2, devuelve
          mayor si dato1 es mayor que dato2,
          igual si dato1 es igual a dato2,
          menor si dato1 es menor que dato2.

  dato1 : dato a comparar.
  dato2 : dato a comparar.
  return resultado de comparar dato1 respecto de dato2.
*/
   //Cambiado del original
ResultadoComparacion compararDato(ptrDato dato1, ptrDato dato2) {    
    if ( *((int*)dato1) > *((int*)dato2) ) {                                                      
        return MAYOR;
    }
    else if (*((int*)dato1) < *((int*)dato2)) {
        return MENOR;
    }
    else {
        return IGUAL;
    }
}


/******************************************************************************/
/* Implementación de Primitivas */
/*------------------------------*/


                                                                                //Cambiado del original

void crearLista(Lista &lista, PFComparacion compara) {
  lista.primero = fin();
  lista.compara = compara;
}


/*----------------------------------------------------------------------------*/
bool listaVacia(Lista &lista) {

  return (primero(lista) == fin());
}

/*----------------------------------------------------------------------------*/
PtrNodoLista fin() {
  return NULL;
}

/*----------------------------------------------------------------------------*/
PtrNodoLista primero(Lista &lista) {
  return lista.primero;
}

/*----------------------------------------------------------------------------*/
PtrNodoLista siguiente(Lista &lista, PtrNodoLista ptrNodo) {

  /* verifica si la lista está vacia o si ptrNodo es el último */
  if ((! listaVacia(lista)) && (ptrNodo != fin()))
    return ptrNodo->sgte;
  else
    return fin();
}

/*----------------------------------------------------------------------------*/
PtrNodoLista anterior(Lista &lista, PtrNodoLista ptrNodo) {

  PtrNodoLista ptrPrevio = fin();
  PtrNodoLista ptrCursor = primero(lista);

  while (( ptrCursor != fin()) && (ptrCursor != ptrNodo)) {
    ptrPrevio = ptrCursor;
    ptrCursor = siguiente(lista,ptrCursor);
  }
  return ptrPrevio;
}

/*----------------------------------------------------------------------------*/
PtrNodoLista ultimo(Lista &lista) {

  /* el último nodo de la lista es el anterior al fin() */
  return anterior(lista,fin());
}

/*----------------------------------------------------------------------------*/
PtrNodoLista crearNodoLista(ptrDato ptrdato) {                                  //Cambiado del original

  /* reserva memoria para el nodo y luego completa sus datos */
  PtrNodoLista ptrAux = new NodoLista;

  ptrAux->ptrdato = ptrdato;
  ptrAux->sgte = fin();

  return ptrAux;
}

/*----------------------------------------------------------------------------*/
PtrNodoLista adicionarPrincipio(Lista &lista, ptrDato dato) {                   //Cambiado del original

  /* crea el nodo */
  PtrNodoLista ptrNuevoNodo = crearNodoLista(dato);

  /* lo incorpora al principio de la lista */
  ptrNuevoNodo->sgte = lista.primero;
  lista.primero = ptrNuevoNodo;

  return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
PtrNodoLista adicionarDespues(Lista &lista, ptrDato dato, PtrNodoLista ptrNodo) { //Cambiado del original          

  PtrNodoLista ptrNuevoNodo = fin();

  /* si la lista está vacia se adiciona la principio */
  if (listaVacia(lista))
    ptrNuevoNodo = adicionarPrincipio(lista,dato);

  else {
    if (ptrNodo != fin()) {

      /* crea el nodo y lo intercala en la lista */
      ptrNuevoNodo = crearNodoLista(dato);

      ptrNuevoNodo->sgte = ptrNodo->sgte;
      ptrNodo->sgte = ptrNuevoNodo;
    }
  }
  return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
PtrNodoLista adicionarFinal(Lista &lista, ptrDato dato) {                       //Cambiado del original

  /* adiciona el dato después del último nodo de la lista */
  return adicionarDespues(lista,dato,ultimo(lista));
}

/*----------------------------------------------------------------------------*/
PtrNodoLista adicionarAntes(Lista &lista, ptrDato dato, PtrNodoLista ptrNodo) { //Cambiado del original

  PtrNodoLista ptrNuevoNodo = fin();

  if (! listaVacia(lista)) {
    if (ptrNodo != primero(lista))
      ptrNuevoNodo = adicionarDespues(lista,dato,anterior(lista,ptrNodo));
    else
      ptrNuevoNodo = adicionarPrincipio(lista,dato);
   }
   return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
void colocarDato(Lista &lista, ptrDato &dato, PtrNodoLista ptrNodo) {

  if ( (! listaVacia(lista)) && (ptrNodo != fin()))
    ptrNodo->ptrdato = dato;
}

/*----------------------------------------------------------------------------*/
void obtenerDato(Lista &lista, ptrDato &dato, PtrNodoLista ptrNodo) {

  if ((! listaVacia(lista)) && (ptrNodo != fin()))
    dato = ptrNodo->ptrdato;
}

/*----------------------------------------------------------------------------*/
void eliminarNodo(Lista &lista, PtrNodoLista ptrNodo) {

  PtrNodoLista ptrPrevio;

  /* verifica que la lista no esté vacia y que nodo no sea fin*/
  if ((! listaVacia(lista)) && (ptrNodo != fin())) {

    if (ptrNodo == primero(lista))
      lista.primero = siguiente(lista,primero(lista));

    else {
      ptrPrevio = anterior( lista , ptrNodo );
      ptrPrevio->sgte = ptrNodo->sgte;
    }
    // Si el dato es un TDA, acá habría que llamar al destructor.

    delete ptrNodo;
  }
}

/*----------------------------------------------------------------------------*/
void eliminarNodoPrimero(Lista &lista) {

  if (! listaVacia(lista))
    eliminarNodo(lista,primero(lista));
}

/*----------------------------------------------------------------------------*/
void eliminarNodoUltimo(Lista &lista) {

  if (! listaVacia(lista))
    eliminarNodo(lista,ultimo(lista));
}

/*----------------------------------------------------------------------------*/
void eliminarLista(Lista &lista) {

  /* retira uno a uno los nodos de la lista */
  while (! listaVacia(lista))
    eliminarNodo(lista,primero(lista));
}

/*----------------------------------------------------------------------------*/
//CAMBIADO DEL ORIGINAL
/*
DESDE MAIN, CREAR EQUIPO
equipo* equipo=new Equipo;
crear (equipo);
set_id/(equipo,1);
localizar (equipo, id)
destruir (equipo)

*/
PtrNodoLista localizarDato(Lista &lista, ptrDato ptrdato) {

   bool encontrado = false;
   ptrDato datoCursor;
   PtrNodoLista ptrCursor = primero(lista);

  /* recorre los nodos hasta llegar al último o hasta
     encontrar el nodo buscado */
  while ((ptrCursor != fin()) && (! encontrado)) {

    /* obtiene el dato del nodo y lo compara */
    ResultadoComparacion res = lista.compara(ptrdato, ptrCursor->ptrdato);
    if (res == IGUAL)
      encontrado = true;
    else
      ptrCursor = siguiente(lista,ptrCursor);
  }

  /* si no lo encontró devuelve fin */
  if (! encontrado)
    ptrCursor = fin();

  return ptrCursor;
}

/*----------------------------------------------------------------------------*/
void eliminarDato(Lista &lista, ptrDato dato) {                                 //Cambiado del original

  /* localiza el dato y luego lo elimina */
  PtrNodoLista ptrNodo = localizarDato(lista,dato);
  if (ptrNodo != fin())
    eliminarNodo(lista,ptrNodo);
}

/*----------------------------------------------------------------------------*/
PtrNodoLista insertarDato(Lista &lista, ptrDato dato) {                         //Cambiado del original

  PtrNodoLista ptrPrevio = primero(lista);
  PtrNodoLista ptrCursor = primero(lista);
  PtrNodoLista ptrNuevoNodo;
  ptrDato datoCursor;
  bool ubicado = false;

  /* recorre la lista buscando el lugar de la inserción */
  while ((ptrCursor != fin()) && (! ubicado)) {

    obtenerDato(lista,datoCursor,ptrCursor);
    if (compararDato(datoCursor,dato) == MAYOR)
      ubicado = true;

    else {
      ptrPrevio = ptrCursor;
      ptrCursor = siguiente(lista,ptrCursor);
    }
  }

  if (ptrCursor == primero(lista))
    ptrNuevoNodo = adicionarPrincipio(lista,dato);
  else
    ptrNuevoNodo = adicionarDespues(lista,dato,ptrPrevio);

  return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/

void reordenar(Lista &lista) {                                                  //Cambiado del original

  Lista temp = lista;
  PtrNodoLista ptrCursor = primero(temp);
  crearLista(lista,&compararDato);
  while ( ptrCursor != fin() ) {
        ptrDato dato;
        obtenerDato( temp, dato, ptrCursor);
        insertarDato( lista, dato );
        eliminarNodo( temp, ptrCursor );
        ptrCursor = primero(temp);
  }
  eliminarLista( temp );
}

/*----------------------------------------------------------------------------*/

int longitud(Lista &lista){
  PtrNodoLista ptrCursor = primero(lista);
  int longitud = 0;
  while ( ptrCursor != fin() ) {
        longitud++;
        ptrCursor = siguiente( lista, ptrCursor);
  }
  return longitud;
}

/*----------------------------------------------------------------------------*/
