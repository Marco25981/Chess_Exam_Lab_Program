#ifndef BISHOP_H
#define BISHOP_H

#include "../Piece.h"

#include <vector>

class Bishop: public Piece
{
private:
    /* data */
public:
    Bishop(int position, char character);
    
    void update_legal_moves(Piece*board[64]) override;

};



#endif //BISHOP_H