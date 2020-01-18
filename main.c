#include <stdio.h>
#include <stdlib.h>

char board[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int player, choice;

void displayBoard();
int checkForWin();
int markBoard(char mark);

int main()
{
    int gameStatus;
    char mark;
    player=1;
    displayBoard();
    do{
        player=(player % 2) ? 1 : 2;
        printf("\nPlayer %d, Enter a number: ", player);
        scanf("%d", &choice);
        mark=(player==1)?'X':'O';
        markBoard(mark);
        displayBoard();
        gameStatus=checkForWin();
        player++;

    }while(gameStatus == 0);
    if(gameStatus==1)
        printf("\n==>\aPlayer %d Win\n", --player);
    else
        printf("\n==>\aGame Draw\n");
    return 0;
}

/* Method to display board */
void displayBoard()
{
    system("cls");
    printf("Tic Tac Toe\n");
    printf("Player 1(X) -  Player 2(O)\n\n");
    printf("       |       |       \n");
    printf("    %c  |   %c   |   %c  \n", board[1], board[2], board[3]);
    printf("_______|_______|_______\n");
    printf("       |       |       \n");
    printf("    %c  |   %c   |   %c  \n", board[4], board[5], board[6]);
    printf("_______|_______|_______\n");
    printf("       |       |       \n");
    printf("    %c  |   %c   |   %c  \n", board[7], board[8], board[9]);
    printf("       |       |       \n");

}

/*Status codes
    Win 1
    Draw -1
    Proceed 0
*/

/* Method to check for Win*/
int checkForWin()
{
    int returnValue=-1;

    if(board[1]==board[2] && board[2]==board[3])
        returnValue=1;

    else if(board[4]==board[5] && board[5]==board[6])
        returnValue=1;

    else if(board[7]==board[8] && board[8]==board[9])
        returnValue=1;

    else if(board[1]==board[5] && board[5]==board[9])
        returnValue=1;

    else if(board[2]==board[5] && board[5]==board[8])
        returnValue=1;

    else if(board[3]==board[5] && board[5]==board[7])
        returnValue=1;

    else if(board[1]==board[4] && board[4]==board[7])
        returnValue=1;

    else if(board[3]==board[6] && board[6]==board[9])
        returnValue=1;

    else if(board[1]!='1' && board[2]!='2' && board[3]!='3'
            && board[4]!='4' && board[5]!='5' && board[6]!='6'
            && board[7]!='7' && board[8]!='8' && board[9]!='9')
        returnValue=-1;

    else
        returnValue=0;

    return returnValue;
}

/* Method to mark on board*/
int markBoard(char mark)
{
    if(choice==1 && board[1]=='1')
        board[1]=mark;

    else if(choice==2 && board[2]=='2')
        board[2]=mark;

    else if(choice==3 && board[3]=='3')
        board[3]=mark;

    else if(choice==4 && board[4]=='4')
        board[4]=mark;

    else if(choice==5 && board[5]=='5')
        board[5]=mark;

    else if(choice==6 && board[6]=='6')
        board[6]=mark;

    else if(choice==7 && board[7]=='7')
        board[7]=mark;

    else if(choice==8 && board[8]=='8')
        board[8]=mark;

    else if(choice==9 && board[9]=='9')
        board[9]=mark;

    else
    {
        printf("\nInvalid Move!!!\n");
        getchar();
    }

}
