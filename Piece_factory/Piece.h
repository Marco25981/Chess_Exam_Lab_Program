#ifndef PIECE_H
#define PIECE_H

#include <cctype>
#include <map>
#include <vector>
#include <algorithm>

    //IDENTIFICARE COLORE SQUADRA
    enum Color
    {
        WHITE=1,
        BLACK=2,
        ENDGAME=0
    };

    //IDENTIFICARE IL TIPO DI PEZZO
    enum Character
    {
        PAWN=0,
        BISHOP=1,
        KNIGHT=2,
        QUEEN=3,
        KING=4,
        ROCK=5
    };

    //IDENTIFICARE IL NUMERO DELLA COLONNA
    enum Colomn
    {
        A=0,
        B=1,
        C=2,
        D=3,
        E=4,
        F=5,
        G=6,
        H=7   
    };

class Piece
{
private:

    int row,coloum,square;
    char name_piece;
    bool is_moved;

    Color color;
    Character type_piece;

    std::vector<int> legal_moves;
    std::map<int,std::vector<int>> map_path;          
                                            
                                        //Funzionamento delle mosse:
                                        //+8 scendi alla cella inferiore
                                        //-8 sali alla cella superiore
                                        //+1 vo a destra
                                        //-1 vo a sinistra 

public:
    /*------COSTRUTTORE-------------*/
    Piece(int pos, char c);
    /*------FINE COSTRUTTORE--------*/

    /*-----------GETTER-------------*/

        int get_row() const;
        int get_col() const;
        int get_square() const;

        char get_name_piece() const;

        bool get_ismoved() const;
        bool is_legal_move(int square) const;

        Color get_color() const;
        
        std::vector<int> get_legal_moves() const;
        std::map<int,std::vector<int>> get_map_path() const;

        bool is_pawn();
        bool is_rock();
        bool is_king();
    /*-----------FINE GETTER-------------*/

    /*-----------SETTER------------------*/

        void set_row(int new_row);
        void set_col(int new_col);
        void set_square(int new_square);

        void set_name_piece(char new_name);

        void set_ismoved(bool new_moved);

        void set_color(Color new_color);

        void set_legal_moves(std::vector<int> new_legal_moves);
        
    /*-----------FINE SETTER------------------*/

    /*-----------FUNZIONI-----------------*/

        void diagonal_move(Piece* board[64], std::vector<int> &legal_moves);
        void straight_move(Piece* board[64], std::vector<int> &legal_moves);
    
        std::vector<int> check_is_king(Piece* board[64], Piece *King);
    
        void add_legal_move(int square);
        void remove_legal_move(int square);
    
    /*-----------FINE FUNZIONI-----------------*/
    
    /*-----------FUNZIONI VIRTUALI----------*/
    
        virtual void update_legal_moves(Piece*board[64])=0;
    
    /*-----------FINE FUNZIONI VIRTUALI----------*/

    virtual ~Piece()= default;
};



#endif //PIECE_H