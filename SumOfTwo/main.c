#include <stdio.h>

int main (){
    int a, b;

    printf("This program will add the sum of two values you will input\n");
    printf("Input your first Integer: ");
    
    scanf("%d", &a);
    
    printf("Now input the second Integer: ");
    
    scanf("%d", &b);
    
    printf("The sum of your two inputs is: %d\n", a+b);

    return 0;
}