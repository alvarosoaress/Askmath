#include <stdio.h>
#include <stdlib.h>

int main (){
	int i, escolha;
	char frase [100][100];
	
	FILE *file;
	file = fopen("sdas.txt", "r");
	
	while(fgets(frase, 100, file) != NULL){
		printf("%s", frase);
	}
		printf("\n");
	
	
	printf("%42s", "pressione ENTER para continuar\n");
getchar();
	system("CLS");

	file = fopen("igreja.txt", "r");
	
	while(fgets(frase, 100, file) != NULL){
		printf("%s", frase);
	}

/*	for (i=0; i<10; i++){
	
	printf("\n");}*/
		fclose(file);

	printf("%42s", "Qual numero falta?\n");
	scanf("%i",&escolha);
	
	if (escolha == 2){
	file = fopen("igreja2.txt", "r");
	
	while(fgets(frase, 100, file) != NULL){
		printf("%s", frase);
	}
	getchar();
	fclose(file);

	}
	else{
		printf("ERRADO");
	}
	getchar();
	}


