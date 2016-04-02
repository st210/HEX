#include "Jeu.h"
#include "menu.h"

#include <stdio.h>
#include <stdlib.h>

#include <SDL/SDL.h>
#include <SDL/SDL_keysym.h>
#include "SDL_image.h"
#include "SDL_ttf.h"


int main (int argc, char *argv[])
{
    SDL_Surface *ecran = NULL;
    Uint8 video_bpp = 32;
    int continuer, choix;
    SDL_Event event;

    continuer = 1;

    SDL_Init(SDL_INIT_VIDEO);

    if (SDL_Init(SDL_INIT_VIDEO) == -1)
        {
            fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
    TTF_Init();
    ecran = SDL_SetVideoMode(WINWI, WINHI, video_bpp, SDL_HWSURFACE | SDL_DOUBLEBUF);

    if (ecran == NULL)
    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_WM_SetCaption("Jeu de HEX", NULL);
    SDL_WM_SetIcon(IMG_Load("Images/hex_icon.png"), NULL);

    choix = create_menu(ecran);
    jeu(ecran);


    TTF_Quit();
    SDL_FreeSurface(ecran);
    SDL_Quit();

    return EXIT_SUCCESS;
}
