#include "Movement_Handler.h"

Movement_Handler::Movement_Handler()
{

}

/*-------------GETTER------------------*/
int Movement_Handler::get_from_square()
{
    return from_square;
}

int Movement_Handler::get_to_square()
{
    return to_square;
}

Piece* Movement_Handler::get_piece()
{
    return piece;
}

Piece* Movement_Handler::get_captured_piece()
{
    return captured_piece;
}

char Movement_Handler::get_captured_piece_type()
{
    return captured_piece_type;
}
/*-------------FINE GETTER------------------*/

/*-------------SETTER------------------*/
void Movement_Handler::set_from_square(int new_from_square)
{
    from_square=new_from_square;
}

void Movement_Handler::set_to_square(int new_to_square)
{
    to_square=new_to_square;
}

void Movement_Handler::set_piece(Piece* new_piece)
{
    piece=new_piece;
}

void Movement_Handler::set_captured_piece(Piece* new_captured_piece)
{
    captured_piece=new_captured_piece;
}

void Movement_Handler::set_captured_piece_type(char new_captured_piece_type)
{
    captured_piece_type=new_captured_piece_type;
}
/*-------------FINE SETTER------------------*/



Movement_Handler::~Movement_Handler()
{
    delete piece;
    delete captured_piece;

    piece=nullptr;
    captured_piece=nullptr;
}


