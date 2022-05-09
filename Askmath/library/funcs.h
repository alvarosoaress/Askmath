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

int timerms = 0;
int entratextoRODAR = 0;

void tempoms() {timerms++;} //controla o tempo_de_troca do GIF
void tempo () {timer++;}//controlador frame time

float delay;
FONT *firasans_16;
FONT *chalk;

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int telaInicial(BITMAP *buffer){
	int x = 0, y = 0, i=0;

	BITMAP* fundo = load_bitmap("assets/telas/askmathTELAINICIAL.bmp", NULL);
	BITMAP* hover = load_bitmap("assets/telas/askmathHOVERTELAINICIAL.bmp", NULL);
	firasans_16 = load_font("library/firasans16.pcx", NULL, NULL);
	
		while(!key[KEY_F10])
	{
		clear(buffer);
		delay = timer;

		if(key[KEY_ESC]) {allegro_exit();}

		draw_sprite(buffer, fundo, 0, 0);//desenhando tela menu principal no buffer

		//BOTÃO JOGAR
		if(mouse_x > 436 && mouse_x <= 859 && //quando o mouser der hover aqui
		mouse_y > 385 && mouse_y <= 492){//aparece um tra�ado preto aqui
			
		draw_sprite(buffer, hover, 427, 382);
		if(mouse_b == 1){
			telaSelecaoPers(buffer);
			}
		}
		
		//BOTÃO CRÉDITOS
		if(mouse_x > 855 && mouse_x <=1280 && 
		mouse_y > 597 && mouse_y <= 701){
		draw_sprite(buffer, hover, 835, 595);
		rest(50);
		if(mouse_b == 1){
			telaCredtios(buffer);
			}
		}

		//BOTÃO SAIR
		if(mouse_x > 11 && mouse_x <= 432 && 
		mouse_y > 597 && mouse_y <= 701){
			rest(25);
			if (mouse_b == 1){
				allegro_exit();}
		draw_sprite(buffer, hover, 0, 595);}
			
	

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
int mouse (BITMAP *buffer){
	BITMAP* ponteiro = load_bitmap("assets/cursor/cursor.bmp", NULL);//importando o ponteiro para VAR ponteiro
		
		set_mouse_sprite(ponteiro);
		draw_sprite(buffer, ponteiro, mouse_x-1, mouse_y);//desenhando o mouse no buffer
		freeze_mouse_flag;
		
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int telaSelecaoPers(BITMAP *buffer){
	int x = 0, y = 0, i;

	BITMAP* telaSelecao = load_bitmap("assets/telas/askmathESCOLHAPERS.bmp", NULL);
	BITMAP* excluir = load_bitmap("assets/telas/botaoExcluir.bmp", NULL);
	BITMAP* hover1 = load_bitmap("assets/telas/askmathESCOLHAPERSHOVERvermelho.bmp", NULL);
	BITMAP* hover2 = load_bitmap("assets/telas/askmathESCOLHAPERSHOVERamarelo.bmp", NULL);
	BITMAP* hover3 = load_bitmap("assets/telas/askmathESCOLHAPERSHOVERazul.bmp", NULL);
	BITMAP* hoverexcluir = load_bitmap("assets/telas/askmathHOVEREXCLUIR.bmp", NULL);
	firasans_16 = load_font("library/firasans16.pcx", NULL, NULL);
	
		while(!key[KEY_F10])
	{
		clear(buffer);
		delay = timer;

		if(key[KEY_ESC]) {telaInicial(buffer);}

		draw_sprite(buffer, telaSelecao, 0, 0);//desenhando tela menu principal no buffer
		
		//BOT�O PERSONAGEM 1
		if(mouse_x > 20 && mouse_x <= 412 && //quando o mouser der hover aqui
		mouse_y > 249 && mouse_y <= 635){//aparece um tra�ado preto aqui
		draw_sprite(buffer, hover1, 0, 0); //aparece a animação de hover quando passa o mouse por cima
		if(mouse_b == 1){//se o player clilcar com o botão esquerdo aqui, dá load state
			rest(100);
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
			rest(100);
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
			rest(100);
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

		draw_sprite(buffer, excluir, 60, 650);
		draw_sprite(buffer, excluir, 503, 650);
		draw_sprite(buffer, excluir, 921, 650);

		// EXCLUIR 1
		if(mouse_x > 60 && mouse_x <= 335 && //quando o mouser der hover aqui
		mouse_y > 645 && mouse_y <= 710){//aparece um tra�ado preto aqui
		draw_sprite(buffer, hoverexcluir, 60, 650);
			if(mouse_b == 1){
			ps.playerNumero = '1';
			loadState();
			ps.playerIdade = 0; ps.playerMundo = 0; ps.playerFase = 0; ps.playerCoracao = 3; ps.playerNome == 0;
			saveState();}
		}
		
		// EXCLUIR 1
		if(mouse_x > 503 && mouse_x <= 778 && //quando o mouser der hover aqui
		mouse_y > 645 && mouse_y <= 710){//aparece um tra�ado preto aqui
		draw_sprite(buffer, hoverexcluir, 503, 650);
		if(mouse_b == 1){
			ps.playerNumero = '2';
			loadState();
			ps.playerIdade = 0; ps.playerMundo = 0; ps.playerFase = 0; ps.playerCoracao = 3; ps.playerNome == 0;
			saveState();}
			}

		// EXCLUIR 1
		if(mouse_x > 921 && mouse_x <= 1196 && //quando o mouser der hover aqui
		mouse_y > 645 && mouse_y <= 710){//aparece um tra�ado preto aqui
		draw_sprite(buffer, hoverexcluir, 921, 650);
		if(mouse_b == 1){
			ps.playerNumero = '3';
			loadState();
			ps.playerIdade = 0; ps.playerMundo = 0; ps.playerFase = 0; ps.playerCoracao = 3; ps.playerNome == 0;
			saveState();}
			}


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

		for(i=0;i<10;i++){
			ps.playerNome[i] = ' ';}

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
			ps.playerIdade = 1;
		}

		mouse(buffer);//importando a função mouse em baixo de tela para ele sobrepor a tela do menu principal

		//MOSTRADOR DE IDADE   //!AUEMENTAR O TAMNHO DA FONTE 
		textprintf_ex(buffer,chalk,510,410,makecol(255,255,255), -1, "%d", ps.playerIdade);

		for(i=0;i<10;i++){
			if(ps.playerNome[i] != NULL ){//imprimindo o nome na tela letra por letra para encaixar no lugar certo
			
				
				textprintf_ex(buffer,chalk,x,y,makecol(255,255,255), -1, "%c", ps.playerNome[i]);
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
int gifAcerto (BITMAP *buffer){
	int i=0;
	int num_frames = 10;
	int frame_atual = 0;
	int tempo_de_troca = 100;
	BITMAP* fv[10];

	 fv[0] = load_bitmap("assets/gifs/gifAcerto/0.bmp", NULL);
	 fv[1] = load_bitmap("assets/gifs/gifAcerto/1.bmp", NULL);
	 fv[2] = load_bitmap("assets/gifs/gifAcerto/2.bmp", NULL);
	 fv[3] = load_bitmap("assets/gifs/gifAcerto/3.bmp", NULL);
	 fv[4] = load_bitmap("assets/gifs/gifAcerto/4.bmp", NULL);
	 fv[5] = load_bitmap("assets/gifs/gifAcerto/5.bmp", NULL);
	 fv[6] = load_bitmap("assets/gifs/gifAcerto/6.bmp", NULL);
	 fv[7] = load_bitmap("assets/gifs/gifAcerto/7.bmp", NULL);
	 fv[8] = load_bitmap("assets/gifs/gifAcerto/8.bmp", NULL);
	 fv[9] = load_bitmap("assets/gifs/gifAcerto/9.bmp", NULL);

		rest(50);
		frame_atual = (timerms / tempo_de_troca) % num_frames;

		draw_sprite(buffer, fv[frame_atual], 470, 350);

		if(mouse_b == 1){rest(100);escolhaFase(ps.playerFase, ps.playerMundo);}


	destroy_bitmap (fv[0]);
	destroy_bitmap (fv[1]);
	destroy_bitmap (fv[2]);
	destroy_bitmap (fv[3]);
	destroy_bitmap (fv[4]);
	destroy_bitmap (fv[5]);
	destroy_bitmap (fv[6]);
	destroy_bitmap (fv[7]);
	destroy_bitmap (fv[8]);
	destroy_bitmap (fv[9]);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int gifCaveira (BITMAP *buffer){
	int i=0;
	int num_frames = 9;
	int frame_atual = 0;
	int tempo_de_troca = 100;
	BITMAP* fv[9];

	 fv[0] = load_bitmap("assets/gifs/gifCaveira/gif_caveira1.bmp", NULL);
	 fv[1] = load_bitmap("assets/gifs/gifCaveira/gif_caveira2.bmp", NULL);
	 fv[2] = load_bitmap("assets/gifs/gifCaveira/gif_caveira3.bmp", NULL);
	 fv[3] = load_bitmap("assets/gifs/gifCaveira/gif_caveira4.bmp", NULL);
	 fv[4] = load_bitmap("assets/gifs/gifCaveira/gif_caveira5.bmp", NULL);
	 fv[5] = load_bitmap("assets/gifs/gifCaveira/gif_caveira6.bmp", NULL);
	 fv[6] = load_bitmap("assets/gifs/gifCaveira/gif_caveira7.bmp", NULL);
	 fv[7] = load_bitmap("assets/gifs/gifCaveira/gif_caveira8.bmp", NULL);
	 fv[8] = load_bitmap("assets/gifs/gifCaveira/gif_caveira9.bmp", NULL);

		rest(50);
		frame_atual = (timerms / tempo_de_troca) % num_frames;

		draw_sprite(buffer, fv[frame_atual], 400, 200);

		if(mouse_b==1){telaMenuPrincipal(buffer);}

	destroy_bitmap (fv[0]);
	destroy_bitmap (fv[1]);
	destroy_bitmap (fv[2]);
	destroy_bitmap (fv[3]);
	destroy_bitmap (fv[4]);
	destroy_bitmap (fv[5]);
	destroy_bitmap (fv[6]);
	destroy_bitmap (fv[7]);
	destroy_bitmap (fv[8]);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int gifTelafinal (BITMAP *buffer){
	int i=0;
	int num_frames = 6;
	int frame_atual = 0;
	int tempo_de_troca = 20;
	BITMAP* fv[6];

	 fv[0] = load_bitmap("assets/gifs/gifTelafinal/confetti0.bmp", NULL);
	 fv[1] = load_bitmap("assets/gifs/gifTelafinal/confetti1.bmp", NULL);
	 fv[2] = load_bitmap("assets/gifs/gifTelafinal/confetti2.bmp", NULL);
	 fv[3] = load_bitmap("assets/gifs/gifTelafinal/confetti3.bmp", NULL);
	 fv[4] = load_bitmap("assets/gifs/gifTelafinal/confetti4.bmp", NULL);
	 fv[5] = load_bitmap("assets/gifs/gifTelafinal/confetti5.bmp", NULL);

		rest(50);
		frame_atual = (timerms / tempo_de_troca) % num_frames;

		draw_sprite(buffer, fv[frame_atual], 470, 350);

		if(mouse_b==1){telaMenuPrincipal(buffer);}


	destroy_bitmap (fv[0]);
	destroy_bitmap (fv[1]);
	destroy_bitmap (fv[2]);
	destroy_bitmap (fv[3]);
	destroy_bitmap (fv[4]);
	destroy_bitmap (fv[5]);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 int gifGameOver (BITMAP *buffer){
	int i=0;
	int num_frames = 31;
	int frame_atual = 0;
	int tempo_de_troca = 250;
	int varLock = 0;

	BITMAP* fv[31];

	char *path;

    for(int i = 0; i < 31; i++){
        asprintf(&path, "assets/gifs/gifGameover/gameoverASKMATH%d.bmp", i);
        fv[i] = load_bitmap(path, NULL);
    }
		delay = timer;

		timerms = 0;

		while(!key[KEY_F10]){
			
		clear(buffer);
		if(key[KEY_ESC]) {telaMenuPrincipal(buffer);}
		if (varLock != 1){
			frame_atual = (timerms / tempo_de_troca) % num_frames;
			draw_sprite(buffer, fv[frame_atual], 0, 0);
			draw_sprite(screen, buffer, 0,0);
			}

			if (frame_atual==30){
				varLock = 1;
				if(mouse_b==1){telaMenuPrincipal(buffer);}
			}
		
		while(timer == delay){}
		clear(buffer);
		}

	for(int i = 0; i < 31; i++){
	destroy_bitmap (fv[i]);}

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
		textprintf_ex(screen,chalk,x,y,makecol(255,255,255), -1, "%c", var);

		//imprimindo letra por letra na tela do usuario
	}

	}
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int entraNome (BITMAP *buffer){
int x = 390, y = 220, i=0;

	BITMAP* fundo = load_bitmap("assets/telas/askmathCRIACAONOME.bmp", NULL);

		while(!key[KEY_F10])
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
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int telaMenuPrincipal(BITMAP *buffer){
	
int x = 0, y = 0, i;

	BITMAP* fundo = load_bitmap("assets/telas/askmathMENUPRINCIPAL.bmp", NULL);
	BITMAP* hover = load_bitmap("assets/telas/askmathHOVERMENUPRINCIPAL.bmp", NULL);
	firasans_16 = load_font("library/firasans16.pcx", NULL, NULL);
	
		while(!key[KEY_F10])
	{
		clear(buffer);
		delay = timer;

		if(key[KEY_ESC]) {telaInicial(buffer);}

		draw_sprite(buffer, fundo, 0, 0);//desenhando tela menu principal no buffer
		
		//BOTÃO CONTINUAR
		if(mouse_x > 52 && mouse_x <= 600 && //quando o mouser der hover aqui
		mouse_y > 40 && mouse_y <= 180){//aparece um tra�ado preto aqui
		draw_sprite(buffer, hover, 43, 40);
			if (mouse_b == 1){
				rest(100);
				 escolhaFase(ps.playerFase, ps.playerMundo);
				 rest(25);
			}
		}

		//BOTÃO PERSONAGEM
		if(mouse_x > 52 && mouse_x <= 600 && //quando o mouser der hover aqui
		mouse_y > 218 && mouse_y <= 340){//aparece um tra�ado preto aqui
		draw_sprite(buffer, hover, 43, 217);
		if (mouse_b == 1){
				rest(100);
				 telaSelecaoPers(buffer);
				 rest(25);
			}
		}

		//BOTÃO MUNDOS
		if(mouse_x > 52 && mouse_x <= 600 && //quando o mouser der hover aqui
		mouse_y > 396 && mouse_y <= 518){//aparece um tra�ado preto aqui
		draw_sprite(buffer, hover, 40, 391);
		if (mouse_b == 1){
				rest(100);
				 telaMundos(buffer);
				 rest(100);
			}
		}

		//BOTÃO SAIR
		if(mouse_x > 52 && mouse_x <= 600 && //quando o mouser der hover aqui
		mouse_y > 560 && mouse_y <= 696){//aparece um tra�ado preto aqui
		draw_sprite(buffer, hover, 42, 558);
			if (mouse_b == 1){
				 allegro_exit();
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
int telaMundos(BITMAP *buffer){
	
int x = 0, y = 0, i;

	BITMAP* fundo = load_bitmap("assets/telas/askmathMUNDOS.bmp", NULL);
	BITMAP* botao = load_bitmap("assets/telas/buttonmenuprincipal.bmp", NULL);
	
		while(!key[KEY_F10])
	{
		clear(buffer);
		delay = timer;

		if(key[KEY_ESC]) {telaInicial(buffer);}

		draw_sprite(buffer, fundo, 0, 0);//desenhando tela menu principal no buffer

		draw_sprite(buffer, botao, 5, 650);//desenhando botão que leva ao menu principal
		
		//BOTAO MENU PRINCIPAL
		if(mouse_x > 0 && mouse_x <= 437 && 
		mouse_y > 650 && mouse_y <= 709){
            if (mouse_b == 1){
				rest(250);
                telaMenuPrincipal(buffer);
                rest(250);
            }
		}

		//MUNDO 01
		if(mouse_x > 18 && mouse_x <= 247 && 
		mouse_y > 17 && mouse_y <= 244){//aparece um tra�ado preto aqui
			if (mouse_b == 1){
				rest(100);
				 fase01(buffer);
				 rest(100);
			}
		}

		//MUNDO 11
		if(mouse_x > 78 && mouse_x <= 195 && 
		mouse_y > 257 && mouse_y <= 375){//aparece um tra�ado preto aqui
			if (mouse_b == 1){
				rest(100);
				if(ps.playerFase>=1 && ps.playerMundo >= 1){
				 fase11(buffer);
				 rest(100);}
				 else{allegro_message("Você ainda não chegou nessa fase!");}
			}
		}

		//MUNDO 02
		if(mouse_x > 342 && mouse_x <= 572 && 
		mouse_y > 17 && mouse_y <= 244){
			if (mouse_b == 1){
				rest(100);
				if(ps.playerFase>=0 && ps.playerMundo >= 2){
				 fase02(buffer);
				 rest(100);}
				 else{allegro_message("Você ainda não chegou nessa fase!");}
			}
		}

		//MUNDO 12
		if(mouse_x > 396 && mouse_x <= 513 && 
		mouse_y > 257 && mouse_y <= 375){
			if (mouse_b == 1){
				rest(100);
				if(ps.playerFase>=1 && ps.playerMundo >= 2){
				fase12(buffer);
				rest(100);}
				else{allegro_message("Você ainda não chegou nessa fase!");}
			}
		}

		//MUNDO 22
		if(mouse_x > 396 && mouse_x <= 513 && 
		mouse_y > 370 && mouse_y <= 486){
			if (mouse_b == 1){
				rest(100);
				if(ps.playerFase>=2 && ps.playerMundo >= 2){
			 	fase22(buffer);
				 rest(100);}
				 else{allegro_message("Você ainda não chegou nessa fase!");}
			}
		}

		//MUNDO 03
		if(mouse_x > 667 && mouse_x <= 897 && 
		mouse_y > 17 && mouse_y <= 244){
			if (mouse_b == 1){
				rest(100);
				if(ps.playerFase>=0 && ps.playerMundo >= 3){
				 fase03(buffer);
				 rest(100);}
				 else{allegro_message("Você ainda não chegou nessa fase!");}
			}
		}
		
		//MUNDO 13
		if(mouse_x > 714 && mouse_x <= 831 && 
		mouse_y > 257 && mouse_y <= 370){
			if (mouse_b == 1){
				rest(100);
				if(ps.playerFase>=1 && ps.playerMundo >= 3){
				fase13(buffer);
				rest(100);}
				else{allegro_message("Você ainda não chegou nessa fase!");}
			}
		}

		//MUNDO 23
		if(mouse_x > 714 && mouse_x <= 831 && 
		mouse_y > 375 && mouse_y <= 486){
			if (mouse_b == 1){
				rest(100);
				if(ps.playerFase>=2 && ps.playerMundo >= 3){
				 fase23(buffer);
				 rest(100);}
				 else{allegro_message("Você ainda não chegou nessa fase!");}
			}
		}

		//MUNDO 33
		if(mouse_x > 714 && mouse_x <= 831 && 
		mouse_y > 492 && mouse_y <= 603){
			if (mouse_b == 1){
				rest(100);
				if(ps.playerFase>=3 && ps.playerMundo >= 3){
				fase33(buffer);
				rest(100);}
				else{allegro_message("Você ainda não chegou nessa fase!");}
			}
		}

		//MUNDO 04
		if(mouse_x > 992 && mouse_x <= 1222 && 
		mouse_y > 17 && mouse_y <= 244){
			if (mouse_b == 1){
				rest(100);
				if(ps.playerFase>=0 && ps.playerMundo >= 4){
				fase04(buffer);
				rest(100);}
				else{allegro_message("Você ainda não chegou nessa fase!");}
			}
		}

		//MUNDO 14
		if(mouse_x > 1032 && mouse_x <= 1149 && 
		mouse_y > 257 && mouse_y <= 370){
			if (mouse_b == 1){
				rest(100);
				if(ps.playerFase>=1 && ps.playerMundo >= 4){
				fase14(buffer);
				rest(100);}
				else{allegro_message("Você ainda não chegou nessa fase!");}
			}
		}

		//MUNDO 24
		if(mouse_x > 1032 && mouse_x <= 1149 && 
		mouse_y > 375 && mouse_y <= 486){
			if (mouse_b == 1){
				rest(100);
				if(ps.playerFase>=2 && ps.playerMundo >= 4){
				fase24(buffer);
				rest(100);}
				else{allegro_message("Você ainda não chegou nessa fase!");}
			}
		}

		//MUNDO 34
		if(mouse_x > 1032 && mouse_x <= 1149 && 
		mouse_y > 492 && mouse_y <= 603){
			if (mouse_b == 1){
				rest(100);
				if(ps.playerFase>=3 && ps.playerMundo >= 4){
				 fase34(buffer);
				 rest(100);}
				 else{allegro_message("Você ainda não chegou nessa fase!");}
			}
		}

		//MUNDO 44
		if(mouse_x > 1032 && mouse_x <= 1149 && 
		mouse_y > 610 && mouse_y <= 721){
			if (mouse_b == 1){
				rest(100);
				if(ps.playerFase>=4 && ps.playerMundo >= 4){
				fase44(buffer);
				rest(100);}
				else{allegro_message("Você ainda não chegou nessa fase!");}
			}
		}

		
		
		mouse(buffer);//importando a fun��o mouse em baixo de tela para ele sobrepor a tela do menu principal
		

		draw_sprite(screen, buffer, 0,0);//desenhando o buffer na screen
		
		while(timer == delay){}
		clear(buffer);
		
	}

	destroy_bitmap(fundo);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int contadorCoracao(BITMAP *buffer){

int x = 219, y = 10, i;

	BITMAP* tresCoracao = load_bitmap("assets/telas/3coracoes.bmp", NULL);
	BITMAP* doisCoracao = load_bitmap("assets/telas/2coracoes.bmp", NULL);
	BITMAP* umCoracao = load_bitmap("assets/telas/1coracoes.bmp", NULL);
	
	BITMAP* coracaoQuebrado = load_bitmap("assets/telas/0coracoes.bmp", NULL);

	switch(ps.playerCoracao){
		case 0:
			gifGameOver(buffer);//desenhando tela menu principal no buffer
			break;

		case 1:
			draw_sprite(buffer, umCoracao, x, y);//desenhando tela menu principal no buffer
			break;

		case 2:
			draw_sprite(buffer, doisCoracao, x, y);//desenhando tela menu principal no buffer
			break;

		case 3:
			draw_sprite(buffer, tresCoracao, x, y);//desenhando tela menu principal no buffer
			break;
	}
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int telaFinal(BITMAP *buffer){
	int x = 0, y = 0, i=0;

	BITMAP* fundo = load_bitmap("assets/telas/askmathTELAFINAL.bmp", NULL);
	
		while(!key[KEY_ESC])
	{
		clear(buffer);
		delay = timer;
		draw_sprite(buffer, fundo, 0, 0);//desenhando tela menu principal no buffer
		
		gifTelafinal(buffer);

		mouse(buffer);//importando a fun��o mouse em baixo de tela para ele sobrepor a tela do menu principal
		
		draw_sprite(screen, buffer, 0,0);//desenhando o buffer na screen
		
		while(timer == delay){}
		clear(buffer);
		
}
	destroy_bitmap(fundo);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int telaCredtios (BITMAP* buffer){
int x = 0, y = 0, i=0;

	BITMAP* fundo = load_bitmap("assets/telas/askmathTELACREDITOS.bmp", NULL);
	
		while(!key[KEY_F10])
	{
		if(key[KEY_ESC]) {telaInicial(buffer);}

		clear(buffer);
		delay = timer;
		draw_sprite(buffer, fundo, 0, 0);//desenhando tela menu principal no buffer
		
		if(mouse_x > 20 && mouse_x <= 455 && 
		mouse_y > 646 && mouse_y <= 715){
			if (mouse_b == 1){telaInicial(buffer);}
			rest(25);
			}

		if(mouse_x > 586 && mouse_x <= 1267 && 
		mouse_y > 646 && mouse_y <= 715){
			if (mouse_b == 1){telaAgradecimentos(buffer);}
			rest(25);
			}

		mouse(buffer);//importando a fun��o mouse em baixo de tela para ele sobrepor a tela do menu principal
		
		draw_sprite(screen, buffer, 0,0);//desenhando o buffer na screen
		
		while(timer == delay){}
		clear(buffer);
		
}
	destroy_bitmap(fundo);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int telaAgradecimentos (BITMAP* buffer){
int x = 0, y = 0, i=0;

	BITMAP* fundo = load_bitmap("assets/telas/askmathTELACREDITOS2.bmp", NULL);
	
		while(!key[KEY_F10])
	{
		if(key[KEY_ESC]) {telaInicial(buffer);}

		clear(buffer);
		delay = timer;
		draw_sprite(buffer, fundo, 0, 0);//desenhando tela menu principal no buffer
		
		if(mouse_x > 20 && mouse_x <= 455 && 
		mouse_y > 646 && mouse_y <= 715){
			if (mouse_b == 1){telaInicial(buffer);}
			rest(50);
			}

		mouse(buffer);//importando a fun��o mouse em baixo de tela para ele sobrepor a tela do menu principal
		
		draw_sprite(screen, buffer, 0,0);//desenhando o buffer na screen
		
		while(timer == delay){}
		clear(buffer);
		
}
	destroy_bitmap(fundo);
}

#endif