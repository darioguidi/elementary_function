#include "function.h"

int main(void)
{
    // Inizializzare SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Errore di inizializzazione di SDL \n");
        return 0;
    }

    // Creazione e configurazione della window
    // Nella configurazione: titolo finestra, posizione finestra rispetto le coordinate (x,y), dimensione della finestra, attributi della finestra
    SDL_Window *window = SDL_CreateWindow(
        "Studio Funzioni Elementari",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_RESIZABLE
    );

    // Controllo sulla corretta apertura della window
    if (window == NULL) {
        printf("Errore nella apertura della window \n");
        return 0;
    }

    // Creazione del renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Controllo sulla corretta creazione del renderer
    if (renderer == NULL) {
        printf("Errore nella creazione del renderer \n");
        return 0;
    }

    // Variabile per determinare l'uscita dal ciclo while
    int exit = 1;
    // Variabile necessaria per determinare quale funzione studiare
    int choose = 0;
    // Variabile per controllare il ciclo di rendering
    int running;

    SDL_Event event;

    // Ciclo per chiedere quale funzione studiare, attraverso un menù
    while (exit) {
        // Menù
        printf("Quale delle seguenti funzioni elementari vorresti studiare?\n");
        printf("0 - Uscire \n");
        printf("1 - Retta \n");
        printf("2 - Parabola y = x^2 \n");

        // Leggo in input la funzione da dover studiare
        scanf("%d", &choose);

        // Switch per studiare la funzione
        switch (choose) {
        case 0:
            // Condizione di uscita
            exit = 0;
            break;

        case 1:
            // Codice per la stampa di una retta
            // Si richiede di inserire il coefficiente angolare ed l'ordinata d'origine

            // Reinizializzo i valori a zero
            float coeff_angolare = 0.0f, ordinata_origine = 0.0f;

            printf("Inserire coefficiente angolare della retta (m): \n");
            scanf("%f", &coeff_angolare);

            printf("Inserire l'ordinata all'origine della retta (q): \n");
            scanf("%f", &ordinata_origine);

            // Condizione ciclo
            running = 1;

            // Questo ciclo serve a mostrare a schermo il risultato della funzione 'retta'
            while (running) {
                // Ciclo che rimane in ascolto di possibili eventi da dover eseguire in base alla condizione associata
                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        printf("Chiusura del programma \n");
                        running = 0;
                    }
                }

                // Imposto il colore di sfondo
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

                // Pulire il renderer
                SDL_RenderClear(renderer);

                // Metodo per rappresentare la funzione sul piano cartesiano
                drawLine(renderer, coeff_angolare, ordinata_origine);

                // Per mostrare a schermo il contenuto del renderer
                SDL_RenderPresent(renderer);
            }
            break;

        case 2:
            // Codice per la stampa della parabola

            // Condizione ciclo
            running = 1;

            // Questo ciclo serve a mostrare a schermo il risultato della funzione 'parabola'
            while (running) {
                // Ciclo che rimane in ascolto di possibili eventi da dover eseguire in base alla condizione associata
                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        printf("Chiusura del programma \n");
                        running = 0;
                    }
                }

                // Imposto il colore di sfondo
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

                // Pulire il renderer
                SDL_RenderClear(renderer);

                // Metodo per rappresentare la funzione sul piano cartesiano
                drawParabola(renderer);

                // Per mostrare a schermo il contenuto del renderer
                SDL_RenderPresent(renderer);
            }
            break;

        default:
            printf("Scelta sbagliata, riprovare! \n");
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
