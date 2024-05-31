#include <stdio.h>
#include "minimax.h"
#include "tabuleiro.h"

void tabuleiro(char jogo[3][3])
{
    printf("\n\t %c | %c | %c ", jogo[0][0], jogo[0][1], jogo[0][2]);
    printf("\n\t-----------");
    printf("\n\t %c | %c | %c ", jogo[1][0], jogo[1][1], jogo[1][2]);
    printf("\n\t-----------");
    printf("\n\t %c | %c | %c ", jogo[2][0], jogo[2][1], jogo[2][2]);
    return;
}

void posicao(int *x, int *y, char jogo[3][3])
{
    int pos, ok = 0;
    do {
        printf("\n\nDigite a posicao:");
        scanf("%d", &pos);
        getchar();
        switch (pos) {
            case 7: *x = 0; *y = 0; break;
            case 8: *x = 0; *y = 1; break;
            case 9: *x = 0; *y = 2; break;
            case 4: *x = 1; *y = 0; break;
            case 5: *x = 1; *y = 1; break;
            case 6: *x = 1; *y = 2; break;
            case 1: *x = 2; *y = 0; break;
            case 2: *x = 2; *y = 1; break;
            case 3: *x = 2; *y = 2; break;
            default: break;
        }
        if (jogo[*x][*y] != ' ' || pos < 1 || pos > 9) {
            printf("\n\nEntrada Invalida\n");
            ok = 1;
        }
        else {
            ok = 0;
        }
    } while (ok != 0);
}

//Fun��o posi��o IA
void posicao_ia(int *x, int *y, char jogo[3][3]){
    /**Minimax**/
    int pos;
    pos=melhor_jogada(jogo);
    switch (pos) {
        case 1: *x = 0; *y = 0; break;
        case 2: *x = 0; *y = 1; break;
        case 3: *x = 0; *y = 2; break;
        case 4: *x = 1; *y = 0; break;
        case 5: *x = 1; *y = 1; break;
        case 6: *x = 1; *y = 2; break;
        case 7: *x = 2; *y = 0; break;
        case 8: *x = 2; *y = 1; break;
        case 9: *x = 2; *y = 2; break;
        default: break;
        }
}