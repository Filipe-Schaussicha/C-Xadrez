#include "raylib.h"
#include "estruturas.h"
#include "visual.h"
#include "logica.h"
#include <stdlib.h>
#include <stdio.h>

int main(){

    InitWindow(SW, SH, "C-Xadrez");

    SetTargetFPS(60);

    Peca **tabuleiro = iniciar_tabuleiro();

    Texture2D **imagens = carregar_imagens();

    if(tabuleiro == NULL || imagens == NULL){
        printf("ERRO de alocação\n");
        return 1;
    }

    while(!WindowShouldClose()){

        BeginDrawing();

        ClearBackground((Color){222, 184, 135, 1});

        DesenharTabuleiro();

        DesenharPecas(imagens, tabuleiro);

        EndDrawing();
    }


    for(int i = 0; i < 8; i++){
        free(tabuleiro[i]);
    }

    
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 6; j++){
            UnloadTexture(imagens[i][j]);
        }
        free(imagens[i]);
    }

    free(imagens);
    free(tabuleiro);

    CloseWindow();
}