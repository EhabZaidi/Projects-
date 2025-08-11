#ifndef COMMANDS_H
    #define COMMANDS_H
    #include <stdbool.h>
    #include "setup.h"
    typedef enum Commands{
    Quit, Help, Write, Erase, Resize, Add, Delete, Save, Load
    }Commands;
    void Paint(Grid* canvas);
    bool isaCommand(char character, Commands* command);
    void User_Command(Commands* command, Grid* canvas);

#endif