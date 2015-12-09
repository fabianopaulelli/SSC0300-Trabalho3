#include <stdio.h>
#include <stdlib.h>
#include "funcMenu.h"


int main()
{
    MatrizEsparsa *m;

    int escolha = -1;
    int tamx = -1;
    int tamy = -1;

    do {
        printf("Defina o tamanho X da matriz esparsa a ser criada: ");
        scanf("%d", &tamx);
    } while (tamx < 0);

    do {
        printf("Defina o tamanho Y da matriz esparsa a ser criada: ");
        scanf("%d", &tamy);
    } while (tamx < 0);

    m = criaMatrizEsparsa(tamx,tamy);

    printf("\nMatriz Esparsa criada com sucesso!\n");

    do {

        do {

            printf("\n\nEscolha uma opcao:\n\n");

            printf("1) Inserir valor na matriz\n");
            printf("2) Deletar valor na matriz\n");
            printf("3) Consultar valor na matriz\n");
            printf("4) Mostrar a matriz inteira na tela\n");
            printf("5) Calcula soma de valores de uma linha na matriz\n");
            printf("6) Calcula soma de valores de uma coluna na matriz\n");
            printf("7) Calcula o determinante da matriz (apenas matrizes quadradas)\n");
            printf("8) Liberar matriz e sair do programa\n\n");

            printf("Escolha: ");

            scanf("%d", &escolha);

            printf("\n");

        } while (escolha < 0 || escolha > 8);

        switch (escolha) {

            case 1:
                menuInserir(m);
                break;

            case 2:
                menuDeletar(m);
                break;

            case 3:
                menuConsultar(m);
                break;

            case 4:
                menuMostrarMatriz(m);
                break;

            case 5:
                menuCalcularLinha(m);
                break;

            case 6:
                menuCalcularColuna(m);
                break;

            case 7:
                menuCalcularDeterminante(m);
                break;

            case 8:
                menuLiberarSair(m);
                break;

        }

    } while (escolha != 8);

    return 0;
}
