//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFP.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGLForm2D *GLForm2D;
//---------------------------------------------------------------------------
__fastcall TGLForm2D::TGLForm2D(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TGLForm2D::FormCreate(TObject *Sender)
{
    hdc = GetDC(Handle);
    SetPixelFormatDescriptor();
    hrc = wglCreateContext(hdc);
    if(hrc == NULL)
    	ShowMessage(":-)~ hrc == NULL");
    if(wglMakeCurrent(hdc, hrc) == false)
    	ShowMessage("Could not MakeCurrent");
    //Cor de fondo de la ventana
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    //inicialización del volumen de vista y la escena
    escena = new Escena(-100, 400, 200, -200);
    //escena = new Escena(-200, 200, 200, -200);

    //escena->resize(escena->f->sheetWidth, escena->f->sheetHeight);

    LPTSTR s = GetCommandLine();
    std::string command(s);
    std::string xmlFile;
    int i = command.find_first_of(" ");
    if ( i > 0)
        xmlFile = command.substr(i + 1, command.size() - 1);

    if (xmlFile.size() == 0)
        xmlFile = "test1.xml";
        
    escena->cargar(xmlFile);
    roamingOn = false;

    lastMX = escena->centerX;
    lastMY = escena->centerY;
    statusBar->SimpleText = "Scroll = Zoom | Left-Click & Move = Move screen | Right-Click = Reset";

}
//---------------------------------------------------------------------------
void __fastcall TGLForm2D::SetPixelFormatDescriptor()
{
    PIXELFORMATDESCRIPTOR pfd = {
    	sizeof(PIXELFORMATDESCRIPTOR),
        1,
        PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
        PFD_TYPE_RGBA,
        32,
        0,0,0,0,0,0,
        0,0,
        0,0,0,0,0,
        32,
        0,
        0,
        PFD_MAIN_PLANE,
        0,
        0,0,0
    };
    int PixelFormat = ChoosePixelFormat(hdc, &pfd);
    SetPixelFormat(hdc, PixelFormat, &pfd);
}
//---------------------------------------------------------------------
void __fastcall TGLForm2D::FormResize(TObject *Sender)
{
    //se actualiza puerto de vista y su radio
    if ((ClientWidth<=1)||(ClientHeight<=1))
    {
        ClientWidth=400;
        ClientHeight=400;
    }

    glViewport(0,0,ClientWidth,ClientHeight);

    escena->resize(ClientWidth, ClientHeight);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(escena->getxL(),escena->getxR(), escena->getyB(), escena->getyT());


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    GLScene();
}
//---------------------------------------------------------------------------
void __fastcall TGLForm2D::GLScene()
{
    glClear(GL_COLOR_BUFFER_BIT);

    escena->render();

    glFlush();
    SwapBuffers(hdc);
}

//---------------------------------------------------------------------------
void __fastcall TGLForm2D::FormPaint(TObject *Sender)
{
    GLScene();
}
//---------------------------------------------------------------------------
void __fastcall TGLForm2D::FormDestroy(TObject *Sender)
{
    ReleaseDC(Handle,hdc);
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hrc);

    // eliminar objetos creados
    delete escena;
}
void __fastcall TGLForm2D::FormMouseWheelDown(TObject *Sender,
      TShiftState Shift, TPoint &MousePos, bool &Handled)
{
    escena->zoomOut();
    GLScene();
}
//---------------------------------------------------------------------------
void __fastcall TGLForm2D::FormMouseWheelUp(TObject *Sender,
      TShiftState Shift, TPoint &MousePos, bool &Handled)
{
    escena->zoomIn();
    GLScene();
}
//---------------------------------------------------------------------------

void __fastcall TGLForm2D::FormMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if (Button == mbRight)
    {
        escena->specialCenter();
        FormResize(this);
        return;
    }
    
    roamingOn = true;
}
//---------------------------------------------------------------------------

void __fastcall TGLForm2D::FormMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if (Button == mbRight)
    {
        return;
    }

    roamingOn = false;
}
//---------------------------------------------------------------------------

void __fastcall TGLForm2D::FormMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
    if (roamingOn)
    {
        escena->move(-X + lastMX, Y - lastMY);
        GLScene();
    }

    lastMX = X;
    lastMY = Y;
}
//---------------------------------------------------------------------------

