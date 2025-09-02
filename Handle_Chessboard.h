#ifndef HANDLE_CHESSBOARD_H
#define HANDLE_CHESSBOARD_H

#include <string>

#include "Piece_factory/Piece.h"

class Handle_Chessboard
{
private:
    /* data */
    std::string fen_string; //La fen descrive la posizione 
                            //dei pezzi sulla scacchiera
    
    Piece *piece[64];   //Serve per controllare i pezzi
                        //tramite puntatore nella scacchiera

    Color turn;
public:
    //Costruttore
    Handle_Chessboard();
    

    //Ad ogni mossa le mosse legali dovranno essere aggiornate
    void update_move_pieces();


    //Funzione che serve all'inizio a far posizionare i pezzi
    void set_board_fenstring(std::string fen_string);
};

#endif //HANDLE_CHESSBOARD_H