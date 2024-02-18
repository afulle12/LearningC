#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <string.h>

int getInput();
int calculator();
char input[20];
int a;

int main(){
    getInput();

    switch ( a ){
        case 1:
            calculator(1);
            break;
        case 2:
            calculator(2);
            break;
        case 3:
            calculator(3);
            break;
        default:
            printf("Input Invalid!\n");
    }

    return 0;
}

int getInput(){
    printf("Rock (1), Paper (2), or Scissors (3)?: \n");
    scanf("%d", &a);

    return(a);
}

int calculator( a ){
    srand(time(NULL));
    int pc = (rand() % 3) + 1;
    printf("PC = %d\n", pc);
    switch ( pc ){
        case 1:
            if (a == 1){
                printf("Rock (Tie)\n");
            } else if (a == 2){
                printf("Paper beats Rock, you win!\n");
            } else {
                printf("Rock beats Scissors, you lose!\n");
            }
            break;
        case 2:
            if (a == 1){
                printf("Paper beats Rock, you lose!\n"); // 1 , 2
            } else if (a == 2){
                printf("Paper (Tie)!\n");                // 2 , 2
            } else {
                printf("Scissors beats Paper, you win!\n"); // 3 , 2 
            }
            break;
        case 3:
            if (a == 1){
                printf("Rock beats Scissors, you win!\n");
            } else if (a == 2){
                printf("Scissors beats Paper, you lose!\n");
            } else {
                printf("Scissors (Tie)\n");
            }
            break;
        default:
            printf("Input Invalid!\n");
    }
    return 0;
}