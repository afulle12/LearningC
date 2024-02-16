#include <stdio.h>
#include <string.h>

int a, b;
int getInput();

int main(){
    char operation[20];
    
    printf("Do you want to Add, Subtract, Multiply, or Divide? ");
    scanf("%s", operation);

    if(strcmp(operation, "Add") == 0){
        getInput();
        printf("The result is %d\n", a+b);
    }

    else if(strcmp(operation, "Subtract") == 0){
        getInput();
        printf("The result is: %d\n", a-b);
    }

    else if(strcmp(operation, "Multiply") == 0){
        getInput();
        printf("The result is: %d\n", a*b);
    }

    else if(strcmp(operation, "Divide") == 0){
        getInput();
        printf("The result is: %d\n", a/b);
    } else {
        printf("You did not input a valid operation. Terminating program\n");
    }
    

    return 0;
}

int getInput(){
    printf("Please input the first number: \n");
    scanf("%d", &a);

    printf("Please input the second number: \n");
    scanf("%d", &b);
    
    return(a, b);
}