#ifndef FUNCTIONS_H
    #define FUNCTIONS_H
    #include "setup.h"
    void Perform_Help(Grid* canvas);
    void Perform_Quit(Grid* canvas);
    void Free_Grid(Grid* canvas);
    void Perform_Erase(Grid* canvas);
    void Perform_Resize(Grid* canvas);
    void Perform_Add(Grid* canvas);
    void Add_Row(Grid* canvas, int pos);
    void Add_Column(Grid* canvas, int pos);
    void Perform_Delete(Grid* canvas);
    void Delete_Row(Grid* canvas, int pos);
    void Delete_Column(Grid* canvas, int pos);
    void Perform_Save(Grid* canvas);
    void Perform_Load(Grid* canvas);
#endif