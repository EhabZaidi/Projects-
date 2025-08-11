#ifndef GAME_H
    #define GAME_H
    #include <stdlib.h>
    
    void PlayGame(int* num_rows, int* num_columns, int* pieces, char** grid);
    void PlayerTurn(int* num_rows, int* num_columns, int* pieces, char** grid, int* curr_player);
    void Switch_player(int* curr_player);
    void Player_1_turn(int* num_rows, int* num_columns, int* pieces, char** grid, int* curr_player);
    void Player_2_turn(int* num_rows, int* num_columns, int* pieces, char** grid, int* curr_player);
    void UpdateGrid(int* num_rows, char** grid, int user_column, int* curr_player);
    bool full_column(int* num_rows, char** grid, int user_column);

#endif