#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>

void pause();

int main(int argc, char *argv[])
{
    // VARIABLES
    SDL_Surface *ecran = NULL, *pion = NULL;
    SDL_Rect position_pion;
    SDL_Event event;
    int fin = 0;

    position_pion.x = 100;
    position_pion.y = 50;


    // INITIALIZATION
    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetCaption(" HEX: Take it easy !", NULL);
    SDL_WM_SetIcon(IMG_Load("images/hex_icon.png"), NULL);


    // OPEN SCREEN
    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
    if (ecran == NULL)
    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    // UPDATE SCREEN
    // background
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    // pion
    pion = IMG_Load("images/button_blue_mini.png");

    // ACTIONS
    while (!fin)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            // close window
            case SDL_QUIT:
                fin = 1;
                break;
            // key pressed
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        fin = 1;
                        break;
                }
                break;
            // mouse click
            case SDL_MOUSEBUTTONUP:
                if (event.button.button == SDL_BUTTON_RIGHT)
                    fin = 1;
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    position_pion.x = event.button.x;
                    position_pion.y = event.button.y;
                }
                break;
        }

        SDL_SetColorKey(pion, SDL_SRCCOLORKEY, SDL_MapRGB(pion->format, 255, 255, 255)); // transparency
        SDL_BlitSurface(pion, NULL, ecran, &position_pion);
        SDL_Flip(ecran);
    }


    // END
    // free memory space
    SDL_FreeSurface(pion);
    SDL_Quit();

    return EXIT_SUCCESS;
}
