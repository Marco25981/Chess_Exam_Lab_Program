#include "Handle_Mouse_Input.h"

Handle_Mouse_Input::Handle_Mouse_Input(Draw_board* ptr,
    std::shared_ptr<Handle_Fen_String> fen)
    :mouse_ptr(ptr),    
     fen_smart(fen)    
{    
    int count=fen_smart.use_count();
    wxLogMessage("Counter: %d",count);
}

void Handle_Mouse_Input::OnMouseLeftUp(wxMouseEvent& event)
{
    wxPoint point=event.GetPosition();
    
    mouse_x=point.x;
    mouse_y=point.y;

    int square_size=56;     //da cambiare se cambia lo square_size di draw_board
                            //ps, potrei creare una variabile dinamica in draw 
                            //così non sto a rompermi il cazzo

    int clicked_row=mouse_y/square_size;
    int clicked_col=mouse_x/square_size;

    wxLogMessage("x: %d, y: %d", clicked_row, clicked_col);

    Piece *handle_piece1=fen_smart.get()->get_piece()[clicked_row*8+clicked_col];

    if(handle_piece1==nullptr)
    {
        return;
    }

    is_select_piece=true;
    select_piece=clicked_row*8+clicked_col;
    
    handle_piece=fen_smart.get()->get_piece()[select_piece];

    
}

Handle_Mouse_Input::~Handle_Mouse_Input()
{


}