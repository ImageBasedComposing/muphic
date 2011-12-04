#pragma once

#ifndef MUSIC_CONST_H
#define MUSIC_CONST_H


// RESPECTO A LA DURACION/LENGTH DE NOTAS:

#define SIXTEENTHNOTE 4  //semicorchea
#define EIGHTHNOTE 8	 //corchea
#define QUARTERNOTE 16   //negra
#define HALFNOTE 32		 //blanca	
#define WHOLE 64		 //redonda


// RESPECTO AL TONO/PITCH

//Tamaño de la escala diatonica 12 semitonos:
#define ESCALA 12

//Escala inicial, sirve para luego añadirle escalas.
#define DO 1
#define DO_S 2 //Do sharp (sostenido)
#define RE_F 2 //Re flat (bemol)
#define RE 3
#define RE_S 4 //RE sharp
#define MI_F 4
#define MI 5
#define FA_F 5
#define MI_S 6
#define FA 6
#define FA_S 7
#define SOL_F 7
#define SOL 8
#define SOL_S 9
#define LA_F 9
#define LA 10
#define LA_S 11
#define SI_F 11
#define SI 12
#define DO_F 12
#define SI_S 13
//Por ejemplo, DO_C = DO + ESCALA * 3 = 37 (hemos subido 3 escalas el do, nos encontramos en el principio de la 4º escala)

#define SILENCIO 0

//Escala central del piano:
#define DO_F_C 36
#define DO_C 37
#define DO_S_C 38
#define RE_F_C 38
#define RE_C 39
#define RE_S_C 40
#define MI_F_C 40
#define MI_C 41
#define FA_F_C 41
#define MI_S_ 42
#define FA_C 42
#define FA_S_C 43
#define SOL_F_C 43
#define SOL_C 44
#define SOL_S_C 45
#define LA_F_C 45
#define LA_C 46
#define LA_S_C 47
#define SI_F_C 47
#define SI_C 48
#define SI_S_C 49

//Intervalos:
#define PER1 0	//PERFECT UNISON (Unisono/misma nota)
#define MIN2 1	//MINOR SECOND (Segunda menor)
#define MAJ2 2	//MAJOR SECOND (Segunda Mayor)
#define MIN3 3	//MINOR THIRD (Tercera menor)
#define MAJ3 4	//MAJOR THIRD (Tercera Mayor)
#define PER4 5	//PERFECT FOURTH (Cuarta justa)
#define AUM4 6  //AUGMENTED FOURTH or DIMINISHED FIFTH (Cuarta aumentada o quinta disminuida)
#define DIM5 6
#define TRIT 6  //Tambien llamada TRITONO
#define PER5 7	//PERFECT FIFTH (Quinta justa)
#define MIN6 8	//MINOR SIXTH (Sexta menor)
#define MAJ6 9	//MAJOR SIXTH (Sexta Mayor)
#define MIN7 10 //MINOR SEVENTH (Septima menor)
#define MAJ7 11	//MAJOR SEVENTH (Septima mayor)
#define PER8 12	//PERFECT OCTAVE (Octava justa)


// RESPECTO A LAS ESCALAS

//Grados y Funciones musicales:
#define TONICA 1;		//TONIC
#define SUPERTONICA 2;	//SUPERTONIC
#define MEDIANTE 3;		//MEDIANT
#define SUBDOMINANTE 4; //SUBDOMINANT
#define DOMINANTE 5;	//DOMINANT
#define SUBMEDIANTE 6;	//SUBMEDIANT
#define SUBTONICA 7;	//SUBTONIC
#define SENSIBLE 7;		//LEADING TONE

#endif