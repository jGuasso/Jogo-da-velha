#include <stdio.h>
#include <time.h>
#include <stdlib.h>
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
    int i,j;
    char linha[3],letra='o';
    /**Ganhar**//**N�o perder**/
    /* horizontal*/
    while(letra!='a'){
        for(i=0;i<=2;i++){
            linha[0]=' ';
            linha[1]=letra;
            linha[2]=letra;
            for(j=0;j<=2;j++){
                if(jogo[i][0]==linha[0] && jogo[i][1]==linha[1] && jogo[i][2]==linha[2]){
                    *y=j;
                    *x=i;
                    return;
                }
                linha[2]=linha[1];
                linha[1]=linha[0];
                linha[0]=letra;
            }
        }
        /* vertical*/
        for(i=0;i<=2;i++){
            linha[0]=' ';
            linha[1]=letra;
            linha[2]=letra;
            for(j=0;j<=2;j++){
                if(jogo[0][i]==linha[0] && jogo[1][i]==linha[1] && jogo[2][i]==linha[2]){
                    *y=i;
                    *x=j;
                    return;
                }
                linha[2]=linha[1];
                linha[1]=linha[0];
                linha[0]=letra;
            }
        }
        /* diagonal'\'*/
        linha[0]=' ';
        linha[1]=letra;
        linha[2]=letra;
        for(j=0;j<=2;j++){
            if(jogo[0][0]==linha[0] && jogo[1][1]==linha[1] && jogo[2][2]==linha[2]){
                *x=j;
                *y=j;
                return;
            }
            linha[2]=linha[1];
            linha[1]=linha[0];
            linha[0]=letra;
        }
        /* diagonal'/'*/
        linha[0]=' ';
        linha[1]=letra;
        linha[2]=letra;
        for(j=0;j<=2;j++){
            if(jogo[0][2]==linha[0] && jogo[1][1]==linha[1] && jogo[2][0]==linha[2]){
                *x=j;
                *y=2-j;
                return;
            }
            linha[2]=linha[1];
            linha[1]=linha[0];
            linha[0]=letra;
        }
        if(letra=='o'){
            letra='x';
        }else{
            letra='a';
        }
    }
    /**Ponto Futuro**/

    /**Ponto Aleat�rio**/
    srand(time(NULL));
    int pos,ok=0;
    do{
        pos=rand()%10;
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
    //Verifica se a entrada e valida
            if (jogo[*x][*y] != ' ') {
                printf("\n\nEntrada Invalida\n");
                ok = 1;
            }
            else if (pos < 1 || pos > 9) {
                ok = 1;
            }
            else {
                ok = 0;
            }
    } while (ok != 0);
}