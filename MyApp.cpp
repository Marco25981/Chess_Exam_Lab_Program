#include "MyApp.h"

bool MyApp::OnInit()
{
    // make sure to call this first
    wxInitAllImageHandlers();
    
    MyFrame1*frame=new Es13(nullptr);
    frame->Show();
    return true;
}