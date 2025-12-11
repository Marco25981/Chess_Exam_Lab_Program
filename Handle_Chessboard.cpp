#include "Handle_Chessboard.h"

//Costruttore:
Handle_Chessboard::Handle_Chessboard
(
    std::shared_ptr<Handle_Fen_String>fen
)
    :handler_fen(fen)
    {
        turn=WHITE;
    }

Color Handle_Chessboard::get_turn()
{
    return turn;
}

void Handle_Chessboard::change_turn()
{
    if(turn==WHITE)
        turn==BLACK;
    else
        turn==WHITE;
}

void Handle_Chessboard::set_turn(Color t)
{
    turn=t;
}

std::vector<Piece*> Handle_Chessboard::get_piece_turn()
{
    std::vector<Piece*> piece_turn={};
    for
    (
        auto itr= handler_fen.get()->get_piece()[0];
        itr!= handler_fen.get()->get_piece()[64]; 
        ++itr
    )
    {
        if(itr->get_color()==get_turn())
        {
            piece_turn.push_back(itr);
        }
    }
    return piece_turn;
}

std::vector<Piece*> Handle_Chessboard::get_no_piece_turn()
{
    std::vector<Piece*> piece_no_turn={};
    for
    (
        auto itr= handler_fen.get()->get_piece()[0];
        itr!= handler_fen.get()->get_piece()[64]; 
        ++itr
    )
    if(itr->get_color()!=get_turn())
    {
        piece_no_turn.push_back(itr);
    }
    return piece_no_turn;
}