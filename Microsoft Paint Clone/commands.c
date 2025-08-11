#include <stdio.h>
#include <stdbool.h>
#include "commands.h"
#include "functions.h"
#include "setup.h"
#include "write.h"

/*
The following function paints on the canvas
It takes the following values as parameters:
canvas = The address of the user-defined datat type which holds the canvas on which the user paints
It does not return anything
*/
void Paint(Grid* canvas){
    char character;
    Commands command;
    printf("Enter your command: ");
    int num_args_read = scanf(" %c", &character);

    while(!isValidInput(1, num_args_read, false) || !isaCommand(character, &command)){
    printf("Unrecognized command. Type h for help.\n");
    printf("Enter your command: ");
    num_args_read = scanf(" %c", &character);
    }

    User_Command(&command, canvas);
}

/*
The following function checks if the user entered one of the commands
It takes the following values as parameters:
canvas = The address of the user-defined datat type which holds the canvas on which the user paints, command = The address of the user-defined data type that contains the list of commands
It returns either true or false
*/
bool isaCommand(char character, Commands* command){
    if(character == 'q'){
        *command = Quit;
        return true;
    }
    else if(character == 'h'){
        *command = Help;
        return true;
    }
    else if(character == 'w'){
        *command = Write;
        return true;
    }
    else if(character == 'e'){
        *command = Erase;
        return true;
    }
    else if(character == 'r'){
        *command = Resize;
        return true;
    }
    else if(character == 'a'){
        *command = Add;
        return true;
    }
    else if(character == 'd'){
        *command = Delete;
        return true;
    }
    else if(character == 's'){
        *command = Save;
        return true;
    }
    else if(character == 'l'){
        *command = Load;
        return true;
    }
    else{
        return false;
    }
}

/*
The following function paints on the canvas
It takes the following values as parameters:
canvas = The address of the user-defined datat type which holds the canvas on which the user paints, command = The address of the user-defined data type that contains the list of commands
It does not return anything
*/
void User_Command(Commands* command, Grid* canvas){
    switch(*command){
        case Quit:
        Perform_Quit(canvas);
        break;
        case Help:
        Perform_Help(canvas);
        break;
        case Write:
        Perform_Write(canvas);
        break;
        case Resize:
        Perform_Resize(canvas);
        break;
        case Add:
        Perform_Add(canvas);
        break;
        case Delete:
        Perform_Delete(canvas);
        break;
        case Erase:
        Perform_Erase(canvas);
        break;
        case Save:
        Perform_Save(canvas);
        break;
        case Load:
        Perform_Load(canvas);
        break;
    }
    Paint(canvas);
}