#include "UsrConf.h"

UsrConf::UsrConf()
{
    //ctor
    phicActive = true;
    phicDebug = false;

    muActive = true;
}

UsrConf::~UsrConf()
{
    //dtor
}

void UsrConf::read(std::string path) 
{
	readMuphic(path);
	readPhic(path);
	readMu(path);
}

void UsrConf::readMuphic(std::string path) 
{
	phicActive = true;
	muActive = true;

	// Abrimos el archivo XML
	TiXmlDocument doc(path.c_str());
	doc.LoadFile();

	// Leemos la cabecera
	TiXmlDeclaration* header = (TiXmlDeclaration*) doc.FirstChild();

	// Leemos los nodos
	TiXmlNode* muphicNode = doc.FirstChild("muphic_conf");
	TiXmlNode* phicNode = muphicNode->FirstChild("phic_conf");
	TiXmlNode* muNode = muphicNode->FirstChild("mu_conf");

	if(phicNode->ToElement()->Attribute("none") != 0)
	{
		std::string none = phicNode->ToElement()->Attribute("none");
		if(strcmp(none.c_str(),"true") == 0)
			phicActive = false;
	}

	muNode->ToElement();

	if(muNode->ToElement()->Attribute("none") != 0)
	{
		std::string none = muNode->ToElement()->Attribute("none");
		if(strcmp(none.c_str(),"true") == 0)
			muActive = false;
	}
}


void UsrConf::readPhic(std::string path) 
{
	// Abrimos el archivo XML
	TiXmlDocument doc(path.c_str());
	doc.LoadFile();

	// Leemos la cabecera
	TiXmlDeclaration* header = (TiXmlDeclaration*) doc.FirstChild();

	// Leemos los nodos
	TiXmlNode* muphicNode = doc.FirstChild("muphic_conf");
	TiXmlNode* phicNode = muphicNode->FirstChild("phic_conf");


	// Debug
	TiXmlNode* debugNode = phicNode->FirstChild("debug");

	if (debugNode != NULL)
		phicDebug = true;
}

void UsrConf::readMu(std::string path) 
{

}

void UsrConf::write(std::string path)
{
    TiXmlDocument doc;

    // Header
    TiXmlDeclaration * headerNode = new TiXmlDeclaration( "1.0", "", "yes" );
    doc.LinkEndChild( headerNode );

    // First shapes node
    TiXmlElement * muphicNode = new TiXmlElement( "muphic_conf" );
    doc.LinkEndChild( muphicNode );

    // Image size
    TiXmlElement * phicNode = new TiXmlElement( "phic_conf" );
    if (!phicActive)
    {
        phicNode->SetAttribute("none", "true");
        if (phicDebug)
        {
            TiXmlElement * debugNode = new TiXmlElement( "debug" );
            phicNode->LinkEndChild(debugNode);
        }
    }

    TiXmlElement * muNode = new TiXmlElement( "mu_conf" );
    if (!muActive)
    {
        muNode->SetAttribute("none", "true");
    }


    muphicNode->LinkEndChild(phicNode);
    muphicNode->LinkEndChild(muNode);


    doc.SaveFile( path.c_str() );
}

// GETTERS

bool UsrConf::getPhicActive() 
{
	return phicActive;
}

bool UsrConf::getPhicDebug()
{
	return phicDebug;
}

bool UsrConf::getMuActive() 
{
	return muActive;
}

// SETTERS

void UsrConf::setPhicActive(bool b)
{
        phicActive = b;
}

void UsrConf::setPhicDebug(bool b)
{
        phicDebug = b;
}

void UsrConf::setMuActive(bool b)
{
        muActive = b;
}


