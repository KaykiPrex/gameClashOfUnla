#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include "Caja.h"

// importar el TDA donde esta el enum y cambiar el nombre de recurso creo que era e_recurso
/*typedef enum
{
    oro = 0 ,
    plata,
    bronce,

} recurso ;
*/
using namespace std;

/**
PRE: El valor del StringStream debe estar inicializado.
POST: Concatena los caracteres de la lina en el StringStream hasta encontrar un caracter
especifico.
*/
void archivo_leerHastaCaracter (char &c ,stringstream &ss , string &linea ,  int &i);
/**
PRE: El valor del StringStream debe estar inicializado.
POST: Concatena los caracteres de la linea en el StringStream hasta fin de linea.
*/
void archivo_leerHastaFinString(string &linea,stringstream &ss , int &i);
/**
PRE: El valor del StringStream debe estar inicializado.
POST: Asigna el valor de StringStream al recurso correspondiente.
*/
void archivo_asignarEnum(e_recurso &mirecurso ,stringstream &ss); // en estos cambiarlos
/**
PRE: El valor del StringStream debe estar inicializado.
POST: Asigna el valor de StringStream a un int.
*/
void archivo_asignarInt(int &entero, stringstream &ss);
/**
PRE: El valor del StringStream debe estar inicializado.
POST: Asigna el valor de StringStream a una cadena.
*/
void archivo_asignarCadena(string &cadena, stringstream &ss);
/**
PRE: La cadena no debe estar vacia.
POST: Evalua la cadena y asigna a la variable correspondiente.
*/
void archivo_evaluarClave(string cadena , int entero , int &enteroS ,int &enteroP,int &enteroA, int &enteroPOSX , int &enteroPOSY, int &enteroIM, int &enteroVM, int &enteroIB, int &enteroVB, int &enteroIP);
/**
PRE: El archivo debe estar creado sin ningun error.
POST: Lee el archivo de la comanda y lo asigna a variables.
*/
void archivo_leerComanda(e_recurso &mirecurso1 ,e_recurso &mirecurso2 ,e_recurso &mirecurso3 ,int &cant1,int &cant2,int &cant3);
/**
PRE: El archivo debe estar creado sin ningun error.
POST: Lee el archivo de la parametros y lo asigna a variables.
*/
void archivo_leerParametros( int &enteroS ,int &enteroP,int &enteroA, int &enteroPOSX , int &enteroPOSY, int &enteroIM, int &enteroVM, int &enteroIB, int &enteroVB, int &enteroIP);
/**
PRE: El archivo debe estar creado sin ningun error.
POST: Lee el archivo de la minas y lo asigna a variables.
*/
void archivo_leerMinas(int &posX, int &posY ,int &codItem, int &IP, int &seq1, int &seq2, int &seq3, int &seq4, int &seq5);


#endif // ARCHIVOS_H_INCLUDED
