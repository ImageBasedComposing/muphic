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

string ComposerDemo::compose(string picPath, string usrConfPath)
{
	/**
		Parte de ABC
	**/

	string abcFile= "";
	//Añadimos id X: 1 por defecto
	abcFile += "X:1\n";
	//Titulo
	abcFile += "T:"+picPath+"\n";
	//Tonalidad Do Mayor por defecto (C)
	abcFile += "M:C\n";


	/**
		Parte de XML
	**/
	//Abrimos el archivo xml
	TiXmlDocument doc((picPath+".xml").c_str());
	doc.LoadFile();

	//Siempre tiene que haber un declaración al principio (cabecera) <?xml version="1.0" ... ?>
	TiXmlDeclaration* declDoc = (TiXmlDeclaration*)doc.FirstChild();
	//Nos posicionamos en shapes:
	TiXmlNode* shapesNode = doc.NextSibling();

	//Nos recorremos las figuras:
	TiXmlElement* figura;
	TiXmlElement* color;
	TiXmlElement* listaVertices;
	for( figura = shapesNode->FirstChildElement(); figura; figura = shapesNode->NextSiblingElement() )
	{
		
	}

	return abcFile;
}


