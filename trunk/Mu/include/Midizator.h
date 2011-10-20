#ifndef MIDIZATOR_H
#define MIDIZATOR_H

#include <string>

using namespace std;

class Midizator
{
    public:
        Midizator();
        virtual ~Midizator();

        string toMidi(); //no recuerdo como evitar recursividad asiq ue no se como poner el music de aqui

    protected:
    private:
};

#endif // MIDIZATOR_H
