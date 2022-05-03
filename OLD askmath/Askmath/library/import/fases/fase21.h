#include<windows.h>
#include<locale.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>

#include "utilityFases.h"

#ifndef _fase21H_
#define _fase21H_


void fase21Header (void){//função para printar o cabeçalho da pergunta
    pulaLinha(3);

        twDialogo("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n",twtime,2);
        twDialogo("=                                                           =\n",twtime,2);
        twDialogo("-  Questão Adição - 1                                       -\n",twtime,2);
        twDialogo("=                                                           =\n",twtime,2);
        twDialogo("-   Um homem decidiu apostar no jogo do bicho, ele          -\n",twtime,2);
        twDialogo("=   tinha 53 reais e ganhou 24 com essa aposta.             =\n",twtime,2);
        twDialogo("-   Quantos reais ele tem agora ?                           -\n",twtime,2);
        twDialogo("=                                                           =\n",twtime,2);
        twDialogo("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n",twtime,2);
        }

void fase21Perguntas (void){//função para printar as opções de resposta
    pulaLinha(2);

        printf("\t\t\t\t  ┌──────┐         ┌──────┐\n");
        printf("\t\t\t\t  │1 - 58│         │2 - 77│\n");
        printf("\t\t\t\t  └──────┘         └──────┘\n");
        printf("\t\t\t\t                           \n");
        printf("\t\t\t\t                           \n");
        printf("\t\t\t\t  ┌──────┐         ┌──────┐\n");
        printf("\t\t\t\t  │3 - 79│         │4 - 80│\n");
        printf("\t\t\t\t  └──────┘         └──────┘\n");
    }

int fase21 (void){//função que "faz funcionar" a fase como um todo
int resposta;
while (resposta != '3'){//caso a resposta seja diferente da certa (nesse caso é a 3) o jogo continuará a pergunta 3 vezes, até o player zerar seus corações
    if (coracao != 0){
    system("cls");
    fase21Header ();
    fase21Perguntas ();
    twtime = -1;//igualando o parametro de tempo para -1 para que quando o player erre, não aconteca toda uma nova animação novamente
    printf("\n\n\n\n\n\n\n%53s%d\n","Corações: ",coracao);
    playerCoracao(coracao);
        resposta = getch();

        if (resposta == '2'){//if para acerto
            system("cls");
            twtime = 3;
            ps.playerXp+=10;
            fase21Header ();
            faseResposta (10);//10 passado como parametro de quantos xp o player irá ganhar
            if (ps.playerMundo <= 1){//verificando o progresso atual do palyer
                ps.playerMundo = 1;//atribuindo ao player em que mundo ele parou
            }
            if((ps.playerMundo <= 1) && (ps.playerFase <= 1))
            {
                ps.playerFase = 1;//atribuindo ao player em que fase ele parou
            }
            saveState();
            printf("Escolha uma opção:\n1 - Continuar jogo\n2 - Voltar ao menu principal\n");
            escolha = getch();
            if (escolha == '1'){
            escolhaFase(1,1);//mudar isso dependendo da fase
            }
            else{
                saveState();
                menuPrincipal();
            }
    }
        else{//else para se o player errar
            coracao--;
        }
}
else{
    
    system("cls");
    playerCoracao(0);
    gameover();
    getch();
    break;
}
}

}
#endif