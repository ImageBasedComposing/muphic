#include "Outputs/MidizatorWAV.h"
//#include "aux_functions.h"
#include "math_functions.h"
#include "launcher.h"

#include <sstream>
#ifdef __LINUX
    #include <unistd.h>
    #include <sys/wait.h>
#endif

MidizatorWAV::MidizatorWAV()
{
	//ctor
}

MidizatorWAV::~MidizatorWAV()
{
    //dtor
}

string MidizatorWAV::toMidi(std::string music)
{
	Launcher* l = new Launcher();
	string args[] = { music};

	l->launch(1, Launcher::ABC2MIDI, args);

    //std::string output = changeExtension(music, "mid");

	return "";//output;
}

string MidizatorWAV::toMidi(Music* music)
{
	//Cosas de Cabecera Wav: ***************************************************************
	cout << "Creating a .wav file..." << endl;
		
		 //ofstream f;
		 //f.open("mazmorra.pferv",ios_base::binary);
         //BinaryWriter writer = new BinaryWriter(stream);

	FILE * fwav;
	fwav = fopen("test.wav", "wb");
	if (!fwav) {
		cout << "Couldn't open output file" << endl;
		return false;
	}

	int RIFF = 0x46464952;		// "RIFF" - Always
	//fileSize -> total size of file, calculate at the end
    int WAVE = 0x45564157;		// "WAVE" - Always
	int format = 0x20746D66;	// "fmt" - Always
    int formatChunkSize = 16;	// Length of format data - Normaly 16 (18 Non-PCMdata or 40 Extensible Format)
	short formatType = 1;		// Compresion 1=PCM
	short channels = 1;			// Tracks
	int samplesPerSecond = 11025; // Blocks per second, HQ(like-CD)=44100  
    
		short bitsPerSample = 16; // Normaly 8, 16 or 32
		short frameSize = (short)(channels * (bitsPerSample/8)); // Block Align 
    int bytesPerSecond = samplesPerSecond * frameSize; // total size in a second
	//frameSize is above
	//bitsPerSample is above
	int data = 0x61746164; //"data" - Always

    int waveSize = 4; //Always 4
	int headerSize = 8; // The header chunck (and subchunck) size, always 8 
	//Dummy data: (re-write at the end)
	int numSamples = 0; //Numero de samples hechos.
    int dataChunkSize = frameSize * numSamples; 
    int fileSize = headerSize + waveSize + headerSize + formatChunkSize + dataChunkSize; // ~65500 es el máximo tamaño (4bytes)
	//				   8      +     4    +     8      +        16       +     DATA

	if (fputs("RIFF", fwav) == EOF
		|| fwrite(&fileSize, sizeof(fileSize), 1, fwav) != 1
		|| fputs("WAVE", fwav) == EOF
		|| fputs("fmt ", fwav) == EOF
		|| fwrite(&formatChunkSize, sizeof(formatChunkSize), 1, fwav) != 1
		|| fwrite(&formatType, sizeof(formatType), 1, fwav) != 1
		|| fwrite(&channels, sizeof(channels), 1, fwav) != 1
		|| fwrite(&samplesPerSecond, sizeof(samplesPerSecond), 1, fwav) != 1
		|| fwrite(&bytesPerSecond, sizeof(bytesPerSecond), 1, fwav) != 1
		|| fwrite(&frameSize, sizeof(frameSize), 1, fwav) != 1
		|| fwrite(&bitsPerSample, sizeof(bitsPerSample), 1, fwav) != 1
		|| fputs("data", fwav) == EOF
		|| fwrite(&dataChunkSize, sizeof(dataChunkSize), 1, fwav) != 1)
	{
		cout << "Error writing header" << endl;
		return false;
	}
	
	//Fin cosas de Cabecera Wav ***************************************************************

	// Conseguimos las voces
	Voz* v;
	Segmento* s;
	Simbolo* simb;

	for( int i = 0; i < music->getVoces()->size(); i++)
	{
		v = music->getVoces()->getAt(i);

		// Trabajamos con cada segmento
		for( int j = 0; j < v->getSegmentos()->size(); j++)
		{
			s = v->getSegmentos()->getAt(j);

			int tempo = s->getTempo(); // BMP de negra
			int tempUnit = tempo*QUARTERNOTE;  //Semifusas por minuto (BMP)
			int tempUnitSec = tempUnit/60; //Cuantas semifusas en un segundo deben haber.
			int tempUnitSample = samplesPerSecond / tempUnitSec;  // Posible perdida de datos por aproximación. Dato de cuantos samples por semifusa (lo que se usa)
			int maxAmplitude = (pow(double(2), bitsPerSample)/2) - 20; //The maximum volumen
			int volumen = maxAmplitude/2; //Un valor cualquiera...
			double freq = 0; //The note

			int durNote = 0;
			short smple; //el propio sample
			double t = (PI * 2) / (samplesPerSecond * channels);

			// Trabajamos con cada símbolo
			for( int k = 0; k < s->getSimbolos()->size(); k++)
			{
				simb = s->getSimbolos()->getAt(k);

				//duracion de la nota según nuestro estandar
				durNote = simb->getDuracion(); 
				//Obtenemos la frecuencia
				freq = transfNote2Hz(((Nota*)simb)->getTono()); 
				//Sumamos lo que nos va a ocupar
				numSamples = numSamples + durNote*tempUnitSample; 

				for(int i = 0; i < durNote*tempUnitSample; i++)
				{
					smple = volumen * sin(t * i * freq); //usamos por defecto sin
					if(fwrite(&smple,sizeof(smple),1,fwav)!= 1)
						cout << "Error writing data in wav" << endl;
				}

			} // Simbolos
		} // Segmentos
	} //VocesS


	//Nos posicionamos para reescribir el tamaño total del archivo y el de los datos

	dataChunkSize = frameSize * numSamples; //Lo que ocupan los datos de verdad
	fileSize = headerSize + waveSize + headerSize + formatChunkSize + dataChunkSize; //Lo que ocupa el archivo en total

	if(fseek(fwav, headerSize + waveSize + headerSize + formatChunkSize + 4/*"data"*/, SEEK_SET /*at the beginning*/) != 0
		|| fwrite(&dataChunkSize, sizeof(dataChunkSize), 1, fwav) != 1)
	{
		cout << "Error re-writing header" << endl;
		return false;
	}

	if(fseek(fwav, 4/*"RIFF*/, SEEK_SET /*at the beginning*/) != 0
		|| fwrite(&fileSize, sizeof(fileSize), 1, fwav) != 1)
	{
		cout << "Error re-writing header" << endl;
		return false;
	}

	//Cerramos fichero
	fclose(fwav);

    return "test.wav";
}

