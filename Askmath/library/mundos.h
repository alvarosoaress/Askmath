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

#ifndef _mundosH_
#define _mundosH_

#define TAM 10

int l=0,c=0; // l = linha / c = coluna -> jogoFase[l][c];

const int mundo11 = TAM;
const int mundo21 = TAM;
const int mundo31 = TAM;
const int mundo41 = TAM;
const int mundo51 = TAM;
const int mundo22 = TAM;
const int mundo32 = TAM;
const int mundo42 = TAM;
const int mundo52 = TAM;
const int mundo33 = TAM;
const int mundo43 = TAM;
const int mundo53 = TAM;
const int mundo44 = TAM;
const int mundo54 = TAM;
const int mundo35 = TAM;
const int mundo55 = TAM;

const int x = 99;

int jogoFase[5][5] = {mundo11, mundo21, mundo31, mundo41, mundo51,
                        x,     mundo22, mundo32, mundo42, mundo52,
                        x,         x,   mundo33, mundo43, mundo53,
                        x,         x,      x,    mundo44, mundo54,
                        x,         x,      x,       x,    mundo55,};
                        
 /*Um máximo de 12 fases e 5 mundos (1 mundo - 3 fases) (2 mundo - 5 fases) (3 mundo - 8 fases)
(4 mundo - 10 fases) (5 mundo - 12 fases) */





#endif