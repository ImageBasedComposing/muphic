#pragma once

#ifndef MUSIC_H
#define MUSIC_H

#include <string>

#include "Outputs/Midizator.h"
#include "Music/Voces.h"
#include "Music/Acorde.h"
#include "Music/music_elements.h"

using namespace std;

class Midizator;

class Music
{
public:

    /* TYPE DECLARATION */
    /*
    	typedef int Clave;
    	struct Metrica {
    		int upper;
    		int lower;
    		Metrica(int a = 4, int b = 4)
    		{
    			upper = a;
    			lower = b;
    		}
    	};
    	typedef int Tempo;
    	/*
    /* TYPE DECLARATION */

    Music();
    Music(Midizator* mdztor);
    virtual ~Music();

    string toMidi();

    /*------Getters------*/
    string getName();
    string getComposer();

    // Realmente nos da igual la clave que use, es meramente gráfico
    //Clave getClave();

    pair<int,int> getBaseLenght();

    Voces* getVoces();
    Midizator* getMidizator();

    /*------Setters------*/
    void setName(string n);
    void setComposer(string c);
    //void setClave(Clave c);

    //Este es el campo L. Por defecto debe ser L=1/8
    void setBaseLenght(pair<int,int> baseLenght);

    void setVoces(Voces* v);
    void setMidizator(Midizator* m);
	
	void changeTempo(int t);

protected:

private:
    string name;
    string composer;
    Voces* voces;
    pair<int,int> bl;

    Midizator* midizator;
};

#endif // MUSIC_H