double MidizatorWAV::transfNote2Hz(int note)
{
	switch(note){
	case SILENCIO: return 0; //Esto es por ahora, creo que no es la mejor solucion.
	case DO: return 32.70;
	case DO_S: return 34.65;
	case RE: return 36.71;
	case RE_S: return 38.89;
	case MI: return 41.20;
	case FA: return 43.65;
	case FA_S: return 46.25;
	case SOL: return 49.00;
	case SOL_S: return 51.91;
	case LA: return 55;
	case LA_S: return 58.27;
	case SI: return 61.74;
//
	case 13: return 65.41;
	case 14: return 69.30;
	case 15: return 73.42;
	case 16: return 77.78;
	case 17: return 82.41;
	case 18: return 87.31;
	case 19: return 92.50;
	case 20: return 98.00;
	case 21: return 103.83;
	case 22: return 110;
	case 23: return 116.54;
	case 24: return 123.47;
//
	case 25: return 130.81;
	case 26: return 138.59;
	case 27: return 146.83;
	case 28: return 155.56;
	case 29: return 164.81;
	case 30: return 174.61;
	case 31: return 185.00;
	case 32: return 196.00;
	case 33: return 207.65;
	case 34: return 220.00;
	case 35: return 233.08;
	case 36: return 246.94;
//	
	case DO_C: return 261.63;
	case DO_S_C: return 277.18;
	case RE_C: return 293.66;
	case RE_S_C: return 311.13;
	case MI_C: return 329.63;
	case FA_C: return 349.23;
	case FA_S_C: return 369.99;
	case SOL_C: return 392.00;
	case SOL_S_C: return 415.30;
	case LA_C: return 440.00;
	case LA_S_C: return 466.16;
	case SI_C: return 493.88;
//
	case 49: return 523.25;
	case 50: return 554.37;
	case 51: return 587.33;
	case 52: return 622.25;
	case 53: return 659.26;
	case 54: return 698.46;
	case 55: return 739.99;
	case 56: return 783.99;
	case 57: return 830.61;
	case 58: return 880.00;
	case 59: return 932.33;
	case 60: return 987.77;
//
	case 61: return 1046.50;
	case 62: return 1108.73;
	case 63: return 1174.66;
	case 64: return 1244.51;
	case 65: return 1318.51;
	case 66: return 1396.91;
	case 67: return 1479.98;
	case 68: return 1567.98;
	case 69: return 1661.22;
	case 70: return 1760.00;
	case 71: return 1864.66;
	case 72: return 1975.53;
//
	case 73: return 2093.00;
	case 74: return 2217.46;
	case 75: return 2349.32;
	case 76: return 2489.02;
	case 77: return 2637.02;
	case 78: return 2793.83;
	case 79: return 2959.96;
	case 80: return 3135.96;
	case 81: return 3322.44;
	case 82: return 3520.00;
	case 83: return 3729.31;
	case 84: return 3951.07;
	case 85: return 4186.01;
	default: return 440.00;
	}

}


