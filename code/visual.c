#include "raylib.h"
#include "estruturas.h"

void DesenharTabuleiro(){

    int lado = SH * 0.8;

    int tamanho_quadrado = lado / 8;

    Vector2 inicio = {(SW - lado) / 2, (SH - lado) / 2};

    Color branco = RAYWHITE;
    Color preto = (Color){100, 100, 100, 255};

    Vector2 mouse = GetMousePosition();

    for(int linha = 0; linha < 8; linha++){
        for(int coluna = 0; coluna < 8; coluna++){

            Color cor = ((linha + coluna) % 2 == 0) ? branco : preto;

            Rectangle quadrado = (Rectangle){inicio.x + tamanho_quadrado * coluna, inicio.y + tamanho_quadrado * linha, tamanho_quadrado, tamanho_quadrado};

            DrawRectangleRec(quadrado, cor);

            if(CheckCollisionPointRec(mouse, quadrado)){
                DrawRectangleLinesEx(quadrado, tamanho_quadrado * 0.05, RED);
            }
        }
    }
}