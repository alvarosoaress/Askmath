#include <allegro.h>
#include <stdlib.h>
#include <stdio.h>
#include <winalleg.h> //SALVA VIDAS <3
#include "utilityFunc.h"
#include "playerStatus.h"
#include "playerFunc.h"


#ifndef _funcsH_
#define _funcsH_

//VAR GLOBAIS
int timer = 0;//controlador frame time
int timersegundos = 0;//controlador "relogio de segundos"
int timerms = 0;
int entratextoRODAR = 0;

void tempoms() {timerms++;}
void tempo () {timer++;}//controlador frame time
void segundos () {timersegundos++;}//controlador "relogio de segundos"
float delay;
FONT *firasans_16;
FONT *chalk;

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int telaInicial(BITMAP *buffer){
	int x = 0, y = 0, i=0;

	BITMAP* fundo = load_bitmap("assets/telas/askmathTELAINICIAL.bmp", NULL);
	BITMAP* hover = load_bitmap("assets/telas/askmathHOVERTELAINICIAL.bmp", NULL);
	firasans_16 = load_font("library/firasans16.pcx", NULL, NULL);
	
		while(!key[KEY_ESC])
	{
		clear(buffer);
		delay = timer;
		draw_sprite(buffer, fundo, 0, 0);//desenhando tela menu principal no buffer
		gifteste(buffer);
		textprintf_ex(buffer,font,100,100,makecol(123,23,222), -1, "%d", timerms);//contador de segundos passados

		textprintf_ex(buffer,font,850,200,makecol(255,0,0), -1, "%s", ps.playerNome);
		//BOT�O JOGAR
		if(mouse_x > 436 && mouse_x <= 859 && //quando o mouser der hover aqui
		mouse_y > 385 && mouse_y <= 492){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 427, 382);
		if(mouse_b == 1){
			telaSelecaoPers(buffer);
			}
		}
		
		//BOT�O CR�DITOS
		if(mouse_x > 11 && mouse_x <= 432 && 
		mouse_y > 597 && mouse_y <= 701){
			
		draw_sprite(buffer, hover, 0, 595);}
		
		//BOT�O SAIR
		if(mouse_x > 855 && mouse_x <=1280 && 
		mouse_y > 597 && mouse_y <= 701){
			
		draw_sprite(buffer, hover, 835, 595);}
	

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
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int mouse (BITMAP *buffer){
	BITMAP* ponteiro = load_bitmap("assets/cursor/cursorpica.bmp", NULL);//importando o ponteiro para VAR ponteiro
		
		textprintf_ex(buffer, font, 200, 200, makecol(200,200,200), -1, "mx %i my %i", mouse_x, mouse_y);
		textprintf_ex(buffer, font, 400, 400, makecol(400,400,400), -1, "mouse click %i", mouse_b);
		set_mouse_sprite(ponteiro);
		draw_sprite(buffer, ponteiro, mouse_x-1, mouse_y);//desenhando o mouse no buffer
		freeze_mouse_flag;
		
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int telaSelecaoPers(BITMAP *buffer){
	int x = 0, y = 0, i;

	BITMAP* telaSelecao = load_bitmap("assets/telas/askmathESCOLHAPERS.bmp", NULL);
	BITMAP* hover1 = load_bitmap("assets/telas/askmathESCOLHAPERSHOVERvermelho.bmp", NULL);
	BITMAP* hover2 = load_bitmap("assets/telas/askmathESCOLHAPERSHOVERamarelo.bmp", NULL);
	BITMAP* hover3 = load_bitmap("assets/telas/askmathESCOLHAPERSHOVERazul.bmp", NULL);
	firasans_16 = load_font("library/firasans16.pcx", NULL, NULL);
	
		while(!key[KEY_ESC])
	{
		clear(buffer);
		delay = timer;
		
		draw_sprite(buffer, telaSelecao, 0, 0);//desenhando tela menu principal no buffer
		
		//BOT�O PERSONAGEM 1
		if(mouse_x > 20 && mouse_x <= 412 && //quando o mouser der hover aqui
		mouse_y > 249 && mouse_y <= 635){//aparece um tra�ado preto aqui
		draw_sprite(buffer, hover1, 0, 0); //aparece a animação de hover quando passa o mouse por cima
		if(mouse_b == 1){//se o player clilcar com o botão esquerdo aqui, dá load state
			ps.playerNumero = '1';// nesse save
			loadState();
			if(ps.playerIdade<=0){
					telaCriacaoPers(buffer);
				}
				else{
					saveState();
					loadState();
					telaMenuPrincipal(buffer);
					}
			}
		}
		
		//BOT�O PERSONAGEM 2
		if(mouse_x > 435 && mouse_x <= 827 && //quando o mouser der hover aqui
		mouse_y > 249 && mouse_y <= 635){//aparece um tra�ado preto aqui
		draw_sprite(buffer, hover2, 0, 0);
			if(mouse_b == 1){
			ps.playerNumero = '2';
			loadState();
			if(ps.playerIdade<=0){
					telaCriacaoPers(buffer);
				}
				else{
					saveState();
					loadState();
					telaMenuPrincipal(buffer);
					}
			}
		}
		
		//BOT�O PERSONAGEM 3
		if(mouse_x > 855 && mouse_x <= 1242 && //quando o mouser der hover aqui
		mouse_y > 249 && mouse_y <= 635){//aparece um tra�ado preto aqui
		draw_sprite(buffer, hover3, 0, 0);
			if(mouse_b == 1){
			ps.playerNumero = '3';
			loadState();
				if(ps.playerIdade<=0){
					telaCriacaoPers(buffer);
				}
				else{
					saveState();
					loadState();
					telaMenuPrincipal(buffer);
					}
				}
			}
		
		
		textprintf_ex(buffer,font,100,100,makecol(123,23,222), -1, "%d", timersegundos);//contador de segundos passados
		
		mouse(buffer);//importando a fun��o mouse em baixo de tela para ele sobrepor a tela do menu principal

		selecaoPers(buffer);


		draw_sprite(screen, buffer, 0,0);//desenhando o buffer na screen
		
		while(timer == delay){}
		clear(buffer);
		
	}

destroy_bitmap(telaSelecao);
destroy_bitmap(hover1);
destroy_bitmap(hover2);
destroy_bitmap(hover3);
destroy_font(firasans_16);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int telaCriacaoPers(BITMAP *buffer){
int x = 390, y = 220, i=0;

	BITMAP* fundo = load_bitmap("assets/telas/askmathCRIACAOPERS.bmp", NULL);
	BITMAP* hover = load_bitmap("assets/telas/askmathMENUHOVER.bmp", NULL);
	BITMAP* hoverIdade = load_bitmap("assets/telas/askmathIDADEHOVER.bmp", NULL);
	BITMAP* hoverNome = load_bitmap("assets/telas/hoverNome.bmp", NULL);
	firasans_16 = load_font("library/firasans16.pcx", NULL, NULL);
	chalk = load_font("library/chalk94.pcx", NULL, NULL);
	
		while(!key[KEY_ESC])
	{
		clear(buffer);
		delay = timer;
		draw_sprite(buffer, fundo, 0, 0);//desenhando tela menu principal no buffer

		//*BOTÃO CONTINUAR
		if(mouse_x > 880 && mouse_x <= 1255 && //quando o mouser der hover aqui
		mouse_y > 623 && mouse_y <= 702){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 880, 620);
		if(mouse_b == 1){
			saveState();
			loadState();
			telaMenuPrincipal(buffer);
			}
		}

		//*BOTÃO NOME
		if(mouse_x > 0 && mouse_x <= 428 && //quando o mouser der hover aqui
		mouse_y > 222 && mouse_y <= 318){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hoverNome, 0, 222);
		if(mouse_b == 1){
			entratextoRODAR = 0;
			entraNome(buffer);
			}
		}

		//*BOTÃO IDADE MAIS
		if(mouse_x > 610 && mouse_x <= 711 && //quando o mouser der hover aqui
		mouse_y > 358 && mouse_y <= 451){//aparece um tra�ado preto aqui
			if(mouse_b == 1){//caso o usuario clique no botão para cima, a idade irá aumentar
			ps.playerIdade += 1;
			rest(150);
			}
		draw_sprite_v_flip(buffer, hoverIdade, 610, 358);
		}

		//*BOTÃO IDADE MENOS
		if(mouse_x > 610 && mouse_x <= 711 && //quando o mouser der hover aqui
		mouse_y > 480 && mouse_y <= 580){//aparece um tra�ado preto aqui
			if(mouse_b == 1){
			ps.playerIdade -= 1;
			rest (150);//rest para evitar que o botão seja clickado sem limite, causando um aumento infinito no ps.playerIdade
			}
		draw_sprite(buffer,hoverIdade,610,480);
		}
		
		if(ps.playerIdade <= 0 || ps.playerIdade >= 99){ //tratando a variavel para que ela não ultrapasse 99 nem fique negativa, caso um dos dois seja verdade a variavel irá ser igualada à 0
			ps.playerIdade = 0;
		}

		mouse(buffer);//importando a função mouse em baixo de tela para ele sobrepor a tela do menu principal

		//MOSTRADOR DE IDADE   //!AUEMENTAR O TAMNHO DA FONTE 
		textprintf_ex(buffer,chalk,510,410,makecol(123,23,222), -1, "%d", ps.playerIdade);

		for(i=0;i<10;i++){
			if(ps.playerNome[i] != NULL ){//imprimindo o nome na tela letra por letra para encaixar no lugar certo
			
				
				textprintf_ex(buffer,chalk,x,y,makecol(123,23,222), -1, "%c", ps.playerNome[i]);
				x+=88;//dando um espaço de 88px entre um caracter e outro
				}
		}

		x = 390;//igualando o x a 390 novamente para a impressão do nome ficar certa

		draw_sprite(screen, buffer, 0,0);//desenhando o buffer na screen

		
		while(timer == delay){}
		clear(buffer);
		}
	destroy_bitmap(fundo);
	destroy_bitmap(hover);
	destroy_bitmap(hoverIdade);
	destroy_bitmap(hoverNome);
	destroy_font(firasans_16);
	destroy_font(chalk);
	}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int gifteste (BITMAP *buffer){
	int i=0;
	int num_frames = 4;
	int frame_atual = 0;
	int tempo_de_troca = 200;

	BITMAP* f0 = load_bitmap("gif/0.bmp", NULL);
	BITMAP* f1 = load_bitmap("gif/1.bmp", NULL);
	BITMAP* f2 = load_bitmap("gif/2.bmp", NULL);
	BITMAP* f3 = load_bitmap("gif/3.bmp", NULL);

	int fv[4] = {f0,f1,f2,f3};

	frame_atual = (timerms / tempo_de_troca) % num_frames;

	draw_sprite(buffer, fv[frame_atual], 0, 0);
	/* printf("Frame atual: %d\n", frame_atual);
	printf("timerms/tempodetroca: %d\n", (timerms / tempo_de_troca)); */

	destroy_bitmap(f0);
	destroy_bitmap(f1);
	destroy_bitmap(f2);
	destroy_bitmap(f3);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int entratexto (int x, int y){
	int i=0;
	int scancode, var;

	chalk = load_font("library/chalk94.pcx", NULL, NULL);

	if (entratextoRODAR == 0){//variavel para evitar que a função rode infinitamente, caso não tenha ela irá ficar esperando um input atras do outro do usuário, travando na tela.
	while(i<10){ 
		if(key[KEY_ENTER]){
			break;
		}
		var = ureadkey(&scancode);//ureadkey para ler input do usuario como unicode e jogar para a variavel SCANCODE
		ps.playerNome[i] = scancode_to_ascii(scancode);//transformando SCANCODE em ASCII, para poder preservar as letras e caracter especiais

		if(ps.playerNome[i] != NULL){//rodando um for até o final do vetor de nome
			i++;
			x+=88;
			entratextoRODAR = 1;//igualando a varivavel de controle para 1, travando toda a função, impedidndo dela rodar novamente até que a varivavel seja 0 novamente;
		}
		textprintf_ex(screen,chalk,x,y,makecol(123,23,222), -1, "%c", var);

		//imprimindo letra por letra na tela do usuario
	}

}
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int entraNome (BITMAP *buffer){
int x = 390, y = 220, i=0;

	BITMAP* fundo = load_bitmap("assets/telas/askmathCRIACAONOME.bmp", NULL);

	firasans_16 = load_font("library/firasans16.pcx", NULL, NULL);
	
		while(!key[KEY_ESC])
	{
		clear(buffer);
		delay = timer;
		draw_sprite(buffer, fundo, 0, 0);//desenhando tela menu principal no buffer

		mouse(buffer);//importando a função mouse em baixo de tela para ele sobrepor a tela do menu principal

		x = 390;//igualando o x a 390 novamente para a impressão do nome ficar certa

		draw_sprite(screen, buffer, 0,0);//desenhando o buffer na screen

		entratexto(300,220);//puxando a entrada de texto para a pessoa colocar seu nome
		
		
		while(timer == delay){}
		clear(buffer);
		return 1;
}
	destroy_bitmap(fundo);
	destroy_font(firasans_16);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int telaMenuPrincipal(BITMAP *buffer){
	
int x = 0, y = 0, i;

	BITMAP* fundo = load_bitmap("assets/telas/askmathMENUPRINCIPAL.bmp", NULL);
	BITMAP* hover = load_bitmap("assets/telas/askmathHOVERMENUPRINCIPAL.bmp", NULL);
	firasans_16 = load_font("library/firasans16.pcx", NULL, NULL);
	
		while(!key[KEY_ESC])
	{
		clear(buffer);
		delay = timer;
		draw_sprite(buffer, fundo, 0, 0);//desenhando tela menu principal no buffer
		gifteste(buffer);
		
		//BOTÃO CONTINUAR
		if(mouse_x > 52 && mouse_x <= 600 && //quando o mouser der hover aqui
		mouse_y > 40 && mouse_y <= 180){//aparece um tra�ado preto aqui
		draw_sprite(buffer, hover, 43, 40);
			if (mouse_b == 1){
				 escolhaFase(ps.playerFase, ps.playerMundo);
			}
		}

		//BOTÃO PERSONAGEM
		if(mouse_x > 52 && mouse_x <= 600 && //quando o mouser der hover aqui
		mouse_y > 218 && mouse_y <= 340){//aparece um tra�ado preto aqui
		draw_sprite(buffer, hover, 43, 217);
		}

		//BOTÃO MUNDOS
		if(mouse_x > 52 && mouse_x <= 600 && //quando o mouser der hover aqui
		mouse_y > 396 && mouse_y <= 518){//aparece um tra�ado preto aqui
		draw_sprite(buffer, hover, 40, 391);
		}

		//BOTÃO SAIR
		if(mouse_x > 52 && mouse_x <= 600 && //quando o mouser der hover aqui
		mouse_y > 560 && mouse_y <= 696){//aparece um tra�ado preto aqui
		draw_sprite(buffer, hover, 42, 558);
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

#endif

