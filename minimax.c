#include "minimax.h"
#include "verifica.h"
#include <stdio.h>
//não funciona bem, precisa de adaptações

int melhor_jogada(char jogo[3][3])
{   
    FILE * log;//para mostrar a pontuação
    char str[100];
    log = fopen("log_minimax.txt" , "w");


    int i,j,pontos[3][3];
    char copiajogo[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            copiajogo[i][j] = jogo[i][j];//para não alterar o principal
            pontos[i][j] = -10000000;//para não inteferir no resultado
        }
    }

    int maior,maiorpontos;
    maiorpontos= -10000000;
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            if(jogo[i][j] == ' ')
            {
                copiajogo[i][j] = 'o';
                pontos[i][j] = __minimax__(copiajogo,'o',0);
                copiajogo[i][j] = ' ';

                sprintf(str,"[%d][%d] = %d pontos",i,j,pontos[i][j]);
                fputs(str,log);
            }

            if (pontos[i][j] > maiorpontos)
            {
                maiorpontos = pontos[i][j];
                maior = i*3+j+1;
            }
        }
        
    }
    sprintf(str,"\nmaior = %d",maior);
    fputs(str,log);
    fclose(log);
    return maior;
}

int __minimax__(char jogo[3][3], char vez,int profundidade)
{
    int i, j,pontos=0;
    char copiajogo[3][3];

    if (verifica_ganhador(jogo)==0)
    {      
        if (vez == 'o')
        {
            return 10-profundidade;
        }
        else
        {
            return profundidade-10;
        }
    }
    
    if (verifica_velha(1,jogo)== 1)
    {
        return 0;
    }
    
    if(vez=='o')//troca a vez
    {
        vez='x';
    }
    else
    {
        vez='o';
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++) {
            copiajogo[i][j] = jogo[i][j];
        }
    }

    //ganhar e evitar perder
    char linha[3],letra=vez;
    //Ganhar N�o perder
    // horizontal
    while(letra!='a'){
        for(i=0;i<=2;i++){
            linha[0]=' ';
            linha[1]=letra;
            linha[2]=letra;
            for(j=0;j<=2;j++){
                if(jogo[i][0]==linha[0] && jogo[i][1]==linha[1] && jogo[i][2]==linha[2]){
                    if (vez == letra)
                    {
                        if (vez == 'o')
                        {
                            return 10-profundidade;
                        }
                        else
                        {
                            return profundidade-10;
                        }
                        
                    }
                    else
                    {
                        copiajogo[i][j]=vez;
                        pontos = __minimax__(copiajogo,vez,profundidade+1);
                        return pontos;
                    }
                    
                }
                linha[2]=linha[1];
                linha[1]=linha[0];
                linha[0]=letra;
            }
        }
        // vertical
        for(i=0;i<=2;i++){
            linha[0]=' ';
            linha[1]=letra;
            linha[2]=letra;
            for(j=0;j<=2;j++){
                if(jogo[0][i]==linha[0] && jogo[1][i]==linha[1] && jogo[2][i]==linha[2]){
                    if (vez == letra)
                    {
                        if (vez == 'o')
                        {
                            return 10-profundidade;
                        }
                        else
                        {
                            return profundidade-10;
                        }
                        
                    }
                    else
                    {
                        copiajogo[i][j]=vez;
                        pontos = __minimax__(copiajogo,vez,profundidade+1);
                        return pontos;
                    }
                }
                linha[2]=linha[1];
                linha[1]=linha[0];
                linha[0]=letra;
            }
        }
        // diagonal'\'
        linha[0]=' ';
        linha[1]=letra;
        linha[2]=letra;
        for(j=0;j<=2;j++){
            if(jogo[0][0]==linha[0] && jogo[1][1]==linha[1] && jogo[2][2]==linha[2]){
                if (vez == letra)
                    {
                        if (vez == 'o')
                        {
                            return 10-profundidade;
                        }
                        else
                        {
                            return profundidade-10;
                        }
                        
                    }
                    else
                    {
                        copiajogo[i][j]=vez;
                        pontos = __minimax__(copiajogo,vez,profundidade+1);
                        return pontos;
                    }
            }
            linha[2]=linha[1];
            linha[1]=linha[0];
            linha[0]=letra;
        }
        // diagonal'/'
        linha[0]=' ';
        linha[1]=letra;
        linha[2]=letra;
        for(j=0;j<=2;j++){
            if(jogo[0][2]==linha[0] && jogo[1][1]==linha[1] && jogo[2][0]==linha[2]){
                if (vez == letra)
                    {
                        if (vez == 'o')
                        {
                            return 10-profundidade;
                        }
                        else
                        {
                            return profundidade-10;
                        }
                        
                    }
                    else
                    {
                        copiajogo[i][j]=vez;
                        pontos = __minimax__(copiajogo,vez,profundidade+1);
                        return pontos;
                    }
            }
            linha[2]=linha[1];
            linha[1]=linha[0];
            linha[0]=letra;
        }
        if(letra==vez){
            if (vez == 'o')
            {
                letra = 'x';
            }
            else
            {
                letra = 'o';
            }
            
        }else{
            letra='a';
        }
    }

    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            if(jogo[i][j] == ' ')
            {
                copiajogo[i][j] = vez;
                pontos += __minimax__(copiajogo,vez,profundidade+1);
                copiajogo[i][j] = ' ';
            }
        }
        
    }
    return pontos;
}