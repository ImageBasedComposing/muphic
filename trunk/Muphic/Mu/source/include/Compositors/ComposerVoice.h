#pragma once

#ifndef COMPOSERVOICE_H
#define COMPOSERVOICE_H

#include <string>
#include "Music/music_elements.h"
#include "Music/music_const.h"
#include "Music/FigureMusic.h"
#include "Music/Segmento.h"
#include "Music/TableScale.h"
#include "Music/instruments.h"

using namespace std;

class ComposerVoice
{
    public:
		ComposerVoice(ColorSystem* cs){ this->cs = cs; this->tb = NULL;};
		ComposerVoice(ColorSystem* cs, TableScale* tb){ this->cs = cs; this->tb = tb;};
		virtual ~ComposerVoice(){};

		//virtual bool composeVoice(FigureMusic* f, Segmento* seg, int dur, int maxDur = HALFNOTE, int minDur = EIGHTHNOTE, Segmento* seg1 = NULL){return false;};
		virtual bool composeVoice(FigureMusic* f, Segmento* seg, int dur, int maxDur, int minDur){return false;};
		virtual bool composeVoice(FigureMusic* f, Segmento* seg, int dur, int maxDur){return false;};
		virtual bool composeVoice(FigureMusic* f, Segmento* seg, int dur){return false;};

		//virtual bool compMelodyFig(FigureMusic* f, Segmento* seg, int dur, int maxDur = HALFNOTE, int minDur = EIGHTHNOTE){return false;};
		virtual bool compMelodyFig(FigureMusic* f, Segmento* seg, int dur, int maxDur, int minDur){return false;};
		virtual bool compMelodyFig(FigureMusic* f, Segmento* seg, int dur, int maxDur){return false;};
		virtual bool compMelodyFig(FigureMusic* f, Segmento* seg, int dur){return false;};

		//virtual bool decMelodyFig(FigureMusic* f, Segmento*seg1, Segmento* seg, int dur, int maxDur = HALFNOTE, int minDur = EIGHTHNOTE){return false;};
		virtual bool decMelodyFig(FigureMusic* f, Segmento*seg1, Segmento* seg, int dur, int maxDur, int minDur){return false;};
		virtual bool decMelodyFig(FigureMusic* f, Segmento*seg1, Segmento* seg, int dur, int maxDur){return false;};
		virtual bool decMelodyFig(FigureMusic* f, Segmento*seg1, Segmento* seg, int dur){return false;};

		//virtual bool compBassFig(FigureMusic* f, Segmento* seg, int dur, int maxDur = HALFNOTE, int minDur = EIGHTHNOTE){return false;};
		virtual bool compBassFig(FigureMusic* f, Segmento* seg, int dur, int maxDur, int minDur){return false;};
		virtual bool compBassFig(FigureMusic* f, Segmento* seg, int dur, int maxDur){return false;};
		virtual bool compBassFig(FigureMusic* f, Segmento* seg, int dur){return false;};

		//virtual bool compRythmFig(FigureMusic* f, Segmento* seg, int dur, int maxDur = HALFNOTE, int minDur = EIGHTHNOTE){return false;};
		virtual bool compRythmFig(FigureMusic* f, Segmento* seg, int dur, int maxDur, int minDur){return false;};
		virtual bool compRythmFig(FigureMusic* f, Segmento* seg, int dur, int maxDur){return false;};
		virtual bool compRythmFig(FigureMusic* f, Segmento* seg, int dur){return false;};

/*------Getters------*/
		inline ColorSystem* getColorSystem(){return cs;};
		inline TableScale* getTableScale(){return tb;};
		inline int getTypeScale(){return typeScale;};
		inline vector<int> getInstruments(){return instruments;};
		inline int getInstrument(){return instruments.front();};

/*------Setters------*/
		void setColorSystem(ColorSystem* cs){this->cs = cs;}
		void setTableScale(TableScale* tb){this->tb = tb;};
		void setTypeScale(int t){this->typeScale = t;};
		void setInstruments(vector<int> i){instruments = i;};

    protected:
		ColorSystem* cs;
		TableScale* tb;
		int typeScale;
		vector<int> instruments;
};

#endif // COMPOSERVOICE_H
