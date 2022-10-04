#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

char slot[11] = {'0','1','2','3','4','5','6','7','8','9'};
void tabuleiro();
int loop();
int verificarJogo();
int computador();
int main()
{   
    loop();
    getch();
    system("cls");
    int escolha, jogador=2;
    char game, restart;
    srand(time(NULL));
    printf("Deseja jogar sozinho?\n S/N ");
    fflush(stdin);
    scanf("%c",&game);
    game = toupper(game);
    while (game!='S'&&game!='N'){
        system("cls");
        printf("Escolha invalida!\n");
        printf("Deseja jogar sozinho?\n S/N ");
        scanf("%c",&game);
        game = toupper(game);
    }
    do {
        tabuleiro(game);
        (jogador==1) ? (jogador=2) : (jogador=1);
        if (jogador==2 && (game=='S')) {
            printf("Vez do computador!");
            // escolha = (rand()%9)+1;
            escolha = computador();
        } else {
            printf ("Jogador %d, digite a posicao: ",jogador);
            scanf("%d",&escolha);
        }
        while (slot[escolha]=='X'||slot[escolha]=='O'||(escolha>9||escolha<1)){
            system("cls");
            tabuleiro(game);
            if (jogador==2 && (game=='S')) {
                printf("Vez do computador!");
                // escolha = (rand()%9)+1;
                escolha = computador();
            } else {
                printf("Escolha invalida!\n");
                printf ("Jogador %d, digite a posicao: ",jogador);
                scanf("%d",&escolha);
            }
        }
        if (jogador==2 && (game=='S')) {sleep(1);}
        (jogador==1) ? (slot[escolha] = 'X') : (slot[escolha] = 'O');
        if (jogador==2 && (game=='S')) {tabuleiro(game);printf("Vez do computador!");sleep(1);}
        system("cls");
    } while(verificarJogo()==0);
    tabuleiro(game);
    if (verificarJogo()==1){
        if (jogador==2 && (game=='S')){
            printf("O computador venceu!\n\n\n");
        } else {
        printf("O jogador %d venceu!\n\n\n",jogador);
        }
    } else {
        printf("Empate!\n\n\n");
    }
    printf("Deseja jogar novamente?\n S/N ");
    fflush(stdin);
    scanf("%c",&restart);
    restart = toupper(restart);
    while (restart!='S'&&restart!='N'){
        system("cls");
        printf("Escolha invalida!\n");
        printf("Deseja jogar novamente?\n S/N ");
        scanf("%c",&restart);
        restart = toupper(restart);
    }
    if (restart=='S'){
        system("JogoDaVelhaAnimated2.exe");
    }
    return 0;
}

int computador() {
    int i,j;
    for (i=1;i<=7;i=i+3){
        if ((slot[i]==slot[i+1]&&slot[i]=='O') || (slot[i+1]==slot[i+2]&&slot[i+1]=='O') || (slot[i]==slot[i+2]&&slot[i+2]=='O')){
            for (j=i;j<=i+2;j++) {
                if (slot[j]!='X'&&slot[j]!='O'){
                    return j;
                }
            }
        }
    }
    for (i=1;i<=3;i++){
        if ((slot[i]==slot[i+3]&&slot[i]=='O') || (slot[i+3]==slot[i+6]&&slot[i+3]=='O') || (slot[i]==slot[i+6]&&slot[i+6]=='O')){
            for (j=i;j<=i+6;j=j+3) {
                if (slot[j]!='X'&&slot[j]!='O'){
                    return j;
                }
            }
        }
    }
    if ((slot[1]==slot[5]&&slot[1]=='O') || (slot[5]==slot[9]&&slot[5]=='O') || (slot[1]==slot[9]&&slot[9]=='O')){
        for (i=1;i<=9;i=i+4){
            if (slot[i]!='X'&&slot[i]!='O'){
                return i;
            }
        }
    }
    if ((slot[3]==slot[5]&&slot[3]=='O') || (slot[5]==slot[7]&&slot[5]=='O') || (slot[3]==slot[7]&&slot[7]=='O')){
        for (i=3;i<=7;i=i+2){
            if (slot[i]!='X'&&slot[i]!='O'){
                return i;
            }
        }
    }
    for (i=1;i<=7;i=i+3){
        if (slot[i]==slot[i+1] || slot[i+1]==slot[i+2] || slot[i]==slot[i+2]){
            for (j=i;j<=i+2;j++) {
                if (slot[j]!='X'&&slot[j]!='O'){
                    return j;
                }
            }
        }
    }
    for (i=1;i<=3;i++){
        if (slot[i]==slot[i+3] || slot[i+3]==slot[i+6] || slot[i]==slot[i+6]){
            for (j=i;j<=i+6;j=j+3) {
                if (slot[j]!='X'&&slot[j]!='O'){
                    return j;
                }
            }
        }
    }
    if (slot[1]==slot[5] || slot[5]==slot[9] || slot[1]==slot[9]){
        for (i=1;i<=9;i=i+4){
            if (slot[i]!='X'&&slot[i]!='O'){
                return i;
            }
        }
    }
    if (slot[3]==slot[5] || slot[5]==slot[7] || slot[3]==slot[7]){
        for (i=3;i<=7;i=i+2){
            if (slot[i]!='X'&&slot[i]!='O'){
                return i;
            }
        }
    }
    return((rand()%9)+1);
}

