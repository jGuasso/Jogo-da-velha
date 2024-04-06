#include <stdio.h>
#include <stdlib.h>

//Projeto de jogo da velha
int main(){
    //Variáveis
    int ganhou = 1,x,y,cont,velha,ok=0;
    char vez = 'x', jogo [3][3]={
        {'0','0','0'},
        {'0','0','0'},
        {'0','0','0'}
    };
    printf("\tJogo da Velha");
   while(ganhou != 0){
        printf("\n\n\tMapa\n\n");
        printf("0 0|0 1|0 2\n");
        printf("1 0|1 1|1 2\n");
        printf("2 0|2 1|2 2\n\n");
        //montar o tabuleiro
        printf("\nVez de %c", vez);
        printf("\n\t%c|%c|%c",jogo[0][0],jogo[0][1],jogo[0][2]);//0|0|0
        printf("\n\t%c|%c|%c",jogo[1][0],jogo[1][1],jogo[1][2]);//0|0|0
        printf("\n\t%c|%c|%c",jogo[2][0],jogo[2][1],jogo[2][2]);//0|0|0

        //Pegar coordenadas

        do{
            printf("\n\nDigite as coordenadas:");
            scanf("%d%d",&x,&y);
            //Verifica se a entrada é válida
            if(jogo[x][y]!='0'){
                printf("\n\nEntrada Invalida, a posicao ja foi escolhida, tente novamente\n");
                ok = 1;
            }else if(x>2||x<0||y>2||y<0){
                printf("\n\nEntrada invalida, os valores nao sao validos");
                ok = 1;
            }else{
                ok = 0;
            }
        }while(ok != 0);

        //Substitui os valores na tabela
        jogo[x][y]=vez;

        //verifica se ganhou
        cont = 0;
        while(cont!=3){
            if(jogo[cont][0] == jogo[cont][1] && jogo[cont][1] == jogo[cont][2] && jogo[cont][0]!= '0'){//Horizontal
                printf("\n\n\tO %c GANHOUUU\nParabens!!\n", vez);
                ganhou = 0;
            }else if(jogo[0][cont] == jogo[1][cont] && jogo[1][cont] == jogo[2][cont] && jogo[0][cont]!= '0'){//Vertical
                printf("\n\n\tO %c GANHOUUU\nParabens!!\n", vez);
                ganhou = 0;
            }else if(jogo[0][0] == jogo[1][1] && jogo[1][1] == jogo[2][2] && jogo[1][1] != '0'){//Diagonal principal
                printf("\n\n\tO %c GANHOUUU\nParabens!!\n", vez);
                ganhou = 0;
            }else if(jogo[0][2] == jogo[1][1] && jogo[1][1] == jogo[2][0] && jogo[1][1] != '0'){//Diagonal segundária

            }
            cont++;
        }
        //Verifica se deu velha
        velha = 1;
        for(x = 0;x < 3;x++){
            for(y = 0;y < 3;y++){
                if(jogo[x][y]=='0'){
                    velha = 0;
                }
            }
        }
        if(velha == 1){
            printf("\nOps, deu velha, joguem outra!!\n");
            ganhou = 0;
        }
        //Troca o jogador
        if(vez == 'x'){
            vez = 'o';
        }else{
            vez = 'x';}
   }
    printf("\n\t%c|%c|%c",jogo[0][0],jogo[0][1],jogo[0][2]);
    printf("\n\t%c|%c|%c",jogo[1][0],jogo[1][1],jogo[1][2]);
    printf("\n\t%c|%c|%c\n\n",jogo[2][0],jogo[2][1],jogo[2][2]);




    //pausa o programa após a execução
    system("pause");
    return 0;
}
