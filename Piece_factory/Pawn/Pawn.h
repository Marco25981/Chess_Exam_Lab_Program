#ifndef PAWN_H
#define PAWN_H

#include "../Piece.h"

class Pawn: public Piece
{
private:
    /* data */
public:
    Pawn(int pos, char character);
    
    void update_legal_moves(Piece*board[64]) override;

    void handle_movement(Piece* board[64], std::vector<int>& legal_moves);
    void handle_offensive(Piece* board[64], std::vector<int>& legal_moves);
    void handle_en_passant(int square);
};


#endif //PAWN_H