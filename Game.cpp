#include "Game.h"



//-------------------------------------------------------------------
//SDL ventana
SDL_Window *win = NULL;
SDL_Renderer *renderer = NULL;

//SDL texturas
SDL_Texture *img_menu = NULL;
SDL_Texture *img_gamewin = NULL;
SDL_Texture *img_mapa = NULL;
SDL_Texture *img_start = NULL;
SDL_Texture *img_bgBlack = NULL;
SDL_Texture *img_stop = NULL;
SDL_Texture *img_tributoBg = NULL;
SDL_Texture *img_tributoBandido = NULL;
SDL_Texture *img_tributoDer = NULL;
SDL_Texture *img_tributoIzq = NULL;
SDL_Texture *img_gato1 = NULL;
SDL_Texture *img_gato2 = NULL;
SDL_Texture *img_bandido = NULL;
SDL_Texture *img_llama = NULL;
SDL_Texture *img_llama1 = NULL;
SDL_Texture *img_llama2 = NULL;
SDL_Texture *img_llama3 = NULL;
SDL_Texture *img_llama4 = NULL;
SDL_Texture *img_llama5 = NULL;
SDL_Texture *img_llama6 = NULL;
SDL_Texture *img_llama7 = NULL;
SDL_Texture *img_coin = NULL;
SDL_Texture *img_estacion = NULL;
SDL_Texture *img_minaLlena = NULL;
SDL_Texture *img_minaVacia = NULL;
SDL_Texture *img_vagon = NULL;
SDL_Texture *img_mapaCuadricula = NULL;
SDL_Texture *img_trenLeft1 = NULL;
SDL_Texture *img_trenLeft2 = NULL;
SDL_Texture *img_trenUp1 = NULL;
SDL_Texture *img_trenUp2 = NULL;
SDL_Texture *img_trenDown1 = NULL;
SDL_Texture *img_trenDown2 = NULL;

SDL_Rect texrLlama;
SDL_Rect texrBandido;
SDL_Rect texrGato;
SDL_Rect texrCoin;
SDL_Rect texrText;
SDL_Rect texrEstacion;
SDL_Rect texrMina_1;
SDL_Rect texrMina_2;
SDL_Rect texrMina_3;
SDL_Rect texrVagon;
SDL_Rect texrMapaCuadricula;

int wgato,hgato , wcoin,hcoin,wbandido,hbandido,wllama,hllama;

//Tiempo Inicial-------------------
Uint32 startTime;
//-------------------------


