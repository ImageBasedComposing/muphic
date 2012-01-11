//---------------------------------------------------------------------------

#ifndef UFPH
#define UFPH
//---------------------------------------------------------------------------
#include <math.h>
#include <stdio.h>

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>

#include <gl\gl.h>
#include <gl\glu.h>

#include "Escena.h"

//---------------------------------------------------------------------------

class TGLForm2D : public TForm
{

__published:	// IDE-managed Components
    TStatusBar *statusBar;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormResize(TObject *Sender);
    void __fastcall FormPaint(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall FormMouseWheelDown(TObject *Sender, TShiftState Shift,
          TPoint &MousePos, bool &Handled);
    void __fastcall FormMouseWheelUp(TObject *Sender, TShiftState Shift,
          TPoint &MousePos, bool &Handled);
    void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall FormMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
public:
    __fastcall TGLForm2D(TComponent* Owner);

// User declarations

    private:
        HDC hdc;
        HGLRC hrc;

        // métodos privados
        void __fastcall SetPixelFormatDescriptor();
        void __fastcall GLScene();

        // User Declarations
        Escena* escena;
        bool roamingOn;
        int lastMX, lastMY;

    public:

};
//---------------------------------------------------------------------------
extern PACKAGE TGLForm2D *GLForm2D;
//---------------------------------------------------------------------------
#endif
