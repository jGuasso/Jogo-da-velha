#include <stdio.h>
#include <stdlib.h>

//Projeto de jogo da velha
int main(){
    //Variaveis
    int ganhou = 1, x, y, pos, cont, velha, ok = 0, dnv = 0, placar[2] = {0, 0}, ver = 0;
    char vez = 'x', cDnv, jogo[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    while (dnv == 0) {
        printf("\tJogo da Velha");
        while (ganhou != 0) {
            printf("\n\n\tMapa (utiliza o padrao do Num Lock)\n\n");
            printf(" 7 | 8 | 9 \n");
            printf("-----------\n");
            printf(" 4 | 5 | 6 \n");
            printf("-----------\n");
            printf(" 1 | 2 | 3 \n\n");
            //montar o tabuleiro
            printf("\nVez de %c", vez);
            printf("\n\t %c | %c | %c ", jogo[0][0], jogo[0][1], jogo[0][2]);//0|0|0
            printf("\n\t-----------");                                    //-----
            printf("\n\t %c | %c | %c ", jogo[1][0], jogo[1][1], jogo[1][2]);//0|0|0
            printf("\n\t-----------");                                    //-----
            printf("\n\t %c | %c | %c ", jogo[2][0], jogo[2][1], jogo[2][2]);//0|0|0

            //Pegar a posicao

            do {
                printf("\n\nDigite a posicao:");
                scanf("%d", &pos);
                getchar(); // Limpa o buffer de entrada
                //traduzir a posicao
                switch (pos) {
                case 7:
                    x = 0;
                    y = 0;
                    break;
                case 8:
                    x = 0;
                    y = 1;
                    break;
                case 9:
                    x = 0;
                    y = 2;
                    break;
                case 4:
                    x = 1;
                    y = 0;
                    break;
                case 5:
                    x = 1;
                    y = 1;
                    break;
                case 6:
                    x = 1;
                    y = 2;
                    break;
                case 1:
                    x = 2;
                    y = 0;
                    break;
                case 2:
                    x = 2;
                    y = 1;
                    break;
                case 3:
                    x = 2;
                    y = 2;
                    break;
                default:
                    break;
                }
                //Verifica se a entrada e valida
                if (jogo[x][y] != ' ') {
                    printf("\n\nEntrada Invalida\n");
                    ok = 1;
                }
                else if (pos < 1 || pos > 9) {
                    printf("\n\nEntrada invalida\n");
                    ok = 1;
                }
                else {
                    ok = 0;
                }
            } while (ok != 0);

            //Substitui os valores na tabela
            jogo[x][y] = vez;

            //Limpa o terminal
            system("cls");

            //verifica se ganhou
            cont = 0;
            while (cont != 3) {
                if (jogo[cont][0] == jogo[cont][1] && jogo[cont][1] == jogo[cont][2] && jogo[cont][0] != ' ') {//Horizontal
                    printf("\n\n\tO %c GANHOUUU\nParabens!!\n", vez);
                    ganhou = 0;
                    break;
                }
                else if (jogo[0][cont] == jogo[1][cont] && jogo[1][cont] == jogo[2][cont] && jogo[0][cont] != ' ') {//Vertical
                    printf("\n\n\tO %c GANHOUUU\nParabens!!\n", vez);
                    ganhou = 0;
                    break;
                }
                else if (jogo[0][0] == jogo[1][1] && jogo[1][1] == jogo[2][2] && jogo[1][1] != ' ') {//Diagonal principal
                    printf("\n\n\tO %c GANHOUUU\nParabens!!\n", vez);
                    ganhou = 0;
                    break;
                }
                else if (jogo[0][2] == jogo[1][1] && jogo[1][1] == jogo[2][0] && jogo[1][1] != ' ') {//Diagonal segundaria
                    printf("\n\n\tO %c GANHOUUU\nParabens!!\n", vez);
                    ganhou = 0;
                    break;
                }
                cont++;
            }
            //Muda o placar se ganhou
            if (ganhou == 0 && vez == 'x') {
                placar[0] += 1;
            }
            else if (ganhou == 0 && vez == 'o') {
                placar[1] += 1;
            }
            //Verifica se deu velha
            if (ganhou != 0) {
                velha = 1;
            }
            for (x = 0; x < 3; x++) {
                for (y = 0; y < 3; y++) {
                    if (jogo[x][y] == ' ') {
                        velha = 0;
                    }
                }
            }
            if (velha == 1) {
                printf("\nOps, deu velha, joguem outra!!\n");
                ganhou = 0;
            }
            //Troca o jogador
            if (vez == 'x') {
                vez = 'o';
            }
            else {
                vez = 'x';
            }
        }
        //Exibe o placar
        printf("\n\t   PLACAR\n        x[%d] : [%d]o\n", placar[0], placar[1]);

        //Mostra o Tabuleiro no  final
        printf("\n\t %c | %c | %c ", jogo[0][0], jogo[0][1], jogo[0][2]);
        printf("\n\t-----------");
        printf("\n\t %c | %c | %c ", jogo[1][0], jogo[1][1], jogo[1][2]);
        printf("\n\t-----------");
        printf("\n\t %c | %c | %c \n\n", jogo[2][0], jogo[2][1], jogo[2][2]);

        //pergunta se querem jogar novamente

        do {
            printf("\nDeseja jogar novamente?(s/n)\n");
            scanf(" %c", &cDnv); // Note o espaço antes de %c para consumir o caractere de nova linha deixado pelo scanf anterior

            if (cDnv == 's' || cDnv == 'S') {
                dnv = 0;
                ver=0;
                ganhou=1;
            }
            else if (cDnv == 'n' || cDnv == 'N') {
                dnv = 1;
                ver=0;
            }
            else {
                ver = 1;
            }

        } while (ver == 1);
        ver = 0;
        system("cls");
        //limpa o tabuleiro;
        for (x = 0; x < 3; x++) {
            for (y = 0; y < 3; y++) {
                jogo[x][y] = ' ';
            }
        }
    }
    return 0;
}
