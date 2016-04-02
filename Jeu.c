#include "Jeu.h"
#include "Menu.h"

#include <stdio.h>
#include <stdlib.h>


void jeu(SDL_Surface *ecran)
{
    SDL_Surface *plateau = NULL;
    SDL_Rect positionPlateau;
    SDL_Event event;
    Button tab_button[3];
    int continuer = 1, i;

    positionPlateau.x = 260;
    positionPlateau.y = 150;

    plateau = IMG_Load("Images/hex.png");
    create_button_menu(tab_button);

    while (continuer)
    {
        SDL_WaitEvent(&event);

        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
        SDL_BlitSurface(plateau, NULL, ecran, &positionPlateau);
        for (i = Jouer; i <= Quitter; ++i)
        {
            SDL_BlitSurface(tab_button[i].button, NULL, ecran, &(tab_button[i].positionButton));
            SDL_BlitSurface(tab_button[i].texte, NULL, ecran, &(tab_button[i].positionTexte));
        }
        SDL_Flip(ecran);
    }

    SDL_FreeSurface(plateau);
}
