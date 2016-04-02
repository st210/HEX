#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#define WINHI 600 // window height
#define WINWI 800 // window width

#include <SDL/SDL.h>
#include <SDL/SDL_keysym.h>
#include "SDL_image.h"
#include "SDL_ttf.h"


struct str_button
{
    SDL_Surface *texte, *button;
    SDL_Rect positionButton, positionTexte;
};

typedef struct str_button Button;
enum choix {Jouer, Charger, Quitter};

char *ToString (int i);
int create_menu(SDL_Surface *ecran);
void create_button_menu(Button *tab_button);

#endif // MENU_H_INCLUDED
