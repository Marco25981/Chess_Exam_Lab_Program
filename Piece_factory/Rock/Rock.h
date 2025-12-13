#ifndef ROCK_H
#define ROCK_H

#include "../Piece.h"

class Rock: public Piece
{
private:
    
public:
    /*-----------Costruttore-----------------*/

    Rock(int coordinate,char character);
    
    /*------------Fine Costruttore-----------*/

    /*----Funzione virtuale aggiornamento----*/
    
    void update_legal_moves(std::shared_ptr<Handle_Fen_String> ptr_smart) override;
    
    /*----Fine funzione virtuale aggiornamento----*/
    
};


#endif //ROCK_H