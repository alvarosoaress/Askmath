#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>
#ifndef _utilityFasesH_
#define _utilityFasesH_

int coracao = 3;
int twtime = 3;//função para controlar o tempo das animações de print
int escolha = 0;
void twDialogo (char frase[], int tempo, int tab){//função para colocar animado na tela uma frase no estilo typeWriter
    int i =0;

    espTab(tab);
    if(tempo > 0){//se o parametro tempo for positivo (>0) irá ocorrer a animação
    while (frase[i] != '\0')
    {
        printf("%c", frase[i]);//printando cara caracter
         if(frase[i] == ' '){//caso seja um espaço irá demorar um tempo diferente
            _sleep(tempo);
        }
        else{ 
            if (tempo != 0){
            _sleep(tempo+2);//se for um caracter, irá demorar mais tempo, simulando a digitação humana
        }
        }
        i++;
    }
    
}
else{//caso o tempo fornecido seja negativo (<0), irá printar instantaneamente a frase
        printf("%s", frase);
    }
}
//=======================================================================================
void faseResposta (int xp){//função para exibir a caixa de resposta correta caso o player acerte a pergunta
    pulaLinha(2);
        twDialogo("     -+*+-+*+-+*+-+*+-+*+-\n",1,4);
        twDialogo("     *                   *\n",1,4);
        twDialogo("     : Resposta Correta! :\n",1,4);
        twDialogo("     *                   *\n",1,4);
        printf("\t\t\t\t     : +%d Xp!           :\n",xp);//o xp será personalizado a cada fase dependendo do parametro passado para a função
        twDialogo("     *                   *\n",1,4);
        twDialogo("     -+*+-+*+-+*+-+*+-+*+-\n",1,4);
    } 
//=======================================================================================
int playerCoracao (int n1){//printa os coraçõees autais do player

switch(coracao){

    case 3: //a cada vez que ele erra uma pergunta, a contagem desce
        pulaLinha(1);
    twDialogo("    ,''', ,''',  ,''', ,''',  ,''', ,''', \n",1,3);
    twDialogo("    ',   '   ,'  ',   '   ,'  ',   '   ,' \n",1,3);
    twDialogo("      ',   ,'      ',   ,'      ',   ,'   \n",1,3);
    twDialogo("        ','          ','          ','     \n",1,3);
    break;

    case 2:
        pulaLinha(1);
    twDialogo("  ,''',          ,''', ,''',  ,''', ,''', \n",0,3);
    _sleep(220);//sleep para printar a fileira inteira ao inves de caracter por caracter
    twDialogo("  ',   \\  ,''',  ',   '   ,'  ',   '   ,' \n",0,3);
    _sleep(220);
    twDialogo("    ', //'   ,'    ',   ,'      ',   ,'   \n",0,3);
    _sleep(220);
    twDialogo("      '\\  ,'        ','          ','     \n",0,3);
    _sleep(220);
    twDialogo("        /,'\n",0,3);
    break;

    case 1:
        pulaLinha(1);
    twDialogo("   ,''',         ,''',          ,''', ,''', \n",0,3);
    _sleep(220);
    twDialogo("   ',   \\  ,''', ',   \\  ,''',  ',   '   ,' \n",0,3);
    _sleep(220);
    twDialogo("     ', //'   ,'   ', //'   ,'    ',   ,'   \n",0,3);
    _sleep(220);
    twDialogo("       '\\  ,'       '\\  ,'        ','     \n",0,3);
    _sleep(220);
    twDialogo("         /,'           /,'\n",0,3);
    break;

    case 0:
        pulaLinha(8);
    twDialogo(",''',         ,''',         ,''',        \n",0,3);
    _sleep(420);//caso zere os corações, irá printar mais devagar, dando um certo drama na cena
    twDialogo("',   \\  ,''', ',   \\  ,''', ',   \\  ,''',\n",0,3);
    _sleep(420);
    twDialogo("  ', //'   ,'   ', //'   ,'   ', //'   ,'\n",0,3);
    _sleep(420);
    twDialogo("    '\\  ,'       '\\  ,'       '\\  ,'  \n",0,3);
    _sleep(420);
    twDialogo("      /,'           /,'           /,'    \n",0,3);
    coracao = 0;
    break;
}
} 
void gameover (void){
    pulaLinha(8);
twDialogo("   ▄▄ •  ▄▄▄· • ▌ ▄ ·. ▄▄▄ .           ▌ ▐·▄▄▄ .▄▄▄      ▄▄ \n",0,2);
twDialogo("  ▐█ ▀ ▪▐█ ▀█ ·██ ▐███▪▀▄.▀·    ▪     ▪█·█▌▀▄.▀·▀▄ █·    ██▌\n",0,2);
twDialogo("  ▄█ ▀█▄▄█▀▀█ ▐█ ▌▐▌▐█·▐▀▀▪▄     ▄█▀▄ ▐█▐█•▐▀▀▪▄▐▀▀▄     ▐█·\n",0,2);
twDialogo("  ▐█▄▪▐█▐█ ▪▐▌██ ██▌▐█▌▐█▄▄▌    ▐█▌.▐▌ ███ ▐█▄▄▌▐█•█▌    .▀ \n",0,2);
twDialogo("  ·▀▀▀▀  ▀  ▀ ▀▀  █▪▀▀▀ ▀▀▀      ▀█▄▀▪. ▀   ▀▀▀ .▀  ▀     ▀ \n",0,2);
typeWriter("\n\n\n\t\t  -Aperte qualquer tecla para voltar ao menu principal-\n",1,1);
coracao = 3;
getch();
menuPrincipal();
}
#endif