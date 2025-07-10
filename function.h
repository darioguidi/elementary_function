// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <string.h>

// Costant
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800
#define OFFSETT_X SCREEN_WIDTH/2
#define OFFSETT_Y SCREEN_HEIGHT/2
#define FOCAL_LENGTH 200.0f
#define SIZE_POINT 3

// Variables

// Struct Point: Serve a rappresentare ideologicamente il pixel nella finestra SDL da dover disegnare
typedef struct Point {
    float x;
    float y;
    // float z;
} Point;

// Functions
// Metodi dedicati alla chiamata della singola funzione

// Metodi per il disegno
void drawPoint(SDL_Renderer *renderer, Point point);
void drawPianoCartesiano(SDL_Renderer *renderer);

// Metodi per il calcolo/rappresentazione dei dati
void drawLine(SDL_Renderer *renderer, float coeff_angolare, float ordinata_origine);