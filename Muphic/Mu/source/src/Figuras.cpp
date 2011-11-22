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
	TiXmlNode* figuraNode = shapesNode->FirstChild("figure");

	// Cargamos las figuras
	cargarRec(figuraNode,NULL);
}

void Figuras::cargarRec(TiXmlNode* f, Figura* id)
{
	if(f != NULL)
	{
		// Creamos la nueva figura
		Figura* figura = new Figura();
	
		// Manipulamos el nodo xml
		TiXmlHandle handle(f);
	
		// Conseguimos los atributos de la figura
		figura->setId(atoi(handle.FirstChildElement("id").ToElement()->GetText()));
		figura->setNumVertices(atoi(handle.FirstChildElement("vertexList").ToElement()->Attribute("num")));
		figura->setParent(id);
		figura->setColor(handle.FirstChildElement("color").FirstChildElement("name").ToElement()->GetText());

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

////Prueba descomentar
//int main( int argc, const char* argv[] )
//{
//	Figuras* f = new Figuras();
//	f->cargar("test2");
//}