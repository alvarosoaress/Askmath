//dentro do for colocar para verificar pelo caracter especial, quando ele aparecer altera-lo pelo nome do jogador ou coisa do tipo, se menos que 6, completar com espaco, se maior subtrair
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>
#ifndef _utilityFuncH_
#define _utilityFuncH_


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
void mostrarTela (char tela[], int tab, int linha){//Tela Inicial do nosso jogo (ainda sem as opções de escolha)
    char carac [100];
	FILE *file;//Ponteiro da função FILE para o nome "file"
	file = fopen(tela, "r");/*Função fopen
	para abrir o arquivo txt que está localizado a ASCII art da tela inicial*/
    int i =0;
   pulaLinha(linha);
	while(fgets(carac, 100, file) != NULL){//printando o txt na tela do usuário
		 espTab(tab);
        printf("%s", carac);// o /t para tentar centralizar o desenho
	}

	fclose(file);//fechando o arquivo e liberando memória após seu uso
}
//=======================================================================================
void loadingPonto (char frase[]){
    printf("%s", frase);
    int i =0;
    
    for (i=0; i<5; i++){
    printf(".");
    _sleep(250);
    }
    
}
//=======================================================================================
void typeWriter (char frase[], int velocidade, int velocidadeEspaco){
    int i =0;
    while (frase[i] != '\0')
    {
        printf("%c", frase[i]);
         if(frase[i] == ' '){
            _sleep(50/velocidadeEspaco);
        }
        else{ 
            _sleep(100/velocidade);
        }
        i++;
    }
}
//=======================================================================================
/*void caixaDia (char frase[], int tab, int linha){//Tela Inicial do nosso jogo (ainda sem as opções de escolha)
    char carac [100];
    char c;

    //42 - 43 carac por linha
	FILE *file;//Ponteiro da função FILE para o nome "file"
	file = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Askmath\\assets\\Telas\\caixaDialogo.txt", "r");
    int i =0;
   pulaLinha(linha);

 	while(fgets(carac, 100, file) != NULL){//printando o txt na tela do usuário
		 espTab(tab);
        printf("%s", carac);// o /t para tentar centralizar o desenho
	}

	while((c = fgetc(file)) != EOF){//printando o txt na tela do usuário
		 espTab(tab);
         if (c == '$'){ 
             printf("AAAAAAAAAAAAAAAAAAA\n");
         }
        }
	

	fclose(file);}//fechando o arquivo e liberando memória após seu uso
*/
//=======================================================================================
void tamanhoTela (int x,int y){

    HANDLE hConsoleOutput;
    COORD coord;
    CONSOLE_SCREEN_BUFFER_INFO  ConsoleInfo;
    HWND console = GetConsoleWindow();
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOutput, &ConsoleInfo);

    SetConsoleScreenBufferSize(hConsoleOutput, coord);
 
    MoveWindow(console, 325, 120, x, y, TRUE);

}
#endif