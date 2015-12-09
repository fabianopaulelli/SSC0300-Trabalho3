#include <stdio.h>
#include <stdlib.h>
#include "matEsp.h"

MatrizEsparsa* criaMatrizEsparsa(int tam_x, int tam_y) {

    MatrizEsparsa *m = (MatrizEsparsa*) malloc(sizeof(MatrizEsparsa));

    if (m == NULL)
        return NULL;

    m->ini = NULL;
    m->tamx = tam_x;
    m->tamy = tam_y;

    int i;

    Celula *p = NULL;

    // adiciona colunas
    for (i=0; i<tam_y+1; i++) {

        Celula *cel = (Celula*) malloc (sizeof(Celula));

        if (cel == NULL)
            return NULL;

        cel->x = -1;
        cel->y = i-1;
        cel->valor = 0;
        cel->prox_linha = NULL;
        cel->prox_coluna = NULL;

        // nenhuma celula
        if (m->ini == NULL) {
            m->ini = cel;
        }
        // apenas uma celula
        else {
            p->prox_coluna = cel;
        }

        p = cel;
    }

    // adiciona linhas
    p = m->ini;

    for (i=1; i<tam_x+1; i++) {

        Celula *cel = (Celula*) malloc (sizeof(Celula));

        if (cel == NULL)
            return NULL;

        cel->x = i-1;
        cel->y = -1;
        cel->valor = 0;
        cel->prox_linha = NULL;
        cel->prox_coluna = NULL;

        p->prox_linha = cel;
        p = cel;

    }

    return m;
}

Celula *verificaPosicaoNaMatrizEsparsa(MatrizEsparsa *m, int x, int y) {

    if (x > m->tamx - 1|| y > m->tamy - 1) {
        return NULL;
    }

    Celula *p = NULL;

    //encontra e coloca p na coluna correta
    for (p = m->ini; p->y != y; p = p->prox_coluna ) {}

    // verifica se existe celula com a posicao x,y pedida
    for (; p != NULL; p = p->prox_linha) {

        if (p->x == x) {
            return p;
        }

        if (p->x > x) {
            return NULL;
        }

    }

    return NULL;

}

int inserirValorMatrizEsparsa(MatrizEsparsa *m, int x, int y, int valor) {

    //o programa nao permite adicionar mais de um valos no mesmo (x,y)
    if (verificaPosicaoNaMatrizEsparsa(m, x, y) != NULL) {
        return 0;
    }

    if (x >= m->tamx || y >= m->tamy || x < 0 || y < 0) {
        return 0;
    }

    Celula *cel = (Celula*) malloc (sizeof(Celula));

    if (cel == NULL)
        return 0;

    cel->x = x;
    cel->y = y;
    cel->valor = valor;
    cel->prox_linha = NULL;
    cel->prox_coluna = NULL;

    Celula *p = NULL;
    Celula *q = NULL;

    //encontra e coloca p na coluna correta
    for (p = m->ini; p->y != y; p = p->prox_coluna ) {}

    // verifica se existe celula com a posicao x,y pedida
    while (p != NULL) {

        if (p->prox_linha == NULL) {

            p->prox_linha = cel;
            break;

        }
        else {

            q = p->prox_linha;

            while (q != NULL && q->x < x) {

                p = q;
                q = q->prox_linha;

            }

            if (q != NULL && q->x > x) {

                p->prox_linha = cel;
                cel->prox_linha = q;
                break;

            }

        }

    }

    q = NULL;

    //encontra e coloca p na linha correta
    for (p = m->ini; p->x != x; p = p->prox_linha ) {}

    // verifica se existe celula com a posicao x,y pedida
    while (p != NULL) {

        if (p->prox_coluna == NULL) {

            p->prox_coluna = cel;
            break;

        }
        else {

            q = p->prox_coluna;

            while (q != NULL && q->y < y) {

                p = q;
                q = q->prox_coluna;

            }

            if (q != NULL && q->y > y) {

                p->prox_coluna = cel;
                cel->prox_coluna = q;
                break;

            }

        }

    }

    return 1;

}

void printaMatrizEsparsa(MatrizEsparsa *m) {

    Celula *p = NULL;
    Celula *q = NULL;

    p = m->ini;

    while (p != NULL) {

        q = p;

        while (q != NULL) {

            printf("(%2d,%2d, %2d) ", q->x, q->y, q->valor);

            q = q->prox_linha;

        }

        printf("\n");

        p = p->prox_coluna;

    }


}

