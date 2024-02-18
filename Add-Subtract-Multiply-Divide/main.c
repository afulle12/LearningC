#include <stdio.h>
#include <string.h>

double a, b;
int getInput();

int main(){
    char operation[20];
    
    printf("Do you want to Add, Subtract, Multiply, or Divide? Or type Exit to terminate: ");
    scanf("%s", operation);

    if(strcmp(operation, "Add") == 0){
        getInput();
        printf("The result is %f\n", a+b);
    }

    else if(strcmp(operation, "Subtract") == 0){
        getInput();
        printf("The result is: %f\n", a-b);
    }

    else if(strcmp(operation, "Multiply") == 0){
        getInput();
        printf("The result is: %f\n", a*b);
    }

    else if(strcmp(operation, "Divide") == 0){
        getInput();
        printf("The result is: %f\n", a/b);
    } else if(strcmp(operation, "Exit") == 0){
    } else {
        printf("You did not input a valid operation. Terminating program\n");
    }
    

    return 0;
}

int getInput(){
    printf("Please input the first number: \n");
    scanf("%f", &a);

    printf("Please input the second number: \n");
    scanf("%f", &b);

    return(a, b);
}