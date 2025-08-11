#ifndef COMMANDLINE_H
    #define COMMANDLINE_H

    void GetCommandLineInput(char** args, int* num_rows, int* num_columns, int* num_pieces);
    void CheckNumArgs(int num_args, char** args, int* rows, int* columns, int* num_pieces);

#endif
