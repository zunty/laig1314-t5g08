#ifndef _NODESCENE_H_
#define _NODESCENE_H_

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include "FileReading.h"



class NodeScene
{
	
	string id;
	bool app;
	bool display_list;
	int display_id;
	CGFappearance* appearance;
	vector<Transform*> scene_transforms;
	vector<CGFobject*> primitives;
	vector<NodeScene*> child_nodes;

public:

	NodeScene(string id, vector<Appearance*> appearances, vector<Texture*> textures, vector<Node*> nodes);

	string getId();
	void setAppearance(vector<CGFappearance*> appearances, vector<Node*> nodes);
	void settransforms(vector<Transform*> transforms, vector<Node*> nodes);
	void set(vector<CGFobject*> objects, vector<Node*> nodes);
	void setDisplayState(bool display_state);

	void generateGeometry();
	void draw();
};

#endif