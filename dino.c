#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

//Variáveis globais
int t,vel=40;

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void delay(int timems){
	long pause;
	clock_t now, then;

	pause= timems*(CLOCKS_PER_SEC/1000);
	now= then = clock();
	while((now-then) < pause){
		now= clock();
	}
}

void iniciar(){
    system("cls");
    gotoxy(10,2);
    printf("Aperte X para sair, Aperte W para Pular");
    gotoxy(62,2);
    printf("SCORE : ");
    gotoxy(1,25);
    for(int x=0;x<79;x++){
    	printf("_");
    }
}

void dino(int pulo)
{
    static int a=1;
 
    if(pulo==0){
        t=0;
    }
    else if(pulo==2){
        t--;
    }
    else{
    	t++;
    } 
    gotoxy(2,14-t);
    printf("                  ");
    gotoxy(2,15-t);
    printf("           0    0 ");
    gotoxy(2,16-t);
    printf("         ########");
    gotoxy(2,17-t);
    printf("         ########");
    gotoxy(2,18-t);
    printf("         ########");
    gotoxy(2,19-t);
    printf(" #      ######## ");
    gotoxy(2,20-t);
    printf(" ###  ########## ");
    gotoxy(2,21-t);
    printf(" ############  # ");
    gotoxy(2,22-t);
    printf("   #########     ");
    gotoxy(2,23-t);
    // código necessário para a movimentação das pernas
    //Posição das pernas no ar
    if(pulo==1 || pulo==2){
	    printf("    ### ##       ");
	    gotoxy(2,24-t);
	    printf("    ##   ##      ");

	//Alternança da posição das pernas ao correr
    }else if(a==1){
	    printf("    ####  ###    ");
	    gotoxy(2,24-t);
	    printf("      ##         ");
	    a=2;
    }else if(a==2){
	    printf("     ### ##      ");
	    gotoxy(2,24-t);
	    printf("          ##     ");
	    a=1;
    }
    gotoxy(2,25-t);

    //Se não estiver no chão, imprime vazio logo abaixo do dino
    if(pulo !=0){
        printf("                ");
    }
    else
    {
        //      ßßßßßßßßßßßßßßßßß
        printf("_________________");
    }
    delay(vel);
}

char manip_object()
{
    static int x=0, scr=0;
    char continuar = ' ';

    //Impressão de fim de jogo
    if(x==63 && t<4)
    {
	    scr=0;
	    vel=40;
	    gotoxy(31,8);
	    printf("FIM DE JOGO");
	    gotoxy(10,9);
	    printf("Aperte W para recomecar ou X para retornar ao menu");
	    continuar = getch();

	    //Reiniciando o jogo
	    x = 0;
	    gotoxy(19,20);
	    printf("        ");
	    gotoxy(19,21);
	    printf("        ");
	    gotoxy(19,22);
	    printf("        ");
	    gotoxy(19,23);
	    printf("        ");
	    gotoxy(19,24);
	    printf("        ");
	    gotoxy(70,2);
	    printf("      ");
	    gotoxy(31,8);
	    printf("           ");
	    gotoxy(10,9);
	    printf("                                                  ");

	    if(continuar != 'w' || continuar != 'W'){
	    	return continuar;
	    }
    }
    gotoxy(74-x,20);
    printf("|----");
    gotoxy(74-x,21);
    printf("|----");
    gotoxy(74-x,22);
    printf("|----");
    gotoxy(74-x,23);
    printf("|----");
    gotoxy(74-x,24);
    printf("|----" );
    x++;
    if(x==73)
    {
	    x=0;
	    scr++;
	    gotoxy(70,2);
	    printf("     ");
	    gotoxy(70,2);
	    printf("%d",scr);
	    if(vel>20){
	        vel--;
	    }
	}
	return continuar;
}

char menu(){
	system("cls");
	
	//Escrevendo "DINO" na tela
	gotoxy(33,10);
	printf("###  # #  # ####");
	gotoxy(33,11);
	printf("#  # # ## # #  #");
	gotoxy(33,12);
	printf("#  # # # ## #  #");
	gotoxy(33,13);
	printf("###  # #  # ####");

	gotoxy(34,16);
	printf("W PARA INICIAR");
	gotoxy(34,17);
	printf("X PARA SAIR");
	gotoxy(34,18);
	printf("C PARA CREDITOS");

	char opcao = getch();
	return opcao;
}

void creditos(){
	system("cls");

	FILE *f = fopen("creditos.txt","r");
	char c;

	while((c = fgetc(f)) != EOF){
		printf("%c", c);
	}

	fclose(f);

	getch();
}
