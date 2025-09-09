#define SW 1280
#define SH 720

#define PRETO (Color){100, 100, 100, 255}

typedef enum{

    NULA = -1,
    PEAO,
    CAVALO,
    BISPO,
    TORRE,
    DAMA,
    REI

}TipoPeca;

typedef struct{

    TipoPeca tipo;
    Color cor;

}Peca;