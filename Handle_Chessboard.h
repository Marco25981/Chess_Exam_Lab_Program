#ifndef HANDLE_CHESSBOARD_H
#define HANDLE_CHESSBOARD_H

#include <string>
#include <stack>


#include "Piece_factory/Piece.h"
#include "Piece_factory/Pawn/Pawn.h"
#include "Piece_factory/Bishop/Bishop.h"
#include "Piece_factory/Queen/Queen.h"
#include "Piece_factory/King/King.h"
#include "Piece_factory/Knight/Knight.h"
#include "Piece_factory/Rock/Rock.h"

#include "Movement_Handler.h"

class Handle_Chessboard
{
private:
    King *white_king;   //Per gestire il check
    King *black_king;   //Per gestire il check

    Piece *piece[64];   //Serve per controllare i pezzi
                        //tramite puntatore nella scacchiera

    std::string fen_string; 

    Color turn;

    int count_draw;

    std::unordered_map<std::string,int> occurences_position;  
    
    std::stack<Handle_Chessboard> move_stack;
    
public:
    //Costruttore
    Handle_Chessboard();
    
    //Ad ogni mossa le mosse legali dovranno essere aggiornate
    void update_move_pieces();

    //Funzione che serve all'inizio a far posizionare i pezzi
    void set_board_fenstring(std::string fen_string);

    //Serve per generare la fen per descrivere la posizione dei pezzi
    std::string generate_fen_string();

    //Aggiungi la fen alla mappa
    void add_fen_to_map(std::string fen_string);

    //Crea il pezzo con la fen
    Piece*create_piece(char c, int square);
    
    //Gestione movimenti da casella a casella
    void handle_move(int from_square, int to_square);

    void add_move_to_stack(Movement_Handler move);
};

#endif //HANDLE_CHESSBOARD_H