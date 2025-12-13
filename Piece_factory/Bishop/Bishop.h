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
    
    void update_legal_moves(std::shared_ptr<Handle_Fen_String> ptr_smart) override;

};



#endif //BISHOP_H