#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//x x x
//x x x
//x x x

//1 2 3
//4 5 6
//7 8 9

int board[3][3];
int output = 0;
int input;

int initSetup();
int boardCheck();
int boardPrint();
int playerInput();
int botInput();


int main(){
    initSetup();
    int t = 0;
    while (t == 0){
        t = boardCheck();
        if (t == 0){
            playerInput();
        }
        t = boardCheck();
        if (t == 0){
            botInput();
        }
        
    }
    if (t == 1){
        printf("Player wins!\n");
        boardPrint();
    } else if (t == 2) {
        printf ("Bot wins!\n");
        boardPrint();
    } else {
        printf("We have a tie!\n");
        boardPrint();
    }
    //printf("%d\n", t);
    
    return 0;
}

int initSetup(){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            board[i][j] = 0;
        }
    }
}

int boardCheck(){
    
    //Returns 1 for player win
    //Returns 2 for bot win
    //Returns 3 for board full (tie)

    int boardFull = 1;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (board[i][j] == 0){
                boardFull = 0;
            }
        }
    }
    if (board[1][1] == 0){
        //printf("If\n");
        for (int i = 0; i < 3; i++){
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] > 0){
                //printf("Line 79!\n");
                return board[i][2];
            }
        }
        for (int i = 0; i < 3; i++){
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] > 0){
                //printf("Line 85!\n");
                return board[2][i];
            }
        }
    } else {
        //printf("Else\n");
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] > 0){
            //printf("Line 92!\n");
            return board[1][1];
        }
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] > 0){
            //printf("Line 99!\n");
            return board[1][1];
        }
        for (int i = 0; i < 3; i++){
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] > 0){
                //printf("Line 105!\n");
                //printf("%d\n", board[i][1]);
                return board[i][2];
            }
        }
        for (int i = 0; i < 3; i++){
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] > 0){
                //printf("Line 111!\n");
                return board[1][i];
            }
        }
    }
/*  printf("board[0][0] = %d\n", board[0][0]);
    printf("board[0][1] = %d\n", board[0][1]);
    printf("board[0][2] = %d\n", board[0][2]);
    printf("board[1][0] = %d\n", board[1][0]);
    printf("board[1][1] = %d\n", board[1][1]);
    printf("board[1][2] = %d\n", board[1][2]);
    printf("board[2][0] = %d\n", board[2][0]);
    printf("board[2][1] = %d\n", board[2][1]);
    printf("board[2][2] = %d\n", board[2][2]); */
    if (boardFull == 1){
        return 3;
    }
    return 0;
}

int playerInput(){
    //Prints current board with options 1-9 depicted
    /* printf("\n");
    int counter = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            counter++;
            if(board[i][j] == 0){
                printf("%d ", counter);
            } else if (board[i][j] == 1) {
                printf("P ");
            } else {
                printf("B ");
            }
        }
        printf("\n");
    } */
    boardPrint();

    //Requests input in the form of options 1-9
    //printf("\nInput a number from 1-9 to select your move: ");
    //scanf("%d", &input);

    //if ((input < 0) || (input > 9)){
        //playerInput();
    //}
    
    //If the spot on the board is empty, change the value
    //If the spot is occupied, have the player try to input another number
    //Edit the board to add the player input
    int failed = 0;
    int counter = 0;
    do {
        printf("\nInput a number from 1-9 to select your move: ");
        scanf("%d", &input);
        counter = 0;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                counter++;
                if (input == counter){
                    if (board[i][j] == 0){
                        board[i][j] = 1;
                        //printf("Recorded!\n");
                        failed = 0;
                    }
                    else {
                        failed = 1;
                    }
            }
        }
    }
    } while (failed == 1);
    
    
    return 0;
}

int botInput(){
    //Check the board
    //Use algorithm to determine next move
    int failed = 0;
    int counter = 0;
    do
    {
        srand(time(NULL));
        int pc = (rand() % 9) + 1;
        //printf("Bot moved to %d\n", pc);
        counter = 0;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                counter++;
                if (pc == counter){
                    if (board[i][j] == 0){
                        board[i][j] = 2;
                        printf("Bot marked %d\n", pc);
                        failed = 0;
                    }
                    else {
                        failed = 1;
                    }
                }
            }
        }
    } while (failed == 1);
    
    //printf("Bot moved to %d\n", counter);
    boardPrint();

    //Check if square is already taken
    //If the square isn't taken, edit the board. If the square is taken, run the algorithm again
}

int boardPrint(){
    printf("\n");
    int counter = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            counter++;
            if(board[i][j] == 0){
                printf("%d ", counter);
            } else if (board[i][j] == 1) {
                printf("P ");
            } else if (board[i][j] == 2) {
                printf("B ");
            } else {
                printf("Error! ");
            }
        }
        printf("\n");
    }
    return 0;
}