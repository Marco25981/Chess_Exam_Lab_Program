#include "Handle_Chessboard.h"

//Costruttore:
Handle_Chessboard::Handle_Chessboard()
{
    
}

void Handle_Chessboard::chessboard_stuff()
{
    //wxLogMessage("entro in chessboard_stuff");
    //Parte il bianco
    turn=WHITE;
}
void Handle_Chessboard::change_turn()
{
    if(turn==WHITE)
    {
        turn=BLACK;
    }
    else
        turn=WHITE;

    //TODO: Da finire
}

std::vector<Piece*> Handle_Chessboard::get_piece_turn()
{
    std::vector<Piece*> piece_turn={};

    for(Piece *piece: this->board)
    {
        if(piece!=nullptr && piece->get_color()==turn)
        {
            piece_turn.push_back(piece);
        }
    }
    return piece_turn;
}

std::vector<Piece*> Handle_Chessboard::get_no_piece_turn()
{
    std::vector<Piece*> piece_no_turn={};

    for(Piece*piece:this->board)
    {
        if(piece==nullptr && piece->get_color()!= turn)
        {
            piece_no_turn.push_back(piece);
        }
    }
    return piece_no_turn;
}

Color Handle_Chessboard::get_turn()
{
    return turn;
}



