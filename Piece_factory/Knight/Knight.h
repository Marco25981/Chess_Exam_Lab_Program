#ifndef KNIGHT_H
#define KNIGHT_H

#include "../Piece.h"

class Knight: public Piece
{
private:
    /* data */
public:
    Knight(int pos, char character);
    
    void update_legal_moves(std::shared_ptr<Handle_Fen_String> ptr_smart) override;
    void get_attack(Piece **board, std::vector<int> &attacked_squares) override;

    void handle_movement(Piece**board, std::vector<int>& legal_moves);
};



#endif //KNIGHT_H