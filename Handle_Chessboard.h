#ifndef HANDLE_CHESSBOARD_H
#define HANDLE_CHESSBOARD_H

#include <vector>
#include <memory>

#include "Piece_factory/King/King.h"
#include "Handle_Fen_String.h"


class Handle_Chessboard
{
private:
    Color turn;  
    std::shared_ptr<Handle_Fen_String> handler_fen;
public:
    //Costruttore
    Handle_Chessboard(std::shared_ptr<Handle_Fen_String>fen);
    
    void change_turn();
    void set_turn(Color t);

    std::vector<Piece*> get_piece_turn();
    std::vector<Piece*> get_no_piece_turn();

    //----------GETTER----------------
    Color get_turn();
    //----------FINE GETTER----------------

    //~Handle_Chessboard();
};

#endif //HANDLE_CHESSBOARD_H