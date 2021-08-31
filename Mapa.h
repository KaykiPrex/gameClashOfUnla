#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED

#define DIM_MAPA_X 6
#define DIM_MAPA_Y 10
#define MPOSX 12    // LARGO
#define MPOSY 15    // ANCHO


typedef struct {
            bool ocupado ;
            int blit_posx; //blit_alto
            int blit_posy; //blit_ancho
        } Mapa;


#endif // MAPA_H_INCLUDED
