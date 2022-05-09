#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>

#ifndef _playerStatusH_
#define _playerStatusH_

//VAR GLOBAIS
int coracao = 3;


struct playerStatus{
	char playerNome [20];
	int playerNumero, playerCoracao, playerIdade, playerFase, playerMundo;
};

struct playerStatus ps;

#endif
