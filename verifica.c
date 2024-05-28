#include <stdio.h>
#include "verifica.h"

//Fun��o que verifica quem ganhou
int verifica_ganhador(char jogo[3][3])
{
    int cont;
    for(cont = 0;cont<3;cont++) {
        if (jogo[cont][0] == jogo[cont][1] && jogo[cont][1] == jogo[cont][2] && jogo[cont][0] != ' ') {//Horizontal
            return 0;
        }
        else if (jogo[0][cont] == jogo[1][cont] && jogo[1][cont] == jogo[2][cont] && jogo[0][cont] != ' ') {//Vertical
            return 0;
        }
        else if (jogo[0][0] == jogo[1][1] && jogo[1][1] == jogo[2][2] && jogo[1][1] != ' ') {//Diagonal principal
            return 0;
        }
        else if (jogo[0][2] == jogo[1][1] && jogo[1][1] == jogo[2][0] && jogo[1][1] != ' ') {//Diagonal segundaria
            return 0;
        }
    }
    return 1; // Simulando que o jogo ainda não acabou
}

//Fun��o que pergunta se o jogo deve ser reiniciado
int jogar_dnv()
{
    char cDnv;
    int ver;
    do {
        printf("\nDeseja jogar novamente?(s/n)\n");
        cDnv = getchar();
        getchar(); // Consumir o '\n' pendente
        if (cDnv == 's' || cDnv == 'S') {
            return 0;
        }
        else if (cDnv == 'n' || cDnv == 'N') {
            return 1;
        }
        else {
            ver = 1;
        }
    } while (ver == 1);
    return 1;
}

//Fun��o que verifica se deu velha
int verifica_velha(int ganhou, char jogo[3][3])
{
    int x,y;
    if (ganhou != 0) {
        for (x = 0; x < 3; x++) {
            for (y = 0; y < 3; y++) {
                if (jogo[x][y] == ' ') {
                    return 0;
                }
            }
        }
        return 1;
    }
    return 0; // Simulando que o jogo ainda não acabou
}
