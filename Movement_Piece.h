#ifndef MOVEMENT_PIECE_H
#define MOVEMENT_PIECE_H

#include <iostream>
#include <wx/wx.h>
#include <memory>
#include <stack>

#include "Piece_factory/Piece.h"
#include "Handle_Fen_String.h"
#include "Move.h"

class Draw_board;

class Movement_Piece
{
private:
    int draw_counter;

    std::stack<Move*>stack;

    Draw_board* draw=nullptr;

    Move *move=nullptr;

    std::shared_ptr<Handle_Fen_String> fen_shared;
public:
    Movement_Piece(Draw_board* board, std::shared_ptr<Handle_Fen_String> fen);

    void handle_move(int from, int to);
    void update_moves_all_piece();
    //void set_enpassant_square();
    //void add_move_to_stack(Move *m);
};

#endif //MOVEMENT_PIECE_H