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

int jogoFase[5][5] = { 00, 01, 02, 03, 04,    //   11, 21, 31, 41, 51,
                        x,  11, 12, 13, 14,   //    x, 22, 32, 42, 52,
                        x,  x,  22, 23, 24,   //    x,  x, 33, 43, 53,
                        x,  x,  x,  33, 34,   //    x,  x,  x, 44, 54,
                        x,  x,  x,  x,  44 }; //    x,  x,  x,  x, 55, 
                  
                        
 /*Um total de 15 fases e 5 mundos (1 mundo - 1 fase) (2 mundo - 2 fases) (3 mundo - 3 fases)
(4 mundo - 4 fases) (5 mundo - 5 fases) */
void escolhaFase (int l, int c){
    
switch (jogoFase[l][c]){

    case 0:
        coracao = 3;
        fase11();
        break;
    
     case 1:
        fase21();
        break;

/*    case 11:
        fase22();
        break;

    case 2:
        fase31();
        break;

    case 12:
        fase32();
        break;

    case 22:
        fase33();
        break;

    case 3:
        fase41();
        break;
    
    case 13:
        fase42();
        break;

    case 23:
        fase43();
        break;

    case 33:
        fase44();
        break;

    case 4:
        fase51();
        break;

    case 14:
        fase52();
        break;
        
    case 24:
        fase53();
        break;

    case 34:
        fase54();
        break;

    case 44:
        fase55();
        break; */

}
}


#endif