int deletarCelula(MatrizEsparsa *m, int x, int y) {

    Celula *p = NULL;
    Celula *q = NULL;

    if (x < 0 || y < 0) return 0;

    //encontra e coloca p na coluna correta
    for (p = m->ini; p->y != y; p = p->prox_coluna ) {}

    q = p->prox_linha;

    while (q != NULL && q->x < x) {

        p = q;
        q = q->prox_linha;

    }

    if (q != NULL) {

        p->prox_linha = q->prox_linha;

    }


    //encontra e coloca p na linha correta
    for (p = m->ini; p->x != x; p = p->prox_linha ) {}

    q = p->prox_coluna;

    while (q != NULL && q->y < y) {

        p = q;
        q = q->prox_coluna;

    }

    if (q != NULL) {

        p->prox_coluna = q->prox_coluna;

    }

    return 1;

}

void destroiMatrizEsparsa(MatrizEsparsa *m) {

    int i,j;

    for (i=0; i<m->tamx; i++) {

        for (j=0; j<m->tamy; j++) {

            deletarCelula(m,i,j);

        }
    }

    Celula *p = NULL;
    Celula *q = NULL;

    p = m->ini;
    q = p->prox_linha;

    while (p->prox_linha != NULL) {

        while (q->prox_linha != NULL) {

            p = q;
            q = q->prox_linha;

        }

        free(q);

        p->prox_linha = NULL;

        p = m->ini;

    }

    p = m->ini;
    q = p->prox_coluna;

    while (p->prox_coluna != NULL) {

        while (q->prox_coluna != NULL) {

            p = q;
            q = q->prox_coluna;

        }

        free(q);

        p->prox_coluna = NULL;

        p = m->ini;

    }

    free(m->ini);
    free(m);

}

int consultaValorCelulaMatrizEsparsa(MatrizEsparsa *m, int x, int y) {

    if (x > m->tamx - 1|| y > m->tamy - 1) {
        return -1;
    }

    Celula *p = NULL;

    //encontra e coloca p na coluna correta
    for (p = m->ini; p->y != y; p = p->prox_coluna ) {}

    // verifica se existe celula com a posicao x,y pedida
    for (; p != NULL; p = p->prox_linha) {

        if (p->x == x) {
            return p->valor;
        }

        if (p->x > x) {
            return -1;
        }

    }

    return -1;

}

int somaLinha(MatrizEsparsa *m, int linha) {

    if (linha < 0 || linha >= m->tamx)
        return 0;

    int total = 0;

    Celula *p = NULL;

    //encontra e coloca p na linha correta
    for (p = m->ini; p->y != linha; p = p->prox_coluna ) {}

    while (p != NULL) {

        total += p->valor;
        p = p->prox_linha;

    }

    return total;

}

int somaColuna(MatrizEsparsa *m, int coluna) {

    if (coluna < 0 || coluna >= m->tamy)
        return 0;

    int total = 0;

    Celula *p = NULL;

    //encontra e coloca p na coluna correta
    for (p = m->ini; p->x != coluna; p = p->prox_linha ) {}

    while (p != NULL) {

        total += p->valor;
        p = p->prox_coluna;

    }

    return total;

}

double calculaDeterminante(MatrizEsparsa *m) {

    if (m->tamx != m->tamy) {

        return -9999;

    }

    double **matriz;
    Celula *p, *px;
    int i,j,k;
    double temp;
    double factor;
    int counter;

    matriz = (double **) calloc(m->tamx, sizeof(double *));

    for (i = 0; i < m->tamx; i++) {

        matriz[i] = (double *) calloc(m->tamx, sizeof(double));

    }

    p = m->ini->prox_coluna;
    px = p->prox_linha;

    for(i = 0; i < m->tamy && p != NULL; i++) {

        for(j = 0; j < m->tamx && px != NULL; j++) {

            if (px->x == j) {

                matriz[i][j] = (double) px->valor;
                px = px->prox_linha;

            }

        }

        p = p->prox_coluna;

        if (p != NULL ) {

            px = p->prox_linha;

        }

    }

    for (i = 0; i < m->tamx - 1; i++) {

        if (matriz[i][i] == 0) {

            for (k = i; k < m->tamx; k++) {

                if (matriz[k][i] != 0) {

                    for (j = 0; j < m->tamx; j++) {

                        temp = matriz[i][j];
                        matriz[i][j] = matriz[k][j];
                        matriz[k][j] = temp;

                    }

                    k = m->tamx;

                }

            }

            counter++;

        }


        if (matriz[i][i] != 0) {

            for (k = i + 1; k < m->tamx; k++) {

                factor = -1.0 * matriz[k][i] /  matriz[i][i];

                for (j = i; j < m->tamx; j++) {

                    matriz[k][j] = matriz[k][j] + (factor * matriz[i][j]);

                }

            }

        }

    }

    temp = 1.0;

    for (i = 0; i < m->tamx; i++) {

        temp *= matriz[i][i];

    }

    if (counter % 2 != 0) {

        temp = -1.0 * temp;

    }


    for (i=0; i < m->tamx;i++) {

        free (matriz[i]);

    }

    free(matriz);

    return temp;
}
