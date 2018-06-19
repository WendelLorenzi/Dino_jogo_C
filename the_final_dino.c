#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // Usada para o comando Kbhit()
#include <time.h> // Usada para função delay
#include <windows.h> // Usada para função gotoxy
#include "dino.h"


int main(int argc, char const *argv[]){

	//Comando para delimitar o tamahno da tela no prompt de comando
    system("mode con: lines=29 cols=82");
    char ch, continuar;
    int i;
    char opcao = menu();
    while(opcao != 'x' || opcao != 'X'){
	    if(opcao == 'w' || opcao == 'W'){
			iniciar();
			// While infinito, irá ficar verificando o buffer em todas as passagens até a colisão.
			while(1){
	        	while(!kbhit()){
		            dino(0);
		            continuar = manip_object();
		            if(continuar == 'x' || continuar == 'X'){
		            	system("cls");
		            	break;
		            }
	        	}
	        	ch=getch();
	        	if(ch == 'w'){
	        		//Subindo no pulo
	            	for(i=0; i<10; i++){
		            	dino(1);
		            	continuar = manip_object();
		            	if(continuar == 'x' || continuar == 'X'){
		            		system("cls");
		            		break;
		            	}
	            	}
	            	//Descendo no pulo
	            	for(i=0; i<10; i++){
			            dino(2);
			            continuar = manip_object();
			            if(continuar == 'x' || continuar == 'X'){
		            		system("cls");
		            		break;
		            	}
	            	}
	        	}
	        	else if (ch == 'x'){
	            	opcao = menu();
	            	break;
	            }
	    	} 
		} else if(opcao == 'c' || opcao == 'C'){
    		creditos();
    		opcao = menu();
   		} else{
	    	return 0;
	    }
	}
}


