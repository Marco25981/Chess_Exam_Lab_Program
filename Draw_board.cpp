#include "Draw_board.h"

Draw_board::Draw_board(wxFrame* parent)
    :MyPanel1(parent,6000,wxPoint(200,100)),game()
    {
        Bind(wxEVT_PAINT,&Draw_board::on_paint,this);
        
    }


void Draw_board::on_paint(wxPaintEvent& evt)
{
    wxPaintDC dc(this);
    wxSize size= GetClientSize();   //Prende la grandezza della bitmap(guarda in start)
    
    wxCoord square_size=size.GetWidth()/8; //Divido per 8 perchè ogni riga è formata da 8 caselle
       
    //square_size=56

    //Disegno la schacchiera:
    for(int row=0; row<8; row++)
    {
        for(int col=0; col<8; col++)
        {
            draw_squares(dc,row,col,square_size);
        }
    }

    //render_piece();
}

/*

    Note per capire bene come vengono disegnati i quadrati nel caso fai ooh cazzo fai...
    Allora la riga zero è la parte superiore insomma il lato alto del quadrato (la schacchiera)
    riga 1 e colonna 1 appartiene alla grande diagonale a destra quindi va da 0(su) a
    7 (giù).

*/

void Draw_board::draw_squares(wxDC& dc, int row, int col, wxCoord square_size)
{
    wxCoord x= col*square_size;
    wxCoord y= row*square_size;
    
    wxColor square_color;

    //Imposto il colore delle caselle...
    if((row+col)%2==0)
    {
        square_color = wxColor(185,182,174);           
    }
    else
    {
        square_color = wxColour(75, 115, 153);
    }

    dc.SetPen(*wxTRANSPARENT_PEN);

    if(selected_square==(row*8+col))
    {
        //Todo: fare il bordo esterno rotondo
    }

    dc.SetBrush(square_color);
    
    wxRect squareRect(x, y, square_size, square_size);
    
    dc.DrawRectangle(squareRect);
}

void Draw_board::draw_piece(wxDC& dc, int row, int col, wxCoord square_size)
{
    
}

void Draw_board::render_piece()
{
    
    char all_piece[]=
    {
        'b','k','n','p','q','r',
        'B','K','N','P','Q','R'
    };

    for(char piece:all_piece)
    {
        wxBitmap bitmap; 

        //Percorso del file:
        std::string path = "/home/marco/Documenti/Visual_Studio_Code_esercizi/es13Creare_wxBitmap/image/"+std::string(1,piece)+".png";

        //Verifico il caricamento dell'immagine:
        bool load_result = bitmap.LoadFile(path,wxBITMAP_TYPE_PNG);

        int square_size= GetClientSize().GetWidth()/8;
        
               

        //Dimensiona immagine 100x100
        if(load_result)
        {
            wxImage image= bitmap.ConvertToImage();
            image.Rescale(square_size,square_size,wxIMAGE_QUALITY_HIGH);
            bitmap=wxBitmap(image);

            chess_piece_bitmaps[piece]=bitmap;
        }
    }
    
}

void Draw_board::OnSize(wxSizeEvent& event)
{
    Refresh();
    //skip the event.
    event.Skip();
}
