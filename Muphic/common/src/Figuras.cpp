#include "Figuras.h"

Figuras::Figuras()
{
    figuras.clear();
}

Figuras::~Figuras()
{
    std::list<Figura*>::iterator it = figuras.begin();
    while (it != figuras.end())
    {
        delete (*it);
        it++;
    }
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

	//Cargamos el ancho y el alto de la página
	sheetWidth = atoi(shapesNode->FirstChild("width")->ToElement()->GetText());
	sheetHeight = atoi(shapesNode->FirstChild("height")->ToElement()->GetText());
	
	//Vamos a la primera figura
	TiXmlNode* figuraNode = shapesNode->FirstChild("figure");

	// Cargamos las figuras
	cargarRec(figuraNode,NULL);
}

void Figuras::guardar(string rutaXML)
{
	
	TiXmlDocument doc;

	// Header
	TiXmlDeclaration * headerNode = new TiXmlDeclaration( "1.0", "", "yes" );
	doc.LinkEndChild( headerNode );
	
	// First shapes node
	TiXmlElement * shapesNode = new TiXmlElement( "shapes" );
	doc.LinkEndChild( shapesNode );

	// Image size
	TiXmlElement * widthNode = new TiXmlElement( "width" );
	TiXmlElement * heightNode = new TiXmlElement( "height" );
	char size[10];
	itoa(this->sheetWidth, size, 10);
	widthNode->LinkEndChild( new TiXmlText(size)  );
	itoa(this->sheetHeight, size, 10);
	heightNode->LinkEndChild( new TiXmlText(size) );

	shapesNode->LinkEndChild( widthNode );
	shapesNode->LinkEndChild( heightNode );
	

	// Iterate father figures and add them to the xml doc
	TiXmlElement* figureNode;
	for (list<Figura*>::iterator it = figPadres.begin(); it != figPadres.end(); it++)
	{
		figureNode = new TiXmlElement("figure");
		guardarRec(figureNode, (*it));
		shapesNode->LinkEndChild( figureNode );
	}

	doc.SaveFile( "rutaXML" );
}


void Figuras::guardarRec(TiXmlElement* f, Figura* id)
{

	// write id
	TiXmlElement * idNode = new TiXmlElement( "id" );
	char intstr[10];
	itoa(id->id, intstr, 10);
	idNode->LinkEndChild( new TiXmlText(intstr)  );
	f->LinkEndChild( idNode );

	// write color
	TiXmlElement * colorNode = new TiXmlElement( "color" );
		//name
		TiXmlElement * nameNode = new TiXmlElement( "name" );
		nameNode->LinkEndChild( new TiXmlText("Dovahkiin") );
		//rgb
		TiXmlElement * rgbNode = new TiXmlElement( "RGB" );
			// r
			TiXmlElement * rNode = new TiXmlElement( "R" );
			itoa(id->getRGB().r, intstr, 10);
			rNode->LinkEndChild( new TiXmlText(intstr) );
			//g
			TiXmlElement * gNode = new TiXmlElement( "G" );
			itoa(id->getRGB().g, intstr, 10);
			gNode->LinkEndChild( new TiXmlText(intstr) );
			// b
			TiXmlElement * bNode = new TiXmlElement( "B" );
			itoa(id->getRGB().b, intstr, 10);
			bNode->LinkEndChild( new TiXmlText(intstr) );
		rgbNode->LinkEndChild( rNode );
		rgbNode->LinkEndChild( gNode );
		rgbNode->LinkEndChild( bNode );
		// gradient
		TiXmlElement * gradientNode = new TiXmlElement( "gradient" );
		gradientNode->LinkEndChild( new TiXmlText("0") );
		// add all
		colorNode->LinkEndChild( nameNode );
		colorNode->LinkEndChild( rgbNode );
		colorNode->LinkEndChild( gradientNode);
	f->LinkEndChild( colorNode );


	// write vertex list
	TiXmlElement * vertexListNode = new TiXmlElement( "vertexList" );
		// size attribute
		itoa(id->listaVertices.size(), intstr, 10);
		vertexListNode->SetAttribute("num", intstr);
		// vertex nodes
		TiXmlElement * vertexNode;
		TiXmlElement * positionNode, * xNode, * yNode;
		for (list<Vertice*>::iterator it = id->listaVertices.begin(); it != id->listaVertices.end(); it++)
		{
			vertexNode = new TiXmlElement("vertex");
			//center vertex
			if ((*it)->centro)
			{
				vertexNode->SetAttribute("type", "center");
			}

			// position
			positionNode = new TiXmlElement("position");
				// x position
				xNode = new TiXmlElement("x");
				itoa((*it)->x, intstr, 10);
				xNode->LinkEndChild( new TiXmlText(intstr) );
				// y position
				yNode = new TiXmlElement("y");
				itoa((*it)->y, intstr, 10);
				yNode->LinkEndChild( new TiXmlText(intstr) );
				// add position
				positionNode->LinkEndChild( xNode );
				positionNode->LinkEndChild( yNode );
			// add info to node
			vertexNode->LinkEndChild( positionNode );
			vertexListNode->LinkEndChild( vertexNode );
		}
	f->LinkEndChild( vertexListNode );



	// write area
	TiXmlElement * areaNode = new TiXmlElement( "area" );
	itoa(id->area, intstr, 10);
	areaNode->LinkEndChild( new TiXmlText(intstr)  );
	f->LinkEndChild( areaNode );

	//  write children, if any
	if (id->hijos.size() != 0)
	{
		TiXmlElement * canvasNode = new TiXmlElement( "canvas" );
		TiXmlElement* figureNode;
		for (list<Figura*>::iterator it = id->hijos.begin(); it != id->hijos.end(); it++)
		{
			figureNode = new TiXmlElement("figure");
			guardarRec(figureNode, (*it));
			canvasNode->LinkEndChild( figureNode );
		}
		f->LinkEndChild( canvasNode );
	}
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

		// Conseguimos la lista de vértices de la figura
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
		
		// Tratamos los casos específicos de figura hijo o figura padre
		if(id != NULL)
		{
			id->colocarHijo(figura);
		} // if id != NULL
		else
		{
			colocarPadre(figura);
		}

		// Añadimos la figura a la lista de figuras
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

	
	// suponemos un polígono formado por los baricentros de cada figura, y calculamos su centro teniendo en cuenta la vistosidad
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