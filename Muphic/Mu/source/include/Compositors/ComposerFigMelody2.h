#pragma once

#ifndef COMPOSERFIGMELODY2_H
#define COMPOSERFIGMELODY2_H

#include "Compositors/ComposerVoice.h"
#include "Music/music_elements.h"
#include "Music/Nota.h"


class FiguresMusic;

using namespace std;

class ComposerFigMelody2 : public ComposerVoice
{

	protected:

		//Funciones auxiliares:
		int getNextDegreeTone(int degree, double actualAngle, double lastAngle, int lastTone);
		int getNextTone(int degree, double actualAngle, double lastAngle, int lastTone, int actualDuration, int lastDuration);
		int makeConsonant(int tone, int toneToModif);
		void adaptDurations(vector<int>* durations, int duration, int minDur = EIGHTHNOTE, int maxDur = HALFNOTE);
		vector< int > calcDurDirect(FigureMusic * f, vector< Vertice* > vertices, int maxDur = HALFNOTE, int minDur = EIGHTHNOTE);
		vector< int > calcTonesDiff(FigureMusic * f, vector< Vertice* > vertices, vector<int> duraciones);
		vector< int > calcTonesCounterPoint(FigureMusic * f, vector< Vertice* > vertices, Segmento* seg1, int pos, vector<int> duraciones);

    public:
		ComposerFigMelody2(ColorSystem* cs);
		ComposerFigMelody2(ColorSystem* cs, TableScale* tbScale);
		virtual ~ComposerFigMelody2();

		//Se pide que haga una melodia dada una figura. Devuelve el segmento con la melodia
		inline bool compMelodyFig(FigureMusic* f, Segmento* seg, int dur){ return compMelodyFig(f,seg,dur,HALFNOTE,EIGHTHNOTE);};
		inline bool compMelodyFig(FigureMusic* f, Segmento* seg, int dur, int maxDur){ return compMelodyFig(f,seg,dur,maxDur,EIGHTHNOTE);};
		bool compMelodyFig(FigureMusic* f, Segmento* seg, int dur, int maxDur, int minDur);

		inline bool decMelodyFig(FigureMusic* f, Segmento* seg1, Segmento* seg, int dur){ return decMelodyFig(f,seg1,seg,dur,HALFNOTE,EIGHTHNOTE);};
		inline bool decMelodyFig(FigureMusic* f, Segmento* seg1, Segmento* seg, int dur, int maxDur){ return decMelodyFig(f,seg1,seg,dur,maxDur,EIGHTHNOTE);};
		bool decMelodyFig(FigureMusic* f, Segmento* seg1, Segmento* seg, int dur, int maxDur, int minDur);

		inline bool compBassFig(FigureMusic* f, Segmento* seg, int dur){ return compBassFig(f,seg,dur,HALFNOTE,EIGHTHNOTE);};
		inline bool compBassFig(FigureMusic* f, Segmento* seg, int dur, int maxDur){ return compBassFig(f,seg,dur,maxDur,EIGHTHNOTE);};
		bool compBassFig(FigureMusic* f, Segmento* seg, int dur, int maxDur, int minDur);

		bool composeVoice(FigureMusic* f, Segmento* seg, int dur, int maxDur = HALFNOTE, int minDur = EIGHTHNOTE, Segmento* seg1 = NULL);
		bool interMelodyFig(FigureMusic* f, Segmento* seg1, Segmento* seg, int dur, int maxDur = HALFNOTE, int minDur = EIGHTHNOTE);
		
		



/*------Getters------*/

/*------Setters------*/

};


#endif