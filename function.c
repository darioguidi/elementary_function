#include "function.h"

// Metodo per disegnare un singolo pixel, simulato dalla nostra struct Point
void drawPoint(SDL_Renderer *renderer, Point point)
{
    // Trasformazione delle coordinate del point
    // int screen_x = (int)((point.x * FOCAL_LENGTH) / point.z) + SCREEN_WIDTH / 2;
    // int screen_y = (int)((-point.y * FOCAL_LENGTH) / point.z) + SCREEN_HEIGHT / 2;

    // Imposta il colore di stampa, gli passi il renderer
    SDL_SetRenderDrawColor(renderer,255,255,255,255);

    // Crea un oggetto rettangolo, gli passiamo le coordinate trasformate del point
    SDL_Rect rect = (SDL_Rect) {point.x, SCREEN_HEIGHT - point.y, SIZE_POINT, SIZE_POINT};
    
    // Stampa del rettangolo
    SDL_RenderFillRect(renderer, &rect);
}

// Metodo per la rappresentazione a schermo dei punti del piano cartesiano
void drawPianoCartesiano(SDL_Renderer *renderer)
{
    // Quanti punti per ciascuna riga
    int totalNumberOfPoints = SCREEN_WIDTH;

    // Puntatore al origine dell'asse delle ordinate
    Point *asse_ordinate = malloc(totalNumberOfPoints*sizeof(Point)); 

    // Puntatore al origine dell'asse delle ascisse
    Point *asse_ascisse = malloc(totalNumberOfPoints*sizeof(Point));

    // Cicli for per popolare i punti di ciascuna asse
    for(int i=0; i<totalNumberOfPoints; i++){
        asse_ordinate[i].x = (float) OFFSETT_X;
        asse_ordinate[i].y = (float) i;

        // Stampa dei punti
        drawPoint(renderer, asse_ordinate[i]);
    }

    for(int j=0; j<totalNumberOfPoints; j++){
        asse_ascisse[j].x = j;
        asse_ascisse[j].y = OFFSETT_Y;

        // Stampa dei punti
        drawPoint(renderer, asse_ascisse[j]);
    }    

    free(asse_ordinate);
    free(asse_ascisse);
}

// Metodo per la rappresentazione della funzone retta - y = mx +q
void drawLine(SDL_Renderer *renderer, float coeff_angolare, float ordinata_origine)
{

    // Disegno del piano cartesiano 
    drawPianoCartesiano(renderer);

    // Definire la quantità di punti che si vogliono utilizzare per rappresentare la retta
    Point *line = malloc(800*sizeof(Point));

    // Valorizzo i punti
    for(int i = 0; i<800;i++){
        line[i].x = i;
        line[i].y = (coeff_angolare*line[i].x) + ordinata_origine;

        // Una volta che il punto è calcolato, si porcede alla sua stampa
        drawPoint(renderer, line[i]);
    }

    // Liberiamo lo spazio di memoria allocato per disegnare la retta
    free(line);
}

// y = x^2
void drawParabola(SDL_Renderer *renderer)
{
    // Disegno del piano cartesiano 
    drawPianoCartesiano(renderer);

    // Numerototale di punti da volere rappresentare
    int totalNumberPoints = 800;

    // Posizione iniziale dal quale iniziare a stampare i valori della funzione
    float center_x = OFFSETT_X;
    float center_y = OFFSETT_Y;

    // Definire la quantità di punti che si vogliono utilizzare per rappresentare la retta
    Point *line = malloc(totalNumberPoints*sizeof(Point));

    // Valorizzo i punti nel quadrante I
    float scale = 0.0f;

    for(int i = 0; i<(totalNumberPoints/2); i++){
        line[i].x = center_x + scale; 
        line[i].y = center_y + (scale*scale);

        scale = scale + 0.07f;

        // Una volta che il punto è calcolato, si porcede alla sua stampa
        drawPoint(renderer, line[i]);
    }

    // Valorizzo i punti nel quadrante I
    scale = 0.0f;

    for(int i = 0; i<(totalNumberPoints/2); i++){
        line[i].x = -(center_x + scale); 
        line[i].y = -(center_y + (scale*scale));
    
        scale = scale + 0.07f;
    
        // Una volta che il punto è calcolato, si porcede alla sua stampa
        drawPoint(renderer, line[i]);
    }

    // Liberiamo lo spazio di memoria allocato per disegnare la retta
    free(line);
}