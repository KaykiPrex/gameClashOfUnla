#include "AdministrarEventos.h"


void eventos_MenuEspera(SDL_Event* evento, bool &salir ,Uint32 &intervalogame ,Uint32 &tiempoIntervalo , Uint32 &timePersonaje , Uint32 &frame, Uint32 startTime,Mix_Music *&bgm , Uint32 pausa)
{

    if(SDL_PollEvent(evento))
    {
        if(evento->type == SDL_QUIT)
        {
            //break;
        }
        else if(evento->type == SDL_KEYDOWN)
        {
            salir = true ;
            Mix_PlayMusic(bgm,0);
            Mix_HaltMusic();
            //Mix_FreeMusic(bgm);
            intervalogame = 0 ;
            tiempoIntervalo = intervaloSeg(3,startTime,pausa) ;
            frame = 1 ;
            timePersonaje =  intervaloSeg(1,startTime,pausa); // Aca se determina en cuantos segundos va a Aparecer por primera vez // intervaloSeg(aparicion,timegame())<-- Ej para la moneda o bandido
            // tiempoFPS = intervaloSeg((1.0/FPS),timegame()) ;//REEEE
            //break;                                  //
        }
    }
}

void eventos_EntradaTrenSentido(SDL_Event* evento , Tren &ptrTren)
{
    if(evento->type == SDL_KEYDOWN)
    {
        switch(evento->key.keysym.sym)
        {
        case SDLK_RIGHT:
            tren_SetSentido(ptrTren,der) ;
            break;
        case SDLK_LEFT:
            tren_SetSentido(ptrTren,izq) ;
            break;
        case SDLK_UP:
            tren_SetSentido(ptrTren,arriba) ;
            break;
        case SDLK_DOWN:
            tren_SetSentido(ptrTren,abajo) ;
            break;
        }
    }

}

void eventos_Pausa(SDL_Event* evento,Uint32 &pausedTicks ,SDL_Renderer *renderer ,SDL_Texture *&img,SDL_Texture *&img_bandido,Bandido &bandido,SDL_Texture *&img_stop,SDL_Texture *&img_tributoBg ,SDL_Texture *&img_tributoDer ,SDL_Texture *&img_tributoIzq ,SDL_Texture *&img_tributoBandido ,Mix_Music *&bgmTributo)
{
    bool salir = false , flag = true;
    Uint32 ticks,tickstimeout;
    SDL_Rect rect_Stop , rect_Der ,rect_Izq;

    rect_Stop.h = 80 ;
    rect_Stop.w = 80 ;
    rect_Stop.x = bandido_GetRect(bandido)->x ;
    rect_Stop.y = bandido_GetRect(bandido)->y -60 ;

    rect_Der.h = 600 ;
    rect_Der.w = 800 ;
    rect_Der.x = 900 ;
    rect_Der.y = 0 ;
    rect_Izq.h = 600 ;
    rect_Izq.w = 800 ;
    rect_Izq.x = -600 ;
    rect_Izq.y = 0 ;
    ticks = SDL_GetTicks();
    tickstimeout = intervaloSeg(2,ticks,pausedTicks);

    SDL_RenderCopy(renderer,img,NULL,NULL);
    SDL_RenderCopy(renderer,img_stop,NULL,&rect_Stop);
    SDL_RenderCopy(renderer, img_bandido,NULL,bandido_GetRect(bandido));
    //SDL_RenderClear(mirenderer);
    while(!salir)
    {


        if( intervalo_PASSED(timegame(ticks,pausedTicks),tickstimeout)  )
        {
            if (Mix_PlayingMusic()==0)  Mix_PlayMusic(bgmTributo,-1)  ;
            if(SDL_PollEvent(evento))
                {
                    if(evento->type == SDL_KEYDOWN)
                    {
                     if(  (evento->key.keysym.sym == SDLK_KP_ENTER ) || (evento->key.keysym.sym == SDLK_BACKSPACE)  )  salir = true;
                    }
                }
            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer,img_tributoBg,NULL,NULL);
            if(rect_Der.x >= 3 )    rect_Der.x -= 3 ;
            else
            {

            }
            if(rect_Izq.x <= -3 )    rect_Izq.x += 3 ;
            SDL_RenderCopy(renderer,img_tributoDer,NULL,&rect_Der);
            SDL_RenderCopy(renderer,img_tributoIzq,NULL,&rect_Izq);
            SDL_RenderCopy(renderer,img_tributoBandido,NULL,NULL);
        }


        SDL_RenderPresent(renderer);
        SDL_Delay(10);
    }

    pausedTicks = SDL_GetTicks() - ticks;
    std::cout<<"\n -Salir Loop PAUSE-\n";
}

void evento_keyPress(SDL_Event* evento ,bool &flag){
    if(SDL_PollEvent(evento))
                {
                    if(evento->type == SDL_KEYDOWN)
                    {
                        flag = true;
                    }
                }
}
