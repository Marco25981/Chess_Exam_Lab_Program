#include "Pawn.h"

Pawn::Pawn(int pos, char character)
    :Piece(pos,character)
    {

    }

/*---------FUNZIONE VIRTUALE------------------*/
void Pawn::update_legal_moves(Piece*board[64])
{
    std::vector<int> legal_moves={};
    
    this->handle_movement(board,legal_moves);
    this->handle_offensive(board,legal_moves);
    
    set_legal_moves(legal_moves);
}
/*---------FINE FUNZIONE VIRTUALE-------------*/

/*---------FUNZIONI DEL PEDONE-----------------*/
void Pawn::handle_movement(Piece*board[64], std::vector<int>& legal_moves)
{
    //Ovviamente il pedone si può muovere di una casella avanti 
    int directions[2]{8,16};

    //Se il pedone non si è mosso può sfruttare il doppio salto
    int stop_index=get_ismoved() ? 1 : 2;

    //Siccome la mia scacchiera parte con 00 la parte superiore
    //allora siccome il bianco parte dal lato inferiore della 
    //scacchiera allora devo sottrarre a un numero già grande 
    int color_team=this->get_color()==WHITE ? -1 : 1;

    //Parto con il ciclo, serve per poter dire se nel quadrato è 
    //presente un pezzo, sennò aggiungi la posizione alle mosse possibili e legali

    for(int i=0; i<stop_index; i++)
    {
        int square= this->get_square() + directions[i] * color_team;

        if(square>0 && square<64)
        {
            if(board[square]==nullptr)
            {
                legal_moves.push_back(square);
            }
            else
                break;
        }
    }
}

void Pawn::handle_offensive(Piece*board[64], std::vector<int>& legal_moves)
{
    
    int directions[2]{7,9};
    
    int color_team= this->get_color()==WHITE? -1 : 1;
    
    for(int i=0; i<2; i++)
    {
        this->get_map_path()[directions[i]]={};
        
        int square= this->get_square()+directions[i]*color_team;

        if(square>=0 && square < 64 && abs(this->get_col()- square %8)<=1)
        {
            if(board[square] != nullptr && this->get_color()!=board[square]->get_color())
            {
                legal_moves.push_back(square);
                this->get_map_path()[directions[i]].push_back(square);
            }
        }
    }

}

void Pawn::handle_en_passant(int square)
{
    std::vector<int> legal_moves = this->get_legal_moves();
    legal_moves.push_back(square);
    this->set_legal_moves(legal_moves);
}
/*-----------FINE FUNZIONI DEL PEDONE---------------*/
