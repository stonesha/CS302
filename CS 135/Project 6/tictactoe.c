/*
 ============================================================================
 Name        : Stone Sha
 Lab         : 1103
 Date        : 3/20/18
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

void clear_table();
void display_table();

void get_player1_move();
void generate_player2_move();
void update_table();
int check_legal_option();

int check_three_in_a_row();
int check_end_of_game();

/*void print_winner(board);

void check_end_of_game(board);*/


int main () 
 {
//Declare the tic-tac-toe board 
    
    char board[SIZE][SIZE]; 
//The row and column of the move for either player 1 or 2 
    
    int row, col; 
//Clear the table 
    
    clear_table(board); 
//Display the table 
    
    display_table(board); 
    
    /*do 
        
        { //Have player 1 enter their move 
            
            get_player1_move(board, row, col); 
//Generate player 2 move 
           
            generate_player2_move(board, row, col); 
//Do this while the game hasn't ended 
        
        }while(check_end_of_game(board) == false); 
//After the game is over, print who won 
            
            print_winner(board);*/
        
        return 0; 
}

void clear_table(char *board[SIZE][SIZE])
{

    int i = 0, j = 0;

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            board[i][j] = "_";
        }
    }
}

void display_table(char *board[SIZE][SIZE])
{

    printf("The current state of the game is:\n");

    int i = 0, j = 0;
        for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("%s ", board[i][j]);
        }
        printf("\n");
    }

}

void get_player1_move(char *board[SIZE][SIZE], int *row, int *col)
{

    int l;

    printf("Player 1 enter you're selection [row, col]: ");

    scanf("%d, %d", &row, &col);

    check_legal_option(board, row, col);

    if (l = 0)
    {
    //update_table(board, row, col);
    display_table(board);
    } else 
    {
        exit(0);
    }



    
}

void generate_player2_move(char *board[SIZE][SIZE], int *row, int *col)
{

    printf("Player 2 has entered [row, col]: ");



}

/*void update_table(char *board[SIZE][SIZE], int *row, int *col)
{


    board[*row][*col] = 'O';


}*/

int check_legal_option(char *board[SIZE][SIZE], int *row, int *col)
{

    if(*row > 2 || *row < 0)
    {
        return 1;
    } else if(*col > 2 || *col < 0)
    {
        return 1;
    } else {
        return 0;
    }

}


int check_three_in_a_row(char *board[SIZE][SIZE])
{
    //Vertical Check
    if((board[0][0] == board[0][1] && board[0][1] == board[0][2])
    ||(board[1][0] == board[1][1] && board[1][1] == board[1][2])
    ||(board[2][0] == board[2][1] && board[2][1] == board[2][2]))
    {return 1;}
    
    //Horizontal Check
    else if((board[0][0] == board[1][0] && board[1][0] == board[2][0])
    ||      (board[0][1] == board[1][1] && board[1][1] == board[2][1])
    ||      (board[0][2] == board[1][2] && board[1][2] == board[2][2]))
    {return 1;}
    
    //Diagonal Check
    else if((board[0][0] == board[1][1] && board[1][1] == board[2][2])
    ||    (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
    {return 1;}
    
    else
    {
        return 0;
    }
}

int check_end_of_game(char *board[SIZE][SIZE])
{
    int w;

    w = check_three_in_a_row(board);

    if(w = 1)
    {
        exit(0);
    } else
    {
        return 0;
    }


}

