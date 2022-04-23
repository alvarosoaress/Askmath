#include<windows.h>
#include<locale.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>

#include "playerStatus.h"
#include "utilityFunc.h"
#include "playerFunc.h"
#include "telasDir.h"
#include "fases.h"

#ifndef _mundosH_
#define _mundosH_


int l=0,c=0; // l = linha / c = coluna -> jogoFase[l][c];

const int x = 0;

 int jogoFase[5][5] = { 11, 21, 31, 41, 51,
                        x,  22, 32, 42, 52,
                        x,  x,  33, 43, 53,
                        x,  x,  x,  44, 54,
                        x,  x,  x,  x,  55 };
                        
 /*Um total de 15 fases e 5 mundos (1 mundo - 1 fase) (2 mundo - 2 fases) (3 mundo - 3 fases)
(4 mundo - 4 fases) (5 mundo - 5 fases) */
void escolhaFase (int l, int c){
    
switch (jogoFase[l][c]){

    case 11:
        if (fase11() == 1){
            ps.playerXp += 10;
        }
        break;
    
/*     case 21:
        fase21();
        break;

    case 22:
        fase22();
        break;

    case 31:
        fase31();
        break;

    case 32:
        fase32();
        break;

    case 33:
        fase33();
        break;

    case 41:
        fase41();
        break;
    
    case 42:
        fase42();
        break;

    case 43:
        fase43();
        break;

    case 44:
        fase44();
        break;

    case 51:
        fase51();
        break;

    case 52:
        fase52();
        break;
        
    case 53:
        fase53();
        break;

    case 54:
        fase54();
        break;

    case 55:
        fase55();
        break; */

}
}


#endif