//RPG escolar

//Include das bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<locale.h>
#include<conio.h>

//Funcoes
void pulaLinha (int l);
void telaInicial (void);
void telaPrincipal (void);
void jogoInicio (void);
void jogoCreditos (void);
void jogoSair (void);


//Variaveis globais
struct playerStatus{
	char playerNome [50][50];
	int playerXp, playerEstudo, playerEnergia, playerFase, playerDano, playerVida;
};

struct playerStatus ps;

int jogoFase[3][3];


//Int Main
int main(){

	setlocale(LC_ALL, "pt-br");

	char escolha;

	telaInicial();
	getchar();
	

	system("cls");
	telaPrincipal();

	escolha = getch();
	system("cls");
	switch (escolha){
		case '1':
			jogoInicio();
			break;

		case '2' :
			jogoCreditos();
			break;
			
		case '3':
			jogoSair();
			break;

		default :
    		printf ("Valor invalido!\n");
			}

	getchar();
	return 0;
}

pulaLinha (int l){
int i=0;
	for ( i = 0; i < l; i++){//For para pular linhas e deixar a caixa de texto no final do terminal
		printf("\n");
	}
}

void telaInicial (void){//Tela Inicial do nosso jogo (ainda sem as opções de escolha)
	
	int i;
	char carac [100][100];

	FILE *file;//Ponteiro da função FILE para o nome "file"
	file = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Teste jogo\\telaInicial.txt", "r");/*Função fopen
	para abrir o arquivo txt que está localizado a ASCII art da tela inicial*/

	while(fgets(carac, 100, file) != NULL){//printando o txt na tela do usuário
		printf("\t%s", carac);// o /t para tentar centralizar o desenho
	}

	fclose(file);//fechando o arquivo e liberando memória após seu uso
}

void telaPrincipal (void){// Tela principal do jogo contendo 1-Jogar 2-Creditos 3-Sair

	int i;
	char carac [100][100];

	FILE *file;
	file = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Teste jogo\\telaPrincipal.txt", "r");
	while(fgets(carac, 100, file) != NULL){
		printf("\t%s", carac);
	}
	fclose(file);

}

void jogoInicio (void){
	
	int i;
	char carac [100][100];

	FILE *file;
	file = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Teste jogo\\jogoInicio.txt", "r");
	
	pulaLinha (25);

	while(fgets(carac, 100, file) != NULL){
		printf("\t\t\t%s", carac);
	}

	gets(ps.playerNome);
	printf("%s", ps.playerNome);
	fclose(file);
	getchar();
}

jogoCreditos(){
	printf("aaaaa");
}

jogoSair(){
	printf("bbbbbbb");
}

