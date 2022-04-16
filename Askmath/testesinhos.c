//Askmath

//Include das bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>

//Funcoes
void pulaLinha (int l);
void espTab (int t);
void telaInicial (void);
void telaPrincipal (void);
void opcaoUm (void);
void telaSelecaoPers(void);
void selecaoPers(void);
void jogoInicio (void);
void jogoInicio2 (void);
void jogoInicio3 (void);
void jogoCreditos (void);
void jogoSair (void);
void saveState (void);
void loadState (void);


//Variaveis globais
struct playerStatus{
	char playerNome [50];
	int playerNumero, playerXp, playerNivel, playerIdade, playerFase, playerSlot;
};

struct playerStatus ps;

//TODO tentar trocar de VAR para algum de tipo "matriz função" tipo void jogoFase[12][5] (void);
int jogoFase[12][5];/*Um máximo de 12 fases e 5 mundos (1 mundo - 3 fases) (2 mundo - 5 fases) (3 mundo - 8 fases)
(4 mundo - 10 fases) (5 mundo - 12 fases) */


//Int Main
int main(){

	char escolha;//escolha que o jogador ira fazer na telaPrincipal
	ps.playerNumero = '1';//!MUDAR ISSO
	loadState();
	telaInicial();
	
	printf("%s", ps.playerNome);
	getchar();

	
	system("cls");
	telaPrincipal();
	
	
	escolha = getch();

	system("cls");

	switch (escolha){//escolhendo qual opcao o jogador deseja
		case '1':
			opcaoUm();
			break;

		case '2' :
			jogoCreditos();
			break;
			
		case '3':
			jogoSair();
			break;

		default :
    		printf ("Opcao invalida, digite um numero de 1 a 3!\n");
			}
	pulaLinha(15);
	saveState();

	
	
	getchar();
	return 0;
}
//=======================================================================================
void opcaoUm (void){

jogoInicio();
jogoInicio2();
jogoInicio3();
telaSelecaoPers();
selecaoPers();
}
//=======================================================================================
void pulaLinha (int l){
int i=0;
	for ( i = 0; i < l; i++){//For para pular linhas e deixar a caixa de texto no final do terminal
		printf("\n");
	}
}
//=======================================================================================
void espTab (int t){
int i=0;
	for ( i = 0; i < t; i++){//For para dar espaço antes das linhas (msm coisa de \t)
		printf("\t");
	}
}

//=======================================================================================
void telaInicial (void){//Tela Inicial do nosso jogo (ainda sem as opções de escolha)
	
	char carac [100][100];

	FILE *file;//Ponteiro da função FILE para o nome "file"
	file = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Askmath\\assets\\Telas\\telaInicial.txt", "r");/*Função fopen
	para abrir o arquivo txt que está localizado a ASCII art da tela inicial*/

	while(fgets(carac, 100, file) != NULL){//printando o txt na tela do usuário
		printf("\t%s", carac);// o /t para tentar centralizar o desenho
	}

	fclose(file);//fechando o arquivo e liberando memória após seu uso
}

//=======================================================================================
void telaPrincipal (void){// Tela principal do jogo contendo 1-Jogar 2-Creditos 3-Sair

	char carac [100][100];

	FILE *file;
	file = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Askmath\\assets\\Telas\\telaPrincipal.txt", "r");
	while(fgets(carac, 100, file) != NULL){
		printf("\t%s", carac);
	}
	fclose(file);
}
//=======================================================================================
void telaSelecaoPers(void){
	system("cls");
	char carac [100][100];
	FILE *file;
	file = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Askmath\\assets\\Telas\\selecaoPers.txt", "r");//abrindo a tela inicial do jogo
	
	while(fgets(carac, 100, file) != NULL){
		printf("\t%s", carac);
	}

	pulaLinha (3);//sub rotina para pular linha a partir de um numero inteiro que eu escolher
	fclose(file);
	getchar();
}
//=======================================================================================
//Askmath

//Include das bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>

//Funcoes
void pulaLinha (int l);
void espTab (int t);
void telaInicial (void);
void telaPrincipal (void);
void opcaoUm (void);
void telaSelecaoPers(void);
void selecaoPers(void);
void jogoInicio (void);
void jogoInicio2 (void);
void jogoInicio3 (void);
void jogoCreditos (void);
void jogoSair (void);
void saveState (void);
void loadState (void);


