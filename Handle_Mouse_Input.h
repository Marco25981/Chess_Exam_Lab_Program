#ifndef HANDLE_MOUSE_INPUT_H
#define HANDLE_MOUSE_INPUT_H

#include <wx/wx.h>
#include "Piece_factory/Piece.h"
#include "Handle_Fen_String.h"
#include <memory>

class Draw_board;   //class declaration perchè se faccio classico include mi entra nel
                    //famosissimo loop e scoppia tutto il programma

class Handle_Mouse_Input
{
private:
    int mouse_x, mouse_y, select_piece;
    
    bool is_select_piece;

    std::shared_ptr<Handle_Fen_String> fen_smart;
    
    Draw_board* mouse_ptr=nullptr;
    Piece* handle_piece=nullptr;  
public:
    Handle_Mouse_Input(Draw_board* ptr,
        std::shared_ptr<Handle_Fen_String> fen);

    void OnMouseLeftUp(wxMouseEvent& event);
    
    ~Handle_Mouse_Input();
};


#endif //HANDLE_MOUSE_INPUT_H