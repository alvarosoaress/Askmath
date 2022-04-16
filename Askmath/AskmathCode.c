//Askmath

//Include das bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>
#include "playerStatus.h"
#include "utilityFunc.h"
#include "playerFunc.h"

//Funcoes
void opcaoUm (void);
void jogoCreditos (void);
void jogoSair (void);

//Variaveis globais


//TODO tentar trocar de VAR para algum de tipo "matriz função" tipo void jogoFase[12][5] (void);
int jogoFase[12][5];/*Um máximo de 12 fases e 5 mundos (1 mundo - 3 fases) (2 mundo - 5 fases) (3 mundo - 8 fases)
(4 mundo - 10 fases) (5 mundo - 12 fases) */


//Int Main
int main(){
	
	char escolha;//escolha que o jogador ira fazer na telaPrincipal
	ps.playerNumero = '1';//!MUDAR ISSO
	loadState();
	
	printf("\n%i\n", ps.playerIdade);
	mostrarTela (telaInicial,1,0);
	loadingPonto("Carrgeando");
	pulaLinha(2);
	typeWriter ("Ola Mundo");
	//printf("%s", ps.playerNome);
	getchar();

	
	system("cls");
	mostrarTela (telaPrincipal,1,0);

	
	while((escolha > 3) || (escolha < 1)){
		escolha = getch();

		switch (escolha){//escolhendo qual opcao o jogador deseja
			case '1':
				system("cls");
				opcaoUm();
				break;

			case '2' :
				system("cls");
				jogoCreditos();
				break;
				
			case '3':
				system("cls");
				jogoSair();
				break;

			default :
				printf ("Opcao invalida, digite um numero de 1 a 3!\n");

				}
		}

	pulaLinha(5);

	
	
	getchar();
	return 0;
}

//=======================================================================================
void opcaoUm (void){
//mostrarTela(jogoInicio, 3,20);
caixaDia ("Bom dia seu pilantra",3,20);
getch();
mostrarTela(jogoInicio2,0,0);
getch();
mostrarTela(jogoInicio3,0,0);
getch();
mostrarTela(telaselecaoPers, 0,0);
getch();
}
//=======================================================================================
void jogoCreditos(){
	printf("aaaaa");
}
		
//=======================================================================================
void jogoSair(){
	printf("bbbbbbb");
}