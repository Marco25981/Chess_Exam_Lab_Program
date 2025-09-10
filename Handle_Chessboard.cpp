#include "Handle_Chessboard.h"

//Costruttore:
Handle_Chessboard::Handle_Chessboard()
{
    fen_string="rnbqkbnr/pppppppp/8/8/PPPPPPPP/RNBQKBNR - w KQkq - 0 1";
    turn=WHITE;

    //Imposto la scacchiera alla fase iniziale
    set_board_fenstring(fen_string);
    update_move_pieces();
}

//Imposta la scacchiera con la fen
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

//Aggiorna i movimenti dei pezzi
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

//Genera la fen_string
std::string Handle_Chessboard::generate_fen_string()
{
    //Imposto la fen_string e il contatore nella posizione iniziale
    std::string fen_string="";
    int count_no_piece=0;

    //Devo iterare tutto nelle caselle della scacchiera:
    //Prima le righe:
    for(int row=0; row<8; row++)
    {
        //Poi le colonne
        for(int col=0; col<8; col++)
        {
            //Controllo se nella posizione tot c'è un pezzo:
            if(piece[row*8+col]==nullptr)
            {
                count_no_piece++;
            }
            else    //Se non c'è allora:
            {
                //Controllo se il contatore è numerato
                if(count_no_piece>0)
                {
                    //Prima metto gli eventuali spazi vuoti
                    fen_string+= std::to_string(count_no_piece);
                    
                    //Poi imposto il contatore a 0
                    count_no_piece=0;
                }
                
                //E poi ovviamente inserisco il pezzo puntato.
                fen_string+=piece[row*8+col]->get_name_piece();

            }
        }

        //Fine della riga:
        //Prima controllo se il contatore è positivo:
        if(count_no_piece>0)
        {
            fen_string+=std::to_string(count_no_piece);
            count_no_piece=0;
        }
        //Nella fen per dire che finisce la riga si usa '/'
        if(row==6)
        {
            fen_string+='/';
        }
    }

    //TODO: Migliorare la generazione della fen con altre cose se possibile
    
    //Esempio fare un textctrl che stampa ogni volta la posizione di tutto insomma dai te lo
    //devo spiegare io? no....
    
    return fen_string;

}

//Aggiungi la fen alla mappa
void Handle_Chessboard::add_fen_to_map(std::string fen_string)
{
    //Metto ++ perchè teoricamente una stringa è fatta da tante char 
    //quindi aggiungo una char e poi ne aggiungo un altra con ++
    this->occurences_position[fen_string]++;
}

//Crea il pezzo
Piece* Handle_Chessboard::create_piece(char c, int square)
{
    switch (c)
    {

    //Caso Pedone:
    case 'p':
    case 'P':
        return new Pawn(square,c);
    
    //Caso Torre:
    case 'r':
    case 'R':
        return new Rock(square,c);
    
    //Caso Alfiere:
    case 'b':
    case 'B':
        return new Bishop(square,c);
    
    //Caso Re:
    case 'k':
        black_king=new King(square,c);
        return black_king;

    case 'K':
        white_king= new King(square,c);
        return white_king;
    
    //Caso Cavallo:
    case 'n':
    case 'N':
        return new Knight(square,c);

    //Caso Donna:
    case 'q':
    case 'Q':
        return new Queen(square,c);
    
    

    default:
        return nullptr; //Carattere sbagliato allora...
    }
}

void Handle_Chessboard::handle_move(int from_square, int to_square)
{
    Movement_Handler move;
    move.set_from_square(from_square);
    move.set_to_square(to_square);
    move.set_piece(piece[from_square]);

    //Gestione di controllo movimenti con legal_moves:
    //Se il movimento del pezzo non appartiene alla posizione finale
    //della scacchiera...
    if(!move.get_piece()->is_legal_move(to_square))
    {
        return;
    }

    this->count_draw++;

    //Movimenti pezzo:
    //Se nella posizione finale c'è un pezzo....
    if(piece[to_square] != nullptr)
    {
        move.set_captured_piece(piece[to_square]);
        move.set_captured_piece_type(piece[to_square]->get_name_piece());

        delete piece[to_square];    //---->non capisco questo...
        this->count_draw=0;
    }
    //Sennò:
    else
    {
        move.set_captured_piece(nullptr);
        move.set_captured_piece_type(' ');
    }

    piece[to_square]= move.get_piece();
    piece[from_square]= nullptr;

    //Il movimento del pedone resetta il count_draw a 0
    if(move.get_piece()->is_pawn())
    {
        this->count_draw=0;
    }

    //Aggiorna la casella del pezzo:
    move.get_piece()->set_square(to_square);

    //Aggiorna il movimento del pezzo: 
    move.get_piece()->set_ismoved(true);

    //Aggiungi la mossa allo stack

    //this->addMoveToStack(move);
    //this->handleEnPassantCapture();
    //this->moveRookOnCastle();
    //this->changeTurn();
}   

void Handle_Chessboard::add_move_to_stack(Movement_Handler move)
{
    //move_stack.push(&move);
    //TODO!!
}
