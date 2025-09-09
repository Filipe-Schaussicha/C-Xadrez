#include "raylib.h"
#include "estruturas.h"
#include "logica.h"
#include <stdio.h>
#include <stdbool.h>

void DesenharTabuleiro(){

    int lado = SH * 0.8;

    int tamanho_quadrado = lado / 8;

    Vector2 inicio = {(SW - lado) / 2, (SH - lado) / 2};

    Color branco = RAYWHITE;
    Color preto = PRETO;

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

    int fonte = tamanho_quadrado * 0.5;
    char letras[] = "abcdefgh";
    int letra_y = (SH + lado + tamanho_quadrado - fonte ) / 2;

    for(int i = 0; i < 8; i++){

        int letra_x = (SW - lado) / 2 + tamanho_quadrado * i + (tamanho_quadrado - MeasureText(TextFormat("%c", letras[i]), fonte)) / 2;

        DrawText(TextFormat("%c", letras[i]), letra_x, letra_y ,fonte, BLACK);

        int numero_y = (SH - lado) / 2 + lado - tamanho_quadrado * i - (tamanho_quadrado + fonte) / 2;
        int numero_x = (SW - lado) / 2 - (tamanho_quadrado + MeasureText(TextFormat("%d", i + 1), fonte)) / 2;

        DrawText(TextFormat("%d", i + 1), numero_x, numero_y ,fonte, BLACK);

    }
}

void DesenharPecas(Texture2D **imagens, Peca **tabuleiro){

    int lado_tabuleiro = SH * 0.8;
    int lado_quadrado = lado_tabuleiro / 8;

    Vector2 inicio = {(SW - lado_tabuleiro) / 2, (SH - lado_tabuleiro) / 2};

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){

            TipoPeca tipo = tabuleiro[i][j].tipo;

            if(tipo != NULA){

                int cor = (compara_cores(tabuleiro[i][j].cor, PRETO)) ? 1 : 0;

                float escala = (float)lado_quadrado / imagens[cor][tipo].height;

                DrawTextureEx(imagens[cor][tipo], (Vector2){inicio.x + lado_quadrado * j, inicio.y + lado_quadrado * i}, 0.0, escala, WHITE);

            }
        }
    }
}