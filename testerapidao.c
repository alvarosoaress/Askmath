#include <stdio.h>
#include <stdlib.h>
struct registro {

    int n[6];
    int acertos;
};

struct registro reg;

int mega (int n[6], int n2);

int main (){
    int i=0;
srand(time(NULL));
    while(i!=100){
        reg.acertos = 0;
    if((mega (reg.n, reg.acertos) == 1)){
        printf("Voce ganhou na mega sena\n");
    }
    else if((mega (reg.n, reg.acertos) == 2)){
        printf("Voce ganhou na quina\n");
    }
    else{
        printf("\nVoce teve %d acertos. Nao ganhou em nada\n", reg.acertos);
    }
    i++;
    }
    getch();
    return 0;
}

int mega (int n[6], int n2){

    int s[6];
    int i,j;

    for(i=0; i<6; i++){
        s[i] = (rand()%60)+1;
        n[i] = (rand()%60)+1;
        printf("s[%d] = %d\n", i, s[i]);
        printf("n[%d] = %d\n", i, n[i]);
        if (s[i] == n[i]){
            n2++;
        }
    }

    if(n2 == 6){
        return 1;
    }
    else if(n2 == 5){
        return 2;
    }
    else{
        reg.acertos = n2;
        return 0;
    }
}

/*     int n[10],i, j;
    char h[10][4];
    srand(time(NULL));
    for(i=0; i<10; i++){
        n[i] = rand()%100;
        itoa(n[i],h[i],16);
    }

    for(i=0; i<10; i++){

            printf("Decimal : %i", n[i]);
            printf("\tHexadecimal [%d]: %s\n", i, h[i]);

    } */