//Variaveis globais
struct playerStatus{
	char playerNome [50];
	int playerNumero, playerXp, playerNivel, playerIdade, playerFase, playerSlot;
};

struct playerStatus ps;

//TODO tentar trocar de VAR para algum de tipo "matriz função" tipo void jogoFase[12][5] (void);
int jogoFase[12][5];/*Um máximo de 12 fases e 5 mundos (1 mundo - 3 fases) (2 mundo - 5 fases) (3 mundo - 8 fases)
(4 mundo - 10 fases) (5 mundo - 12 fases) */


//Int Main
int main(){

	char escolha;//escolha que o jogador ira fazer na telaPrincipal
	ps.playerNumero = '1';//!MUDAR ISSO
	loadState();
	telaInicial();
	
	//printf("%s", ps.playerNome);
	getchar();

	
	system("cls");
	telaPrincipal();
	
	
	escolha = getch();

	system("cls");

	switch (escolha){//escolhendo qual opcao o jogador deseja
		case '1':
			opcaoUm();
			break;

		case '2' :
			jogoCreditos();
			break;
			
		case '3':
			jogoSair();
			break;

		default :
    		printf ("Opcao invalida, digite um numero de 1 a 3!\n");
			}
	pulaLinha(15);

	
	
	getchar();
	return 0;
}
//=======================================================================================
void opcaoUm (void){

jogoInicio();
jogoInicio2();
jogoInicio3();
telaSelecaoPers();
selecaoPers();
}
//=======================================================================================
pulaLinha (int l){
int i=0;
	for ( i = 0; i < l; i++){//For para pular linhas e deixar a caixa de texto no final do terminal
		printf("\n");
	}
}
//=======================================================================================
espTab (int t){
int i=0;
	for ( i = 0; i < t; i++){//For para dar espaço antes das linhas (msm coisa de \t)
		printf("\t");
	}
}

//=======================================================================================
void telaInicial (void){//Tela Inicial do nosso jogo (ainda sem as opções de escolha)
	
	char carac [100][100];

	FILE *file;//Ponteiro da função FILE para o nome "file"
	file = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Askmath\\assets\\Telas\\telaInicial.txt", "r");/*Função fopen
	para abrir o arquivo txt que está localizado a ASCII art da tela inicial*/

	while(fgets(carac, 100, file) != NULL){//printando o txt na tela do usuário
		printf("\t%s", carac);// o /t para tentar centralizar o desenho
	}

	fclose(file);//fechando o arquivo e liberando memória após seu uso
}

