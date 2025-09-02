#include "Handle_Chessboard.h"

Handle_Chessboard::Handle_Chessboard()
{
    fen_string="rnbqkbnr/pppppppp/8/8/PPPPPPPP/RNBQKBNR - w KQkq - 0 1";
    turn=WHITE;

    //Imposto la scacchiera alla fase iniziale
    set_board_fenstring(fen_string);
    update_move_pieces();
}

void Handle_Chessboard::set_board_fenstring(std::string fen)
{
    for(int i=0; i<64; i++)
    {
        piece[i]=nullptr;
    }

    //Prendo la fen per la schacchiera:
    std::string board_fen_string=fen.substr(0,fen.find(" "));

    //preparo le variabili per le righe e le colonne:
    int row=0;
    int col=0;

    for(char set_board : board_fen_string)
    {
        if(set_board=='/')
        {
            row++;
            col=0;
        }
        else 
        {
            if(std::isdigit(set_board))    //Controllo se ci sono numeri
            {
                int conv=set_board-'0'; //Nella conversione ASCII per avere 8 devo sottrare
                                        //il valore ASCII di 8 - il valore ASCII di 0 
                col+=conv;
            }
            else
            {
                //Creazione e posizionamento dei pezzi
                //piece[row*8+col]=create_piece(row*8+col,set_board);
                col++;
            }
        }
        
    }

}

void Handle_Chessboard::update_move_pieces()
{
    for(Piece*p:piece)
    {
        if(p!=nullptr)
        {
            p->update_legal_moves(piece);
        }
    }
}
