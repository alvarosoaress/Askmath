//Askmath

//Include das bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>
#include<windows.h>
#include "library\importAll.h"

int main(){
	tamanhoTela(800,600);

	//menu();
	menuPrincipal();
	getch();
	return 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void menuPrincipal(void){
	#define MAX 3
	#define MIN 1

	int posicao = 1;
	int keyPressed = 0;
	
	while(keyPressed != 13){
		system("cls");

	switch(posicao){
		case 1:
		system("cls");
		mostrarTela(mpContinuarSeta, 1,5);
		mostrarTela(mpMundo, 3,3);
		mostrarTela(mpSair, 3,3);
		break;

		case 2:
		system("cls");
		mostrarTela(mpContinuar, 3,5);
		mostrarTela(mpMundoSeta, 1,3);
		mostrarTela(mpSair, 3,3);
		break;

		case 3:
		system("cls");
		mostrarTela(mpContinuar, 3,5);
		mostrarTela(mpMundo, 3,3);
		mostrarTela(mpSairSeta, 1,3);
		break;
	}

	keyPressed = getch();
	fflush(stdin);
	
	if(keyPressed == 80 && posicao != MAX){
		posicao++;
	}
	else if(keyPressed == 72 && posicao != MIN){
		posicao--;
	}
	else{
		posicao = posicao;
	}
	
	}
    switch(posicao){
        case 1:
        system("cls");
        printf("\nOLA\n");
        break;

    }
}



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++