int verificarJogo() {
    int i;
    for (i=1;i<=7;i=i+3){
        if (slot[i]==slot[i+1] && slot[i+1]==slot[i+2]){
        return 1;
        }
    }
    for (i=1;i<=3;i++){
        if (slot[i]==slot[i+3] && slot[i+3]==slot[i+6]){
        return 1;
        }
    }
    if (slot[1]==slot[5] && slot[5]==slot[9]){
        return 1;
    }
    if (slot[3]==slot[5] && slot[5]==slot[7]){
        return 1;
    }

    if (slot[1]!='1' && slot[2]!='2' && slot[3]!='3' && slot[4]!='4' &&
    slot[5]!='5' && slot[6]!='6' && slot[7]!='7' && slot[8]!='8' && slot[9]!='9'){
        return -1;
    } else {
        return 0;
    }

}

void tabuleiro(game) {
    system("cls");
    printf ("\n\n       Jogo da Velha\n\n");
    //Mostrar os jogadores
    if (game=='S')
    {
    printf ("Jogador - X   Computador - O \n\n");
    } else {
    printf ("Jogador 1 - X   Jogador 2 - O \n\n");
    }
    //print do tabuleiro
    printf ("          |     |     \n");
    printf ("       %c  |  %c  |  %c  \n",slot[1],slot[2],slot[3]);
    printf ("     _____|_____|_____\n");
    printf ("          |     |     \n");
    printf ("       %c  |  %c  |  %c  \n",slot[4],slot[5],slot[6]);
    printf ("     _____|_____|_____\n");
    printf ("          |     |     \n");
    printf ("       %c  |  %c  |  %c  \n",slot[7],slot[8],slot[9]);
    printf ("          |     |     \n\n");
}

char inicio[11] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
void tab2() {
    system("cls");
    printf ("\n\n       Jogo da Velha\n\n");
    //print do tabuleiro
    printf ("          |     |     \n");
    printf ("       %c  |  %c  |  %c  \n",inicio[1],inicio[2],inicio[3]);
    printf ("     _____|_____|_____\n");
    printf ("          |     |     \n");
    printf ("       %c  |  %c  |  %c  \n",inicio[4],inicio[5],inicio[6]);
    printf ("     _____|_____|_____\n");
    printf ("          |     |     \n");
    printf ("       %c  |  %c  |  %c  \n",inicio[7],inicio[8],inicio[9]);
    printf ("          |     |     \n\n");
    printf ("Precione qualquer tecla para comecar");
    usleep(300000);
    }

int loop() {
    int i, j,l;
    for (l=1;l=l+2;l++){
    for (i=1;i<=7;i=i+3){
        for (j=i;j<=i+2;j++) {
            inicio[j]='X';
        }
        tab2();
        for (j=i;j<=i+2;j++) {
            inicio[j]=' ';
        }
        if (kbhit()) {
        return NULL;
        }
    }
    for (i=1;i<=3;i++){
        for (j=i;j<=i+6;j=j+3) {
            inicio[j]='X';
        }
        tab2();
        for (j=i;j<=i+6;j=j+3) {
            inicio[j]=' ';
        }
        if (kbhit()) {
        return NULL;
        }
    }
    for (i=1;i<=9;i=i+4){
        inicio[i]='X';
    }
    tab2();
    for (i=1;i<=9;i=i+4){
        inicio[i]=' ';
    }
    if (kbhit()) {
    return NULL;
    }
    for (i=3;i<=7;i=i+2){
        inicio[i]='X';
    }
    tab2();
    for (i=3;i<=7;i=i+2){
        inicio[i]=' ';
    }
    if (kbhit()) {
    return NULL;
    }
    }
}