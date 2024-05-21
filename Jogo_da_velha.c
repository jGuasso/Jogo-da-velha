#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

//Fun��o que verifica quem ganhou
int verifica_ganhador(char jogo[3][3], char vez)
{
    int cont;
    for(cont = 0;cont<3;cont++) {
        if (jogo[cont][0] == jogo[cont][1] && jogo[cont][1] == jogo[cont][2] && jogo[cont][0] != ' ') {//Horizontal
            printf("\n\n\tO %c GANHOUUU\nParabens!!\n", vez);
            return 0;
        }
        else if (jogo[0][cont] == jogo[1][cont] && jogo[1][cont] == jogo[2][cont] && jogo[0][cont] != ' ') {//Vertical
            printf("\n\n\tO %c GANHOUUU\nParabens!!\n", vez);
            return 0;
        }
        else if (jogo[0][0] == jogo[1][1] && jogo[1][1] == jogo[2][2] && jogo[1][1] != ' ') {//Diagonal principal
            printf("\n\n\tO %c GANHOUUU\nParabens!!\n", vez);
            return 0;
        }
        else if (jogo[0][2] == jogo[1][1] && jogo[1][1] == jogo[2][0] && jogo[1][1] != ' ') {//Diagonal segundaria
            printf("\n\n\tO %c GANHOUUU\nParabens!!\n", vez);
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
int verifica_velha(int ganhou, char jogo[3][3]){
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
    }while(jogadores!=1&&jogadores!=2);

    while (dnv == 0) {
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
            ganhou = verifica_ganhador(jogo, vez);

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
