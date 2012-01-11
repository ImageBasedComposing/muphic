//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
#include <vcl.h>
#include <string>
#pragma hdrstop
USERES("muphic_viewer.res");
USEFORM("UFP.cpp", GLForm2D);
USEUNIT("Escena.cpp");
USEUNIT("Figura.cpp");
USEUNIT("Figuras.cpp");
USEUNIT("tinystr.cpp");
USEUNIT("tinyxml.cpp");
USEUNIT("tinyxmlerror.cpp");
USEUNIT("tinyxmlparser.cpp");
USEUNIT("Vertice.cpp");
USEUNIT("Pincel.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TGLForm2D), &GLForm2D);
         Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------

#endif
