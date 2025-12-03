#include "Handle_Mouse_Input.h"

Handle_Mouse_Input::Handle_Mouse_Input(Draw_board* ptr,
    std::shared_ptr<Handle_Fen_String> fen,
    Movement_Piece* move,
    Handle_Chessboard* chess)
    :mouse_ptr(ptr),    
     fen_smart(fen),
     handle_movement(move),
     handle_chessboard(chess)    
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
    mouse_ptr->Refresh();
    
}

void Handle_Mouse_Input::onMouseLeftUp(wxMouseEvent& event)
{
    //wxLogMessage(wxT("entro in onleftup"));
    //Controllo preliminare:
    if(!is_select_piece || select_piece==-1 || handle_piece==nullptr)
    {
        return;
    }
    //So già che square_size è 56 da Draw_board
    int square_size=56;

    //Ottengo coordinate di rilascio del mouse:
    int release_row= mouse_x/square_size;
    int release_col= mouse_y/square_size;
    int release_square= release_row*8+release_col;

    handle_movement->handle_move(select_piece,release_square);

    is_select_piece=false;
    handle_piece=nullptr;
    select_piece=-1;

    mouse_ptr->Refresh();
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


}