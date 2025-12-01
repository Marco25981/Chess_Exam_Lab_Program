#include "Handle_Mouse_Input.h"

Handle_Mouse_Input::Handle_Mouse_Input(Draw_board* ptr,
    std::shared_ptr<Handle_Fen_String> fen)
    :mouse_ptr(ptr),    
     fen_smart(fen),
     handle_chessboard(new Handle_Chessboard())    
{    
    
}

void Handle_Mouse_Input::onMouseLeftDown(wxMouseEvent& event)
{
    //wxLogMessage(wxT("Entro in mouseleftdown"));
    wxPoint point=event.GetPosition();
    
    mouse_x=point.x;
    mouse_y=point.y;

    int square_size=56;     //da cambiare se cambia lo square_size di draw_board
                            //ps, potrei creare una variabile dinamica in draw 
                            //così non sto a rompermi il cazzo

    int clicked_row=mouse_y/square_size;
    int clicked_col=mouse_x/square_size;

    Piece *piece_ptr=fen_smart.get()->get_piece()[clicked_row*8+clicked_col];
    
    is_select_piece=true;
    
    select_piece=clicked_row*8+clicked_col;
    
    //wxLogMessage(wxT("Il pezzo è selezionato? %d"),is_select_piece);
    //wxLogMessage(wxT("Il pezzo selezionato è della casella: %d"),select_piece);

    handle_piece=fen_smart.get()->get_piece()[select_piece]; 
    
}

void Handle_Mouse_Input::onMouseLeftUp(wxMouseEvent& event)
{
    wxLogMessage("entro in mouse_left_up");
}


bool Handle_Mouse_Input::get_is_select_piece() const
{
    return is_select_piece;
}

void Handle_Mouse_Input::set_is_select_piece(bool s)
{
    is_select_piece=s;
}

int Handle_Mouse_Input::get_selected_piece() const
{
    return select_piece;
}

Piece* Handle_Mouse_Input::get_handle_piece() const
{
    return handle_piece;
}

Handle_Mouse_Input::~Handle_Mouse_Input()
{
    delete handle_chessboard;
    handle_chessboard=nullptr;

}