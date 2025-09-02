#include "Bishop.h"

Bishop::Bishop(int position, char character)
    :Piece(position,character)
{

}

void Bishop::update_legal_moves(Piece*board[64])
{
    std::vector<int> legal_moves={};
    diagonal_move(board,legal_moves);
    set_legal_moves(legal_moves);
}


