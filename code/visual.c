#include "raylib.h"
#include "estruturas.h"

void DesenharTabuleiro(){

    int lado = SH * 0.8;

    int tamanho_quadrado = lado / 8;

    Vector2 inicio = {(SW - lado) / 2, (SH - lado) / 2};

    Color branco = RAYWHITE;
    Color preto = (Color){100, 100, 100, 255};

    for(int linha = 0; linha < 8; linha++){
        for(int coluna = 0; coluna < 8; coluna++){

            Color cor = ((linha + coluna) % 2 == 0) ? branco : preto;

            int x = inicio.x + tamanho_quadrado * coluna;
            int y = inicio.y + tamanho_quadrado * linha;

            DrawRectangle(x, y, tamanho_quadrado, tamanho_quadrado, cor);
        }
    }

}