//=======================================================================================
void telaPrincipal (void){// Tela principal do jogo contendo 1-Jogar 2-Creditos 3-Sair

	char carac [100][100];

	FILE *file;
	file = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Askmath\\assets\\Telas\\telaPrincipal.txt", "r");
	while(fgets(carac, 100, file) != NULL){
		printf("\t%s", carac);
	}
	fclose(file);
}
//=======================================================================================
void telaSelecaoPers(void){
	system("cls");
	char carac [100][100];
	FILE *file;
	file = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Askmath\\assets\\Telas\\selecaoPers.txt", "r");//abrindo a tela inicial do jogo
	
	while(fgets(carac, 100, file) != NULL){
		printf("\t%s", carac);
	}

	pulaLinha (3);//sub rotina para pular linha a partir de um numero inteiro que eu escolher
	fclose(file);
	getchar();
}
//=======================================================================================
void selecaoPers(void) {

   FILE * input; //ponteiro input para a função FILE

		input = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Askmath\\assets\\Players\\playerUm.txt", "r");
		//abrindo o txt playerUm no modo "read"

			fscanf(input, "playerNome=%s\nplayerXp=%d\nplayerNivel=%d\nplayerIdade=%d\nplayerFase=%d\nplayerSlot=%d\n", & ps.playerNome, & ps.playerXp, & ps.playerNivel, & ps.playerIdade, & ps.playerFase, &ps.playerSlot);
			//lendo os dados dentro do txt e atribuindo seus valores para dentro da struct playerStatus
			if (ps.playerSlot = 1){
			printf("\t%4s%s\n\t%4s%i\n\t%4s%i\n\t%4s%i\n\t%4s%i", "Nome: ", ps.playerNome, "Xp: ", ps.playerXp, "Nivel: ", ps.playerNivel, "Idade: ", ps.playerIdade, "Fase: ", ps.playerFase); //!Printando as informações do player Um uma por uma
			}
			else {
				printf("\t%4s\n", "Slot livre");
			}

			pulaLinha(3);
		fclose(input);

		input = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Askmath\\assets\\Players\\playerDois.txt", "r");
		//abrindo o txt playerDois no modo "read"

			fscanf(input, "playerNome=%s\nplayerXp=%d\nplayerNivel=%d\nplayerIdade=%d\nplayerFase=%d\nplayerSlot=%d\n", & ps.playerNome, & ps.playerXp, & ps.playerNivel, & ps.playerIdade, & ps.playerFase, &ps.playerSlot);
			//lendo os dados dentro do txt e atribuindo seus valores para dentro da struct playerStatus

			printf("\t%4s%s\n\t%4s%i\n\t%4s%i\n\t%4s%i\n\t%4s%i", "Nome: ", ps.playerNome, "Xp: ", ps.playerXp, "Nivel: ", ps.playerNivel, "Idade: ", ps.playerIdade, "Fase: ", ps.playerFase); //!Printando as informações do player Dois

			pulaLinha(3);
		fclose(input);

		input = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Askmath\\assets\\Players\\playerTres.txt", "r");
		//abrindo o txt playerTres no modo "read"

			fscanf(input, "playerNome=%s\nplayerXp=%d\nplayerNivel=%d\nplayerIdade=%d\nplayerFase=%d\nplayerSlot=%d\n", & ps.playerNome, & ps.playerXp, & ps.playerNivel, & ps.playerIdade, & ps.playerFase, &ps.playerSlot);
			//lendo os dados dentro do txt e atribuindo seus valores para dentro da struct playerStatus

			printf("\t%4s%s\n\t%4s%i\n\t%4s%i\n\t%4s%i\n\t%4s%i", "Nome: ", ps.playerNome, "Xp: ", ps.playerXp, "Nivel: ", ps.playerNivel, "Idade: ", ps.playerIdade, "Fase: ", ps.playerFase); //!Printando as informações do player Tres

			pulaLinha(3);
		fclose(input);
}
//=======================================================================================
void jogoInicio (void){

	char carac [100][100];

	FILE *file;
	file = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Askmath\\assets\\Telas\\jogoInicio.txt", "r");//abrindo a tela inicial do jogo
	
	pulaLinha (25);//sub rotina para pular linha a partir de um numero inteiro que eu escolher

	while(fgets(carac, 100, file) != NULL){
		printf("\t\t\t%s", carac);
	}

	pulaLinha (1);
	espTab (5);
	//fgets(ps.playerNome,50,stdin);
	printf("%s", ps.playerNome);
	fclose(file);
}
//=======================================================================================
void jogoInicio2 (void){
	system("cls");
	char carac [100][100];

	FILE *file;
	file = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Askmath\\assets\\Telas\\jogoInicio2.txt", "r");//abrindo a tela inicial do jogo
	
	pulaLinha (25);//sub rotina para pular linha a partir de um numero inteiro que eu escolher

	while(fgets(carac, 100, file) != NULL){
		printf("\t\t\t%s", carac);
	}
	fclose(file);
	getchar();}

//=======================================================================================
void jogoInicio3 (void){
	system("cls");
	char carac [100][100];

	FILE *file;
	file = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Askmath\\assets\\Telas\\jogoInicio3.txt", "r");//abrindo a tela inicial do jogo
	
	pulaLinha (25);//sub rotina para pular linha a partir de um numero inteiro que eu escolher

	while(fgets(carac, 100, file) != NULL){
		printf("\t\t\t%s", carac);
	}
	fclose(file);
	
	pulaLinha (1);
	espTab (5);
	scanf("%i", &ps.playerIdade);
	}

//=======================================================================================
void jogoCreditos(){
	printf("aaaaa");
}
		