void inicioGame()
{

    Mapa mapa[MPOSX][MPOSY];
    //--------Salida main loop----------------------
    bool gameover = false;
    bool victory = false ;
    bool runGame = true;
    bool quit=false ;
    //----------------------------------------------
    int numRecurso=6;
    int inventario[numRecurso]; // donde el codigo de item es de 1 a 6 , porque Oro = 1 en enumerados
    int comanda[numRecurso];
    //inicializar todos

    for (int i=0; i<6; i++)
    {
        inventario[i]=0;
        comanda[i]=0;
    }

    comanda[1]= 1; //oro
    comanda[2]= 0; //plata
    comanda[3]= 0; //bronce
    comanda[4]= 0;
    comanda[5]= 0;

    //-----------------Archivo Comanda------------------------------
    e_recurso mirecurso1,mirecurso2,mirecurso3;
    int cant1,cant2,cant3;

    archivo_leerComanda(mirecurso1, mirecurso2, mirecurso3,cant1, cant2, cant3);

    comanda[mirecurso1] = cant1 ;
    comanda[mirecurso2] = cant2 ;
    comanda[mirecurso3] = cant3 ;

//--------------TEST---------------------
    int posCoinX = 5 , posCoinY = 5 ;
    bool monedaActiva = true;

    //creacion MONEDA
    int idmoneda=0;
    Lista listaMoneda ;
    crearLista(listaMoneda,compararListaMoneda);
    //creacion BANDIDO
    int idbandido=0;
    Lista listaBandido ;
    crearLista(listaBandido,compararListaBandido);
    //creacion CAJA

    Caja *vectorCajas;
    vectorCajas = new Caja[5];
    //caja_SetCantItem(vectorCajas[0],5);
    //caja_SetCantItem(vectorCajas[1],2);
    Caja *vectorCajasMina2;
    vectorCajasMina2 = new Caja[5];
    Caja *vectorCajasMina3;
    vectorCajasMina3 = new Caja[5];

    //creacion Mina
    Mina *ptrMina = new Mina;
    mina_Crear(*ptrMina);
    mina_SetPosx(*ptrMina,2);
    mina_SetPosy(*ptrMina,2);
    mina_SetId(*ptrMina,1);

    Mina *ptrMina2 = new Mina;
    mina_Crear(*ptrMina2);
    mina_SetPosx(*ptrMina2,4);
    mina_SetPosy(*ptrMina2,7);
    mina_SetId(*ptrMina2,2);

    Mina *ptrMina3 = new Mina;
    mina_Crear(*ptrMina3);
    mina_SetPosx(*ptrMina3,9);
    mina_SetPosy(*ptrMina3,9);
    mina_SetId(*ptrMina3,3);
//---------------fin test----------------------------
//---------Tiempos------------------------------
    Uint32 pausedTicks = 0 ;
    Uint32 frame = 1 ;
    Uint32 tiempoFPS = 0 ;
    Uint32 timeCat=1000; // tiempo del movimiento automatico del gato en ms

    Uint32 intervalogame = 0 ; // INTERVALOS TOTALES : empieza en 0 al comienzo del juego
    Uint32 duracionIntervalo = 3 ;    // !!!PARAMETRO INTERVALO!!! cuantos segundos dura entre cada intervalo // Clave:S
    Uint32 tiempoIntervalo = intervaloSeg(duracionIntervalo,startTime,pausedTicks) ; // <---aca va "duracionIntervalo" en vez de (3)

    //---monedas--------------
    Uint32 intervaloRandom ;
    Uint32 Max_intervalo = 2 ;        // !!!PARAMETRO INTERVALO MAX!!! // Clave:IM
    Uint32 Max_duracion = 6 ;         // !!!PARAMETRO DURACION  MAX!!! // Clave:VM
    //---bandidos--------------
    Uint32 intervaloRandom_bandido ;
    Uint32 Max_intervalo_bandido = 4 ;  // Clave:IB
    Uint32 Max_duracion_bandido = 3 ;   // Clave:VB
    int MaxRecursos = 10 ; // Clave:P
    //---mina--------------
    Uint32 intervaloProduccion = 2 ;    // Clave:IP
    Uint32 tiempoIP = 0 ;
    int posProd = 0 ;

    Uint32 intervaloProduccionMina2 = 4 ;//(igualar si son iguales) Clave:IP
    Uint32 tiempoIPMina2 = 0 ;
    int posProdMina2 = 0 ;

    Uint32 intervaloProduccionMina3 = 5 ;//(igualar si son iguales) Clave:IP
    Uint32 tiempoIPMina3 = 0 ;
    int posProdMina3 = 0 ;
    //----gameover---------
    SDL_Texture *img_gameover[4];
    img_gameover[0] = IMG_LoadTexture(renderer, IMG_GAMEOVER_F0_PATH);
    img_gameover[1] = IMG_LoadTexture(renderer, IMG_GAMEOVER_F1_PATH);
    img_gameover[2] = IMG_LoadTexture(renderer, IMG_GAMEOVER_F2_PATH);
    img_gameover[3] = IMG_LoadTexture(renderer, IMG_GAMEOVER_F3_PATH);
    //----vagon---------
    SDL_Texture *img_vagones[29];
    img_vagones[0] = IMG_LoadTexture(renderer, IMG_VAGON00_PATH);
    img_vagones[1] = IMG_LoadTexture(renderer, IMG_VAGON01_PATH);
    img_vagones[2] = IMG_LoadTexture(renderer, IMG_VAGON02_PATH);
    img_vagones[3] = IMG_LoadTexture(renderer, IMG_VAGON03_PATH);
    img_vagones[4] = IMG_LoadTexture(renderer, IMG_VAGON04_PATH);
    img_vagones[5] = IMG_LoadTexture(renderer, IMG_VAGON05_PATH);
    img_vagones[6] = IMG_LoadTexture(renderer, IMG_VAGON06_PATH);
    img_vagones[7] = IMG_LoadTexture(renderer, IMG_VAGON028_PATH);
    img_vagones[8] = IMG_LoadTexture(renderer, IMG_VAGON07_PATH);
    img_vagones[9] = IMG_LoadTexture(renderer, IMG_VAGON08_PATH);
    img_vagones[10] = IMG_LoadTexture(renderer, IMG_VAGON09_PATH);
    img_vagones[11] = IMG_LoadTexture(renderer, IMG_VAGON010_PATH);
    img_vagones[12] = IMG_LoadTexture(renderer, IMG_VAGON011_PATH);
    img_vagones[13] = IMG_LoadTexture(renderer, IMG_VAGON012_PATH);
    img_vagones[14] = IMG_LoadTexture(renderer, IMG_VAGON013_PATH);
    img_vagones[15] = IMG_LoadTexture(renderer, IMG_VAGON014_PATH);
    img_vagones[16] = IMG_LoadTexture(renderer, IMG_VAGON015_PATH);
    img_vagones[17] = IMG_LoadTexture(renderer, IMG_VAGON016_PATH);
    img_vagones[18] = IMG_LoadTexture(renderer, IMG_VAGON017_PATH);
    img_vagones[19] = IMG_LoadTexture(renderer, IMG_VAGON018_PATH);
    img_vagones[20] = IMG_LoadTexture(renderer, IMG_VAGON019_PATH);
    img_vagones[21] = IMG_LoadTexture(renderer, IMG_VAGON020_PATH);
    img_vagones[22] = IMG_LoadTexture(renderer, IMG_VAGON021_PATH);
    img_vagones[23] = IMG_LoadTexture(renderer, IMG_VAGON022_PATH);
    img_vagones[24] = IMG_LoadTexture(renderer, IMG_VAGON023_PATH);
    img_vagones[25] = IMG_LoadTexture(renderer, IMG_VAGON024_PATH);
    img_vagones[26] = IMG_LoadTexture(renderer, IMG_VAGON025_PATH);
    img_vagones[27] = IMG_LoadTexture(renderer, IMG_VAGON026_PATH);
    img_vagones[28] = IMG_LoadTexture(renderer, IMG_VAGON027_PATH);


    //-----interfaz--------
    SDL_Texture *img_interfazScore;
    img_interfazScore = IMG_LoadTexture(renderer, IMG_INTERFAZSCORE_PATH);
    // CREACION //------------------------------------------------------------
    //---------parametros------
    int estacion_PosXE = 11;// Clave:PosXE
    int estacion_PosYE = 7;// Clave:PosYE

    //---------mapa------------
    crearMapa(mapa);
    //tren---------------------
    Tren* ptrTren = new Tren ;
    tren_Crear(*ptrTren);
    tren_SetPosx(*ptrTren,0);
    tren_SetPosy(*ptrTren,0);
    tren_SetCantCoin(*ptrTren,0);
    //estacion-----------------
    texrEstacion.x = mapa[estacion_PosXE][estacion_PosYE].blit_posy -10;
    texrEstacion.y = mapa[estacion_PosXE][estacion_PosYE].blit_posx +10;
    //mina-----------------
    texrMina_1.x = mapa[2][2].blit_posy;
    texrMina_1.y = mapa[2][2].blit_posx;
    texrMina_2.x = mapa[4][7].blit_posy;
    texrMina_2.y = mapa[4][7].blit_posx;
    texrMina_3.x = mapa[9][9].blit_posy;
    texrMina_3.y = mapa[9][9].blit_posx;
    texrMina_2.h = texrMina_1.h ;
    texrMina_2.w = texrMina_1.w ;
    texrMina_3.h = texrMina_1.h ;
    texrMina_3.w = texrMina_1.w ;
    //---------texto-----------
    std::stringstream ssScore ;
    ssScore <<"x" <<0 ;
    SDL_Color color= {0,0,0};
    TTF_Font *times= TTF_OpenFont("Times.ttf",20);
    SDL_Surface *text_surface = TTF_RenderText_Solid(times,ssScore.str().c_str(),color);
    SDL_Texture *message = SDL_CreateTextureFromSurface(renderer,text_surface);
    ssScore <<"x" << tren_GetCantCoin(*ptrTren) ;

    //-------------------------

    srand(time(NULL));
    //-----------vagon---------0
    texrVagon.y =  mapa[0][0].blit_posx; // INICIO vagon , tiene que ser igual que el tren
    texrVagon.x =  mapa[0][0].blit_posy;

    tren_AgregarVagon(*ptrTren,1);

    /** TEST

        PtrNodoLista minodo = primero(ptrTren->vagones);
        while(minodo != finLista()){

            /// Obtengo el dato por la primitiva

            Vagon* vagon = (Vagon*) minodo->ptrDato;
            std::cout<<"\n LISTA  Vagon : "<<vagon->id<<std::endl;

            minodo = siguiente(ptrTren->vagones, minodo);
        }
     */
//-------------fin-----------------------------------------------------------


    //---------------------test-------------------------------------
    mapa[posCoinX][posCoinY].ocupado=true;
  //  srand(time(NULL));
    //--------------------fintest-----------------------------------


    intervaloRandom = rand()%Max_intervalo ;
    intervaloRandom_bandido = rand()%Max_intervalo_bandido ;

    tiempoIP+= intervaloProduccion ;
    tiempoIPMina2+= intervaloProduccionMina2;
    tiempoIPMina3+= intervaloProduccion ;

    tiempoFPS = intervaloSeg((1.0/FPS),startTime,pausedTicks) ;//borrar

    generarSecuenciaCajas(vectorCajas,ptrMina,oro,2,1,4,3,5);// Crea la cola entera , la secuencia entera de cajas , va en INIT
    generarSecuenciaCajas(vectorCajasMina2,ptrMina2,plata,1,2,3,4,5);
    generarSecuenciaCajas(vectorCajasMina3,ptrMina3,bronce,5,4,3,2,1);
    // system("Cls");
    std::cout<<("\n==================CATS OF UNLA==================")<<std::endl;

    // Sounds
    Mix_Music *bgmMenu = Mix_LoadMUS("./sound/mainmenu.mp3");
    Mix_Music *bgmGame = Mix_LoadMUS("./sound/game.mp3");
    Mix_Music *bgmTributo = Mix_LoadMUS("./sound/tributo.mp3");
    Mix_Music *bgmGameOver = Mix_LoadMUS("./sound/gameover.mp3");
    Mix_Music *bgmGameWin  = Mix_LoadMUS("./sound/gamewin.mp3");
    Mix_VolumeMusic(MIX_MAX_VOLUME/2);

    //LOOP principal del juego
    while (runGame)
    {
        SDL_Event e ;

        while(!quit)   //-------------------- ///////  MENU DEL JUEGO ,espera hasta que este presionada una tecla
        {

            fpsgame(frame,tiempoFPS,FPS,startTime,pausedTicks);//borrar
            SDL_RenderCopy(renderer, img_menu, NULL, NULL);
            //Music
            if (Mix_PlayingMusic()==0)
                Mix_PlayMusic(bgmMenu,-1)  ;

            if((frame>=8) && (frame<=22))
                SDL_RenderCopy(renderer, img_start, NULL, NULL);

            texrLlama.x = 160 ;
            texrLlama.y = 245;
            texrLlama.h = 40;
            texrLlama.w = 30;
            dibujarTexturaxRangoFrame(1,4,  frame,&texrLlama,renderer,img_llama);
            dibujarTexturaxRangoFrame(5,8,  frame,&texrLlama,renderer,img_llama1);
            dibujarTexturaxRangoFrame(9,12, frame,&texrLlama,renderer,img_llama2);
            dibujarTexturaxRangoFrame(13,15,frame,&texrLlama,renderer,img_llama3);
            dibujarTexturaxRangoFrame(16,19,frame,&texrLlama,renderer,img_llama4);
            dibujarTexturaxRangoFrame(20,23,frame,&texrLlama,renderer,img_llama5);
            dibujarTexturaxRangoFrame(24,27,frame,&texrLlama,renderer,img_llama6);
            dibujarTexturaxRangoFrame(28,30,frame,&texrLlama,renderer,img_llama7);

            SDL_RenderPresent(renderer);
            eventos_MenuEspera(&e,quit,intervalogame,tiempoIntervalo,timeCat,frame,startTime,bgmMenu,pausedTicks);

            SDL_Delay(10);
        }

//------------------------------------------------------------------------------------------------------
        intervalo_GAME(duracionIntervalo ,tiempoIntervalo ,intervalogame,startTime,pausedTicks);
        fpsgame(frame,tiempoFPS,FPS,startTime,pausedTicks);

//-------------------------------------------------------------------------------------------------------
        if( (Mix_PlayingMusic()==0) && (!victory) && (!gameover) )
            Mix_PlayMusic(bgmGame,-1)  ;
        //EVENTOS DE TIPO ENTRADA //
        if ( SDL_PollEvent(&e) )
        {
            if (e.type == SDL_QUIT)
                break;
            else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE)
                break;
            eventos_EntradaTrenSentido(&e , *ptrTren);
            if((e.type == SDL_KEYDOWN)&&    (   gameover || victory   ) && (e.key.keysym.sym == SDLK_SPACE)  )
                runGame = false ;
        }
        //FIN EVENTOS DE TIPO ENTRADA

        // -----------MAPA-----------------------------
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, img_mapa, NULL, NULL);
        SDL_RenderCopy(renderer, img_interfazScore, NULL, NULL);

        for(int i=0; i<MPOSX; i++)
        {
            for(int j=0; j<MPOSY; j++)
            {
                texrMapaCuadricula.y = mapa[i][j].blit_posx;
                texrMapaCuadricula.x = mapa[i][j].blit_posy;
                SDL_RenderCopy(renderer,img_mapaCuadricula,NULL,&texrMapaCuadricula);
            }
        }
        //------------FIN MAPA--------------------------
        mapa[tren_GetPosx(*ptrTren)][tren_GetPosy(*ptrTren)].ocupado =false ;
        if( (SDL_TICKS_PASSED(timegame(startTime,pausedTicks),timeCat)) && ((tren_GetSentido(*ptrTren))!=centro)  )  // Si paso el tiempo del personaje se avanza 1 fila
        {
            tren_ActualizarVagones(*ptrTren,mapa);
            tren_Movimiento(*ptrTren,timeCat,startTime,pausedTicks);
            mapa[tren_GetPosx(*ptrTren)][tren_GetPosy(*ptrTren)].ocupado =true ;
        }
        /** PARADAS  */
        /**MINA*/
        if(  (tren_GetPosx(*ptrTren) == mina_GetPosx(*ptrMina))&&(tren_GetPosy(*ptrTren) == mina_GetPosy(*ptrMina))  )
        {
            tren_SetSentido(*ptrTren,centro);
        }
        if(  (tren_GetPosx(*ptrTren) == mina_GetPosx(*ptrMina2))&&(tren_GetPosy(*ptrTren) == mina_GetPosy(*ptrMina2))  )
        {
            tren_SetSentido(*ptrTren,centro);
        }
        if(  (tren_GetPosx(*ptrTren) == mina_GetPosx(*ptrMina3))&&(tren_GetPosy(*ptrTren) == mina_GetPosy(*ptrMina3))  )
        {
            tren_SetSentido(*ptrTren,centro);
        }
        /**ESTACION*/
        if(  (tren_GetPosx(*ptrTren) == estacion_PosXE)&&(tren_GetPosy(*ptrTren) == estacion_PosYE)  )
        {
            tren_SetSentido(*ptrTren,centro);
            if(tren_GetCantCoin(*ptrTren)>0)
            {
                tren_AgregarVagon(*ptrTren,0);

                tren_SetCantCoin(*ptrTren,0);
            }
        }
        /** Fin PARADAS */

        // renderer mina
        if (mina_GetVacia(*ptrMina))    SDL_RenderCopy(renderer,img_minaVacia,NULL,&texrMina_1);
        else                            SDL_RenderCopy(renderer,img_minaLlena,NULL,&texrMina_1);
        if (mina_GetVacia(*ptrMina2))   SDL_RenderCopy(renderer,img_minaVacia,NULL,&texrMina_2);
        else                            SDL_RenderCopy(renderer,img_minaLlena,NULL,&texrMina_2);
        if (mina_GetVacia(*ptrMina3))   SDL_RenderCopy(renderer,img_minaVacia,NULL,&texrMina_3);
        else                            SDL_RenderCopy(renderer,img_minaLlena,NULL,&texrMina_3);

        // ** mapa[tren_GetPosx(*ptrTren)][tren_GetPosy(*ptrTren)].ocupado =true ;

        // DIBUJAR vagon antes del Tren !
        tren_MostrarVagones(*ptrTren,img_vagones,renderer);

        texrGato.x = mapa[ptrTren->posx][ptrTren->posy].blit_posy ;   // SE MUEVE POR EL ANCHO DE LA PANTALLA X // distinto de blit_posy
        texrGato.y = mapa[ptrTren->posx][ptrTren->posy].blit_posx ;  // SE MUEVE POR EL ALTO DE LA PANTALLA Y   // distinto de blit_posx
        tren_SetRect(*ptrTren,40,40,mapa[ptrTren->posx][ptrTren->posy].blit_posy,mapa[ptrTren->posx][ptrTren->posy].blit_posx);

        // --------------fin movimiento----------------------------------------------------------------------------

        switch (tren_GetSentido(*ptrTren))
        {
        case der:
            dibujarTexturaxRangoFrame(1,3,  frame,&texrGato,renderer,img_gato1);
            dibujarTexturaxRangoFrame(7,9,  frame,&texrGato,renderer,img_gato1);
            dibujarTexturaxRangoFrame(13,15,frame,&texrGato,renderer,img_gato1);
            dibujarTexturaxRangoFrame(19,21,frame,&texrGato,renderer,img_gato1);
            dibujarTexturaxRangoFrame(25,27,frame,&texrGato,renderer,img_gato1);

            dibujarTexturaxRangoFrame(4,6,  frame,&texrGato,renderer,img_gato2);
            dibujarTexturaxRangoFrame(10,12,frame,&texrGato,renderer,img_gato2);
            dibujarTexturaxRangoFrame(16,18,frame,&texrGato,renderer,img_gato2);
            dibujarTexturaxRangoFrame(22,24,frame,&texrGato,renderer,img_gato2);
            dibujarTexturaxRangoFrame(28,30,frame,&texrGato,renderer,img_gato2);
            ;
            break;

        case arriba:
            dibujarTexturaxRangoFrame(1,3,  frame,&texrGato,renderer,img_trenUp1);
            dibujarTexturaxRangoFrame(7,9,  frame,&texrGato,renderer,img_trenUp1);
            dibujarTexturaxRangoFrame(13,15,frame,&texrGato,renderer,img_trenUp1);
            dibujarTexturaxRangoFrame(19,21,frame,&texrGato,renderer,img_trenUp1);
            dibujarTexturaxRangoFrame(25,27,frame,&texrGato,renderer,img_trenUp1);

            dibujarTexturaxRangoFrame(4,6,  frame,&texrGato,renderer,img_trenUp2);
            dibujarTexturaxRangoFrame(10,12,frame,&texrGato,renderer,img_trenUp2);
            dibujarTexturaxRangoFrame(16,18,frame,&texrGato,renderer,img_trenUp2);
            dibujarTexturaxRangoFrame(22,24,frame,&texrGato,renderer,img_trenUp2);
            dibujarTexturaxRangoFrame(28,30,frame,&texrGato,renderer,img_trenUp2);
            ;
            break;

        case izq:
            dibujarTexturaxRangoFrame(1,3,  frame,&texrGato,renderer,img_trenLeft1);
            dibujarTexturaxRangoFrame(7,9,  frame,&texrGato,renderer,img_trenLeft1);
            dibujarTexturaxRangoFrame(13,15,frame,&texrGato,renderer,img_trenLeft1);
            dibujarTexturaxRangoFrame(19,21,frame,&texrGato,renderer,img_trenLeft1);
            dibujarTexturaxRangoFrame(25,27,frame,&texrGato,renderer,img_trenLeft1);

            dibujarTexturaxRangoFrame(4,6,  frame,&texrGato,renderer,img_trenLeft2);
            dibujarTexturaxRangoFrame(10,12,frame,&texrGato,renderer,img_trenLeft2);
            dibujarTexturaxRangoFrame(16,18,frame,&texrGato,renderer,img_trenLeft2);
            dibujarTexturaxRangoFrame(22,24,frame,&texrGato,renderer,img_trenLeft2);
            dibujarTexturaxRangoFrame(28,30,frame,&texrGato,renderer,img_trenLeft2);
            ;
            break;

        case abajo:
            dibujarTexturaxRangoFrame(1,3,  frame,&texrGato,renderer,img_trenDown1);
            dibujarTexturaxRangoFrame(7,9,  frame,&texrGato,renderer,img_trenDown1);
            dibujarTexturaxRangoFrame(13,15,frame,&texrGato,renderer,img_trenDown1);
            dibujarTexturaxRangoFrame(19,21,frame,&texrGato,renderer,img_trenDown1);
            dibujarTexturaxRangoFrame(25,27,frame,&texrGato,renderer,img_trenDown1);

            dibujarTexturaxRangoFrame(4,6,  frame,&texrGato,renderer,img_trenDown2);
            dibujarTexturaxRangoFrame(10,12,frame,&texrGato,renderer,img_trenDown2);
            dibujarTexturaxRangoFrame(16,18,frame,&texrGato,renderer,img_trenDown2);
            dibujarTexturaxRangoFrame(22,24,frame,&texrGato,renderer,img_trenDown2);
            dibujarTexturaxRangoFrame(28,30,frame,&texrGato,renderer,img_trenDown2);
            ;
            break;
        case centro:
            dibujarTexturaxRangoFrame(1,3,  frame,&texrGato,renderer,img_trenUp1);
            dibujarTexturaxRangoFrame(7,9,  frame,&texrGato,renderer,img_trenUp1);
            dibujarTexturaxRangoFrame(13,15,frame,&texrGato,renderer,img_trenUp1);
            dibujarTexturaxRangoFrame(19,21,frame,&texrGato,renderer,img_trenUp1);
            dibujarTexturaxRangoFrame(25,27,frame,&texrGato,renderer,img_trenUp1);

            dibujarTexturaxRangoFrame(4,6,  frame,&texrGato,renderer,img_trenUp2);
            dibujarTexturaxRangoFrame(10,12,frame,&texrGato,renderer,img_trenUp2);
            dibujarTexturaxRangoFrame(16,18,frame,&texrGato,renderer,img_trenUp2);
            dibujarTexturaxRangoFrame(22,24,frame,&texrGato,renderer,img_trenUp2);
            dibujarTexturaxRangoFrame(28,30,frame,&texrGato,renderer,img_trenUp2);
            ;
            break;
        }
        //---------------------TEST LISTA ERROR------------------------------
        agregarMonedas(listaMoneda,idmoneda,Max_intervalo ,Max_duracion ,intervalogame ,intervaloRandom , mapa);
        mostrarMonedas(listaMoneda,intervalogame,ptrTren,mapa,img_coin,renderer);
        if(  (!gameover) && (!victory) )
        {
            agregarBandidos(listaBandido,idbandido,Max_intervalo_bandido,Max_duracion_bandido,intervalogame,intervaloRandom_bandido,mapa,MaxRecursos);
            mostrarBandidos(listaBandido,inventario,intervalogame,ptrTren,mapa,gameover,img_bandido,renderer,&e,pausedTicks,img_bgBlack,img_stop,img_tributoBg,img_tributoDer,img_tributoIzq,img_tributoBandido,bgmGame,bgmTributo);

            generarRecurso(vectorCajas,ptrMina,intervaloProduccion,intervalogame,tiempoIP,posProd); // intercambie colision por generarRecurso
            colisionTrenMina(*ptrTren ,ptrMina ,vectorCajas,posProd,inventario);

            generarRecurso(vectorCajasMina2,ptrMina2,intervaloProduccionMina2,intervalogame,tiempoIPMina2,posProdMina2);
            colisionTrenMina(*ptrTren ,ptrMina2 ,vectorCajasMina2,posProdMina2,inventario);

            generarRecurso(vectorCajasMina3,ptrMina3,intervaloProduccionMina3,intervalogame,tiempoIPMina3,posProdMina3);
            colisionTrenMina(*ptrTren ,ptrMina3 ,vectorCajasMina3,posProdMina3,inventario);
        }

        ssScore.str("");
        ssScore <<"x" <<tren_GetCantCoin(*ptrTren) ;
        text_surface = TTF_RenderText_Solid(times,ssScore.str().c_str(),color);
        message = SDL_CreateTextureFromSurface(renderer,text_surface);

        //--------------------------------------------------------
        SDL_RenderCopy(renderer,img_estacion,NULL,&texrEstacion);

        SDL_RenderCopy(renderer,message,NULL,&texrText);//**** imprime el SCORE
        //--------------------------------------------------------
        if(   (gameover)   && (!victory)    )       //gameover hacer funcion !!! Si el tren esta en el borde y pasa 1 intervalo entra
        {
            dibujarTexturaxRangoFrame(1,7,frame,NULL,renderer,img_gameover[0]);
            dibujarTexturaxRangoFrame(8,15,frame,NULL,renderer,img_gameover[1]);
            dibujarTexturaxRangoFrame(16,22,frame,NULL,renderer,img_gameover[2]);
            dibujarTexturaxRangoFrame(23,30,frame,NULL,renderer,img_gameover[3]);
            if (Mix_PlayingMusic()==0)      Mix_PlayMusic(bgmGameOver,-1)  ;

        }
        else
        {
            if( (tren_GetBorde(*ptrTren) != sinBorde) && (!victory)  )
            {
                gameover = true ;
                Mix_PlayMusic(bgmGame,0);
                Mix_HaltMusic();
            }
        }
        if(victory)
        {
            SDL_RenderCopy(renderer,img_gamewin,NULL,NULL);
            if (Mix_PlayingMusic()==0)      Mix_PlayMusic(bgmGameWin,-1)  ;

        }
        else
        {
            if( (( comanda[oro]-inventario[oro])<= 0) && (( comanda[plata]-inventario[plata])<= 0) && (( comanda[bronce]-inventario[bronce])<= 0)  )
            {
                victory = true ;
                Mix_PlayMusic(bgmGame,0);
                Mix_HaltMusic();
            }
        }
        //---------------------------------------------------------
        SDL_RenderPresent(renderer);

        // GAME OVER
        SDL_Delay(10); // Simplemente para que no consuma demasiado CPU , puede traer problemas con los ticks
    }//fin run
    //-----------------fin del juego ----------------------------------------------------------------
    terminarGame();
    //--------------------- eliminar punteros---------------

    Mix_FreeMusic(bgmGame);
    Mix_Quit();
    tren_Destruir(*ptrTren);
    eliminarLista(listaMoneda);
    eliminarLista(listaBandido);

    delete ptrMina;
    delete ptrMina2;
    delete ptrMina3;
    delete vectorCajas;
    delete vectorCajasMina2;
    delete vectorCajasMina3;

    TTF_Quit();
    //------------------------------------------------------
}//fin void

