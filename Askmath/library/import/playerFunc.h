#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>
#include "playerStatus.h"
#include "utilityFunc.h"
#ifndef _playerFuncsH_
#define _playerFuncsH_

int slotLivre = 1;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void saveState(){//sub-rotina para salvar os status atuais do jogador

	FILE* output;//ponteiro output para a função FILE

	switch (ps.playerNumero){
		case '1':
			output = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Askmath\\assets\\Players\\playerUm.txt", "w");
			//abrindo o txt playerUm no modo "write"

			fprintf(output, "playerNome=%s\nplayerXp=%d\nplayerNivel=%d\nplayerIdade=%d\nplayerMundo=%d\nplayerFase=%d\n",ps.playerNome,ps.playerXp, ps.playerNivel, ps.playerIdade,ps.playerMundo,ps.playerFase);//escrevendo os dados dentro do txt

			fclose(output);
			break;

		case '2':
			output = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Askmath\\assets\\Players\\playerDois.txt", "w");
			//abrindo o txt playerDois no modo "write"

			fprintf(output, "playerNome=%s\nplayerXp=%d\nplayerNivel=%d\nplayerIdade=%d\nplayerMundo=%d\nplayerFase=%d\n",ps.playerNome,ps.playerXp, ps.playerNivel, ps.playerIdade,ps.playerMundo,ps.playerFase);//escrevendo os dados dentro do txt
			
			fclose(output);
			break;

		case '3':
			output = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Askmath\\assets\\Players\\playerTres.txt", "w");
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
				input = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Askmath\\assets\\Players\\playerUm.txt", "r");
				//abrindo o txt playerUm no modo "read"

				fscanf(input, "playerNome=%s\nplayerXp=%d\nplayerNivel=%d\nplayerIdade=%d\nplayerMundo=%d\nplayerFase=%d\n",&ps.playerNome,&ps.playerXp, &ps.playerNivel, &ps.playerIdade,&ps.playerMundo,&ps.playerFase);
				//lendo os dados dentro do txt e atribuindo seus valores para dentro da struct playerStatus
				
				if (ps.playerIdade > 0){
				slotLivre = 0;}
		
				fclose(input);
				break;

			case '2':
				input = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Askmath\\assets\\Players\\playerDois.txt", "r");
				//abrindo o txt playerDois no modo "read"

				fscanf(input, "playerNome=%s\nplayerXp=%d\nplayerNivel=%d\nplayerIdade=%d\nplayerMundo=%d\nplayerFase=%d\n",&ps.playerNome,&ps.playerXp, &ps.playerNivel, &ps.playerIdade,&ps.playerMundo,&ps.playerFase);
				//lendo os dados dentro do txt e atribuindo seus valores para dentro da struct playerStatus
				
				if (ps.playerIdade > 0){
				slotLivre = 0;}

				fclose(input);
				break;

			case '3':
				input = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Askmath\\assets\\Players\\playerTres.txt", "r");
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
void selecaoPers(void) {

   FILE * input; //ponteiro input para a função FILE

		input = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Askmath\\assets\\Players\\playerUm.txt", "r");
		//abrindo o txt playerUm no modo "read"

			fscanf(input, "playerNome=%s\nplayerXp=%d\nplayerNivel=%d\nplayerIdade=%d\nplayerMundo=%d\nplayerFase=%d\n",&ps.playerNome,&ps.playerXp, &ps.playerNivel, &ps.playerIdade,&ps.playerMundo,&ps.playerFase);
				//lendo os dados dentro do txt e atribuindo seus valores para dentro da struct playerStatus

			if (ps.playerIdade > 0){//!Verificando se o save game existe a partir da idade que o jogador ofereca, caso ela seja 0, o save nao existe.
			printf("%s\t%4s%s\n\t%4s%i\n\t%4s%i\n\t%4s%i\n\t%4s%i\n\t%4s%i","   1 - ", "Nome: ", ps.playerNome, "Xp: ", ps.playerXp, "Nivel: ", ps.playerNivel, "Idade: ", ps.playerIdade, "Mundo: ", ps.playerMundo, "Fase: ", ps.playerFase); //!Printando as informações do player Um uma por uma
			}
			else {
				printf("%s\t%4s\n","   1 - ", "Slot livre");//!Caso nao exista o save, irá aparecer slot livre
			}

			pulaLinha(3);
		fclose(input);

		input = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Askmath\\assets\\Players\\playerDois.txt", "r");
		//abrindo o txt playerDois no modo "read"

			fscanf(input, "playerNome=%s\nplayerXp=%d\nplayerNivel=%d\nplayerIdade=%d\nplayerMundo=%d\nplayerFase=%d\n",&ps.playerNome,&ps.playerXp, &ps.playerNivel, &ps.playerIdade,&ps.playerMundo,&ps.playerFase);
				//lendo os dados dentro do txt e atribuindo seus valores para dentro da struct playerStatus

			if (ps.playerIdade > 0){//!Verificando se o save game existe a partir da idade que o jogador ofereca, caso ela seja 0, o save nao existe.

			printf("%s\t%4s%s\n\t%4s%i\n\t%4s%i\n\t%4s%i\n\t%4s%i\n\t%4s%i","   2 - ", "Nome: ", ps.playerNome, "Xp: ", ps.playerXp, "Nivel: ", ps.playerNivel, "Idade: ", ps.playerIdade, "Mundo: ", ps.playerMundo, "Fase: ", ps.playerFase); //!Printando as informações do player Dois uma por uma
			}
			else {
				printf("%s\t%4s\n","   2 - ", "Slot livre");
			}

			pulaLinha(3);
		fclose(input);

		input = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Askmath\\assets\\Players\\playerTres.txt", "r");
		//abrindo o txt playerTres no modo "read"

			fscanf(input, "playerNome=%s\nplayerXp=%d\nplayerNivel=%d\nplayerIdade=%d\nplayerMundo=%d\nplayerFase=%d\n",&ps.playerNome,&ps.playerXp, &ps.playerNivel, &ps.playerIdade,&ps.playerMundo,&ps.playerFase);
				//lendo os dados dentro do txt e atribuindo seus valores para dentro da struct playerStatus

			if (ps.playerIdade > 0){//!Verificando se o save game existe a partir da idade que o jogador ofereca, caso ela seja 0, o save nao existe.

			printf("%s\t%4s%s\n\t%4s%i\n\t%4s%i\n\t%4s%i\n\t%4s%i\n\t%4s%i","   3 - ", "Nome: ", ps.playerNome, "Xp: ", ps.playerXp, "Nivel: ", ps.playerNivel, "Idade: ", ps.playerIdade, "Mundo: ", ps.playerMundo, "Fase: ", ps.playerFase); //!Printando as informações do player Tres uma por uma
			}
			else {
				printf("%s\t%4s\n","   3 - ", "Slot livre");
			}

			pulaLinha(3);
		fclose(input);
}


#endif