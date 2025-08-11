#include <stdio.h>
#include <stdlib.h>
#include "validinput.h"
#include "setup.h"
#include "game.h"
#include "endgame.h"

#define addressOf(x) (&x)
#define valueAt(x) (*x)

/*
The function plays the game connect-n between 2 people
It takes the following parameters:
*num_rows = The address of where the number of rows is stored, *num_columns = The address of where the number of columns is stored
*pieces = The address of where the number of pieces needed to win is stored, **grid = The address of the grid used to play connect-n
*/
void PlayGame(int* num_rows, int* num_columns, int* pieces, char** grid){
    int current_player = 1; //First player plays first
    int* curr_player = &current_player;
    while(!game_is_over(num_rows, num_columns, pieces, grid)){
        PlayerTurn(num_rows, num_columns, pieces, grid, curr_player);
        Switch_player(curr_player);
    }
    if(game_is_over(num_rows, num_columns, pieces, grid)){
        announce_results(num_rows, num_columns, pieces, grid);
    }
}

/*
The function plays a player's turn depeding upon if its player 1 or 2
It takes the following parameters:
*num_rows = The address of where the number of rows is stored, *num_columns = The address of where the number of columns is stored
*pieces = The address of where the number of pieces needed to win is stored, **grid = The address of the grid used to play connect-n
*curr_player = The address which stores which player is playing
*/
void PlayerTurn(int* num_rows, int* num_columns, int* pieces, char** grid, int* curr_player){
    if(valueAt(curr_player) == 1){
        Player_1_turn(num_rows, num_columns, pieces, grid, curr_player);
    }
    else{
        Player_2_turn(num_rows, num_columns, pieces, grid, curr_player);
    }
}

/*
The function switches from player 1 to player 2 and vice versa
It takes the following parameters:
*curr_player = The address which stores which player is playing
*/
void Switch_player(int* curr_player){
    if(valueAt(curr_player) == 1){
        valueAt(curr_player) = 2;
    }
    else{
        valueAt(curr_player) = 1;
    }
}

/*
The function plays a player 1's turn by asking him where he wants to play his piece
It takes the following parameters:
*num_rows = The address of where the number of rows is stored, *num_columns = The address of where the number of columns is stored
*pieces = The address of where the number of pieces needed to win is stored, **grid = The address of the grid used to play connect-n
*curr_player = The address which stores which player is playing
*/
void Player_1_turn(int* num_rows, int* num_columns, int* pieces, char** grid, int* curr_player){
    int user_column, num_args_read, num_tries = 0;

    do{
    printf("Enter a column between 0 and %d to play in: ",valueAt(num_columns)-1);
    num_args_read = scanf(" %d", &user_column);
    if(num_tries == 30){
        printf("Exiting program due to too many failed attempts.");
        exit(0);
    }
    else{
        num_tries += 1;
    }
    }while(full_column(num_rows, grid, user_column)||!isValidInput(1, num_args_read) || (user_column<0 || user_column>=valueAt(num_columns)));

    UpdateGrid(num_rows, grid, user_column, curr_player);
    PrintGrid(num_rows, num_columns, grid);
}

/*
The function plays a player 2's turn by asking him where he wants to play his piece
It takes the following parameters:
*num_rows = The address of where the number of rows is stored, *num_columns = The address of where the number of columns is stored
*pieces = The address of where the number of pieces needed to win is stored, **grid = The address of the grid used to play connect-n
*curr_player = The address which stores which player is playing
*/
void Player_2_turn(int* num_rows, int* num_columns, int* pieces, char** grid, int* curr_player){
    int user_column, num_args_read, num_tries = 0;

    do{
    printf("Enter a column between 0 and %d to play in: ",valueAt(num_columns)-1);
    num_args_read = scanf(" %d", &user_column);
    if(num_tries == 30){
        printf("Exiting program due to too many failed attempts.");
        exit(0);
    }
    else{
        num_tries += 1;
    }
    }while(full_column(num_rows, grid, user_column)||!isValidInput(1, num_args_read) || (user_column<0 || user_column>=valueAt(num_columns)));
    UpdateGrid(num_rows, grid, user_column, curr_player);
    PrintGrid(num_rows, num_columns, grid);
}

/*
The function updates the grid based on where the player chose to play their piece
It takes the following parameters:
*num_rows = The address of where the number of rows is stored, **grid = The address of the grid used to play connect-n
user_column = The column the user chose to play his piece, *curr_player = The address which stores which player is playing
*/
void UpdateGrid(int* num_rows, char** grid, int user_column, int* curr_player){
    for(int i = 0; i<valueAt(num_rows); i++){
        if(grid[i][user_column] != '*'){
            if(grid[i+1][user_column] == '*'){
                if(valueAt(curr_player) == 1){
                grid[i+1][user_column] = 'X';
                break;
                }
                else{
                    grid[i+1][user_column] = 'O';
                    break;
                }
            }
            }
        else{
            if(valueAt(curr_player) == 1){
                grid[i][user_column] = 'X';
                break;
                }
            else{
                    grid[i][user_column] = 'O';
                    break;
                }
        }
        }
}

/*
The function checks if the column chosen by the user is full or not
It takes the following parameters:
*num_rows = The address of where the number of rows is stored, **grid = The address of the grid used to play connect-n
user_column = The column the user chose to play his piece in
*/
bool full_column(int* num_rows, char** grid, int user_column){
    bool column_status = false;
    int num_pieces = 0;
    for(int i = 0; i<valueAt(num_rows); i++){
        if(grid[i][user_column] != '*'){
            num_pieces += 1;
        }
    }
    if(num_pieces == valueAt(num_rows)){
        column_status = true;
        return column_status;
    }
    else{
        return column_status;
    }

}