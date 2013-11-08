#ifndef _FILEREADING_H_
#define _FILEREADING_H_

#include "tinyxml.h"
#include "Appearence.h"
#include "Texture.h"
#include "Globals.h"
#include "Lighting.h"
#include "LinearAnimation.h"
#include "Node.h"
#include "Camera.h"

using namespace std;

class FileReading
{
public:

	//Main vectors
	vector<Appearance*> appearances;
	vector<Animation*> animations;
	vector<Texture*> textures;
	vector<Camera*> cameras;
	vector<Lighting*> lights;
	vector<Globals*> globals;
	vector<Node*> nodes;

	//Camera globals
	string initial_camera;

	//Lighting Globals
	string doublesided, local, enabled;
	vector<float> ambient;

	//Graph Globals
	string root_node_id;

	FileReading(char *filename);	
	~FileReading();

	void print();
	void printNodes();

	static TiXmlElement *findChildByAttribute(TiXmlElement *parent,const char * attr, const char *val);
	
protected:

	TiXmlDocument* doc;
	TiXmlElement* yafElement;
	TiXmlElement* globalsElement; 	
	TiXmlElement* camerasElement;
	TiXmlElement* perspectiveElement;
	TiXmlElement* lightingElement;
	TiXmlElement* textsElement;
	TiXmlElement* appsElement;
	TiXmlElement* animesElement;
	TiXmlElement* transformsElement;
	TiXmlElement* childrenElement;
	TiXmlElement* leavesElement;
	TiXmlElement* nodesElement;
	TiXmlElement* graphElement;
};

#endif