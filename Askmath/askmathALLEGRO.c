#include <allegro.h>
#include <stdlib.h>
#include <stdio.h>
#include "library\utilityFunc.h"
#include "library\funcs.h"
#include "library\playerStatus.h"
#include "library\playerFunc.h"
#include "library\fases.h"
#include <winalleg.h> //SALVA VIDAS <3

//INT MAIN
int main (){
	allegro_init();
	install_timer();
	install_int_ex(tempo, MSEC_TO_TIMER(1));//16ms de frame time = 60 fps
	install_int_ex(segundos, SECS_TO_TIMER(1));// contando 1 seg a cada 1 seg para o "relogio"
	install_int_ex(tempoms, MSEC_TO_TIMER(1));// contando 1 seg a cada 1 seg para o "relogio"
	install_mouse();
	install_keyboard();
	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1280, 720, 0, 0);// TAMANHO DA JANELA
	set_window_title("Askmath");// TITULO DA JANELA
	install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
	
	
	//VARIAVEIS

	//MUSICAS

	//DETERMINANDO NOME DA VARIAVEL PARA TOCAR A MUSICA E O LOCAL DELA
	SAMPLE *wave = load_sample("assets/musicas/fundomusica.wav");
	
	//TOCANDO A MUSICA 24/7
	//play_sample(wave, 255, 128, 1000, 1);
	
	//CRIANDO BUFFER PRO JOGO INTEIRO
	BITMAP* buffer = create_bitmap(1280,720);

	telaInicial(buffer);
	
	destroy_sample(wave);
	return 0;
}
END_OF_MAIN();


	
