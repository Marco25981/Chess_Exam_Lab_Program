#include "Movement_Piece.h"

Movement_Piece::Movement_Piece
(
    Draw_board* board, 
    std::shared_ptr<Handle_Fen_String> fen,
    Handle_Chessboard *chess
) 
    :draw(board),
    fen_shared(fen),
    handle_chess(chess)
{  
    
}

void Movement_Piece::handle_move(int from, int to)
{
    //Creo la nuova mossa:
    Move move;
    move.set_from_square(from);
    move.set_to_square(to);

    const auto &piece = fen_shared.get()->get_piece();

    //Gestisco la legalità dei pezzi:
    move.set_piece_status(piece[move.get_from_square()]);

    if(!move.get_piece_status()->is_legal_move(move.get_to_square()))
    {
        wxLogMessage(wxT("Mossa non legale"));
    }
    //Tutto okay, incremento il contatore del pareggio:
    this->draw_counter++;

    //Gestisco la cattura:
    if(piece[move.get_to_square()]!=nullptr)
    {
        //puntatore al pezzo catturato andrà al to_square:
        move.set_piece_captured(piece[move.get_to_square()]);
        
        //Voglio sapere che tipo di carattere è....
        move.set_character_captured(piece[move.get_to_square()]->get_name_piece());
        
        //elimino il pezzo puntato dal carattere ucciso:
        delete piece[move.get_to_square()];
        
        //riporto a zero il contatore del pareggio pk se mangio reset
        this->draw_counter=0;
    }
    //Se non c'è nessun pezzo ad ostacolare la mossa legale allora:
    else
    {
        //Metto piece_captured=nullptr, per forza non mangia quindi è nullptr
        move.set_piece_captured(nullptr);
        //il personaggio catturato sarà ovviamente vuoto:
        move.set_character_captured(' ');
    }
    piece[move.get_to_square()]=move.get_piece_status();
    piece[move.get_from_square()]=nullptr;

    if(move.get_piece_status()->is_pawn())
    {
        this->draw_counter=0;
    }
    move.get_piece_status()->set_square(move.get_to_square());
    move.get_piece_status()->set_ismoved(true); 
    
    //RIGENERA LA NUOVA FEN_STRING:
    std::string new_fen= fen_shared.get()->generate_fen_string();
    fen_shared.get()->add_fen_to_map(new_fen);
}

void Movement_Piece::update_moves_all_piece()
{
    const auto& piece=fen_shared.get()->get_piece();
    for(int i=0; i<64; ++i)
    {
        if(piece[i])
        {
            piece[i]->update_legal_moves(fen_shared);
        }
    }
}

std::vector<int> Movement_Piece::get_path_to_king(Piece *king)
{
    //const auto& piece=fen_shared.get()->get_piece();

    int a_prova= 10;
    wxLogMessage(wxT("%d"),a_prova);
    for(int i=0; i<64; i++)
    {
        if(fen_shared.get()->get_piece()[i]!=nullptr)
        {
            for(const auto& entry: fen_shared.get()->get_piece()[i]->get_map_path())
            {   
                wxLogMessage(wxT("entro nel loop di entry get_path_king"));
                //wxLogMessage("Il pezzo è: %c",fen_shared.get()->get_piece()[i]->get_name_piece());
                auto const& direction = entry.first;
                auto const& path = entry.second;
                int a_path=path.size();
                
                
                for(auto square : path)
                {
                    wxLogMessage(wxT("entro nel loop di path get_path_king"));
                    

                    if(fen_shared.get()->get_piece()[square]==king)
                    {
                        wxLogMessage(wxT("Trovato il percorso del re"));
                        return fen_shared.get()->get_piece()[square]->get_map_path()[direction];
                    }
                }
                return {};
            }
        }
    }
    return {};
    
}