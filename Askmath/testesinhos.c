#include <stdio.h>
#include <stdlib.h>   //for exit(0), system("cls")
#include <conio.h>    //For kbhit, getch()
#include <time.h>     //For clock(),clock_t

int minute=0,second=20;   //global variables

void delay(ms)  //delay function
{
    clock_t timeDelay = ms + clock();    //Step up the difference from clock delay
    while (timeDelay > clock());         //stop when the clock is higher than time delay
}
int counter(){
    while(resposta != 3){     //keep looping while the user didn't hit any key and flag is 0
                     printData();           //print out the new data, delay for 1000 millisecond and increase 1 second.
                    delay(1000);second -= 1;
        }
}

int printData(){   //print data to screen
system("cls");      //clear the screen
printf("***********************************\n");
printf("            %d:%d\n",minute,second);      //output the data
printf("***********************************\n");
}

int main()
{
    while(1){             //keep the program running and never end
    counter();
    }
}