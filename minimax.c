#include "minimax.h"
#include "verifica.h"

int minimax(char jogo[3][3],char vez){

    int k,i,j,possiveis[9],count=0,x,y,pontos[9] = {0,0,0,0,0,0,0,0,0};
    char copiajogo[3][3];
    if(!(verifica_ganhador(jogo))){
        if (vez=='x')
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    if (verifica_velha(1,jogo))
    {
            return 0;
    }
    if (vez == 'x') {
                vez = 'o';
            }
            else {
                vez = 'x';
            }
    for ( i = 0; i < 9; i++){
    
        switch (i){
            case 7: x = 0; y = 0; break;
            case 8: x = 0; y = 1; break;
            case 9: x = 0; y = 2; break;
            case 4: x = 1; y = 0; break;
            case 5: x = 1; y = 1; break;
            case 6: x = 1; y = 2; break;
            case 1: x = 2; y = 0; break;
            case 2: x = 2; y = 1; break;
            case 3: x = 2; y = 2; break;
            default: break;
        }
        if (jogo[x][y]==' ')
        {
            possiveis[count]=i;
            count++;
        }
        
    }
    for ( k = 0; k < 3; k++)
    {
        for (j = 0; j < 3; j++)
        {
            copiajogo[i][j]=jogo[i][j];
        }
        
    }
    
    for ( i = 0; i < count; i++)
    {
            for ( k = 0; k < 3; k++)
        {
                 for (j = 0; j < 3; j++)
                {
                    copiajogo[i][j]=jogo[i][j];
                }
        
    }
        switch (possiveis[i]){
            case 7: x = 0; y = 0; break;
            case 8: x = 0; y = 1; break;
            case 9: x = 0; y = 2; break;
            case 4: x = 1; y = 0; break;
            case 5: x = 1; y = 1; break;
            case 6: x = 1; y = 2; break;
            case 1: x = 2; y = 0; break;
            case 2: x = 2; y = 1; break;
            case 3: x = 2; y = 2; break;
            default: break;
        }
        copiajogo[x][y]=vez;
        pontos[possiveis[i]]+= minimax(copiajogo,vez);
    }
    int maiorponto=-9000,maior;
    for ( i = 0; i < count; i++)
    {
        if (pontos[possiveis[i]]>maiorponto)
        {
            maiorponto = pontos[possiveis[i]]>maiorponto;
            maior = possiveis[i];
        }
        
    }
    return maior;
    
}   