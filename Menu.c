#include <stdio.h>
#include <stdlib.h>

#include "Menu.h"


char *ToString (int i)
{
    char *nom;
    if (i == 0) nom = "Jouer";
    if (i == 1) nom = "Charger";
    if (i == 2) nom = "Quitter";

    return nom;
}


void create_button_menu(Button *tab_button)
{
    int width, height, i;
    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {0, 0, 0};

    width = 20;
    height = 100;
    police = TTF_OpenFont("font_police/OptimusPrinceps.ttf", 32);

    for (i = Jouer; i <= Quitter; ++i)
    {
        tab_button[i].positionButton.x = width;
        tab_button[i].positionButton.y = height;

        tab_button[i].button = IMG_Load("Images/rectangle_gray.png");

        tab_button[i].texte = TTF_RenderText_Blended(police, ToString(i), couleurNoire);

        tab_button[i].positionTexte.x = (tab_button[i].positionButton.x) + 25;
        tab_button[i].positionTexte.y = (tab_button[i].positionButton.y) + 20;

        height = height + 80;
    }
}

int create_menu (SDL_Surface *ecran)
{
    SDL_Event event;
    Button tab_button[3];
    int option_choisie, continuer = 1, i, height, width;
    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {0, 0, 0};

    height = (WINHI/2) - 150;
    width = (WINWI/2) - 100;

    police = TTF_OpenFont("font_police/OptimusPrinceps.ttf", 32);

    for (i = Jouer; i <= Quitter; ++i)
    {
        tab_button[i].positionButton.x = width;
        tab_button[i].positionButton.y = height;

        tab_button[i].button = IMG_Load("Images/rectangle_gray.png");

        tab_button[i].texte = TTF_RenderText_Blended(police, ToString(i), couleurNoire);

        tab_button[i].positionTexte.x = (tab_button[i].positionButton.x) + 25;
        tab_button[i].positionTexte.y = (tab_button[i].positionButton.y) + 20;

         height = height + 100;
    }

    while (continuer)
    {
        SDL_WaitEvent(&event);

        switch(event.type)
        {
            case SDL_MOUSEBUTTONUP:
                if (event.button.x > tab_button[Jouer].positionButton.x && event.button.x < tab_button[Jouer].positionButton.x + 160 && event.button.y > tab_button[Jouer].positionButton.y && event.button.y < tab_button[Jouer].positionButton.y +69)
                {
                    option_choisie = 0;
                    continuer = 0;
                }
                else if (event.button.x > tab_button[Charger].positionButton.x && event.button.x < tab_button[Charger].positionButton.x + 160 && event.button.y > tab_button[Charger].positionButton.y && event.button.y < tab_button[Charger].positionButton.y +69)
                {
                    option_choisie = 1;
                    continuer = 0;
                }
                else if (event.button.x > tab_button[Quitter].positionButton.x && event.button.x < tab_button[Quitter].positionButton.x + 160 && event.button.y > tab_button[Quitter].positionButton.y && event.button.y < tab_button[Quitter].positionButton.y +69)
                {
                    option_choisie = 2;
                    continuer = 0;
                }
                break;

            case SDL_QUIT:
                continuer = 0;
                break;
        }
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

        for (i = Jouer; i <= Quitter; ++i)
        {
            SDL_BlitSurface(tab_button[i].button, NULL, ecran, &(tab_button[i].positionButton));
            SDL_BlitSurface(tab_button[i].texte, NULL, ecran, &(tab_button[i].positionTexte));
        }
        SDL_Flip(ecran);
    }
    return (option_choisie);

}

