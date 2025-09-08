#include "raylib.h"
#include "estruturas.h"
#include "visual.h"

int main(){

    InitWindow(SW, SH, "C-Xadrez");

    SetTargetFPS(60);

    while(!WindowShouldClose()){

        BeginDrawing();

        ClearBackground((Color){222, 184, 135, 1});

        DesenharTabuleiro();

        EndDrawing();
    }

    CloseWindow();

}