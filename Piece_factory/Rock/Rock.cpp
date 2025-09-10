#include "Rock.h"


/*----Costruttore------*/
Rock::Rock(int coordinate, char character)
    :Piece(coordinate,character)
{

}
/*----Fine Costruttore----*/

void Rock::update_legal_moves(Piece*board[64])
{
    //imposto il vettore delle mosse legali a 0
    std::vector<int> legal_moves={};
    
    //Creo le mosse in avanti e le registro in legal moves  
    straight_move(board,legal_moves);
    
    //registro le nuove mosse legali nella variabile della classe base Piece
    set_legal_moves(legal_moves);
}
