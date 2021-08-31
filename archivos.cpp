#include "archivos.h"

void archivo_leerHastaCaracter ( char &c ,stringstream &ss , string &linea , int &i)
{
    ss.clear();
    ss.str("");

    while (linea[i] != c )
    {
        ss <<linea[i] ;
        i++;
    }
    i++;
}
void archivo_leerHastaFinString(string &linea,stringstream &ss , int &i)
{   ss.clear();
    ss.str("");
    while (i<=linea.size())
    {
        ss <<linea[i] ;
        i++;
    }
}

void archivo_asignarEnum(e_recurso &mirecurso ,stringstream &ss)
{
    if((ss.str().compare("oro")) == 0)  mirecurso = oro ;
    if((ss.str().compare("plata")) == 0)  mirecurso = plata ;
    if((ss.str().compare("bronce")) == 0)  mirecurso = bronce ;
}

void archivo_asignarInt(int &entero, stringstream &ss)
{
    ss >> entero;
}

void archivo_asignarCadena(string &cadena, stringstream &ss)
{
    cadena = ss.str();
}

void archivo_leerComanda(e_recurso &mirecurso1 ,e_recurso &mirecurso2 ,e_recurso &mirecurso3 ,int &cant1,int &cant2,int &cant3)
{
    string linea ;
    int i ;
    char puntocoma = ';';
    stringstream ss ;
    ifstream archivo;

    archivo.open ("Comanda.txt");        // open file

    getline(archivo, linea);
    i=0 ;

    archivo_leerHastaCaracter (puntocoma ,ss , linea ,  i) ;
    archivo_asignarEnum(mirecurso1,ss);
    archivo_leerHastaFinString(linea,ss,i);
    archivo_asignarInt(cant1,ss);

    getline(archivo, linea);
    i=0 ;

    archivo_leerHastaCaracter (puntocoma ,ss , linea ,  i) ;
    archivo_asignarEnum(mirecurso2,ss);
    archivo_leerHastaFinString(linea,ss,i);
    archivo_asignarInt(cant2,ss);

    getline(archivo, linea);
    i=0 ;

    archivo_leerHastaCaracter (puntocoma ,ss , linea ,  i);
    archivo_asignarEnum(mirecurso3,ss);
    archivo_leerHastaFinString(linea,ss,i);
    archivo_asignarInt(cant3,ss);

    archivo.close();           // close file
}

void archivo_evaluarClave(string cadena , int entero , int &enteroS ,int &enteroP,int &enteroA, int &enteroPOSX , int &enteroPOSY, int &enteroIM, int &enteroVM, int &enteroIB, int &enteroVB, int &enteroIP)
{
    if     (    ((cadena).compare("S")) == 0   )  enteroS = entero ;
    else if(    ((cadena).compare("P")) == 0   )  enteroP = entero ;
    else if(    ((cadena).compare("A")) == 0   )  enteroA = entero ;
    else if(  ( ((cadena).compare("posXE")) == 0 ) || ( ((cadena).compare("POSXE")) == 0)  )  enteroPOSX = entero ;
    else if(  ( ((cadena).compare("posYE")) == 0 ) || ( ((cadena).compare("POSYE")) == 0)  )  enteroPOSY = entero ;
    else if(    ((cadena).compare("IM")) == 0   )  enteroIM = entero ;
    else if(    ((cadena).compare("VM")) == 0   )  enteroVM = entero ;
    else if(    ((cadena).compare("IB")) == 0   )  enteroIB = entero ;
    else if(    ((cadena).compare("VB")) == 0   )  enteroVB = entero ;
    else if(    ((cadena).compare("IP")) == 0   )  enteroIP = entero ;

}

void archivo_leerParametros( int &enteroS ,int &enteroP,int &enteroA, int &enteroPOSX , int &enteroPOSY, int &enteroIM, int &enteroVM, int &enteroIB, int &enteroVB, int &enteroIP)
{
    string linea ,cadena;
    int i ,entero,cantParametros=10;
    char igual = '=';
    stringstream ssP ;
    ifstream archivo;

    archivo.open ("Parametros.txt");        // open file

    for( cantParametros=0 ; cantParametros<10; cantParametros++)
    {
        getline(archivo, linea);
        i=0 ;

        archivo_leerHastaCaracter (igual ,ssP , linea ,  i) ;
        archivo_asignarCadena(cadena,ssP);
        archivo_leerHastaFinString(linea,ssP,i);
        archivo_asignarInt(entero,ssP);
        archivo_evaluarClave(cadena,entero,enteroS,enteroP,enteroA,enteroPOSX,enteroPOSY,enteroIM,enteroVM,enteroIB,enteroVB,enteroIP);

    }

    archivo.close();           // close file
}

void archivo_leerMinas(int &posX, int &posY ,int &codItem, int &IP, int &seq1, int &seq2, int &seq3, int &seq4, int &seq5)
{
    string linea ;
    int i ;
    char puntocoma = ';';
    stringstream ssM ;
    ifstream archivo;

    archivo.open ("Minas.txt");        // open file

    getline(archivo, linea);
    i=0 ;
    archivo_leerHastaCaracter (puntocoma ,ssM , linea ,  i) ;
    archivo_asignarInt(posX,ssM);
    archivo_leerHastaCaracter (puntocoma ,ssM , linea ,  i) ;
    archivo_asignarInt(posY,ssM);
    archivo_leerHastaCaracter (puntocoma ,ssM , linea ,  i) ;
    archivo_asignarInt(codItem,ssM);
    archivo_leerHastaCaracter (puntocoma ,ssM , linea ,  i) ;
    archivo_asignarInt(IP,ssM);
    archivo_leerHastaCaracter (puntocoma ,ssM , linea ,  i) ;
    archivo_asignarInt(seq1,ssM);
    archivo_leerHastaCaracter (puntocoma ,ssM , linea ,  i) ;
    archivo_asignarInt(seq2,ssM);
    archivo_leerHastaCaracter (puntocoma ,ssM , linea ,  i) ;
    archivo_asignarInt(seq3,ssM);
    archivo_leerHastaCaracter (puntocoma ,ssM , linea ,  i) ;
    archivo_asignarInt(seq4,ssM);

    archivo_leerHastaFinString(linea,ssM,i);
    archivo_asignarInt(seq5,ssM);

}
