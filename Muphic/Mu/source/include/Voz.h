#ifndef VOZ_H
#define VOZ_H

#include "Simbolos.h"

using namespace std;

class Voz
{
    public:

        /* Por ahora definimos los tipos como enteros */

        typedef int Instrumento;

        Voz();
        virtual ~Voz();

/*------Getters------*/
        int getInstrumento();
        Simbolos getSimbolos();

/*------Setters------*/
        void setInstrumento(int i);
        void setSimbolos(Simbolos s);

    protected:

    private:
        Instrumento instrumento;
        Simbolos simbolos;
};

#endif // VOZ_H
