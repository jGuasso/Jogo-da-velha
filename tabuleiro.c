#include <stdio.h>
#include "minimax.h"
#include "tabuleiro.h"

void mapa()
{
    printf("\n\t 7 | 8 | 9 ");
    printf("\n\t-----------");
    printf("\n\t 4 | 5 | 6 ");
    printf("\n\t-----------");
    printf("\n\t 1 | 2 | 3 ");
    return;
}

void tabuleiro(char jogo[3][3])
{

    char bola[5][7]={
        {" ____ "},
        {"/  _ \\"},
        {"| / \\|"},
        {"| \\_/|"},
        {"\\____/"}
    };


    char xis[5][7]={
        {"___  _"},
        {"\\  \\//"},
        {" \\  / "},
        {" /  \\ "},
        {"/__/\\\\"}};

    char vazio[5][7]={
        {"      "},
        {"      "},
        {"      "},
        {"      "},
        {"      "}};
    printf("\n");
    for(int i=0; i<3;i++){
        printf("\t             |             |\n");
        for(int j=0; j<5; j++){
            printf("\t   ");
            switch(jogo[i][0]){
                case 'o':
                    printf("%s",bola[j]);
                    break;
                case 'x':
                    printf("%s",xis[j]);
                    break;
                default:
                    printf("%s",vazio[j]);
                    break;
            }
            printf("    |   ");
            switch(jogo[i][1]){
                case 'o':
                    printf("%s",bola[j]);
                    break;
                case 'x':
                    printf("%s",xis[j]);
                    break;
                default:
                    printf("%s",vazio[j]);
                    break;
            }
            printf("    |   ");
            switch(jogo[i][2]){
                case 'o':
                    printf("%s\n",bola[j]);
                    break;
                case 'x':
                    printf("%s\n",xis[j]);
                    break;
                default:
                    printf("%s\n",vazio[j]);
                    break;
            }
        }
        printf("\t             |             |\n");
        if(i<2){
        printf("\t_____________|_____________|_____________\n");
        }
        else
        {
        printf("\t             |             |\n");
        }
        

    }

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