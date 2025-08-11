#include <stdbool.h>
#include <stdio.h>
#include "endgame.h"

#define addressOf(x) (&x)
#define valueAt(x) (*x)

/*
The function checks if the game is over or not
It takes the following parameters:
*num_rows = The address of where the number of rows is stored, *num_columns = The address of where the number of columns is stored
*pieces = The address of where the number of pieces needed to win is stored, **grid = The address of the grid used to play connect-n
*/
bool game_is_over(int* num_rows, int* num_columns, int* pieces, char** grid){
    if(game_is_tie(num_rows, num_columns, pieces, grid)||player_1_wins(num_rows, num_columns, pieces, grid)||player_2_wins(num_rows, num_columns, pieces, grid)){
        return true;
    }
    else{
        return false;
    }
}

/*
The function checks if the game is a tie or not
It takes the following parameters:
*num_rows = The address of where the number of rows is stored, *num_columns = The address of where the number of columns is stored
*pieces = The address of where the number of pieces needed to win is stored, **grid = The address of the grid used to play connect-n
*/
bool game_is_tie(int* num_rows, int* num_columns, int* pieces, char** grid){
    if(board_full(num_rows, num_columns, grid) && (!player_1_wins(num_rows, num_columns, pieces, grid) || !player_2_wins(num_rows, num_columns, pieces, grid))){
        return true;
    }
    else{
        return false;
    }
}

/*
The function checks if player 1 wins the game or not
It takes the following parameters:
*num_rows = The address of where the number of rows is stored, *num_columns = The address of where the number of columns is stored
*pieces = The address of where the number of pieces needed to win is stored, **grid = The address of the grid used to play connect-n
*/
bool player_1_wins(int* num_rows, int* num_columns, int* pieces, char** grid){
    if(win_horizontally(num_rows, num_columns, pieces, grid, 'X') || win_vertically(num_rows, num_columns, pieces, grid, 'X') || win_diagonally(num_rows, num_columns, pieces, grid, 'X')){
        return true;
    }
    else{
        return false;
    }
}

/*
The function checks if player 2 wins the game or not
It takes the following parameters:
*num_rows = The address of where the number of rows is stored, *num_columns = The address of where the number of columns is stored
*pieces = The address of where the number of pieces needed to win is stored, **grid = The address of the grid used to play connect-n
*/
bool player_2_wins(int* num_rows, int* num_columns, int* pieces, char** grid){
    if(win_horizontally(num_rows, num_columns, pieces, grid, 'O') || win_vertically(num_rows, num_columns, pieces, grid, 'O') || win_diagonally(num_rows, num_columns, pieces, grid, 'O')){
        return true;
    }
    else{
        return false;
    }
}

/*
The function checks if board is completely full or not
It takes the following parameters:
*num_rows = The address of where the number of rows is stored, *num_columns = The address of where the number of columns is stored
**grid = The address of the grid used to play connect-n
*/
bool board_full(int* num_rows, int* num_columns, char** grid){
    int total_pieces_played = 0;
    for(int i = 0; i<valueAt(num_rows); i++){
        for(int j = 0; j<valueAt(num_columns); j++){
            if(grid[i][j] != '*'){
                total_pieces_played +=1;
            }
        }
    }
    if(total_pieces_played == (valueAt(num_rows) * valueAt(num_columns))){
        return true;
    }
    else{
        return false;
    }
}

/*
The function checks if a player wins the game horizontally or not
It takes the following parameters:
*num_rows = The address of where the number of rows is stored, *num_columns = The address of where the number of columns is stored
*pieces = The address of where the number of pieces needed to win is stored, **grid = The address of the grid used to play connect-n
player_piece = The piece the player uses in the game
*/
bool win_horizontally(int* num_rows, int* num_columns, int* pieces, char** grid, char player_piece){
    for( int i = 0; i<valueAt(num_rows); i++){
        int num_player_pieces = 0;
        for(int j = 0; j<valueAt(num_columns); j++){
            if(grid[i][j] == player_piece){
                    num_player_pieces += 1;
            }
            else{
                num_player_pieces = 0;
                continue;
            }
            if(num_player_pieces == valueAt(pieces)){
                return true;
            }
        } 
    }
    return false;
}

