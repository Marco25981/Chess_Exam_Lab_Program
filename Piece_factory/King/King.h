#ifndef KING_H
#define KING_H

#include "../Piece.h"
class King: public Piece
{
private:
    bool is_check;
public:
    //Costruttore
    King(int position, char character);
    
    //Getter
    bool get_is_check() const;

    //Funzione virtuale
    void update_legal_moves(Piece*board[64]) override;

    //Funzioni del re
    void handle_movement(Piece*board[64], std::vector<int> legal_moves);
    void handle_arrok(Piece*board[64]);

};



#endif //KING_H