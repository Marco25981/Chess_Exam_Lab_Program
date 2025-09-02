#ifndef DRAW_BOARD_H
#define DRAW_BOARD_H

#include "start/MyProjectBase.h"
#include <wx/wx.h>

/*
    NOTE:
    Il mio programma crea le celle e inizia da 0,0.
    Quindi se provo a inserire un immagine a caso e la imposto in 0,0 mi da come
    posizione alto a sinistra quindi siccome il primo blocco del log ha coordinata 
    0,0 allora parto dall'alto e proseguo fino al basso.
    Le diagonali quindi a destra +1 a sinistra -1 in basso +8 e in alto -8, combinando
    e facendo le somme trovo anche le diagonali.
*/

class Draw_board: public MyPanel1
{
private:
    /* data */
    int selected_square;

    /*-------------Per il re-------------*/
    wxBitmap resized;
    wxImage image;
    
    //percorso del file 
    wxString file="/home/marco/Documenti/Visual_Studio_Code_esercizi/es13Creare_wxBitmap/image/K.png";
    
    static const int image_width=70;
    static const int image_height=70;
    
    wxBitmapType format= wxBITMAP_TYPE_PNG;
    /*----------------------------------*/

public:
    //Costruttore
    Draw_board(wxFrame* parent);

    //Disegno dei quadratini
    void draw_squares(wxDC& dc, int row, int col, wxCoord square_size);

    //Funzione del re
    void render_whiteking(wxDC& dc);

    //Disegno principale
    void on_paint(wxPaintEvent& evt);

    //Gestione ridimensionamento finestra
    void OnSize(wxSizeEvent& event);
    
};

#endif //DRAW_BOARD_H