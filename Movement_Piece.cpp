#include "Movement_Piece.h"

Movement_Piece::Movement_Piece()
    //Inializzazione puntatori:
    :create(new Create_Piece()),
    fen(new Handle_Fen_String())
    {  
        fen->fen_string_stuff();
           
    }
/*-------------GETTER------------------*/
int Movement_Piece::get_from_square()
{
    return from_square;
}

int Movement_Piece::get_to_square()
{
    return to_square;
}

Piece* Movement_Piece::get_piece()
{
    return piece1;
}

Piece* Movement_Piece::get_captured_piece()
{
    return captured_piece;
}

char Movement_Piece::get_captured_piece_type()
{
    return captured_piece_type;
}
/*-------------FINE GETTER------------------*/

/*-------------SETTER------------------*/
void Movement_Piece::set_from_square(int new_from_square)
{
    from_square=new_from_square;
}

void Movement_Piece::set_to_square(int new_to_square)
{
    to_square=new_to_square;
}

void Movement_Piece::set_piece(Piece* new_piece)
{
    piece1=new_piece;
}

void Movement_Piece::set_captured_piece(Piece* new_captured_piece)
{
    captured_piece=new_captured_piece;
}

void Movement_Piece::set_captured_piece_type(char new_captured_piece_type)
{
    captured_piece_type=new_captured_piece_type;
}
/*-------------FINE SETTER------------------*/

//Funzione che serve a ottenere il puntatore singolo nella scacchiera:
Piece** Movement_Piece::get_board()
{
    return piece;
}
