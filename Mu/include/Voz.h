#ifndef VOZ_H
#define VOZ_H

#include "Simbolos.h"

class Voz
{
    public:
        Voz();
        virtual ~Voz();

/*------Getters------*/
        int getInstrumento();
        Simbolos* getSimbolos();

/*------Setters------*/
        void setInstrumento(int i);
        void setSimbolos(); //????

    protected:

    private:
        int instrumento;
        Simbolos* simbolos;
};

#endif // VOZ_H
