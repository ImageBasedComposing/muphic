#include "Compositors/ComposerFigRitmo2.h"
#include "math_functions.h"


bool ComposerFigRitmo2::compRythmFig(FigureMusic* f, Segmento* seg, int dur, int maxDur)
{
	int t = f->sizeVertices();
	pair<int,int> center;
	center.first = 0;
	center.second = 0;
	int duracionTotal = 0;
	int duracion;

	//Simbolos* ss = seg->getSimbolos();
	Simbolos* simbtmp = new Simbolos();

	//Primero rellenamos todo con la maxDur (que por defecto es redonda)
	while (duracionTotal < dur)
	{
		if((dur - duracionTotal) < maxDur)
		{
			simbtmp->pushBack(new Nota(dur - duracionTotal, getDrumTone()));
			duracionTotal += dur - duracionTotal;
		}
		else
		{
			simbtmp->pushBack(new Nota(maxDur, getDrumTone()));
			duracionTotal += maxDur;
		}
		
	}

	//Ahora según van desviandose del círculo equivalente-en-area vamos
	// cambiando la duracion de las notas.

	//Hallar el radio y el centro del circulo equivalente-en-area:
	double radio = radiusOfArea(f->getArea());
	center = f->getBarycenter();

	//Calculamos la longitud/desviación de cada vértice
	int numVertices = f->sizeVertices();
	double distTotal = 0, distMin = 9000000, distMax = 0;
	int posMin;
	vector< double > distWithNext;  //Distancias con el siguiente vertice.
	for(int i = 0; i < numVertices; i++)
	{
		distWithNext.push_back( abs(dist2DPoints(center, f->getVerticeAt(i)->getPair()) - radio) );
		//Vemos distancia medio vertice, mayor vertice y menor vertice.
		if(distMin > distWithNext.back())
		{
			posMin = i;
			distMin = distWithNext.back();
		}
		distMax = max(distMax, distWithNext.back());
		distTotal += distWithNext.back();
	}
	
	int numNotas = simbtmp->size() - 1;

	//Si tenemos demasiados vértices, destruimos los menos significativos
	while( (numNotas*2) < distWithNext.size() )
	{
		distWithNext.erase(distWithNext.begin() + posMin);
		//Hallamos nuevo mínimo
		distMin = distWithNext.at(0);
		posMin = 0;
		for(int i = 1; i < distWithNext.size(); i++)
			if(distMin > distWithNext.at(i))
			{
				posMin = i;
				distMin = distWithNext.at(i);
			}

	}

	double dist1, dist2;
	//Diferentes rangos
	double range0 = ((distMax - distMin)/10) + distMin;
	double range1 = ((distMax - distMin)/2) + distMin;
	//double radio2 = radio*0.6;
	Nota* s;
	int notasAdded = 0, j = 0;
	//Vamos descomponiendo el ritmo que teníamos.
	for(int i = 0; i < numNotas-1; i++)
	{
		dist1 = distWithNext.at(j);
		j++;
		dist2 = distWithNext.at(j);
		j++;

		if( dist1 > range1 )
			if ( dist2 > range1 )
			{ //dum(L), chuss, chuss
				s = (Nota*)simbtmp->getAt(i+notasAdded);
				s->setDuracion(s->getDuracion()/2);
				//suenan platillos
				simbtmp->insert(i+notasAdded+1, new Nota(s->getDuracion()/2,getCymbalTone()));	
				notasAdded++;
				simbtmp->insert(i+notasAdded+1, new Nota(s->getDuracion()/2,getCymbalTone()));
				notasAdded++;
			}
			else if( dist2 > range0 )
			{ //dum, dum, chuss(L)
				s = (Nota*)simbtmp->getAt(i+notasAdded);
				s->setDuracion(s->getDuracion()/4);
				simbtmp->insert(i+notasAdded+1, new Nota(s->getDuracion(),getDrumTone()));	
				notasAdded++;
				simbtmp->insert(i+notasAdded+1, new Nota(s->getDuracion()*2,getCymbalTone()));
				notasAdded++;
			}
			else
			{ //dum(L), z, chuss
				s = (Nota*)simbtmp->getAt(i+notasAdded);
				s->setDuracion(s->getDuracion()/2);
				simbtmp->insert(i+notasAdded+1, new Nota(s->getDuracion()/2,SILENCIO));	
				notasAdded++;
				simbtmp->insert(i+notasAdded+1, new Nota(s->getDuracion()/2,getCymbalTone()));
				notasAdded++;
			}
		else if( dist1 > range0 )
			if ( dist2 > range1 )
			{ //dum(L), dum, chuss
				s = (Nota*)simbtmp->getAt(i+notasAdded);
				s->setDuracion(s->getDuracion()/2);
				//suenan platillos
				simbtmp->insert(i+notasAdded+1, new Nota(s->getDuracion()/2,getDrumTone()));	
				notasAdded++;
				simbtmp->insert(i+notasAdded+1, new Nota(s->getDuracion()/2,getCymbalTone()));
				notasAdded++;
			}
			else if( dist2 > range0 )
			{ //dum, dum, dum(L)
				s = (Nota*)simbtmp->getAt(i+notasAdded);
				s->setDuracion(s->getDuracion()/4);
				simbtmp->insert(i+notasAdded+1, new Nota(s->getDuracion(),getDrumTone()));	
				notasAdded++;
				simbtmp->insert(i+notasAdded+1, new Nota(s->getDuracion()*2,getDrumTone()));
				notasAdded++;
			}
			else
			{ //dum(L), z, dum
				s = (Nota*)simbtmp->getAt(i+notasAdded);
				s->setDuracion(s->getDuracion()/2);
				simbtmp->insert(i+notasAdded+1, new Nota(s->getDuracion()/2,SILENCIO));	
				notasAdded++;
				simbtmp->insert(i+notasAdded+1, new Nota(s->getDuracion()/2,getDrumTone()));
				notasAdded++;
			}
		else 
			if ( dist2 > range1 )
			{ //dum(L), chuss, z
				s = (Nota*)simbtmp->getAt(i+notasAdded);
				s->setDuracion(s->getDuracion()/2);
				//suenan platillos
				simbtmp->insert(i+notasAdded+1, new Nota(s->getDuracion()/2,getCymbalTone()));
				notasAdded++;
				simbtmp->insert(i+notasAdded+1, new Nota(s->getDuracion()/2,SILENCIO));	
				notasAdded++;
			}
			else if( dist2 > range0 )
			{ //dum, dum, z(L)
				s = (Nota*)simbtmp->getAt(i+notasAdded);
				s->setDuracion(s->getDuracion()/4);
				simbtmp->insert(i+notasAdded+1, new Nota(s->getDuracion(),getDrumTone()));	
				notasAdded++;
				simbtmp->insert(i+notasAdded+1, new Nota(s->getDuracion()*2,SILENCIO));
				notasAdded++;
			}
			else
			{ //dum(L), z, z
				s = (Nota*)simbtmp->getAt(i+notasAdded);
				s->setDuracion(s->getDuracion()/2);
				simbtmp->insert(i+notasAdded+1, new Nota(s->getDuracion()/2,SILENCIO));	
				notasAdded++;
				simbtmp->insert(i+notasAdded+1, new Nota(s->getDuracion()/2,SILENCIO));
				notasAdded++;
			}


	}
	
	seg->setSimbolos(simbtmp);

	return true;
}

int ComposerFigRitmo2::getCymbalTone()
{
	return LA_C+ESCALA+ESCALA; // por ejemplo
}

int ComposerFigRitmo2::getDrumTone()
{
	return LA_C; // por ejemplo
}
