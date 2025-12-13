#include "Bishop.h"
#include "../../Handle_Fen_String.h"

Bishop::Bishop(int position, char character)
    :Piece(position,character)
{

}

void Bishop::update_legal_moves(std::shared_ptr<Handle_Fen_String> ptr_smart)
{
    std::vector<int> legal_moves={};

    const auto& board=ptr_smart.get()->get_piece();

    diagonal_move(board,legal_moves);
    
    set_legal_moves(legal_moves);
}


