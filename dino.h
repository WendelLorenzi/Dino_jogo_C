#include <conio.h>
#include <time.h>
#include <windows.h>

//Função que posiciona o cursor na tela
//Passa primeiro a coluna e depois a linha
void gotoxy(int x, int y);

void delay(int timems);

//Função que inicia o jogo editando a tela
void iniciar();

// Função responsavel pela criação e movimentação do dino
void dino(int pulo);

char manip_object();

//Menu do jogo
char menu();

void creditos();


