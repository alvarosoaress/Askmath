void saveState (void);
void loadState (void);

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void saveState(){//sub-rotina para salvar os status atuais do jogador

	FILE* output;//ponteiro output para a função FILE

	switch (ps.playerNumero){
		case '1':
			output = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Teste jogo\\assets\\Players\\playerUm.txt", "w");
			//abrindo o txt playerUm no modo "write"

			fprintf(output, "playerXp=%d\nplayerNivel=%d\nplayerIdade=%d\nplayerFase=%d\n",ps.playerXp, ps.playerNivel, ps.playerIdade,ps.playerFase);//escrevendo os dados dentro do txt
			fclose(output);
			break;

		case '2':
			output = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Teste jogo\\assets\\Players\\playerDois.txt", "w");
			//abrindo o txt playerDois no modo "write"

			fprintf(output, "playerXp=%d\nplayerNivel=%d\nplayerIdade=%d\nplayerFase=%d\n",ps.playerXp, ps.playerNivel, ps.playerIdade,ps.playerFase);//escrevendo os dados dentro do txt
			fclose(output);
			break;

		case '3':
			output = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Teste jogo\\assets\\Players\\playerTres.txt", "w");
			//abrindo o txt playerTres no modo "write"

			fprintf(output, "playerXp=%d\nplayerNivel=%d\nplayerIdade=%d\nplayerFase=%d\n",ps.playerXp, ps.playerNivel, ps.playerIdade,ps.playerFase);//escrevendo os dados dentro do txt
			fclose(output);
			break;

		default :
    		printf ("Opcao invalida, digite um numero de 1 a 3!\n");
			}

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void loadState(){//sub-rotina para carregar os status atuais do jogador

	FILE* input;//ponteiro input para a função FILE
	
		switch (ps.playerNumero){
			case '1':
				input = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Teste jogo\\assets\\Players\\playerUm.txt", "r");
				//abrindo o txt playerUm no modo "read"

				fscanf(input, "playerXp=%d\nplayerNivel=%d\nplayerIdade=%d\nplayerFase=%d\n",&ps.playerXp, &ps.playerNivel, &ps.playerIdade,&ps.playerFase);
				//lendo os dados dentro do txt e atribuindo seus valores para dentro da struct playerStatus
				break;

			case '2':
				input = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Teste jogo\\assets\\Players\\playerDois.txt", "r");
				//abrindo o txt playerDois no modo "read"

				fscanf(input, "playerXp=%d\nplayerNivel=%d\nplayerIdade=%d\nplayerFase=%d\n",&ps.playerXp, &ps.playerNivel, &ps.playerIdade,&ps.playerFase);
				//lendo os dados dentro do txt e atribuindo seus valores para dentro da struct playerStatus
				break;

			case '3':
				input = fopen("C:\\Users\\Administrator\\Documents\\GitHub\\Geobuild\\Teste jogo\\assets\\Players\\playerTres.txt", "r");
				//abrindo o txt playerTres no modo "read"

				fscanf(input, "playerXp=%d\nplayerNivel=%d\nplayerIdade=%d\nplayerFase=%d\n",&ps.playerXp, &ps.playerNivel, &ps.playerIdade,&ps.playerFase);
				//lendo os dados dentro do txt e atribuindo seus valores para dentro da struct playerStatus
				break;

			default :
    			printf ("Opcao invalida, digite um numero de 1 a 3!\n");
				}

	fclose(input);
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++