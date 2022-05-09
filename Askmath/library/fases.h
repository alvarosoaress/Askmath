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

int tfill = 0;
int timersegundos = 0;//controlador "relogio de segundos"
int r=0, g=255, b=0;

void tempofill () {tfill++;}
void segundos() {timersegundos++;}//controlador "relogio de segundos"
int limiteRect = 0;
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
 // fase = l \\ mundo = c
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 int fase00(BITMAP *buffer){

    int x = 0, y = 0, i;
    r=0, g=255, b=0;
    loadState();
    BITMAP* fundo = load_bitmap("assets/telas/fases/tutorial.bmp", NULL);
	BITMAP* hover = load_bitmap("assets/telas/askmathHOVERPERGUNTAS.bmp", NULL);
	firasans_16 = load_font("library/firasans16.pcx", NULL, NULL);

    tfill = 0;
    limiteRect = 0;

		while(!key[KEY_F10])
	{   
        
		clear(buffer);
		delay = timer;

            if (ps.playerCoracao <= 0){
                ps.playerCoracao = 0;
            }

        if(key[KEY_ESC]) {telaMenuPrincipal(buffer);}

		draw_sprite(buffer, fundo, 0, 0);//desenhando tela menu principal no buffer

        contadorCoracao(buffer); //contador dos corações 

        timerResposta(buffer, 15); //temporizador para resposta 
        

        //OPÇÃO 1
		if(mouse_x > 190 && mouse_x <= 535 && //quando o mouser der hover aqui
		mouse_y > 430 && mouse_y <= 530){//aparece um tra�ado preto aqui
			// hover
		draw_sprite(buffer, hover, 185, 427);
            //click
            if (mouse_b == 1){
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
            }
		}

        //OPÇÃO 2
        if(mouse_x > 740 && mouse_x <= 1085 && //quando o mouser der hover aqui
		mouse_y > 430 && mouse_y <= 530){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 730, 427);
            //click
            if (mouse_b == 1){
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
            }
		}

        //OPÇÃO 3
        if(mouse_x > 190 && mouse_x <= 535 && //quando o mouser der hover aqui
		mouse_y > 575 && mouse_y <= 670){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 185, 573);
            //click
                if (mouse_b == 1){
                    if(ps.playerMundo == 0 && ps.playerFase == 0) ps.playerMundo += 1;
                    saveState();
                    telaAcerto(buffer);
                }
		}

        //OPÇÃO 4
        if(mouse_x > 740 && mouse_x <= 1085 && //quando o mouser der hover aqui
		mouse_y > 575 && mouse_y <= 670){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 730, 585);
            //click
            if (mouse_b == 1){
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
            }
		}
		
        mouse(buffer);//importando a fun��o mouse em baixo de tela para ele sobrepor a tela do menu principal
		
		draw_sprite(screen, buffer, 0,0);//desenhando o buffer na screen
		
		while(timer == delay){}
		clear(buffer);
		
}
	destroy_bitmap(fundo);
	destroy_bitmap(hover);
	destroy_font(firasans_16);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int fase01(BITMAP *buffer){

    int x = 0, y = 0, i;
    r=0, g=255, b=0;
    loadState();
    BITMAP* fundo = load_bitmap("assets/telas/fases/adicao01.bmp", NULL);
	BITMAP* hover = load_bitmap("assets/telas/askmathHOVERPERGUNTAS.bmp", NULL);
	firasans_16 = load_font("library/firasans16.pcx", NULL, NULL);

    tfill = 0;
    limiteRect = 0;

		while(!key[KEY_F10])
	{
        
		clear(buffer);
		delay = timer;
            if (ps.playerCoracao <= 0){
                ps.playerCoracao = 0;
            }
        if(key[KEY_ESC]) {telaMenuPrincipal(buffer);}

		draw_sprite(buffer, fundo, 0, 0);//desenhando tela menu principal no buffer

        contadorCoracao(buffer); //contador dos corações 

        timerResposta(buffer, 15); //temporizador para resposta 


        //OPÇÃO 1
		if(mouse_x > 190 && mouse_x <= 535 && //quando o mouser der hover aqui
		mouse_y > 430 && mouse_y <= 530){//aparece um tra�ado preto aqui
			// hover
		draw_sprite(buffer, hover, 185, 427);
            //click
            if (mouse_b == 1){
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
            }
		}

        //OPÇÃO 2
        if(mouse_x > 740 && mouse_x <= 1085 && //quando o mouser der hover aqui
		mouse_y > 430 && mouse_y <= 530){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 730, 427);
            //click
            if (mouse_b == 1){ //!COLOCAR AUMENTO DE PS.PLAYERMUNDO E PS.PLAYERFASE
                if(ps.playerFase == 0 && ps.playerMundo == 1 ) ps.playerFase += 1;
                saveState();
                telaAcerto(buffer);
            }
		}

        //OPÇÃO 3
        if(mouse_x > 190 && mouse_x <= 535 && //quando o mouser der hover aqui
		mouse_y > 575 && mouse_y <= 670){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 185, 573);
            //click
                if (mouse_b == 1){ 
                    ps.playerCoracao -= 1;
                    saveState();
                    rest(250);
                }
		}

        //OPÇÃO 4
        if(mouse_x > 740 && mouse_x <= 1085 && //quando o mouser der hover aqui
		mouse_y > 575 && mouse_y <= 670){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 730, 585);
            //click
            if (mouse_b == 1){
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
            }
		}
		
        mouse(buffer);//importando a fun��o mouse em baixo de tela para ele sobrepor a tela do menu principal
		
		draw_sprite(screen, buffer, 0,0);//desenhando o buffer na screen
		
		while(timer == delay){}
		clear(buffer);
		
}
	destroy_bitmap(fundo);
	destroy_bitmap(hover);
	destroy_font(firasans_16);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int fase11(BITMAP *buffer){

    int x = 0, y = 0, i;
    r=0, g=255, b=0;
    loadState();
    BITMAP* fundo = load_bitmap("assets/telas/fases/adicao11.bmp", NULL);
	BITMAP* hover = load_bitmap("assets/telas/askmathHOVERPERGUNTAS.bmp", NULL);
	firasans_16 = load_font("library/firasans16.pcx", NULL, NULL);

    tfill = 0;
    limiteRect = 0;

		while(!key[KEY_F10])
	{
        
		clear(buffer);
		delay = timer;
            if (ps.playerCoracao <= 0){
                ps.playerCoracao = 0;
            }
        if(key[KEY_ESC]) {telaMenuPrincipal(buffer);}

		draw_sprite(buffer, fundo, 0, 0);//desenhando tela menu principal no buffer

        contadorCoracao(buffer); //contador dos corações 

        timerResposta(buffer, 15); //temporizador para resposta 


        //OPÇÃO 1
		if(mouse_x > 190 && mouse_x <= 535 && //quando o mouser der hover aqui
		mouse_y > 430 && mouse_y <= 530){//aparece um tra�ado preto aqui
			// hover
		draw_sprite(buffer, hover, 185, 427);
            //click
            if (mouse_b == 1){
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
            }
		}

        //OPÇÃO 2
        if(mouse_x > 740 && mouse_x <= 1085 && //quando o mouser der hover aqui
		mouse_y > 430 && mouse_y <= 530){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 730, 427);
            //click
                if (mouse_b == 1){ 
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
                }
		}

        //OPÇÃO 3
        if(mouse_x > 190 && mouse_x <= 535 && //quando o mouser der hover aqui
		mouse_y > 575 && mouse_y <= 670){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 185, 573);
            //click
            if (mouse_b == 1){ //!COLOCAR AUMENTO DE PS.PLAYERMUNDO E PS.PLAYERFASE
            if(ps.playerFase == 1 && ps.playerMundo == 1 ) ps.playerMundo += 1; ps.playerFase = 0;
            saveState();
            telaAcerto(buffer);
            }
		}

        //OPÇÃO 4
        if(mouse_x > 740 && mouse_x <= 1085 && //quando o mouser der hover aqui
		mouse_y > 575 && mouse_y <= 670){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 730, 585);
            //click
            if (mouse_b == 1){
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
            }
		}
		
        mouse(buffer);//importando a fun��o mouse em baixo de tela para ele sobrepor a tela do menu principal
		
		draw_sprite(screen, buffer, 0,0);//desenhando o buffer na screen
		
		while(timer == delay){}
		clear(buffer);
		
}
	destroy_bitmap(fundo);
	destroy_bitmap(hover);
	destroy_font(firasans_16);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int fase02(BITMAP *buffer){

    int x = 0, y = 0, i;
    r=0, g=255, b=0;
    loadState();
    BITMAP* fundo = load_bitmap("assets/telas/fases/subtracao02.bmp", NULL);
	BITMAP* hover = load_bitmap("assets/telas/askmathHOVERPERGUNTAS.bmp", NULL);
	firasans_16 = load_font("library/firasans16.pcx", NULL, NULL);

    tfill = 0;
    limiteRect = 0;

		while(!key[KEY_ESC])
	{
		clear(buffer);
		delay = timer;

        if(key[KEY_ESC]) {telaMenuPrincipal(buffer);}

		draw_sprite(buffer, fundo, 0, 0);//desenhando tela menu principal no buffer

        contadorCoracao(buffer); //contador dos corações 

        timerResposta(buffer, 15); //temporizador para resposta 


        //OPÇÃO 1
		if(mouse_x > 190 && mouse_x <= 535 && //quando o mouser der hover aqui
		mouse_y > 430 && mouse_y <= 530){//aparece um tra�ado preto aqui
			// hover
		draw_sprite(buffer, hover, 185, 427);
            //click
            if (mouse_b == 1){
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
            }
		}

        //OPÇÃO 2
        if(mouse_x > 740 && mouse_x <= 1085 && //quando o mouser der hover aqui
		mouse_y > 430 && mouse_y <= 530){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 730, 427);
            //click
                if (mouse_b == 1){ 
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
                }
		}

        //OPÇÃO 3
        if(mouse_x > 190 && mouse_x <= 535 && //quando o mouser der hover aqui
		mouse_y > 575 && mouse_y <= 670){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 185, 573);
            //click
                if (mouse_b == 1){ 
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
                }
            }
		

        //OPÇÃO 4
        if(mouse_x > 740 && mouse_x <= 1085 && //quando o mouser der hover aqui
		mouse_y > 575 && mouse_y <= 670){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 730, 585);
            //click
            if (mouse_b == 1){ //!COLOCAR AUMENTO DE PS.PLAYERMUNDO E PS.PLAYERFASE
            if(ps.playerFase == 0 && ps.playerMundo == 2 ) ps.playerFase+= 1;
            saveState();
            telaAcerto(buffer);
            
		}}
		
        mouse(buffer);//importando a fun��o mouse em baixo de tela para ele sobrepor a tela do menu principal
		
		draw_sprite(screen, buffer, 0,0);//desenhando o buffer na screen
		
		while(timer == delay){}
		clear(buffer);
    }

	destroy_bitmap(fundo);
	destroy_bitmap(hover);
	destroy_font(firasans_16);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int fase12(BITMAP *buffer){

    int x = 0, y = 0, i;
    r=0, g=255, b=0;
    loadState();
    BITMAP* fundo = load_bitmap("assets/telas/fases/subtracao12.bmp", NULL);
	BITMAP* hover = load_bitmap("assets/telas/askmathHOVERPERGUNTAS.bmp", NULL);
	firasans_16 = load_font("library/firasans16.pcx", NULL, NULL);

    tfill = 0;
    limiteRect = 0;

		while(!key[KEY_F10])
	{
        
		clear(buffer);
		delay = timer;
            if (ps.playerCoracao <= 0){
                ps.playerCoracao = 0;
            }
        if(key[KEY_ESC]) {telaMenuPrincipal(buffer);}

		draw_sprite(buffer, fundo, 0, 0);//desenhando tela menu principal no buffer

        contadorCoracao(buffer); //contador dos corações 

        timerResposta(buffer, 15); //temporizador para resposta 


        //OPÇÃO 1
		if(mouse_x > 190 && mouse_x <= 535 && //quando o mouser der hover aqui
		mouse_y > 430 && mouse_y <= 530){//aparece um tra�ado preto aqui
			// hover
		draw_sprite(buffer, hover, 185, 427);
            //click
            if (mouse_b == 1){
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
            }
		}

        //OPÇÃO 2
        if(mouse_x > 740 && mouse_x <= 1085 && //quando o mouser der hover aqui
		mouse_y > 430 && mouse_y <= 530){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 730, 427);
            //click
            if (mouse_b == 1){ //!COLOCAR AUMENTO DE PS.PLAYERMUNDO E PS.PLAYERFASE
            if(ps.playerFase == 1 && ps.playerMundo == 2 ) ps.playerFase+= 1;
            saveState();
            telaAcerto(buffer);
            
            }
		}

        //OPÇÃO 3
        if(mouse_x > 190 && mouse_x <= 535 && //quando o mouser der hover aqui
		mouse_y > 575 && mouse_y <= 670){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 185, 573);
            //click
            if (mouse_b == 1){ 
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
                }
		}

        //OPÇÃO 4
        if(mouse_x > 740 && mouse_x <= 1085 && //quando o mouser der hover aqui
		mouse_y > 575 && mouse_y <= 670){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 730, 585);
            //click
            if (mouse_b == 1){ 
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
                }
		}
		
        mouse(buffer);//importando a fun��o mouse em baixo de tela para ele sobrepor a tela do menu principal
		
		draw_sprite(screen, buffer, 0,0);//desenhando o buffer na screen
		
		while(timer == delay){}
		clear(buffer);
    }

	destroy_bitmap(fundo);
	destroy_bitmap(hover);
	destroy_font(firasans_16);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int fase22(BITMAP *buffer){

    int x = 0, y = 0, i;
    r=0, g=255, b=0;
    loadState();
    BITMAP* fundo = load_bitmap("assets/telas/fases/subtracao22.bmp", NULL);
	BITMAP* hover = load_bitmap("assets/telas/askmathHOVERPERGUNTAS.bmp", NULL);
	firasans_16 = load_font("library/firasans16.pcx", NULL, NULL);

    tfill = 0;
    limiteRect = 0;

		while(!key[KEY_F10])
	{
        
		clear(buffer);
		delay = timer;
            if (ps.playerCoracao <= 0){
                ps.playerCoracao = 0;
            }
        if(key[KEY_ESC]) {telaMenuPrincipal(buffer);}

		draw_sprite(buffer, fundo, 0, 0);//desenhando tela menu principal no buffer

        contadorCoracao(buffer); //contador dos corações 

        timerResposta(buffer, 15); //temporizador para resposta 


        //OPÇÃO 1
		if(mouse_x > 190 && mouse_x <= 535 && //quando o mouser der hover aqui
		mouse_y > 430 && mouse_y <= 530){//aparece um tra�ado preto aqui
			// hover
		draw_sprite(buffer, hover, 185, 427);
            //click
            if (mouse_b == 1){
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
            }
		}

        //OPÇÃO 2
        if(mouse_x > 740 && mouse_x <= 1085 && //quando o mouser der hover aqui
		mouse_y > 430 && mouse_y <= 530){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 730, 427);
            //click
                if (mouse_b == 1){ 
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
                }
		}

        //OPÇÃO 3
        if(mouse_x > 190 && mouse_x <= 535 && //quando o mouser der hover aqui
		mouse_y > 575 && mouse_y <= 670){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 185, 573);
            //click
            if (mouse_b == 1){ 
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
                }
            
            }
		

        //OPÇÃO 4
        if(mouse_x > 740 && mouse_x <= 1085 && //quando o mouser der hover aqui
		mouse_y > 575 && mouse_y <= 670){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 730, 585);
            //click
            if (mouse_b == 1){ //!COLOCAR AUMENTO DE PS.PLAYERMUNDO E PS.PLAYERFASE
            if(ps.playerFase == 2 && ps.playerMundo == 2 ) ps.playerFase = 0; ps.playerMundo = 3;
            saveState();
            telaAcerto(buffer);
		}}
		
        mouse(buffer);//importando a fun��o mouse em baixo de tela para ele sobrepor a tela do menu principal
		
		draw_sprite(screen, buffer, 0,0);//desenhando o buffer na screen
		
		while(timer == delay){}
		clear(buffer);
		
    }
	destroy_bitmap(fundo);
	destroy_bitmap(hover);
	destroy_font(firasans_16);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int fase03(BITMAP *buffer){

    int x = 0, y = 0, i;
    r=0, g=255, b=0;
    loadState();
    BITMAP* fundo = load_bitmap("assets/telas/fases/multiplicacao03.bmp", NULL);
	BITMAP* hover = load_bitmap("assets/telas/askmathHOVERPERGUNTAS.bmp", NULL);
	firasans_16 = load_font("library/firasans16.pcx", NULL, NULL);

    tfill = 0;
    limiteRect = 0;

		while(!key[KEY_F10])
	{
        
		clear(buffer);
		delay = timer;
            if (ps.playerCoracao <= 0){
                ps.playerCoracao = 0;
            }
        if(key[KEY_ESC]) {telaMenuPrincipal(buffer);}

		draw_sprite(buffer, fundo, 0, 0);//desenhando tela menu principal no buffer

        contadorCoracao(buffer); //contador dos corações 

        timerResposta(buffer, 15); //temporizador para resposta 


        //OPÇÃO 1
		if(mouse_x > 190 && mouse_x <= 535 && //quando o mouser der hover aqui
		mouse_y > 430 && mouse_y <= 530){//aparece um tra�ado preto aqui
			// hover
		draw_sprite(buffer, hover, 185, 427);
            //click
            if (mouse_b == 1){
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
            }
		}

        //OPÇÃO 2
        if(mouse_x > 740 && mouse_x <= 1085 && //quando o mouser der hover aqui
		mouse_y > 430 && mouse_y <= 530){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 730, 427);
            //click
                if (mouse_b == 1){ 
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
                }
		}

        //OPÇÃO 3
        if(mouse_x > 190 && mouse_x <= 535 && //quando o mouser der hover aqui
		mouse_y > 575 && mouse_y <= 670){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 185, 573);
            //click
            if (mouse_b == 1){ 
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
                }
            }
		

        //OPÇÃO 4
        if(mouse_x > 740 && mouse_x <= 1085 && //quando o mouser der hover aqui
		mouse_y > 575 && mouse_y <= 670){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 730, 585);
            //click
            if (mouse_b == 1){ //!COLOCAR AUMENTO DE PS.PLAYERMUNDO E PS.PLAYERFASE
            if(ps.playerFase == 0 && ps.playerMundo == 3 ) ps.playerFase += 1;
            saveState();
            telaAcerto(buffer);
		}}
		
        mouse(buffer);//importando a fun��o mouse em baixo de tela para ele sobrepor a tela do menu principal
		
		draw_sprite(screen, buffer, 0,0);//desenhando o buffer na screen
		
		while(timer == delay){}
		clear(buffer);
		
    }
	destroy_bitmap(fundo);
	destroy_bitmap(hover);
	destroy_font(firasans_16);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int fase13(BITMAP *buffer){

    int x = 0, y = 0, i;
    r=0, g=255, b=0;
    loadState();
    BITMAP* fundo = load_bitmap("assets/telas/fases/multiplicacao13.bmp", NULL);
	BITMAP* hover = load_bitmap("assets/telas/askmathHOVERPERGUNTAS.bmp", NULL);
	firasans_16 = load_font("library/firasans16.pcx", NULL, NULL);

    tfill = 0;
    limiteRect = 0;

		while(!key[KEY_F10])
	{
        
		clear(buffer);
		delay = timer;
            if (ps.playerCoracao <= 0){
                ps.playerCoracao = 0;
            }
        if(key[KEY_ESC]) {telaMenuPrincipal(buffer);}

		draw_sprite(buffer, fundo, 0, 0);//desenhando tela menu principal no buffer

        contadorCoracao(buffer); //contador dos corações 

        timerResposta(buffer, 15); //temporizador para resposta 


        //OPÇÃO 1
		if(mouse_x > 190 && mouse_x <= 535 && //quando o mouser der hover aqui
		mouse_y > 430 && mouse_y <= 530){//aparece um tra�ado preto aqui
			// hover
		draw_sprite(buffer, hover, 185, 427);
            //click
            if (mouse_b == 1){
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
            }
		}

        //OPÇÃO 2
        if(mouse_x > 740 && mouse_x <= 1085 && //quando o mouser der hover aqui
		mouse_y > 430 && mouse_y <= 530){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 730, 427);
            //click
            if (mouse_b == 1){ //!COLOCAR AUMENTO DE PS.PLAYERMUNDO E PS.PLAYERFASE
            if(ps.playerFase == 1 && ps.playerMundo == 3 ) ps.playerFase += 1;
            saveState();
            telaAcerto(buffer);
		}
		}

        //OPÇÃO 3
        if(mouse_x > 190 && mouse_x <= 535 && //quando o mouser der hover aqui
		mouse_y > 575 && mouse_y <= 670){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 185, 573);
            //click
            if (mouse_b == 1){ 
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
                }
            }
		

        //OPÇÃO 4
        if(mouse_x > 740 && mouse_x <= 1085 && //quando o mouser der hover aqui
		mouse_y > 575 && mouse_y <= 670){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 730, 585);
            //click
            if (mouse_b == 1){ 
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
                }
            }
		
        mouse(buffer);//importando a fun��o mouse em baixo de tela para ele sobrepor a tela do menu principal
		
		draw_sprite(screen, buffer, 0,0);//desenhando o buffer na screen
		
		while(timer == delay){}
		clear(buffer);
		
    }
	destroy_bitmap(fundo);
	destroy_bitmap(hover);
	destroy_font(firasans_16);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int fase23(BITMAP *buffer){

    int x = 0, y = 0, i;
    r=0, g=255, b=0;
    loadState();
    BITMAP* fundo = load_bitmap("assets/telas/fases/multiplicacao23.bmp", NULL);
	BITMAP* hover = load_bitmap("assets/telas/askmathHOVERPERGUNTAS.bmp", NULL);
	firasans_16 = load_font("library/firasans16.pcx", NULL, NULL);

    tfill = 0;
    limiteRect = 0;

		while(!key[KEY_F10])
	{
        
		clear(buffer);
		delay = timer;
            if (ps.playerCoracao <= 0){
                ps.playerCoracao = 0;
            }
        if(key[KEY_ESC]) {telaMenuPrincipal(buffer);}

		draw_sprite(buffer, fundo, 0, 0);//desenhando tela menu principal no buffer

        contadorCoracao(buffer); //contador dos corações 

        timerResposta(buffer, 15); //temporizador para resposta 


        //OPÇÃO 1
		if(mouse_x > 190 && mouse_x <= 535 && //quando o mouser der hover aqui
		mouse_y > 430 && mouse_y <= 530){//aparece um tra�ado preto aqui
			// hover
		draw_sprite(buffer, hover, 185, 427);
            //click
            if (mouse_b == 1){
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
            }
		}

        //OPÇÃO 2
        if(mouse_x > 740 && mouse_x <= 1085 && //quando o mouser der hover aqui
		mouse_y > 430 && mouse_y <= 530){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 730, 427);
            //click
          if (mouse_b == 1){ 
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
                }
		}

        //OPÇÃO 3
        if(mouse_x > 190 && mouse_x <= 535 && //quando o mouser der hover aqui
		mouse_y > 575 && mouse_y <= 670){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 185, 573);
            //click
            if (mouse_b == 1){ 
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
                }
            }
		

        //OPÇÃO 4
        if(mouse_x > 740 && mouse_x <= 1085 && //quando o mouser der hover aqui
		mouse_y > 575 && mouse_y <= 670){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 730, 585);
            //click
            if (mouse_b == 1){ //!COLOCAR AUMENTO DE PS.PLAYERMUNDO E PS.PLAYERFASE
            if(ps.playerFase == 2 && ps.playerMundo == 3 ) ps.playerFase += 1;
            saveState();
            telaAcerto(buffer);
		    }
        }
		
        mouse(buffer);//importando a fun��o mouse em baixo de tela para ele sobrepor a tela do menu principal
		
		draw_sprite(screen, buffer, 0,0);//desenhando o buffer na screen
		
		while(timer == delay){}
		clear(buffer);
		
    }
	destroy_bitmap(fundo);
	destroy_bitmap(hover);
	destroy_font(firasans_16);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int fase33(BITMAP *buffer){

    int x = 0, y = 0, i;
    r=0, g=255, b=0;
    loadState();
    BITMAP* fundo = load_bitmap("assets/telas/fases/multiplicacao33.bmp", NULL);
	BITMAP* hover = load_bitmap("assets/telas/askmathHOVERPERGUNTAS.bmp", NULL);
	firasans_16 = load_font("library/firasans16.pcx", NULL, NULL);

    tfill = 0;
    limiteRect = 0;

		while(!key[KEY_F10])
	{
        
		clear(buffer);
		delay = timer;
            if (ps.playerCoracao <= 0){
                ps.playerCoracao = 0;
            }
        if(key[KEY_ESC]) {telaMenuPrincipal(buffer);}

		draw_sprite(buffer, fundo, 0, 0);//desenhando tela menu principal no buffer

        contadorCoracao(buffer); //contador dos corações 

        timerResposta(buffer, 15); //temporizador para resposta 


        //OPÇÃO 1
		if(mouse_x > 190 && mouse_x <= 535 && //quando o mouser der hover aqui
		mouse_y > 430 && mouse_y <= 530){//aparece um tra�ado preto aqui
			// hover
		draw_sprite(buffer, hover, 185, 427);
            //click
            if (mouse_b == 1){
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
            }
		}

        //OPÇÃO 2
        if(mouse_x > 740 && mouse_x <= 1085 && //quando o mouser der hover aqui
		mouse_y > 430 && mouse_y <= 530){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 730, 427);
            //click
              if (mouse_b == 1){ 
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
                }
		}

        //OPÇÃO 3
        if(mouse_x > 190 && mouse_x <= 535 && //quando o mouser der hover aqui
		mouse_y > 575 && mouse_y <= 670){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 185, 573);
            //click
            if (mouse_b == 1){ //!COLOCAR AUMENTO DE PS.PLAYERMUNDO E PS.PLAYERFASE
            if(ps.playerFase == 3 && ps.playerMundo == 3 ) ps.playerFase = 0; ps.playerMundo = 4;
            saveState();
            telaAcerto(buffer);
		    }
        }
		

        //OPÇÃO 4
        if(mouse_x > 740 && mouse_x <= 1085 && //quando o mouser der hover aqui
		mouse_y > 575 && mouse_y <= 670){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 730, 585);
            //click
            if (mouse_b == 1){ 
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
                }
        }
		
        mouse(buffer);//importando a fun��o mouse em baixo de tela para ele sobrepor a tela do menu principal
		
		draw_sprite(screen, buffer, 0,0);//desenhando o buffer na screen
		
		while(timer == delay){}
		clear(buffer);
		
    }
	destroy_bitmap(fundo);
	destroy_bitmap(hover);
	destroy_font(firasans_16);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int fase04(BITMAP *buffer){

    int x = 0, y = 0, i;
    r=0, g=255, b=0;
    loadState();
    BITMAP* fundo = load_bitmap("assets/telas/fases/divisao04.bmp", NULL);
	BITMAP* hover = load_bitmap("assets/telas/askmathHOVERPERGUNTAS.bmp", NULL);
	firasans_16 = load_font("library/firasans16.pcx", NULL, NULL);

    tfill = 0;
    limiteRect = 0;

		while(!key[KEY_F10])
	{
        
		clear(buffer);
		delay = timer;
            if (ps.playerCoracao <= 0){
                ps.playerCoracao = 0;
            }
        if(key[KEY_ESC]) {telaMenuPrincipal(buffer);}

		draw_sprite(buffer, fundo, 0, 0);//desenhando tela menu principal no buffer

        contadorCoracao(buffer); //contador dos corações 

        timerResposta(buffer, 15); //temporizador para resposta 


        //OPÇÃO 1
		if(mouse_x > 190 && mouse_x <= 535 && //quando o mouser der hover aqui
		mouse_y > 430 && mouse_y <= 530){//aparece um tra�ado preto aqui
			// hover
		draw_sprite(buffer, hover, 185, 427);
            //click
            if (mouse_b == 1){
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
            }
		}

        //OPÇÃO 2
        if(mouse_x > 740 && mouse_x <= 1085 && //quando o mouser der hover aqui
		mouse_y > 430 && mouse_y <= 530){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 730, 427);
            //click
          if (mouse_b == 1){ 
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
                }
		}

        //OPÇÃO 3
        if(mouse_x > 190 && mouse_x <= 535 && //quando o mouser der hover aqui
		mouse_y > 575 && mouse_y <= 670){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 185, 573);
            //click
            if (mouse_b == 1){ 
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
                }
            }
		

        //OPÇÃO 4
        if(mouse_x > 740 && mouse_x <= 1085 && //quando o mouser der hover aqui
		mouse_y > 575 && mouse_y <= 670){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 730, 585);
            //click
            if (mouse_b == 1){ //!COLOCAR AUMENTO DE PS.PLAYERMUNDO E PS.PLAYERFASE
            if(ps.playerFase == 0 && ps.playerMundo == 4 ) ps.playerFase += 1;
            saveState();
            telaAcerto(buffer);
		    }
        }
		
        mouse(buffer);//importando a fun��o mouse em baixo de tela para ele sobrepor a tela do menu principal
		
		draw_sprite(screen, buffer, 0,0);//desenhando o buffer na screen
		
		while(timer == delay){}
		clear(buffer);
		
    }
	destroy_bitmap(fundo);
	destroy_bitmap(hover);
	destroy_font(firasans_16);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int fase14(BITMAP *buffer){

    int x = 0, y = 0, i;
    r=0, g=255, b=0;
    loadState();
    BITMAP* fundo = load_bitmap("assets/telas/fases/divisao14.bmp", NULL);
	BITMAP* hover = load_bitmap("assets/telas/askmathHOVERPERGUNTAS.bmp", NULL);
	firasans_16 = load_font("library/firasans16.pcx", NULL, NULL);

    tfill = 0;
    limiteRect = 0;

		while(!key[KEY_F10])
	{
        
		clear(buffer);
		delay = timer;
            if (ps.playerCoracao <= 0){
                ps.playerCoracao = 0;
            }
        if(key[KEY_ESC]) {telaMenuPrincipal(buffer);}

		draw_sprite(buffer, fundo, 0, 0);//desenhando tela menu principal no buffer

        contadorCoracao(buffer); //contador dos corações 

        timerResposta(buffer, 15); //temporizador para resposta 


        //OPÇÃO 1
		if(mouse_x > 190 && mouse_x <= 535 && //quando o mouser der hover aqui
		mouse_y > 430 && mouse_y <= 530){//aparece um tra�ado preto aqui
			// hover
		draw_sprite(buffer, hover, 185, 427);
            //click
            if (mouse_b == 1){
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
            }
		}

        //OPÇÃO 2
        if(mouse_x > 740 && mouse_x <= 1085 && //quando o mouser der hover aqui
		mouse_y > 430 && mouse_y <= 530){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 730, 427);
            //click
          if (mouse_b == 1){ 
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
                }
		}

        //OPÇÃO 3
        if(mouse_x > 190 && mouse_x <= 535 && //quando o mouser der hover aqui
		mouse_y > 575 && mouse_y <= 670){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 185, 573);
            //click
            if (mouse_b == 1){ 
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
                }
            }
		

        //OPÇÃO 4
        if(mouse_x > 740 && mouse_x <= 1085 && //quando o mouser der hover aqui
		mouse_y > 575 && mouse_y <= 670){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 730, 585);
            //click
            if (mouse_b == 1){ //!COLOCAR AUMENTO DE PS.PLAYERMUNDO E PS.PLAYERFASE
            if(ps.playerFase == 1 && ps.playerMundo == 4 ) ps.playerFase += 1;
            saveState();
            telaAcerto(buffer);
		    }
        }
		
        mouse(buffer);//importando a fun��o mouse em baixo de tela para ele sobrepor a tela do menu principal
		
		draw_sprite(screen, buffer, 0,0);//desenhando o buffer na screen
		
		while(timer == delay){}
		clear(buffer);
		
    }
	destroy_bitmap(fundo);
	destroy_bitmap(hover);
	destroy_font(firasans_16);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int fase24(BITMAP *buffer){

    int x = 0, y = 0, i;
    r=0, g=255, b=0;
    loadState();
    BITMAP* fundo = load_bitmap("assets/telas/fases/divisao24.bmp", NULL);
	BITMAP* hover = load_bitmap("assets/telas/askmathHOVERPERGUNTAS.bmp", NULL);
	firasans_16 = load_font("library/firasans16.pcx", NULL, NULL);

    tfill = 0;
    limiteRect = 0;

		while(!key[KEY_F10])
	{
        
		clear(buffer);
		delay = timer;
            if (ps.playerCoracao <= 0){
                ps.playerCoracao = 0;
            }
        if(key[KEY_ESC]) {telaMenuPrincipal(buffer);}

		draw_sprite(buffer, fundo, 0, 0);//desenhando tela menu principal no buffer

        contadorCoracao(buffer); //contador dos corações 

        timerResposta(buffer, 15); //temporizador para resposta 


        //OPÇÃO 1
		if(mouse_x > 190 && mouse_x <= 535 && //quando o mouser der hover aqui
		mouse_y > 430 && mouse_y <= 530){//aparece um tra�ado preto aqui
			// hover
		draw_sprite(buffer, hover, 185, 427);
            //click
            if (mouse_b == 1){
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
            }
		}

        //OPÇÃO 2
        if(mouse_x > 740 && mouse_x <= 1085 && //quando o mouser der hover aqui
		mouse_y > 430 && mouse_y <= 530){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 730, 427);
            //click
            if (mouse_b == 1){ //!COLOCAR AUMENTO DE PS.PLAYERMUNDO E PS.PLAYERFASE
            if(ps.playerFase == 2 && ps.playerMundo == 4 ) ps.playerFase += 1;
            saveState();
            telaAcerto(buffer);
		    }
		}

        //OPÇÃO 3
        if(mouse_x > 190 && mouse_x <= 535 && //quando o mouser der hover aqui
		mouse_y > 575 && mouse_y <= 670){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 185, 573);
            //click
            if (mouse_b == 1){ 
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
                }
            }
		

        //OPÇÃO 4
        if(mouse_x > 740 && mouse_x <= 1085 && //quando o mouser der hover aqui
		mouse_y > 575 && mouse_y <= 670){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 730, 585);
            //click
            if (mouse_b == 1){ 
            ps.playerCoracao -= 1;
            saveState();
            rest(250);
            }
        }
		
        mouse(buffer);//importando a fun��o mouse em baixo de tela para ele sobrepor a tela do menu principal
		
		draw_sprite(screen, buffer, 0,0);//desenhando o buffer na screen
		
		while(timer == delay){}
		clear(buffer);
		
    }
	destroy_bitmap(fundo);
	destroy_bitmap(hover);
	destroy_font(firasans_16);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int fase34(BITMAP *buffer){

    int x = 0, y = 0, i;
    r=0, g=255, b=0;
    loadState();
    BITMAP* fundo = load_bitmap("assets/telas/fases/divisao34.bmp", NULL);
	BITMAP* hover = load_bitmap("assets/telas/askmathHOVERPERGUNTAS.bmp", NULL);
	firasans_16 = load_font("library/firasans16.pcx", NULL, NULL);

    tfill = 0;
    limiteRect = 0;

		while(!key[KEY_F10])
	{
        
		clear(buffer);
		delay = timer;
            if (ps.playerCoracao <= 0){
                ps.playerCoracao = 0;
            }
        if(key[KEY_ESC]) {telaMenuPrincipal(buffer);}

		draw_sprite(buffer, fundo, 0, 0);//desenhando tela menu principal no buffer

        contadorCoracao(buffer); //contador dos corações 

        timerResposta(buffer, 15); //temporizador para resposta 


        //OPÇÃO 1
		if(mouse_x > 190 && mouse_x <= 535 && //quando o mouser der hover aqui
		mouse_y > 430 && mouse_y <= 530){//aparece um tra�ado preto aqui
			// hover
		draw_sprite(buffer, hover, 185, 427);
            //click
            if (mouse_b == 1){ //!COLOCAR AUMENTO DE PS.PLAYERMUNDO E PS.PLAYERFASE
            if(ps.playerFase == 3 && ps.playerMundo == 4 ) ps.playerFase += 1;
            saveState();
            telaAcerto(buffer);
		    }
           
		}

        //OPÇÃO 2
        if(mouse_x > 740 && mouse_x <= 1085 && //quando o mouser der hover aqui
		mouse_y > 430 && mouse_y <= 530){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 730, 427);
            //click
            if (mouse_b == 1){
            ps.playerCoracao -= 1;
            saveState();
            rest(250);
        }
		}

        //OPÇÃO 3
        if(mouse_x > 190 && mouse_x <= 535 && //quando o mouser der hover aqui
		mouse_y > 575 && mouse_y <= 670){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 185, 573);
            //click
            if (mouse_b == 1){ 
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
                }
            }
		

        //OPÇÃO 4
        if(mouse_x > 740 && mouse_x <= 1085 && //quando o mouser der hover aqui
		mouse_y > 575 && mouse_y <= 670){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 730, 585);
            //click
            if (mouse_b == 1){ 
            ps.playerCoracao -= 1;
            saveState();
            rest(250);
            }
        }
		
        mouse(buffer);//importando a fun��o mouse em baixo de tela para ele sobrepor a tela do menu principal
		
		draw_sprite(screen, buffer, 0,0);//desenhando o buffer na screen
		
		while(timer == delay){}
		clear(buffer);
		
    }
	destroy_bitmap(fundo);
	destroy_bitmap(hover);
	destroy_font(firasans_16);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int fase44(BITMAP *buffer){

    int x = 0, y = 0, i;
    r=0, g=255, b=0;
    loadState();
    BITMAP* fundo = load_bitmap("assets/telas/fases/divisao44.bmp", NULL);
	BITMAP* hover = load_bitmap("assets/telas/askmathHOVERPERGUNTAS.bmp", NULL);
	firasans_16 = load_font("library/firasans16.pcx", NULL, NULL);

    tfill = 0;
    limiteRect = 0;

		while(!key[KEY_F10])
	{
        
		clear(buffer);
		delay = timer;
            if (ps.playerCoracao <= 0){
                ps.playerCoracao = 0;
            }
        if(key[KEY_ESC]) {telaMenuPrincipal(buffer);}

		draw_sprite(buffer, fundo, 0, 0);//desenhando tela menu principal no buffer

        contadorCoracao(buffer); //contador dos corações 

        timerResposta(buffer, 15); //temporizador para resposta 


        //OPÇÃO 1
		if(mouse_x > 190 && mouse_x <= 535 && //quando o mouser der hover aqui
		mouse_y > 430 && mouse_y <= 530){//aparece um tra�ado preto aqui
			// hover
		draw_sprite(buffer, hover, 185, 427);
            //click
           if (mouse_b == 1){ 
            ps.playerCoracao -= 1;
            saveState();
            rest(250);
            }
		}

        //OPÇÃO 2
        if(mouse_x > 740 && mouse_x <= 1085 && //quando o mouser der hover aqui
		mouse_y > 430 && mouse_y <= 530){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 730, 427);
            //click
            if (mouse_b == 1){
            ps.playerCoracao -= 1;
            saveState();
            rest(250);
            }
		}

        //OPÇÃO 3
        if(mouse_x > 190 && mouse_x <= 535 && //quando o mouser der hover aqui
		mouse_y > 575 && mouse_y <= 670){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 185, 573);
            //click
            if (mouse_b == 1){ 
                ps.playerCoracao -= 1;
                saveState();
                rest(250);
                }
            }
		

        //OPÇÃO 4
        if(mouse_x > 740 && mouse_x <= 1085 && //quando o mouser der hover aqui
		mouse_y > 575 && mouse_y <= 670){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 730, 585);
            //click
            if (mouse_b == 1){ //!COLOCAR AUMENTO DE PS.PLAYERMUNDO E PS.PLAYERFASE
            saveState();
            telaFinal(buffer);
		    }
        }
		
        mouse(buffer);//importando a fun��o mouse em baixo de tela para ele sobrepor a tela do menu principal
		
		draw_sprite(screen, buffer, 0,0);//desenhando o buffer na screen
		
		while(timer == delay){}
		clear(buffer);
		
    }
	destroy_bitmap(fundo);
	destroy_bitmap(hover);
	destroy_font(firasans_16);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 void escolhaFase (int l, int c){ //FASE = L  \\  MUNDO = C
BITMAP* buffer = create_bitmap(1280,720); //declarando buffer dentro do escopo do escolhaFase
switch (jogoFase[l][c]){

    case 0:
        ps.playerCoracao = 3; //! IGUALANDO CORAÇÕES PARA SEU MÁXIMO POIS É UMA PRIMEIRA FASE DE UM NOVO MUNDO
        fase00(buffer);
        break;
    
     case 1:
        ps.playerCoracao = 3;
        fase01(buffer);
        break;

    case 11:
        fase11(buffer);
        break;

    case 2:
        ps.playerCoracao = 3;
        fase02(buffer);
        break;

    case 12:
        fase12(buffer);
        break;

    case 22:
        fase22(buffer);
        break;

    case 3:
        ps.playerCoracao = 3;
        fase03(buffer);
        break;
    
    case 13:
        fase13(buffer);
        break;

    case 23:
        fase23(buffer);
        break;

    case 33:
        fase33(buffer);
        break;

    case 4:
        ps.playerCoracao = 3;
        fase04(buffer);
        break;

    case 14:
        fase14(buffer);
        break;
        
    case 24:
        fase24(buffer);
        break;

    case 34:
        fase34(buffer);
        break;

    case 44:
        fase44(buffer);
        break; 

}
} 
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int telaAcerto(BITMAP *buffer){

	BITMAP* fundo = load_bitmap("assets/telas/askmathRESPCORRETA.bmp", NULL);

		while(mouse_b != 1)
	{
		clear(buffer);
		delay = timer;

        if(key[KEY_ESC]) {telaMenuPrincipal(buffer);}

		draw_sprite(buffer, fundo, 0, 0);//desenhando tela menu principal no buffer

		gifAcerto(buffer);

		mouse(buffer);//importando a fun��o mouse em baixo de tela para ele sobrepor a tela do menu principal
		
        
		draw_sprite(screen, buffer, 0,0);//desenhando o buffer na screen
		
		while(timer == delay){}
		clear(buffer);
	}

	destroy_bitmap(fundo);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int timerResposta(BITMAP *buffer, int segs){
    int msTimer = 0;  
    int corTimer;

    if(segs == 15){
        msTimer = 36;
    }
    else{
        msTimer = 50;
    }

    install_int_ex(tempofill, MSEC_TO_TIMER(msTimer));// contando 1 seg a cada 1 seg para o "relogio"

		 if (limiteRect != 1042){//controle para parada do rectfill
		limiteRect = 630+tfill;}

        if(timerms%10 == 0){
        if(r!=255) r += 5;
        if(r==255 && g!= 0)  g -= 6;}

        if(limiteRect == 1042){gifGameOver(buffer);}

		rectfill(buffer,630, 75, limiteRect ,50, makecol(r,g,b));//desenhando um retangulo preenchido atras

        rect(buffer, 630, 75, 1042, 50, 0xffffff);// desenhando um retangulo sem preenchimento
        rect(buffer, 631, 76, 1043, 51, 0xffffff); // desenhando novamente suas linhas 1px a mais para 
        rect(buffer, 632, 77, 1044, 52, 0xffffff);	// "reforça-las" e deixar elas mais grossas
}
 
#endif