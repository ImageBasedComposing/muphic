//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("glSkeleton.res");
USEFORM("UFP.cpp", GLForm2D);
USEFORM("controlsForm.cpp", Form1);
USEUNIT("Pincel.cpp");
USEUNIT("Escena.cpp");
USEUNIT("lista\Lista.cpp");
USEUNIT("lista\Nodo.cpp");
USEUNIT("DibujoLineas.cpp");
USEUNIT("Segmento.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TGLForm2D), &GLForm2D);
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