string MidizatorWAV::imprimeNota(Simbolo* simbolo, pair<int,int> duracionBase)
{
	// Trabajamos con notas
	if (Nota* n = dynamic_cast<Nota *> (simbolo))
	{
		n = (Nota*) simbolo;

		return transformNota(n, duracionBase);
	} // Nota
	// Trabajamos con acordes
	else if (Acorde* a = dynamic_cast<Acorde *> (simbolo))
	{
		a = (Acorde*) simbolo;

		return transformAcorde(a, duracionBase);
	} // Acorde
	else
	{
		// LANZAR ERROR DE SÍMBOLO!!
		return "";
	}
}

string MidizatorWAV::transformNota(Nota* n, pair<int,int> duracionBase)
{  /*
	// salida debug
	std::stringstream ostr;
	ostr << "a" << n->getDuracion() << " ";
	return ostr.str();

	//return "a";
	*/
	string prefijo = ""; // Si tiene algo delante la nota (ej: ^ sostenido, ...)
	int tono = n->getTono(); //el tono que nos dan, si 0 es silencio
	int tonoModif; //la nota que cambiamos para sacar el sonido/tono que nos piden
	string sufijo = ""; // Los sufijos, vease la escala y la duracion
	string nota = ""; // La propia nota.

	//Primero consultamos la tabla y ponemos accidentes si los necesita:
	if(tono > 0)
		nota = tablaTransf->getNota(tono%ESCALA);
	else
		nota = "z"; //Tenemos un silencio.
	if(nota.empty()) //si no hemos recuperado una nota es que nos toca modificar alguna.
	{				 //No hay nota que sea como la que tenemos, pasamos a añadir accidente
		tonoModif = tablaTransf->setNuevaNota(tono%ESCALA);
		if( tonoModif != -1)
		{
			if( (tonoModif+1) == tono%ESCALA) //Le hemos puesto un sostenido
				prefijo += "^";
			else if ( tonoModif == 0)
				prefijo += "=";
			else
				prefijo += "_";

			//Ahora ya nos devuelve el char de la nota
			nota = tablaTransf->getNota(tono%ESCALA);
		}
		else
		{
			//LANZAR ERROR DE TRANSFORMACION!!
		}
	}

	//Ahora vamos a ver en que escala está:
	int numEscala = (tono-1)/ESCALA;
	if(tono > 0)
		switch(numEscala){
			case 0: sufijo += ",";
			case 1: sufijo += ",";
			case 2: sufijo += ","; //Se van acumulando las ','
			case 3:
				break; //Hasta aqui la escala central
			case 6: sufijo += "'";
			case 5: sufijo += "'";
			case 4: nota = *(nota.c_str()) + 32;  //Convertimos a Minusculas, imprescindible que nota sea un string de una sola letra
				break;
			default: break; //La dejamos en la escala central, Posible error out of range
		}
	else //Es un silencio, no hace falta añadirle escalas
		sufijo += "";

	// Y por ultimo la duración de la nota.
	int duracion = n->getDuracion();
	duracion = (duracion * duracionBase.second) / 64; //Ej: 16(negra) * 8/64 (nuestra L:1/8) = 2.
												//64 porque nuestra duración minima es semifusa, no contemplamos más abajo
	stringstream convertString; // stringstream used for the conversion

	convertString << duracion;//add the value of Number to the characters in the stream

	sufijo += convertString.str();

	//Componemos la nota:

	nota = " " + prefijo + nota + sufijo;

	return nota;
}

string MidizatorWAV::transformAcorde(Acorde* a, pair<int,int> duracionBase)
{
	return "a";
}

string MidizatorWAV::printInstrumento(Instrumento i)
{
	std::ostringstream out;
	out << "%%MIDI";

	if (i < 128)
	{
		out << " program " << i;
	}
	else if (i == 128)
	{
		out << " channel 10";
	}

	return out.str();
}