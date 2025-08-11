#ifndef WRITE_H
    #define WRITE_H
    #include <stdbool.h>
    #include "setup.h"
    typedef struct Position{
    int start_row;
    int start_column;
    int end_row;
    int end_column;
    }Position;

    void Perform_Write(Grid* canvas);
    void Check_Line(Grid* canvas, Position position);
    bool Check_Horizontal(Position position);
    void PaintHorizontal(Grid* canvas, Position position);
    bool Check_Vertical(Position position);
    void PaintVertical(Grid* canvas, Position position);
    bool Check_Left_Diagonal(Position position);
    void PaintLeftDiagonal(Grid* canvas, Position position);
    bool Check_Right_Diagonal(Position position);
    void PaintRightDiagonal(Grid* canvas, Position position);

#endif