/*
The function checks if a player wins vertically or not
It takes the following parameters:
*num_rows = The address of where the number of rows is stored, *num_columns = The address of where the number of columns is stored
*pieces = The address of where the number of pieces needed to win is stored, **grid = The address of the grid used to play connect-n
player_piece = The piece the player uses in the game
*/
bool win_vertically(int* num_rows, int* num_columns, int* pieces, char** grid, char player_piece){
    for(int j = 0; j<valueAt(num_columns); j++){
         int num_player_pieces = 0;
        for(int i = 0; i<valueAt(num_rows); i++){
            if(grid[i][j] == player_piece){
                    num_player_pieces += 1;
            }
            else{
                num_player_pieces = 0;
                continue;
            }
            if(num_player_pieces == valueAt(pieces)){
                return true;
            }
        }
    }
    return false;
}

/*
The function checks if a player wins diagonally or not
It takes the following parameters:
*num_rows = The address of where the number of rows is stored, *num_columns = The address of where the number of columns is stored
*pieces = The address of where the number of pieces needed to win is stored, **grid = The address of the grid used to play connect-n
player_piece = The piece the player uses in the game
*/
bool win_diagonally(int* num_rows, int* num_columns, int* pieces, char** grid, char player_piece){
    if(win_left_diagonal(num_rows, num_columns, pieces, grid, player_piece) || win_right_diagonal(num_rows, num_columns, pieces, grid, player_piece)){
        return true;
    }
    else{
        return false;
    }
}

/*
The function checks if a player wins through a left diagonal or not
It takes the following parameters:
*num_rows = The address of where the number of rows is stored, *num_columns = The address of where the number of columns is stored
*pieces = The address of where the number of pieces needed to win is stored, **grid = The address of the grid used to play connect-n
player_piece = The piece the player uses in the game
*/
bool win_left_diagonal(int* num_rows, int* num_columns, int* pieces, char** grid, char player_piece){
    for( int i = 0; i<valueAt(num_rows); i++){
        for(int j = 0; j<valueAt(num_columns); j++){
            int num_player_pieces = 0;
            if(grid[i][j] == player_piece){
            int b = j;
            for(int a = i; ((a<valueAt(num_rows))&&(b<valueAt(num_columns))); a++){
                if(grid[a][b] == player_piece){
                    num_player_pieces += 1;
                }
                else{
                    num_player_pieces = 0;
                    b++;
                    continue;
                }
                if(num_player_pieces == valueAt(pieces)){
                return true;
            }
            b++;
            }
            } 
        }
    }
    return false;
}

/*
The function checks if a player wins through a right diagonal or not
It takes the following parameters:
*num_rows = The address of where the number of rows is stored, *num_columns = The address of where the number of columns is stored
*pieces = The address of where the number of pieces needed to win is stored, **grid = The address of the grid used to play connect-n
player_piece = The piece the player uses in the game
*/
bool win_right_diagonal(int* num_rows, int* num_columns, int* pieces, char** grid, char player_piece){
    for( int i = 0; i< valueAt(num_rows); i++){
        for(int j = 0; j<valueAt(num_columns); j++){
            int num_player_pieces = 0;
            if(grid[i][j] == player_piece){
                int b = j;
            for(int a = i; (a>=0)&&(b<valueAt(num_columns)); a--){
                if(grid[a][b] == player_piece){
                    num_player_pieces += 1;
                }
                else{
                    num_player_pieces = 0;
                    b++;
                    continue;
                }
                 if(num_player_pieces == valueAt(pieces)){
                return true;
            }
            b++;
            }
     }
    }
}
    return false;
}

/*
The function announces the results based on if it is a tie or a player wins
It takes the following parameters:
*num_rows = The address of where the number of rows is stored, *num_columns = The address of where the number of columns is stored
*pieces = The address of where the number of pieces needed to win is stored, **grid = The address of the grid used to play connect-n
*/
void announce_results(int* num_rows, int* num_columns, int* pieces, char** grid){
    if(game_is_tie(num_rows, num_columns, pieces, grid)){
        printf("Tie game!");
    }
    if(player_1_wins(num_rows, num_columns, pieces, grid)){
        printf("Player 1 Won!");
    }
    if(player_2_wins(num_rows, num_columns, pieces, grid)){
        printf("Player 2 Won!");
    }
}