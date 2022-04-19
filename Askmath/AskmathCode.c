//Askmath

//Include das bibliotecas
#include "library\importAll.h"
#include "library\mundos.h"
//Funcoes
void opcaoUm (void);
void jogoCreditos (void);
void jogoSair (void);

//Variaveis globais


//Int Main
int main(){
	int i,j;
	UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);// tudo isso ai pra colocar acento

	tamanhoTela(800,600);
	char escolha;//escolha que o jogador ira fazer na telaPrincipal

	for ( i = 0; i < 5; i++){
	for ( j = 0; j < 5; j++){
		printf("|%i|", jogoFase[i][j]);}
	printf("\n---------------------");
    printf("\n");}
	
	getch();
	mostrarTela (telaInicial,1,0);

	getchar();

	
	system("cls");
	mostrarTela (telaPrincipal,0,0);

	
	while((escolha > 3) || (escolha < 1)){
		escolha = getch();

		switch (escolha){//escolhendo qual opcao o jogador deseja
			case '1':
				system("cls");
				opcaoUm();
				break;

			case '2' :
				system("cls");
				jogoCreditos();
				break;
				
			case '3':
				system("cls");
				jogoSair();
				break;

			default :
				printf ("Opcao invalida, digite um numero de 1 a 3!\n");

				}
		}

	pulaLinha(5);

	
	
	getchar();
	return 0;
	SetConsoleOutputCP(CPAGE_DEFAULT);//acento tbm aceita ai
}

//=======================================================================================
void opcaoUm (void){

	mostrarTela(telaselecaoPers,0,0);//mostra o cabeçalho da seleção de personagens
		pulaLinha(2);
		selecaoPers();//mostra a tela de personagens disponíveis, se não existir, existirá "slot livre"
		ps.playerNumero = getch();//pega qual personagem o usuário deseja jogar
		loadState();
		system("cls");
//	system("cls");

	if (slotLivre == 1){
	mostrarTela(jogoInicio, 3,20);
		gets(ps.playerNome);
	system("cls");

	mostrarTela(jogoInicio2,3,20);
	getch();
	system("cls");

	mostrarTela(jogoInicio3,3,20);
		scanf("%d", &ps.playerIdade);
		saveState();
	system("cls");}

	else{
		//menuPrincipal();
	}
	getch();

}
//=======================================================================================
void jogoCreditos(){
	printf("aaaaa");
}
		
//=======================================================================================
void jogoSair(){
	printf("bbbbbbb");
}