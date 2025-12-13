#include "Queen.h"
#include "../../Handle_Fen_String.h"

Queen::Queen(int position, char character)
    :Piece(position,character)
    {

    }

void Queen::update_legal_moves(std::shared_ptr<Handle_Fen_String> ptr_smart) 
{
    std::vector<int> legal_moves={};

    const auto& board= ptr_smart.get()->get_piece();

    straight_move(board,legal_moves);
    diagonal_move(board,legal_moves);
    
    set_legal_moves(legal_moves);
}