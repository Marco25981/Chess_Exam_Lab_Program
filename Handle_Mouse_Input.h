#ifndef HANDLE_MOUSE_INPUT_H
#define HANDLE_MOUSE_INPUT_H

#include <wx/wx.h>

class Draw_board;

class Handle_Mouse_Input
{
private:
    int mouse_x, mouse_y;
    Draw_board* mouse_ptr=nullptr;
public:
    Handle_Mouse_Input(Draw_board* ptr);
    
    void OnMouseLeftUp(wxMouseEvent& event);
    
    ~Handle_Mouse_Input();
};


#endif //HANDLE_MOUSE_INPUT_H