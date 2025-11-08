#ifndef ES13_H
#define ES13_H

#include "wx/wx.h"
#include "start/MyProjectBase.h"
#include "Draw_board.h"
#include "Handle_Mouse_Input.h"

class Es13: public MyFrame1
{
private:
    Draw_board* board=nullptr;
public:
    /*Costruttore del form:*/
    Es13(wxWindow* parent);
    /*---------------------*/
    void open_panel(wxCommandEvent& event);
    
    void open_board(wxCommandEvent& event);

};



#endif //ES13_H