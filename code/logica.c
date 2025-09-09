#include "raylib.h"
#include "estruturas.h"
#include "logica.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

Peca **iniciar_tabuleiro(){

    // aloca a matriz de peças
    Peca **tabuleiro = malloc(sizeof(Peca*) * 8);

    if(tabuleiro == NULL){
        return NULL;
    }

    for(int i = 0; i < 8; i++){

        tabuleiro[i] = malloc(sizeof(Peca) * 8);

        if(tabuleiro[i] == NULL){
            return NULL;
        }
    }

    // serve de referencia para preencher a primeira e última linha de peças
    TipoPeca disposicao_pecas[]= {
        TORRE, CAVALO, BISPO, DAMA, REI, BISPO, CAVALO, TORRE
    };

    // popula o array
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){

            Color cor;

            if(i < 4){
                cor = PRETO;
            }else{
                cor = WHITE;
            }

            // popula a primeira e útima linha com as pesças do array anterior
            if(i == 0 || i == 7){
                tabuleiro[i][j] = (Peca){disposicao_pecas[j], cor};

            // popula a segunda e penúltima linha com peões 
            }else if(i == 1 || i == 6){
                tabuleiro[i][j] = (Peca){PEAO, cor};

            // popula o resto das linhas com a peça "NULA"
            }else{
                tabuleiro[i][j] = (Peca){NULA, RED};
            }

            // para debug
            printf("Peca[%d][%d]: Tipo %d\n", i, j, tabuleiro[i][j].tipo);
        }
    }

    return tabuleiro;
}

Texture2D **carregar_imagens(){

    // aloca o array
    Texture2D **imagens = malloc(sizeof(Texture2D *) * 2);

    if(imagens == NULL) return NULL;

    for(int i = 0; i < 2; i++){
        imagens[i] = malloc(sizeof(Texture2D) * 6);
        if(imagens[i] == NULL) return NULL;
    }

    // lista dos nomes e cores (ver pasta pieces)
    char *nomes[] = {"pawn", "knight", "bishop", "rook", "queen", "king"};
    char *cores[] = {"white", "black"};
    char caminho[100];
    char cor;

    // Popula o array de Texture2D com as imagens carregadas
    for(int i = 0; i < 2; i++){

        for(int j = 0; j < 6; j++){

            sprintf(caminho, "pieces/%s-%s.png", cores[i], nomes[j]);

            imagens[i][j] = LoadTexture(caminho);
        }
    }

    return imagens;
}

bool compara_cores(Color cor1, Color cor2){

    // verifica se ambas cores são iguais
    if(cor1.r == cor2.r && cor1.g == cor2.g && cor1.b == cor2.b && cor1.a == cor2.a){
        return true;
    }

    return false;
}

