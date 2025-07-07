#include "function.h"

int main(void)
{
    // Inizializzare SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Errore di inizializzazione di SDL \n");
        return 0;
    }

    // Creazione e configurazione della window
    SDL_Window *window = SDL_CreateWindow(
        "Studio Funzioni Elementari",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH,
        HEIGHT,
        SDL_WINDOW_RESIZABLE
    );


    // Controllo sulla corretta aperta della window
    if (window==NULL){
        printf("Errore nella apertura della window \n");
        return 0;
    }

    // Creazione del renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED);

    // Controllosulla corretta creazione del renderer
    if (renderer == NULL){
        printf("Errore nella apertura della window \n");
        return 0;       
    }

    // Variabile per determinare l'uscita dal ciclo while
    int exit = 1;
    // Variabile necessarie per determinare quale funzione studiare
    int choose = 0;
    // Ciclo per chiedere quale funzione studiare, attraverso un menù
    while(exit){
        // Menù
        printf("Quale delle seguenti funzioni elementari vorresti studiare?\n");
        printf("0 - Uscire \n");
        printf("1 - Retta \n");

        // Leggo in input la funzione da dover studiare
        scanf("%d", &choose);

        // Switch per studiare la funzione
        switch (choose)
        {
        case 0:
            exit = 0;
            break;
        case 1:
            /* code */
            break;
        default:
            printf("Scelta sbagliata, riprovare! \n");
        }
    }
}