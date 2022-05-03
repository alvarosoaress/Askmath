#include <stdio.h>
#include <windows.h>

void printc (char texto[], int color);

int main (){
    int x = 278;

    printc("Ola mundo", 4); 

    printf("\nBom dia!");

    typeWriter("Ola %d",1,1);

    getch();
    return 0;
}

void printc (char texto[], int color){

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

    printf("%s", texto);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void typeWriter (char frase[], int velocidade, int velocidadeEspaco){
    int i =0;
    while (frase[i] != '\0')
    {
        printf("%c", frase[i]);
         if(frase[i] == ' '){
            _sleep(50/velocidadeEspaco);
        }
        else{ 
            _sleep(100/velocidade);
        }
        i++;
    }
}