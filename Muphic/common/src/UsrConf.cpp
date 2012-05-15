#include "UsrConf.h"

UsrConf::UsrConf()
{
    //ctor
    phicActive = true;
    phicDebug = false;

    phicFilterSelec = 2;        //Filtro Canny
    phicThresholdSelec = 50;    //Mismo valor que en Phic
	phicAnalysisDetail = 50;

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
		phicAnalysisDetail = atoi(phicNode->FirstChild("anlDet")->ToElement()->GetText());
        phicColorLevels = atoi(phicNode->FirstChild("colLvl")->ToElement()->GetText());
        phicThresholdH = atoi(phicNode->FirstChild("thresholdH")->ToElement()->GetText());
        phicThresholdS = atoi(phicNode->FirstChild("thresholdS")->ToElement()->GetText());
        phicThresholdV = atoi(phicNode->FirstChild("thresholdV")->ToElement()->GetText());

        // Debug
        TiXmlNode* debugNode = phicNode->FirstChild("debug");

        if (debugNode != NULL)
            phicDebug = true;
    }

	muNode->ToElement();

	if(muNode->ToElement()->Attribute("none") != 0)
	{
		std::string none = muNode->ToElement()->Attribute("none");
		if(strcmp(none.c_str(),"true") == 0)
			muActive = false;
	}

    if(muActive)
    {
        // Leemos los nodos
        muCompMix = atoi(muNode->FirstChild("compositorMix")->ToElement()->GetText());
        muCompVoice1 = atoi(muNode->FirstChild("compositor_voice1")->ToElement()->GetText());
        muCompVoice2 = atoi(muNode->FirstChild("compositor_voice2")->ToElement()->GetText());
        muCompVoice3 = atoi(muNode->FirstChild("compositor_voice3")->ToElement()->GetText());
        muCompVoice4 = atoi(muNode->FirstChild("compositor_voice4")->ToElement()->GetText());

        muInstrVoice1 = atoi(muNode->FirstChild("instrument_voice1")->ToElement()->GetText());
        muInstrVoice2 = atoi(muNode->FirstChild("instrument_voice2")->ToElement()->GetText());
        muInstrVoice3 = atoi(muNode->FirstChild("instrument_voice3")->ToElement()->GetText());
        muInstrVoice4 = atoi(muNode->FirstChild("instrument_voice4")->ToElement()->GetText());

        muReconColors = atoi(muNode->FirstChild("color-system")->ToElement()->GetText());
        muTempo = atoi(muNode->FirstChild("tempo")->ToElement()->GetText());
        muOutputFile = muNode->FirstChild("muOutputFile")->ToElement()->GetText();


        // Debug
        TiXmlNode* debugNode = muNode->FirstChild("debug");

        if (debugNode != NULL)
            muDebug = true;
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
	phicAnalysisDetail = atoi(phicNode->FirstChild("anlDet")->ToElement()->GetText());
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
	muCompMix = atoi(muNode->FirstChild("compositorMix")->ToElement()->GetText());
	muCompVoice1 = atoi(muNode->FirstChild("compositor_voice1")->ToElement()->GetText());
	muCompVoice2 = atoi(muNode->FirstChild("compositor_voice2")->ToElement()->GetText());
	muCompVoice3 = atoi(muNode->FirstChild("compositor_voice3")->ToElement()->GetText());
	muCompVoice4 = atoi(muNode->FirstChild("compositor_voice4")->ToElement()->GetText());

	muInstrVoice1 = atoi(muNode->FirstChild("instrument_voice1")->ToElement()->GetText());
	muInstrVoice2 = atoi(muNode->FirstChild("instrument_voice2")->ToElement()->GetText());
	muInstrVoice3 = atoi(muNode->FirstChild("instrument_voice3")->ToElement()->GetText());
	muInstrVoice4 = atoi(muNode->FirstChild("instrument_voice4")->ToElement()->GetText());

	muReconColors = atoi(muNode->FirstChild("color-system")->ToElement()->GetText());
	muTempo = atoi(muNode->FirstChild("tempo")->ToElement()->GetText());
    muOutputFile = muNode->FirstChild("muOutputFile")->ToElement()->GetText();


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

        TiXmlElement * phicAnlDetNode = new TiXmlElement( "anlDet" );
        phicAnlDetNode->LinkEndChild(new TiXmlText(our_itoa(phicAnalysisDetail,a,10)));
        phicNode->LinkEndChild(phicAnlDetNode);

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

		//Node for ComposerMix
		TiXmlElement* muCompMixNode = new TiXmlElement("compositorMix");
		char a[10];
		muCompMixNode->LinkEndChild(new TiXmlText(our_itoa(muCompMix,a,10)));
		muNode->LinkEndChild(muCompMixNode);

		//Node for ComposerVoice1
		TiXmlElement* muCompVoice1Node = new TiXmlElement("compositor_voice1");
		muCompVoice1Node->LinkEndChild(new TiXmlText(our_itoa(muCompVoice1,a,10)));
		muNode->LinkEndChild(muCompVoice1Node);

		//Node for ComposerVoice2
		TiXmlElement* muCompVoice2Node = new TiXmlElement("compositor_voice2");
		muCompVoice2Node->LinkEndChild(new TiXmlText(our_itoa(muCompVoice2,a,10)));
		muNode->LinkEndChild(muCompVoice2Node);

		//Node for ComposerVoice3
		TiXmlElement* muCompVoice3Node = new TiXmlElement("compositor_voice3");
		muCompVoice3Node->LinkEndChild(new TiXmlText(our_itoa(muCompVoice3,a,10)));
		muNode->LinkEndChild(muCompVoice3Node);

		//Node for ComposerVoice4
		TiXmlElement* muCompVoice4Node = new TiXmlElement("compositor_voice4");
		muCompVoice4Node->LinkEndChild(new TiXmlText(our_itoa(muCompVoice4,a,10)));
		muNode->LinkEndChild(muCompVoice4Node);

		//Node for InstrumentVoice1
		TiXmlElement* muInstrVoice1Node = new TiXmlElement("instrument_voice1");
		muInstrVoice1Node->LinkEndChild(new TiXmlText(our_itoa(muInstrVoice1,a,10)));
		muNode->LinkEndChild(muInstrVoice1Node);

		//Node for InstrumentVoice2
		TiXmlElement* muInstrVoice2Node = new TiXmlElement("instrument_voice2");
		muInstrVoice2Node->LinkEndChild(new TiXmlText(our_itoa(muInstrVoice2,a,10)));
		muNode->LinkEndChild(muInstrVoice2Node);

		//Node for InstrumentVoice3
		TiXmlElement* muInstrVoice3Node = new TiXmlElement("instrument_voice3");
		muInstrVoice3Node->LinkEndChild(new TiXmlText(our_itoa(muInstrVoice3,a,10)));
		muNode->LinkEndChild(muInstrVoice3Node);

		//Node for InstrumentVoice4
		TiXmlElement* muInstrVoice4Node = new TiXmlElement("instrument_voice4");
		muInstrVoice4Node->LinkEndChild(new TiXmlText(our_itoa(muInstrVoice4,a,10)));
		muNode->LinkEndChild(muInstrVoice4Node);

		//Node for ReconColors
		TiXmlElement* muReconColorsNode = new TiXmlElement("color-system");
		muReconColorsNode->LinkEndChild(new TiXmlText(our_itoa(muReconColors,a,10)));
		muNode->LinkEndChild(muReconColorsNode);

		//Node for Tempo
		TiXmlElement* muTempoNode = new TiXmlElement("tempo");
		muTempoNode->LinkEndChild(new TiXmlText(our_itoa(muTempo,a,10)));
		muNode->LinkEndChild(muTempoNode);

        //Node for MuOutputFile
        TiXmlElement* muOutputFileNode = new TiXmlElement("muOutputFile");
        muOutputFileNode->LinkEndChild(new TiXmlText(muOutputFile.c_str()));
        muNode->LinkEndChild(muOutputFileNode);
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

int UsrConf::getPhicAnalysisDetail()
{
	return phicAnalysisDetail;
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

int UsrConf::getMuCompMix()
{
	return muCompMix;
}

int UsrConf::getMuCompVoice1()
{
	return muCompVoice1;
}

int UsrConf::getMuCompVoice2()
{
	return muCompVoice2;
}

int UsrConf::getMuCompVoice3()
{
	return muCompVoice3;
}

int UsrConf::getMuCompVoice4()
{
	return muCompVoice4;
}

int UsrConf::getMuInstrVoice1()
{
	return muInstrVoice1;
}

int UsrConf::getMuInstrVoice2()
{
	return muInstrVoice2;
}

int UsrConf::getMuInstrVoice3()
{
	return muInstrVoice3;
}

int UsrConf::getMuInstrVoice4()
{
	return muInstrVoice4;
}

int UsrConf::getMuReconColors()
{
	return muReconColors;
}

int UsrConf::getMuTempo()
{
	return muTempo;
}

std::string UsrConf::getMuOutputFile()
{
    return muOutputFile;
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

void UsrConf::setPhicAnalysisDetail(int i)
{
	phicAnalysisDetail = i;
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

void UsrConf::setMuCompMix(int c)
{
	muCompMix = c;
}

void UsrConf::setMuCompVoice1(int c)
{
	muCompVoice1 = c;
}

void UsrConf::setMuCompVoice2(int c)
{
	muCompVoice2 = c;
}

void UsrConf::setMuCompVoice3(int c)
{
	muCompVoice3 = c;
}

void UsrConf::setMuCompVoice4(int c)
{
	muCompVoice4 = c;
}

void UsrConf::setMuInstrVoice1(int i)
{
	muInstrVoice1 = i;
}

void UsrConf::setMuInstrVoice2(int i)
{
	muInstrVoice2 = i;
}

void UsrConf::setMuInstrVoice3(int i)
{
	muInstrVoice3 = i;
}

void UsrConf::setMuInstrVoice4(int i)
{
	muInstrVoice4 = i;
}

void UsrConf::setMuReconColors(int cs)
{
	muReconColors = cs;
}

void UsrConf::setMuTempo(int t)
{
	muTempo = t;
}

void UsrConf::setMuOutputFile(std::string o)
{
    muOutputFile = o;
}
