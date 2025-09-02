#include "King.h"

//Costruttore
King::King(int position, char character)
    :Piece(position,character)
    {

    }

//Getter
bool King::get_is_check() const
{
    return is_check;
}

//Funzione virtuale
void King::update_legal_moves(Piece*board[64])
{
    std::vector<int> legal_moves={};

}


//Funzione del movimento del re
void King::handle_movement(Piece*board[64], std::vector<int> legal_moves)
{
    int direction[8]={8,7,9,1,-1,-7,-8,-9};
    

    for(int i=0; i<8; i++)
    {
        int square=this->get_square()+direction[i];

        if(square>=0 && square<64 && abs(this->get_col()-square %8)<=1)
        {
            if(board[square]==nullptr)
            {
                legal_moves.push_back(square);
            }
            else if(board[square]->get_color()!=this->get_color())
            {
                legal_moves.push_back(square);
            }
        }
    }
}