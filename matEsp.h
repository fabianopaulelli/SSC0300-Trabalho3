#ifndef MATESP_H
#define MATESP_H

typedef struct celula {

    int valor;
    int x,y;
    struct celula *prox_linha;
    struct celula *prox_coluna;

} Celula;

typedef struct matesparsa {
    Celula *ini;
    int tamx, tamy;
} MatrizEsparsa;

MatrizEsparsa* criaMatrizEsparsa(int tam_x, int tam_y);
Celula *verificaPosicaoNaMatrizEsparsa(MatrizEsparsa *m, int x, int y);
int inserirValorMatrizEsparsa(MatrizEsparsa *m, int x, int y, int valor);
void printaMatrizEsparsa(MatrizEsparsa *m);
int deletarCelula(MatrizEsparsa *m, int x, int y);
void destroiMatrizEsparsa(MatrizEsparsa *m);
int consultaValorCelulaMatrizEsparsa(MatrizEsparsa *m, int x, int y);
int somaLinha(MatrizEsparsa *m, int linha);
int somaColuna(MatrizEsparsa *m, int coluna);
double calculaDeterminante(MatrizEsparsa *m);

#endif
