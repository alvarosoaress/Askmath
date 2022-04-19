#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>
#ifndef _playerStatusH_
#define _playerStatusH_

struct playerStatus{
	char playerNome [50][50];
	int playerNumero, playerXp, playerNivel, playerIdade, playerFase;
};

struct playerStatus ps;

#endif