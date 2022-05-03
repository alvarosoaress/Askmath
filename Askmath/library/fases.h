#include<allegro.h>
#include<windows.h>
#include<locale.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>
#include <winalleg.h> //SALVA VIDAS <3

#include "playerStatus.h"
#include "utilityFunc.h"
#include "playerFunc.h"



#ifndef _fasesH_
#define _fasesH_

//VAR GLOBAIS
int coracao = 3;


float delay;
FONT *firasans_16;
FONT *chalk;

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int l=0,c=0; // l = linha / c = coluna -> jogoFase[l][c];

const int x = 0;

int jogoFase[5][5] = { 00, 01, 02, 03, 04,    //   11, 21, 31, 41, 51,
                        x,  11, 12, 13, 14,   //    x, 22, 32, 42, 52,
                        x,  x,  22, 23, 24,   //    x,  x, 33, 43, 53,
                        x,  x,  x,  33, 34,   //    x,  x,  x, 44, 54,
                        x,  x,  x,  x,  44 }; //    x,  x,  x,  x, 55, 
                  
                        
 /*Um total de 15 fases e 5 mundos (1 mundo - 1 fase) (2 mundo - 2 fases) (3 mundo - 3 fases)
(4 mundo - 4 fases) (5 mundo - 5 fases) */
 
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 int fase00(BITMAP *buffer){

int x = 0, y = 0, i;
    
    BITMAP* fundo = load_bitmap("assets/telas/00/tutorial.bmp", NULL);
	BITMAP* hover = load_bitmap("assets/telas/askmathHOVERPERGUNTAS.bmp", NULL);
	firasans_16 = load_font("library/firasans16.pcx", NULL, NULL);
	
		while(!key[KEY_ESC])
	{
		clear(buffer);
		delay = timer;
		draw_sprite(buffer, fundo, 0, 0);//desenhando tela menu principal no buffer

        //OPÇÃO 1
		if(mouse_x > 190 && mouse_x <= 535 && //quando o mouser der hover aqui
		mouse_y > 430 && mouse_y <= 530){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 185, 427);
		}

        //OPÇÃO 2
        if(mouse_x > 740 && mouse_x <= 1085 && //quando o mouser der hover aqui
		mouse_y > 430 && mouse_y <= 530){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 730, 427);
		}

        //OPÇÃO 2
        if(mouse_x > 740 && mouse_x <= 1085 && //quando o mouser der hover aqui
		mouse_y > 430 && mouse_y <= 530){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 730, 427);
		}
		
        mouse(buffer);//importando a fun��o mouse em baixo de tela para ele sobrepor a tela do menu principal
		
		draw_sprite(screen, buffer, 0,0);//desenhando o buffer na screen
		
		while(timer == delay){}
		clear(buffer);
		if (key[KEY_W]){
			return (1);
		}
		
}
	destroy_bitmap(fundo);
	destroy_bitmap(hover);
	destroy_font(firasans_16);

}

 void escolhaFase (int l, int c){ //FASE = L  \\  MUNDO = C
BITMAP* buffer = create_bitmap(1280,720); //declarando buffer dentro do escopo do escolhaFase
switch (jogoFase[l][c]){

    case 0:
        coracao = 3;
        fase00(buffer);
        break;
    
     /*case 1:
        int fase21(BITMAP *buffer);
        break;*/

/*    case 11:
        fase22();
        break;

    case 2:
        fase31();
        break;

    case 12:
        fase32();
        break;

    case 22:
        fase33();
        break;

    case 3:
        fase41();
        break;
    
    case 13:
        fase42();
        break;

    case 23:
        fase43();
        break;

    case 33:
        fase44();
        break;

    case 4:
        fase51();
        break;

    case 14:
        fase52();
        break;
        
    case 24:
        fase53();
        break;

    case 34:
        fase54();
        break;

    case 44:
        fase55();
        break; */

}
} 





#endif