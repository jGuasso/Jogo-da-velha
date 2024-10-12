#include <stdio.h>
#include <stdlib.h>
#include "tabuleiro.h"
#include "verifica.h"
#include "ansi_colors.h"

//menu_cores
void menu_cores(){
    int seletor;

    do
    {
        printf("Escolha a  cor:\n\n");
        printf(TEXT_BLUE BG_CYAN"1 - Jogo assim\n");
        printf(TEXT_RED BG_H_PURPLE"2 - Jogo assim\n");
        printf(TEXT_WHITE BG_BLACK"3 - Jogo assim\n");
        printf(TEXT_YELLOW BG_GREEN"4 - Jogo assim\n");
        printf(TEXT_H_PURPLE BG_RED"5 - Jogo assim\n");
        printf(TEXT_BLACK BG_WHITE"6 - Jogo assim\n");
        printf(TEXT_H_BLUE BG_H_YELLOW"7 - Jogo assim\n");
        printf(TEXT_H_GREEN BG_GREEN"8 - Jogo assim\n");
        printf(TEXT_CYAN BG_H_CYAN"9 - Jogo assim\n");
        printf(RESET);
        scanf("%d",&seletor);
        switch(seletor){
            case 1:
                    printf(TEXT_BLUE BG_CYAN);
                break;
            case 2:
                    printf(TEXT_RED BG_H_PURPLE);
                break;
            case 3:
                    printf(TEXT_WHITE BG_BLACK);
                break;
            case 4:
                    printf(TEXT_YELLOW BG_GREEN);
                break;
            case 5:
                    printf(TEXT_H_PURPLE BG_RED);
                break;
            case 6:
                    printf(TEXT_BLACK BG_WHITE);
                break;
            case 7:
                    printf(TEXT_H_BLUE BG_H_YELLOW);
                break;
            case 8:
                    printf(TEXT_H_GREEN BG_GREEN);
                break;
            case 9:
                    printf(TEXT_CYAN BG_H_CYAN);
                break;
        }
        system("cls");
    } while (seletor<1||seletor>9);
}

void mensagem_ganhador(char vez){
    if (vez == 'o')
    {
        printf("  ____                           _                            _     _    ___    _                                                  _ \n");
        printf(" |  _ \\    __ _   _ __    __ _  | |__     ___   _ __    ___  | |   ( )  / _ \\  ( )   __   __   ___   _ __     ___    ___   _   _  | |\n");
        printf(" | |_) |  / _` | | '__|  / _` | | '_ \\   / _ \\ | '_ \\  / __| | |   |/  | | | | |/    \\ \\ / /  / _ \\ | '_ \\   / __|  / _ \\ | | | | | |\n");
        printf(" |  __/  | (_| | | |    | (_| | | |_) | |  __/ | | | | \\__ \\ |_|       | |_| |        \\ V /  |  __/ | | | | | (__  |  __/ | |_| | |_|\n");
        printf(" |_|      \\__,_| |_|     \\__,_| |_.__/   \\___| |_| |_| |___/ (_)        \\___/          \\_/    \\___| |_| |_|  \\___|  \\___|  \\__,_| (_)\n");

    }
    else
    {
        printf("  ____                           _                            _     _  __  __  _                                                  _ \n");
        printf(" |  _ \\    __ _   _ __    __ _  | |__     ___   _ __    ___  | |   ( ) \\ \\/ / ( )   __   __   ___   _ __     ___    ___   _   _  | |\n");
        printf(" | |_) |  / _` | | '__|  / _` | | '_ \\   / _ \\ | '_ \\  / __| | |   |/   \\  /  |/    \\ \\ / /  / _ \\ | '_ \\   / __|  / _ \\ | | | | | |\n");
        printf(" |  __/  | (_| | | |    | (_| | | |_) | |  __/ | | | | \\__ \\ |_|        /  \\         \\ V /  |  __/ | | | | | (__  |  __/ | |_| | |_|\n");
        printf(" |_|      \\__,_| |_|     \\__,_| |_.__/   \\___| |_| |_| |___/ (_)       /_/\\_\\         \\_/    \\___| |_| |_|  \\___|  \\___|  \\__,_| (_)\n");

    }
    
}

void mensagem_velha(){
    printf("  ____                                    _   _                               \n");
    printf(" |  _ \\    ___   _   _    __   __   ___  | | | |__     __ _     _           _ \n");
    printf(" | | | |  / _ \\ | | | |   \\ \\ / /  / _ \\ | | | '_ \\   / _` |   (_)  _____  (_)\n");
    printf(" | |_| | |  __/ | |_| |    \\ V /  |  __/ | | | | | | | (_| |    _  |_____|  _ \n");
    printf(" |____/   \\___|  \\__,_|     \\_/    \\___| |_| |_| |_|  \\__,_|   ( )         ( )\n");
    printf("                                                               |/          |/ \n");

}

void titulo(){
    printf("   ___  _____  _____  _____  ______   ___    _   _  _____  _      _   _   ___  \n");
    printf("  |_  ||  _  ||  __ \\|  _  | |  _  \\ / _ \\  | | | ||  ___|| |    | | | | / _ \\ \n");
    printf("    | || | | || |  \\/| | | | | | | |/ /_\\ \\ | | | || |__  | |    | |_| |/ /_\\ \\\n");
    printf("    | || | | || | __ | | | | | | | ||  _  | | | | ||  __| | |    |  _  ||  _  |\n");
    printf("/\\__/ /\\ \\_/ /| |_\\ \\\\ \\_/ / | |/ / | | | | \\ \\_/ /| |___ | |____| | | || | | |\n");
    printf("\\____/  \\___/  \\____/ \\___/  |___/  \\_| |_/  \\___/ \\____/ \\_____/\\_| |_/\\_| |_/\n");

}

//Projeto de jogo da velha
int main()
{

    //Variaveis
    int jogadores, ganhou = 1, x, y, velha, dnv = 0, placar[2] = {0, 0};
    char vez = 'x';
    char jogo[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    //definir a cor do jogo
    titulo();
    menu_cores();

    //N�mero de Jogadores
    do{
        titulo();
        printf("\n\nDigite o numero de jogadores:  (1 ou 2)\n");
        scanf("%d",&jogadores);
    }while(jogadores!=1 && jogadores!=2);
	system("cls");
    while (dnv == 0) {
        titulo();
        printf("\n");
        //Monta o tabuleiro mapeado
        printf("\n\n\tMapa (utiliza o padrao do NumPad)\n\n");
        mapa();
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
            mensagem_ganhador(vez);
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
            mensagem_velha();
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
            printf("\n\t\t   PLACAR\n\t        x[%d] : [%d]o\n\a", placar[0], placar[1]);

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
