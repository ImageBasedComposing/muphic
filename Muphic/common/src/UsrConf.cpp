#include "UsrConf.h"

UsrConf::UsrConf()
{
    //ctor
    phicActive = true;
    phicDebug = false;

    phicFilterSelec = 2;        //Filtro Canny
    phicThresholdSelec = 50;    //Mismo valor que en Phic

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

    if(phicActive)
    {
        phicFilterSelec = atoi(phicNode->FirstChild("filter")->ToElement()->GetText());
        phicThresholdSelec = atoi(phicNode->FirstChild("threshold")->ToElement()->GetText());
        phicNoiseSelec = atoi(phicNode->FirstChild("noise")->ToElement()->GetText());
        phicPolygonSimp = atoi(phicNode->FirstChild("polSimp")->ToElement()->GetText());
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
    phicFilterSelec = atoi(phicNode->FirstChild("filter")->ToElement()->GetText());
    phicThresholdSelec = atoi(phicNode->FirstChild("threshold")->ToElement()->GetText());
    phicNoiseSelec = atoi(phicNode->FirstChild("noise")->ToElement()->GetText());
    phicPolygonSimp = atoi(phicNode->FirstChild("polSimp")->ToElement()->GetText());


	// Debug
	TiXmlNode* debugNode = phicNode->FirstChild("debug");

	if (debugNode != NULL)
		phicDebug = true;
}

void UsrConf::readMu(std::string path) 
{
    // Abrimos el archivo XML
    TiXmlDocument doc(path.c_str());
    doc.LoadFile();

    // Leemos la cabecera
    TiXmlDeclaration* header = (TiXmlDeclaration*) doc.FirstChild();

    // Leemos los nodos
    TiXmlNode* muphicNode = doc.FirstChild("muphic_conf");
    TiXmlNode* muNode = muphicNode->FirstChild("mu_conf");


    // Debug
    TiXmlNode* debugNode = muNode->FirstChild("debug");

    if (debugNode != NULL)
        muDebug = true;
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
    }
	else
	{
        if (phicDebug)
        {
            TiXmlElement * debugNode = new TiXmlElement( "debug" );
            phicNode->LinkEndChild(debugNode);
        }

        // We add the node for filter selection
        TiXmlElement * phicFilterNode = new TiXmlElement( "filter" );
        char a[10];
        phicFilterNode->LinkEndChild(new TiXmlText(our_itoa(phicFilterSelec,a,10)));
        phicNode->LinkEndChild(phicFilterNode);

        //Node for Threshold setting
        TiXmlElement * phicThresholdNode = new TiXmlElement( "threshold" );
        phicThresholdNode->LinkEndChild(new TiXmlText(our_itoa(phicThresholdSelec,a,10)));
        phicNode->LinkEndChild(phicThresholdNode);

        //Node for ignored area setting
        TiXmlElement * phicNoiseNode = new TiXmlElement( "noise" );
        phicNoiseNode->LinkEndChild(new TiXmlText(our_itoa(phicNoiseSelec,a,10)));
        phicNode->LinkEndChild(phicNoiseNode);

        //Node for polygon simplification setting
        TiXmlElement * phicPolSimpNode = new TiXmlElement( "polSimp" );
        phicPolSimpNode->LinkEndChild(new TiXmlText(our_itoa(phicPolygonSimp,a,10)));
        phicNode->LinkEndChild(phicPolSimpNode);
	}

    TiXmlElement * muNode = new TiXmlElement( "mu_conf" );
    if (!muActive)
    {
        muNode->SetAttribute("none", "true");
    }
    else
    {
        if (muDebug)
        {
            TiXmlElement * debugNode = new TiXmlElement( "debug" );
            muNode->LinkEndChild(debugNode);
        }
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

int UsrConf::getPhicFilterSelect()
{
    return phicFilterSelec;
}

int UsrConf::getPhicThresholdSelec()
{
    return phicThresholdSelec;
}

int UsrConf::getPhicNoiseSelec()
{
    return phicNoiseSelec;
}

int UsrConf::getPhicPolygonSimp()
{
    return phicPolygonSimp;
}

bool UsrConf::getMuActive() 
{
	return muActive;
}

bool UsrConf::getMuDebug()
{
    return muDebug;
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

void UsrConf::setPhicFilterSelect(int fn)
{
    phicFilterSelec = fn;
}

void UsrConf::setPhicThresholdSelec(int t)
{
    phicThresholdSelec = t;
}

void UsrConf::setPhicPolygonSimp(int i)
{
    phicPolygonSimp = i;
}

void UsrConf::setPhicNoiseSelec(int n)
{
    phicNoiseSelec = n;
}

void UsrConf::setMuActive(bool b)
{
        muActive = b;
}

void UsrConf::setMuDebug(bool b)
{
        muDebug = b;
}


