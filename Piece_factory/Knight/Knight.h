#ifndef KNIGHT_H
#define KNIGHT_H

#include "../Piece.h"

class Knight: public Piece
{
private:
    /* data */
public:
    Knight(int pos, char character);
    
    void update_legal_moves(Piece*board[64]) override;

    void handle_movement(Piece*board[64], std::vector<int>& legal_moves);



};



#endif //KNIGHT_H