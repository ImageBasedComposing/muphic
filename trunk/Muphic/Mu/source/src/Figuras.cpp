#include "Figuras.h"

Figuras::Figuras()
{
    figuras.clear();
}

Figuras::~Figuras()
{
    figuras.clear();
}

// Funciones
void Figuras::cargar(string rutaXML)
{
	// Abrimos el archivo XML
	TiXmlDocument doc((rutaXML + ".xml").c_str());
	doc.LoadFile();

	// Leemos la cabecera
	TiXmlDeclaration* header = (TiXmlDeclaration*) doc.FirstChild();

	// Vamos a Shapes
	TiXmlNode* shapesNode = doc.FirstChild("shapes"); 

	//Cargamos el ancho y el alto de la p�gina
	sheetWidth = atoi(shapesNode->FirstChild("width")->ToElement()->GetText());
	sheetHeight = atoi(shapesNode->FirstChild("height")->ToElement()->GetText());
	
	//Vamos a la primera figura
	TiXmlNode* figuraNode = shapesNode->FirstChild("figure");

	// Cargamos las figuras
	cargarRec(figuraNode,NULL);
}

void Figuras::cargarRec(TiXmlNode* f, Figura* id)
{
	if(f != NULL)
	{
		// Creamos la nueva figura
		Figura* figura = createFigure();
	
		// Manipulamos el nodo xml
		TiXmlHandle handle(f);
	
		// Conseguimos los atributos de la figura
		figura->setId(atoi(handle.FirstChildElement("id").ToElement()->GetText()));
		figura->setNumVertices(atoi(handle.FirstChildElement("vertexList").ToElement()->Attribute("num")));
		figura->setParent(id);
		figura->setColor(handle.FirstChildElement("color").FirstChildElement("name").ToElement()->GetText());
		figura->setRGB((float)atof(handle.FirstChildElement("color").FirstChildElement("RGB").FirstChildElement("R").ToElement()->GetText()),
						 (float)atof(handle.FirstChildElement("color").FirstChildElement("RGB").FirstChildElement("G").ToElement()->GetText()),
						 (float)atof(handle.FirstChildElement("color").FirstChildElement("RGB").FirstChildElement("B").ToElement()->GetText()));
		// Preparamos el tratamiento de vertices
		Vertice* v;
		TiXmlNode* vertice = f->FirstChildElement("vertexList")->FirstChildElement("vertex");

		// Conseguimos la lista de v�rtices de la figura
		for( int i = 0; i < figura->getNumVertices(); i++)
		{
			v = new Vertice();
			v->x = atoi(vertice->FirstChildElement("position")->FirstChildElement("x")->GetText());
			v->y = atoi(vertice->FirstChildElement("position")->FirstChildElement("y")->GetText());

			// Comprobamos que tenga atributo
			if(vertice->ToElement()->Attribute("type") != 0)
			{
				string l = vertice->ToElement()->Attribute("type");
				if(strcmp(vertice->ToElement()->Attribute("type"),"center") == 0)
					v->centro = true;
			}
			figura->colocarVertice(v);
			vertice = vertice->NextSibling("vertex");
		}

		// Leemos su area
		figura->setArea(atoi(handle.FirstChildElement("area").ToElement()->GetText()));
		
		// Tratamos los casos espec�ficos de figura hijo o figura padre
		if(id != NULL)
		{
			id->colocarHijo(figura);
		} // if id != NULL
		else
		{
			colocarPadre(figura);
		}

		// A�adimos la figura a la lista de figuras
		colocarFig(figura);

		// Si la figura tiene figuras en su interior hacemos la llamada recursiva pertinente
		if(handle.FirstChildElement("canvas").ToElement())
		{
			cargarRec(f->FirstChildElement("canvas")->FirstChildElement("figure"),figura);
		} // if canvas

		// Hacemos la llamada recursiva
		cargarRec(f->NextSibling("figure"),id);
	} // if f != NULL
}

// Envoltorio de list
bool Figuras::emptyFig()
{
	return figuras.empty();
}

bool Figuras::emptyPadre()
{
	return figPadres.empty();
}

int Figuras::sizeFig()
{
	return figuras.size();
}

int Figuras::sizePadre()
{
	return figPadres.size();
}

void Figuras::colocarFig(Figura* s)
{
	figuras.push_back(s);

	figuras.sort(&Figura::compare);
}

void Figuras::colocarPadre(Figura* s)
{
	figPadres.push_back(s);

	figPadres.sort(&Figura::compare);
}

//void Figuras::insertFig(Figura* s, int n)
//{
//	list<Figura*>::iterator it = figuras.begin();
//
//	for(int i = 0; i < n; i++)
//	{
//		it++;
//	}
//
//	figuras.insert(it,s);
//}
//
//void Figuras::insertPadre(Figura* s, int n)
//{
//	list<Figura*>::iterator it = figPadres.begin();
//
//	for(int i = 0; i < n; i++)
//	{
//		it++;
//	}
//
//	figPadres.insert(it,s);
//}

Figura* Figuras::getFigAt(int n)
{
	list<Figura*>::iterator it = figuras.begin();

	for(int i = 0; i < n; i++)
	{
		it++;
	}

	return *it;
}

Figura* Figuras::getPadreAt(int n)
{
	list<Figura*>::iterator it = figPadres.begin();

	for(int i = 0; i < n; i++)
	{
		it++;
	}

	return *it;
}

/*
// recibe una lista de figuras con su vistosidad calculada y calcula su centro
pair<int,int> Figuras::calcularCentro()
{
	// calculamos la vistosidad total para normalizar
	float vistosidadTotal = 0;
	for (list<FigureMusic*>::iterator it = figuras.begin(); it != figuras.end(); it++)
	{
		vistosidadTotal += (*it)->getVistosidad();
	}

	// normalizamos la vistosidad de cada figura
	for (list<FigureMusic*>::iterator it = figuras.begin(); it != figuras.end(); it++)
	{
		(*it)->vistosidad /= vistosidadTotal;
	}

	
	// suponemos un pol�gono formado por los baricentros de cada figura, y calculamos su centro teniendo en cuenta la vistosidad
	pair<int,int> centerFigura;
	pair<int,int> centerTotal;
	centerTotal.first = 0;
	centerTotal.second = 0;
	for (list<FigureMusic*>::iterator it = figuras.begin(); it != figuras.end(); it++)
	{
		centerFigura = (*it)->getBarycenter();
		centerTotal.first += (int)(*it)->vistosidad * centerFigura.first;
		centerTotal.second += (int)(*it)->vistosidad * centerFigura.second;
	}
	
	return centerTotal;
}
*/

/*------Getters------*/
int Figuras::getHeight()
{
	return sheetHeight;
}

int Figuras::getWidth()
{
	return sheetWidth;
}

//list<Figura*>* Figuras::getFiguras()
//{
//	return &figuras;
//}
//
//list<Figura*>* Figuras::getFigPadre()
//{
//	return &figPadres;
//}

Figura* Figuras::createFigure()
{
	Figura* f = new Figura();
	return f;
}

////Prueba descomentar
//int main( int argc, const char* argv[] )
//{
//	Figuras* f = new Figuras();
//	f->cargar("test2");
//}