//=======================================================================================
void jogoSair(){
	printf("bbbbbbb");
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void saveState(){//sub-rotina para salvar os status atuais do jogador

	FILE* output;//ponteiro output para a função FILE

	switch (ps.playerNumero){
		case '1':
			output = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Askmath\\assets\\Players\\playerUm.txt", "w");
			//abrindo o txt playerUm no modo "write"

			fprintf(output, "playerNome=%s\nplayerXp=%d\nplayerNivel=%d\nplayerIdade=%d\nplayerFase=%d\nplayerSlot=%d\n",ps.playerNome,ps.playerXp, ps.playerNivel, ps.playerIdade,ps.playerFase,ps.playerSlot);//escrevendo os dados dentro do txt
			fclose(output);
			break;

		case '2':
			output = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Askmath\\assets\\Players\\playerDois.txt", "w");
			//abrindo o txt playerDois no modo "write"

			fprintf((output, "playerNome=%s\nplayerXp=%d\nplayerNivel=%d\nplayerIdade=%d\nplayerFase=%d\nplayerSlot=%d\n",ps.playerNome,ps.playerXp, ps.playerNivel, ps.playerIdade,ps.playerFase,ps.playerSlot);//escrevendo os dados dentro do txt
			fclose(output);
			break;

		case '3':
			output = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Askmath\\assets\\Players\\playerTres.txt", "w");
			//abrindo o txt playerTres no modo "write"

			fprintf(output, "playerNome=%s\nplayerXp=%d\nplayerNivel=%d\nplayerIdade=%d\nplayerFase=%d\nplayerSlot=%d\n",ps.playerNome,ps.playerXp, ps.playerNivel, ps.playerIdade,ps.playerFase,ps.playerSlot);//escrevendo os dados dentro do txt
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

				fscanf(input, "playerNome=%s\nplayerXp=%d\nplayerNivel=%d\nplayerIdade=%d\nplayerFase=%d\nplayerSlot=%d\n",&ps.playerNome,&ps.playerXp, &ps.playerNivel, &ps.playerIdade,&ps.playerFase, &ps.playerSlot);
				//lendo os dados dentro do txt e atribuindo seus valores para dentro da struct playerStatus
				break;

			case '2':
				input = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Askmath\\assets\\Players\\playerDois.txt", "r");
				//abrindo o txt playerDois no modo "read"

				fscanf(input, "playerNome=%s\nplayerXp=%d\nplayerNivel=%d\nplayerIdade=%d\nplayerFase=%d\nplayerSlot=%d\n",&ps.playerNome,&ps.playerXp, &ps.playerNivel, &ps.playerIdade,&ps.playerFase, &ps.playerSlot);
				//lendo os dados dentro do txt e atribuindo seus valores para dentro da struct playerStatus
				break;

			case '3':
				input = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Askmath\\assets\\Players\\playerTres.txt", "r");
				//abrindo o txt playerTres no modo "read"

				fscanf(input, "playerNome=%s\nplayerXp=%d\nplayerNivel=%d\nplayerIdade=%d\nplayerFase=%d\nplayerSlot=%d\n",&ps.playerNome,&ps.playerXp, &ps.playerNivel, &ps.playerIdade,&ps.playerFase, &ps.playerSlot);
				//lendo os dados dentro do txt e atribuindo seus valores para dentro da struct playerStatus
				break;

			default :
    			printf ("Opcao invalida, digite um numero de 1 a 3!\n");
				}

	fclose(input);
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//=======================================================================================
void jogoInicio (void){

	char carac [100][100];

	FILE *file;
	file = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Askmath\\assets\\Telas\\jogoInicio.txt", "r");//abrindo a tela inicial do jogo
	
	pulaLinha (25);//sub rotina para pular linha a partir de um numero inteiro que eu escolher

	while(fgets(carac, 100, file) != NULL){
		printf("\t\t\t%s", carac);
	}

	pulaLinha (1);
	espTab (5);
	fgets(ps.playerNome,50,stdin);
	printf("%s", ps.playerNome);
	fclose(file);
}
//=======================================================================================
void jogoInicio2 (void){
	system("cls");
	char carac [100][100];

	FILE *file;
	file = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Askmath\\assets\\Telas\\jogoInicio2.txt", "r");//abrindo a tela inicial do jogo
	
	pulaLinha (25);//sub rotina para pular linha a partir de um numero inteiro que eu escolher

	while(fgets(carac, 100, file) != NULL){
		printf("\t\t\t%s", carac);
	}
	fclose(file);
	getchar();}

//=======================================================================================
void jogoInicio3 (void){
	system("cls");
	char carac [100][100];

	FILE *file;
	file = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Askmath\\assets\\Telas\\jogoInicio3.txt", "r");//abrindo a tela inicial do jogo
	
	pulaLinha (25);//sub rotina para pular linha a partir de um numero inteiro que eu escolher

	while(fgets(carac, 100, file) != NULL){
		printf("\t\t\t%s", carac);
	}
	fclose(file);
	
	pulaLinha (1);
	espTab (5);
	scanf("%i", &ps.playerIdade);
	}

//=======================================================================================
void jogoCreditos(){
	printf("aaaaa");
}
		
//=======================================================================================
void jogoSair(){
	printf("bbbbbbb");
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void saveState(){//sub-rotina para salvar os status atuais do jogador

	FILE* output;//ponteiro output para a função FILE

	switch (ps.playerNumero){
		case '1':
			output = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Askmath\\assets\\Players\\playerUm.txt", "w");
			//abrindo o txt playerUm no modo "write"

			fprintf(output, "playerNome=%s\nplayerXp=%d\nplayerNivel=%d\nplayerIdade=%d\nplayerFase=%d\nplayerSlot=%d\n",ps.playerNome,ps.playerXp, ps.playerNivel, ps.playerIdade,ps.playerFase,ps.playerSlot);//escrevendo os dados dentro do txt
			fclose(output);
			break;

		case '2':
			output = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Askmath\\assets\\Players\\playerDois.txt", "w");
			//abrindo o txt playerDois no modo "write"

			fprintf(output, "playerNome=%s\nplayerXp=%d\nplayerNivel=%d\nplayerIdade=%d\nplayerFase=%d\nplayerSlot=%d\n",ps.playerNome,ps.playerXp, ps.playerNivel, ps.playerIdade,ps.playerFase,ps.playerSlot);//escrevendo os dados dentro do txt
			fclose(output);
			break;

		case '3':
			output = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Askmath\\assets\\Players\\playerTres.txt", "w");
			//abrindo o txt playerTres no modo "write"

			fprintf(output, "playerNome=%s\nplayerXp=%d\nplayerNivel=%d\nplayerIdade=%d\nplayerFase=%d\nplayerSlot=%d\n",ps.playerNome,ps.playerXp, ps.playerNivel, ps.playerIdade,ps.playerFase,ps.playerSlot);//escrevendo os dados dentro do txt
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

				fscanf(input, "playerNome=%s\nplayerXp=%d\nplayerNivel=%d\nplayerIdade=%d\nplayerFase=%d\nplayerSlot=%d\n",&ps.playerNome,&ps.playerXp, &ps.playerNivel, &ps.playerIdade,&ps.playerFase, &ps.playerSlot);
				//lendo os dados dentro do txt e atribuindo seus valores para dentro da struct playerStatus
				break;

			case '2':
				input = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Askmath\\assets\\Players\\playerDois.txt", "r");
				//abrindo o txt playerDois no modo "read"

				fscanf(input, "playerNome=%s\nplayerXp=%d\nplayerNivel=%d\nplayerIdade=%d\nplayerFase=%d\nplayerSlot=%d\n",&ps.playerNome,&ps.playerXp, &ps.playerNivel, &ps.playerIdade,&ps.playerFase, &ps.playerSlot);
				//lendo os dados dentro do txt e atribuindo seus valores para dentro da struct playerStatus
				break;

			case '3':
				input = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Askmath\\assets\\Players\\playerTres.txt", "r");
				//abrindo o txt playerTres no modo "read"

				fscanf(input, "playerNome=%s\nplayerXp=%d\nplayerNivel=%d\nplayerIdade=%d\nplayerFase=%d\nplayerSlot=%d\n",&ps.playerNome,&ps.playerXp, &ps.playerNivel, &ps.playerIdade,&ps.playerFase, &ps.playerSlot);
				//lendo os dados dentro do txt e atribuindo seus valores para dentro da struct playerStatus
				break;

			default :
    			printf ("Opcao invalida, digite um numero de 1 a 3!\n");
				}

	fclose(input);
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

