#ifndef ENDGAME_H
    #define ENDGAME_H
    #include <stdbool.h>

    bool game_is_over(int* num_rows, int* num_columns, int* pieces, char** grid);
    bool game_is_tie(int* num_rows, int* num_columns, int* pieces, char** grid);
    bool player_1_wins(int* num_rows, int* num_columns, int* pieces, char** grid);
    bool player_2_wins(int* num_rows, int* num_columns, int* pieces, char** grid);
    bool board_full(int* num_rows, int* num_columns, char** grid);
    bool win_horizontally(int* num_rows, int* num_columns, int* pieces, char** grid, char player_piece);
    bool win_vertically(int* num_rows, int* num_columns, int* pieces, char** grid, char player_piece);
    bool win_diagonally(int* num_rows, int* num_columns, int* pieces, char** grid, char player_piece);
    bool win_left_diagonal(int* num_rows, int* num_columns, int* pieces, char** grid, char player_piece);
    bool win_right_diagonal(int* num_rows, int* num_columns, int* pieces, char** grid, char player_piece);
    void announce_results(int* num_rows, int* num_columns, int* pieces, char** grid);

#endif