bool inicializar()
{


    // INIT del SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return false;
    };

    //INIT del audio		};
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2 ,2048)!=0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return false;
    };
    //INIT del texto
    if(TTF_Init()==-1)
    {
        printf("TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }
    //INIT de la ventana
    win = SDL_CreateWindow("CATS of UNLA", 100, 100, WIDTH, HEIGHT, 0);
    if (!win)
    {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return false;
    };


    //Creacion del render
    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    //Creacion de imagenes
    img_menu = IMG_LoadTexture(renderer, IMG_MENU_PATH);
    img_gamewin = IMG_LoadTexture(renderer, IMG_WINGAME_PATH);
    img_mapa = IMG_LoadTexture(renderer, IMG_BG_PATH);
    img_start = IMG_LoadTexture(renderer, IMG_PRESS_START_PATH);
    img_bgBlack = IMG_LoadTexture(renderer, IMG_BG_BLACK_PATH);
    img_stop = IMG_LoadTexture(renderer, IMG_STOP_PATH);
    img_tributoBg = IMG_LoadTexture(renderer, IMG_TRIBUTO_BG_PATH);
    img_tributoBandido = IMG_LoadTexture(renderer, IMG_TRIBUTO_BANDIDO_PATH);
    img_tributoDer = IMG_LoadTexture(renderer, IMG_TRIBUTO_DER_PATH);
    img_tributoIzq = IMG_LoadTexture(renderer, IMG_TRIBUTO_IZQ_PATH);
    img_gato1 = IMG_LoadTexture(renderer, IMG_TRENRIGHT1_PATH);
    img_gato2 = IMG_LoadTexture(renderer, IMG_TRENRIGHT2_PATH);
    /*img_coin = IMG_LoadTexture(renderer, IMG_COIN_PATH);*/
    /*img_bandido = IMG_LoadTexture(renderer, IMG_BANDIDO_PATH);*/
    img_llama = IMG_LoadTexture(renderer, IMG_BANDIDO_LLAMA_PATH);
    img_llama1 = IMG_LoadTexture(renderer, IMG_BANDIDO_LLAMA1_PATH);
    img_llama2 = IMG_LoadTexture(renderer, IMG_BANDIDO_LLAMA2_PATH);
    img_llama3 = IMG_LoadTexture(renderer, IMG_BANDIDO_LLAMA3_PATH);
    img_llama4 = IMG_LoadTexture(renderer, IMG_BANDIDO_LLAMA4_PATH);
    img_llama5 = IMG_LoadTexture(renderer, IMG_BANDIDO_LLAMA5_PATH);
    img_llama6 = IMG_LoadTexture(renderer, IMG_BANDIDO_LLAMA6_PATH);
    img_llama7 = IMG_LoadTexture(renderer, IMG_BANDIDO_LLAMA7_PATH);

    SDL_QueryTexture(img_gato1, NULL, NULL, &wgato, &hgato);
    texrGato.x = 0;
    texrGato.y = 200;
    texrGato.w = wgato/1;//1.8
    texrGato.h = hgato/1;

    cargarTextura(img_coin,texrCoin,IMG_COIN_PATH,renderer,1,1); //2

    cargarTextura(img_bandido,texrBandido,IMG_BANDIDO_PATH,renderer,1,1);//1.7

    SDL_QueryTexture(img_llama, NULL, NULL, &wllama, &hllama);
    texrLlama.x = 0;
    texrLlama.y = 0;
    texrLlama.w = wllama/3.2;
    texrLlama.h = hllama/4.4;

    texrText.x = 180;
    texrText.y = 15;
    texrText.w = 60;
    texrText.h = 30;

    cargarTextura(img_minaVacia,texrMina_1,IMG_MINA_VACIA_PATH,renderer,1,1);
    cargarTextura(img_minaLlena,texrMina_1,IMG_MINA_PATH,renderer,1,1);//3.8
    cargarTextura(img_estacion,texrEstacion,IMG_ESTACION_PATH,renderer,1,1);//2
    cargarTextura(img_vagon,texrVagon,IMG_VAGON_PATH,renderer,1,1);//3.5
    cargarTextura(img_mapaCuadricula,texrMapaCuadricula,IMG_CUADRICULA_PATH,renderer,1,1);
    cargarTextura(img_trenLeft1,texrGato,IMG_TRENLEFT1_PATH,renderer,1,1);
    cargarTextura(img_trenLeft2,texrGato,IMG_TRENLEFT2_PATH,renderer,1,1);
    cargarTextura(img_trenUp1,texrGato,IMG_TRENUP1_PATH,renderer,1,1);
    cargarTextura(img_trenUp2,texrGato,IMG_TRENUP2_PATH,renderer,1,1);
    cargarTextura(img_trenDown1,texrGato,IMG_TRENDOWN1_PATH,renderer,1,1);
    cargarTextura(img_trenDown2,texrGato,IMG_TRENDOWN2_PATH,renderer,1,1);


    startTime = SDL_GetTicks();

    return true;

}

void terminarGame()
{

    //Liberar

    SDL_DestroyTexture(img_mapa);
    SDL_DestroyTexture(img_gato1);
    SDL_DestroyTexture(img_gato2);
    SDL_DestroyTexture(img_coin);
    SDL_DestroyTexture(img_bandido);
    SDL_DestroyTexture(img_start);
    SDL_DestroyTexture(img_menu);
    SDL_DestroyTexture(img_gamewin);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    //Mix_FreeMusic(bgm);
    //Mix_Quit();
}

void crearMapa(Mapa mapa[][MPOSY])
{

    int posInitx,posInity,desx,desy; // calcular el desplazamiento dependiendo de la resolucion del mapa (ANCHO y LARGO) o de su area a dibujar

    desx = 40;  // Suponemos un desplazamiento de 40 , ya que 40 son los pixeles que vamos a usar 40x40 esto se deberia hacer con una funcion (x65,y64)
    desy = 40;
    posInity = ((WIDTH)-(desx*MPOSY) )/2; // Posicion de inicio de la matriz dibujada en pantalla ,superior izquierda
    posInitx = ((HEIGHT)-(desy*MPOSX))/2 ;

    for(int i=0; i<MPOSX; i++)
    {

        for(int j=0; j<MPOSY; j++)
        {
            mapa[i][j].ocupado = false ;
            mapa[i][j].blit_posx = (desx *i)+posInitx;  // X
            mapa[i][j].blit_posy = (desy *j)+posInity;  // Y
            //SDL_RenderCopy(renderer,img_bandido,NULL,&texrBandido);
        }
    }
}


//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
// Si listaActiva == true hacer esto <<
//Precondicion definir antes:   intervalo o aparicion = intervaloSeg(aparicion,timegame());  <--- intervalo "Aparicion"********   activo = false  listaActiva= true
int id_borrarMoneda(Uint32 &aparicion, Uint32 intervaloActual, Moneda *ptrMoneda)  //--->Devuelve el ID de la moneda a borrar , si no hay moneda para borrar devuelve -1
{

    if (intervalo_PASSED(intervaloActual, aparicion ) )  //Si pasa el intervalo de tiempo hace tal accion
    {
        return (ptrMoneda->id) ;// si paso , localizarlo por id y borrar el item de la lista
    }
    else return (-1) ;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------- POSICIONES ALEATORIAS----------------------------------------------------------------------------
/*void posicionAleatoria(Moneda* ptrmoneda){    // pasar como parametro fila y col de la matriz que viene en el archivo
    int fila = 6 , col = 10 ;
    int miRandomA = rand()%(fila-1);
    int miRandomB = rand()%(col-1);

    if (fila>col)
        while (miRandomA == ptrmoneda->posx){
            miRandomA = rand()%(fila-1);
        }
    else
        while (miRandomB == ptrmoneda->posy){
            miRandomB = rand()%(col-1);
        }

    //posA = miRandomA;
    //posB = miRandomB;
    moneda_SetPosx(*ptrmoneda,miRandomA);
    moneda_SetPosy(*ptrmoneda,miRandomB);

}*/

//------------------------- POSICIONES ALEATORIAS 2----------------------------------------------------------------------------
void posicionAleatoria(int &posA , int &posB)
{
    int fila = 6 , col = 10 ;
    int miRandomA = rand()%(fila-1);
    int miRandomB = rand()%(col-1);

    if (fila>col)
        while (miRandomA == posA)
        {
            miRandomA = rand()%(fila-1);
        }
    else
        while (miRandomB == posB)
        {
            miRandomB = rand()%(col-1);
        }

    posA = miRandomA;
    posB = miRandomB;

}

void intervaloAleatorio(int duracion , int aparicion , int maxDuracion , int maxIntervalo)  // quizas solo lo seteo //
{
    duracion = rand()%maxDuracion;
    aparicion = rand()%maxIntervalo;
}
//--------------------------------------------------------------------------------------------------
//------------------------CAJA-----------------------------------------------//
void generarSecuenciaCajas(Caja *&ptrCaja ,Mina *&ptrMina, e_recurso recurso ,int seq1,int seq2,int seq3,int seq4,int seq5)   // No se si esta bien //CREO deberia encolar todo tambien
{
    // deberia pasar por parametro los 5 recursos de la mina , la estructura que los contenga
    caja_SetCantItem(ptrCaja[0],seq1);//2 = seq 1
    caja_SetCantItem(ptrCaja[1],seq2);//1 = seq 2 .. seq como parametro
    caja_SetCantItem(ptrCaja[2],seq3);
    caja_SetCantItem(ptrCaja[3],seq4);
    caja_SetCantItem(ptrCaja[4],seq5);

    caja_SetRecurso(ptrCaja[0],recurso);
    caja_SetRecurso(ptrCaja[1],recurso);
    caja_SetRecurso(ptrCaja[2],recurso);
    caja_SetRecurso(ptrCaja[3],recurso);
    caja_SetRecurso(ptrCaja[4],recurso);

    encolar(ptrMina->cajas,&ptrCaja[0]);
    encolar(ptrMina->cajas,&ptrCaja[1]);
    encolar(ptrMina->cajas,&ptrCaja[2]);
    encolar(ptrMina->cajas,&ptrCaja[3]);
    encolar(ptrMina->cajas,&ptrCaja[4]);

    mina_SetVacia(*ptrMina,false);
}
//------------------------MINA-----------------------------------------------//
void generarRecurso(Caja *&ptrCaja ,Mina *&ptrMina , int intervaloProduccion , Uint32 intervaloActual , Uint32 &tiempoIntervaloProduccion, int &posProd)  //CREO encola solo uno
{
    // std::cout<<"\nCAJA: "<< ptrCaja[1].cantItem<<std::endl;
    if (intervalo_PASSED(intervaloActual, tiempoIntervaloProduccion))   //  || mapa.ocupado
    {
        if ( posProd >= 5 ) posProd = 0 ;    //cambiar de recurso desencolar y ese mismo encolar nuevamente // PARA MODIFICAR COLA FRENTE caja_SetCantItem(*(  (Caja*)(colaFrente(ptrMina->cajas)->ptrDato) )  ,89);
        if(!(ptrMina->vacia))
        {
            encolar(ptrMina->cajas,/*((  (Caja*)(colaFrente(ptrMina->cajas)->ptrDato) )  )*/&ptrCaja[posProd]); //Encolar el frente
            desencolar(ptrMina->cajas);
            std::cout<<"\nMina: "<< mina_GetId(*ptrMina) <<"\nCOLA PRODUCCION : "<< caja_GetCantItem(*(  (Caja*)(colaFrente(ptrMina->cajas)->ptrDato) )  ) <<" recursos generados \nINTERVALO PRODUCCION: "<<posProd<<std::endl;
            posProd+=1 ;
        }

        tiempoIntervaloProduccion = intervalo_ADDTIME(intervaloProduccion,intervaloActual);
        mina_SetVacia(*ptrMina,false);


    }
}//SE CREA 5 PUNTEROS CAJA Y SE AGREGA A LA COLA , sino se hace en el procedimiento principal con arrays

void colisionTrenMina(Tren &tren ,Mina* &ptrMina ,Caja* &vectorCajas ,int &posProd ,int vectorInventario[5])
{
    if ( (tren_GetPosx(tren) == mina_GetPosx(*ptrMina))&&(tren_GetPosy(tren) == mina_GetPosy(*ptrMina))&& (!(mina_GetVacia(*ptrMina))) )  //MANDAR A FUNCION
    {
        encolar(ptrMina->cajas,&vectorCajas[posProd]);
        Caja* auxcaja = (Caja*)desencolar(ptrMina->cajas);////NUEVO
        mina_SetVacia(*ptrMina,true);
        posProd+=1 ;
        // if hay vagones " longitud de la lista = 0 " sumar { hacer bucle con todos los vagones pero si encontro alguno debe salir de la iteracion
        bool encontrado = false ;
        PtrNodoLista minodo = primero(tren.vagones);
        while(     (minodo != finLista()) && (!encontrado)    )
        {

            Vagon* ptrvagon = (Vagon*) minodo->ptrDato;

            sumarCajaEnVagon(*ptrvagon,auxcaja,vectorInventario,encontrado);

            minodo = siguiente(tren.vagones, minodo);
        }

        /**
        std::cout<<" \n VAGON // capacidad : "<<vagon_GetCapacidad(vagon) <<" Cantidad de items : "<<vagon_GetCantItem(vagon)<< " Items de Mina a recibir : "<<auxcaja->cantItem<<" \n";
        if(     (   (vagon.recurso == auxcaja->recurso)||(vagon.recurso == noAsignado)  ) &&      ( ( vagon_GetCapacidad(vagon) - vagon_GetCantItem(vagon) ) >= auxcaja->cantItem )   ) //capacidad - cantItem = Items disponibles
        {
            if  (vagon.recurso == noAsignado)   vagon_SetRecurso(vagon,auxcaja->recurso);
            vagon_ApilarCaja(vagon,auxcaja);//NUEVO
            vagon_SetCantItem(vagon,auxcaja->cantItem + vagon_GetCantItem(vagon));
            Caja auxcajaComanda = *auxcaja;//NUEVO
            comanda[auxcajaComanda.recurso] += auxcajaComanda.cantItem ;//Lleno la comanda de recurso con el recurso y cantItem ;
            //recurso : 0- noAsignado 1- oro 2-plata 3-bronce

            std::cout<<" Numero de recursos obtenidos : OROx"<< comanda[0] <<" PLATAx"<< comanda[1] <<" BRONCEx"<< comanda[2] <<"\n Vagon : Cantidad de items en la caja de la cima : "<< caja_GetCantItem( *(  (Caja*)(cima(vagon.cajas)->ptrDato) )  ) <<std::endl; //MODIFICAR PERO VA BIEN
        }
        */
        // } else no hacer nada , ya que en el momento que pisa la mina siempre se desencola arriba

    }
}

void sumarCajaEnVagon(Vagon &vagon, Caja* caja ,int vectorInventario[5],bool &flag)
{
    std::cout<<" \n VAGON // capacidad : "<<vagon_GetCapacidad(vagon) <<" Cantidad de items : "<<vagon_GetCantItem(vagon)<< " Items de Mina a recibir : "<<caja->cantItem<<" \n";
    if(     (   (vagon.recurso == caja->recurso)||(vagon.recurso == noAsignado)  ) &&      ( ( vagon_GetCapacidad(vagon) - vagon_GetCantItem(vagon) ) >= caja->cantItem )   ) //capacidad - cantItem = Items disponibles
    {
        if  (vagon.recurso == noAsignado)   vagon_SetRecurso(vagon,caja->recurso);
        vagon_ApilarCaja(vagon,caja);//NUEVO
        vagon_SetCantItem(vagon,caja->cantItem + vagon_GetCantItem(vagon));
        Caja auxcajaComanda = *caja;//NUEVO
        vectorInventario[auxcajaComanda.recurso] += auxcajaComanda.cantItem ;//Lleno la comanda de recurso con el recurso y cantItem ;
        //recurso : 0- noAsignado 1- oro 2-plata 3-bronce
        flag = true ;
        std::cout<<" Comanda - recursos obtenidos : OROx"<< vectorInventario[oro] <<" PLATAx"<< vectorInventario[plata] <<" BRONCEx"<< vectorInventario[bronce] <<"\n Vagon : Cantidad de items en la caja de la cima : "<< caja_GetCantItem( *(  (Caja*)(cima(vagon.cajas)->ptrDato) )  ) <<std::endl; //MODIFICAR PERO VA BIEN
    }
    // } else no hacer nada , ya que en el momento que pisa la mina siempre se desencola arriba
}


//------------------------COMPARACIONES-----------------------------------------------//
ResultadoComparacion compararListaMoneda(PtrDato ptrDato1, PtrDato ptrDato2)
{
    int dato1 = ((Moneda*) ptrDato1)->id;
    int dato2 = ((Moneda*) ptrDato2)->id;

    if (dato1 < dato2)
    {
        return MENOR;
    }
    else if (dato1 > dato2)
    {
        return MAYOR;
    }
    else
    {
        return IGUAL;
    }
}

ResultadoComparacion compararListaBandido(PtrDato ptrDato1, PtrDato ptrDato2)
{
    int dato1 = ((Bandido*) ptrDato1)->id;
    int dato2 = ((Bandido*) ptrDato2)->id;

    if (dato1 < dato2)
    {
        return MENOR;
    }
    else if (dato1 > dato2)
    {
        return MAYOR;
    }
    else
    {
        return IGUAL;
    }
}
//------------------------FIN COMPARACIONES----------------------------------------------//

/*
//  SDL_Rect divider[30];
	for (int i=0; i<30; i++){
		divider[i].w =   4;
		divider[i].h =  10;
		divider[i].x = 398;
		divider[i].y = 5+i*(divider[i].h*2);
	}

	for (int i=0; i<30; i++){
    SDL_RenderFillRect(Renderer, &divider[i]);
}
*/

















