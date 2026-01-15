#ifndef QUEEN_H
#define QUEEN_H

#include "../Piece.h"

class Queen: public Piece
{
private:
    /* data */
public:
    Queen(int position, char character);
    
    void update_legal_moves(std::shared_ptr<Handle_Fen_String> ptr_smart) override;
    void get_attack(Piece **board, std::vector<int> &attacked_squares) override;
};



#endif //QUEEN_H