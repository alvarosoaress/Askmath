#include <stdio.h>
#include <stdlib.h>

int main (){
	int i;
	char frase [100][100];
	
	FILE *file;
	file = fopen("sdas.txt", "r");
	printf("\n");
	while(fgets(frase, 100, file) != NULL){
		printf("\t\t%s", frase);
	}
	for (i=0; i<10; i++){
	
	printf("\n");}
	
	printf("%42s", "pressione ENTER para continuar\n");
getchar();
	printf("\na");
	fclose(file);

return 0;
}


