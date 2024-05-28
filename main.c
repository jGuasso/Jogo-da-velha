#include <stdio.h>
#include <stdlib.h>
#include "tabuleiro.h"
#include "minimax.h"//prototipo
#include "verifica.h"

//Projeto de jogo da velha
int main()
{
    //Variaveis
    int jogadores, ganhou = 1, x, y, velha, dnv = 0, placar[2] = {0, 0};
    char vez = 'x';
    char mapa[3][3] = { //sistema do numpad
        {'7', '8', '9'},
        {'4', '5', '6'},
        {'1', '2', '3'}
    };
    char jogo[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    //N�mero de Jogadores
    do{
        printf("Digite o numero de jogadores:  (1 ou 2)\n");
        scanf("%d",&jogadores);
    }while(jogadores!=1 && jogadores!=2);

    while (dnv == 0) {
        system("color 9F");
        printf("\tJogo da Velha");

            //Monta o tabuleiro mapeado
            printf("\n\n\tMapa (utiliza o padrao do NumPad)\n\n");
            tabuleiro(mapa);
            putchar('\n');

            //montar o tabuleiro
            printf("\nVez de %c", vez);
            tabuleiro(jogo);

            //Pegar a posicao
                /*1 Jogador*/
            if(jogadores==1&&vez=='o'){
                posicao_ia(&x,&y,jogo);
            }else{
                posicao(&x,&y,jogo);
            }

            //Substitui os valores na tabela
            jogo[x][y] = vez;

            //Limpa o terminal
            system("cls");

            //verifica se ganhou
            ganhou = verifica_ganhador(jogo);
            if (ganhou == 0){
                printf("\n\n\tO %c GANHOUUU\nParabens!!\n", vez);
            }

            //Muda o placar se ganhou
            if (ganhou == 0 && vez == 'x') {
                placar[0] += 1;
            }
            else if (ganhou == 0 && vez == 'o') {
                placar[1] += 1;
            }
            //Verifica se deu velha
            velha = verifica_velha(ganhou, jogo);

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
        if(ganhou == 0){
            //Exibe o placar
            printf("\n\t   PLACAR\n        x[%d] : [%d]o\n\a", placar[0], placar[1]);

            //Mostra o Tabuleiro no  final
            tabuleiro(jogo);

            //pergunta se querem jogar novamente
            dnv=jogar_dnv();

            system("cls");
            //limpa o tabuleiro;
            for (x = 0; x < 3; x++) {
                for (y = 0; y < 3; y++) {
                    jogo[x][y] = ' ';
                }
            }
        }
    }
    return 0;
}