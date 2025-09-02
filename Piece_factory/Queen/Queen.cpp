#include "Queen.h"

Queen::Queen(int position, char character)
    :Piece(position,character)
    {

    }

void Queen::update_legal_moves(Piece* board[64]) 
{
    std::vector<int> legal_moves={};
    straight_move(board,legal_moves);
    diagonal_move(board,legal_moves);
    set_legal_moves(legal_moves);
}