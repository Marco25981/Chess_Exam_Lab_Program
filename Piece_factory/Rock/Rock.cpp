#include "Rock.h"
#include "../../Handle_Fen_String.h"

/*----Costruttore------*/
Rock::Rock(int coordinate, char character)
    :Piece(coordinate,character)
{

}
/*----Fine Costruttore----*/

void Rock::update_legal_moves(std::shared_ptr<Handle_Fen_String> ptr_smart)
{
    //imposto il vettore delle mosse legali a 0
    std::vector<int> legal_moves={};
    
    const auto& board = ptr_smart.get()->get_piece();
    
    //Creo le mosse in avanti e le registro in legal moves  
    straight_move(board,legal_moves);
    
    //registro le nuove mosse legali nella variabile della classe base Piece
    set_legal_moves(legal_moves);
}
