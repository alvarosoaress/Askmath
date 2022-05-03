#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>
#include <allegro.h>

#include <unistd.h>
#include <limits.h>

#include "playerStatus.h"
#include "utilityFunc.h"

#ifndef _playerFuncsH_
#define _playerFuncsH_

FONT *ubuntu_12;

int slotLivre = 1;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void saveState(){//sub-rotina para salvar os status atuais do jogador

	FILE* output;//ponteiro output para a função FILE

	switch (ps.playerNumero){
		case '1':
			output = fopen("assets/Players/playerUm.txt", "w");
			//abrindo o txt playerUm no modo "write"

			fprintf(output, "playerNome=%s\nplayerXp=%d\nplayerNivel=%d\nplayerIdade=%d\nplayerMundo=%d\nplayerFase=%d\n",ps.playerNome,ps.playerXp, ps.playerNivel, ps.playerIdade,ps.playerMundo,ps.playerFase);//escrevendo os dados dentro do txt

			fclose(output);
			break;

		case '2':
			output = fopen("assets/Players/playerDois.txt", "w");
			//abrindo o txt playerDois no modo "write"

			fprintf(output, "playerNome=%s\nplayerXp=%d\nplayerNivel=%d\nplayerIdade=%d\nplayerMundo=%d\nplayerFase=%d\n",ps.playerNome,ps.playerXp, ps.playerNivel, ps.playerIdade,ps.playerMundo,ps.playerFase);//escrevendo os dados dentro do txt
			
			fclose(output);
			break;

		case '3':
			output = fopen("assets/Players/playerTres.txt", "w");
			//abrindo o txt playerTres no modo "write"

			fprintf(output, "playerNome=%s\nplayerXp=%d\nplayerNivel=%d\nplayerIdade=%d\nplayerMundo=%d\nplayerFase=%d\n",ps.playerNome,ps.playerXp, ps.playerNivel, ps.playerIdade,ps.playerMundo,ps.playerFase);//escrevendo os dados dentro do txt
			
			fclose(output);
			break;

		default :
    		printf ("Opcao invalida, digite um numero de 1 a 3!\n");
			}

}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void loadState(){//sub-rotina para carregar os status atuais do jogador

	FILE* input;//ponteiro input para a função FILE

		switch (ps.playerNumero){
			case '1':
				input = fopen("assets/Players/playerUm.txt", "r");
				//abrindo o txt playerUm no modo "read"
				if(input==NULL)
				    {
				        printf("Error! Can't find file!\n");
				    }
				 char cwd[PATH_MAX];
				   if (getcwd(cwd, sizeof(cwd)) != NULL) {
				       printf("Current working dir: %s\n", cwd);
				   } else {
				       perror("getcwd() error");
				   }
				fscanf(input, "playerNome=%s\nplayerXp=%d\nplayerNivel=%d\nplayerIdade=%d\nplayerMundo=%d\nplayerFase=%d\n",&ps.playerNome,&ps.playerXp, &ps.playerNivel, &ps.playerIdade,&ps.playerMundo,&ps.playerFase);
				//lendo os dados dentro do txt e atribuindo seus valores para dentro da struct playerStatus
				
				if (ps.playerIdade > 0){
				slotLivre = 0;}
		
				fclose(input);
				break;

			case '2':
				input = fopen("assets/Players/playerDois.txt", "r");
				//abrindo o txt playerDois no modo "read"

				fscanf(input, "playerNome=%s\nplayerXp=%d\nplayerNivel=%d\nplayerIdade=%d\nplayerMundo=%d\nplayerFase=%d\n",&ps.playerNome,&ps.playerXp, &ps.playerNivel, &ps.playerIdade,&ps.playerMundo,&ps.playerFase);
				//lendo os dados dentro do txt e atribuindo seus valores para dentro da struct playerStatus
				
				if (ps.playerIdade > 0){
				slotLivre = 0;}

				fclose(input);
				break;

			case '3':
				input = fopen("assets/Players/playerTres.txt", "r");
				//abrindo o txt playerTres no modo "read"

				fscanf(input, "playerNome=%s\nplayerXp=%d\nplayerNivel=%d\nplayerIdade=%d\nplayerMundo=%d\nplayerFase=%d\n",&ps.playerNome,&ps.playerXp, &ps.playerNivel, &ps.playerIdade,&ps.playerMundo,&ps.playerFase);
				//lendo os dados dentro do txt e atribuindo seus valores para dentro da struct playerStatus
				
				if (ps.playerIdade > 0){
				slotLivre = 0;}

				fclose(input);
				break;

			default :
    			printf ("Opcao invalida, digite um numero de 1 a 3!\n");
				}

	fclose(input);
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void selecaoPers(BITMAP *buffer) {
	ubuntu_12 = load_font("library/space_mono.pcx", NULL, NULL);
   FILE * input; //ponteiro input para a função FILE

		input = fopen("assets/Players/playerUm.txt", "r");
		//abrindo o txt playerUm no modo "read"

			fscanf(input, "playerNome=%s\nplayerXp=%d\nplayerNivel=%d\nplayerIdade=%d\nplayerMundo=%d\nplayerFase=%d\n",&ps.playerNome,&ps.playerXp, &ps.playerNivel, &ps.playerIdade,&ps.playerMundo,&ps.playerFase);
				//lendo os dados dentro do txt e atribuindo seus valores para dentro da struct playerStatus

			if (ps.playerIdade > 0){//!Verificando se o save game existe a partir da idade que o jogador ofereca, caso ela seja 0, o save nao existe.
			// PLAYER 1 
			textprintf_ex(buffer, ubuntu_12, 80,300,makecol(255,0,0), -1,"%4s%s", "Nome: ", ps.playerNome);
			textprintf_ex(buffer, ubuntu_12, 50,355,makecol(255,0,0), -1,"%4s%i","Xp: ", ps.playerXp);
			textprintf_ex(buffer, ubuntu_12, 50,410,makecol(255,0,0), -1,"%4s%i","Nivel: ", ps.playerNivel);
			textprintf_ex(buffer, ubuntu_12, 50,465,makecol(255,0,0), -1,"%4s%i","Idade: ", ps.playerIdade);
			textprintf_ex(buffer, ubuntu_12, 50,515,makecol(255,0,0), -1,"%4s%i","Mundo: ", ps.playerMundo);
			textprintf_ex(buffer, ubuntu_12, 50,565,makecol(255,0,0), -1,"%4s%i","Fase: ", ps.playerFase);
			// PLAYER 1  //!Printando as informações do player Um uma por uma
			}
			else {
				textprintf_ex(buffer, ubuntu_12, 80,300,makecol(255,0,0), -1,"%s%4s","1 - ", "Slot livre");//!Caso nao exista o save, irá aparecer slot livre
			}

			pulaLinha(3);
		fclose(input);

		input = fopen("assets/Players/playerDois.txt", "r");
		//abrindo o txt playerDois no modo "read"

			fscanf(input, "playerNome=%s\nplayerXp=%d\nplayerNivel=%d\nplayerIdade=%d\nplayerMundo=%d\nplayerFase=%d\n",&ps.playerNome,&ps.playerXp, &ps.playerNivel, &ps.playerIdade,&ps.playerMundo,&ps.playerFase);
				//lendo os dados dentro do txt e atribuindo seus valores para dentro da struct playerStatus

			if (ps.playerIdade > 0){//!Verificando se o save game existe a partir da idade que o jogador ofereca, caso ela seja 0, o save nao existe.

			// PLAYER 2 
			textprintf_ex(buffer, ubuntu_12, 500,300,makecol(204,204,0), -1,"%4s%s", "Nome: ", ps.playerNome);
			textprintf_ex(buffer, ubuntu_12, 470,355,makecol(204,204,0), -1,"%4s%i","Xp: ", ps.playerXp);
			textprintf_ex(buffer, ubuntu_12, 470,410,makecol(204,204,0), -1,"%4s%i","Nivel: ", ps.playerNivel);
			textprintf_ex(buffer, ubuntu_12, 470,465,makecol(204,204,0), -1,"%4s%i","Idade: ", ps.playerIdade);
			textprintf_ex(buffer, ubuntu_12, 470,515,makecol(204,204,0), -1,"%4s%i","Mundo: ", ps.playerMundo);
			textprintf_ex(buffer, ubuntu_12, 470,565,makecol(204,204,0), -1,"%4s%i","Fase: ", ps.playerFase);
			// PLAYER 2  //!Printando as informações do player Dois uma por uma
			}
			else {
				textprintf_ex(buffer, ubuntu_12, 500,300,makecol(204,204,0), -1,"%s%4s","2 - ", "Slot livre");
			}

			pulaLinha(3);
		fclose(input);

		input = fopen("assets/Players/playerTres.txt", "r");
		//abrindo o txt playerTres no modo "read"

			fscanf(input, "playerNome=%s\nplayerXp=%d\nplayerNivel=%d\nplayerIdade=%d\nplayerMundo=%d\nplayerFase=%d\n",&ps.playerNome,&ps.playerXp, &ps.playerNivel, &ps.playerIdade,&ps.playerMundo,&ps.playerFase);
				//lendo os dados dentro do txt e atribuindo seus valores para dentro da struct playerStatus

			if (ps.playerIdade > 0){//!Verificando se o save game existe a partir da idade que o jogador ofereca, caso ela seja 0, o save nao existe.

			// PLAYER 3
			textprintf_ex(buffer, ubuntu_12, 920,300,makecol(0,204,204), -1,"%4s%s", "Nome: ", ps.playerNome);
			textprintf_ex(buffer, ubuntu_12, 890,355,makecol(0,204,204), -1,"%4s%i","Xp: ", ps.playerXp);
			textprintf_ex(buffer, ubuntu_12, 890,410,makecol(0,204,204), -1,"%4s%i","Nivel: ", ps.playerNivel);
			textprintf_ex(buffer, ubuntu_12, 890,465,makecol(0,204,204), -1,"%4s%i","Idade: ", ps.playerIdade);
			textprintf_ex(buffer, ubuntu_12, 890,515,makecol(0,204,204), -1,"%4s%i","Mundo: ", ps.playerMundo);
			textprintf_ex(buffer, ubuntu_12, 890,565,makecol(0,204,204), -1,"%4s%i","Fase: ", ps.playerFase);
			// PLAYER 3 //!Printando as informações do player Tres uma por uma
			}
			else {
				textprintf_ex(buffer, ubuntu_12, 920,300,makecol(0,204,204), -1,"%s%4s","3 - ", "Slot livre");
			}

			pulaLinha(3);
		fclose(input);

	destroy_font(ubuntu_12);
}


#endif