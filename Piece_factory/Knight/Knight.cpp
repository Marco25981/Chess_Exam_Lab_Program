#include "Knight.h"

Knight::Knight(int pos, char character)
    :Piece(pos,character)
    {

    }


void Knight::update_legal_moves(Piece*board[64])
{
    std::vector<int> legal_moves {};
    handle_movement(board,legal_moves);
}

void Knight::handle_movement(Piece*board[64],std::vector<int>&legal_moves)
{
    int directions[8]={17,15,10,-6,6,-10,-15,-17};
    

    for(int i=0; i<8; i++)
    {
        int square= this->get_square()+directions[i];
        //Se il quadrato selezionato è tra 0 e 64 && Il quadrato
        //selezionato è tra due colonne 
        if(square>=0 && square<64 && abs(this->get_col()-square %8)<3)
        {
            if(board[square]==nullptr || board[square]->get_color()!= this->get_color())
            {
                legal_moves.push_back(square);
            }
        }
        set_legal_moves(legal_moves);
    }



}
