#include <allegro.h>

int main (){
	//INSTALAÇÕES
	allegro_init();
	install_timer();
	install_mouse();
	install_keyboard();
	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
	set_window_title("Teste Allegro");
	install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
	
	//BITMAPS
	int x = 100, y = 100, i;
	BITMAP* buffer = create_bitmap(800,600);
	BITMAP* imagem = load_bitmap("imagem.bmp", NULL);
	BITMAP* fundo = load_bitmap("fundo.bmp", NULL);
	BITMAP* ponteiro = load_bitmap("ponteiro.bmp", NULL);
	BITMAP* ponteiro3 = load_bitmap("ponteiro3.bmp", NULL);
	
	//SONS
	SAMPLE *wave = load_sample("fundomusica.wav");
	play_sample(wave, 255, 128, 1000, 1);
	
	//WHILE DE JOGO
	while(!key[KEY_ESC])
	{
	//	show_mouse(screen);
		textprintf_ex(screen, font, 200, 200, makecol(200,200,200), -1, "mx %i my %i", mouse_x, mouse_y);
		textprintf_ex(screen, font, 400, 400, makecol(400,400,400), -1, "mouse click %i", mouse_b);
			
		if (key[KEY_LEFT])x -= 5;
		if (key[KEY_RIGHT])x += 5;
		if (key[KEY_DOWN])y += 5;
		if (key[KEY_UP])y -= 5;
	
		draw_sprite(buffer, fundo, 0, 0);
		draw_sprite(buffer, imagem, 100+x, 125+y);
		if(mouse_b == 2){
				draw_sprite(buffer, ponteiro3, mouse_x, mouse_y);
			}
		draw_sprite(buffer, ponteiro, mouse_x, mouse_y);
		draw_sprite(screen, buffer, 0, 0);
		//rest(10);
		clear(buffer);
	
	}
	destroy_bitmap(buffer);
	destroy_bitmap(imagem);
	destroy_bitmap(fundo);
	destroy_bitmap(ponteiro);
	destroy_bitmap(ponteiro3);
	destroy_sample(wave);
	return 0;
}
END_OF_MAIN();
