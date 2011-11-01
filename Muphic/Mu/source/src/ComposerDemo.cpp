#include "ComposerDemo.h"


ComposerDemo::ComposerDemo()
{
}

ComposerDemo::~ComposerDemo()
{
}

string ComposerDemo::compose()
{

	return "";
}

int ComposerDemo::distCualit(Vertex* v1, Vertex* v2)
{
	return 0;
}

string ComposerDemo::compose(string picPath, string usrConfPath)
{
	/**
		Parte de ABC
	**/

	string abcFile= "";
	//A�adimos id X: 1 por defecto
	abcFile += "X:1\n";
	//Titulo
	abcFile += "T:"+picPath+"\n";
	//Tonalidad Do Mayor por defecto (C)
	abcFile += "K:C\n";
	//M�trica comp�s 4/4 � C por defecto (4/4) no confundir con K!
	abcFile += "M:4/4\n";
	//Longitud base de las notas por defecto corchea (1/8)
	abcFile += "L:1/8\n";


	/**
		Parte de XML
	**/

	//Abrimos el archivo xml
	TiXmlDocument doc((picPath+".xml").c_str());
	doc.LoadFile();

	//Siempre tiene que haber un declaraci�n al principio (cabecera) <?xml version="1.0" ... ?>
	TiXmlDeclaration* declDoc = (TiXmlDeclaration*)doc.FirstChild();
	//Nos posicionamos en shapes:
	TiXmlNode* shapesNode = doc.FirstChild("shapes");

	//Nos recorremos las figuras:
	TiXmlNode* figura;

	//Por defecto vamos ha hacer 3 voces: Dos de Melodia y una de ritmo.
	string voice1, voice2, voice3;
	string color;
	
	TiXmlElement* vertex;
	int numVerticesTotal = 0;
	figura = shapesNode->FirstChild("figure");
	for( figura = shapesNode->FirstChild("figure"); figura; figura = figura->NextSibling("figure") )
	{
		Vertex** listaVertices;
		Vertex** listaAux;
		//Handle sirve para poder recorrer una estructura xml sin preocuparnos de la excepci�n null.
		TiXmlHandle handle(figura);
		
		//Vamos a ver el color;
		color = handle.FirstChildElement("color").FirstChildElement("name").ToElement()->GetText();

		//Vamos a jugar con los vertices
		vertex = handle.FirstChildElement("vertexList").FirstChildElement("vertex").ToElement();
		Vertex* vertice;
		int numVertices = atoi(handle.FirstChildElement("vertexList").ToElement()->Attribute("num"));
		listaVertices = new Vertex*[numVertices];
		numVerticesTotal = numVertices;
		for( int i = 0; i < numVertices; i++)
		{
			vertice = new Vertex();
			vertice->x = atoi(vertex->FirstChildElement("position")->FirstChildElement("x")->GetText());
			vertice->y = atoi(vertex->FirstChildElement("position")->FirstChildElement("y")->GetText());
			vertice->color = color;
			listaVertices[i] = vertice;
		}
		//Si hay canvas
		if(handle.FirstChildElement("canvas").ToElement())
		{
			color = handle.FirstChild("canvas").FirstChild("figure").FirstChild("color").FirstChild("name").ToElement()->GetText();
			numVertices = atoi(handle.FirstChild("canvas").FirstChild("figure").FirstChild("vertexList").ToElement()->Attribute("num"));
			vertex = handle.FirstChild("canvas").FirstChild("figure").FirstChild("vertexList").FirstChild("vertex").ToElement();

			listaAux = listaVertices;
			listaVertices = new Vertex*[numVerticesTotal+numVertices];
			for( int i = 0; i < numVerticesTotal; i++)
			{
				listaVertices[i] = listaAux[i];
			}
			delete listaAux;
			

			for( int i = 0; i < numVertices; i++)
			{
				vertice = new Vertex();
				vertice->x = atoi(vertex->FirstChildElement("position")->FirstChildElement("x")->GetText());
				vertice->y = atoi(vertex->FirstChildElement("position")->FirstChildElement("y")->GetText());
				vertice->color = color;
				listaVertices[i+numVerticesTotal] = vertice;
			}

			numVerticesTotal += numVertices;
		}

		/**
			Parte de ABC
		**/

		//8 corcheas disponible
		int totalCompasPend = 8;
		for(int i = 0; i < numVerticesTotal; i++)
		{
			color = listaVertices[i]->color;
			while (totalCompasPend > 0){
				if(rand()%2 && totalCompasPend > 1)
				{
					if(strcmp(color.c_str(),"Amarillo")==0)
					{
						voice1 += "d2";
					}
					else if(strcmp(color.c_str(),"Gris")==0)
					{
						voice1 += "_B2";
					}
					else if(strcmp(color.c_str(),"Rojo")==0)
					{
						voice1 += "c2";
					}
					else if(strcmp(color.c_str(),"Verde")==0)
					{
						voice1 += "A2";
					}
					else
						voice1 += "d2";

					totalCompasPend -= 2;
				}
				else
				{
					if(strcmp(color.c_str(),"Amarillo")==0)
					{
						voice1 += "d";
					}
					else if(strcmp(color.c_str(),"Gris")==0)
					{
						voice1 += "_B";
					}
					else if(strcmp(color.c_str(),"Rojo")==0)
					{
						voice1 += "c";
					}
					else if(strcmp(color.c_str(),"Verde")==0)
					{
						voice1 += "A";
					}
					else
						voice1 += "d";

					totalCompasPend -= 1;
				}
			} //se ha hecho un compas completo

			voice1 += "|";
			totalCompasPend = 8;
		}//por cada v�rtice un comp�s
					
		for(int i = 0; i < numVerticesTotal; i++)
		{
			delete listaVertices[i];
		}
		delete listaVertices;
	}

	voice1 += "|"; //la doble barra del final

	

	/**
		Parte de ABC -> Fichero
	**/

	abcFile += "V:1\n";
	abcFile += voice1;

	FILE * fabc;

	string pathABC = picPath +".abc";

	fabc = fopen(pathABC.c_str(),"w");

	fprintf(fabc,"%s",abcFile.c_str());

	fclose(fabc);

	return pathABC;
}

