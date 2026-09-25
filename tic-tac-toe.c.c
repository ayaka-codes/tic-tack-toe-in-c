#include<stdio.h>
char winner(char board[3][3]);
int main(){
    char board[3][3]={
    {' ', ' ', ' '},
    {' ', ' ', ' '},                                                                    // board layout
    {' ', ' ', ' '}
};


int row;
int column;
int turn=0;

for(turn=0;turn<9;turn++){

    if(turn%2==0){
        printf("player X, your turn... \n");                                        //tells whos turn it is
    }
    else
     {
        printf("player O, your turn... \n");
     }
  
    
    printf("enter row: ");
        scanf("%d",&row);
        printf("\n enter column: ");                                                    //user enters target site
        scanf("%d",&column);
        
         if(row<0 || row>2 || column<0 || column>2){                                  //to make sure target site isnt outside the grid
        printf(" brother that's outside the map T-T \n");
        turn--;
        continue;
    }

     if(board[row][column] == ' ')
     {
        if(turn%2==0){    
        board[row][column] = 'X';                                       //place's x / o if target site is empty
        }  
        else
        {
            board[row][column]='O';
        } 


        printf(" %c | %c | %c \n",board[0][0],board[0][1],board[0][2]);
        printf("___|___|___\n");
        printf(" %c | %c | %c \n",board[1][0],board[1][1],board[1][2]);             //prints the updated board
        printf("___|___|___\n");
        printf(" %c | %c | %c \n",board[2][0],board[2][1],board[2][2]);

        char result = winner(board);
        if(result != ' '){
            printf("winner is: %c \n",result);                                      //tells who the winer is at the end
            break;
        }

     }   
     else
     {
           printf(" there is something there 'entity cant be placed' \n");              //makes sure there is no illegal move placed
           turn--;                                                                       
           continue;                                                                     
    }

}
if(turn >=9){
    printf("it's a draw");                                                  //tells if it's a draw
}


return 0;
}

char winner(char board[3][3])
{                                                                                   //checks all the conditions for winning
    for(int i=0;i<3;i++)
    {
      if    (board[i][0]==board[i][1] &&                                    //row
            board[i][1]==board[i][2] &&
            board[i][0] != ' ' ) 
        {
            return board[i][0];
        }
    }

    for(int i=0;i<3;i++){
        if(board[0][i]==board[1][i] &&                                       //column
            board[1][i]==board[2][i] &&
            board[0][i] != ' '){
                return board[0][i];
            }
    }

    if(board[0][0]==board[1][1] && board[1][1]==board[2][2] &&                  //diagonals
        board[0][0] != ' '){
        return board[0][0];
    }
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && 
       board [0][2] != ' '){
        return board[0][2];
    }
    return ' ';
}

