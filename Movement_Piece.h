#ifndef MOVEMENT_PIECE_H
#define MOVEMENT_PIECE_H

#include <stack>
#include <iostream>
#include <algorithm>

#include "Movement_Handler.h"
#include "Handle_Chessboard.h"
#include "Handle_Fen_String.h"
#include "Create_Piece.h"
#include "Piece_factory/Pawn/Pawn.h"
#include "Piece_factory/King/King.h"

class Movement_Piece//: public Movement_Handler
{
private:

    int from_square;
    int to_square;

    char captured_piece_type;
    int count_draw;

    Piece *piece[64];
    
    std::stack<Movement_Piece> move_stack;
    std::vector<Piece*> pieces_attacking;
    
    Create_Piece* create = nullptr;
    Handle_Fen_String* fen=nullptr;
    Piece *piece1 = nullptr;
    Piece *captured_piece = nullptr;
public:
    Movement_Piece();

    /*----  GETTER   ---*/
    int get_from_square();
    int get_to_square();
    Piece* get_piece();
    Piece* get_captured_piece();
    char get_captured_piece_type();
    /*----  FINE GETTER   ---*/
    
    /*----  SETTER   ---*/
    void set_from_square(int new_from_square);
    void set_to_square(int new_to_square);
    void set_piece(Piece* new_piece);
    void set_captured_piece(Piece* new_captured_piece);
    void set_captured_piece_type(char new_captured_piece_type);
    /*----  FINE SETTER   ---*/

    //Ottieni il singolo puntatore piece
    Piece** get_board();

    

};


#endif //MOVEMENT_PIECE_H