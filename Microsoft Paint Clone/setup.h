#ifndef SETUP_H
    #define SETUP_H
    #include <stdbool.h>

    typedef struct Grid{
    int rows;
    int columns;
    char** grid;
    }Grid;

    bool isValidInput(const int num_args_needed, const int num_args_read, bool should_be_last_value_on_line);
    void GetCommandLineValues(int* rows, int* columns, char** argv);
    void SetUpCanvas(int* rows, int* columns, Grid* canvas);
    void PrintCanvas(Grid* canvas);

#endif