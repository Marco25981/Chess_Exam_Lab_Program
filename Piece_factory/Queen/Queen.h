#ifndef QUEEN_H
#define QUEEN_H

#include "../Piece.h"

class Queen: public Piece
{
private:
    /* data */
public:
    Queen(int position, char character);
    
    void update_legal_moves(Piece* board[64]) override;
};



#endif //QUEEN_H