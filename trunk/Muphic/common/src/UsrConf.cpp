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
        phicColorLevels = atoi(phicNode->FirstChild("colLvl")->ToElement()->GetText());
        phicThresholdH = atoi(phicNode->FirstChild("thresholdH")->ToElement()->GetText());
        phicThresholdS = atoi(phicNode->FirstChild("thresholdS")->ToElement()->GetText());
        phicThresholdV = atoi(phicNode->FirstChild("thresholdV")->ToElement()->GetText());
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
    phicColorLevels = atoi(phicNode->FirstChild("colLvl")->ToElement()->GetText());
    phicThresholdH = atoi(phicNode->FirstChild("thresholdH")->ToElement()->GetText());
    phicThresholdS = atoi(phicNode->FirstChild("thresholdS")->ToElement()->GetText());
    phicThresholdV = atoi(phicNode->FirstChild("thresholdV")->ToElement()->GetText());


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

        //Node for color levels setting
        TiXmlElement * phicColLvlNode = new TiXmlElement( "colLvl" );
        phicColLvlNode->LinkEndChild(new TiXmlText(our_itoa(phicColorLevels,a,10)));
        phicNode->LinkEndChild(phicColLvlNode);

        //Node for Threshold H setting
        TiXmlElement * phicThresholdHNode = new TiXmlElement( "thresholdH" );
        phicThresholdHNode->LinkEndChild(new TiXmlText(our_itoa(phicThresholdH,a,10)));
        phicNode->LinkEndChild(phicThresholdHNode);

        //Node for Threshold S setting
        TiXmlElement * phicThresholdSNode = new TiXmlElement( "thresholdS" );
        phicThresholdSNode->LinkEndChild(new TiXmlText(our_itoa(phicThresholdS,a,10)));
        phicNode->LinkEndChild(phicThresholdSNode);

        //Node for Threshold V setting
        TiXmlElement * phicThresholdVNode = new TiXmlElement( "thresholdV" );
        phicThresholdVNode->LinkEndChild(new TiXmlText(our_itoa(phicThresholdV,a,10)));
        phicNode->LinkEndChild(phicThresholdVNode);
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

int UsrConf::getPhicColorLevels()
{
    return phicColorLevels;
}

int UsrConf::getPhicThresholdH()
{
    return phicThresholdH;
}

int UsrConf::getPhicThresholdS()
{
    return phicThresholdS;
}

int UsrConf::getPhicThresholdV()
{
    return phicThresholdV;
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

void UsrConf::setPhicColorLevels(int c)
{
    phicColorLevels = c;
}

void UsrConf::setPhicThresholdH(int t)
{
    phicThresholdH = t;
}

void UsrConf::setPhicThresholdS(int t)
{
    phicThresholdS = t;
}

void UsrConf::setPhicThresholdV(int t)
{
    phicThresholdV = t;
}

void UsrConf::setMuActive(bool b)
{
        muActive = b;
}

void UsrConf::setMuDebug(bool b)
{
        muDebug = b;
}

