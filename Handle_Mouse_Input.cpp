#include "Handle_Mouse_Input.h"

Handle_Mouse_Input::Handle_Mouse_Input(Draw_board* ptr)
    :mouse_ptr(ptr)
{
    wxLogMessage("Entro in Handle_Mouse_Input");
}

void Handle_Mouse_Input::OnMouseLeftUp(wxMouseEvent& event)
{
    /*wxPoint point=event.GetPosition();
    mouse_x=point.x/();
    mouse_y=point.y/(draw->GetClientSize().GetWidth()/8);
    */
    wxLogMessage("ei");
  
}

Handle_Mouse_Input::~Handle_Mouse_Input()
{

}