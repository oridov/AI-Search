#pragma once

#include <string>
#include <map>
//#include <iostream>
//#include <fstream>

#include "pugixml.hpp"
#include "ComponentFactory.h"
#include "CompSystem.h"

//using namespace rapidxml;
using namespace std;
using namespace pugi;

class Parser
{
public:
	Parser(void);
	~Parser(void);
	CompSystem *parseCompSystem(string system_filename);

private:	
	void parseComponents(xml_document &doc, map<string, Component*> &components, map<string, inport*> &inputs, map<string, outport*> &outputs);
	void parseConnections(xml_document &doc, map<string, Component*> &components);
	void extractInportsOutports(Component *c, string name, map<string, inport*> &inputs, map<string, outport*> &outputs);
};
