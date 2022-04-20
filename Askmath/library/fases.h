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
#include "mundos.h"

#ifndef _fasesH_
#define _fasesH_

void typeWriterDialogo (char frase[], int linha, int tab){
    int i =0;
    pulaLinha(linha);
    espTab(tab);
    while (frase[i] != '\0')
    {
        
        printf("%c", frase[i]);
         if(frase[i] == ' '){
           // _sleep(3);
        }
        else{ 
            //_sleep(5);
        }
        i++;
    }
}


void fase11 (void){
typeWriterDialogo(" +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n",0,2); 
typeWriterDialogo(" =                                                           =\n",0,2);
typeWriterDialogo(" -  Questão Tutorial - Soma                                  -\n",0,2);
typeWriterDialogo(" =                                                           =\n",0,2 );
typeWriterDialogo(" -   Edgar tinha 22 gatinhos em sua casa, decidiu adotar     -\n",0,2);
typeWriterDialogo(" =   mais um, quantos gatinhos ele tem em sua casa agora?    =\n",0,2);
typeWriterDialogo(" -                                                           -\n",0,2 );
typeWriterDialogo(" +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n",0,2 );
printf("\n\t\t = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =");
printf("\n%18s%60s\n%18s%20s%22s%18s\n%18s%60s\n%18s%20s%22s%18s\n%18s%60s", "-","-","-","1 - 22","2 - 25","-","-","-","-","3 - 23","4 - 21","-","-","-");//18 espaços dps -, 60esp dps -, 18esp dps -, 20esp dps 1, 22esp dps 2, 18 esp dps -,18esp dps -, 60esp dps -,18 esp dps -, 20esp dps 3, 22esp dps 4,18esp dps -, 18sp dps -, 60esp dps -
printf("\n\t\t = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =");
}





















#endif