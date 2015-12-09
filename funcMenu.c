#include <stdio.h>
#include <stdlib.h>
#include "funcMenu.h"

void menuInserir(MatrizEsparsa *m) {

    int paramx, paramy, paramvalor;

    do {
        printf("Defina a posicao X na matriz: ");
        scanf("%d", &paramx);
    } while (paramx < 0 || paramx >= m->tamx);

    do {
        printf("Defina a posicao Y na matriz: ");
        scanf("%d", &paramy);
    } while (paramy < 0 || paramy >= m->tamy);

    printf("Defina o valor a ser atribuido na posicao (%2d,%2d): ", paramx, paramy);
    scanf("%d", &paramvalor);

    printf("\n");

    if (inserirValorMatrizEsparsa(m, paramx, paramy, paramvalor) == 0) {
        printf("Nao foi possivel inserir na matriz.\n");
    }
    else {
        printf("Valor inserido com sucesso!\n");
    }

}

void menuDeletar(MatrizEsparsa *m) {

    int paramx, paramy;

    do {
        printf("Defina a posicao X na matriz: ");
        scanf("%d", &paramx);
    } while (paramx < 0 || paramx >= m->tamx);

    do {
        printf("Defina a posicao Y na matriz: ");
        scanf("%d", &paramy);
    } while (paramy < 0 || paramy >= m->tamy);

    printf("\n");

    if (deletarCelula(m, paramx, paramy) == 0) {
        printf("Nao foi possivel deletar a celula.\n");
    }
    else {
        printf("Celula deletada com sucesso!\n");
    }
}

void menuConsultar(MatrizEsparsa *m) {

    int paramx, paramy, retorno;

    do {
        printf("Defina a posicao X na matriz: ");
        scanf("%d", &paramx);
    } while (paramx < 0 || paramx >= m->tamx);

    do {
        printf("Defina a posicao Y na matriz: ");
        scanf("%d", &paramy);
    } while (paramy < 0 || paramy >= m->tamy);

    printf("\n");

    if ((retorno = consultaValorCelulaMatrizEsparsa(m, paramx, paramy)) == -1) {
        printf("Nao foi possivel consultar nessa posicao.\n");
    }
    else {
        printf("Valor na posicao (%2d,%2d) = %d", paramx, paramy, retorno);
    }

}

void menuMostrarMatriz(MatrizEsparsa *m) {

    printf("\n\n");
    printaMatrizEsparsa(m);

}

void menuCalcularLinha(MatrizEsparsa *m) {

    int linha;

    do {
        printf("Defina a linha da matriz: ");
        scanf("%d", &linha);
    } while (linha < 0 || linha >= m->tamy);

    printf("\n");

    printf("Soma dos valores da linha %d: %d\n", linha, somaLinha(m, linha));

}

void menuCalcularColuna(MatrizEsparsa *m) {

    int coluna;

    do {
        printf("Defina a coluna da matriz: ");
        scanf("%d", &coluna);
    } while (coluna < 0 || coluna >= m->tamx);

    printf("\n");

    printf("Soma dos valores da coluna %d: %d\n", coluna, somaColuna(m, coluna));

}

void menuCalcularDeterminante(MatrizEsparsa *m) {

    double det;

    if ((det = calculaDeterminante(m)) == -9999) {

        printf("Matriz nao eh quadrada; impossivel calcular seu determinante.\n");

    }

    else {

        printf("Determinante da matriz eh %8.3f\n", det);

    }

}

void menuLiberarSair(MatrizEsparsa *m) {

    destroiMatrizEsparsa(m);
    printf("Matriz liberada com sucesso!\n");

}
